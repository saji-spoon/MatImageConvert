#include"MatImageConvert.hpp"

cv::Mat cvsiv::GetMatLinkedToImage(s3d::Image& image)
{
        cv::Mat_<cv::Vec4b> mat(image.height, image.width, static_cast<cv::Vec4b*>(image.data()), image.stride);
        
        return mat;
}

cv::Mat cvsiv::ImageToMat(s3d::Image& image)
{
        //引数のimageを参照するcv::Matを作成
        cv::Mat linkedMat = GetMatLinkedToImage(image);

        //データをコピー
        cv::Mat mat = linkedMat.clone();

        return mat;
}

bool cvsiv::IsPossibleMatToImageForce(const cv::Mat& mat)
{
        if (mat.data == nullptr)
        {
                LOG_ERROR(L"IsPossibleMatToImageForce: cv::Mat is empty.");
                return false;
        }

        if (mat.dims != 2)
        {
                LOG_ERROR(L"IsPossibleMatToImageForce: cv::Mat dimension must be 2.");
                return false;
        }

        switch (mat.channels())
        {
        case 1: case 3: case 4:
                break;
        default:
                LOG_ERROR(L"IsPossibleMatToImageForce: cv::Mat channel must be 1, 3 or 4.");
                return false;
                break;
        }

        return true;
}

bool cvsiv::IsPossibleMatToImage(const cv::Mat& mat)
{
        if (!IsPossibleMatToImageForce(mat)) return false;

        if (mat.channels() != 4)
        {
                LOG_ERROR(L"IsPossibleMatToImage: cv::Mat channel must be 4.");
                return false;
        }

        if (mat.depth() != CV_8U)
        {
                LOG_ERROR(L"IsPossibleMatToImage: cv::Mat depth must be CV_8U");
                return false;
        }

        return true;
}


s3d::Image cvsiv::MatToImage(const cv::Mat& mat)
{
        s3d::Image image(mat.cols, mat.rows);

        cv::Mat dst = ImageToMat(image);

        mat.copyTo(dst);

        return image;
}

s3d::Image cvsiv::MatToImageForce(const cv::Mat& mat, bool isRGB)
{
        if (!IsPossibleMatToImageForce(mat)) return s3d::Image();        

        cv::Mat copy = mat.clone();

        copy.convertTo(copy, CV_8U);

        switch (copy.channels())
        {
        case 1:
                cv::cvtColor(copy, copy, cv::COLOR_GRAY2RGBA);
                break;
        case 3:
                cv::cvtColor(copy, copy, isRGB ? cv::COLOR_RGB2RGBA : cv::COLOR_BGR2RGBA);
                break;
        case 4:
                if (!isRGB) cv::cvtColor(copy, copy, cv::COLOR_BGRA2RGBA);
                break;
        }

        return MatToImage(copy);
}