#include <opencv2/opencv.hpp>
#include "../include/image_processing.h"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <image_path>" << std::endl;
        return 1;
    }

    cv::Mat image = cv::imread(argv[1]);
    if (image.empty())
    {
        std::cerr << "Failed to load image" << std::endl;
        return 1;
    }
    cv::Mat horizon = detectHorizon(image);
    cv::imshow("image", horizon);
    cv::waitKey(0);

    return 0;
}