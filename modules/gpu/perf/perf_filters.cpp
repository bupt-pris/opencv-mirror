#include "perf_precomp.hpp"

#ifdef HAVE_CUDA

IMPLEMENT_PARAM_CLASS(KernelSize, int)

//////////////////////////////////////////////////////////////////////
// Blur

GPU_PERF_TEST(Blur, cv::gpu::DeviceInfo, cv::Size, MatType, KernelSize)
{
    cv::gpu::DeviceInfo devInfo = GET_PARAM(0);
    cv::gpu::setDevice(devInfo.deviceID());

    cv::Size size = GET_PARAM(1);
    int type = GET_PARAM(2);
    int ksize = GET_PARAM(3);

    cv::Mat src_host(size, type);

    declare.in(src_host, WARMUP_RNG);

    cv::gpu::GpuMat src(src_host);
    cv::gpu::GpuMat dst;

    TEST_CYCLE()
    {
        cv::gpu::blur(src, dst, cv::Size(ksize, ksize));
    }
}

INSTANTIATE_TEST_CASE_P(Filter, Blur, testing::Combine(
    ALL_DEVICES,
    GPU_TYPICAL_MAT_SIZES,
    testing::Values(MatType(CV_8UC1), MatType(CV_8UC4)),
    testing::Values(KernelSize(3), KernelSize(5), KernelSize(7))));

//////////////////////////////////////////////////////////////////////
// Sobel

GPU_PERF_TEST(Sobel, cv::gpu::DeviceInfo, cv::Size, MatType, KernelSize)
{
    cv::gpu::DeviceInfo devInfo = GET_PARAM(0);
    cv::gpu::setDevice(devInfo.deviceID());

    cv::Size size = GET_PARAM(1);
    int type = GET_PARAM(2);
    int ksize = GET_PARAM(3);

    cv::Mat src_host(size, type);

    declare.in(src_host, WARMUP_RNG);

    cv::gpu::GpuMat src(src_host);
    cv::gpu::GpuMat dst;
    cv::gpu::GpuMat buf;

    TEST_CYCLE()
    {
        cv::gpu::Sobel(src, dst, -1, 1, 1, buf, ksize);
    }
}

INSTANTIATE_TEST_CASE_P(Filter, Sobel, testing::Combine(
    ALL_DEVICES,
    GPU_TYPICAL_MAT_SIZES,
    testing::Values(MatType(CV_8UC1), MatType(CV_8UC4), MatType(CV_32FC1)),
    testing::Values(KernelSize(3), KernelSize(5), KernelSize(7), KernelSize(9), KernelSize(11), KernelSize(13), KernelSize(15))));

//////////////////////////////////////////////////////////////////////
// Scharr

GPU_PERF_TEST(Scharr, cv::gpu::DeviceInfo, cv::Size, MatType)
{
    cv::gpu::DeviceInfo devInfo = GET_PARAM(0);
    cv::gpu::setDevice(devInfo.deviceID());

    cv::Size size = GET_PARAM(1);
    int type = GET_PARAM(2);

    cv::Mat src_host(size, type);

    declare.in(src_host, WARMUP_RNG);

    cv::gpu::GpuMat src(src_host);
    cv::gpu::GpuMat dst;
    cv::gpu::GpuMat buf;

    TEST_CYCLE()
    {
        cv::gpu::Scharr(src, dst, -1, 1, 0, buf);
    }
}

INSTANTIATE_TEST_CASE_P(Filter, Scharr, testing::Combine(
    ALL_DEVICES,
    GPU_TYPICAL_MAT_SIZES,
    testing::Values(MatType(CV_8UC1), MatType(CV_8UC4), MatType(CV_32FC1))));

//////////////////////////////////////////////////////////////////////
// GaussianBlur

GPU_PERF_TEST(GaussianBlur, cv::gpu::DeviceInfo, cv::Size, MatType, KernelSize)
{
    cv::gpu::DeviceInfo devInfo = GET_PARAM(0);
    cv::gpu::setDevice(devInfo.deviceID());

    cv::Size size = GET_PARAM(1);
    int type = GET_PARAM(2);
    int ksize = GET_PARAM(3);

    cv::Mat src_host(size, type);

    declare.in(src_host, WARMUP_RNG);

    cv::gpu::GpuMat src(src_host);
    cv::gpu::GpuMat dst;
    cv::gpu::GpuMat buf;

    TEST_CYCLE()
    {
        cv::gpu::GaussianBlur(src, dst, cv::Size(ksize, ksize), buf, 0.5);
    }
}

INSTANTIATE_TEST_CASE_P(Filter, GaussianBlur, testing::Combine(
    ALL_DEVICES,
    GPU_TYPICAL_MAT_SIZES,
    testing::Values(MatType(CV_8UC1), MatType(CV_8UC4), MatType(CV_32FC1)),
    testing::Values(KernelSize(3), KernelSize(5), KernelSize(7), KernelSize(9), KernelSize(11), KernelSize(13), KernelSize(15))));

//////////////////////////////////////////////////////////////////////
// Laplacian

GPU_PERF_TEST(Laplacian, cv::gpu::DeviceInfo, cv::Size, MatType, KernelSize)
{
    cv::gpu::DeviceInfo devInfo = GET_PARAM(0);
    cv::gpu::setDevice(devInfo.deviceID());

    cv::Size size = GET_PARAM(1);
    int type = GET_PARAM(2);
    int ksize = GET_PARAM(3);

    cv::Mat src_host(size, type);

    declare.in(src_host, WARMUP_RNG);

    cv::gpu::GpuMat src(src_host);
    cv::gpu::GpuMat dst;

    TEST_CYCLE()
    {
        cv::gpu::Laplacian(src, dst, -1, ksize);
    }
}

INSTANTIATE_TEST_CASE_P(Filter, Laplacian, testing::Combine(
    ALL_DEVICES,
    GPU_TYPICAL_MAT_SIZES,
    testing::Values(MatType(CV_8UC1), MatType(CV_8UC4), MatType(CV_32FC1), MatType(CV_32FC4)),
    testing::Values(KernelSize(1), KernelSize(3))));

//////////////////////////////////////////////////////////////////////
// Erode

GPU_PERF_TEST(Erode, cv::gpu::DeviceInfo, cv::Size, MatType)
{
    cv::gpu::DeviceInfo devInfo = GET_PARAM(0);
    cv::gpu::setDevice(devInfo.deviceID());

    cv::Size size = GET_PARAM(1);
    int type = GET_PARAM(2);

    cv::Mat src_host(size, type);

    declare.in(src_host, WARMUP_RNG);

    cv::Mat ker = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

    cv::gpu::GpuMat src(src_host);
    cv::gpu::GpuMat dst;
    cv::gpu::GpuMat buf;

    TEST_CYCLE()
    {
        cv::gpu::erode(src, dst, ker, buf);
    }
}

INSTANTIATE_TEST_CASE_P(Filter, Erode, testing::Combine(
    ALL_DEVICES,
    GPU_TYPICAL_MAT_SIZES,
    testing::Values(MatType(CV_8UC1), MatType(CV_8UC4))));

//////////////////////////////////////////////////////////////////////
// Dilate

GPU_PERF_TEST(Dilate, cv::gpu::DeviceInfo, cv::Size, MatType)
{
    cv::gpu::DeviceInfo devInfo = GET_PARAM(0);
    cv::gpu::setDevice(devInfo.deviceID());

    cv::Size size = GET_PARAM(1);
    int type = GET_PARAM(2);

    cv::Mat src_host(size, type);

    declare.in(src_host, WARMUP_RNG);

    cv::Mat ker = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

    cv::gpu::GpuMat src(src_host);
    cv::gpu::GpuMat dst;
    cv::gpu::GpuMat buf;

    TEST_CYCLE()
    {
        cv::gpu::dilate(src, dst, ker, buf);
    }
}

INSTANTIATE_TEST_CASE_P(Filter, Dilate, testing::Combine(
    ALL_DEVICES,
    GPU_TYPICAL_MAT_SIZES,
    testing::Values(MatType(CV_8UC1), MatType(CV_8UC4))));

//////////////////////////////////////////////////////////////////////
// MorphologyEx

CV_ENUM(MorphOp, cv::MORPH_OPEN, cv::MORPH_CLOSE, cv::MORPH_GRADIENT, cv::MORPH_TOPHAT, cv::MORPH_BLACKHAT)
#define ALL_MORPH_OPS testing::Values(MorphOp(cv::MORPH_OPEN), MorphOp(cv::MORPH_CLOSE), MorphOp(cv::MORPH_GRADIENT), MorphOp(cv::MORPH_TOPHAT), MorphOp(cv::MORPH_BLACKHAT))

GPU_PERF_TEST(MorphologyEx, cv::gpu::DeviceInfo, cv::Size, MatType, MorphOp)
{
    cv::gpu::DeviceInfo devInfo = GET_PARAM(0);
    cv::gpu::setDevice(devInfo.deviceID());

    cv::Size size = GET_PARAM(1);
    int type = GET_PARAM(2);
    int morphOp = GET_PARAM(3);

    cv::Mat src_host(size, type);

    declare.in(src_host, WARMUP_RNG);

    cv::Mat ker = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

    cv::gpu::GpuMat src(src_host);
    cv::gpu::GpuMat dst;
    cv::gpu::GpuMat buf1;
    cv::gpu::GpuMat buf2;

    TEST_CYCLE()
    {
        cv::gpu::morphologyEx(src, dst, morphOp, ker, buf1, buf2);
    }
}

INSTANTIATE_TEST_CASE_P(Filter, MorphologyEx, testing::Combine(
    ALL_DEVICES,
    GPU_TYPICAL_MAT_SIZES,
    testing::Values(MatType(CV_8UC1), MatType(CV_8UC4)),
    ALL_MORPH_OPS));

//////////////////////////////////////////////////////////////////////
// Filter2D

GPU_PERF_TEST(Filter2D, cv::gpu::DeviceInfo, cv::Size, MatType, KernelSize)
{
    cv::gpu::DeviceInfo devInfo = GET_PARAM(0);
    cv::gpu::setDevice(devInfo.deviceID());

    cv::Size size = GET_PARAM(1);
    int type = GET_PARAM(2);
    int ksize = GET_PARAM(3);

    cv::Mat src_host(size, type);
    cv::Mat kernel(ksize, ksize, CV_32FC1);

    declare.in(src_host, kernel, WARMUP_RNG);

    cv::gpu::GpuMat src(src_host);
    cv::gpu::GpuMat dst;

    TEST_CYCLE()
    {
        cv::gpu::filter2D(src, dst, -1, kernel);
    }
}

INSTANTIATE_TEST_CASE_P(Filter, Filter2D, testing::Combine(
    ALL_DEVICES,
    GPU_TYPICAL_MAT_SIZES,
    testing::Values(MatType(CV_8UC1), MatType(CV_8UC4), MatType(CV_32FC1), MatType(CV_32FC4)),
    testing::Values(KernelSize(3), KernelSize(5), KernelSize(7), KernelSize(9), KernelSize(11), KernelSize(13), KernelSize(15))));

#endif
