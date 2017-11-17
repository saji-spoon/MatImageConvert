#include"ImageMatConvert.hpp"

cv::Mat cvsiv::ImageToMat(s3d::Image& image)
{
        cv::Mat_<cv::Vec4b> mat(image.height(), image.width(), static_cast<cv::Vec4b*>(static_cast<void*>(image.data())), image.stride());

        return mat;
}

s3d::Image cvsiv::MatToImage(const cv::Mat& mat)
{
        s3d::Image image(mat.cols, mat.rows);

        cv::Mat dst = ImageToMat(image);

        mat.copyTo(dst);

        return image;
}

s3d::Image cvsiv::MatToImageForce(const cv::Mat& mat, bool isBGR)
{
        if (mat.data == nullptr)
        {
                return s3d::Image();
        }

        if (mat.dims != 2)
        {
                LOG_ERROR(L"MatToImage: cv::Mat dimension must be 2.");
                return s3d::Image();

        }

        cv::Mat copy = mat.clone();

        copy.convertTo(copy, CV_8U);

        switch (copy.channels())
        {
        case 1:
                cv::cvtColor(copy, copy, cv::COLOR_GRAY2RGBA);
                break;
        case 3:
                cv::cvtColor(copy, copy, isBGR ? cv::COLOR_BGR2RGBA : cv::COLOR_RGB2RGBA);
                break;
        case 4:
                if (isBGR) cv::cvtColor(copy, copy, cv::COLOR_BGRA2RGBA);
                break;
        default:
                LOG_ERROR(L"MatToImage: cv::Mat channel must be 1, 3 or 4.");
                return s3d::Image();
                break;
        }

        return MatToImage(copy);
}