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

#include "cvtest.h"
#include <string>
#include <limits>

using namespace cv;
using namespace std;

template<class T> double thres() { return 1.0; }
template<> double thres<float>() { return 1e-5; }   

class CV_ReprojectImageTo3DTest : public CvTest
{
public:
    CV_ReprojectImageTo3DTest()
        : CvTest( "reprojectImageTo3D", "cvReprojectImageTo3D")
    {
        support_testing_modes = CvTS::CORRECTNESS_CHECK_MODE;
    }
    ~CV_ReprojectImageTo3DTest() {}
protected: 

    
    void run(int)
    {        
        ts->set_failed_test_info(CvTS::OK);
        int progress = 0;

        progress = update_progress( progress, 1, 14, 0 );
        runCase<float, float>(-100.f, 100.f);
        progress = update_progress( progress, 2, 14, 0 );
        runCase<int, float>(-100, 100);
        progress = update_progress( progress, 3, 14, 0 );
        runCase<short, float>(-100, 100);
        progress = update_progress( progress, 4, 14, 0 );
        runCase<unsigned char, float>(10, 100);
        progress = update_progress( progress, 5, 14, 0 );

        runCase<float, int>(-100.f, 100.f);
        progress = update_progress( progress, 6, 14, 0 );
        runCase<int, int>(-100, 100);
        progress = update_progress( progress, 7, 14, 0 );
        runCase<short, int>(-100, 100);
        progress = update_progress( progress, 8, 14, 0 );
        runCase<unsigned char, int>(10, 100);
        progress = update_progress( progress, 10, 14, 0 );

        runCase<float, short>(-100.f, 100.f);
        progress = update_progress( progress, 11, 14, 0 );
        runCase<int, short>(-100, 100);
        progress = update_progress( progress, 12, 14, 0 );
        runCase<short, short>(-100, 100);
        progress = update_progress( progress, 13, 14, 0 );
        runCase<unsigned char, short>(10, 100);        
        progress = update_progress( progress, 14, 14, 0 );
    }

    template<class U, class V> double error(const Vec<U, 3>& v1, const Vec<V, 3>& v2) const
    {
        double tmp, sum = 0;
        double nsum = 0;
        for(size_t i = 0; i < 3; ++i)
        {
            tmp = static_cast<double>(v1[i]);
            nsum +=  tmp * tmp;            

            tmp = tmp - static_cast<double>(v2[i]);
            sum += tmp * tmp;
            
        }        
        return sqrt(sum)/sqrt(nsum);
    }

    template<class InT, class OutT> void runCase(InT min, InT max)
    {                     
        typedef Vec<OutT, 3> out3d_t;

        bool handleMissingValues = (int)theRNG() % 2 == 0;                   

        Mat_<InT> disp(Size(320, 240));
        randu(disp, Scalar(min), Scalar(max));

        if (handleMissingValues)
            disp(disp.rows/2, disp.cols/2) = min - 1;
        
        Mat_<double> Q(4, 4);
        randu(Q, Scalar(-5), Scalar(5));

        Mat_<out3d_t> _3dImg(disp.size());
                       
        CvMat cvdisp = disp; CvMat cv_3dImg = _3dImg; CvMat cvQ = Q;
        cvReprojectImageTo3D( &cvdisp, &cv_3dImg, &cvQ, handleMissingValues );

        if (numeric_limits<OutT>::max() == numeric_limits<float>::max())
            reprojectImageTo3D(disp, _3dImg, Q, handleMissingValues);
                        
        for(int y = 0; y < disp.rows; ++y)
            for(int x = 0; x < disp.cols; ++x)
            {
                InT d = disp(y, x);                

                double from[4] = { x, y, d, 1 };
                Mat res = Q * Mat_<double>(4, 1, from);
                res /= res.at<double>(3, 0);

                out3d_t pixel_exp = *res.ptr<Vec3d>();
                out3d_t pixel_out = _3dImg(y, x);

                const int largeZValue = 10000; /* see documentation */ 

                if (handleMissingValues && y == disp.rows/2 && x == disp.cols/2)                    
                {   
                    if (pixel_out[2] == largeZValue)
                        continue;

                    ts->set_failed_test_info( CvTS::FAIL_BAD_ACCURACY );                       
                    return;
                }
                else                                
                    if (error(pixel_exp, pixel_out) > thres<OutT>())
                    {
                        ts->set_failed_test_info( CvTS::FAIL_BAD_ACCURACY );                       
                        return;
                    }
            }    
    }
};   
    
CV_ReprojectImageTo3DTest reprojectImageTo3D_test;
