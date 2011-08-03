package org.opencv.test.calib3d;

import java.util.ArrayList;
import java.util.List;

import org.opencv.calib3d.Calib3d;
import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.Point;
import org.opencv.core.Point3;
import org.opencv.core.Scalar;
import org.opencv.core.Size;
import org.opencv.test.OpenCVTestCase;

public class calib3dTest extends OpenCVTestCase {

    public void test_1() {
        super.test_1("calib3d");
    }

    public void testCalibrateCameraListOfMatListOfMatSizeMatMatListOfMatListOfMat() {
        fail("Not yet implemented");
    }

    public void testCalibrateCameraListOfMatListOfMatSizeMatMatListOfMatListOfMatInt() {
        fail("Not yet implemented");
    }

    public void testCalibrationMatrixValues() {
        fail("Not yet implemented");
    }

    public void testComposeRTMatMatMatMatMatMat() {
        Mat rvec1 = new Mat(3, 1, CvType.CV_32F);
        rvec1.put(0, 0, 0.5302828, 0.19925919, 0.40105945);
        Mat tvec1 = new Mat(3, 1, CvType.CV_32F);
        tvec1.put(0, 0, 0.81438506, 0.43713298, 0.2487897);
        Mat rvec2 = new Mat(3, 1, CvType.CV_32F);
        rvec2.put(0, 0, 0.77310503, 0.76209372, 0.30779448);
        Mat tvec2 = new Mat(3, 1, CvType.CV_32F);
        tvec2.put(0, 0, 0.70243168, 0.4784472, 0.79219002);

        Mat rvec3 = new Mat();
        Mat tvec3 = new Mat();

        Mat outRvec = new Mat(3, 1, CvType.CV_32F);
        outRvec.put(0, 0, 1.418641, 0.88665926, 0.56020796);
        Mat outTvec = new Mat(3, 1, CvType.CV_32F);
        outTvec.put(0, 0, 1.4560841, 1.0680628, 0.81598103);

        Calib3d.composeRT(rvec1, tvec1, rvec2, tvec2, rvec3, tvec3);

        assertMatEqual(outRvec, rvec3, EPS);
        assertMatEqual(outTvec, tvec3, EPS);
    }

    public void testComposeRTMatMatMatMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testComposeRTMatMatMatMatMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testComposeRTMatMatMatMatMatMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testComposeRTMatMatMatMatMatMatMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testComposeRTMatMatMatMatMatMatMatMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testComposeRTMatMatMatMatMatMatMatMatMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testComposeRTMatMatMatMatMatMatMatMatMatMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testComposeRTMatMatMatMatMatMatMatMatMatMatMatMatMatMat() {
        fail("Not yet implemented");
        // Mat dr3dr1;
        // Mat dr3dt1;
        // Mat dr3dr2;
        // Mat dr3dt2;
        // Mat dt3dr1;
        // Mat dt3dt1;
        // Mat dt3dr2;
        // Mat dt3dt2;
        // , dr3dr1, dr3dt1, dr3dr2, dr3dt2, dt3dr1, dt3dt1, dt3dr2, dt3dt2);
        // [0.97031879, -0.091774099, 0.38594806;
        // 0.15181915, 0.98091727, -0.44186208;
        // -0.39509675, 0.43839464, 0.93872648]
        // [0, 0, 0;
        // 0, 0, 0;
        // 0, 0, 0]
        // [1.0117353, 0.16348237, -0.083180845;
        // -0.1980398, 1.006078, 0.30299222;
        // 0.075766489, -0.32784501, 1.0163091]
        // [0, 0, 0;
        // 0, 0, 0;
        // 0, 0, 0]
        // [0, 0, 0;
        // 0, 0, 0;
        // 0, 0, 0]
        // [0.69658804, 0.018115902, 0.7172426;
        // 0.51114357, 0.68899536, -0.51382649;
        // -0.50348526, 0.72453934, 0.47068608]
        // [0.18536358, -0.20515044, -0.48834875;
        // -0.25120571, 0.29043972, 0.60573936;
        // 0.35370794, -0.69923931, 0.45781645]
        // [1, 0, 0;
        // 0, 1, 0;
        // 0, 0, 1]
    }

    public void testConvertPointsFromHomogeneous() {
        fail("Not yet implemented");
    }

    public void testConvertPointsToHomogeneous() {
        fail("Not yet implemented");
    }

    public void testDecomposeProjectionMatrixMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testDecomposeProjectionMatrixMatMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testDecomposeProjectionMatrixMatMatMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testDecomposeProjectionMatrixMatMatMatMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testDecomposeProjectionMatrixMatMatMatMatMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testDrawChessboardCorners() {
        fail("Not yet implemented");
    }

    public void testEstimateAffine3DMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testEstimateAffine3DMatMatMatMatDouble() {
        fail("Not yet implemented");
    }

    public void testEstimateAffine3DMatMatMatMatDoubleDouble() {
        fail("Not yet implemented");
    }

    public void testFilterSpecklesMatDoubleIntDouble() {
        gray_16s_1024.copyTo(dst);
        Point center = new Point(gray_16s_1024.rows() / 2., gray_16s_1024.cols() / 2.);
        Core.circle(dst, center, 1, Scalar.all(4096));

        assertMatNotEqual(gray_16s_1024, dst);
        Calib3d.filterSpeckles(dst, 1024.0, 100, 0.);
        assertMatEqual(gray_16s_1024, dst);
    }

    public void testFilterSpecklesMatDoubleIntDoubleMat() {
        fail("Not yet implemented");
    }

    public void testFindChessboardCornersMatSizeMat() {
        Size patternSize = new Size(9, 6);
        Calib3d.findChessboardCorners(grayChess, patternSize, dst);
        assertTrue(!dst.empty());
    }

    public void testFindChessboardCornersMatSizeMatInt() {
        Size patternSize = new Size(9, 6);
        Calib3d.findChessboardCorners(grayChess, patternSize, dst, Calib3d.CALIB_CB_ADAPTIVE_THRESH + Calib3d.CALIB_CB_NORMALIZE_IMAGE
                + Calib3d.CALIB_CB_FAST_CHECK);
        assertTrue(!dst.empty());
    }

    public void testFindCirclesGridDefaultMatSizeMat() {
        int size = 300;
        Mat img = new Mat(size, size, CvType.CV_8U);
        img.setTo(new Scalar(255));
        Mat centers = new Mat();

        assertFalse(Calib3d.findCirclesGridDefault(img, new Size(5, 5), centers));

        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) {
                Point pt = new Point(size * (2 * i + 1) / 10, size * (2 * j + 1) / 10);
                Core.circle(img, pt, 10, new Scalar(0), -1);
            }

        assertTrue(Calib3d.findCirclesGridDefault(img, new Size(5, 5), centers));

        assertEquals(25, centers.rows());
        assertEquals(1, centers.cols());
        assertEquals(CvType.CV_32FC2, centers.type());
    }

    public void testFindCirclesGridDefaultMatSizeMatInt() {
        int size = 300;
        Mat img = new Mat(size, size, CvType.CV_8U);
        img.setTo(new Scalar(255));
        Mat centers = new Mat();

        assertFalse(Calib3d.findCirclesGridDefault(img, new Size(3, 5), centers, Calib3d.CALIB_CB_CLUSTERING
                | Calib3d.CALIB_CB_ASYMMETRIC_GRID));

        int step = size * 2 / 15;
        int offsetx = size / 6;
        int offsety = (size - 4 * step) / 2;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 5; j++) {
                Point pt = new Point(offsetx + (2 * i + j % 2) * step, offsety + step * j);
                Core.circle(img, pt, 10, new Scalar(0), -1);
            }

        assertTrue(Calib3d.findCirclesGridDefault(img, new Size(3, 5), centers, Calib3d.CALIB_CB_CLUSTERING
                | Calib3d.CALIB_CB_ASYMMETRIC_GRID));

        assertEquals(15, centers.rows());
        assertEquals(1, centers.cols());
        assertEquals(CvType.CV_32FC2, centers.type());
    }

    public void testFindFundamentalMatMatMat() {
        List<Point> pts1 = new ArrayList<Point>();
        List<Point> pts2 = new ArrayList<Point>();

        int minFundamentalMatPoints = 8;
        for (int i = 0; i < minFundamentalMatPoints; i++) {
            double x = Math.random() * 100 - 50;
            double y = Math.random() * 100 - 50;
            pts1.add(new Point(x, y));
            pts2.add(new Point(x, y));
        }

        Mat fm = Calib3d.findFundamentalMat(pts1, pts2);

        truth = new Mat(3, 3, CvType.CV_64F);
        truth.put(0, 0, 0, -0.5, -0.5, 0.5, 0, 0, 0.5, 0, 0);
        assertMatEqual(truth, fm, EPS);
    }

    public void testFindFundamentalMatMatMatInt() {
        fail("Not yet implemented");
    }

    public void testFindFundamentalMatMatMatIntDouble() {
        fail("Not yet implemented");
    }

    public void testFindFundamentalMatMatMatIntDoubleDouble() {
        fail("Not yet implemented");
    }

    public void testFindFundamentalMatMatMatIntDoubleDoubleMat() {
        fail("Not yet implemented");
    }

    public void testFindHomographyMatMat() {

        List<Point> originalPoints = new ArrayList<Point>();
        List<Point> transformedPoints = new ArrayList<Point>();

        for (int i = 0; i < 20; i++) {
            double x = Math.random() * 100 - 50;
            double y = Math.random() * 100 - 50;
            originalPoints.add(new Point(x, y));
            transformedPoints.add(new Point(y, x));
        }

        Mat hmg = Calib3d.findHomography(originalPoints, transformedPoints);

        truth = new Mat(3, 3, CvType.CV_64F);
        truth.put(0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1);

        assertMatEqual(truth, hmg, EPS);
    }

    public void testFindHomographyMatMatInt() {
        fail("Not yet implemented");
    }

    public void testFindHomographyMatMatIntDouble() {
        fail("Not yet implemented");
    }

    public void testFindHomographyMatMatIntDoubleMat() {
        fail("Not yet implemented");
    }

    public void testGetOptimalNewCameraMatrixMatMatSizeDouble() {
        fail("Not yet implemented");
    }

    public void testGetOptimalNewCameraMatrixMatMatSizeDoubleSize() {
        fail("Not yet implemented");
    }

    public void testGetOptimalNewCameraMatrixMatMatSizeDoubleSizeRect() {
        fail("Not yet implemented");
    }

    public void testGetOptimalNewCameraMatrixMatMatSizeDoubleSizeRectBoolean() {
        fail("Not yet implemented");
    }

    public void testGetValidDisparityROI() {
        fail("Not yet implemented");
    }

    public void testInitCameraMatrix2DListOfMatListOfMatSize() {
        fail("Not yet implemented");
    }

    public void testInitCameraMatrix2DListOfMatListOfMatSizeDouble() {
        fail("Not yet implemented");
    }

    public void testMatMulDeriv() {
        fail("Not yet implemented");
    }

    public void testProjectPointsMatMatMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testProjectPointsMatMatMatMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testProjectPointsMatMatMatMatMatMatMatDouble() {
        fail("Not yet implemented");
    }

    public void testRectify3Collinear() {
        fail("Not yet implemented");
    }

    public void testReprojectImageTo3DMatMatMat() {
        Mat transformMatrix = new Mat(4, 4, CvType.CV_64F);
        transformMatrix.put(0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

        Mat disparity = new Mat(matSize, matSize, CvType.CV_32F);

        float[] disp = new float[matSize * matSize];
        for (int i = 0; i < matSize; i++)
            for (int j = 0; j < matSize; j++)
                disp[i * matSize + j] = i - j;
        disparity.put(0, 0, disp);

        Mat _3dPoints = new Mat();

        Calib3d.reprojectImageTo3D(disparity, _3dPoints, transformMatrix);

        assertEquals(CvType.CV_32FC3, _3dPoints.type());
        assertEquals(matSize, _3dPoints.rows());
        assertEquals(matSize, _3dPoints.cols());

        truth = new Mat(matSize, matSize, CvType.CV_32FC3);

        float[] _truth = new float[matSize * matSize * 3];
        for (int i = 0; i < matSize; i++)
            for (int j = 0; j < matSize; j++) {
                _truth[(i * matSize + j) * 3 + 0] = i;
                _truth[(i * matSize + j) * 3 + 1] = j;
                _truth[(i * matSize + j) * 3 + 2] = i - j;
            }
        truth.put(0, 0, _truth);

        assertMatEqual(truth, _3dPoints, EPS);
    }

    public void testReprojectImageTo3DMatMatMatBoolean() {
        Mat transformMatrix = new Mat(4, 4, CvType.CV_64F);
        transformMatrix.put(0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

        Mat disparity = new Mat(matSize, matSize, CvType.CV_32F);

        float[] disp = new float[matSize * matSize];
        for (int i = 0; i < matSize; i++)
            for (int j = 0; j < matSize; j++)
                disp[i * matSize + j] = i - j;
        disp[0] = -Float.MAX_VALUE;
        disparity.put(0, 0, disp);

        Mat _3dPoints = new Mat();

        Calib3d.reprojectImageTo3D(disparity, _3dPoints, transformMatrix, true);

        assertEquals(CvType.CV_32FC3, _3dPoints.type());
        assertEquals(matSize, _3dPoints.rows());
        assertEquals(matSize, _3dPoints.cols());

        truth = new Mat(matSize, matSize, CvType.CV_32FC3);

        float[] _truth = new float[matSize * matSize * 3];
        for (int i = 0; i < matSize; i++)
            for (int j = 0; j < matSize; j++) {
                _truth[(i * matSize + j) * 3 + 0] = i;
                _truth[(i * matSize + j) * 3 + 1] = j;
                _truth[(i * matSize + j) * 3 + 2] = i - j;
            }
        _truth[2] = 10000;
        truth.put(0, 0, _truth);

        assertMatEqual(truth, _3dPoints, EPS);
    }

    public void testReprojectImageTo3DMatMatMatBooleanInt() {
        Mat transformMatrix = new Mat(4, 4, CvType.CV_64F);
        transformMatrix.put(0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

        Mat disparity = new Mat(matSize, matSize, CvType.CV_32F);

        float[] disp = new float[matSize * matSize];
        for (int i = 0; i < matSize; i++)
            for (int j = 0; j < matSize; j++)
                disp[i * matSize + j] = i - j;
        disparity.put(0, 0, disp);

        Mat _3dPoints = new Mat();

        Calib3d.reprojectImageTo3D(disparity, _3dPoints, transformMatrix, false, CvType.CV_16S);

        assertEquals(CvType.CV_16SC3, _3dPoints.type());
        assertEquals(matSize, _3dPoints.rows());
        assertEquals(matSize, _3dPoints.cols());

        truth = new Mat(matSize, matSize, CvType.CV_16SC3);

        short[] _truth = new short[matSize * matSize * 3];
        for (short i = 0; i < matSize; i++)
            for (short j = 0; j < matSize; j++) {
                _truth[(i * matSize + j) * 3 + 0] = i;
                _truth[(i * matSize + j) * 3 + 1] = j;
                _truth[(i * matSize + j) * 3 + 2] = (short) (i - j);
            }
        truth.put(0, 0, _truth);

        assertMatEqual(truth, _3dPoints, EPS);
    }

    public void testRodriguesMatMat() {
        Mat r = new Mat(3, 1, CvType.CV_32F);
        Mat R = new Mat(3, 3, CvType.CV_32F);

        r.put(0, 0, Math.PI, 0, 0);

        Calib3d.Rodrigues(r, R);

        truth = new Mat(3, 3, CvType.CV_32F);
        truth.put(0, 0, 1, 0, 0, 0, -1, 0, 0, 0, -1);
        assertMatEqual(truth, R, EPS);

        Mat r2 = new Mat();
        Calib3d.Rodrigues(R, r2);

        assertMatEqual(r, r2, EPS);
    }

    public void testRodriguesMatMatMat() {
        fail("Not yet implemented");
    }

    public void testRQDecomp3x3MatMatMat() {
        fail("Not yet implemented");
    }

    public void testRQDecomp3x3MatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testRQDecomp3x3MatMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testRQDecomp3x3MatMatMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testSolvePnPMatMatMatMatMatMat() {
        Mat intrinsics = Mat.eye(3, 3, CvType.CV_32F);
        intrinsics.put(0, 0, 400);
        intrinsics.put(1, 1, 400);
        intrinsics.put(0, 2, 640 / 2);
        intrinsics.put(1, 2, 480 / 2);

        List<Point3> points3d = new ArrayList<Point3>();
        List<Point> points2d = new ArrayList<Point>();
        int minPnpPointsNum = 4;

        for (int i = 0; i < minPnpPointsNum; i++) {
            double x = Math.random() * 100 - 50;
            double y = Math.random() * 100 - 50;
            points2d.add(new Point(x, y));
            points3d.add(new Point3(0, y, x));
        }

        Mat rvec = new Mat();
        Mat tvec = new Mat();
        Calib3d.solvePnP(points3d, points2d, intrinsics, new Mat(), rvec, tvec);

        Mat truth_rvec = new Mat(3, 1, CvType.CV_64F);
        truth_rvec.put(0, 0, 0, Math.PI / 2, 0);

        Mat truth_tvec = new Mat(3, 1, CvType.CV_64F);
        truth_tvec.put(0, 0, -320, -240, 400);

        assertMatEqual(truth_rvec, rvec, EPS);
        assertMatEqual(truth_tvec, tvec, EPS);
    }

    public void testSolvePnPMatMatMatMatMatMatBoolean() {
        fail("Not yet implemented");
    }

    public void testSolvePnPRansacMatMatMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testSolvePnPRansacMatMatMatMatMatMatBoolean() {
        fail("Not yet implemented");
    }

    public void testSolvePnPRansacMatMatMatMatMatMatBooleanInt() {
        fail("Not yet implemented");
    }

    public void testSolvePnPRansacMatMatMatMatMatMatBooleanIntFloat() {
        fail("Not yet implemented");
    }

    public void testSolvePnPRansacMatMatMatMatMatMatBooleanIntFloatInt() {
        fail("Not yet implemented");
    }

    public void testSolvePnPRansacMatMatMatMatMatMatBooleanIntFloatIntMat() {
        fail("Not yet implemented");
    }

    public void testStereoCalibrateListOfMatListOfMatListOfMatMatMatMatMatSizeMatMatMatMat() {
        fail("Not yet implemented");
    }

    public void testStereoCalibrateListOfMatListOfMatListOfMatMatMatMatMatSizeMatMatMatMatTermCriteria() {
        fail("Not yet implemented");
    }

    public void testStereoCalibrateListOfMatListOfMatListOfMatMatMatMatMatSizeMatMatMatMatTermCriteriaInt() {
        fail("Not yet implemented");
    }

    public void testStereoRectifyUncalibratedMatMatMatSizeMatMat() {
        fail("Not yet implemented");
    }

    public void testStereoRectifyUncalibratedMatMatMatSizeMatMatDouble() {
        fail("Not yet implemented");
    }

    public void testValidateDisparityMatMatIntInt() {
        fail("Not yet implemented");
    }

    public void testValidateDisparityMatMatIntIntInt() {
        fail("Not yet implemented");
    }

}
