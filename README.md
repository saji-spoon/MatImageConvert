# MatImageConvert
cv::Mat←→s3d::Image Converter

# Requirement (Other environments aren't tested)
Siv3D August v2  
OpenCV **3.0.0**   
 (Only OpenCV header(.hpp) is required because Siv3D uses its own OpenCV lib.  
  Instead, other version is not available)

# Example

## Precondition

- Use Siv3D project
- Add OpenCV 3.0.0 include directory to "Additional include directories" in project settings
- Submodule or download this repository and add MatImageConvert.hpp/cpp to the project 

## Code
```cpp
#define NO_S3D_USING
#include<opencv2/opencv.hpp>
#include <Siv3D.hpp>
#include "../MatImageConvert/MatImageConvert.hpp"

void Main()
{
        s3d::Window::Resize(800,600);

        s3d::Image image(L"Example/Windmill.png");

        //Get cv::Mat that refer s3d::Image's pixel data 
        cv::Mat mat = cvsiv::GetMatLinkedToImage(image);        

        cv::Rect roiRect(0, 0, 200, 200);

        //If you get new cv::Mat from original one...
        cv::Mat roiMat = mat(roiRect);

        //Convert it to s3d::Image explicitly
        s3d::Image cutImage = cvsiv::MatToImage(roiMat);

        //Otherwise, if you apply effect or other to original one, the change is applied to s3d::Image 
        cv::blur(mat, mat, cv::Size(5, 5));
        
        //image ... Blured Image (from mat) 
        s3d::Texture tex1(image);

        //cutImage ... Cut Image (roiMat is generated from mat, and is converted by cvsiv::MatToImage)
        s3d::Texture tex2(cutImage);

        while (s3d::System::Update())
	{
                tex1.draw();
                tex2.draw(500,0);
	}
}
```

## Result
![Image](https://github.com/saji-spoon/MatImageConvert/blob/img/windmill.png)

