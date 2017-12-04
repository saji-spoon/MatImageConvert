#pragma once
#include<opencv2/opencv.hpp>
#include<Siv3D.hpp>


namespace cvsiv
{
        /// <summary>
        /// s3d::Image���̃f�[�^���Q�Ƃ���cv::Mat���쐬���܂��B
        /// </summary>
        /// <param name="image">�Q�Ƃ���s3d::Image</param>
        /// <returns>cv::Mat</returns>
        cv::Mat GetMatLinkedToImage(s3d::Image& image);

        /// <summary>
        /// s3d::Image���̃f�[�^���R�s�[����cv::Mat���쐬���܂��B
        /// </summary>
        /// <param name="image">�R�s�[����s3d::Image</param>
        /// <returns>cv::Mat</returns>
        cv::Mat ImageToMat(s3d::Image& image);

        /// <summary>
        /// ������cv::Mat��MatToImageForce��K�p�ł��邩�ǂ����Ԃ��܂��B
        /// </summary>
        /// <param name="image">��������cv::Mat</param>
        /// <returns>�K�p�\�Ȃ�true, �s�Ȃ�false</returns>
        bool IsPossibleMatToImageForce(const cv::Mat& mat);

        /// <summary>
        /// ������cv::Mat��MatToImage��K�p�ł��邩�ǂ����Ԃ��܂��B
        /// </summary>
        /// <param name="image">��������cv::Mat</param>
        /// <returns>�K�p�\�Ȃ�true, �s�Ȃ�false</returns>
        bool IsPossibleMatToImage(const cv::Mat& mat);

        /// <summary>
        /// <para>���L�̏����𖞂���cv::Mat����s3d::Image��V�����쐬���܂��B</para>
        /// <para>�E�r�b�g�[�x8</para>
        /// <para>�E�`�����l����4��RGBA</para>
        /// </summary>
        /// <param name="mat">�쐬����cv::Mat</param>
        /// <returns>s3d::Image</returns>
        s3d::Image MatToImage(const cv::Mat& mat);

        /// <summary>
        /// cv::Mat����s3d::Image��V�����쐬���܂��B�i�`�����l������r�b�g�[�x�̈Ⴂ���z���j
        /// </summary>
        /// <param name="mat">�쐬����cv::Mat</param>
        /// <param name="isBGR">��f����(BGR��true, RGB��false) �O���C�X�P�[���̏ꍇ�͖������܂�</param>
        /// <returns>s3d::Image</returns>
        s3d::Image MatToImageForce(const cv::Mat& mat, bool isBGR);


}