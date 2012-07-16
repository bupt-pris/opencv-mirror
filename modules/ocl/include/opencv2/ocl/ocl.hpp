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

#ifndef __OPENCV_GPU_HPP__
#define __OPENCV_GPU_HPP__

#include <memory>
#include <vector>

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

namespace cv
{
    namespace ocl
    {
        using std::auto_ptr;
        
#define CVCL_DEVICE_TYPE_DEFAULT                      (1 << 0)
#define CVCL_DEVICE_TYPE_CPU                          (1 << 1)
#define CVCL_DEVICE_TYPE_GPU                          (1 << 2)
#define CVCL_DEVICE_TYPE_ACCELERATOR                  (1 << 3)
        //#define CVCL_DEVICE_TYPE_CUSTOM                       (1 << 4)
#define CVCL_DEVICE_TYPE_ALL                          0xFFFFFFFF
        //this class contains ocl runtime information
        class CV_EXPORTS Info
        {
        public:
            struct Impl;
            Impl *impl;

            Info();
            Info(const Info &m);
            ~Info();
            void release();
            Info &operator = (const Info &m);
        };
        //////////////////////////////// Initialization & Info ////////////////////////
        //this function may be obsoleted
        //CV_EXPORTS cl_device_id getDevice();
        //the function must be called before any other cv::ocl::functions, it initialize ocl runtime
        CV_EXPORTS int getDevice(std::vector<Info>& oclinfo, int devicetype = CVCL_DEVICE_TYPE_GPU);
        //set device you want to use, optional function after getDevice be called
        CV_EXPORTS void setDevice(Info &oclinfo, int devnum = 0);
        //this function is not ready yet
        //CV_EXPORTS void getComputeCapability(cl_device_id device, int &major, int &minor);
        //optional function, if you want save opencl binary kernel to the file, set its path
        CV_EXPORTS  void setBinpath(const char *path);

        //////////////////////////////// Error handling ////////////////////////
        CV_EXPORTS void error(const char *error_string, const char *file, const int line, const char *func);

        //////////////////////////////// OpenCL context ////////////////////////
        //This is a global singleton class used to represent a OpenCL context.
        class Context
        {
        protected:
            Context();
            friend class auto_ptr<Context>;
            static auto_ptr<Context> clCxt;

        public:
            ~Context();
            static int val;
            static Context *getContext();
            static void setContext(Info &oclinfo);
            struct Impl;
            Impl *impl;
        };

        //////////////////////////////// oclMat ////////////////////////////////
        class CV_EXPORTS oclMat
        {
            public:
            //! default constructor
            oclMat();
            //! constructs oclMatrix of the specified size and type (_type is CV_8UC1, CV_64FC3, CV_32SC(12) etc.)
            oclMat(int rows, int cols, int type);
            oclMat(Size size, int type);
            //! constucts oclMatrix and fills it with the specified value _s.
            oclMat(int rows, int cols, int type, const Scalar &s);
            oclMat(Size size, int type, const Scalar &s);
            //! copy constructor
            oclMat(const oclMat &m);

            //! constructor for oclMatrix headers pointing to user-allocated data
            oclMat(int rows, int cols, int type, void *data, size_t step = Mat::AUTO_STEP);
            oclMat(Size size, int type, void *data, size_t step = Mat::AUTO_STEP);

            //! creates a matrix header for a part of the bigger matrix
            oclMat(const oclMat &m, const Range &rowRange, const Range &colRange);
            oclMat(const oclMat &m, const Rect &roi);

            //! builds oclMat from Mat. Perfom blocking upload to device.
            explicit oclMat (const Mat &m);

            //! destructor - calls release()
            ~oclMat();

            //! assignment operators
            oclMat &operator = (const oclMat &m);
            //! assignment operator. Perfom blocking upload to device.
            oclMat &operator = (const Mat &m);

            /* Fixme! To be supported in OpenCL later. */
#if 0
            //! returns lightweight DevMem2D_ structure for passing to nvcc-compiled code.
            // Contains just image size, data ptr and step.
            template <class T> operator DevMem2D_<T>() const;
            template <class T> operator PtrStep_<T>() const;
#endif

            //! pefroms blocking upload data to oclMat.
            void upload(const cv::Mat &m);

            /* Fixme! To be supported in OpenCL later. */
#if 0
            //! upload async
            void upload(const CudaMem &m, Stream &stream);
#endif

            //! downloads data from device to host memory. Blocking calls.
            operator Mat() const;
            void download(cv::Mat &m) const;

            /* Fixme! To be supported in OpenCL later. */
#if 0
            //! download async
            void download(CudaMem &m, Stream &stream) const;
#endif

            //! returns a new oclMatrix header for the specified row
            oclMat row(int y) const;
            //! returns a new oclMatrix header for the specified column
            oclMat col(int x) const;
            //! ... for the specified row span
            oclMat rowRange(int startrow, int endrow) const;
            oclMat rowRange(const Range &r) const;
            //! ... for the specified column span
            oclMat colRange(int startcol, int endcol) const;
            oclMat colRange(const Range &r) const;

            //! returns deep copy of the oclMatrix, i.e. the data is copied
            oclMat clone() const;
            //! copies the oclMatrix content to "m".
            // It calls m.create(this->size(), this->type()).
            // It supports any data type
            void copyTo( oclMat &m ) const;
            //! copies those oclMatrix elements to "m" that are marked with non-zero mask elements.
            //It supports 8UC1 8UC4 32SC1 32SC4 32FC1 32FC4
            void copyTo( oclMat &m, const oclMat &mask ) const;
            //! converts oclMatrix to another datatype with optional scalng. See cvConvertScale.
            //It supports 8UC1 8UC4 32SC1 32SC4 32FC1 32FC4
            void convertTo( oclMat &m, int rtype, double alpha = 1, double beta = 0 ) const;

            void assignTo( oclMat &m, int type = -1 ) const;

            //! sets every oclMatrix element to s
            //It supports 8UC1 8UC4 32SC1 32SC4 32FC1 32FC4
            oclMat &operator = (const Scalar &s);
            //! sets some of the oclMatrix elements to s, according to the mask
            //It supports 8UC1 8UC4 32SC1 32SC4 32FC1 32FC4
            oclMat &setTo(const Scalar &s, const oclMat &mask = oclMat());
            //! creates alternative oclMatrix header for the same data, with different
            // number of channels and/or different number of rows. see cvReshape.
            oclMat reshape(int cn, int rows = 0) const;

            //! allocates new oclMatrix data unless the oclMatrix already has specified size and type.
            // previous data is unreferenced if needed.
            void create(int rows, int cols, int type);
            void create(Size size, int type);
            //! decreases reference counter;
            // deallocate the data when reference counter reaches 0.
            void release();

            //! swaps with other smart pointer
            void swap(oclMat &mat);

            //! locates oclMatrix header within a parent oclMatrix. See below
            void locateROI( Size &wholeSize, Point &ofs ) const;
            //! moves/resizes the current oclMatrix ROI inside the parent oclMatrix.
            oclMat &adjustROI( int dtop, int dbottom, int dleft, int dright );
            //! extracts a rectangular sub-oclMatrix
            // (this is a generalized form of row, rowRange etc.)
            oclMat operator()( Range rowRange, Range colRange ) const;
            oclMat operator()( const Rect &roi ) const;

            //! returns true if the oclMatrix data is continuous
            // (i.e. when there are no gaps between successive rows).
            // similar to CV_IS_oclMat_CONT(cvoclMat->type)
            bool isContinuous() const;
            //! returns element size in bytes,
            // similar to CV_ELEM_SIZE(cvMat->type)
            size_t elemSize() const;
            //! returns the size of element channel in bytes.
            size_t elemSize1() const;
            //! returns element type, similar to CV_MAT_TYPE(cvMat->type)
            int type() const;
            //! returns element type, similar to CV_MAT_DEPTH(cvMat->type)
            int depth() const;
            //! returns element type, similar to CV_MAT_CN(cvMat->type)
            int channels() const;
            //! returns step/elemSize1()
            size_t step1() const;
            //! returns oclMatrix size:
            // width == number of columns, height == number of rows
            Size size() const;
            //! returns true if oclMatrix data is NULL
            bool empty() const;

            //! returns pointer to y-th row
            uchar *ptr(int y = 0);
            const uchar *ptr(int y = 0) const;

            //! template version of the above method
            template<typename _Tp> _Tp *ptr(int y = 0);
            template<typename _Tp> const _Tp *ptr(int y = 0) const;

            //! matrix transposition
            oclMat t() const;

            /*! includes several bit-fields:
              - the magic signature
              - continuity flag
              - depth
              - number of channels
              */
            int flags;
            //! the number of rows and columns
            int rows, cols;
            //! a distance between successive rows in bytes; includes the gap if any
            size_t step;
            //! pointer to the data(OCL memory object)
            uchar *data;

            //! pointer to the reference counter;
            // when oclMatrix points to user-allocated data, the pointer is NULL
            int *refcount;

            //! helper fields used in locateROI and adjustROI
            //datastart and dataend are not used in current version
            uchar *datastart;
            uchar *dataend;

            //! OpenCL context associated with the oclMat object.
            Context *clCxt;
            //add offset for handle ROI, calculated in byte
            int offset;
            //add wholerows and wholecols for the whole matrix, datastart and dataend are no longer used
            int wholerows;
            int wholecols;
            //add download_channels for 3 channels to 4 channels
            int download_channels;
        };

        ///////////////////// mat split and merge /////////////////////////////////
        //! Compose a multi-channel array from several single-channel arrays
        // Support all types
        CV_EXPORTS void merge(const oclMat *src, size_t n, oclMat &dst);
        CV_EXPORTS void merge(const vector<oclMat> &src, oclMat &dst);

        //! Divides multi-channel array into several single-channel arrays
        // Support all types
        CV_EXPORTS void split(const oclMat &src, oclMat *dst);
        CV_EXPORTS void split(const oclMat &src, vector<oclMat> &dst);

        ////////////////////////////// Arithmetics ///////////////////////////////////
        //#if defined DOUBLE_SUPPORT
        //typedef double F;
        //#else
        //typedef float F;
        //#endif
        //  CV_EXPORTS void addWeighted(const oclMat& a,F  alpha, const oclMat& b,F beta,F gama, oclMat& c);
        CV_EXPORTS void addWeighted(const oclMat &a, double  alpha, const oclMat &b, double beta, double gama, oclMat &c);
        //! adds one matrix to another (c = a + b)
        // supports all types except CV_8SC1,CV_8SC2,CV8SC3 and CV_8SC4
        CV_EXPORTS void add(const oclMat &a, const oclMat &b, oclMat &c);
        //! adds one matrix to another (c = a + b)
        // supports all types except CV_8SC1,CV_8SC2,CV8SC3 and CV_8SC4
        CV_EXPORTS void add(const oclMat &a, const oclMat &b, oclMat &c, const oclMat &mask);
        //! adds scalar to a matrix (c = a + s)
        // supports all types except CV_8SC1,CV_8SC2,CV8SC3 and CV_8SC4
        CV_EXPORTS void add(const oclMat &a, const Scalar &sc, oclMat &c, const oclMat &mask = oclMat());
        //! subtracts one matrix from another (c = a - b)
        // supports all types except CV_8SC1,CV_8SC2,CV8SC3 and CV_8SC4
        CV_EXPORTS void subtract(const oclMat &a, const oclMat &b, oclMat &c);
        //! subtracts one matrix from another (c = a - b)
        // supports all types except CV_8SC1,CV_8SC2,CV8SC3 and CV_8SC4
        CV_EXPORTS void subtract(const oclMat &a, const oclMat &b, oclMat &c, const oclMat &mask);
        //! subtracts scalar from a matrix (c = a - s)
        // supports all types except CV_8SC1,CV_8SC2,CV8SC3 and CV_8SC4
        CV_EXPORTS void subtract(const oclMat &a, const Scalar &sc, oclMat &c, const oclMat &mask = oclMat());
        //! subtracts scalar from a matrix (c = a - s)
        // supports all types except CV_8SC1,CV_8SC2,CV8SC3 and CV_8SC4
        CV_EXPORTS void subtract(const Scalar &sc, const oclMat &a, oclMat &c, const oclMat &mask = oclMat());
        //! computes element-wise product of the two arrays (c = a * b)
        // supports all types except CV_8SC1,CV_8SC2,CV8SC3 and CV_8SC4
        CV_EXPORTS void multiply(const oclMat &a, const oclMat &b, oclMat &c, double scale = 1);
        //! computes element-wise quotient of the two arrays (c = a / b)
        // supports all types except CV_8SC1,CV_8SC2,CV8SC3 and CV_8SC4
        CV_EXPORTS void divide(const oclMat &a, const oclMat &b, oclMat &c, double scale = 1);
        //! computes element-wise quotient of the two arrays (c = a / b)
        // supports all types except CV_8SC1,CV_8SC2,CV8SC3 and CV_8SC4
        CV_EXPORTS void divide(double scale, const oclMat &b, oclMat &c);

        //! compares elements of two arrays (c = a <cmpop> b)
        // supports except CV_8SC1,CV_8SC2,CV8SC3,CV_8SC4 types
        CV_EXPORTS void compare(const oclMat &a, const oclMat &b, oclMat &c, int cmpop);

        //! transposes the matrix
        // supports  CV_8UC1, 8UC4, 8SC4, 16UC2, 16SC2, 32SC1 and 32FC1.(the same as cuda)
        CV_EXPORTS void transpose(const oclMat &src1, oclMat &dst);

        //! computes element-wise absolute difference of two arrays (c = abs(a - b))
        // supports all types except CV_8SC1,CV_8SC2,CV8SC3 and CV_8SC4
        CV_EXPORTS void absdiff(const oclMat &a, const oclMat &b, oclMat &c);
        //! computes element-wise absolute difference of array and scalar (c = abs(a - s))
        // supports all types except CV_8SC1,CV_8SC2,CV8SC3 and CV_8SC4
        CV_EXPORTS void absdiff(const oclMat &a, const Scalar &s, oclMat &c);

        //! computes mean value and standard deviation of all or selected array elements
        // supports except CV_32F,CV_64F
        CV_EXPORTS void meanStdDev(const oclMat &mtx, Scalar &mean, Scalar &stddev);

        //! computes norm of array
        // supports NORM_INF, NORM_L1, NORM_L2
        // supports only CV_8UC1 type
        CV_EXPORTS double norm(const oclMat &src1, int normType = NORM_L2);

        //! computes norm of the difference between two arrays
        // supports NORM_INF, NORM_L1, NORM_L2
        // supports only CV_8UC1 type
        CV_EXPORTS double norm(const oclMat &src1, const oclMat &src2, int normType = NORM_L2);

        //! reverses the order of the rows, columns or both in a matrix
        // supports all types
        CV_EXPORTS void flip(const oclMat &a, oclMat &b, int flipCode);

        //! computes sum of array elements
        // disabled until fix crash
        // support all types
        CV_EXPORTS Scalar sum(const oclMat &m);

        //! finds global minimum and maximum array elements and returns their values
        // support all types
        CV_EXPORTS void minMax(const oclMat &src, double *minVal, double *maxVal = 0, const oclMat &mask = oclMat());

        //! finds global minimum and maximum array elements and returns their values with locations
        // support all types
        CV_EXPORTS void minMaxLoc(const oclMat &src, double *minVal, double *maxVal = 0, Point *minLoc = 0, Point *maxLoc = 0,
                const oclMat &mask = oclMat());

        //! counts non-zero array elements
        // support all types
        CV_EXPORTS int countNonZero(const oclMat &src);

        //! transforms 8-bit unsigned integers using lookup table: dst(i)=lut(src(i))
        // destination array will have the depth type as lut and the same channels number as source
        //It supports 8UC1 8UC4 only
        CV_EXPORTS void LUT(const oclMat &src, const oclMat &lut, oclMat &dst);

        //! only 8UC1 and 256 bins is supported now
        CV_EXPORTS void calcHist(const oclMat &mat_src, oclMat &mat_hist);
        //! only 8UC1 and 256 bins is supported now
        CV_EXPORTS void equalizeHist(const oclMat &mat_src, oclMat &mat_dst);
        //! bilateralFilter
        // supports 8UC1 8UC4
        CV_EXPORTS void bilateralFilter(const oclMat &, oclMat &, int , double, double, int);
        //! computes exponent of each matrix element (b = e**a)
        // supports only CV_32FC1 type
        CV_EXPORTS void exp(const oclMat &a, oclMat &b);

        //! computes natural logarithm of absolute value of each matrix element: b = log(abs(a))
        // supports only CV_32FC1 type
        CV_EXPORTS void log(const oclMat &a, oclMat &b);

        //! computes magnitude of each (x(i), y(i)) vector
        // supports only CV_32F CV_64F type
        CV_EXPORTS void magnitude(const oclMat &x, const oclMat &y, oclMat &magnitude);
        CV_EXPORTS void magnitudeSqr(const oclMat &x, const oclMat &y, oclMat &magnitude);

        CV_EXPORTS void magnitudeSqr(const oclMat &x, oclMat &magnitude);

        //! computes angle (angle(i)) of each (x(i), y(i)) vector
        // supports only CV_32F CV_64F type
        CV_EXPORTS void phase(const oclMat &x, const oclMat &y, oclMat &angle, bool angleInDegrees = false);

        //! the function raises every element of tne input array to p
        //! support only CV_32F CV_64F type
        CV_EXPORTS void pow(const oclMat &x, double p, oclMat &y);

        //! converts Cartesian coordinates to polar
        // supports only CV_32F CV_64F type
        CV_EXPORTS void cartToPolar(const oclMat &x, const oclMat &y, oclMat &magnitude, oclMat &angle, bool angleInDegrees = false);

        //! converts polar coordinates to Cartesian
        // supports only CV_32F CV_64F type
        CV_EXPORTS void polarToCart(const oclMat &magnitude, const oclMat &angle, oclMat &x, oclMat &y, bool angleInDegrees = false);

        //! perfroms per-elements bit-wise inversion
        // supports all types
        CV_EXPORTS void bitwise_not(const oclMat &src, oclMat &dst);
        //! calculates per-element bit-wise disjunction of two arrays
        // supports all types
        CV_EXPORTS void bitwise_or(const oclMat &src1, const oclMat &src2, oclMat &dst, const oclMat &mask = oclMat());
        CV_EXPORTS void bitwise_or(const oclMat &src1, const Scalar &s, oclMat &dst, const oclMat &mask = oclMat());
        //! calculates per-element bit-wise conjunction of two arrays
        // supports all types
        CV_EXPORTS void bitwise_and(const oclMat &src1, const oclMat &src2, oclMat &dst, const oclMat &mask = oclMat());
        CV_EXPORTS void bitwise_and(const oclMat &src1, const Scalar &s, oclMat &dst, const oclMat &mask = oclMat());
        //! calculates per-element bit-wise "exclusive or" operation
        // supports all types
        CV_EXPORTS void bitwise_xor(const oclMat &src1, const oclMat &src2, oclMat &dst, const oclMat &mask = oclMat());
        CV_EXPORTS void bitwise_xor(const oclMat &src1, const Scalar &s, oclMat &dst, const oclMat &mask = oclMat());

        //! Logical operators
        CV_EXPORTS oclMat operator ~ (const oclMat &src);
        CV_EXPORTS oclMat operator | (const oclMat &src1, const oclMat &src2);
        CV_EXPORTS oclMat operator & (const oclMat &src1, const oclMat &src2);
        CV_EXPORTS oclMat operator ^ (const oclMat &src1, const oclMat &src2);
        CV_EXPORTS void cvtColor(const oclMat &src, oclMat &dst, int code , int dcn = 0);

        //////////////////////////////// Filter Engine ////////////////////////////////

        /*!
          The Base Class for 1D or Row-wise Filters

          This is the base class for linear or non-linear filters that process 1D data.
          In particular, such filters are used for the "horizontal" filtering parts in separable filters.
          */
        class CV_EXPORTS BaseRowFilter_GPU
        {
            public:
                BaseRowFilter_GPU(int ksize_, int anchor_, int bordertype_) : ksize(ksize_), anchor(anchor_), bordertype(bordertype_) {}
                virtual ~BaseRowFilter_GPU() {}
                virtual void operator()(const oclMat &src, oclMat &dst) = 0;
                int ksize, anchor, bordertype;
        };

        /*!
          The Base Class for Column-wise Filters

          This is the base class for linear or non-linear filters that process columns of 2D arrays.
          Such filters are used for the "vertical" filtering parts in separable filters.
          */
        class CV_EXPORTS BaseColumnFilter_GPU
        {
            public:
                BaseColumnFilter_GPU(int ksize_, int anchor_, int bordertype_) : ksize(ksize_), anchor(anchor_), bordertype(bordertype_) {}
                virtual ~BaseColumnFilter_GPU() {}
                virtual void operator()(const oclMat &src, oclMat &dst) = 0;
                int ksize, anchor, bordertype;
        };

        /*!
          The Base Class for Non-Separable 2D Filters.

          This is the base class for linear or non-linear 2D filters.
          */
        class CV_EXPORTS BaseFilter_GPU
        {
            public:
                BaseFilter_GPU(const Size &ksize_, const Point &anchor_, const int &borderType_)
                    : ksize(ksize_), anchor(anchor_), borderType(borderType_) {}
                virtual ~BaseFilter_GPU() {}
                virtual void operator()(const oclMat &src, oclMat &dst) = 0;
                Size ksize;
                Point anchor;
                int borderType;
        };

        /*!
          The Base Class for Filter Engine.

          The class can be used to apply an arbitrary filtering operation to an image.
          It contains all the necessary intermediate buffers.
          */
        class CV_EXPORTS FilterEngine_GPU
        {
            public:
                virtual ~FilterEngine_GPU() {}

                virtual void apply(const oclMat &src, oclMat &dst, Rect roi = Rect(0, 0, -1, -1)) = 0;
        };

        //! returns the non-separable filter engine with the specified filter
        CV_EXPORTS Ptr<FilterEngine_GPU> createFilter2D_GPU(const Ptr<BaseFilter_GPU> filter2D);

        //! returns the primitive row filter with the specified kernel
        CV_EXPORTS Ptr<BaseRowFilter_GPU> getLinearRowFilter_GPU(int srcType, int bufType, const Mat &rowKernel,
                int anchor = -1, int bordertype = BORDER_DEFAULT);

        //! returns the primitive column filter with the specified kernel
        CV_EXPORTS Ptr<BaseColumnFilter_GPU> getLinearColumnFilter_GPU(int bufType, int dstType, const Mat &columnKernel,
                int anchor = -1, int bordertype = BORDER_DEFAULT, double delta = 0.0);

        //! returns the separable linear filter engine
        CV_EXPORTS Ptr<FilterEngine_GPU> createSeparableLinearFilter_GPU(int srcType, int dstType, const Mat &rowKernel,
                const Mat &columnKernel, const Point &anchor = Point(-1, -1), double delta = 0.0, int bordertype = BORDER_DEFAULT);

        //! returns the separable filter engine with the specified filters
        CV_EXPORTS Ptr<FilterEngine_GPU> createSeparableFilter_GPU(const Ptr<BaseRowFilter_GPU>& rowFilter,
                const Ptr<BaseColumnFilter_GPU>& columnFilter);

        //! returns the Gaussian filter engine
        CV_EXPORTS Ptr<FilterEngine_GPU> createGaussianFilter_GPU(int type, Size ksize, double sigma1, double sigma2 = 0, int bordertype = BORDER_DEFAULT);

        //! returns filter engine for the generalized Sobel operator
        CV_EXPORTS Ptr<FilterEngine_GPU> createDerivFilter_GPU( int srcType, int dstType, int dx, int dy, int ksize, int borderType=BORDER_DEFAULT );

        //! applies Laplacian operator to the image
        // supports only ksize = 1 and ksize = 3 8UC1 8UC4 32FC1 32FC4 data type
        CV_EXPORTS void Laplacian(const oclMat &src, oclMat &dst, int ddepth, int ksize = 1, double scale = 1);

        //! returns 2D box filter
        // supports CV_8UC1 and CV_8UC4 source type, dst type must be the same as source type
        CV_EXPORTS Ptr<BaseFilter_GPU> getBoxFilter_GPU(int srcType, int dstType,
                const Size &ksize, Point anchor = Point(-1, -1), int borderType = BORDER_DEFAULT);

        //! returns box filter engine
        CV_EXPORTS Ptr<FilterEngine_GPU> createBoxFilter_GPU(int srcType, int dstType, const Size &ksize,
                const Point &anchor = Point(-1, -1), int borderType = BORDER_DEFAULT);

        //! returns 2D filter with the specified kernel
        // supports CV_8UC1 and CV_8UC4 types
        CV_EXPORTS Ptr<BaseFilter_GPU> getLinearFilter_GPU(int srcType, int dstType, const Mat &kernel, const Size &ksize,
                Point anchor = Point(-1, -1), int borderType = BORDER_DEFAULT);

        //! returns the non-separable linear filter engine
        CV_EXPORTS Ptr<FilterEngine_GPU> createLinearFilter_GPU(int srcType, int dstType, const Mat &kernel,
                const Point &anchor = Point(-1, -1), int borderType = BORDER_DEFAULT);

        //! smooths the image using the normalized box filter
        // supports data type: CV_8UC1, CV_8UC4, CV_32FC1 and CV_32FC4
        // supports border type: BORDER_CONSTANT, BORDER_REPLICATE, BORDER_REFLECT,BORDER_REFLECT_101,BORDER_WRAP
        CV_EXPORTS void boxFilter(const oclMat &src, oclMat &dst, int ddepth, Size ksize,
                Point anchor = Point(-1, -1), int borderType = BORDER_DEFAULT);

        //! returns 2D morphological filter
        //! only MORPH_ERODE and MORPH_DILATE are supported
        // supports CV_8UC1, CV_8UC4, CV_32FC1 and CV_32FC4 types
        // kernel must have CV_8UC1 type, one rows and cols == ksize.width * ksize.height
        CV_EXPORTS Ptr<BaseFilter_GPU> getMorphologyFilter_GPU(int op, int type, const Mat &kernel, const Size &ksize,
                Point anchor = Point(-1, -1));

        //! returns morphological filter engine. Only MORPH_ERODE and MORPH_DILATE are supported.
        CV_EXPORTS Ptr<FilterEngine_GPU> createMorphologyFilter_GPU(int op, int type, const Mat &kernel,
                const Point &anchor = Point(-1, -1), int iterations = 1);

        //! a synonym for normalized box filter
        // supports data type: CV_8UC1, CV_8UC4, CV_32FC1 and CV_32FC4
        // supports border type: BORDER_CONSTANT, BORDER_REPLICATE, BORDER_REFLECT,BORDER_REFLECT_101
        static inline void blur(const oclMat &src, oclMat &dst, Size ksize, Point anchor = Point(-1, -1),
                int borderType = BORDER_CONSTANT)
        {
            boxFilter(src, dst, -1, ksize, anchor, borderType);
        }

        //! applies non-separable 2D linear filter to the image
        CV_EXPORTS void filter2D(const oclMat &src, oclMat &dst, int ddepth, const Mat &kernel,
                Point anchor = Point(-1, -1), int borderType = BORDER_DEFAULT);

        //! applies separable 2D linear filter to the image
        CV_EXPORTS void sepFilter2D(const oclMat &src, oclMat &dst, int ddepth, const Mat &kernelX, const Mat &kernelY,
                Point anchor = Point(-1, -1), double delta = 0.0, int bordertype = BORDER_DEFAULT);

        //! applies generalized Sobel operator to the image
        // dst.type must equalize src.type
        // supports data type: CV_8UC1, CV_8UC4, CV_32FC1 and CV_32FC4
        // supports border type: BORDER_CONSTANT, BORDER_REPLICATE, BORDER_REFLECT,BORDER_REFLECT_101
        CV_EXPORTS void Sobel(const oclMat &src, oclMat &dst, int ddepth, int dx, int dy, int ksize = 3, double scale = 1, double delta = 0.0, int bordertype = BORDER_DEFAULT);

        //! applies the vertical or horizontal Scharr operator to the image
        // dst.type must equalize src.type
        // supports data type: CV_8UC1, CV_8UC4, CV_32FC1 and CV_32FC4
        // supports border type: BORDER_CONSTANT, BORDER_REPLICATE, BORDER_REFLECT,BORDER_REFLECT_101
        CV_EXPORTS void Scharr(const oclMat &src, oclMat &dst, int ddepth, int dx, int dy, double scale = 1, double delta = 0.0, int bordertype = BORDER_DEFAULT);

        //! smooths the image using Gaussian filter.
        // dst.type must equalize src.type
        // supports data type: CV_8UC1, CV_8UC4, CV_32FC1 and CV_32FC4
        // supports border type: BORDER_CONSTANT, BORDER_REPLICATE, BORDER_REFLECT,BORDER_REFLECT_101
        CV_EXPORTS void GaussianBlur(const oclMat &src, oclMat &dst, Size ksize, double sigma1, double sigma2 = 0, int bordertype = BORDER_DEFAULT);

        //! erodes the image (applies the local minimum operator)
        // supports data type: CV_8UC1, CV_8UC4, CV_32FC1 and CV_32FC4
        CV_EXPORTS void erode( const oclMat &src, oclMat &dst, const Mat &kernel, Point anchor = Point(-1, -1), int iterations = 1);

        //! dilates the image (applies the local maximum operator)
        // supports data type: CV_8UC1, CV_8UC4, CV_32FC1 and CV_32FC4
        CV_EXPORTS void dilate( const oclMat &src, oclMat &dst, const Mat &kernel, Point anchor = Point(-1, -1), int iterations = 1);

        //! applies an advanced morphological operation to the image
        CV_EXPORTS void morphologyEx( const oclMat &src, oclMat &dst, int op, const Mat &kernel, Point anchor = Point(-1, -1), int iterations = 1);

        ////////////////////////////// Image processing //////////////////////////////
        //! Does mean shift filtering on GPU.
        CV_EXPORTS void meanShiftFiltering(const oclMat &src, oclMat &dst, int sp, int sr,
                TermCriteria criteria = TermCriteria(TermCriteria::MAX_ITER + TermCriteria::EPS, 5, 1));

        //! Does mean shift procedure on GPU.
        CV_EXPORTS void meanShiftProc(const oclMat &src, oclMat &dstr, oclMat &dstsp, int sp, int sr,
                TermCriteria criteria = TermCriteria(TermCriteria::MAX_ITER + TermCriteria::EPS, 5, 1));

        //! Does mean shift segmentation with elimiation of small regions.
        CV_EXPORTS void meanShiftSegmentation(const oclMat &src, Mat &dst, int sp, int sr, int minsize,
                TermCriteria criteria = TermCriteria(TermCriteria::MAX_ITER + TermCriteria::EPS, 5, 1));

        //! applies fixed threshold to the image.
        // supports CV_8UC1 and CV_32FC1 data type
        // supports threshold type: THRESH_BINARY, THRESH_BINARY_INV, THRESH_TRUNC, THRESH_TOZERO, THRESH_TOZERO_INV
        CV_EXPORTS double threshold(const oclMat &src, oclMat &dst, double thresh, double maxVal, int type = THRESH_TRUNC);

        //! resizes the image
        // Supports INTER_NEAREST, INTER_LINEAR
        // supports CV_8UC1, CV_8UC4, CV_32FC1 and CV_32FC4 types
        CV_EXPORTS void resize(const oclMat &src, oclMat &dst, Size dsize, double fx = 0, double fy = 0, int interpolation = INTER_LINEAR);

        //! Applies a generic geometrical transformation to an image.
            // Supports INTER_NEAREST, INTER_LINEAR.
            // Map1 supports CV_16SC2, CV_32FC2  types.
        // Src supports CV_8UC1, CV_8UC2, CV_8UC4.
        CV_EXPORTS void remap(const oclMat& src, oclMat& dst, oclMat& map1, oclMat& map2, int interpolation, int bordertype, const Scalar& value = Scalar());
        //! copies 2D array to a larger destination array and pads borders with user-specifiable constant
        // supports CV_8UC1, CV_8UC4, CV_32SC1 types
        CV_EXPORTS void copyMakeBorder(const oclMat &src, oclMat &dst, int top, int bottom, int left, int right, int boardtype, const Scalar &value = Scalar());

        //! Smoothes image using median filter
        // The source 1- or 4-channel image. When m is 3 or 5, the image depth should be CV 8U or CV 32F.
        CV_EXPORTS void medianFilter(const oclMat &src, oclMat &dst, int m);

        //! warps the image using affine transformation
        // Supports INTER_NEAREST, INTER_LINEAR, INTER_CUBIC
        // supports CV_8UC1, CV_8UC4, CV_32FC1 and CV_32FC4 types
        CV_EXPORTS void warpAffine(const oclMat &src, oclMat &dst, const Mat &M, Size dsize, int flags = INTER_LINEAR);

        //! warps the image using perspective transformation
        // Supports INTER_NEAREST, INTER_LINEAR, INTER_CUBIC
        // supports CV_8UC1, CV_8UC4, CV_32FC1 and CV_32FC4 types
        CV_EXPORTS void warpPerspective(const oclMat &src, oclMat &dst, const Mat &M, Size dsize, int flags = INTER_LINEAR);

        //! computes the integral image and integral for the squared image
        // sum will have CV_32S type, sqsum - CV32F type
        // supports only CV_8UC1 source type
        CV_EXPORTS void integral(const oclMat &src, oclMat &sum, oclMat &sqsum);
        CV_EXPORTS void integral(const oclMat &src, oclMat &sum);
        CV_EXPORTS void cornerHarris(const oclMat &src, oclMat &dst, int blockSize, int ksize, double k, int bordertype = cv::BORDER_DEFAULT);
        CV_EXPORTS void cornerMinEigenVal(const oclMat &src, oclMat &dst, int blockSize, int ksize, int bordertype = cv::BORDER_DEFAULT);


        //////////////////////////////// StereoBM_GPU ////////////////////////////////
        class CV_EXPORTS StereoBM_GPU
        {
        public:
            enum { BASIC_PRESET = 0, PREFILTER_XSOBEL = 1 };

            enum { DEFAULT_NDISP = 64, DEFAULT_WINSZ = 19 };

            //! the default constructor
            StereoBM_GPU();
            //! the full constructor taking the camera-specific preset, number of disparities and the SAD window size. ndisparities must be multiple of 8.
            StereoBM_GPU(int preset, int ndisparities = DEFAULT_NDISP, int winSize = DEFAULT_WINSZ);

            //! the stereo correspondence operator. Finds the disparity for the specified rectified stereo pair
            //! Output disparity has CV_8U type.
            void operator() ( const oclMat &left, const oclMat &right, oclMat &disparity);

            //! Some heuristics that tries to estmate
            // if current GPU will be faster then CPU in this algorithm.
            // It queries current active device.
            static bool checkIfGpuCallReasonable();

            int preset;
            int ndisp;
            int winSize;

            // If avergeTexThreshold  == 0 => post procesing is disabled
            // If avergeTexThreshold != 0 then disparity is set 0 in each point (x,y) where for left image
            // SumOfHorizontalGradiensInWindow(x, y, winSize) < (winSize * winSize) * avergeTexThreshold
            // i.e. input left image is low textured.
            float avergeTexThreshold;
        private:
            oclMat minSSD, leBuf, riBuf;
        };

        ////////////////////////// StereoBeliefPropagation ///////////////////////////
        // "Efficient Belief Propagation for Early Vision"
        // P.Felzenszwalb

        class CV_EXPORTS StereoBeliefPropagation
        {
        public:
            enum { DEFAULT_NDISP  = 64 };
            enum { DEFAULT_ITERS  = 5  };
            enum { DEFAULT_LEVELS = 5  };

            static void estimateRecommendedParams(int width, int height, int &ndisp, int &iters, int &levels);

            //! the default constructor
            explicit StereoBeliefPropagation(int ndisp  = DEFAULT_NDISP,
                    int iters  = DEFAULT_ITERS,
                    int levels = DEFAULT_LEVELS,
                    int msg_type = CV_16S);

            //! the full constructor taking the number of disparities, number of BP iterations on each level,
            //! number of levels, truncation of data cost, data weight,
            //! truncation of discontinuity cost and discontinuity single jump
            //! DataTerm = data_weight * min(fabs(I2-I1), max_data_term)
            //! DiscTerm = min(disc_single_jump * fabs(f1-f2), max_disc_term)
            //! please see paper for more details
            StereoBeliefPropagation(int ndisp, int iters, int levels,
                    float max_data_term, float data_weight,
                    float max_disc_term, float disc_single_jump,
                    int msg_type = CV_32F);

            //! the stereo correspondence operator. Finds the disparity for the specified rectified stereo pair,
            //! if disparity is empty output type will be CV_16S else output type will be disparity.type().
            void operator()(const oclMat &left, const oclMat &right, oclMat &disparity);

            //! version for user specified data term
            void operator()(const oclMat &data, oclMat &disparity);

            int ndisp;

            int iters;
            int levels;

            float max_data_term;
            float data_weight;
            float max_disc_term;
            float disc_single_jump;

            int msg_type;
        private:
            oclMat u, d, l, r, u2, d2, l2, r2;
            std::vector<oclMat> datas;
            oclMat out;
        };

        /////////////////////////// StereoConstantSpaceBP ///////////////////////////
        // "A Constant-Space Belief Propagation Algorithm for Stereo Matching"
        // Qingxiong Yang, Liang Wang�? Narendra Ahuja
        // http://vision.ai.uiuc.edu/~qyang6/

        class CV_EXPORTS StereoConstantSpaceBP
        {
        public:
            enum { DEFAULT_NDISP    = 128 };
            enum { DEFAULT_ITERS    = 8   };
            enum { DEFAULT_LEVELS   = 4   };
            enum { DEFAULT_NR_PLANE = 4   };

            static void estimateRecommendedParams(int width, int height, int &ndisp, int &iters, int &levels, int &nr_plane);

            //! the default constructor
            explicit StereoConstantSpaceBP(int ndisp    = DEFAULT_NDISP,
                    int iters    = DEFAULT_ITERS,
                    int levels   = DEFAULT_LEVELS,
                    int nr_plane = DEFAULT_NR_PLANE,
                    int msg_type = CV_32F);

            //! the full constructor taking the number of disparities, number of BP iterations on each level,
            //! number of levels, number of active disparity on the first level, truncation of data cost, data weight,
            //! truncation of discontinuity cost, discontinuity single jump and minimum disparity threshold
            StereoConstantSpaceBP(int ndisp, int iters, int levels, int nr_plane,
                    float max_data_term, float data_weight, float max_disc_term, float disc_single_jump,
                    int min_disp_th = 0,
                    int msg_type = CV_32F);

            //! the stereo correspondence operator. Finds the disparity for the specified rectified stereo pair,
            //! if disparity is empty output type will be CV_16S else output type will be disparity.type().
            void operator()(const oclMat &left, const oclMat &right, oclMat &disparity);

            int ndisp;

            int iters;
            int levels;

            int nr_plane;

            float max_data_term;
            float data_weight;
            float max_disc_term;
            float disc_single_jump;

            int min_disp_th;

            int msg_type;

            bool use_local_init_data_cost;
        private:
            oclMat u[2], d[2], l[2], r[2];
            oclMat disp_selected_pyr[2];

            oclMat data_cost;
            oclMat data_cost_selected;

            oclMat temp;

            oclMat out;
        };
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////CascadeClassifier//////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        class CV_EXPORTS_W OclCascadeClassifier : public  cv::CascadeClassifier
        {
        public:
            OclCascadeClassifier() {};
            ~OclCascadeClassifier() {};

            CvSeq *oclHaarDetectObjects(oclMat &gimg, CvMemStorage *storage, double scaleFactor,
                    int minNeighbors, int flags, CvSize minSize = cvSize(0, 0), CvSize maxSize = cvSize(0, 0));
        };

        ///////////////////////////////////////////////////////jhp_benchmark////////////////////////////////////////////////////
        void benchmark_copy_vectorize(const oclMat &src, oclMat &dst);
        void benchmark_copy_offset_stride(const oclMat &src, oclMat &dst);
        void benchmark_ILP();
        
    }
}
#include "opencv2/ocl/matrix_operations.hpp"
#endif /* __OPENCV_GPU_HPP__ */
