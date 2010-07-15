/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                          License Agreement
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
#ifndef __OPENCV_PRECOMP_H__
#define __OPENCV_PRECOMP_H__

#if _MSC_VER >= 1200
#pragma warning( disable: 4251 4710 4711 4514 4996 )
#endif

#ifdef HAVE_CONFIG_H 
#include <cvconfig.h> 
#endif

#include "opencv2/gpu/gpu.hpp"
#include "opencv2/gpu/gpumat.hpp"

#include "cuda_shared.hpp"

#if _MSC_VER >= 1200
#pragma warning (disable : 4100 4211 4201 4408)
#endif

#include "cuda_runtime_api.h"


#define cudaSafeCall(err)  __cudaSafeCall(err, __FILE__, __LINE__)

//inline void __cudaSafeCall( cudaError err, const char *file, const int line )
//{
//    if( cudaSuccess != err) 
//        CV_Error_(CV_StsAssert, ("%s(%i) : Runtime API error : %s.\n", cudaGetErrorString(err)));
//}

namespace cv
{
    namespace gpu
    {
        
        inline void __cudaSafeCall( cudaError err, const char *file, const int line )
        {
            if( cudaSuccess != err) 
            {
		        fprintf(stderr, "%s(%i) : cudaSafeCall() Runtime API error : %s.\n", file, line, cudaGetErrorString(err) );
                exit(-1);
            }
        }

        template<class T>
        inline DevMem2D_<T> getDevMem(const GpuMat& mat) { return DevMem2D_<T>(m.rows, m.cols, m.data, m.step); }
    }
}

#endif
