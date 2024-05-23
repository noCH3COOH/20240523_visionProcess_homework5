// ==================== includes ====================

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

// ==================== defines ====================

#define kernel_mean_blur 1.0/9, 1.0/9, 1.0/9, \
                        1.0/9, 1.0/9, 1.0/9, \
                        1.0/9, 1.0/9, 1.0/9

#define kernel_gaussian_blur 1.0/16, 2.0/16, 1.0/16, \
                             2.0/16, 4.0/16, 2.0/16, \
                             1.0/16, 2.0/16, 1.0/16

#define kernel_sharpen -1, -1, -1, \
                       -1,  9, -1, \
                       -1, -1, -1

#define kernel_sobel_x -1,  0,  1, \
                        -2,  0,  2, \
                        -1,  0,  1

#define kernel_sobel_y -1, -2, -1, \
                        0,  0,  0, \
                        1,  2,  1

#define kernel_sobel_leftup 2, 1, 0, \
                            1, 0, -1, \
                            0, -1, -2

#define kernel_sobel_rightup 0, 1, 2, \
                            -1, 0, 1, \
                            -2, -1, 0

#define kernel_laplacian  0, -1,  0, \
                          -1,  4, -1, \
                          0, -1,  0

#define kernel_laplacian_8conn 1, 1, 1, \
                               1, -8, 1, \
                               1, 1, 1
               
#define kernel_emboss -2, -1,  0, \
                       -1,  1,  1, \
                        0,  1,  2

#define kernel_emboss_alternative -1, -1,  0, \
                                    -1,  0,  1, \
                                    0,  1,  1

#define kernel_prewitt_x -1,  0,  1, \
                          -1,  0,  1, \
                          -1,  0,  1

#define kernel_prewitt_y -1, -1, -1, \
                           0,  0,  0, \
                           1,  1,  1

#define kernel_prewitt_leftup 1, 1, 0, \
                                1, 0, -1, \
                                0, -1, -1

#define kernel_prewitt_rightup 0, 1, 1, \
                                -1, 0, 1, \
                                -1, -1, 0

#define kernel_high_pass -1, -1, -1, \
                          -1,  8, -1, \
                          -1, -1, -1

#define kernel_scharr_x  -3,  0,  3, \
                          -10, 0, 10, \
                          -3,  0,  3

#define kernel_scharr_y  -3, -10, -3, \
                           0,  0,  0, \
                           3, 10,  3

#define kernel_LOG 0, 0, 1, 0, 0, \
                   0, 1, 2, 1, 0, \
                   1, 2, -16, 2, 1, \
                   0, 1, 2, 1, 0, \
                   0, 0, 1, 0, 0

// ==================== functions ====================

void convolve(const cv::Mat& input, cv::Mat& output, const cv::Mat& kernel);

// ==================== main ====================

int main() {
    cv::Mat input = imread("test.png", cv::IMREAD_GRAYSCALE);
    if (input.empty()) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    } else {
        cv::imwrite("input.png", input);
    }

    cv::Mat output;
    
    convolve(input, output, (cv::Mat_<float>(3, 3) << kernel_mean_blur));
    cv::imwrite("output_mean_blur.png", output);
    convolve(input, output, (cv::Mat_<float>(3, 3) << kernel_gaussian_blur));
    cv::imwrite("output_gaussian_blur.png", output);
    convolve(input, output, (cv::Mat_<float>(3, 3) << kernel_sharpen));
    cv::imwrite("output_sharpen.png", output);
    convolve(input, output, (cv::Mat_<float>(3, 3) << kernel_sobel_x));
    cv::imwrite("output_sobel_x.png", output);
    convolve(input, output, (cv::Mat_<float>(3, 3) << kernel_sobel_y));
    cv::imwrite("output_sobel_y.png", output);
    convolve(input, output, (cv::Mat_<float>(3, 3) << kernel_sobel_leftup));
    cv::imwrite("output_sobel_leftup.png", output);
    convolve(input, output, (cv::Mat_<float>(3, 3) << kernel_sobel_rightup));
    cv::imwrite("output_sobel_rightup.png", output);
    convolve(input, output, (cv::Mat_<float>(3, 3) << kernel_laplacian));
    cv::imwrite("output_laplacian.png", output);
    convolve(input, output, (cv::Mat_<float>(3, 3) << kernel_laplacian_8conn));
    cv::imwrite("output_laplacian_8conn.png", output);
    convolve(input, output, (cv::Mat_<float>(3, 3) << kernel_emboss));
    cv::imwrite("output_emboss.png", output);
    convolve(input, output, (cv::Mat_<float>(3, 3) << kernel_emboss_alternative));
    cv::imwrite("output_emboss_alternative.png", output);
    convolve(input, output, (cv::Mat_<float>(3, 3) << kernel_prewitt_x));
    cv::imwrite("output_prewitt_x.png", output);
    convolve(input, output, (cv::Mat_<float>(3, 3) << kernel_prewitt_y));
    cv::imwrite("output_prewitt_y.png", output);
    convolve(input, output, (cv::Mat_<float>(3, 3) << kernel_prewitt_leftup));
    cv::imwrite("output_prewitt_leftup.png", output);
    convolve(input, output, (cv::Mat_<float>(3, 3) << kernel_prewitt_rightup));
    cv::imwrite("output_prewitt_rightup.png", output);
    convolve(input, output, (cv::Mat_<float>(3, 3) << kernel_high_pass));
    cv::imwrite("output_high_pass.png", output);
    convolve(input, output, (cv::Mat_<float>(3, 3) << kernel_scharr_x));
    cv::imwrite("output_scharr_x.png", output);
    convolve(input, output, (cv::Mat_<float>(3, 3) << kernel_scharr_y));
    cv::imwrite("output_scharr_y.png", output);
    convolve(input, output, (cv::Mat_<float>(5, 5) << kernel_LOG));
    cv::imwrite("output_LOG.png", output);

    return 0;
}

// ==================== function implements ====================

void convolve(const cv::Mat& input, cv::Mat& output, const cv::Mat& kernel) {
    output.create(input.size(), input.type());

    int kernelRadiusX = kernel.size().width / 2;
    int kernelRadiusY = kernel.size().height / 2;

    for (int x = 0; x < input.rows; x++) {
        for (int y = 0; y < input.cols; y++) {
            float sum = 0.0;
            for (int m = -kernelRadiusX; m <= kernelRadiusX; m++) {
                for (int n = -kernelRadiusY; n <= kernelRadiusY; n++) {
                    int i = x+m, j = y+n;
                    if (i >= 0 && i < input.rows && j >= 0 && j < input.cols) {
                        sum += input.at<uchar>(i, j) * kernel.at<float>(m + kernelRadiusX, n + kernelRadiusY);
                    }
                }
            }
            output.at<uchar>(x, y) = cv::saturate_cast<uchar>(sum);
        }
    }
}
