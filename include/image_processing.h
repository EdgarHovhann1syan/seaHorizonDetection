#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H
#include <opencv2/opencv.hpp>

cv::Mat convertToGray(const cv::Mat& image);
cv::Mat applyAdaptiveMedianFilter(const cv::Mat& grayImage);
cv::Mat applyMultipleFilters(const cv::Mat& grayImage);
void adjustCannyThresholds(const cv::Mat& filteredImage, int& threshold1, int& threshold2);
cv::Mat detectEdges(const cv::Mat& filteredImage);
std::vector<cv::Vec4i> findHorizontalLines(const cv::Mat& edges);
cv::Mat drawHorizonLine(const cv::Mat& image, const std::vector<cv::Vec4i>& lines);
cv::Mat detectHorizon(const cv::Mat& image);
#endif // IMAGE_PROCESSING_H