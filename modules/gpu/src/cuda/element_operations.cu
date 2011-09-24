/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                           License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2000-2008, Intel Corporation, all rights reserved.
// Copyright (C) 2009, Willow Garage Inc., all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of the copyright holders may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are disclaimed.
// In no event shall the Intel Corporation or contributors be liable for any direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/

#include "opencv2/gpu/device/functional.hpp"
#include "opencv2/gpu/device/vec_math.hpp"
#include "opencv2/gpu/device/transform.hpp"
#include "opencv2/gpu/device/limits.hpp"
#include "opencv2/gpu/device/saturate_cast.hpp"
#include "internal_shared.hpp"

namespace cv { namespace gpu { namespace device
{
    //////////////////////////////////////////////////////////////////////////////////////
    // Compare

    template <typename T> struct NotEqual : binary_function<T, T, uchar>
    {
        __device__ __forceinline__ uchar operator()(T src1, T src2) const
        {
            return static_cast<uchar>(static_cast<int>(src1 != src2) * 255);
        }
    };

    template <typename T>
    inline void compare_ne(const DevMem2D& src1, const DevMem2D& src2, const DevMem2D& dst, cudaStream_t stream)
    {
        NotEqual<T> op;
        transform(static_cast< DevMem2D_<T> >(src1), static_cast< DevMem2D_<T> >(src2), dst, op, stream);
    }

    void compare_ne_8uc4(const DevMem2D& src1, const DevMem2D& src2, const DevMem2D& dst, cudaStream_t stream)
    {
        compare_ne<uint>(src1, src2, dst, stream);
    }
    void compare_ne_32f(const DevMem2D& src1, const DevMem2D& src2, const DevMem2D& dst, cudaStream_t stream)
    {
        compare_ne<float>(src1, src2, dst, stream);
    }


    //////////////////////////////////////////////////////////////////////////
    // Unary bitwise logical matrix operations

    enum { UN_OP_NOT };

    template <typename T, int opid>
    struct UnOp;

    template <typename T>
    struct UnOp<T, UN_OP_NOT>
    { 
        static __device__ __forceinline__ T call(T v) { return ~v; }
    };


    template <int opid>
    __global__ void bitwiseUnOpKernel(int rows, int width, const PtrStep src, PtrStep dst)
    {
        const int x = (blockDim.x * blockIdx.x + threadIdx.x) * 4;
        const int y = blockDim.y * blockIdx.y + threadIdx.y;

        if (y < rows) 
        {
            uchar* dst_ptr = dst.ptr(y) + x;
            const uchar* src_ptr = src.ptr(y) + x;
            if (x + sizeof(uint) - 1 < width)
            {
                *(uint*)dst_ptr = UnOp<uint, opid>::call(*(uint*)src_ptr);
            }
            else
            {
                const uchar* src_end = src.ptr(y) + width;
                while (src_ptr < src_end)
                {
                    *dst_ptr++ = UnOp<uchar, opid>::call(*src_ptr++);
                }
            }
        }
    }


    template <int opid>
    void bitwiseUnOp(int rows, int width, const PtrStep src, PtrStep dst, 
                     cudaStream_t stream)
    {
        dim3 threads(16, 16);
        dim3 grid(divUp(width, threads.x * sizeof(uint)), 
                  divUp(rows, threads.y));

        bitwiseUnOpKernel<opid><<<grid, threads>>>(rows, width, src, dst);
        cudaSafeCall( cudaGetLastError() );

        if (stream == 0) 
            cudaSafeCall( cudaDeviceSynchronize() );
    }


    template <typename T, int opid>
    __global__ void bitwiseUnOpKernel(int rows, int cols, int cn, const PtrStep src, 
                                      const PtrStep mask, PtrStep dst)
    {
        const int x = blockDim.x * blockIdx.x + threadIdx.x;
        const int y = blockDim.y * blockIdx.y + threadIdx.y;

        if (x < cols && y < rows && mask.ptr(y)[x / cn]) 
        {
            T* dst_row = (T*)dst.ptr(y);
            const T* src_row = (const T*)src.ptr(y);

            dst_row[x] = UnOp<T, opid>::call(src_row[x]);
        }
    }


    template <typename T, int opid>
    void bitwiseUnOp(int rows, int cols, int cn, const PtrStep src, 
                     const PtrStep mask, PtrStep dst, cudaStream_t stream)
    {
        dim3 threads(16, 16);
        dim3 grid(divUp(cols, threads.x), divUp(rows, threads.y));

        bitwiseUnOpKernel<T, opid><<<grid, threads>>>(rows, cols, cn, src, mask, dst); 
        cudaSafeCall( cudaGetLastError() );

        if (stream == 0) 
            cudaSafeCall( cudaDeviceSynchronize() );
    }


    void bitwiseNotCaller(int rows, int cols, size_t elem_size1, int cn, 
                          const PtrStep src, PtrStep dst, cudaStream_t stream)
    {
        bitwiseUnOp<UN_OP_NOT>(rows, static_cast<int>(cols * elem_size1 * cn), src, dst, stream);
    }


    template <typename T>
    void bitwiseMaskNotCaller(int rows, int cols, int cn, const PtrStep src, 
                              const PtrStep mask, PtrStep dst, cudaStream_t stream)
    {
        bitwiseUnOp<T, UN_OP_NOT>(rows, cols * cn, cn, src, mask, dst, stream);
    }

    template void bitwiseMaskNotCaller<uchar>(int, int, int, const PtrStep, const PtrStep, PtrStep, cudaStream_t);
    template void bitwiseMaskNotCaller<ushort>(int, int, int, const PtrStep, const PtrStep, PtrStep, cudaStream_t);
    template void bitwiseMaskNotCaller<uint>(int, int, int, const PtrStep, const PtrStep, PtrStep, cudaStream_t);


    //////////////////////////////////////////////////////////////////////////
    // Binary bitwise logical matrix operations

    enum { BIN_OP_OR, BIN_OP_AND, BIN_OP_XOR };

    template <typename T, int opid>
    struct BinOp;

    template <typename T>
    struct BinOp<T, BIN_OP_OR>
    { 
        static __device__ __forceinline__ T call(T a, T b) { return a | b; } 
    };


    template <typename T>
    struct BinOp<T, BIN_OP_AND>
    { 
        static __device__ __forceinline__ T call(T a, T b) { return a & b; } 
    };

    template <typename T>
    struct BinOp<T, BIN_OP_XOR>
    { 
        static __device__ __forceinline__ T call(T a, T b) { return a ^ b; } 
    };


    template <int opid>
    __global__ void bitwiseBinOpKernel(int rows, int width, const PtrStep src1, 
                                       const PtrStep src2, PtrStep dst)
    {
        const int x = (blockDim.x * blockIdx.x + threadIdx.x) * 4;
        const int y = blockDim.y * blockIdx.y + threadIdx.y;

        if (y < rows) 
        {
            uchar* dst_ptr = dst.ptr(y) + x;
            const uchar* src1_ptr = src1.ptr(y) + x;
            const uchar* src2_ptr = src2.ptr(y) + x;

            if (x + sizeof(uint) - 1 < width)
            {
                *(uint*)dst_ptr = BinOp<uint, opid>::call(*(uint*)src1_ptr, *(uint*)src2_ptr);
            }
            else
            {
                const uchar* src1_end = src1.ptr(y) + width;
                while (src1_ptr < src1_end)
                {
                    *dst_ptr++ = BinOp<uchar, opid>::call(*src1_ptr++, *src2_ptr++);
                }
            }
        }
    }


    template <int opid>
    void bitwiseBinOp(int rows, int width, const PtrStep src1, const PtrStep src2, 
                      PtrStep dst, cudaStream_t stream)
    {
        dim3 threads(16, 16);
        dim3 grid(divUp(width, threads.x * sizeof(uint)), divUp(rows, threads.y));

        bitwiseBinOpKernel<opid><<<grid, threads>>>(rows, width, src1, src2, dst);
        cudaSafeCall( cudaGetLastError() );

        if (stream == 0) 
            cudaSafeCall( cudaDeviceSynchronize() );
    }


    template <typename T, int opid>
    __global__ void bitwiseBinOpKernel(
            int rows, int cols, int cn, const PtrStep src1, const PtrStep src2, 
            const PtrStep mask, PtrStep dst)
    {
        const int x = blockDim.x * blockIdx.x + threadIdx.x;
        const int y = blockDim.y * blockIdx.y + threadIdx.y;

        if (x < cols && y < rows && mask.ptr(y)[x / cn]) 
        {
            T* dst_row = (T*)dst.ptr(y);
            const T* src1_row = (const T*)src1.ptr(y);
            const T* src2_row = (const T*)src2.ptr(y);

            dst_row[x] = BinOp<T, opid>::call(src1_row[x], src2_row[x]);
        }
    }


    template <typename T, int opid>
    void bitwiseBinOp(int rows, int cols, int cn, const PtrStep src1, const PtrStep src2, 
                        const PtrStep mask, PtrStep dst, cudaStream_t stream)
    {
        dim3 threads(16, 16);
        dim3 grid(divUp(cols, threads.x), divUp(rows, threads.y));

        bitwiseBinOpKernel<T, opid><<<grid, threads>>>(rows, cols, cn, src1, src2, mask, dst);
        cudaSafeCall( cudaGetLastError() );

        if (stream == 0) 
            cudaSafeCall( cudaDeviceSynchronize() );
    }


    void bitwiseOrCaller(int rows, int cols, size_t elem_size1, int cn, const PtrStep src1, 
                         const PtrStep src2, PtrStep dst, cudaStream_t stream)
    {
        bitwiseBinOp<BIN_OP_OR>(rows, static_cast<int>(cols * elem_size1 * cn), src1, src2, dst, stream);
    }


    template <typename T>
    void bitwiseMaskOrCaller(int rows, int cols, int cn, const PtrStep src1, const PtrStep src2, 
                             const PtrStep mask, PtrStep dst, cudaStream_t stream)
    {
        bitwiseBinOp<T, BIN_OP_OR>(rows, cols * cn, cn, src1, src2, mask, dst, stream);
    }

    template void bitwiseMaskOrCaller<uchar>(int, int, int, const PtrStep, const PtrStep, const PtrStep, PtrStep, cudaStream_t);
    template void bitwiseMaskOrCaller<ushort>(int, int, int, const PtrStep, const PtrStep, const PtrStep, PtrStep, cudaStream_t);
    template void bitwiseMaskOrCaller<uint>(int, int, int, const PtrStep, const PtrStep, const PtrStep, PtrStep, cudaStream_t);


    void bitwiseAndCaller(int rows, int cols, size_t elem_size1, int cn, const PtrStep src1, 
                          const PtrStep src2, PtrStep dst, cudaStream_t stream)
    {
        bitwiseBinOp<BIN_OP_AND>(rows, static_cast<int>(cols * elem_size1 * cn), src1, src2, dst, stream);
    }


    template <typename T>
    void bitwiseMaskAndCaller(int rows, int cols, int cn, const PtrStep src1, const PtrStep src2, 
                              const PtrStep mask, PtrStep dst, cudaStream_t stream)
    {
        bitwiseBinOp<T, BIN_OP_AND>(rows, cols * cn, cn, src1, src2, mask, dst, stream);
    }

    template void bitwiseMaskAndCaller<uchar>(int, int, int, const PtrStep, const PtrStep, const PtrStep, PtrStep, cudaStream_t);
    template void bitwiseMaskAndCaller<ushort>(int, int, int, const PtrStep, const PtrStep, const PtrStep, PtrStep, cudaStream_t);
    template void bitwiseMaskAndCaller<uint>(int, int, int, const PtrStep, const PtrStep, const PtrStep, PtrStep, cudaStream_t);


    void bitwiseXorCaller(int rows, int cols, size_t elem_size1, int cn, const PtrStep src1, 
                          const PtrStep src2, PtrStep dst, cudaStream_t stream)
    {
        bitwiseBinOp<BIN_OP_XOR>(rows, static_cast<int>(cols * elem_size1 * cn), src1, src2, dst, stream);
    }


    template <typename T>
    void bitwiseMaskXorCaller(int rows, int cols, int cn, const PtrStep src1, const PtrStep src2, 
                              const PtrStep mask, PtrStep dst, cudaStream_t stream)
    {
        bitwiseBinOp<T, BIN_OP_XOR>(rows, cols * cn, cn, src1, src2, mask, dst, stream);
    }

    template void bitwiseMaskXorCaller<uchar>(int, int, int, const PtrStep, const PtrStep, const PtrStep, PtrStep, cudaStream_t);
    template void bitwiseMaskXorCaller<ushort>(int, int, int, const PtrStep, const PtrStep, const PtrStep, PtrStep, cudaStream_t);
    template void bitwiseMaskXorCaller<uint>(int, int, int, const PtrStep, const PtrStep, const PtrStep, PtrStep, cudaStream_t);


    //////////////////////////////////////////////////////////////////////////
    // min/max

    namespace detail
    {
        template <size_t size, typename F> struct MinMaxTraits : DefaultTransformFunctorTraits<F>
        {
        };
        template <typename F> struct MinMaxTraits<2, F> : DefaultTransformFunctorTraits<F>
        {
            enum { smart_shift = 4 };
        };
        template <typename F> struct MinMaxTraits<4, F> : DefaultTransformFunctorTraits<F>
        {
            enum { smart_block_dim_y = 4 };
            enum { smart_shift = 4 };
        };
    }

    template <typename T> struct TransformFunctorTraits< minimum<T> > : detail::MinMaxTraits< sizeof(T), minimum<T> >
    {
    };
    template <typename T> struct TransformFunctorTraits< maximum<T> > : detail::MinMaxTraits< sizeof(T), maximum<T> >
    {
    };
    template <typename T> struct TransformFunctorTraits< binder2nd< minimum<T> > > : detail::MinMaxTraits< sizeof(T), binder2nd< minimum<T> > >
    {
    };
    template <typename T> struct TransformFunctorTraits< binder2nd< maximum<T> > > : detail::MinMaxTraits< sizeof(T), binder2nd< maximum<T> > >
    {
    };
    
    template <typename T>
    void min_gpu(const DevMem2D_<T>& src1, const DevMem2D_<T>& src2, const DevMem2D_<T>& dst, cudaStream_t stream)
    {
        transform(src1, src2, dst, minimum<T>(), stream);    
    }

    template void min_gpu<uchar >(const DevMem2D& src1, const DevMem2D& src2, const DevMem2D& dst, cudaStream_t stream);
    template void min_gpu<schar >(const DevMem2D_<schar>& src1, const DevMem2D_<schar>& src2, const DevMem2D_<schar>& dst, cudaStream_t stream);
    template void min_gpu<ushort>(const DevMem2D_<ushort>& src1, const DevMem2D_<ushort>& src2, const DevMem2D_<ushort>& dst, cudaStream_t stream);
    template void min_gpu<short >(const DevMem2D_<short>& src1, const DevMem2D_<short>& src2, const DevMem2D_<short>& dst, cudaStream_t stream);
    template void min_gpu<int   >(const DevMem2D_<int>& src1, const DevMem2D_<int>& src2, const DevMem2D_<int>& dst, cudaStream_t stream);
    template void min_gpu<float >(const DevMem2D_<float>& src1, const DevMem2D_<float>& src2, const DevMem2D_<float>& dst, cudaStream_t stream);
    template void min_gpu<double>(const DevMem2D_<double>& src1, const DevMem2D_<double>& src2, const DevMem2D_<double>& dst, cudaStream_t stream);

    template <typename T>
    void max_gpu(const DevMem2D_<T>& src1, const DevMem2D_<T>& src2, const DevMem2D_<T>& dst, cudaStream_t stream)
    {
        transform(src1, src2, dst, maximum<T>(), stream);    
    }
    
    template void max_gpu<uchar >(const DevMem2D& src1, const DevMem2D& src2, const DevMem2D& dst, cudaStream_t stream);
    template void max_gpu<schar >(const DevMem2D_<schar>& src1, const DevMem2D_<schar>& src2, const DevMem2D_<schar>& dst, cudaStream_t stream);
    template void max_gpu<ushort>(const DevMem2D_<ushort>& src1, const DevMem2D_<ushort>& src2, const DevMem2D_<ushort>& dst, cudaStream_t stream);
    template void max_gpu<short >(const DevMem2D_<short>& src1, const DevMem2D_<short>& src2, const DevMem2D_<short>& dst, cudaStream_t stream);
    template void max_gpu<int   >(const DevMem2D_<int>& src1, const DevMem2D_<int>& src2, const DevMem2D_<int>& dst, cudaStream_t stream);
    template void max_gpu<float >(const DevMem2D_<float>& src1, const DevMem2D_<float>& src2, const DevMem2D_<float>& dst, cudaStream_t stream);
    template void max_gpu<double>(const DevMem2D_<double>& src1, const DevMem2D_<double>& src2, const DevMem2D_<double>& dst, cudaStream_t stream);

    template <typename T>
    void min_gpu(const DevMem2D_<T>& src1, T src2, const DevMem2D_<T>& dst, cudaStream_t stream)
    {
        transform(src1, dst, device::bind2nd(minimum<T>(), src2), stream);    
    }

    template void min_gpu<uchar >(const DevMem2D& src1, uchar src2, const DevMem2D& dst, cudaStream_t stream);
    template void min_gpu<schar >(const DevMem2D_<schar>& src1, schar src2, const DevMem2D_<schar>& dst, cudaStream_t stream);
    template void min_gpu<ushort>(const DevMem2D_<ushort>& src1, ushort src2, const DevMem2D_<ushort>& dst, cudaStream_t stream);
    template void min_gpu<short >(const DevMem2D_<short>& src1, short src2, const DevMem2D_<short>& dst, cudaStream_t stream);
    template void min_gpu<int   >(const DevMem2D_<int>& src1, int src2, const DevMem2D_<int>& dst, cudaStream_t stream);
    template void min_gpu<float >(const DevMem2D_<float>& src1, float src2, const DevMem2D_<float>& dst, cudaStream_t stream);
    template void min_gpu<double>(const DevMem2D_<double>& src1, double src2, const DevMem2D_<double>& dst, cudaStream_t stream);

    template <typename T>
    void max_gpu(const DevMem2D_<T>& src1, T src2, const DevMem2D_<T>& dst, cudaStream_t stream)
    {
        transform(src1, dst, device::bind2nd(maximum<T>(), src2), stream);    
    }

    template void max_gpu<uchar >(const DevMem2D& src1, uchar src2, const DevMem2D& dst, cudaStream_t stream);
    template void max_gpu<schar >(const DevMem2D_<schar>& src1, schar src2, const DevMem2D_<schar>& dst, cudaStream_t stream);
    template void max_gpu<ushort>(const DevMem2D_<ushort>& src1, ushort src2, const DevMem2D_<ushort>& dst, cudaStream_t stream);
    template void max_gpu<short >(const DevMem2D_<short>& src1, short src2, const DevMem2D_<short>& dst, cudaStream_t stream);
    template void max_gpu<int   >(const DevMem2D_<int>& src1, int src2, const DevMem2D_<int>& dst, cudaStream_t stream);
    template void max_gpu<float >(const DevMem2D_<float>& src1, float src2, const DevMem2D_<float>& dst, cudaStream_t stream);
    template void max_gpu<double>(const DevMem2D_<double>& src1, double src2, const DevMem2D_<double>& dst, cudaStream_t stream);

    
    //////////////////////////////////////////////////////////////////////////
    // threshold

    namespace detail
    {
        template <size_t size, typename F> struct ThresholdTraits : DefaultTransformFunctorTraits<F>
        {
        };
        template <typename F> struct ThresholdTraits<2, F> : DefaultTransformFunctorTraits<F>
        {
            enum { smart_shift = 4 };
        };
        template <typename F> struct ThresholdTraits<4, F> : DefaultTransformFunctorTraits<F>
        {
            enum { smart_block_dim_y = 4 };
            enum { smart_shift = 4 };
        };
    }

    template <typename T> struct TransformFunctorTraits< thresh_binary_func<T> > : detail::ThresholdTraits< sizeof(T), thresh_binary_func<T> >
    {
    };
    template <typename T> struct TransformFunctorTraits< thresh_binary_inv_func<T> > : detail::ThresholdTraits< sizeof(T), thresh_binary_inv_func<T> >
    {
    };
    template <typename T> struct TransformFunctorTraits< thresh_trunc_func<T> > : detail::ThresholdTraits< sizeof(T), thresh_trunc_func<T> >
    {
    };
    template <typename T> struct TransformFunctorTraits< thresh_to_zero_func<T> > : detail::ThresholdTraits< sizeof(T), thresh_to_zero_func<T> >
    {
    };
    template <typename T> struct TransformFunctorTraits< thresh_to_zero_inv_func<T> > : detail::ThresholdTraits< sizeof(T), thresh_to_zero_inv_func<T> >
    {
    };

    template <template <typename> class Op, typename T>
    void threshold_caller(const DevMem2D_<T>& src, const DevMem2D_<T>& dst, T thresh, T maxVal, 
        cudaStream_t stream)
    {
        Op<T> op(thresh, maxVal);
        transform(src, dst, op, stream);
    }

    template <typename T>
    void threshold_gpu(const DevMem2D& src, const DevMem2D& dst, T thresh, T maxVal, int type,
        cudaStream_t stream)
    {
        typedef void (*caller_t)(const DevMem2D_<T>& src, const DevMem2D_<T>& dst, T thresh, T maxVal, 
            cudaStream_t stream);

        static const caller_t callers[] = 
        {
            threshold_caller<thresh_binary_func, T>, 
            threshold_caller<thresh_binary_inv_func, T>, 
            threshold_caller<thresh_trunc_func, T>, 
            threshold_caller<thresh_to_zero_func, T>, 
            threshold_caller<thresh_to_zero_inv_func, T>
        };

        callers[type]((DevMem2D_<T>)src, (DevMem2D_<T>)dst, thresh, maxVal, stream);
    }

    template void threshold_gpu<uchar>(const DevMem2D& src, const DevMem2D& dst, uchar thresh, uchar maxVal, int type, cudaStream_t stream);
    template void threshold_gpu<schar>(const DevMem2D& src, const DevMem2D& dst, schar thresh, schar maxVal, int type, cudaStream_t stream);
    template void threshold_gpu<ushort>(const DevMem2D& src, const DevMem2D& dst, ushort thresh, ushort maxVal, int type, cudaStream_t stream);
    template void threshold_gpu<short>(const DevMem2D& src, const DevMem2D& dst, short thresh, short maxVal, int type, cudaStream_t stream);
    template void threshold_gpu<int>(const DevMem2D& src, const DevMem2D& dst, int thresh, int maxVal, int type, cudaStream_t stream);
    template void threshold_gpu<float>(const DevMem2D& src, const DevMem2D& dst, float thresh, float maxVal, int type, cudaStream_t stream);
    template void threshold_gpu<double>(const DevMem2D& src, const DevMem2D& dst, double thresh, double maxVal, int type, cudaStream_t stream);


    //////////////////////////////////////////////////////////////////////////
    // subtract

    template <> struct TransformFunctorTraits< minus<short> > : DefaultTransformFunctorTraits< minus<short> >
    {
        enum { smart_block_dim_y = 8 };
        enum { smart_shift = 4 };
    };

    template <typename T> void subtractCaller(const DevMem2D src1, const DevMem2D src2, DevMem2D dst, cudaStream_t stream)
    {
        transform((DevMem2D_<T>)src1, (DevMem2D_<T>)src2, (DevMem2D_<T>)dst, minus<T>(), stream);
    }

    template void subtractCaller<short>(const DevMem2D src1, const DevMem2D src2, DevMem2D dst, cudaStream_t stream);


    //////////////////////////////////////////////////////////////////////////
    // pow
    
    template<typename T, bool Signed = device::numeric_limits<T>::is_signed> struct PowOp : unary_function<T, T>
    {    
        float power;
        PowOp(float power_) : power(power_) {}
            
        __device__ __forceinline__ T operator()(const T& e) const
        {      
            return saturate_cast<T>(__powf((float)e, power));
        }      
    };

    template<typename T> struct PowOp<T, true> : unary_function<T, T>
    {
        float power;
        PowOp(float power_) : power(power_) {}

        __device__ __forceinline__ float operator()(const T& e) const
        {
            T res = saturate_cast<T>(__powf((float)e, power));            
            
            if ( (e < 0) && (1 & (int)power) )
                    res *= -1;            
            return res;         
        }
    };

    template<> struct PowOp<float> : unary_function<float, float>
    {
        float power;
        PowOp(float power_) : power(power_) {}

        __device__ __forceinline__ float operator()(const float& e) const
        {
            return __powf(::fabs(e), power);
        }
    };

    namespace detail
    {
        template <size_t size, typename T> struct PowOpTraits : DefaultTransformFunctorTraits< PowOp<T> >
        {
        };
        template <typename T> struct PowOpTraits<1, T> : DefaultTransformFunctorTraits< PowOp<T> >
        {
            enum { smart_block_dim_y = 8 };
            enum { smart_shift = 8 };
        };
        template <typename T> struct PowOpTraits<2, T> : DefaultTransformFunctorTraits< PowOp<T> >
        {
            enum { smart_shift = 4 };
        };
        template <typename T> struct PowOpTraits<4, T> : DefaultTransformFunctorTraits< PowOp<T> >
        {
            enum { smart_block_dim_y = 4 };
            enum { smart_shift = 4 };
        };
    }

    template <typename T> struct TransformFunctorTraits< PowOp<T> > : detail::PowOpTraits<sizeof(T), T>
    {
    };

    template<typename T>
    void pow_caller(const DevMem2D& src, float power, DevMem2D dst, cudaStream_t stream)
    {
        transform((DevMem2D_<T>)src, (DevMem2D_<T>)dst, PowOp<T>(power), stream);
    }   

    template void pow_caller<uchar>(const DevMem2D& src, float power, DevMem2D dst, cudaStream_t stream);
    template void pow_caller<schar>(const DevMem2D& src, float power, DevMem2D dst, cudaStream_t stream);
    template void pow_caller<short>(const DevMem2D& src, float power, DevMem2D dst, cudaStream_t stream);
    template void pow_caller<ushort>(const DevMem2D& src, float power, DevMem2D dst, cudaStream_t stream);
    template void pow_caller<int>(const DevMem2D& src, float power, DevMem2D dst, cudaStream_t stream);
    template void pow_caller<float>(const DevMem2D& src, float power, DevMem2D dst, cudaStream_t stream);


    //////////////////////////////////////////////////////////////////////////
    // divide

    struct divide_8uc4_32f : binary_function<uchar4, float, uchar4>
    {
        __device__ __forceinline__ uchar4 operator ()(uchar4 a, float b) const
        {
            return make_uchar4(saturate_cast<uchar>(a.x / b), saturate_cast<uchar>(a.y / b),
                               saturate_cast<uchar>(a.z / b), saturate_cast<uchar>(a.w / b));
        }
    };

    template <> struct TransformFunctorTraits<divide_8uc4_32f> : DefaultTransformFunctorTraits<divide_8uc4_32f>
    {
        enum { smart_block_dim_x = 8 };
        enum { smart_block_dim_y = 8 };
        enum { smart_shift = 8 };
    };

    void divide_gpu(const DevMem2D_<uchar4>& src1, const DevMem2Df& src2, const DevMem2D_<uchar4>& dst, cudaStream_t stream)
    {
        transform(static_cast< DevMem2D_<uchar4> >(src1), src2, static_cast< DevMem2D_<uchar4> >(dst), divide_8uc4_32f(), stream);
    }


    struct divide_16sc4_32f : binary_function<short4, float, short4>
    {
        __device__ __forceinline__ short4 operator ()(short4 a, float b) const
        {
            return make_short4(saturate_cast<short>(a.x / b), saturate_cast<uchar>(a.y / b),
                               saturate_cast<short>(a.z / b), saturate_cast<uchar>(a.w / b));
        }
    };

    template <> struct TransformFunctorTraits<divide_16sc4_32f> : DefaultTransformFunctorTraits<divide_16sc4_32f>
    {
        enum { smart_block_dim_x = 8 };
        enum { smart_block_dim_y = 8 };
        enum { smart_shift = 8 };
    };

    void divide_gpu(const DevMem2D_<short4>& src1, const DevMem2Df& src2, const DevMem2D_<short4>& dst, cudaStream_t stream)
    {
        transform(static_cast< DevMem2D_<short4> >(src1), src2, static_cast< DevMem2D_<short4> >(dst), divide_16sc4_32f(), stream);
    }


    //////////////////////////////////////////////////////////////////////////
    // multiply

    template <> struct TransformFunctorTraits< plus<short> > : DefaultTransformFunctorTraits< plus<short> >
    {
        enum { smart_block_dim_y = 8 };
        enum { smart_shift = 4 };
    };

    template <typename T> void add_gpu(const DevMem2D src1, const DevMem2D src2, DevMem2D dst, cudaStream_t stream)
    {
        transform((DevMem2D_<T>)src1, (DevMem2D_<T>)src2, (DevMem2D_<T>)dst, plus<T>(), stream);
    }

    template void add_gpu<short>(const DevMem2D src1, const DevMem2D src2, DevMem2D dst, cudaStream_t stream);

    //////////////////////////////////////////////////////////////////////////
    // multiply

    struct multiply_8uc4_32f : binary_function<uint, float, uint>
    {
        __device__ __forceinline__ uint operator ()(uint a, float b) const
        {
            uint res = 0;

            res |= (saturate_cast<uchar>((0xffu & (a      )) * b)      );
            res |= (saturate_cast<uchar>((0xffu & (a >>  8)) * b) <<  8);
            res |= (saturate_cast<uchar>((0xffu & (a >> 16)) * b) << 16);
            res |= (saturate_cast<uchar>((0xffu & (a >> 24)) * b) << 24);

            return res;
        }
    };

    template <> struct TransformFunctorTraits<multiply_8uc4_32f> : DefaultTransformFunctorTraits<multiply_8uc4_32f>
    {
        enum { smart_block_dim_x = 8 };
        enum { smart_block_dim_y = 8 };
        enum { smart_shift = 8 };
    };

    void multiply_gpu(const DevMem2D_<uchar4>& src1, const DevMem2Df& src2, const DevMem2D_<uchar4>& dst, cudaStream_t stream)
    {
        transform(static_cast< DevMem2D_<uint> >(src1), src2, static_cast< DevMem2D_<uint> >(dst), multiply_8uc4_32f(), stream);
    }

    struct multiply_16sc4_32f : binary_function<short4, float, short4>
    {
        __device__ __forceinline__ short4 operator ()(short4 a, float b) const
        {
            return make_short4(saturate_cast<short>(a.x * b), saturate_cast<short>(a.y * b),
                               saturate_cast<short>(a.z * b), saturate_cast<short>(a.w * b));
        }
    };

    template <> struct TransformFunctorTraits<multiply_16sc4_32f> : DefaultTransformFunctorTraits<multiply_16sc4_32f>
    {
        enum { smart_block_dim_x = 8 };
        enum { smart_block_dim_y = 8 };
        enum { smart_shift = 8 };
    };

    void multiply_gpu(const DevMem2D_<short4>& src1, const DevMem2Df& src2, const DevMem2D_<short4>& dst, cudaStream_t stream)
    {
        transform(static_cast< DevMem2D_<short4> >(src1), src2, 
                  static_cast< DevMem2D_<short4> >(dst), multiply_16sc4_32f(), stream);
    }


    //////////////////////////////////////////////////////////////////////////
    // multiply (by scalar)

    template <typename T, typename D, typename S> struct MultiplyScalar : unary_function<T, D>
    {
        __host__ __device__ __forceinline__ MultiplyScalar(typename TypeTraits<S>::ParameterType scale_) : scale(scale_) {}

        __device__ __forceinline__ D operator ()(typename TypeTraits<T>::ParameterType a) const
        {
            return saturate_cast<D>(a * scale);
        }

        const S scale;
    };

    template <> struct TransformFunctorTraits< MultiplyScalar<uchar, uchar, float> > : DefaultTransformFunctorTraits< MultiplyScalar<uchar, uchar, float> >
    {
        enum { smart_block_dim_y = 8 };
        enum { smart_shift = 8 };
    };

    template <typename T, typename D>
    void multiplyScalar_gpu(const DevMem2D& src, float scale, const DevMem2D& dst, cudaStream_t stream)
    {
        transform(static_cast< DevMem2D_<T> >(src), static_cast< DevMem2D_<D> >(dst), MultiplyScalar<T, D, float>(scale), stream);
    }

    template void multiplyScalar_gpu<uchar, uchar>(const DevMem2D& src, float scale, const DevMem2D& dst, cudaStream_t stream);


    //////////////////////////////////////////////////////////////////////////
    // addWeighted

    template <typename T1, typename T2, typename D> struct AddWeighted : binary_function<T1, T2, D>
    {
        __host__ __device__ __forceinline__ AddWeighted(double alpha_, double beta_, double gamma_) : alpha(alpha_), beta(beta_), gamma(gamma_) {}

        __device__ __forceinline__ D operator ()(typename TypeTraits<T1>::ParameterType a, typename TypeTraits<T2>::ParameterType b) const
        {
            return saturate_cast<D>(alpha * a + beta * b + gamma);
        }

        const double alpha;
        const double beta;
        const double gamma;
    };

    template <> struct TransformFunctorTraits< AddWeighted<ushort, ushort, ushort> > : DefaultTransformFunctorTraits< AddWeighted<ushort, ushort, ushort> >
    {
        enum { smart_shift = 4 };
    };
    template <> struct TransformFunctorTraits< AddWeighted<ushort, ushort, short> > : DefaultTransformFunctorTraits< AddWeighted<ushort, ushort, short> >
    {
        enum { smart_shift = 4 };
    };
    template <> struct TransformFunctorTraits< AddWeighted<ushort, short, ushort> > : DefaultTransformFunctorTraits< AddWeighted<ushort, short, ushort> >
    {
        enum { smart_shift = 4 };
    };
    template <> struct TransformFunctorTraits< AddWeighted<ushort, short, short> > : DefaultTransformFunctorTraits< AddWeighted<ushort, short, short> >
    {
        enum { smart_shift = 4 };
    };
    template <> struct TransformFunctorTraits< AddWeighted<short, short, ushort> > : DefaultTransformFunctorTraits< AddWeighted<short, short, ushort> >
    {
        enum { smart_shift = 4 };
    };
    template <> struct TransformFunctorTraits< AddWeighted<short, short, short> > : DefaultTransformFunctorTraits< AddWeighted<short, short, short> >
    {
        enum { smart_shift = 4 };
    };

    template <> struct TransformFunctorTraits< AddWeighted<int, int, int> > : DefaultTransformFunctorTraits< AddWeighted<int, int, int> >
    {
        enum { smart_block_dim_y = 8 };
        enum { smart_shift = 4 };
    };
    template <> struct TransformFunctorTraits< AddWeighted<int, int, float> > : DefaultTransformFunctorTraits< AddWeighted<int, int, float> >
    {
        enum { smart_block_dim_y = 8 };
        enum { smart_shift = 4 };
    };
    template <> struct TransformFunctorTraits< AddWeighted<int, float, int> > : DefaultTransformFunctorTraits< AddWeighted<int, float, int> >
    {
        enum { smart_block_dim_y = 8 };
        enum { smart_shift = 4 };
    };
    template <> struct TransformFunctorTraits< AddWeighted<int, float, float> > : DefaultTransformFunctorTraits< AddWeighted<int, float, float> >
    {
        enum { smart_block_dim_y = 8 };
        enum { smart_shift = 4 };
    };
    template <> struct TransformFunctorTraits< AddWeighted<float, float, int> > : DefaultTransformFunctorTraits< AddWeighted<float, float, float> >
    {
        enum { smart_block_dim_y = 8 };
        enum { smart_shift = 4 };
    };
    template <> struct TransformFunctorTraits< AddWeighted<float, float, float> > : DefaultTransformFunctorTraits< AddWeighted<float, float, float> >
    {
        enum { smart_block_dim_y = 8 };
        enum { smart_shift = 4 };
    };

    template <typename T1, typename T2, typename D>
    void addWeighted_gpu(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream)
    {
        cudaSafeCall( cudaSetDoubleForDevice(&alpha) );
        cudaSafeCall( cudaSetDoubleForDevice(&beta) );
        cudaSafeCall( cudaSetDoubleForDevice(&gamma) );

        AddWeighted<T1, T2, D> op(alpha, beta, gamma);

        transform(static_cast< DevMem2D_<T1> >(src1), static_cast< DevMem2D_<T2> >(src2), static_cast< DevMem2D_<D> >(dst), op, stream);
    }

    template void addWeighted_gpu<uchar, uchar, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, uchar, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, uchar, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, uchar, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, uchar, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, uchar, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, uchar, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<uchar, schar, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, schar, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, schar, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, schar, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, schar, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, schar, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, schar, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<uchar, ushort, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, ushort, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, ushort, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, ushort, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, ushort, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, ushort, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, ushort, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<uchar, short, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, short, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, short, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, short, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, short, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, short, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, short, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<uchar, int, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, int, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, int, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, int, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, int, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, int, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, int, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<uchar, float, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, float, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, float, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, float, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, float, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, float, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, float, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<uchar, double, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, double, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, double, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, double, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, double, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, double, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<uchar, double, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);



    template void addWeighted_gpu<schar, schar, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, schar, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, schar, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, schar, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, schar, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, schar, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, schar, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<schar, ushort, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, ushort, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, ushort, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, ushort, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, ushort, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, ushort, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, ushort, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<schar, short, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, short, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, short, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, short, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, short, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, short, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, short, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<schar, int, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, int, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, int, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, int, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, int, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, int, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, int, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<schar, float, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, float, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, float, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, float, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, float, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, float, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, float, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<schar, double, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, double, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, double, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, double, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, double, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, double, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<schar, double, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);



    template void addWeighted_gpu<ushort, ushort, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, ushort, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, ushort, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, ushort, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, ushort, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, ushort, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, ushort, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<ushort, short, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, short, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, short, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, short, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, short, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, short, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, short, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<ushort, int, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, int, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, int, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, int, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, int, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, int, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, int, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<ushort, float, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, float, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, float, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, float, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, float, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, float, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, float, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<ushort, double, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, double, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, double, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, double, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, double, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, double, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<ushort, double, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);



    template void addWeighted_gpu<short, short, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, short, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, short, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, short, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, short, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, short, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, short, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<short, int, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, int, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, int, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, int, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, int, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, int, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, int, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<short, float, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, float, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, float, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, float, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, float, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, float, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, float, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<short, double, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, double, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, double, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, double, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, double, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, double, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<short, double, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    

    template void addWeighted_gpu<int, int, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<int, int, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<int, int, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<int, int, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<int, int, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<int, int, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<int, int, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<int, float, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<int, float, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<int, float, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<int, float, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<int, float, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<int, float, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<int, float, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<int, double, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<int, double, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<int, double, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<int, double, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<int, double, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<int, double, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<int, double, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    

    template void addWeighted_gpu<float, float, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<float, float, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<float, float, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<float, float, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<float, float, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<float, float, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<float, float, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    template void addWeighted_gpu<float, double, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<float, double, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<float, double, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<float, double, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<float, double, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<float, double, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<float, double, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);

    

    template void addWeighted_gpu<double, double, uchar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<double, double, schar>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<double, double, ushort>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<double, double, short>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<double, double, int>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<double, double, float>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
    template void addWeighted_gpu<double, double, double>(const DevMem2D& src1, double alpha, const DevMem2D& src2, double beta, double gamma, const DevMem2D& dst, cudaStream_t stream);
}}}
