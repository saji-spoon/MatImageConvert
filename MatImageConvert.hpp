#pragma once
#define NO_S3D_USING
#include<opencv2/opencv.hpp>
#include<Siv3D.hpp>

namespace cvsiv
{
        /// <summary>
        /// s3d::Image内のデータを参照するcv::Matを作成します。
        /// </summary>
        /// <param name="image">参照するs3d::Image</param>
        /// <returns>cv::Mat</returns>
        cv::Mat ImageToMat(s3d::Image& image);

        /// <summary>
        /// <para>下記の条件を満たすcv::Matからs3d::Imageを新しく作成します。</para>
        /// <para>・次元数2</para>
        /// <para>・ビット深度8</para>
        /// <para>・チャンネル数4でRGBA</para>
        /// <para>・連続データである</para>
        /// </summary>
        /// <param name="mat">作成元のcv::Mat</param>
        /// <returns>s3d::Image</returns>
        s3d::Image MatToImage(const cv::Mat& mat);

        /// <summary>
        /// cv::Matからs3d::Imageを新しく作成します。
        /// </summary>
        /// <param name="mat">作成元のcv::Mat</param>
        /// <param name="isBGR">画素並び(BGR→true, RGB→false) グレイスケールの場合は無視します</param>
        /// <returns>s3d::Image</returns>
        s3d::Image MatToImageForce(const cv::Mat& mat, bool isBGR);
}