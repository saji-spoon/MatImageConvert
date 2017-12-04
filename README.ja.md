＃MatImageConvert
cv::Mat←→s3d::Image 変換関数

＃要件（他の環境は未テスト）
Siv3D August v2
OpenCV ** 3.0.0 **
 （OpenCVのヘッダ（.hpp）のみ利用します。
  OpenCVの他のバージョンは利用できません）

＃サンプル

## 前提条件

 -  Siv3Dプロジェクト
 -  OpenCV 3.0.0のインクルードディレクトリをプロジェクト設定の「追加のインクルードディレクトリ」に追加する
 - このリポジトリをダウンロードするかgit submodule addして、MatImageConvert.hpp / cppをプロジェクトに追加

## ソースコード
```cpp
#define NO_S3D_USING
#include<opencv2/opencv.hpp>
#include <Siv3D.hpp>
#include "../MatImageConvert/MatImageConvert.hpp"

void Main()
{
        s3d::Window::Resize(800,600);

        s3d::Image image(L"Example/Windmill.png");

        //s3d::Imageのピクセルデータを参照するcv::Matを取得する
        cv::Mat mat = cvsiv::GetMatLinkedToImage(image);        

        cv::Rect roiRect(0, 0, 200, 200);

        //もともとのcv::Matから新しいcv::Matを作成した場合...
        cv::Mat roiMat = mat(roiRect);

        //明示的にs3d::Imageに変換する必要がある
        s3d::Image cutImage = cvsiv::MatToImage(roiMat);

        //そうでなく、元のcv::Matを加工するなどの場合は、変更はs3d::Imageに反映される（同じピクセルデータを参照しているため）
        cv::blur(mat, mat, cv::Size(5, 5));
        
        //image ... Blurがかかった画像 (matを通して加工された) 
        s3d::Texture tex1(image);

        //cutImage ... 切り出された画像 (matのROIであるroiMatをcvsiv::MatToImageでs3d::Imageへ変換した)
        s3d::Texture tex2(cutImage);

        while (s3d::System::Update())
	{
                tex1.draw();
                tex2.draw(500,0);
	}
}
```

## 結果
！[画像]（https://github.com/saji-spoon/MatImageConvert/blob/img/windmill.png）
