/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                        Intel License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2000, Intel Corporation, all rights reserved.
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
//   * The name of Intel Corporation may not be used to endorse or promote products
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

#ifndef _GRFMT_PNG_H_
#define _GRFMT_PNG_H_

#ifdef HAVE_PNG

#include "grfmt_base.h"
#include "bitstrm.h"

/* libpng version only */

class GrFmtPngReader : public GrFmtReader
{
public:
    
    GrFmtPngReader( const char* filename );
    ~GrFmtPngReader();

    bool  CheckFormat( const char* signature );
    bool  ReadData( uchar* data, int step, int color );
    bool  ReadHeader();
    void  Close();

protected:

    void* m_png_ptr;  // pointer to decompression structure
    void* m_info_ptr; // pointer to image information structure
    void* m_end_info; // pointer to one more image information structure
    FILE* m_f;
    int   m_color_type;
    int   m_bit_depth;
};


class GrFmtPngWriter : public GrFmtWriter
{
public:
    
    GrFmtPngWriter( const char* filename );
    ~GrFmtPngWriter();

    bool  WriteImage( const uchar* data, int step,
                      int width, int height, bool isColor );

protected:
};


// PNG filter factory
class GrFmtPng : public GrFmtFilterFactory
{
public:
    
    GrFmtPng();
    ~GrFmtPng();

    GrFmtReader* NewReader( const char* filename );
    GrFmtWriter* NewWriter( const char* filename );
    bool CheckSignature( const char* signature );
};

#endif

#endif/*_GRFMT_PNG_H_*/
