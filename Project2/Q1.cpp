#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include <cmath>

cv::Mat ToonShadingAlg(const cv::Mat &image, int Levels) {
    cv::Mat result(image.rows, image.cols, CV_8UC3); 
    const float level_size = 255.f / Levels;
    const uchar *img_data = image.datastart;
    uchar *ToonShadingValues = result.data;
    while (img_data != image.dataend)
        *ToonShadingValues++ = uchar((int)(*img_data++ / level_size) * level_size); 
    return result;
}
cv::Mat ColorCompressionAlg(const cv::Mat &image, int Levels) {
    cv::Mat result; 
    const float level_size = 255.f / Levels;
    cv::cvtColor(image, result, cv::COLOR_BGR2HSV); 
    for (auto row = 0; row < result.rows; row++)
        for (auto col = 0; col < result.cols; col++)
            result.at<cv::Vec3b>(row, col)[1] = uchar(result.at<cv::Vec3b>(row, col)[1] / level_size) * level_size;
    cv::cvtColor(result, result, cv::COLOR_HSV2BGR); 
    return result;
}
cv::Mat ResultantImage(const std::vector<cv::Mat> &ImageVector, 
                            int ROW, int COL, const cv::Size &ImageSize) {
    cv::Mat All_Images = cv::Mat::zeros(ImageSize.height, ImageSize.width, CV_8UC3);
    const int WIDTH = ImageSize.width / COL, HEIGHT = ImageSize.height / ROW; 
    int FinalWidth = 0, FinalHeight = 0; 
    cv::Mat img_resized;
    for (const cv::Mat &image : ImageVector) {
        auto NewWidth = image.cols * (float(HEIGHT) / image.rows);
        auto NewHeight = image.rows * (float(WIDTH) / image.cols);
        if (NewWidth <= WIDTH) 
            cv::resize(image, img_resized, cv::Size(NewWidth, HEIGHT));
        else 
            cv::resize(image, img_resized, cv::Size(WIDTH, NewHeight));
        for (auto IndexRow = 0; IndexRow < img_resized.rows; IndexRow++)
            for (auto IndexCol = 0; IndexCol < img_resized.cols; IndexCol++)
                All_Images.at<cv::Vec3b>(IndexRow + FinalHeight, IndexCol + FinalWidth) = ((image.type() == CV_8UC3) 
                                                        ? img_resized.at<cv::Vec3b>(IndexRow, IndexCol) : 
                                                        cv::Vec3b(img_resized.at<uint8_t>(IndexRow, IndexCol), 
                                                        img_resized.at<uint8_t>(IndexRow, IndexCol), img_resized.at<uint8_t>(IndexRow, IndexCol)));
        FinalWidth += WIDTH;
        if (FinalWidth >= ImageSize.width - WIDTH + 1) { 
            FinalWidth = 0;
            FinalHeight += HEIGHT;
        }
    }
    return All_Images;
}
int main(int argc, char *argv[]) {
    std::vector<cv::Mat> ImageVector;
    const std::vector<std::string> Images = {      "PA-2-Images/P-1/ElCapitan.jpg" , 
                                                   "PA-2-Images/P-1/Lilly.jpg"     , 
                                                   "PA-2-Images/P-1/Orchids.jpg"   , 
                                                   "PA-2-Images/P-1/OrchidsY.jpg"  , 
                                                   "PA-2-Images/P-1/Parrot.jpg"    };
    const std::vector<int> Levels = {2, 4, 8, 16};
    for (auto file_name : Images) {
        ImageVector.push_back(cv::imread(file_name));
    }
    for (int i = 0; i < Images.size(); ++i) {
        std::vector<cv::Mat> ToonShading = {ImageVector[i].clone()}; 
        std::vector<cv::Mat> color_compressed = {ImageVector[i].clone()};
        for (auto compression_level : Levels)
            ToonShading.push_back(ToonShadingAlg(ImageVector[i], compression_level));
        for (auto compression_level : Levels)
            color_compressed.push_back(ColorCompressionAlg(ImageVector[i], compression_level));
        std::string result_file_name = Images[i].substr(0, Images[i].find_first_of('.'));
        result_file_name += "_results.jpg";
        std::vector<cv::Mat> temp_disp = ToonShading;
        for (const cv::Mat &m : color_compressed)
            temp_disp.push_back(m.clone());
        cv::Mat result = ResultantImage(temp_disp, 2, ToonShading.size(), 
                                              cv::Size(ImageVector[i].cols * 
                                              (1 + ToonShading.size()), 2 * ImageVector[i].rows));

        cv::imwrite(result_file_name, result);

    }
    cv::waitKey(0); 
    cv::destroyAllWindows();
    return 0;
}
