#include "perf_precomp.hpp"

using namespace std;
using namespace cv;
using namespace perf;

typedef std::tr1::tuple<Size, MatType, MatDepth> Size_MatType_OutMatDepth_t;
typedef perf::TestBaseWithParam<Size_MatType_OutMatDepth_t> Size_MatType_OutMatDepth;

/*
// void integral(InputArray image, OutputArray sum, int sdepth=-1 )
*/
PERF_TEST_P( Size_MatType_OutMatDepth, integral1, 
    testing::Combine(
        testing::Values( TYPICAL_MAT_SIZES ), 
        testing::Values( CV_8UC1, CV_8UC4 ),
        testing::Values( CV_32S, CV_32F, CV_64F )
    )
    )
{
    Size sz = std::tr1::get<0>(GetParam());
    int matType = std::tr1::get<1>(GetParam());
    int sdepth = std::tr1::get<2>(GetParam());

    Mat src(sz, matType);
    Mat sum(sz, sdepth);

    declare.in(src, WARMUP_RNG);
    
    TEST_CYCLE(100) { integral(src, sum, sdepth);  }
    
    SANITY_CHECK(sum);
}



/*
// void integral(InputArray image, OutputArray sum, OutputArray sqsum, int sdepth=-1 )
*/


/*
// void integral(InputArray image, OutputArray sum, OutputArray sqsum, OutputArray tilted, int sdepth=-1 )
*/