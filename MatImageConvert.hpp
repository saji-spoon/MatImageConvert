#pragma once
#include<opencv2/opencv.hpp>
#include<Siv3D.hpp>


namespace cvsiv
{
        /// <summary>
        /// s3d::Image内のデータを参照するcv::Matを作成します。
        /// </summary>
        /// <param name="image">参照するs3d::Image</param>
        /// <returns>cv::Mat</returns>
        cv::Mat GetMatLinkedToImage(s3d::Image& image);

        /// <summary>
        /// s3d::Image内のデータをコピーしたcv::Matを作成します。
        /// </summary>
        /// <param name="image">コピーするs3d::Image</param>
        /// <returns>cv::Mat</returns>
        cv::Mat ImageToMat(s3d::Image& image);

        /// <summary>
        /// 引数のcv::MatがMatToImageForceを適用できるかどうか返します。
        /// </summary>
        /// <param name="image">検査するcv::Mat</param>
        /// <returns>適用可能ならtrue, 不可ならfalse</returns>
        bool IsPossibleMatToImageForce(const cv::Mat& mat);

        /// <summary>
        /// 引数のcv::MatがMatToImageを適用できるかどうか返します。
        /// </summary>
        /// <param name="image">検査するcv::Mat</param>
        /// <returns>適用可能ならtrue, 不可ならfalse</returns>
        bool IsPossibleMatToImage(const cv::Mat& mat);

        /// <summary>
        /// <para>下記の条件を満たすcv::Matからs3d::Imageを新しく作成します。</para>
        /// <para>・ビット深度8</para>
        /// <para>・チャンネル数4でRGBA</para>
        /// </summary>
        /// <param name="mat">作成元のcv::Mat</param>
        /// <returns>s3d::Image</returns>
        s3d::Image MatToImage(const cv::Mat& mat);

        /// <summary>
        /// cv::Matからs3d::Imageを新しく作成します。（チャンネル数やビット深度の違いを吸収）
        /// </summary>
        /// <param name="mat">作成元のcv::Mat</param>
        /// <param name="isBGR">画素並び(BGR→true, RGB→false) グレイスケールの場合は無視します</param>
        /// <returns>s3d::Image</returns>
        s3d::Image MatToImageForce(const cv::Mat& mat, bool isBGR);


}