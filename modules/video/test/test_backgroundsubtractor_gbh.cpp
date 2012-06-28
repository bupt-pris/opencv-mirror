/*
 * BackgroundSubtractorGBH_test.cpp
 *
 *  Created on: Jun 14, 2012
 *      Author: andrewgodbehere
 */

#include "test_precomp.hpp"

using namespace cv;

class CV_BackgroundSubtractorTest : public cvtest::BaseTest
{
public:
	CV_BackgroundSubtractorTest();
protected:
	void run(int);
};

CV_BackgroundSubtractorTest::CV_BackgroundSubtractorTest()
{
}

/**
 * This test checks the following:
 * (i) BackgroundSubtractorGMG can operate with matrices of various types and sizes
 * (ii) Training mode returns empty fgmask
 * (iii) End of training mode, and anomalous frame yields every pixel detected as FG
 */
void CV_BackgroundSubtractorTest::run(int)
{
	int code = cvtest::TS::OK;
	RNG& rng = ts->get_rng();
	int type = ((unsigned int)rng)%7;  //!< pick a random type, 0 - 6, defined in types_c.h
	int channels = 1 + ((unsigned int)rng)%4;  //!< random number of channels from 1 to 4.
	int channelsAndType = CV_MAKETYPE(type,channels);
	int width = 2 + ((unsigned int)rng)%98; //!< Mat will be 2 to 100 in width and height
	int height = 2 + ((unsigned int)rng)%98;

	Ptr<BackgroundSubtractorGMG> fgbg =
			Algorithm::create<BackgroundSubtractorGMG>("BackgroundSubtractor.GMG");
	Mat fgmask;

	if (fgbg == NULL)
		CV_Error(CV_StsError,"Failed to create Algorithm\n");

	/**
	 * Set a few parameters
	 */
	fgbg->set("smoothingRadius",7);
	fgbg->set("decisionThreshold",0.7);
	fgbg->set("initializationFrames",120);

	/**
	 * Generate bounds for the values in the matrix for each type
	 */
	uchar maxuc,minuc = 0;
	char maxc,minc = 0;
	uint maxui,minui = 0;
	int maxi,mini = 0;
	long int maxli,minli = 0;
	float maxf,minf = 0.0;
	double maxd,mind = 0.0;

	/**
	 * Max value for simulated images picked randomly in upper half of type range
	 * Min value for simulated images picked randomly in lower half of type range
	 */
	if (type == CV_8U)
	{
		unsigned char half = UCHAR_MAX/2;
		maxuc = (unsigned char)rng.uniform(half+32,UCHAR_MAX);
		minuc = (unsigned char)rng.uniform(0,half-32);
	}
	else if (type == CV_8S)
	{
		char half = CHAR_MAX/2 + CHAR_MIN/2;
		maxc = (char)rng.uniform(half+32,CHAR_MAX);
		minc = (char)rng.uniform(CHAR_MIN,half-32);
	}
	else if (type == CV_16U)
	{
		uint half = UINT_MAX/2;
		maxui = (unsigned int)rng.uniform((int)half+32,UINT_MAX);
		minui = (unsigned int)rng.uniform(0,(int)half-32);
	}
	else if (type == CV_16S)
	{
		int half = INT_MAX/2 + INT_MIN/2;
		maxi = rng.uniform(half+32,INT_MAX);
		mini = rng.uniform(INT_MIN,half-32);
	}
	else if (type == CV_32S)
	{
		long int half = LONG_MAX/2 + LONG_MIN/2;
		maxli = rng.uniform((int)half+32,(int)LONG_MAX);
		minli = rng.uniform((int)LONG_MIN,(int)half-32);
	}
	else if (type == CV_32F)
	{
		float half = FLT_MAX/2.0 + FLT_MIN/2.0;
		maxf = rng.uniform(half+(float)32.0*FLT_EPSILON,FLT_MAX);
		minf = rng.uniform(FLT_MIN,half-(float)32.0*FLT_EPSILON);
	}
	else if (type == CV_64F)
	{
		double half = DBL_MAX/2.0 + DBL_MIN/2.0;
		maxd = rng.uniform(half+(double)32.0*DBL_EPSILON,DBL_MAX);
		mind = rng.uniform(DBL_MIN,half-(double)32.0*DBL_EPSILON);
	}

	Mat simImage = Mat::zeros(height,width,channelsAndType);
	const uint numLearningFrames = 120;
	for (uint i = 0; i < numLearningFrames; ++i)
	{
		/**
		 * Genrate simulated "image" for any type. Values always confined to upper half of range.
		 */
		if (type == CV_8U)
		{
			rng.fill(simImage,RNG::UNIFORM,(unsigned char)(minuc/2+maxuc/2),maxuc);
			if (i == 0)
				fgbg->initializeType(simImage,minuc,maxuc);
		}
		else if (type == CV_8S)
		{
			rng.fill(simImage,RNG::UNIFORM,(char)(minc/2+maxc/2),maxc);
			if (i==0)
				fgbg->initializeType(simImage,minc,maxc);
		}
		else if (type == CV_16U)
		{
			rng.fill(simImage,RNG::UNIFORM,(unsigned int)(minui/2+maxui/2),maxui);
			if (i==0)
				fgbg->initializeType(simImage,minui,maxui);
		}
		else if (type == CV_16S)
		{
			rng.fill(simImage,RNG::UNIFORM,(int)(mini/2+maxi/2),maxi);
			if (i==0)
				fgbg->initializeType(simImage,mini,maxi);
		}
		else if (type == CV_32F)
		{
			rng.fill(simImage,RNG::UNIFORM,(float)(minf/2.0+maxf/2.0),maxf);
			if (i==0)
				fgbg->initializeType(simImage,minf,maxf);
		}
		else if (type == CV_32S)
		{
			rng.fill(simImage,RNG::UNIFORM,(long int)(minli/2+maxli/2),maxli);
			if (i==0)
				fgbg->initializeType(simImage,minli,maxli);
		}
		else if (type == CV_64F)
		{
			rng.fill(simImage,RNG::UNIFORM,(double)(mind/2.0+maxd/2.0),maxd);
			if (i==0)
				fgbg->initializeType(simImage,mind,maxd);
		}

		/**
		 * Feed simulated images into background subtractor
		 */
		(*fgbg)(simImage,fgmask);
		Mat fullbg = Mat::zeros(Size(simImage.cols,simImage.rows),CV_8U);
		fgbg->updateBackgroundModel(fullbg);

		//! fgmask should be entirely background during training
		code = cvtest::cmpEps2( ts, fgmask, fullbg, 0, false, "The training foreground mask" );
		if (code < 0)
			ts->set_failed_test_info( code );
	}
	//! generate last image, distinct from training images
	if (type == CV_8U)
		rng.fill(simImage,RNG::UNIFORM,minuc,minuc);
	else if (type == CV_8S)
		rng.fill(simImage,RNG::UNIFORM,minc,minc);
	else if (type == CV_16U)
		rng.fill(simImage,RNG::UNIFORM,minui,minui);
	else if (type == CV_16S)
		rng.fill(simImage,RNG::UNIFORM,mini,mini);
	else if (type == CV_32F)
		rng.fill(simImage,RNG::UNIFORM,minf,minf);
	else if (type == CV_32S)
		rng.fill(simImage,RNG::UNIFORM,minli,minli);
	else if (type == CV_64F)
		rng.fill(simImage,RNG::UNIFORM,mind,mind);

	(*fgbg)(simImage,fgmask);
	//! now fgmask should be entirely foreground
	Mat fullfg = 255*Mat::ones(Size(simImage.cols,simImage.rows),CV_8U);
	code = cvtest::cmpEps2( ts, fgmask, fullfg, 255, false, "The final foreground mask" );
	if (code < 0)
	{
		ts->set_failed_test_info( code );
	}

}

TEST(VIDEO_BGSUBGMG, accuracy) { CV_BackgroundSubtractorTest test; test.safe_run(); }
