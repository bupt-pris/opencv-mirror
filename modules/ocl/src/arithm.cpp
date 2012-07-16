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
// Copyright (C) 2010-2012, Institute Of Software Chinese Academy Of Science, all rights reserved.
// Copyright (C) 2010-2012, Advanced Micro Devices, Inc., all rights reserved.
// Third party copyrights are property of their respective owners.
//
// @Authors
//    Niko Li, newlife20080214@gmail.com
//    Jia Haipeng, jiahaipeng95@gmail.com
//    Shengen Yan, yanshengen@gmail.com
//    Jiang Liyuan, jlyuan001.good@163.com
//    Rock Li, Rock.Li@amd.com
//    Zailong Wu, bullet@yeah.net
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other oclMaterials provided with the distribution.
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

#include "precomp.hpp"
#include <iomanip>


using namespace cv;
using namespace cv::ocl;
using namespace std;

#if !defined (HAVE_OPENCL)

/* arithmetics */
void cv::ocl::add(const oclMat &, const oclMat &, oclMat &)
{
    throw_nogpu();
}
void cv::ocl::add(const oclMat &, const oclMat &, oclMat &, const oclMat &)
{
    throw_nogpu();
}
void cv::ocl::add(const oclMat &, const Scalar &, oclMat &, const oclMat &)
{
    throw_nogpu();
}
void cv::ocl::subtract(const oclMat &, const oclMat &, oclMat &)
{
    throw_nogpu();
}
void cv::ocl::subtract(const oclMat &, const oclMat &, oclMat &, const oclMat &)
{
    throw_nogpu();
}
void cv::ocl::subtract(const oclMat &, const Scalar &, oclMat &, const oclMat & )
{
    throw_nogpu();
}
void cv::ocl::subtract(const Scalar &, const oclMat &,  oclMat &, const oclMat & )
{
    throw_nogpu();
}
void cv::ocl::multiply(const oclMat &, const oclMat &, oclMat &, double)
{
    throw_nogpu();
}
void cv::ocl::divide(const oclMat &, const oclMat &, oclMat &, double)
{
    throw_nogpu();
}
void cv::ocl::divide(double, const oclMat &, oclMat &)
{
    throw_nogpu();
}
void cv::ocl::absdiff(const oclMat &, const oclMat &, oclMat &)
{
    throw_nogpu();
}
void cv::ocl::absdiff(const oclMat &, const Scalar &, oclMat &)
{
    throw_nogpu();
}
void cv::ocl::compare(const oclMat &, const oclMat &, oclMat & , int)
{
    throw_nogpu();
}
void cv::ocl::meanStdDev(const oclMat &, Scalar &, Scalar &)
{
    throw_nogpu();
}
double cv::ocl::norm(const oclMat &, int)
{
    throw_nogpu();
    return 0.0;
}
double cv::ocl::norm(const oclMat &, const oclMat &, int)
{
    throw_nogpu();
    return 0.0;
}
void cv::ocl::flip(const oclMat &, oclMat &, int)
{
    throw_nogpu();
}
Scalar cv::ocl::sum(const oclMat &)
{
    throw_nogpu();
    return Scalar();
}
void cv::ocl::minMax(const oclMat &, double *, double *, const oclMat &)
{
    throw_nogpu();
}
void cv::ocl::minMaxLoc(const oclMat &, double *, double *, Point *, Point *, const oclMat &)
{
    throw_nogpu();
}
void cv::ocl::LUT(const oclMat &, const Mat &, oclMat &)
{
    throw_nogpu();
}
void cv::ocl::exp(const oclMat &, oclMat &)
{
    throw_nogpu();
}
void cv::ocl::log(const oclMat &, oclMat &)
{
    throw_nogpu();
}
void cv::ocl::magnitude(const oclMat &, oclMat &)
{
    throw_nogpu();
}
void cv::ocl::phase(const oclMat &, const oclMat &, oclMat &, bool)
{
    throw_nogpu();
}
void cv::ocl::cartToPolar(const oclMat &, const oclMat &, oclMat &, oclMat &, bool)
{
    throw_nogpu();
}
void cv::ocl::polarToCart(const oclMat &, const oclMat &, oclMat &, oclMat &, bool)
{
    throw_nogpu();
}
void cv::ocl::transpose(const oclMat &, oclMat &)
{
    throw_nogpu();
}
void cv::ocl::pow(const oclMat &, double, oclMat &)
{
    throw_nogpu();
}
void cv::ocl::addWeighted(const oclMat &src1, double alpha, const oclMat &src2, double beta, double gama, oclMat &dst)
{
    throw_nogpu();
}
void cv::ocl::magnitudeSqr(const oclMat &src1, const oclMat &src2, oclMat &dst)
{
    throw_nogpu();
}

/* bit wise operations */
void cv::ocl::bitwise_not(const oclMat &, oclMat &)
{
    throw_nogpu();
}
void cv::ocl::bitwise_or(const oclMat &, const oclMat &, oclMat &, const oclMat &)
{
    throw_nogpu();
}
void cv::ocl::bitwise_and(const oclMat &, const oclMat &, oclMat &, const oclMat &)
{
    throw_nogpu();
}
void cv::ocl::bitwise_and(const oclMat &, const Scalar &, oclMat &, const oclMat &)
{
    throw_nogpu();
}
void cv::ocl::bitwise_xor(const oclMat &, const oclMat &, oclMat &, const oclMat &)
{
    throw_nogpu();
}
cv::ocl::oclMat cv::ocl::operator ~ (const oclMat &)
{
    throw_nogpu();
    return oclMat();
}
cv::ocl::oclMat cv::ocl::operator | (const oclMat &, const oclMat &)
{
    throw_nogpu();
    return oclMat();
}
cv::ocl::oclMat cv::ocl::operator & (const oclMat &, const oclMat &)
{
    throw_nogpu();
    return oclMat();
}
cv::ocl::oclMat cv::ocl::operator ^ (const oclMat &, const oclMat &)
{
    throw_nogpu();
    return oclMat();
}

#else /* !defined (HAVE_OPENCL) */
namespace cv
{
    namespace ocl
    {
        ////////////////////////////////OpenCL kernel strings/////////////////////
        extern const char *bitwise;
        extern const char *bitwiseM;
        extern const char *transpose_kernel;
        extern const char *arithm_nonzero;
        extern const char *arithm_sum;
        extern const char *arithm_2_mat;
        extern const char *arithm_sum_3;
        extern const char *arithm_minMax;
        extern const char *arithm_minMax_mask;
        extern const char *arithm_minMaxLoc;
        extern const char *arithm_minMaxLoc_mask;
        extern const char *arithm_LUT;
        extern const char *arithm_add;
        extern const char *arithm_add_scalar;
        extern const char *arithm_add_scalar_mask;
        extern const char *arithm_bitwise_not;
        extern const char *arithm_bitwise_and;
        extern const char *arithm_bitwise_and_mask;
        extern const char *arithm_bitwise_and_scalar;
        extern const char *arithm_bitwise_and_scalar_mask;
        extern const char *arithm_bitwise_or;
        extern const char *arithm_bitwise_or_mask;
        extern const char *arithm_bitwise_or_scalar;
        extern const char *arithm_bitwise_or_scalar_mask;
        extern const char *arithm_bitwise_xor;
        extern const char *arithm_bitwise_xor_mask;
        extern const char *arithm_bitwise_xor_scalar;
        extern const char *arithm_bitwise_xor_scalar_mask;
        extern const char *arithm_compare_eq;
        extern const char *arithm_compare_ne;
        extern const char *arithm_sub;
        extern const char *arithm_sub_scalar;
        extern const char *arithm_sub_scalar_mask;
        extern const char *arithm_mul;
        extern const char *arithm_div;
        extern const char *arithm_absdiff;
        extern const char *arithm_transpose;
        extern const char *arithm_flip;
        extern const char *arithm_flip_rc;
        extern const char *arithm_magnitude;
        extern const char *arithm_cartToPolar;
        extern const char *arithm_polarToCart;
        extern const char *arithm_exp;
        extern const char *arithm_log;
        extern const char *arithm_addWeighted;
        extern const char *arithm_phase;
        extern const char *arithm_pow;
        extern const char *arithm_magnitudeSqr;
        //extern const char * jhp_transpose_kernel;
        int64 kernelrealtotal = 0;
        int64 kernelalltotal = 0;
        int64 reducetotal = 0;
        int64 downloadtotal = 0;
        int64 alltotal = 0;
    }
}

//////////////////////////////////////////////////////////////////////////
//////////////////common/////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline int divUp(int total, int grain)
{
    return (total + grain - 1) / grain;
}
//////////////////////////////////////////////////////////////////////////////
/////////////////////// add subtract multiply divide /////////////////////////
//////////////////////////////////////////////////////////////////////////////
template<typename T>
void arithmetic_run(const oclMat &src1, const oclMat &src2, oclMat &dst, string kernelName, const char **kernelString, void *_scalar)
{
    if(src1.clCxt -> impl -> double_support ==0 && src1.type() == CV_64F)
    {
        CV_Error(-217,"Selected device don't support double\r\n");
        return;
    }

    dst.create(src1.size(), src1.type());
    CV_Assert(src1.cols == src2.cols && src2.cols == dst.cols &&
              src1.rows == src2.rows && src2.rows == dst.rows);

    CV_Assert(src1.type() == src2.type() && src1.type() == dst.type());
    CV_Assert(src1.depth() != CV_8S);

    Context  *clCxt = src1.clCxt;
    int channels = dst.channels();
    int depth = dst.depth();

    int vector_lengths[4][7] = {{4, 0, 4, 4, 1, 1, 1},
        {4, 0, 4, 4, 1, 1, 1},
        {4, 0, 4, 4, 1, 1, 1},
        {4, 0, 4, 4, 1, 1, 1}
    };

    size_t vector_length = vector_lengths[channels-1][depth];
    int offset_cols = (dst.offset / dst.elemSize1()) & (vector_length - 1);
    int cols = divUp(dst.cols * channels + offset_cols, vector_length);

    size_t localThreads[3]  = { 64, 4, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
                                divUp(dst.rows, localThreads[1]) * localThreads[1],
                                1
                              };

    int dst_step1 = dst.cols * dst.elemSize();
    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src1.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src2.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.offset ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst_step1 ));

    if(_scalar != NULL)
    {
        double scalar1 = *((double *)_scalar);
        T scalar = (T)scalar1;
        args.push_back( make_pair( sizeof(T), (void *)&scalar ));
    }

    openCLExecuteKernel(clCxt, kernelString, kernelName, globalThreads, localThreads, args, -1, depth);
}
void arithmetic_run(const oclMat &src1, const oclMat &src2, oclMat &dst, string kernelName, const char **kernelString)
{
    arithmetic_run<char>(src1, src2, dst, kernelName, kernelString, (void *)NULL);
}
void arithmetic_run(const oclMat &src1, const oclMat &src2, oclMat &dst, const oclMat &mask, string kernelName, const char **kernelString)
{
    if(src1.clCxt -> impl -> double_support ==0 && src1.type() == CV_64F)
    {
        CV_Error(-217,"Selected device don't support double\r\n");
        return;
    }

    dst.create(src1.size(), src1.type());
    CV_Assert(src1.cols == src2.cols && src2.cols == dst.cols &&
              src1.rows == src2.rows && src2.rows == dst.rows &&
              src1.rows == mask.rows && src1.cols == mask.cols);

    CV_Assert(src1.type() == src2.type() && src1.type() == dst.type());
    CV_Assert(src1.depth() != CV_8S);
    CV_Assert(mask.type() == CV_8U);

    Context  *clCxt = src1.clCxt;
    int channels = dst.channels();
    int depth = dst.depth();

    int vector_lengths[4][7] = {{4, 4, 2, 2, 1, 1, 1},
        {2, 2, 1, 1, 1, 1, 1},
        {4, 4, 2, 2 , 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1}
    };

    size_t vector_length = vector_lengths[channels-1][depth];
    int offset_cols = ((dst.offset % dst.step) / dst.elemSize()) & (vector_length - 1);
    int cols = divUp(dst.cols + offset_cols, vector_length);

    size_t localThreads[3]  = { 64, 4, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
                                divUp(dst.rows, localThreads[1]) * localThreads[1],
                                1
                              };

    int dst_step1 = dst.cols * dst.elemSize();
    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src1.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src2.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&mask.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&mask.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&mask.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.offset ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst_step1 ));

    openCLExecuteKernel(clCxt, kernelString, kernelName, globalThreads, localThreads, args, channels, depth);
}
void cv::ocl::add(const oclMat &src1, const oclMat &src2, oclMat &dst)
{
    arithmetic_run(src1, src2, dst, "arithm_add", &arithm_add);
}
void cv::ocl::add(const oclMat &src1, const oclMat &src2, oclMat &dst, const oclMat &mask)
{
    arithmetic_run(src1, src2, dst, mask, "arithm_add_with_mask", &arithm_add);
}

void cv::ocl::subtract(const oclMat &src1, const oclMat &src2, oclMat &dst)
{
    arithmetic_run(src1, src2, dst, "arithm_sub", &arithm_sub);
}
void cv::ocl::subtract(const oclMat &src1, const oclMat &src2, oclMat &dst, const oclMat &mask)
{
    arithmetic_run(src1, src2, dst, mask, "arithm_sub_with_mask", &arithm_sub);
}
typedef void (*MulDivFunc)(const oclMat &src1, const oclMat &src2, oclMat &dst, string kernelName,
                           const char **kernelString, void *scalar);

void cv::ocl::multiply(const oclMat &src1, const oclMat &src2, oclMat &dst, double scalar)
{
    static MulDivFunc tab[] =
    {
        arithmetic_run<float>, 0, arithmetic_run<float>, arithmetic_run<float>,
        arithmetic_run<float>, arithmetic_run<float>, arithmetic_run<double>,
    };

    tab[src1.depth()](src1, src2, dst, "arithm_mul", &arithm_mul, (void *)(&scalar));
}
void cv::ocl::divide(const oclMat &src1, const oclMat &src2, oclMat &dst, double scalar)
{
    if(src1.clCxt -> impl -> double_support ==0)
    {
        CV_Error(-217,"Selected device don't support double\r\n");
        return;
    }

    arithmetic_run<double>(src1, src2, dst, "arithm_div", &arithm_div, (void *)(&scalar));
}
    template <typename WT ,typename CL_WT>
void arithmetic_scalar_run(const oclMat &src1, const Scalar &src2, oclMat &dst, const oclMat &mask, string kernelName, const char **kernelString, int isMatSubScalar)
{
    if(src1.clCxt -> impl -> double_support ==0 && src1.type() == CV_64F)
    {
        CV_Error(-217,"Selected device don't support double\r\n");
        return;
    }

    dst.create(src1.size(), src1.type());

    CV_Assert(src1.cols == dst.cols && src1.rows == dst.rows &&
            src1.type() == dst.type());

    //CV_Assert(src1.depth() != CV_8S);

    if(mask.data)
        CV_Assert(mask.type() == CV_8U && src1.rows == mask.rows && src1.cols == mask.cols);

    Context  *clCxt = src1.clCxt;
    int channels = dst.channels();
    int depth = dst.depth();

    WT s[4] = { saturate_cast<WT>(src2.val[0]), saturate_cast<WT>(src2.val[1]),
        saturate_cast<WT>(src2.val[2]), saturate_cast<WT>(src2.val[3])
    };

    int vector_lengths[4][7] = {{4, 0, 2, 2, 1, 1, 1},
        {2, 0, 1, 1, 1, 1, 1},
        {4, 0, 2, 2 , 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1}
    };

    size_t vector_length = vector_lengths[channels-1][depth];
    int offset_cols = ((dst.offset % dst.step) / dst.elemSize()) & (vector_length - 1);
    int cols = divUp(dst.cols + offset_cols, vector_length);

    size_t localThreads[3]  = { 64, 4, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
        divUp(dst.rows, localThreads[1]) * localThreads[1],
        1
    };

    int dst_step1 = dst.cols * dst.elemSize();
    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_mem) , (void *)&src1.data ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&src1.step ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&src1.offset));
    args.push_back( make_pair( sizeof(cl_mem) , (void *)&dst.data ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&dst.step ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&dst.offset));

    if(mask.data)
    {
        args.push_back( make_pair( sizeof(cl_mem) , (void *)&mask.data ));
        args.push_back( make_pair( sizeof(cl_int) , (void *)&mask.step ));
        args.push_back( make_pair( sizeof(cl_int) , (void *)&mask.offset));
    }
    args.push_back( make_pair( sizeof(CL_WT) ,  (void *)&s ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&src1.rows ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&dst_step1 ));
    if(isMatSubScalar != 0)
    {
        isMatSubScalar = isMatSubScalar > 0 ? 1 : 0;
        args.push_back( make_pair( sizeof(cl_int) , (void *)&isMatSubScalar));
    }

    openCLExecuteKernel(clCxt, kernelString, kernelName, globalThreads, localThreads, args, channels, depth);
}

void arithmetic_scalar_run(const oclMat &src, oclMat &dst, string kernelName, const char **kernelString, double scalar)
{
    if(src.clCxt -> impl -> double_support ==0 && src.type() == CV_64F)
    {
        CV_Error(-217,"Selected device don't support double\r\n");
        return;
    }

    dst.create(src.size(), src.type());
    CV_Assert(src.cols == dst.cols && src.rows == dst.rows);

    CV_Assert(src.type() == dst.type());
    CV_Assert(src.depth() != CV_8S);

    Context  *clCxt = src.clCxt;
    int channels = dst.channels();
    int depth = dst.depth();

    int vector_lengths[4][7] = {{4, 0, 4, 4, 1, 1, 1},
        {4, 0, 4, 4, 1, 1, 1},
        {4, 0, 4, 4 , 1, 1, 1},
        {4, 0, 4, 4, 1, 1, 1}
    };

    size_t vector_length = vector_lengths[channels-1][depth];
    int offset_cols = (dst.offset / dst.elemSize1()) & (vector_length - 1);
    int cols = divUp(dst.cols * channels + offset_cols, vector_length);

    size_t localThreads[3]  = { 64, 4, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
        divUp(dst.rows, localThreads[1]) * localThreads[1],
        1
    };

    int dst_step1 = dst.cols * dst.elemSize();
    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.offset ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src.rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst_step1 ));
    args.push_back( make_pair( sizeof(cl_double), (void *)&scalar ));

    openCLExecuteKernel(clCxt, kernelString, kernelName, globalThreads, localThreads, args, -1, depth);
}

typedef void (*ArithmeticFuncS)(const oclMat &src1, const Scalar &src2, oclMat &dst, const oclMat &mask, string kernelName, const char **kernelString, int isMatSubScalar);


void arithmetic_scalar(const oclMat &src1, const Scalar &src2, oclMat &dst, const oclMat &mask, string kernelName, const char **kernelString, int isMatSubScalar)
{
    static ArithmeticFuncS tab[8] =
    {
        arithmetic_scalar_run<int, cl_int4>,
        arithmetic_scalar_run<int, cl_int4>,
        arithmetic_scalar_run<int, cl_int4>,
        arithmetic_scalar_run<int, cl_int4>,
        arithmetic_scalar_run<int, cl_int4>,
        arithmetic_scalar_run<float, cl_float4>,
        arithmetic_scalar_run<double, cl_double4>,
        0
    };
    ArithmeticFuncS func = tab[src1.depth()];
    if(func == 0)
        cv::ocl::error("Unsupported arithmetic operation", __FILE__, __LINE__);
    func(src1, src2, dst, mask, kernelName, kernelString, isMatSubScalar);
}
void arithmetic_scalar(const oclMat &src1, const Scalar &src2, oclMat &dst, const oclMat &mask, string kernelName, const char **kernelString)
{
    arithmetic_scalar(src1, src2, dst, mask, kernelName, kernelString, 0);
}

void cv::ocl::add(const oclMat &src1, const Scalar &src2, oclMat &dst, const oclMat &mask)
{
    string kernelName = mask.data ? "arithm_s_add_with_mask" : "arithm_s_add";
    const char **kernelString = mask.data ? &arithm_add_scalar_mask : &arithm_add_scalar;

    arithmetic_scalar( src1, src2, dst, mask, kernelName, kernelString);
}

void cv::ocl::subtract(const oclMat &src1, const Scalar &src2, oclMat &dst, const oclMat &mask)
{
    string kernelName = mask.data ? "arithm_s_sub_with_mask" : "arithm_s_sub";
    const char **kernelString = mask.data ? &arithm_sub_scalar_mask : &arithm_sub_scalar;
    arithmetic_scalar( src1, src2, dst, mask, kernelName, kernelString, 1);
}
void cv::ocl::subtract(const Scalar &src2, const oclMat &src1, oclMat &dst, const oclMat &mask)
{
    string kernelName = mask.data ? "arithm_s_sub_with_mask" : "arithm_s_sub";
    const char **kernelString = mask.data ? &arithm_sub_scalar_mask : &arithm_sub_scalar;
    arithmetic_scalar( src1, src2, dst, mask, kernelName, kernelString, -1);
}
void cv::ocl::divide(double scalar, const oclMat &src,  oclMat &dst)
{
    if(src.clCxt -> impl -> double_support ==0)
    {
        CV_Error(-217,"Selected device don't support double\r\n");
        return;
    }

    string kernelName =  "arithm_s_div";
    arithmetic_scalar_run(src, dst, kernelName, &arithm_div, scalar);
}
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////  Absdiff ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void cv::ocl::absdiff(const oclMat &src1, const oclMat &src2, oclMat &dst)
{
    arithmetic_run(src1, src2, dst, "arithm_absdiff", &arithm_absdiff);
}
void cv::ocl::absdiff(const oclMat &src1, const Scalar &src2, oclMat &dst)
{
    string kernelName = "arithm_s_absdiff";
    oclMat mask;
    arithmetic_scalar( src1, src2, dst, mask, kernelName, &arithm_absdiff);
}
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////  compare ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void compare_run(const oclMat &src1, const oclMat &src2, oclMat &dst, string kernelName, const char **kernelString)
{
    dst.create(src1.size(), CV_8UC1);
    CV_Assert(src1.channels() == 1);
    CV_Assert(src1.type() == src2.type());
    Context  *clCxt = src1.clCxt;
    int depth = src1.depth();
    int vector_lengths[7] = {4, 0, 4, 4, 4, 4, 4};
    size_t vector_length = vector_lengths[depth];
    int offset_cols = (dst.offset / dst.elemSize1()) & (vector_length - 1);
    int cols = divUp(dst.cols  + offset_cols, vector_length);
    size_t localThreads[3]  = { 64, 4, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
                                divUp(dst.rows, localThreads[1]) * localThreads[1],
                                1
                              };
    int dst_step1 = dst.cols * dst.elemSize();
    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src1.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src2.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.offset ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst_step1 ));
    openCLExecuteKernel(clCxt, kernelString, kernelName, globalThreads, localThreads, args, -1, depth);
}

void cv::ocl::compare(const oclMat &src1, const oclMat &src2, oclMat &dst , int cmpOp)
{
    if(src1.clCxt -> impl -> double_support ==0)
    {
        cout << "Selected device do not support double" << endl;
        return;
    }
    string kernelName;
    const char **kernelString = NULL;
    switch( cmpOp )
    {
    case CMP_EQ:
        kernelName = "arithm_compare_eq";
        kernelString = &arithm_compare_eq;
        break;
    case CMP_GT:
        kernelName = "arithm_compare_gt";
        kernelString = &arithm_compare_eq;
        break;
    case CMP_GE:
        kernelName = "arithm_compare_ge";
        kernelString = &arithm_compare_eq;
        break;
    case CMP_NE:
        kernelName = "arithm_compare_ne";
        kernelString = &arithm_compare_ne;
        break;
    case CMP_LT:
        kernelName = "arithm_compare_lt";
        kernelString = &arithm_compare_ne;
        break;
    case CMP_LE:
        kernelName = "arithm_compare_le";
        kernelString = &arithm_compare_ne;
        break;
    default:
        CV_Error(CV_StsBadArg, "Unknown comparison method");
    }
    compare_run(src1, src2, dst, kernelName, kernelString);
}

//////////////////////////////////////////////////////////////////////////////
////////////////////////////////// sum  //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//type = 0 sum,type = 1 absSum,type = 2 sqrSum
void arithmetic_sum_buffer_run(const oclMat &src, cl_mem &dst, int vlen , int groupnum, int type = 0)
{
    vector<pair<size_t , const void *> > args;
    int all_cols = src.step / (vlen * src.elemSize1());
    int pre_cols = (src.offset % src.step) / (vlen * src.elemSize1());
    int sec_cols = all_cols - (src.offset % src.step + src.cols * src.elemSize() - 1) / (vlen * src.elemSize1()) - 1;
    int invalid_cols = pre_cols + sec_cols;
    int cols = all_cols - invalid_cols , elemnum = cols * src.rows;;
    int offset = src.offset / (vlen * src.elemSize1());
    int repeat_s = src.offset / src.elemSize1() - offset * vlen;
    int repeat_e = (offset + cols) * vlen - src.offset / src.elemSize1() - src.cols * src.channels();
    char build_options[512];
    CV_Assert(type == 0 || type == 1 || type == 2);
    sprintf(build_options, "-D DEPTH_%d -D REPEAT_S%d -D REPEAT_E%d -D FUNC_TYPE_%d", src.depth(), repeat_s, repeat_e, type);
    args.push_back( make_pair( sizeof(cl_int) , (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&invalid_cols ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&offset));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&elemnum));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&groupnum));
    args.push_back( make_pair( sizeof(cl_mem) , (void *)&src.data));
    args.push_back( make_pair( sizeof(cl_mem) , (void *)&dst ));
    size_t gt[3] = {groupnum * 256, 1, 1}, lt[3] = {256, 1, 1};
    if(src.channels() != 3)
        openCLExecuteKernel(src.clCxt, &arithm_sum, "arithm_op_sum", gt, lt, args, -1, -1, build_options);
    else
        openCLExecuteKernel(src.clCxt, &arithm_sum_3, "arithm_op_sum_3", gt, lt, args, -1, -1, build_options);
}

template <typename T>
Scalar arithmetic_sum(const oclMat &src)
{
    size_t groupnum = src.clCxt->impl->maxComputeUnits;
    CV_Assert(groupnum != 0);
    int vlen = src.channels() == 3 ? 12 : 8, dbsize = groupnum * vlen, status;
    Context *clCxt = src.clCxt;
    T *p = new T[dbsize];
    cl_mem dstBuffer = openCLCreateBuffer(clCxt,CL_MEM_WRITE_ONLY,dbsize*sizeof(T));
    Scalar s;
    s.val[0] = 0.0;
    s.val[1] = 0.0;
    s.val[2] = 0.0;
    s.val[3] = 0.0;
    arithmetic_sum_buffer_run(src, dstBuffer, vlen, groupnum);

    memset(p, 0, dbsize * sizeof(T));
    openCLReadBuffer(clCxt,dstBuffer,(void *)p,dbsize*sizeof(T));
    for(int i = 0; i < dbsize;)
    {
        for(int j = 0; j < src.channels(); j++, i++)
            s.val[j] += p[i];
    }
    delete[] p;
    openCLFree(dstBuffer);
    return s;
}

typedef Scalar (*sumFunc)(const oclMat &src);
Scalar cv::ocl::sum(const oclMat &src)
{
    if(src.clCxt->impl->double_support==0 && src.depth()==CV_64F)
    {
        CV_Error(-217,"select device don't support double");
    }
    static sumFunc functab[2] =
    {
        arithmetic_sum<float>,
        arithmetic_sum<double>
    };

    sumFunc func;
    func = functab[src.clCxt->impl->double_support];
    return func(src);
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////// meanStdDev //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void cv::ocl::meanStdDev(const oclMat &src, Scalar &mean, Scalar &stddev)
{
    CV_Assert(src.depth() <= CV_32S);
    cv::Size sz(1, 1);
    int channels = src.channels();
    Mat m1(sz, CV_MAKETYPE(CV_32S, channels), cv::Scalar::all(0)),
        m2(sz, CV_MAKETYPE(CV_32S, channels), cv::Scalar::all(0));
    oclMat dst1(m1), dst2(m2);
    //arithmetic_sum_run(src, dst1,"arithm_op_sum");
    //arithmetic_sum_run(src, dst2,"arithm_op_squares_sum");
    m1 = (Mat)dst1;
    m2 = (Mat)dst2;
    int i = 0, *p = (int *)m1.data, *q = (int *)m2.data;
    for(; i < channels; i++)
    {
        mean.val[i] = (double)p[i] / (src.cols * src.rows);
        stddev.val[i] = std::sqrt(std::max((double) q[i] / (src.cols * src.rows) - mean.val[i] * mean.val[i] , 0.));
    }
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// minMax  /////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void arithmetic_minMax_run(const oclMat &src, const oclMat &mask, cl_mem &dst, int vlen , int groupnum, string kernelName)
{
    vector<pair<size_t , const void *> > args;
    int all_cols = src.step / (vlen * src.elemSize1());
    int pre_cols = (src.offset % src.step) / (vlen * src.elemSize1());
    int sec_cols = all_cols - (src.offset % src.step + src.cols * src.elemSize() - 1) / (vlen * src.elemSize1()) - 1;
    int invalid_cols = pre_cols + sec_cols;
    int cols = all_cols - invalid_cols , elemnum = cols * src.rows;;
    int offset = src.offset / (vlen * src.elemSize1());
    int repeat_s = src.offset / src.elemSize1() - offset * vlen;
    int repeat_e = (offset + cols) * vlen - src.offset / src.elemSize1() - src.cols * src.channels();
    char build_options[50];
    sprintf(build_options, "-D DEPTH_%d -D REPEAT_S%d -D REPEAT_E%d", src.depth(), repeat_s, repeat_e);
    args.push_back( make_pair( sizeof(cl_int) , (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&invalid_cols ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&offset));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&elemnum));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&groupnum));
    args.push_back( make_pair( sizeof(cl_mem) , (void *)&src.data));
    if(!mask.empty())
    {
        int mall_cols = mask.step / (vlen * mask.elemSize1());
        int mpre_cols = (mask.offset % mask.step) / (vlen * mask.elemSize1());
        int msec_cols = mall_cols - (mask.offset % mask.step + mask.cols * mask.elemSize() - 1) / (vlen * mask.elemSize1()) - 1;
        int minvalid_cols = mpre_cols + msec_cols;
        int moffset = mask.offset / (vlen * mask.elemSize1());

        args.push_back( make_pair( sizeof(cl_int) , (void *)&minvalid_cols ));
        args.push_back( make_pair( sizeof(cl_int) , (void *)&moffset ));
        args.push_back( make_pair( sizeof(cl_mem) , (void *)&mask.data ));
    }
    args.push_back( make_pair( sizeof(cl_mem) , (void *)&dst ));
    size_t gt[3] = {groupnum * 256, 1, 1}, lt[3] = {256, 1, 1};
    openCLExecuteKernel(src.clCxt, &arithm_minMax, kernelName, gt, lt, args, -1, -1, build_options);
}


void arithmetic_minMax_mask_run(const oclMat &src, const oclMat &mask, cl_mem &dst, int vlen, int groupnum, string kernelName)
{
    vector<pair<size_t , const void *> > args;
    size_t gt[3] = {groupnum * 256, 1, 1}, lt[3] = {256, 1, 1};
    char build_options[50];
    if(src.channels() == 1)
    {
        int cols = (src.cols - 1) / vlen + 1;
        int invalid_cols = src.step / (vlen * src.elemSize1()) - cols;
        int offset = src.offset / src.elemSize1();
        int repeat_me = vlen - (mask.cols % vlen == 0 ? vlen : mask.cols % vlen);
        int minvalid_cols = mask.step / (vlen * mask.elemSize1()) - cols;
        int moffset = mask.offset / mask.elemSize1();
        int elemnum = cols * src.rows;
        sprintf(build_options, "-D DEPTH_%d -D REPEAT_E%d", src.depth(), repeat_me);
        args.push_back( make_pair( sizeof(cl_int) , (void *)&cols ));
        args.push_back( make_pair( sizeof(cl_int) , (void *)&invalid_cols ));
        args.push_back( make_pair( sizeof(cl_int) , (void *)&offset));
        args.push_back( make_pair( sizeof(cl_int) , (void *)&elemnum));
        args.push_back( make_pair( sizeof(cl_int) , (void *)&groupnum));
        args.push_back( make_pair( sizeof(cl_mem) , (void *)&src.data));
        args.push_back( make_pair( sizeof(cl_int) , (void *)&minvalid_cols ));
        args.push_back( make_pair( sizeof(cl_int) , (void *)&moffset ));
        args.push_back( make_pair( sizeof(cl_mem) , (void *)&mask.data ));
        args.push_back( make_pair( sizeof(cl_mem) , (void *)&dst ));
        //        printf("elemnum:%d,cols:%d,invalid_cols:%d,offset:%d,minvalid_cols:%d,moffset:%d,repeat_e:%d\r\n",
        //               elemnum,cols,invalid_cols,offset,minvalid_cols,moffset,repeat_me);
        openCLExecuteKernel(src.clCxt, &arithm_minMax_mask, kernelName, gt, lt, args, -1, -1, build_options);
    }
}

template <typename T> void arithmetic_minMax(const oclMat &src, double *minVal, double *maxVal, const oclMat &mask)
{
    size_t groupnum = src.clCxt->impl->maxComputeUnits;
    CV_Assert(groupnum != 0);
    groupnum = groupnum * 2;
    int vlen = 8;
    int dbsize = groupnum * 2 * vlen * sizeof(T) , status;
    Context *clCxt = src.clCxt;
    cl_mem dstBuffer = openCLCreateBuffer(clCxt,CL_MEM_WRITE_ONLY,dbsize);
    *minVal = std::numeric_limits<double>::max() , *maxVal = -std::numeric_limits<double>::max();
    if (mask.empty())
    {
        arithmetic_minMax_run(src, mask, dstBuffer, vlen, groupnum, "arithm_op_minMax");
    }
    else
    {
        arithmetic_minMax_mask_run(src, mask, dstBuffer, vlen, groupnum, "arithm_op_minMax_mask");
    }
    T *p = new T[groupnum * vlen * 2];
    memset(p, 0, dbsize);
    openCLReadBuffer(clCxt,dstBuffer,(void *)p,dbsize);
    for(int i = 0; i < vlen * groupnum; i++)
    {
        *minVal = *minVal < p[i] ? *minVal : p[i];
    }
    for(int i = vlen * groupnum; i < 2 * vlen * groupnum; i++)
    {
        *maxVal = *maxVal > p[i] ? *maxVal : p[i];
    }
    delete[] p;
    openCLFree(dstBuffer);
}

typedef void (*minMaxFunc)(const oclMat &src, double *minVal, double *maxVal, const oclMat &mask);
void cv::ocl::minMax(const oclMat &src, double *minVal, double *maxVal, const oclMat &mask)
{
    CV_Assert(src.channels() == 1);
    if(src.clCxt->impl->double_support==0 && src.depth()==CV_64F)
    {
        CV_Error(-217,"select device don't support double");
    }
    static minMaxFunc functab[8] =
    {
        arithmetic_minMax<uchar>,
        arithmetic_minMax<char>,
        arithmetic_minMax<ushort>,
        arithmetic_minMax<short>,
        arithmetic_minMax<int>,
        arithmetic_minMax<float>,
        arithmetic_minMax<double>,
        0
    };
    minMaxFunc func;
    func = functab[src.depth()];
    func(src, minVal, maxVal, mask);
}

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// norm /////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
double cv::ocl::norm(const oclMat &src1, int normType)
{
    return norm(src1, oclMat(src1.size(), src1.type(), Scalar::all(0)), normType);
}

double cv::ocl::norm(const oclMat &src1, const oclMat &src2, int normType)
{
    bool isRelative = (normType & NORM_RELATIVE) != 0;
    normType &= 7;
    CV_Assert(src1.depth() <= CV_32S && src1.type() == src2.type() && ( normType == NORM_INF || normType == NORM_L1 || normType == NORM_L2));
    int channels = src1.channels(), i = 0, *p;
    double r = 0;
    oclMat gm1(src1.size(), src1.type());
    int min_int = (normType == NORM_INF ? CL_INT_MIN : 0);
    Mat m(1, 1, CV_MAKETYPE(CV_32S, channels), cv::Scalar::all(min_int));
    oclMat gm2(m), emptyMat;
    switch(normType)
    {
    case NORM_INF:
        //  arithmetic_run(src1, src2, gm1, "arithm_op_absdiff");
        //arithmetic_minMax_run(gm1,emptyMat, gm2,"arithm_op_max");
        m = (gm2);
        p = (int *)m.data;
        r = -std::numeric_limits<double>::max();
        for(i = 0; i < channels; i++)
        {
            r = std::max(r, (double)p[i]);
        }
        break;
    case NORM_L1:
        //arithmetic_run(src1, src2, gm1, "arithm_op_absdiff");
        //arithmetic_sum_run(gm1, gm2,"arithm_op_sum");
        m = (gm2);
        p = (int *)m.data;
        for(i = 0; i < channels; i++)
        {
            r = r + (double)p[i];
        }
        break;
    case NORM_L2:
        //arithmetic_run(src1, src2, gm1, "arithm_op_absdiff");
        //arithmetic_sum_run(gm1, gm2,"arithm_op_squares_sum");
        m = (gm2);
        p = (int *)m.data;
        for(i = 0; i < channels; i++)
        {
            r = r + (double)p[i];
        }
        r = std::sqrt(r);
        break;
    }
    if(isRelative)
        r = r / norm(src2, normType);
    return r;
}

//////////////////////////////////////////////////////////////////////////////
////////////////////////////////// flip //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void arithmetic_flip_rows_run(const oclMat &src, oclMat &dst, string kernelName)
{
    if(src.clCxt -> impl -> double_support ==0 && src.type() == CV_64F)
    {
        CV_Error(-217,"Selected device don't support double\r\n");
        return;
    }

    CV_Assert(src.cols == dst.cols && src.rows == dst.rows);

    CV_Assert(src.type() == dst.type());

    Context  *clCxt = src.clCxt;
    int channels = dst.channels();
    int depth = dst.depth();

    int vector_lengths[4][7] = {{4, 4, 4, 4, 1, 1, 1},
        {4, 4, 4, 4, 1, 1, 1},
        {4, 4, 4, 4, 1, 1, 1},
        {4, 4, 4, 4, 1, 1, 1}
    };

    size_t vector_length = vector_lengths[channels-1][depth];
    int offset_cols = ((dst.offset % dst.step) / dst.elemSize1()) & (vector_length - 1);

    int cols = divUp(dst.cols * channels + offset_cols, vector_length);
    int rows = divUp(dst.rows, 2);

    size_t localThreads[3]  = { 64, 4, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
                                divUp(rows, localThreads[1]) * localThreads[1],
                                1
                              };

    int dst_step1 = dst.cols * dst.elemSize();
    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.offset ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst_step1 ));

    openCLExecuteKernel(clCxt, &arithm_flip, kernelName, globalThreads, localThreads, args, -1, depth);
}
void arithmetic_flip_cols_run(const oclMat &src, oclMat &dst, string kernelName, bool isVertical)
{
    if(src.clCxt -> impl -> double_support ==0 && src.type() == CV_64F)
    {
        CV_Error(-217,"Selected device don't support double\r\n");
        return;
    }

    CV_Assert(src.cols == dst.cols && src.rows == dst.rows);
    CV_Assert(src.type() == dst.type());

    Context  *clCxt = src.clCxt;
    int channels = dst.channels();
    int depth = dst.depth();

    int vector_lengths[4][7] = {{1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1}
    };

    size_t vector_length = vector_lengths[channels-1][depth];
    int offset_cols = ((dst.offset % dst.step) / dst.elemSize()) & (vector_length - 1);
    int cols = divUp(dst.cols + offset_cols, vector_length);
    cols = isVertical ? cols : divUp(cols, 2);
    int rows = isVertical ?  divUp(dst.rows, 2) : dst.rows;

    size_t localThreads[3]  = { 64, 4, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
                                divUp(rows, localThreads[1]) * localThreads[1],
                                1
                              };

    int dst_step1 = dst.cols * dst.elemSize();
    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.offset ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.cols ));

    if(isVertical)
        args.push_back( make_pair( sizeof(cl_int), (void *)&rows ));
    else
        args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));

    args.push_back( make_pair( sizeof(cl_int), (void *)&dst_step1 ));

    const char **kernelString = isVertical ? &arithm_flip_rc : &arithm_flip;

    openCLExecuteKernel(clCxt, kernelString, kernelName, globalThreads, localThreads, args, src.channels(), depth);
}
void cv::ocl::flip(const oclMat &src, oclMat &dst, int flipCode)
{
    dst.create(src.size(), src.type());
    if(flipCode == 0)
    {
        arithmetic_flip_rows_run(src, dst, "arithm_flip_rows");
    }
    else if(flipCode > 0)
        arithmetic_flip_cols_run(src, dst, "arithm_flip_cols", false);
    else
        arithmetic_flip_cols_run(src, dst, "arithm_flip_rc", true);
}

//////////////////////////////////////////////////////////////////////////////
////////////////////////////////// LUT  //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void arithmetic_lut_run(const oclMat &src1, const oclMat &src2, oclMat &dst, string kernelName)
{
    Context *clCxt = src1.clCxt;
    int channels = src1.channels();
    int rows = src1.rows;
    int cols = src1.cols;
    //int step = src1.step;
    int src_step = src1.step;
    int dst_step = dst.step;
    int whole_rows = src1.wholerows;
    int whole_cols = src1.wholecols;
    int src_offset = src1.offset;
    int dst_offset = dst.offset;
    int lut_offset = src2.offset;
    int left_col = 0, right_col = 0;
    size_t localSize[] = {16, 16, 1};
    //cl_kernel kernel = openCLGetKernelFromSource(clCxt,&arithm_LUT,kernelName);
    size_t globalSize[] = {(cols + localSize[0] - 1) / localSize[0]*localSize[0], (rows + localSize[1] - 1) / localSize[1]*localSize[1], 1};
    if(channels == 1 && cols > 6)
    {
        left_col = 4 - (dst_offset & 3);
        left_col &= 3;
        dst_offset += left_col;
        src_offset += left_col;
        cols -= left_col;
        right_col = cols & 3;
        cols -= right_col;
        globalSize[0] = (cols / 4 + localSize[0] - 1) / localSize[0] * localSize[0];
    }
    else if(channels == 1)
    {
        left_col = cols;
        right_col = 0;
        cols = 0;
        globalSize[0] = 0;
    }
    CV_Assert(clCxt == dst.clCxt);
    CV_Assert(src1.cols == dst.cols);
    CV_Assert(src1.rows == dst.rows);
    CV_Assert(src1.channels() == dst.channels());
    //  CV_Assert(src1.step == dst.step);
    vector<pair<size_t , const void *> > args;

    if(globalSize[0] != 0)
    {
        args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
        args.push_back( make_pair( sizeof(cl_mem), (void *)&src1.data ));
        args.push_back( make_pair( sizeof(cl_mem), (void *)&src2.data ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&rows ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&channels ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&whole_rows ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&whole_cols ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&src_offset ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&dst_offset ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&lut_offset ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&src_step ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&dst_step ));
        openCLExecuteKernel(clCxt, &arithm_LUT, kernelName, globalSize, localSize, args, src1.channels(), src1.depth());
    }
    if(channels == 1 && (left_col != 0 || right_col != 0))
    {
        src_offset = src1.offset;
        dst_offset = dst.offset;
        localSize[0] = 1;
        localSize[1] = 256;
        globalSize[0] = left_col + right_col;
        globalSize[1] = (rows + localSize[1] - 1) / localSize[1] * localSize[1];
        //kernel = openCLGetKernelFromSource(clCxt,&arithm_LUT,"LUT2");
        args.clear();
        args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
        args.push_back( make_pair( sizeof(cl_mem), (void *)&src1.data ));
        args.push_back( make_pair( sizeof(cl_mem), (void *)&src2.data ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&rows ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&left_col ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&channels ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&whole_rows ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&src_offset ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&dst_offset ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&lut_offset ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&src_step ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&dst_step ));
        openCLExecuteKernel(clCxt, &arithm_LUT, "LUT2", globalSize, localSize, args, src1.channels(), src1.depth());
    }
}

void cv::ocl::LUT(const oclMat &src, const oclMat &lut, oclMat &dst)
{
    int cn = src.channels();
    CV_Assert(src.depth() == CV_8U);
    CV_Assert((lut.channels() == 1 || lut.channels() == cn) && lut.rows == 1 && lut.cols == 256);
    dst.create(src.size(), CV_MAKETYPE(lut.depth(), cn));
    //oclMat _lut(lut);
    string kernelName = "LUT";
    arithmetic_lut_run(src, lut, dst, kernelName);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////// exp log /////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void arithmetic_exp_log_run(const oclMat &src, oclMat &dst, string kernelName, const char **kernelString)
{
    dst.create(src.size(), src.type());
    CV_Assert(src.cols == dst.cols &&
              src.rows == dst.rows );

    CV_Assert(src.type() == dst.type());
    CV_Assert( src.type() == CV_32F || src.type() == CV_64F);

    Context  *clCxt = src.clCxt;

    //int channels = dst.channels();
    int depth = dst.depth();

    size_t localThreads[3]  = { 64, 4, 1 };
    size_t globalThreads[3] = { divUp(dst.cols, localThreads[0]) * localThreads[0],
                                divUp(dst.rows, localThreads[1]) * localThreads[1],
                                1
                              };

    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_int), (void *)&src.rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src.cols ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src.offset ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src.data ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));

    openCLExecuteKernel(clCxt, kernelString, kernelName, globalThreads, localThreads, args, -1, depth);
}
void cv::ocl::exp(const oclMat &src, oclMat &dst)
{
    arithmetic_exp_log_run(src, dst, "arithm_exp", &arithm_exp);
}

void cv::ocl::log(const oclMat &src, oclMat &dst)
{
    arithmetic_exp_log_run(src, dst, "arithm_log", &arithm_log);
}

//////////////////////////////////////////////////////////////////////////////
////////////////////////////// magnitude phase ///////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void arithmetic_magnitude_phase_run(const oclMat &src1, const oclMat &src2, oclMat &dst, string kernelName)
{
    if(src1.clCxt -> impl -> double_support ==0 && src1.type() == CV_64F)
    {
        CV_Error(-217,"Selected device don't support double\r\n");
        return;
    }

    Context  *clCxt = src1.clCxt;
    int channels = dst.channels();
    int depth = dst.depth();

    size_t vector_length = 1;
    int offset_cols = ((dst.offset % dst.step) / dst.elemSize1()) & (vector_length - 1);
    int cols = divUp(dst.cols * channels + offset_cols, vector_length);
    int rows = dst.rows;

    size_t localThreads[3]  = { 64, 4, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
                                divUp(rows, localThreads[1]) * localThreads[1],
                                1
                              };

    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src1.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src2.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.offset ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));

    openCLExecuteKernel(clCxt, &arithm_magnitude, kernelName, globalThreads, localThreads, args, -1, depth);
}

void cv::ocl::magnitude(const oclMat &src1, const oclMat &src2, oclMat &dst)
{
    CV_Assert(src1.type() == src2.type() && src1.size() == src2.size() &&
              (src1.depth() == CV_32F || src1.depth() == CV_64F));

    dst.create(src1.size(), src1.type());
    arithmetic_magnitude_phase_run(src1, src2, dst, "arithm_magnitude");
}

void arithmetic_phase_run(const oclMat &src1, const oclMat &src2, oclMat &dst, string kernelName, const char **kernelString)
{
    if(src1.clCxt -> impl -> double_support ==0 && src1.type() == CV_64F)
    {
        CV_Error(-217,"Selected device don't support double\r\n");
        return;
    }

    CV_Assert(src1.cols == src2.cols && src2.cols == dst.cols && src1.rows == src2.rows && src2.rows == dst.rows);
    CV_Assert(src1.type() == src2.type() && src1.type() == dst.type());

    Context  *clCxt = src1.clCxt;
    int channels = dst.channels();
    int depth = dst.depth();

    size_t vector_length = 1;
    int offset_cols = ((dst.offset % dst.step) / dst.elemSize1()) & (vector_length - 1);
    int cols = divUp(dst.cols * channels + offset_cols, vector_length);
    int rows = dst.rows;

    size_t localThreads[3]  = { 64, 4, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
                                divUp(rows, localThreads[1]) * localThreads[1],
                                1
                              };

    int dst_step1 = dst.cols * dst.elemSize();
    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src1.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src2.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.offset ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst_step1 ));

    openCLExecuteKernel(clCxt, kernelString, kernelName, globalThreads, localThreads, args, -1, depth);
}
void cv::ocl::phase(const oclMat &x, const oclMat &y, oclMat &Angle , bool angleInDegrees)
{
    CV_Assert(x.type() == y.type() && x.size() == y.size() && (x.depth() == CV_32F || x.depth() == CV_64F));
    Angle.create(x.size(), x.type());
    string kernelName = angleInDegrees ? "arithm_phase_indegrees" : "arithm_phase_inradians";
    if(angleInDegrees)
    {
        arithmetic_phase_run(x, y, Angle, kernelName, &arithm_phase);
        //cout<<"1"<<endl;
    }
    else
    {
        arithmetic_phase_run(x, y, Angle, kernelName, &arithm_phase);
        //cout<<"2"<<endl;
    }
}

//////////////////////////////////////////////////////////////////////////////
////////////////////////////////// cartToPolar ///////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void arithmetic_cartToPolar_run(const oclMat &src1, const oclMat &src2, oclMat &dst_mag, oclMat &dst_cart,
                                string kernelName, bool angleInDegrees)
{
    if(src1.clCxt -> impl -> double_support ==0 && src1.type() == CV_64F)
    {
        CV_Error(-217,"Selected device don't support double\r\n");
        return;
    }

    Context  *clCxt = src1.clCxt;
    int channels = src1.channels();
    int depth = src1.depth();

    int cols = src1.cols * channels;
    int rows = src1.rows;

    size_t localThreads[3]  = { 64, 4, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
                                divUp(rows, localThreads[1]) * localThreads[1],
                                1
                              };

    int tmp = angleInDegrees ? 1 : 0;
    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src1.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src2.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst_mag.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst_mag.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst_mag.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst_cart.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst_cart.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst_cart.offset ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&tmp ));

    openCLExecuteKernel(clCxt, &arithm_cartToPolar, kernelName, globalThreads, localThreads, args, -1, depth);
}
void cv::ocl::cartToPolar(const oclMat &x, const oclMat &y, oclMat &mag, oclMat &angle, bool angleInDegrees)
{
    CV_Assert(x.type() == y.type() && x.size() == y.size() && (x.depth() == CV_32F || x.depth() == CV_64F));

    mag.create(x.size(), x.type());
    angle.create(x.size(), x.type());

    arithmetic_cartToPolar_run(x, y, mag, angle, "arithm_cartToPolar", angleInDegrees);
}

//////////////////////////////////////////////////////////////////////////////
////////////////////////////////// polarToCart ///////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void arithmetic_ptc_run(const oclMat &src1, const oclMat &src2, oclMat &dst1, oclMat &dst2, bool angleInDegrees,
                        string kernelName)
{
    if(src1.clCxt -> impl -> double_support ==0 && src1.type() == CV_64F)
    {
        CV_Error(-217,"Selected device don't support double\r\n");
        return;
    }

    Context  *clCxt = src2.clCxt;
    int channels = src2.channels();
    int depth = src2.depth();

    int cols = src2.cols * channels;
    int rows = src2.rows;

    size_t localThreads[3]  = { 64, 4, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
                                divUp(rows, localThreads[1]) * localThreads[1],
                                1
                              };

    int tmp = angleInDegrees ? 1 : 0;
    vector<pair<size_t , const void *> > args;
    if(src1.data)
    {
        args.push_back( make_pair( sizeof(cl_mem), (void *)&src1.data ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&src1.step ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&src1.offset ));
    }
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src2.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst1.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst1.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst1.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst2.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst2.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst2.offset ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&tmp ));

    openCLExecuteKernel(clCxt, &arithm_polarToCart, kernelName, globalThreads, localThreads, args, -1, depth);
}

void cv::ocl::polarToCart(const oclMat &magnitude, const oclMat &angle, oclMat &x, oclMat &y, bool angleInDegrees)
{
    CV_Assert(angle.depth() == CV_32F || angle.depth() == CV_64F);

    x.create(angle.size(), angle.type());
    y.create(angle.size(), angle.type());

    if( magnitude.data )
    {
        CV_Assert( magnitude.size() == angle.size() && magnitude.type() == angle.type() );
        arithmetic_ptc_run(magnitude, angle, x, y, angleInDegrees, "arithm_polarToCart_mag");
    }
    else
        arithmetic_ptc_run(magnitude, angle, x, y, angleInDegrees, "arithm_polarToCart");
}

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// minMaxLoc ////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void arithmetic_minMaxLoc_run(const oclMat &src, cl_mem &dst, int vlen , int groupnum)
{
    vector<pair<size_t , const void *> > args;
    int all_cols = src.step / (vlen * src.elemSize1());
    int pre_cols = (src.offset % src.step) / (vlen * src.elemSize1());
    int sec_cols = all_cols - (src.offset % src.step + src.cols * src.elemSize1() - 1) / (vlen * src.elemSize1()) - 1;
    int invalid_cols = pre_cols + sec_cols;
    int cols = all_cols - invalid_cols , elemnum = cols * src.rows;;
    int offset = src.offset / (vlen * src.elemSize1());
    int repeat_s = src.offset / src.elemSize1() - offset * vlen;
    int repeat_e = (offset + cols) * vlen - src.offset / src.elemSize1() - src.cols;
    args.push_back( make_pair( sizeof(cl_int) , (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&invalid_cols ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&offset));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&elemnum));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&groupnum));
    args.push_back( make_pair( sizeof(cl_mem) , (void *)&src.data));
    args.push_back( make_pair( sizeof(cl_mem) , (void *)&dst ));
    char build_options[50];
    sprintf(build_options, "-D DEPTH_%d -D REPEAT_S%d -D REPEAT_E%d", src.depth(), repeat_s, repeat_e);
    size_t gt[3] = {groupnum * 256, 1, 1}, lt[3] = {256, 1, 1};
    openCLExecuteKernel(src.clCxt, &arithm_minMaxLoc, "arithm_op_minMaxLoc", gt, lt, args, -1, -1, build_options);
}

void arithmetic_minMaxLoc_mask_run(const oclMat &src, const oclMat &mask, cl_mem &dst, int vlen, int groupnum)
{
    vector<pair<size_t , const void *> > args;
    size_t gt[3] = {groupnum * 256, 1, 1}, lt[3] = {256, 1, 1};
    char build_options[50];
    if(src.channels() == 1)
    {
        int cols = (src.cols - 1) / vlen + 1;
        int invalid_cols = src.step / (vlen * src.elemSize1()) - cols;
        int offset = src.offset / src.elemSize1();
        int repeat_me = vlen - (mask.cols % vlen == 0 ? vlen : mask.cols % vlen);
        int minvalid_cols = mask.step / (vlen * mask.elemSize1()) - cols;
        int moffset = mask.offset / mask.elemSize1();
        int elemnum = cols * src.rows;
        sprintf(build_options, "-D DEPTH_%d -D REPEAT_E%d", src.depth(), repeat_me);
        args.push_back( make_pair( sizeof(cl_int) , (void *)&cols ));
        args.push_back( make_pair( sizeof(cl_int) , (void *)&invalid_cols ));
        args.push_back( make_pair( sizeof(cl_int) , (void *)&offset));
        args.push_back( make_pair( sizeof(cl_int) , (void *)&elemnum));
        args.push_back( make_pair( sizeof(cl_int) , (void *)&groupnum));
        args.push_back( make_pair( sizeof(cl_mem) , (void *)&src.data));
        args.push_back( make_pair( sizeof(cl_int) , (void *)&minvalid_cols ));
        args.push_back( make_pair( sizeof(cl_int) , (void *)&moffset ));
        args.push_back( make_pair( sizeof(cl_mem) , (void *)&mask.data ));
        args.push_back( make_pair( sizeof(cl_mem) , (void *)&dst ));
        //    printf("elemnum:%d,cols:%d,invalid_cols:%d,offset:%d,minvalid_cols:%d,moffset:%d,repeat_e:%d\r\n",
        //           elemnum,cols,invalid_cols,offset,minvalid_cols,moffset,repeat_me);
        openCLExecuteKernel(src.clCxt, &arithm_minMaxLoc_mask, "arithm_op_minMaxLoc_mask", gt, lt, args, -1, -1, build_options);
    }
}
template<typename T>
void arithmetic_minMaxLoc(const oclMat &src, double *minVal, double *maxVal,
                        Point *minLoc, Point *maxLoc, const oclMat &mask)
{
    CV_Assert(src.channels() == 1);
   	size_t groupnum = src.clCxt->impl->maxComputeUnits;
    CV_Assert(groupnum != 0);
    int minloc = -1 , maxloc = -1;
    int vlen = 8, dbsize = groupnum * vlen * 4 * sizeof(T) , status;
    Context *clCxt = src.clCxt;
    cl_mem dstBuffer = openCLCreateBuffer(clCxt,CL_MEM_WRITE_ONLY,dbsize);
    *minVal = std::numeric_limits<double>::max() , *maxVal = -std::numeric_limits<double>::max();
    if (mask.empty())
    {
        arithmetic_minMaxLoc_run(src, dstBuffer, vlen, groupnum);
    }
    else
    {
        arithmetic_minMaxLoc_mask_run(src, mask, dstBuffer, vlen, groupnum);
    }
    T *p = new T[groupnum * vlen * 4];
    memset(p, 0, dbsize);
    openCLReadBuffer(clCxt,dstBuffer,(void *)p,dbsize);
    for(int i = 0; i < vlen * groupnum; i++)
    {
        *minVal = (*minVal < p[i] || p[i + 2 * vlen *groupnum] == -1) ? *minVal : p[i];
        minloc = (*minVal < p[i] || p[i + 2 * vlen *groupnum] == -1) ? minloc : p[i + 2 * vlen * groupnum];
    }
    for(int i = vlen * groupnum; i < 2 * vlen * groupnum; i++)
    {
        *maxVal = (*maxVal > p[i] || p[i + 2 * vlen *groupnum] == -1) ? *maxVal : p[i];
        maxloc = (*maxVal > p[i] || p[i + 2 * vlen *groupnum] == -1) ? maxloc : p[i + 2 * vlen * groupnum];
    }

    int pre_rows = src.offset / src.step;
    int pre_cols = (src.offset % src.step) / src.elemSize1();
    int wholecols = src.step / src.elemSize1();
    if( minLoc )
    {
        if( minloc >= 0 )
        {
            minLoc->y = minloc / wholecols - pre_rows;
            minLoc->x = minloc % wholecols - pre_cols;
        }
        else
            minLoc->x = minLoc->y = -1;
    }
    if( maxLoc )
    {
        if( maxloc >= 0 )
        {
            maxLoc->y = maxloc / wholecols - pre_rows;
            maxLoc->x = maxloc % wholecols - pre_cols;
        }
        else
            maxLoc->x = maxLoc->y = -1;
    }
    delete[] p;
    openCLSafeCall(clReleaseMemObject(dstBuffer));
}

typedef void (*minMaxLocFunc)(const oclMat &src, double *minVal, double *maxVal,
                        Point *minLoc, Point *maxLoc, const oclMat &mask);
void cv::ocl::minMaxLoc(const oclMat &src, double *minVal, double *maxVal,
                        Point *minLoc, Point *maxLoc, const oclMat &mask)
{
    if(src.clCxt->impl->double_support==0 && src.depth()==CV_64F)
    {
        CV_Error(-217,"select device don't support double");
    }
    static minMaxLocFunc functab[2] =
    {
        arithmetic_minMaxLoc<float>,
        arithmetic_minMaxLoc<double>
    };

    minMaxLocFunc func;
    func = functab[src.clCxt->impl->double_support];
    func(src,minVal,maxVal,minLoc,maxLoc,mask);
}

//////////////////////////////////////////////////////////////////////////////
///////////////////////////// countNonZero ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void arithmetic_countNonZero_run(const oclMat &src, cl_mem &dst, int vlen , int groupnum, string kernelName)
{
    vector<pair<size_t , const void *> > args;
    int all_cols = src.step / (vlen * src.elemSize1());
    int pre_cols = (src.offset % src.step) / (vlen * src.elemSize1());
    int sec_cols = all_cols - (src.offset % src.step + src.cols * src.elemSize() - 1) / (vlen * src.elemSize1()) - 1;
    int invalid_cols = pre_cols + sec_cols;
    int cols = all_cols - invalid_cols , elemnum = cols * src.rows;;
    int offset = src.offset / (vlen * src.elemSize1());
    int repeat_s = src.offset / src.elemSize1() - offset * vlen;
    int repeat_e = (offset + cols) * vlen - src.offset / src.elemSize1() - src.cols * src.channels();

    char build_options[50];
    sprintf(build_options, "-D DEPTH_%d -D REPEAT_S%d -D REPEAT_E%d", src.depth(), repeat_s, repeat_e);

    args.push_back( make_pair( sizeof(cl_int) , (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&invalid_cols ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&offset));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&elemnum));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&groupnum));
    args.push_back( make_pair( sizeof(cl_mem) , (void *)&src.data));
    args.push_back( make_pair( sizeof(cl_mem) , (void *)&dst ));
    size_t gt[3] = {groupnum * 256, 1, 1}, lt[3] = {256, 1, 1};
    openCLExecuteKernel(src.clCxt, &arithm_nonzero, kernelName, gt, lt, args, -1, -1, build_options);
}

int cv::ocl::countNonZero(const oclMat &src)
{
    size_t groupnum = src.clCxt->impl->maxComputeUnits;
    if(src.clCxt->impl->double_support == 0 && src.depth()==CV_64F)
    {
        CV_Error(-217,"select device don't support double");
    }
    CV_Assert(groupnum != 0);
    groupnum = groupnum * 2;
    int vlen = 8 , dbsize = groupnum * vlen, status;
    //cl_ulong start, end;
    Context *clCxt = src.clCxt;
    string kernelName = "arithm_op_nonzero";
    int *p = new int[dbsize], nonzero = 0;
    cl_mem dstBuffer = openCLCreateBuffer(clCxt,CL_MEM_WRITE_ONLY,dbsize*sizeof(int));
    arithmetic_countNonZero_run(src, dstBuffer, vlen, groupnum, kernelName);

    memset(p, 0, dbsize * sizeof(int));
    openCLReadBuffer(clCxt,dstBuffer,(void *)p,dbsize*sizeof(int));
    for(int i = 0; i < dbsize; i++)
    {
        nonzero += p[i];
    }
    delete[] p;
    openCLSafeCall(clReleaseMemObject(dstBuffer));
    return nonzero;
}

//////////////////////////////////////////////////////////////////////////////
////////////////////////////////bitwise_op////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void bitwise_run(const oclMat &src1, oclMat &dst, string kernelName, const char **kernelString)
{
    dst.create(src1.size(), src1.type());


    Context  *clCxt = src1.clCxt;
    int channels = dst.channels();
    int depth = dst.depth();

    int vector_lengths[4][7] = {{4, 4, 4, 4, 1, 1, 1},
        {4, 4, 4, 4, 1, 1, 1},
        {4, 4, 4, 4, 1, 1, 1},
        {4, 4, 4, 4, 1, 1, 1}
    };

    size_t vector_length = vector_lengths[channels-1][depth];
    int offset_cols = (dst.offset / dst.elemSize1()) & (vector_length - 1);
    int cols = divUp(dst.cols * channels + offset_cols, vector_length);

    size_t localThreads[3]  = { 64, 4, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
                                divUp(dst.rows, localThreads[1]) * localThreads[1],
                                1
                              };

    int dst_step1 = dst.cols * dst.elemSize();
    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src1.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.offset ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst_step1 ));

    openCLExecuteKernel(clCxt, kernelString, kernelName, globalThreads, localThreads, args, -1, depth);
}


template<typename T>
void bitwise_run(const oclMat &src1, const oclMat &src2, oclMat &dst, string kernelName, const char **kernelString, void *_scalar)
{
    dst.create(src1.size(), src1.type());
    CV_Assert(src1.cols == src2.cols && src2.cols == dst.cols &&
              src1.rows == src2.rows && src2.rows == dst.rows);

    CV_Assert(src1.type() == src2.type() && src1.type() == dst.type());

    Context  *clCxt = src1.clCxt;
    int channels = dst.channels();
    int depth = dst.depth();

    int vector_lengths[4][7] = {{4, 4, 4, 4, 1, 1, 1},
        {4, 4, 4, 4, 1, 1, 1},
        {4, 4, 4, 4, 1, 1, 1},
        {4, 4, 4, 4, 1, 1, 1}
    };

    size_t vector_length = vector_lengths[channels-1][depth];
    int offset_cols = (dst.offset / dst.elemSize1()) & (vector_length - 1);
    int cols = divUp(dst.cols * channels + offset_cols, vector_length);

    size_t localThreads[3]  = { 64, 4, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
                                divUp(dst.rows, localThreads[1]) * localThreads[1],
                                1
                              };

    int dst_step1 = dst.cols * dst.elemSize();
    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src1.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src2.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.offset ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst_step1 ));

    if(_scalar != NULL)
    {
        double scalar1 = *((double *)_scalar);
        T scalar = (T)scalar1;
        args.push_back( make_pair( sizeof(T), (void *)&scalar ));
    }

    openCLExecuteKernel(clCxt, kernelString, kernelName, globalThreads, localThreads, args, -1, depth);
}
void bitwise_run(const oclMat &src1, const oclMat &src2, oclMat &dst, string kernelName, const char **kernelString)
{
    bitwise_run<char>(src1, src2, dst, kernelName, kernelString, (void *)NULL);
}
void bitwise_run(const oclMat &src1, const oclMat &src2, oclMat &dst, const oclMat &mask, string kernelName, const char **kernelString)
{
    dst.create(src1.size(), src1.type());
    CV_Assert(src1.cols == src2.cols && src2.cols == dst.cols &&
              src1.rows == src2.rows && src2.rows == dst.rows &&
              src1.rows == mask.rows && src1.cols == mask.cols);

    CV_Assert(src1.type() == src2.type() && src1.type() == dst.type());
    CV_Assert(mask.type() == CV_8U);

    Context  *clCxt = src1.clCxt;
    int channels = dst.channels();
    int depth = dst.depth();

    int vector_lengths[4][7] = {{4, 4, 2, 2, 1, 1, 1},
        {2, 2, 1, 1, 1, 1, 1},
        {4, 4, 2, 2 , 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1}
    };

    size_t vector_length = vector_lengths[channels-1][depth];
    int offset_cols = ((dst.offset % dst.step) / dst.elemSize()) & (vector_length - 1);
    int cols = divUp(dst.cols + offset_cols, vector_length);

    size_t localThreads[3]  = { 64, 4, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
                                divUp(dst.rows, localThreads[1]) * localThreads[1],
                                1
                              };

    int dst_step1 = dst.cols * dst.elemSize();
    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src1.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src2.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&mask.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&mask.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&mask.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.offset ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst_step1 ));

    openCLExecuteKernel(clCxt, kernelString, kernelName, globalThreads, localThreads, args, channels, depth);
}


template <typename WT ,typename CL_WT>
void bitwise_scalar_run(const oclMat &src1, const Scalar &src2, oclMat &dst, const oclMat &mask, string kernelName, const char **kernelString, int isMatSubScalar)
{
    dst.create(src1.size(), src1.type());

    CV_Assert(src1.cols == dst.cols && src1.rows == dst.rows &&
              src1.type() == dst.type());


    if(mask.data)
        CV_Assert(mask.type() == CV_8U && src1.rows == mask.rows && src1.cols == mask.cols);

    Context  *clCxt = src1.clCxt;
    int channels = dst.channels();
    int depth = dst.depth();

    WT s[4] = { saturate_cast<WT>(src2.val[0]), saturate_cast<WT>(src2.val[1]),
                saturate_cast<WT>(src2.val[2]), saturate_cast<WT>(src2.val[3])
              };

    int vector_lengths[4][7] = {{4, 4, 2, 2, 1, 1, 1},
        {2, 2, 1, 1, 1, 1, 1},
        {4, 4, 2, 2 , 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1}
    };

    size_t vector_length = vector_lengths[channels-1][depth];
    int offset_cols = ((dst.offset % dst.step) / dst.elemSize()) & (vector_length - 1);
    int cols = divUp(dst.cols + offset_cols, vector_length);

    size_t localThreads[3]  = { 64, 4, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
                                divUp(dst.rows, localThreads[1]) * localThreads[1],
                                1
                              };

    int dst_step1 = dst.cols * dst.elemSize();
    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_mem) , (void *)&src1.data ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&src1.step ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&src1.offset));
    args.push_back( make_pair( sizeof(cl_mem) , (void *)&dst.data ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&dst.step ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&dst.offset));

    if(mask.data)
    {
        args.push_back( make_pair( sizeof(cl_mem) , (void *)&mask.data ));
        args.push_back( make_pair( sizeof(cl_int) , (void *)&mask.step ));
        args.push_back( make_pair( sizeof(cl_int) , (void *)&mask.offset));
    }
    args.push_back( make_pair( sizeof(CL_WT) , (void *)&s ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&src1.rows ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int) , (void *)&dst_step1 ));
    if(isMatSubScalar != 0)
    {
        isMatSubScalar = isMatSubScalar > 0 ? 1 : 0;
        args.push_back( make_pair( sizeof(cl_int) , (void *)&isMatSubScalar));
    }

    openCLExecuteKernel(clCxt, kernelString, kernelName, globalThreads, localThreads, args, channels, depth);
}


typedef void (*BitwiseFuncS)(const oclMat &src1, const Scalar &src2, oclMat &dst, const oclMat &mask, string kernelName, const char **kernelString, int isMatSubScalar);


void bitwise_scalar(const oclMat &src1, const Scalar &src2, oclMat &dst, const oclMat &mask, string kernelName, const char **kernelString, int isMatSubScalar)
{
    static BitwiseFuncS tab[8] =
    {
#if 0
        bitwise_scalar_run<unsigned char>,
        bitwise_scalar_run<char>,
        bitwise_scalar_run<unsigned short>,
        bitwise_scalar_run<short>,
        bitwise_scalar_run<int>,
        bitwise_scalar_run<float>,
        bitwise_scalar_run<double>,
        0
#else

        bitwise_scalar_run<unsigned char,cl_uchar4>,
        bitwise_scalar_run<char,cl_char4>,
        bitwise_scalar_run<unsigned short,cl_ushort4>,
        bitwise_scalar_run<short,cl_short4>,
        bitwise_scalar_run<int,cl_int4>,
        bitwise_scalar_run<float,cl_float4>,
        bitwise_scalar_run<double,cl_double4>,
        0
#endif
    };
    BitwiseFuncS func = tab[src1.depth()];
    if(func == 0)
        cv::ocl::error("Unsupported arithmetic operation", __FILE__, __LINE__);
    func(src1, src2, dst, mask, kernelName, kernelString, isMatSubScalar);
}
void bitwise_scalar(const oclMat &src1, const Scalar &src2, oclMat &dst, const oclMat &mask, string kernelName, const char **kernelString)
{
    bitwise_scalar(src1, src2, dst, mask, kernelName, kernelString, 0);
}

void cv::ocl::bitwise_not(const oclMat &src, oclMat &dst)
{
    if(src.clCxt -> impl -> double_support ==0)
    {
        cout << "Selected device do not support double" << endl;
        return;
    }
    dst.create(src.size(), src.type());
    string kernelName =  "arithm_bitwise_not";
    bitwise_run(src, dst, kernelName, &arithm_bitwise_not);
}

void cv::ocl::bitwise_or(const oclMat &src1, const oclMat &src2, oclMat &dst, const oclMat &mask)
{
    // dst.create(src1.size(),src1.type());
    if(src1.clCxt -> impl -> double_support ==0)
    {
        cout << "Selected device do not support double" << endl;
        return;
    }
    oclMat emptyMat;
    string kernelName = mask.empty() ? "arithm_bitwise_or" : "arithm_bitwise_or_with_mask";
    if (mask.empty())
        bitwise_run(src1, src2, dst, kernelName, &arithm_bitwise_or);
    else
        bitwise_run(src1, src2, dst, mask, kernelName, &arithm_bitwise_or_mask);
}


void cv::ocl::bitwise_or(const oclMat &src1, const Scalar &src2, oclMat &dst, const oclMat &mask)
{
    if(src1.clCxt -> impl -> double_support ==0)
    {
        cout << "Selected device do not support double" << endl;
        return;
    }
    string kernelName = mask.data ? "arithm_s_bitwise_or_with_mask" : "arithm_s_bitwise_or";
    if (mask.data)
        bitwise_scalar( src1, src2, dst, mask, kernelName, &arithm_bitwise_or_scalar_mask);
    else
        bitwise_scalar( src1, src2, dst, mask, kernelName, &arithm_bitwise_or_scalar);
}

void cv::ocl::bitwise_and(const oclMat &src1, const oclMat &src2, oclMat &dst, const oclMat &mask)
{
    //    dst.create(src1.size(),src1.type());
    if(src1.clCxt -> impl -> double_support ==0)
    {
        cout << "Selected device do not support double" << endl;
        return;
    }
    oclMat emptyMat;

    string kernelName = mask.empty() ? "arithm_bitwise_and" : "arithm_bitwise_and_with_mask";

    if (mask.empty())
        bitwise_run(src1, src2, dst, kernelName, &arithm_bitwise_and);
    else
        bitwise_run(src1, src2, dst, mask, kernelName, &arithm_bitwise_and_mask);
}

void cv::ocl::bitwise_and(const oclMat &src1, const Scalar &src2, oclMat &dst, const oclMat &mask)
{
    if(src1.clCxt -> impl -> double_support ==0)
    {
        cout << "Selected device do not support double" << endl;
        return;
    }
    string kernelName = mask.data ? "arithm_s_bitwise_and_with_mask" : "arithm_s_bitwise_and";
    if (mask.data)
        bitwise_scalar(src1, src2, dst, mask, kernelName, &arithm_bitwise_and_scalar_mask);
    else
        bitwise_scalar(src1, src2, dst, mask, kernelName, &arithm_bitwise_and_scalar);
}

void cv::ocl::bitwise_xor(const oclMat &src1, const oclMat &src2, oclMat &dst, const oclMat &mask)
{
    if(src1.clCxt -> impl -> double_support ==0)
    {
        cout << "Selected device do not support double" << endl;
        return;
    }
    oclMat emptyMat;
    string kernelName = mask.empty() ? "arithm_bitwise_xor" : "arithm_bitwise_xor_with_mask";


    if (mask.empty())
        bitwise_run(src1, src2, dst, kernelName, &arithm_bitwise_xor);
    else
        bitwise_run(src1, src2, dst, mask, kernelName, &arithm_bitwise_xor_mask);
}


void cv::ocl::bitwise_xor(const oclMat &src1, const Scalar &src2, oclMat &dst, const oclMat &mask)
{

    if(src1.clCxt -> impl -> double_support ==0)
    {
        cout << "Selected device do not support double" << endl;
        return;
    }
    string kernelName = mask.data ? "arithm_s_bitwise_xor_with_mask" : "arithm_s_bitwise_xor";
    if (mask.data)
        bitwise_scalar( src1, src2, dst, mask, kernelName, &arithm_bitwise_xor_scalar_mask);
    else
        bitwise_scalar( src1, src2, dst, mask, kernelName, &arithm_bitwise_xor_scalar);
}

cv::ocl::oclMat cv::ocl::operator ~ (const oclMat &src)
{
    oclMat dst;
    bitwise_not(src, dst);
    return dst;
}

cv::ocl::oclMat cv::ocl::operator | (const oclMat &src1, const oclMat &src2)
{
    oclMat dst;
    bitwise_or(src1, src2, dst);
    return dst;
}

cv::ocl::oclMat cv::ocl::operator & (const oclMat &src1, const oclMat &src2)
{
    oclMat dst;
    bitwise_and(src1, src2, dst);
    return dst;
}

cv::ocl::oclMat cv::ocl::operator ^ (const oclMat &src1, const oclMat &src2)
{
    oclMat dst;
    bitwise_xor(src1, src2, dst);
    return dst;
}

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// transpose ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#define TILE_DIM      (32)
#define BLOCK_ROWS    (256/TILE_DIM)
void transpose_run(const oclMat &src, oclMat &dst, string kernelName)
{
    if(src.clCxt -> impl -> double_support ==0 && src.type() == CV_64F)
    {
        CV_Error(-217,"Selected device don't support double\r\n");
        return;
    }

    CV_Assert(src.cols == dst.rows && src.rows == dst.cols);

    Context  *clCxt = src.clCxt;
    int channels = src.channels();
    int depth = src.depth();

    int vector_lengths[4][7] = {{1, 0, 0, 0, 1, 1, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0 , 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0}
    };

    size_t vector_length = vector_lengths[channels-1][depth];
    int offset_cols = ((dst.offset % dst.step) / dst.elemSize()) & (vector_length - 1);
    int cols = divUp(src.cols + offset_cols, vector_length);

    size_t localThreads[3]  = { TILE_DIM, BLOCK_ROWS, 1 };
    size_t globalThreads[3] = { divUp(cols, TILE_DIM) * localThreads[0],
                                divUp(src.rows, TILE_DIM) * localThreads[1],
                                1
                              };

    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.offset ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src.rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));

    openCLExecuteKernel(clCxt, &arithm_transpose, kernelName, globalThreads, localThreads, args, channels, depth);
}

void cv::ocl::transpose(const oclMat &src, oclMat &dst)
{
    CV_Assert(src.type() == CV_8UC1  || src.type() == CV_8UC4  || src.type() == CV_8SC4  ||
              src.type() == CV_16UC2 || src.type() == CV_16SC2 || src.type() == CV_32SC1 || src.type() == CV_32FC1);

    stringstream idxstr;
    oclMat emptyMat;

    if( src.data == dst.data && dst.cols == dst.rows )
        transpose_run( src, emptyMat, "transposeI_");
    else
    {
        dst.create(src.cols, src.rows, src.type());
        transpose_run( src, dst, "transpose");
    }
}

void cv::ocl::addWeighted(const oclMat &src1, double alpha, const oclMat &src2, double beta, double gama, oclMat &dst)
{
    dst.create(src1.size(), src1.type());
    CV_Assert(src1.cols ==  src2.cols && src2.cols == dst.cols &&
              src1.rows ==  src2.rows && src2.rows == dst.rows);
    CV_Assert(src1.type() == src2.type() && src1.type() == dst.type());

    Context *clCxt = src1.clCxt;
    int channels = dst.channels();
    int depth = dst.depth();


    int vector_lengths[4][7] = {{4, 0, 4, 4, 4, 4, 4},
        {4, 0, 4, 4, 4, 4, 4},
        {4, 0, 4, 4, 4, 4, 4},
        {4, 0, 4, 4, 4, 4, 4}
    };


    size_t vector_length = vector_lengths[channels-1][depth];
    int offset_cols = (dst.offset / dst.elemSize1()) & (vector_length - 1);
    int cols = divUp(dst.cols * channels + offset_cols, vector_length);

    size_t localThreads[3]  = { 256, 1, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
                                divUp(dst.rows, localThreads[1]) * localThreads[1],
                                1
                              };

    int dst_step1 = dst.cols * dst.elemSize();
    vector<pair<size_t , const void *> > args;
    if(sizeof(double) == 8)
    {
        args.push_back( make_pair( sizeof(cl_mem), (void *)&src1.data ));
        args.push_back( make_pair( sizeof(cl_double), (void *)&alpha ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&src1.step ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&src1.offset));
        args.push_back( make_pair( sizeof(cl_mem), (void *)&src2.data ));
        args.push_back( make_pair( sizeof(cl_double), (void *)&beta ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&src2.step ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&src2.offset));
        args.push_back( make_pair( sizeof(cl_double), (void *)&gama ));
        args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&dst.step ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&dst.offset));
        args.push_back( make_pair( sizeof(cl_int), (void *)&src1.rows ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&dst_step1 ));
    }
    else
    {

        args.push_back( make_pair( sizeof(cl_mem), (void *)&src1.data ));
        args.push_back( make_pair( sizeof(cl_float), (void *)&alpha ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&src1.step ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&src1.offset));
        args.push_back( make_pair( sizeof(cl_mem), (void *)&src2.data ));
        args.push_back( make_pair( sizeof(cl_float), (void *)&beta ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&src2.step ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&src2.offset));
        args.push_back( make_pair( sizeof(cl_float), (void *)&gama ));
        args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&dst.step ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&dst.offset));
        args.push_back( make_pair( sizeof(cl_int), (void *)&src1.rows ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));
        args.push_back( make_pair( sizeof(cl_int), (void *)&dst_step1 ));
    }
    openCLExecuteKernel(clCxt, &arithm_addWeighted, "addWeighted", globalThreads, localThreads, args, -1, depth);
}

void cv::ocl::magnitudeSqr(const oclMat &src1, const oclMat &src2, oclMat &dst)
{
    CV_Assert(src1.type() == src2.type() && src1.size() == src2.size() &&
              (src1.depth() == CV_32F ));

    dst.create(src1.size(), src1.type());


    Context *clCxt = src1.clCxt;
    int channels = dst.channels();
    int depth = dst.depth();


    int vector_lengths[4][7] = {{4, 0, 4, 4, 4, 4, 4},
        {4, 0, 4, 4, 4, 4, 4},
        {4, 0, 4, 4, 4, 4, 4},
        {4, 0, 4, 4, 4, 4, 4}
    };


    size_t vector_length = vector_lengths[channels-1][depth];
    int offset_cols = (dst.offset / dst.elemSize1()) & (vector_length - 1);
    int cols = divUp(dst.cols * channels + offset_cols, vector_length);

    size_t localThreads[3]  = { 256, 1, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
                                divUp(dst.rows, localThreads[1]) * localThreads[1],
                                1
                              };

    int dst_step1 = dst.cols * dst.elemSize();
    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src1.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.offset));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src2.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src2.offset));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.offset));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst_step1 ));

    openCLExecuteKernel(clCxt, &arithm_magnitudeSqr, "magnitudeSqr", globalThreads, localThreads, args, 1, depth);
}

void cv::ocl::magnitudeSqr(const oclMat &src1, oclMat &dst)
{
    CV_Assert (src1.depth() == CV_32F );
    CV_Assert(src1.size() == dst.size());

    dst.create(src1.size(), CV_32FC1);


    Context *clCxt = src1.clCxt;
    int channels = dst.channels();
    int depth = dst.depth();


    int vector_lengths[4][7] = {{4, 0, 4, 4, 4, 4, 4},
        {4, 0, 4, 4, 4, 4, 4},
        {4, 0, 4, 4, 4, 4, 4},
        {4, 0, 4, 4, 4, 4, 4}
    };


    size_t vector_length = vector_lengths[channels-1][depth];
    int offset_cols = (dst.offset / dst.elemSize1()) & (vector_length - 1);
    int cols = divUp(dst.cols * channels + offset_cols, vector_length);

    size_t localThreads[3]  = { 256, 1, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
                                divUp(dst.rows, localThreads[1]) * localThreads[1],
                                1
                              };

    int dst_step1 = dst.cols * dst.elemSize();
    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src1.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.offset));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.offset));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst_step1 ));

    openCLExecuteKernel(clCxt, &arithm_magnitudeSqr, "magnitudeSqr", globalThreads, localThreads, args, 2, depth);
}

void arithmetic_pow_run(const oclMat &src1, double p, oclMat &dst, string kernelName, const char **kernelString)
{
    CV_Assert(src1.cols == dst.cols && src1.rows == dst.rows);
    CV_Assert(src1.type() == dst.type());

    Context  *clCxt = src1.clCxt;
    int channels = dst.channels();
    int depth = dst.depth();

    size_t vector_length = 1;
    int offset_cols = ((dst.offset % dst.step) / dst.elemSize1()) & (vector_length - 1);
    int cols = divUp(dst.cols * channels + offset_cols, vector_length);
    int rows = dst.rows;

    size_t localThreads[3]  = { 64, 4, 1 };
    size_t globalThreads[3] = { divUp(cols, localThreads[0]) * localThreads[0],
                                divUp(rows, localThreads[1]) * localThreads[1],
                                1
                              };

    int dst_step1 = dst.cols * dst.elemSize();
    vector<pair<size_t , const void *> > args;
    args.push_back( make_pair( sizeof(cl_mem), (void *)&src1.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&src1.offset ));
    args.push_back( make_pair( sizeof(cl_mem), (void *)&dst.data ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.step ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.offset ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst.rows ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&cols ));
    args.push_back( make_pair( sizeof(cl_int), (void *)&dst_step1 ));
    args.push_back( make_pair( sizeof(cl_double), (void *)&p ));

    openCLExecuteKernel(clCxt, kernelString, kernelName, globalThreads, localThreads, args, -1, depth);
}
void cv::ocl::pow(const oclMat &x, double p, oclMat &y)
{
    if(x.clCxt -> impl -> double_support ==0)
    {
        cout << "Selected device do not support double" << endl;
        return;
    }

    CV_Assert(x.type() == y.type() && x.size() == y.size() && x.depth() == CV_32F || x.depth() == CV_64F);
    y.create(x.size(), x.type());
    string kernelName = "arithm_pow";

    arithmetic_pow_run(x, p, y, kernelName, &arithm_pow);
}
#endif /* !defined (HAVE_OPENCL) */
