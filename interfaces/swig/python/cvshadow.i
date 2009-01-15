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

/* This file contains custom python shadow class code for certain troublesome functions */

%{
#include "cvshadow.h"
%}

%define %myshadow(function)
%ignore function;
%rename (function) function##_Shadow;
%enddef

%include "stl.i"

// %ignore, %rename must come before %include
%myshadow(cvCvtSeqToArray);
%myshadow(cvArcLength);
%myshadow(cvHaarDetectObjects);
%myshadow(cvSegmentMotion);
%myshadow(cvApproxPoly);
%myshadow(cvContourPerimeter);
%myshadow(cvConvexHull2);
%newobject cvConvexHull2; // shadowed functioned always returns new object

/* cvSnakeImage shadow uses a vector<CvPoint> and vector<float> */ 
%template(FloatVector)   std::vector<float>;
%template(CvPointVector) std::vector<CvPoint>;
%myshadow(cvSnakeImage);

// eliminates need for IplImage ** typemap
%rename (cvCalcImageHist) cvCalcHist;
%pythoncode %{
def cvCalcHist(*args):
	return cvCalcArrHist(*args)
%}

// must come after %ignore, %rename
%include "cvshadow.h"

/* return a typed CvSeq instead of generic for CvSubdiv2D edges -- see cvseq.i */
%rename (untyped_edges) CvSubdiv2D::edges;
%ignore CvSubdiv2D::edges;
%rename (edges) CvSubdiv2D::typed_edges;

/* Python doesn't know what to do with these */
%rename (asIplImage) operator IplImage*;
%rename (asCvMat) operator CvMat*;
%ignore operator const IplImage*;
%ignore operator const CvMat*;

/* Define sequence type for functions returning sequences */
%define %cast_seq( cvfunc, type )
%rename (cvfunc##Untyped) cvfunc;
%pythoncode %{
def cvfunc(*args):
	seq = cvfunc##Untyped( *args )
	return type.cast(seq)
%}
%enddef

%cast_seq( cvHoughCircles, CvSeq_float_3 );
%cast_seq( cvPyrSegmentation, CvSeq_CvConnectedComp );
%cast_seq( cvApproxChains, CvSeq_CvPoint);
%cast_seq( cvContourFromContourTree, CvSeq_CvPoint );
%cast_seq( cvConvexityDefects, CvSeq_CvConvexityDefect );

/* Special cases ... */
%rename(cvFindContoursUntyped) cvFindContours;
%pythoncode %{
def cvFindContours( *args ):
	count, seq = cvFindContoursUntyped( *args )
	return count, CvSeq_CvPoint.cast(seq)
%}

/* cvHoughLines2 returns a different type of sequence depending on its args */
%rename (cvHoughLinesUntyped) cvHoughLines2;
%pythoncode %{
def cvHoughLines2( *args ):
	seq = cvHoughLinesUntyped( *args )
	type = CV_SEQ_ELTYPE(seq) 
	if type == CV_32SC4:
		return CvSeq_CvPoint_2.cast(seq)
	return CvSeq_float_2.cast(seq)
%}

// cvPointSeqFromMat
// cvSeqPartition
// cvSeqSlice
// cvTreeToNodeSeq

// Elsewhere in this wrapper, the cvRelease* functions are mapped to 
// the destructors for the corresponding OpenCV object wrapper.  This
// is done in order to let Python handle memory management.  If the 
// reference count of the Python object wrapping the OpenCV object 
// goes to 0, the garbage collector will call the destructor, and 
// therefore the cvRelease* function, before freeing the Python object.
// However, if the user explicitly calls the cvRelease* function, we 
// must prevent the Python garbage collector from calling it again when
// the refcount reaches 0 -- otherwise a double-free error occurs.
//
// Thus, below, we redirect each cvRelease* function to the 
// corresponding OpenCV object's destructor.  This has the effect of:
// (1) Calling the corresponding cvRelease* function, and therefore 
//     immediately releasing the OpenCV object.
// (2) Telling SWIG to disown memory management for this OpenCV object.  
//
// Thus, when the refcount for the Python object reaches 0, the Python
// object is garbage collected, but since it no longer owns the OpenCV 
// object, this is not freed again.
%define %myrelease(Function, Type)
%ignore Function;
%rename (Function) Function##_Shadow;
%pythoncode %{
Function = _cv.delete_##Type
%}
%enddef

// TODO some of these objects lack the delete method -- why???
%myrelease(cvReleaseImage, CvMat);  // IplImage is CvMat in Python
%myrelease(cvReleaseMat, CvMat);
%myrelease(cvReleaseStructuringElement, IplConvKernel);
%myrelease(cvReleaseConDensation, CvConDensation);
%myrelease(cvReleaseKalman, CvKalman);
%myrelease(cvReleaseHist, CvHistogram);
%myrelease(cvReleaseHaarClassifierCascade, CvHaarClassifierCascade);
//%myrelease(cvReleasePOSITObject, CvPOSITObject);
%myrelease(cvReleaseImageHeader, CvMat); // IplImage is CvMat
%myrelease(cvReleaseMatND, CvMatND);
%myrelease(cvReleaseSparseMat, CvSparseMat);
%myrelease(cvReleaseMemStorage, CvMemStorage);
%myrelease(cvReleaseGraphScanner, CvGraphScanner);
//%myrelease(cvReleaseFileStorage, CvFileStorage);
//%myrelease(cvReleaseCapture, CvCapture);
//%myrelease(cvReleaseVideoWriter, CvVideoWriter);

// TODO implement this
%ignore cvRelease;
