#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "opencv2/core/core.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/videostab/videostab.hpp"

using namespace std;
using namespace cv;
using namespace cv::videostab;

Ptr<IFrameSource> stabilizedFrames;
double outputFps;
string outputPath;
bool quietMode;

void run();
void printHelp();

void run()
{
    VideoWriter writer;
    Mat stabilizedFrame;

    while (!(stabilizedFrame = stabilizedFrames->nextFrame()).empty())
    {
        if (!outputPath.empty())
        {
            if (!writer.isOpened())
                writer.open(outputPath, CV_FOURCC('X','V','I','D'), outputFps, stabilizedFrame.size());
            writer << stabilizedFrame;
        }
        if (!quietMode)
        {
            imshow("stabilizedFrame", stabilizedFrame);
            char key = static_cast<char>(waitKey(3));
            if (key == 27)
                break;
        }
    }

    cout << "\nfinished\n";
}


void printHelp()
{
    cout << "OpenCV video stabilizer.\n"
            "Usage: videostab <file_path> [arguments]\n\n"
            "Arguments:\n"
            "  -m, --model=(transl|transl_and_scale|affine)\n"
            "      Set motion model. The default is affine.\n"
            "  --outlier-ratio=<float_number>\n"
            "      Outliers ratio in motion estimation. The default is 0.5.\n"
            "  --min-inlier-ratio=<float_number>\n"
            "      Minimum inlier ratio to decide if estimated motion is OK. The default is 0.1,\n"
            "      but you may want to increase it.\n\n"
            "  -r, --radius=<int_number>\n"
            "      Set smoothing radius. The default is 15.\n"
            "  --stdev=<float_number>\n"
            "      Set smoothing weights standard deviation. The default is sqrt(radius).\n\n"
            "  --deblur=(yes|no)\n"
            "      Do deblurring.\n"
            "  --deblur-sens=<float_number>\n"
            "      Set deblurring sensitivity (from 0 to +inf). The default is 0.1.\n\n"
            "  -t, --trim-ratio=<float_number>\n"
            "      Set trimming ratio (from 0 to 0.5). The default is 0.0.\n"
            "  --est-trim=(yes|no)\n"
            "      Estimate trim ratio automatically. The default is yes (that leads to two passes,\n"
            "      you can turn it off if you want to use one pass only).\n"
            "  --incl-constr=(yes|no)\n"
            "      Ensure the inclusion constraint is always satisfied. The default is no.\n\n"
            "  --border-mode=(replicate|reflect|const)\n"
            "      Set border extrapolation mode. The default is replicate.\n\n"
            "  --mosaic=(yes|no)\n"
            "      Do consistent mosaicing. The default is no.\n"
            "  --mosaic-stdev=<float_number>\n"
            "      Consistent mosaicing stdev threshold. The default is 10.0.\n\n"
            "  --motion-inpaint=(yes|no)\n"
            "      Do motion inpainting (requires GPU support). The default is no.\n"
            "  --dist-thresh=<float_number>\n"
            "      Estimated flow distance threshold for motion inpainting. The default is 5.0.\n\n"
            "  --color-inpaint=(no|average|ns|telea)\n"
            "      Do color inpainting. The defailt is no.\n"
            "  --color-inpaint-radius=<float_number>\n"
            "      Set color inpainting radius (for ns and telea options only).\n\n"
            "  -o, --output=(no|<file_path>)\n"
            "      Set output file path explicitely. The default is stabilized.avi.\n"
            "  --fps=<int_number>\n"
            "      Set output video FPS explicitely. By default the source FPS is used.\n"
            "  -q, --quiet\n"
            "      Don't show output video frames.\n\n"
            "  -h, --help\n"
            "      Print help.\n"
            "\n";
}


int main(int argc, const char **argv)
{
    try
    {
        const char *keys =
                "{ 1 | | | | }"
                "{ m | model | | }"
                "{ | min-inlier-ratio | | }"
                "{ | outlier-ratio | | }"
                "{ r | radius | | }"
                "{ | stdev | | }"
                "{ | deblur | | }"
                "{ | deblur-sens | | }"
                "{ | est-trim | | }"
                "{ t | trim-ratio | | }"
                "{ | incl-constr | | }"
                "{ | border-mode | | }"
                "{ | mosaic | | }"
                "{ | mosaic-stdev | | }"
                "{ | motion-inpaint | | }"
                "{ | dist-thresh | | }"
                "{ | color-inpaint | no | }"
                "{ | color-inpaint-radius | | }"
                "{ o | output | stabilized.avi | }"
                "{ | fps | | }"
                "{ q | quiet | false | }"
                "{ h | help | false | }";
        CommandLineParser cmd(argc, argv, keys);

        // parse command arguments

        if (cmd.get<bool>("help"))
        {
            printHelp();
            return 0;
        }               

        StabilizerBase *stabilizer;
        GaussianMotionFilter *motionFilter = 0;

        if (!cmd.get<string>("stdev").empty())
        {
            motionFilter = new GaussianMotionFilter();
            motionFilter->setStdev(cmd.get<float>("stdev"));
        }

        bool isTwoPass = cmd.get<string>("est-trim") == "yes";

        if (isTwoPass)
        {
            TwoPassStabilizer *twoPassStabilizer = new TwoPassStabilizer();
            if (!cmd.get<string>("est-trim").empty())
                twoPassStabilizer->setEstimateTrimRatio(cmd.get<string>("est-trim") == "yes");
            if (motionFilter)
                twoPassStabilizer->setMotionStabilizer(motionFilter);
            stabilizer = twoPassStabilizer;
        }
        else
        {
            OnePassStabilizer *onePassStabilizer= new OnePassStabilizer();
            if (motionFilter)
                onePassStabilizer->setMotionFilter(motionFilter);
            stabilizer = onePassStabilizer;
        }

        string inputPath = cmd.get<string>("1");
        if (inputPath.empty())
            throw runtime_error("specify video file path");

        VideoFileSource *frameSource = new VideoFileSource(inputPath);
        outputFps = frameSource->fps();
        stabilizer->setFrameSource(frameSource);
        cout << "frame count: " << frameSource->frameCount() << endl;

        PyrLkRobustMotionEstimator *motionEstimator = new PyrLkRobustMotionEstimator();
        if (cmd.get<string>("model") == "transl")           
            motionEstimator->setMotionModel(TRANSLATION);
        else if (cmd.get<string>("model") == "transl_and_scale")
            motionEstimator->setMotionModel(TRANSLATION_AND_SCALE);
        else if (cmd.get<string>("model") == "affine")
            motionEstimator->setMotionModel(AFFINE);
        else if (!cmd.get<string>("model").empty())
            throw runtime_error("unknow motion mode: " + cmd.get<string>("model"));        

        if (!cmd.get<string>("outlier-ratio").empty())
        {
            RansacParams ransacParams = motionEstimator->ransacParams();
            ransacParams.eps = cmd.get<float>("outlier-ratio");
            motionEstimator->setRansacParams(ransacParams);
        }

        if (!cmd.get<string>("min-inlier-ratio").empty())
            motionEstimator->setMinInlierRatio(cmd.get<float>("min-inlier-ratio"));

        stabilizer->setMotionEstimator(motionEstimator);

        if (!cmd.get<string>("radius").empty())
            stabilizer->setRadius(cmd.get<int>("radius"));

        if (cmd.get<string>("deblur") == "yes")
        {
            WeightingDeblurer *deblurer = new WeightingDeblurer();
            if (!cmd.get<string>("deblur-sens").empty())
                deblurer->setSensitivity(cmd.get<float>("deblur-sens"));
            stabilizer->setDeblurer(deblurer);
        }

        if (!cmd.get<string>("trim-ratio").empty())
            stabilizer->setTrimRatio(cmd.get<float>("trim-ratio"));

        if (!cmd.get<string>("incl-constr").empty())
            stabilizer->setCorrectionForInclusion(cmd.get<string>("incl-constr") == "yes");

        if (cmd.get<string>("border-mode") == "reflect")
            stabilizer->setBorderMode(BORDER_REFLECT);
        else if (cmd.get<string>("border-mode") == "replicate")
            stabilizer->setBorderMode(BORDER_REPLICATE);
        else if (cmd.get<string>("border-mode") == "const")
            stabilizer->setBorderMode(BORDER_CONSTANT);
        else if (!cmd.get<string>("border-mode").empty())
            throw runtime_error("unknown border extrapolation mode: " + cmd.get<string>("border-mode"));

        InpaintingPipeline *inpainters = new InpaintingPipeline();
        if (cmd.get<string>("mosaic") == "yes")
        {
            ConsistentMosaicInpainter *inpainter = new ConsistentMosaicInpainter();
            if (!cmd.get<string>("mosaic-stdev").empty())
                inpainter->setStdevThresh(cmd.get<float>("mosaic-stdev"));
            inpainters->pushBack(inpainter);
        }
        if (cmd.get<string>("motion-inpaint") == "yes")
        {
            MotionInpainter *inpainter = new MotionInpainter();
            if (!cmd.get<string>("dist-thresh").empty())
                inpainter->setDistThreshold(cmd.get<float>("dist-thresh"));
            inpainters->pushBack(inpainter);
        }
        if (!cmd.get<string>("color-inpaint").empty())
        {
            if (cmd.get<string>("color-inpaint") == "average")
                inpainters->pushBack(new ColorAverageInpainter());
            else if (!cmd.get<string>("color-inpaint-radius").empty())
            {
                float radius = cmd.get<float>("color-inpaint-radius");
                if (cmd.get<string>("color-inpaint") == "ns")
                    inpainters->pushBack(new ColorInpainter(INPAINT_NS, radius));
                else if (cmd.get<string>("color-inpaint") == "telea")
                    inpainters->pushBack(new ColorInpainter(INPAINT_TELEA, radius));
                else if (cmd.get<string>("color-inpaint") != "no")
                    throw runtime_error("unknown color inpainting method: " + cmd.get<string>("color-inpaint"));
            }
            else
            {
                if (cmd.get<string>("color-inpaint") == "ns")
                    inpainters->pushBack(new ColorInpainter(INPAINT_NS));
                else if (cmd.get<string>("color-inpaint") == "telea")
                    inpainters->pushBack(new ColorInpainter(INPAINT_TELEA));
                else if (cmd.get<string>("color-inpaint") != "no")
                    throw runtime_error("unknown color inpainting method: " + cmd.get<string>("color-inpaint"));
            }
        }
        if (!inpainters->empty())
            stabilizer->setInpainter(inpainters);

        stabilizer->setLog(new LogToStdout());

        outputPath = cmd.get<string>("output") != "no" ? cmd.get<string>("output") : "";

        if (!cmd.get<string>("fps").empty())
            outputFps = cmd.get<double>("fps");

        quietMode = cmd.get<bool>("quiet");

        stabilizedFrames = dynamic_cast<IFrameSource*>(stabilizer);

        run();
    }
    catch (const exception &e)
    {
        cout << "error: " << e.what() << endl;
        stabilizedFrames.release();
        return -1;
    }
    stabilizedFrames.release();
    return 0;
}
