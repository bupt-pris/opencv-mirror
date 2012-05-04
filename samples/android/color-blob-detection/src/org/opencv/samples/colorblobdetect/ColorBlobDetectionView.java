package org.opencv.samples.colorblobdetect;

import java.util.ArrayList;
import java.util.List;

import org.opencv.android.Utils;
import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.MatOfPoint;
import org.opencv.core.Rect;
import org.opencv.core.Scalar;
import org.opencv.core.Size;
import org.opencv.highgui.Highgui;
import org.opencv.highgui.VideoCapture;
import org.opencv.imgproc.Imgproc;

import android.content.Context;
import android.graphics.Bitmap;
import android.util.Log;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.View;
import android.view.View.OnTouchListener;

public class ColorBlobDetectionView extends SampleCvViewBase implements OnTouchListener {

	private Mat mRgba;
	private static final String TAG = "Example/CollorBlobDetection";

	public boolean mIsColorSelected = false;
	public Scalar mSelectedColorRgba = new Scalar(255);
	public Scalar mSelectedColorHsv = new Scalar(255);
	public Scalar mLowerBound = new Scalar(0);
	public Scalar mUpperBound = new Scalar(0);
	private final int mColorRadius = 25;
	public Mat mSpectrum = new Mat();
	public int mSpectrumScale = 2;
	
	public ColorBlobDetectionView(Context context)
	{
        super(context);
        setOnTouchListener(this);
	}
	
    @Override
    public void surfaceChanged(SurfaceHolder _holder, int format, int width, int height) {
        super.surfaceChanged(_holder, format, width, height);
        synchronized (this) {
            // initialize Mat before usage
            mRgba = new Mat();
        }
    }
	
	public boolean onTouch(View v, MotionEvent event)
	{
		// TODO Auto-generated method stub
        int cols = mRgba.cols();
        int rows = mRgba.rows();
        
        Log.d(TAG, "Resolition: " + cols + "x" + rows);
        
        int xoffset = (getWidth() - cols) / 2;
        int yoffset = (getHeight() - rows) / 2;

        Log.d(TAG, "Touch offset " + xoffset + "x" + yoffset);
        
        Log.d(TAG, "Screen touch coordinates: " + event.getX() + "x" + event.getY());
        
        int x = (int)event.getX() - xoffset;
        int y = (int)event.getY() - yoffset;
        
        Log.i(TAG, "Touch coordinates: (" + x + ", " + y + ")");
        
        if ((x > cols) || (y > rows)) return false;
  
        Rect TouchedRect = new Rect();
        
        if (x-4 >= 0)
        	TouchedRect.x = x-4;
        else
        	TouchedRect.x = 0;
        
        if (y-4 >= 0)
        	TouchedRect.y = y-4;
        else
        	TouchedRect.y = 0;

        if (x+4 < mRgba.cols())
        	TouchedRect.width = x + 4 - TouchedRect.x;
        else
        	TouchedRect.width = mRgba.width() - TouchedRect.x;
        
        if (y+4 < mRgba.rows())
        	TouchedRect.height = y+4 - TouchedRect.y;
        else
        	TouchedRect.height = mRgba.rows() - TouchedRect.y;
        	
        Mat TouchedRegionMat = mRgba.submat(TouchedRect);
        Mat TouchedRegionMatHsv = new Mat();
        
        Imgproc.cvtColor(TouchedRegionMat, TouchedRegionMatHsv, Imgproc.COLOR_RGB2HSV_FULL);
        
        mSelectedColorHsv = Core.sumElems(TouchedRegionMatHsv);
        int DotCount = TouchedRect.width*TouchedRect.height;
        for (int i = 0; i < mSelectedColorHsv.val.length; i++)
        {
        	mSelectedColorHsv.val[i] /= DotCount;
        }
        
        Mat rgbaDotMap = new Mat();
        Mat hsvDotMat = new Mat(1, 1, CvType.CV_8UC3);
        
        byte[] buf = {(byte)mSelectedColorHsv.val[0], (byte)mSelectedColorHsv.val[1], (byte)mSelectedColorHsv.val[2]};
        
        hsvDotMat.put(0, 0, buf);
        Imgproc.cvtColor(hsvDotMat, rgbaDotMap, Imgproc.COLOR_HSV2RGB_FULL, 4);
        
        mSelectedColorRgba.val = rgbaDotMap.get(0, 0);
        
        Log.i(TAG, "Touched rgba color: (" + mSelectedColorRgba.val[0] + ", " + mSelectedColorRgba.val[1] + 
    			", " + mSelectedColorRgba.val[2] + ", " + mSelectedColorRgba.val[3] + ")");
        
    	double MinH = 0;
    	double MaxH = 255;
        
        if (mSelectedColorHsv.val[0]-mColorRadius >= 0)
        	MinH = mSelectedColorHsv.val[0]-mColorRadius;
        else
        	MinH = 0;
        
        if (mSelectedColorHsv.val[0]+mColorRadius <= 255)
        	MaxH = mSelectedColorHsv.val[0]+mColorRadius;
        else
        	MaxH = 255;
    	
  		mLowerBound.val[0] = MinH;
   		mUpperBound.val[0] = MaxH;
   		
  		mLowerBound.val[1] = 100;
   		mUpperBound.val[1] = 255;
   		
  		mLowerBound.val[2] = 100;
   		mUpperBound.val[2] = 255;
   		
   		Mat HsvSpectrum = new Mat(32, 2*mColorRadius*mSpectrumScale, CvType.CV_8UC3);
   		
   		for (int i = 0; i < 32; i++)
   		{
   			for (int k = 0; k < mSpectrumScale; k++)
   			{
   				for (int j = 0; j < MaxH-MinH; j++)
   				{
   					byte[] tmp = {(byte)(MinH+j), (byte)255, (byte)255};
   					HsvSpectrum.put(i, j*mSpectrumScale + k, tmp);
   				}
   			}
   		}
        
   		Imgproc.cvtColor(HsvSpectrum, mSpectrum, Imgproc.COLOR_HSV2RGB_FULL, 4);
   		
        mIsColorSelected = true;
        
        return false; // don't need subsequent touch events
	}

	@Override
	protected Bitmap processFrame(VideoCapture capture) {
		// TODO Auto-generated method stub
		capture.retrieve(mRgba, Highgui.CV_CAP_ANDROID_COLOR_FRAME_RGBA);
		
        Bitmap bmp = Bitmap.createBitmap(mRgba.cols(), mRgba.rows(), Bitmap.Config.ARGB_8888);
        
        if (mIsColorSelected)
        {        	
        	Mat BlurMat = mRgba; //new Mat();
        	//Imgproc.blur(mRgba, BlurMat, new Size(3, 3));
        	
        	Mat hsvMat = new Mat();
        	Imgproc.cvtColor(BlurMat, hsvMat, Imgproc.COLOR_RGB2HSV_FULL);
       		
        	Log.d(TAG, "Bounds: " + mLowerBound + "x" + mUpperBound);
        	
        	Mat RangedHsvMat = new Mat();
        	Core.inRange(hsvMat, mLowerBound, mUpperBound, RangedHsvMat);
        	
        	Mat DilatedMat = new Mat();
        	Imgproc.dilate(RangedHsvMat, DilatedMat, new Mat());

        	Mat CannyRangedMat = new Mat();
        	Imgproc.Canny(RangedHsvMat, CannyRangedMat, 80, 90);
        	        	
            List<MatOfPoint> contours = new ArrayList<MatOfPoint>(5);
            Mat hierarchy = new Mat();

            Imgproc.findContours(CannyRangedMat, contours, hierarchy, Imgproc.RETR_EXTERNAL, Imgproc.CHAIN_APPROX_SIMPLE);
            Imgproc.drawContours(mRgba, contours, -1, new Scalar(255,0,0,255));
            
            Mat TestColorMat = mRgba.submat(2, 34, 2, 34);
            TestColorMat.setTo(mSelectedColorRgba);
            
            Mat TestSpectrumMat = mRgba.submat(2, 34, 38, 38 + mSpectrum.cols());
            mSpectrum.copyTo(TestSpectrumMat);
        }

        try {
        	Utils.matToBitmap(mRgba, bmp);
        } catch(Exception e) {
        	Log.e(TAG, "Utils.matToBitmap() throws an exception: " + e.getMessage());
            bmp.recycle();
            bmp = null;
        }
        
        return bmp;
	}
	
    @Override
    public void run() {
        super.run();

        synchronized (this) {
            // Explicitly deallocate Mats
            if (mRgba != null)
                mRgba.release();

            mRgba = null;
        }
    }
}
