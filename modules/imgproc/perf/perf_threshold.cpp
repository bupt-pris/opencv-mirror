#include "perf_precomp.hpp"

using namespace std;
using namespace cv;
using namespace perf;

CV_ENUM(ThreshType, THRESH_BINARY, THRESH_BINARY_INV, THRESH_TRUNC, THRESH_TOZERO, THRESH_TOZERO_INV)

typedef std::tr1::tuple<Size, MatType, ThreshType> Size_MatType_ThreshType_t;
typedef perf::TestBaseWithParam<Size_MatType_ThreshType_t> Size_MatType_ThreshType;

PERF_TEST_P(Size_MatType_ThreshType, threshold,
            testing::Combine(
                testing::Values(TYPICAL_MAT_SIZES),
                testing::Values(CV_8UC1, CV_16SC1),
                testing::ValuesIn(ThreshType::all())
            )
          )
{

    Size sz = std::tr1::get<0>(GetParam());
    int type = std::tr1::get<1>(GetParam());
    ThreshType threshType = std::tr1::get<2>(GetParam());

    Mat src(sz, type);
    Mat dst(sz, type);

    double thresh = cv::theRNG().uniform(1, 254);
    double maxval = cv::theRNG().uniform(1, 254);

    declare.in(src, WARMUP_RNG).out(dst);

    TEST_CYCLE(100)
    {
        cv::threshold(src, dst, thresh, maxval, threshType);
    }

    SANITY_CHECK(dst);
}


typedef perf::TestBaseWithParam<Size> Size_Only;

PERF_TEST_P(Size_Only, threshold_otsu, testing::Values(TYPICAL_MAT_SIZES) )
{
    Size sz = GetParam();

    Mat src(sz, CV_8UC1);
    Mat dst(sz, CV_8UC1);

    double maxval = cv::theRNG().uniform(1, 254);

    declare.in(src, WARMUP_RNG).out(dst);

    TEST_CYCLE(100)
    {
        cv::threshold(src, dst, 0, maxval, THRESH_BINARY|THRESH_OTSU);
    }

    SANITY_CHECK(dst);
}

