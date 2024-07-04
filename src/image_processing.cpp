#include "../include/image_processing.h"
#include <vector>

cv::Mat convertToGray(const cv::Mat &image)
{
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
    return grayImage;
}

cv::Mat applyMedianFilter(const cv::Mat& grayImage, int size)
{
    cv::Mat filteredImage;
    cv::medianBlur(grayImage, filteredImage, size);
    return filteredImage;
}

cv::Mat detectEdges(const cv::Mat& filteredImage)
{
    cv::Mat edges;
    cv::Canny(filteredImage, edges, 100, 200, 3, true);
    return edges;
}

std::vector<cv::Vec4i> findHorizontalLines(const cv::Mat& edges)
{
    std::vector<cv::Vec4i> lines;
    cv::HoughLinesP(edges, lines, 1, CV_PI/180, 80, 50, 10);
    return lines;
}

cv::Mat drawHorizonLine(const cv::Mat& image, const std::vector<cv::Vec4i>& lines)
{
    cv::Mat result = image.clone();
    for (const auto& line : lines)
    {
        int x1 = line[0], y1 = line[1], x2 = line[2], y2 = line[3];
        float angle = std::atan2(y2 - y1, x2 - x1) * 180.0 / CV_PI;
        if (std::abs(angle) < 10) 
        {
            
            cv::line(result, cv::Point(0, y1), cv::Point(result.cols - 1, y1), cv::Scalar(0, 0, 255), 2);
        }
    }
    return result;
}

cv::Mat detectHorizon(const cv::Mat& image)
{
    cv::Mat grayImage = convertToGray(image);
    int kernelSize = 5; 

    cv::Mat filteredImage = applyMedianFilter(grayImage, kernelSize);
    cv::Mat edges = detectEdges(filteredImage);
    std::vector<cv::Vec4i> lines = findHorizontalLines(edges);
    return drawHorizonLine(image, lines);
}