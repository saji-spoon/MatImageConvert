# MatImageConvert
cv::Mat←→s3d::Image Converter

# Requirement (Other environments aren't tested)
Visual Studio Community 2017 15.4.3  
OpenSiv3D v0.1.7  
OpenCV 3.3.1

# Example

## Precondition

- Use OpenSiv3D project
- Setup OpenCV in the project (Add include directory, lib directory...)
- Submodule or download this repository and add MatImageConvert.hpp/cpp to the project 

## Code
```cpp
#include <Siv3D.hpp> // OpenSiv3D v0.1.7
#include <opencv2/opencv.hpp>
#include "../MatImageConvert/MatImageConvert.hpp"

void Main()
{
        cv::Mat mat = cv::imread("example/windmill.png", cv::IMREAD_UNCHANGED);

        s3d::Image image = cvsiv::MatToImageForce(mat, true);

        s3d::Texture texture(image);

        while (System::Update())
        {
                texture.draw();
        }
}
```

## Result

