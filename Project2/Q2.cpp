#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include <cmath>

int main(int argc, char* argv[]) 
{
	std::string image = "PA-2-Images/P-2/LiDAR01.png";
	cv::Mat image;
	std::vector<cv::Vec3f> BadCircles;
	std::vector<cv::Vec3f> GoodCircles;
	image = cv::imread(image, cv::IMREAD_GRAYSCALE);
	for (auto IndexRow = 3; IndexRow < 50; IndexRow += 2) {
		cv::HoughCircles(image, BadCircles, cv::HOUGH_GRADIENT, .8, 2 * IndexRow, 97.0, 11.1 * IndexRow / sqrt(pow(IndexRow,2) - 1), IndexRow, IndexRow + 3);
		for (const cv::Vec3f& PossibleCircle : BadCircles) {
            cv::Point CircleCenter(PossibleCircle[0], PossibleCircle[1]);
			auto CircleRadius = PossibleCircle[2];
			bool Incompatible = false;
			for (const cv::Vec3f& VectorOfCircles : GoodCircles) {
				cv::Point center(VectorOfCircles[0], VectorOfCircles[1]);
				auto radius = VectorOfCircles[2];
				if (cv::norm(CircleCenter - center) < (CircleRadius + radius)) {
					Incompatible = true;
					break;
				}
			}
			if (Incompatible == false) { 
				GoodCircles.push_back(PossibleCircle); 
			}
		}
		BadCircles.clear();
	}
	cv::cvtColor(image, image, cv::COLOR_GRAY2BGR);
	for (auto i = 0; i < GoodCircles.size(); i++) {
		cv::Point center(GoodCircles[i][0], GoodCircles[i][1]);
		auto radius = GoodCircles[i][2];
		cv::circle(image, center, radius, cv::Scalar(0, 255, 255), 3);
	}
	cv::imwrite(image.substr(0, image.find_last_of('.')) + "_Resultant" + image.substr(image.find_last_of('.')), image);
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}
