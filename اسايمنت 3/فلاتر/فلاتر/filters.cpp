/*void marge() {
    string image1, image2;
    cout << "Please enter name of image 1: ";
    cin >> image1;
    cout << "Please enter name of image 2: ";
    cin >> image2;

    // Load the images
    Image img1(image1);
    Image img2(image2);

    int min_w = min(img1.width, img2.width);
    int min_h = min(img1.height, img2.height);

    // Resize 
    Image resImg1(min_w, min_h);
    Image resImg2(min_w, min_h);

    // Resize image 1
    for (int i = 0; i < min_h; ++i) {
        for (int j = 0; j < min_w; ++j) {
            for (int k = 0; k < 3; ++k) {
                resImg1(j, i, k) = img1(j, i, k);
            }
        }
    }

    // Resize image 2
    for (int i = 0; i < min_h; ++i) {
        for (int j = 0; j < min_w; ++j) {
            for (int k = 0; k < 3; ++k) {
                resImg2(j, i, k) = img2(j, i, k);
            }
        }
    }

    // Merge the images
    Image mergedImage(min_w, min_h);
    for (int i = 0; i < min_h; ++i) {
        for (int j = 0; j < min_w; ++j) {
            for (int k = 0; k < 3; ++k) {
                mergedImage(j, i, k) = (resImg1(j, i, k) + resImg2(j, i, k)) / 2;
            }
        }
    }

    // Save the merged image
    cout << "Please enter the filename to store the merged image, and specify extension (.jpg, .bmp, .png, .tga): ";
    string newname;
    cin >> newname;
    mergedImage.saveImage(newname);
    system(newname.c_str());

    cout << "Merged image has been saved." << endl;

}
.................................................................................
void Black_and_White(){
    string imgname;
    cout << "Pls enter colored image name to turn to gray scale: ";
    cin >> imgname;

    Image image(imgname);

    const int threshold = 128;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0;
            for (int k = 0; k < image.channels; ++k) {
                avg += image(i, j, k);
            }
            avg /= 3;
            unsigned char color = (avg > threshold) ? 255 : 0;
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = color;
            }
        }
    }
    cout << "Please enter the filename to store the merged image, and specify extension (.jpg, .bmp, .png, .tga): ";
    string newname;
    cin >> newname;
    image.saveImage(newname);
    system(newname.c_str());
    cout << "Merged image has been saved." << endl;
}


...................................................................................
void gray() {
    string imgname;
    cout << "Pls enter colored image name to turn to gray scale: ";
    cin >> imgname;

    Image image(imgname);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int gr = 0; 

            for (int k = 0; k < 3; ++k) {
                gr += (unsigned int)image(i, j, k); 
            }
            gr /= 3; 
            image(i, j, 0) = gr;
            image(i, j, 1) = gr;
            image(i, j, 2) = gr;
        }
    }
    cout << "Please enter the filename to store the merged image, and specify extension (.jpg, .bmp, .png, .tga): ";
    string newname;
    cin >> newname;
    image.saveImage(newname);
    system(newname.c_str());
    cout << "Merged image has been saved." << endl;
}


...........................................................................


........................................................




*/
//#include <iostream>
//#include "Image_Class.h"
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//void Detect() {
//    string imgname;
//    cout << "Please enter the filename of the image: ";
//    cin >> imgname;
//
//    Image image(imgname);
//
//    const int threshold = 128;
//    for (int i = 0; i < image.width; ++i) {
//        for (int j = 0; j < image.height; ++j) {
//            unsigned int avg = 0;
//            for (int k = 0; k < image.channels; ++k) {
//                avg += image(i, j, k);
//            }
//            avg /= 3;
//            unsigned char color = (avg > threshold) ? 255 : 0;
//            for (int k = 0; k < 3; ++k) {
//                image(i, j, k) = color;
//            }
//        }
//    }
//
//    Image edges(image.width, image.height);
//    for (int i = 1; i < image.width - 1; ++i) {
//        for (int j = 1; j < image.height - 1; ++j) {
//            int gradientX = 0, gradientY = 0;
//            for (int k = 0; k < 3; ++k) {
//                
//                gradientX += image(i - 1, j - 1, k) - image(i + 1, j - 1, k);
//                gradientX += 2 * (image(i - 1, j, k) - image(i + 1, j, k));
//                gradientX += image(i - 1, j + 1, k) - image(i + 1, j + 1, k);
//
//                gradientY += image(i - 1, j - 1, k) - image(i - 1, j + 1, k);
//                gradientY += 2 * (image(i, j - 1, k) - image(i, j + 1, k));
//                gradientY += image(i + 1, j - 1, k) - image(i + 1, j + 1, k);
//            }
//            int magnitude = sqrt(gradientX * gradientX + gradientY * gradientY);
//            if (magnitude > threshold) {
//                for (int k = 0; k < 3; ++k) {
//                    edges(i, j, k) = 0; 
//                }
//            }
//            else {
//                for (int k = 0; k < 3; ++k) {
//                    edges(i, j, k) = 255; 
//                }
//            }
//        }
//    }
//
//    cout << "Please enter the filename to store the edge-detected image: ";
//    string newname;
//    cin >> newname;
//    edges.saveImage(newname);
//    system(newname.c_str());
//    cout << "Edge-detected image has been saved." << endl;
//}
////............................................................................................................
//void Darken_and_lighten() {
//    string  imgname;
//    cout << "Please enter the filename of the image: ";
//    cin >> imgname;
//
//    Image image(imgname);
//
//    int x = 0;
//    while (x != 1 && x != 2) {
//        cout << "What do you want?\n" << "1) Increase lighting\n" << "2) Decrease lighting\n";
//        cin >> x;
//
//        if (x == 1) {
//            for (int i = 0; i < image.width; ++i) {
//                for (int j = 0; j < image.height; ++j) {
//                    for (int k = 0; k < 3; ++k) {
//                        float increasedValue = image(i, j, k) + image(i, j, k) * 0.5;
//
//                        if (increasedValue > 255) {
//                            increasedValue = 255;
//                        }
//
//                        image(i, j, k) = increasedValue;
//                    }
//                }
//            }
//        }
//        else if (x == 2) {
//            for (int i = 0; i < image.width; ++i) {
//                for (int j = 0; j < image.height; ++j) {
//                    for (int k = 0; k < 3; ++k) {
//                        float decreasedValue = image(i, j, k) * 0.5;
//
//                        if (decreasedValue < 0) {
//                            decreasedValue = 0;
//                        }
//
//                        image(i, j, k) = decreasedValue;
//                    }
//                }
//            }
//        }
//        else {
//            cout << "Invalid choice. Please enter 1 or 2." << endl;
//        }
//    }
//
//    cout << "Please enter the filename to store the adjusted image, and specify extension (.jpg, .bmp, .png, .tga): ";
//    string newname;
//    cin >> newname;
//    image.saveImage(newname);
//    system(newname.c_str());
//    cout << "Adjusted image has been saved." << endl;
//}
////...............................................................................................................................
//void oilPaintingEffect() {
//    string imageName;
//    cout << "Please enter the filename of the image: ";
//    cin >> imageName;
//
//    Image image(imageName);
//
//    Image oilPainting(image.width, image.height);
//
//    int r = 10;
//
//    for (int i = 0; i < image.width; ++i) {
//        for (int j = 0; j < image.height; ++j) {
//            int densityCount[3][256] = { 0 };
//
//            for (int x = max(0, i - r); x <= min(image.width - 1, i + r); ++x) {
//                for (int y = max(0, j - r); y <= min(image.height - 1, j + r); ++y) {
//                    for (int k = 0; k < 3; ++k) {
//                        int density = image(x, y, k);
//                        densityCount[k][density]++;
//                    }
//                }
//            }
//
//            int maxCount[3] = { 0 };
//            for (int k = 0; k < 3; ++k) {
//                for (int density = 0; density < 256; ++density) {
//                    if (densityCount[k][density] > densityCount[k][maxCount[k]]) {
//                        maxCount[k] = density;
//                    }
//                }
//            }
//
//            for (int k = 0; k < 3; ++k) {
//                oilPainting(i, j, k) = maxCount[k] / 2 + image(i, j, k) / 2;
//            }
//        }
//    }
//
//    cout << "Please enter the filename to store the oil painting effect image: ";
//    string newname;
//    cin >> newname;
//    oilPainting.saveImage(newname);
//    system(newname.c_str());
//    cout << "Oil painting effect image has been saved." << endl;
//}
//
//
//void skewed() {
//    string imgname;
//    cout << "Please enter the filename of the image: ";
//    cin >> imgname;
//
//    Image image(imgname);
//
//    double angle = (40 * 3.1416) / 180.0;
//
//    int newWidth = image.width + image.height * tan(angle); 
//    int newHeight = image.height;
//
//    Image skewedImage(newWidth, newHeight);
//
//    for (int i = 0; i < newWidth; ++i) {
//        for (int j = 0; j < newHeight; ++j) {
//            int x = i - j * tan(angle); 
//
//            if (x >= 0 && x < image.width) {
//                for (int k = 0; k < image.channels; ++k) {
//                    skewedImage(i, j, k) = image(x, j, k);
//                }
//            }
//            else {
//                for (int k = 0; k < image.channels; ++k) {
//                    skewedImage(i, j, k) = 0;
//                }
//            }
//        }
//    }
//
//    for (int i = 0; i < newWidth / 2; ++i) {
//        for (int j = 0; j < newHeight; ++j) {
//            for (int k = 0; k < image.channels; ++k) {
//                swap(skewedImage(i, j, k), skewedImage(newWidth - i - 1, j, k));
//            }
//        }
//    }
//
//    cout << "Please enter the filename to store the corrected skewed and flipped image: ";
//    string newname;
//    cin >> newname;
//    skewedImage.saveImage(newname);
//    system(newname.c_str());
//    cout << "Corrected skewed and flipped image has been saved." << endl;
//
// }
//
//void applyOldTVFilter() {
//    string imgname, newname;
//    cout << "Enter the input filename: ";
//    cin >> imgname;
//
//    Image image(imgname);
//    srand(time(nullptr));
//
//    int noiseLevel = rand() % 31;
//    int scanlineIntensity = rand() % 256;
//    int distortionLevel = rand() % 256;
//
//    for (int y = 0; y < image.height; ++y) {
//        for (int x = 0; x < image.width; ++x) {
//            for (int c = 0; c < image.channels; ++c) {
//                int noise = rand() % (noiseLevel + 1);
//                int pixelValue = image(x, y, c);
//                image(x, y, c) = max(0, min(255, pixelValue + noise));
//            }
//        }
//    }
//
//    for (int y = 0; y < image.height; ++y) {
//        if (y % 2 == 0) {
//            for (int x = 0; x < image.width; ++x) {
//                for (int c = 0; c < image.channels; ++c) {
//                    image(x, y, c) = max(0, image(x, y, c) - scanlineIntensity);
//                }
//            }
//        }
//    }
//
//    for (int y = 0; y < image.height; ++y) {
//        for (int x = 0; x < image.width; ++x) {
//            for (int c = 0; c < image.channels; ++c) {
//                int distortion = rand() % (distortionLevel + 1);
//                int pixelValue = image(x, y, c);
//                image(x, y, c) = max(0, min(255, pixelValue + distortion));
//            }
//        }
//    }
//
//    cout << "Enter the output filename: ";
//    cin >> newname;
//
//    image.saveImage(newname);
//    system(newname.c_str());
//    cout << "Filtered image has been saved." << endl;
//}
//
//int main() {
//    applyOldTVFilter();
//    return 0;
//}
//#include <iostream>
//#include "Image_Class.h"
//
//using namespace std;
//
//// Function to apply pencil sketch filter
//void applyPencilSketchFilter(Image& image) {
//    // Loop through each pixel in the image
//    for (int y = 0; y < image.height; ++y) {
//        for (int x = 0; x < image.width; ++x) {
//            // Get pixel values for neighboring pixels
//            unsigned char& pixelR = image(x, y, 0);
//            unsigned char& pixelG = image(x, y, 1);
//            unsigned char& pixelB = image(x, y, 2);
//
//            // Convert to grayscale
//            unsigned char grayscale = (unsigned char)(0.2126 * pixelR + 0.7152 * pixelG + 0.0722 * pixelB);
//
//            // Apply pencil sketch effect
//            unsigned char pencilR = 255 - grayscale;
//            unsigned char pencilG = 255 - grayscale;
//            unsigned char pencilB = 255 - grayscale;
//
//            // Update pixel values
//            pixelR = pencilR;
//            pixelG = pencilG;
//            pixelB = pencilB;
//        }
//    }
//}
//
//int main() {
//    string imgname;
//    cout << "Please enter the filename of the image: ";
//    cin >> imgname;
//
//    // Load the image
//    Image image(imgname);
//
//    // Apply pencil sketch filter
//    applyPencilSketchFilter(image);
//
//    // Save the skewed image
//    string newname;
//    cout << "Please enter the filename to store the skewed image: ";
//    cin >> newname;
//    image.saveImage(newname);
//    system(newname.c_str());
//    cout << "Skewed image has been saved." << endl;
//
//    return 0;
//}
#include <iostream>
#include "Image_Class.h"

using namespace std;

// Function to apply the warm dramatic filter with increased color sharpness
void applyWarmDramaticFilter(Image& image) {
    // Loop through each pixel in the image
    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            // Get pixel values
            int red = image(x, y, 0);
            int green = image(x, y, 1);
            int blue = image(x, y, 2);

            // Increase warmth by adjusting red and green channels
            red = min(255, red + 50);
            green = min(255, green + 20);

            // Increase contrast by reducing blue channel
            blue = max(0, blue - 20);

            // Enhance color sharpness by increasing contrast between adjacent pixels
            if (x > 0) {
                int prevRed = image(x - 1, y, 0);
                int prevGreen = image(x - 1, y, 1);
                int prevBlue = image(x - 1, y, 2);
                red = min(255, red + (red - prevRed) / 2);
                green = min(255, green + (green - prevGreen) / 2);
                blue = min(255, blue + (blue - prevBlue) / 2);
            }
            if (y > 0) {
                int prevRed = image(x, y - 1, 0);
                int prevGreen = image(x, y - 1, 1);
                int prevBlue = image(x, y - 1, 2);
                red = min(255, red + (red - prevRed) / 2);
                green = min(255, green + (green - prevGreen) / 2);
                blue = min(255, blue + (blue - prevBlue) / 2);
            }

            // Set new pixel values
            image(x, y, 0) = red;
            image(x, y, 1) = green;
            image(x, y, 2) = blue;
        }
    }
}

int main() {
    string imgname;
    cout << "Please enter the filename of the image: ";
    cin >> imgname;

    Image image(imgname);

    applyWarmDramaticFilter(image);

    string newname;
    cout << "Please enter the filename to store the filtered image: ";
    cin >> newname;

    image.saveImage(newname);
    system(newname.c_str());
    cout << "Filtered image has been saved." << endl;

    return 0;
}















