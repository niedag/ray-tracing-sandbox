#include "color.h"
#include "ray.h"
#include "vec3.h"

#include <iostream>

color ray_color(const ray& r) { // Returns color of Z
    return color(0,0,0);
}

int main() {

    // Image
    
    auto aspect_ratio = 16.0 / 9.0;  // Width / Height
    int image_width = 400;
    
    // Calculate image height based on ratio
    int image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 0) ? 1 : image_height; // (condition) ? expression_if_true : expression_if_false ==== Ensure the value of height is always greater than 1
    
    // Viewport/Camera
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = 2 * viewport_height * (static_cast<double>(image_width)/image_height); // It is okay if the viewport width is < 1 ;
    auto camera_center = point3(0,0,0);



    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255 \n";

    for(int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
            write_color(std::cout, pixel_color);
            // Replaced 
            // auto r = double(i) / (image_width -1);
            // auto g = double(j) / (image_height -1);
            // auto b = 0;

            // int ir = static_cast<int>(255.999 * r);
            // int ig = static_cast<int>(255.999 * g);
            // int ib = static_cast<int>(255.999 * b);

            // std::cout << ir << ' ' << ig << ' ' << ib << '\n'; 
        }
    }
    std::clog << "\rDone.                 \n";

}

