
/*

    Name: Qossay mohammed mahmoud aqil
    ID:20230722 
    Filter 1 & 4 & 7 & 10 & 14 & 15 & 18 & 20

    Name: Marwan Ali Mohamed Bebars
    ID:20230384
    Filter 2 & 5 & 8 & 11 & 16 & 19 

    Name: Belal Gamal Faris Abd Al Aziz
    ID:20230095
    Filter 3 & 6 & 9 & 12 & 13 & 17


    LAB 3&4
*/


#pragma warning(disable : 4996)
#include<iostream>
#include<vector>
#include<cstring>
#include<random>
#include<cstdlib>
#include<ctime>
#include "Image_Class.h"
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;


//upload Image
Image processImage() {
    string imgname;
    Image image;
    bool isValidImage = false;
    while (!isValidImage) {
        cout << "Please enter the filename of the image: ";
        cin >> imgname;
        try {
            if (image.loadNewImage(imgname)) {
                isValidImage = true; // Set flag to true to exit the looplu
                cout << "Image loaded successfully!\n" << endl;
                // Add code to process the image here
            } else {
                cout << "\nFailed to load the image. Please try again." << endl;
                // You can add additional error handling here if needed
            }
        } catch (const std::invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
            cout << "Please enter a valid filename." << endl;
        }
    }
    return image;
}


string saveImageWithExtension() {
    string newname;
    bool isValidExtension = false;
    while (!isValidExtension) {
        cout << "Please enter the filename to store the image, and specify extension (.jpg, .bmp, .png, .tga): ";
        cin >> newname;

        // Check if the filename has a valid extension
        if (newname.length() >= 4 && (newname.substr(newname.length() - 4) == ".jpg" ||
                                       newname.substr(newname.length() - 4) == ".bmp" ||
                                       newname.substr(newname.length() - 4) == ".png" ||
                                       newname.substr(newname.length() - 4) == ".tga")) {
            isValidExtension = true; // Set flag to true to exit the loop
        } else {
            cout << "Invalid filename extension. Please use ( .jpg, .bmp, .png, .tga. )!" << endl;
        }
    }
    return newname;

}


//a function that make a validation that read only number
float ReadNumber() {
	float number = 0;
	cin >> number;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one" << endl;
		cin >> number;
	}
	return number;
}

// a function that depends on raed number function and use it
//to read only a number in a specified range by the arguments
int	readNumInRange(int from, int to) {
	int num;
	do {
		cout << "\nplease enter a whole number from " << from << " to " << to << endl;
		cin >> num;
	} while (round(num) != num || num > to || num < from);
	return num;
}

//Grayscale Conversion scale filter 1
Image gray(Image& image) {
    Image filter = image;
	for (int i = 0; i < filter.width; ++i) {
		for (int j = 0; j < filter.height; ++j) {
			unsigned int gr = 0;

			for (int k = 0; k < 3; ++k) {
				gr += (unsigned int)filter(i, j, k);
			}
			gr /= 3;
			filter(i, j, 0) = gr;
			filter(i, j, 1) = gr;
			filter(i, j, 2) = gr;
		}
	}
    return filter ;

}

//Black and White Filter 2
Image Black_and_White(Image& image)
{
    Image filter = image;
	const int threshold = 128;
	for (int i = 0; i < filter.width; ++i) {
		for (int j = 0; j < filter.height; ++j) {
			unsigned int avg = 0;
			for (int k = 0; k < filter.channels; ++k) {
				avg += filter(i, j, k);
			}
			avg /= 3;
			unsigned char color = (avg > threshold) ? 255 : 0;
			for (int k = 0; k < 3; ++k) {
				filter(i, j, k) = color;
			}
		}
	}
    return filter;
}


//invert color functions 3
Image Invert_image_filter(Image& image){
    Image filter = image ;
	for (int i = 0; i < filter.width; i++) {
		for (int j = 0; j < filter.height; j++) {
			for (int k = 0; k < 3; k++) {

				filter(i, j, k)=255- filter(i, j, k);
			}
		}
	}
    return filter;
}

//merge filter 4
Image marge(Image& image) {
    
    Image filter1 = image ;
    Image filter2 ;
    filter2 = processImage();

	// Load the images
	Image img1(filter1);
	Image img2(filter2);

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
    return mergedImage;

}

//Flip Image filter 5
Image Flip_Image(Image& image)
{
	Image image5 = image;
	// Horizontal flip (left-right flip)
	for (int i = 0; i < image5.height; ++i) {
		for (int j = 0; j < image5.width / 2; ++j) {
			for (int k = 0; k < image5.channels; ++k) {
				swap(image5(j, i, k), image5(image5.width - 1 - j, i, k));
			}
		}
	}
	// system(newname.c_str());

	Image image55 = image;

	//     Vertical flip (top-bottom flip)
	for (int i = 0; i < image55.height / 2; ++i) {
		for (int j = 0; j < image55.width; ++j) {
			for (int k = 0; k < image55.channels; ++k) {
				swap(image55(j, i, k), image55(j, image5.height - 1 - i, k));
			}
		}
	}
    cout << "1) Saved Horizontal flip.\n";
    cout << "2) Saved Vertical flip.\n";
    float chose = readNumInRange(1, 3);
    string newname;
    if (chose == 1)
    {
        return image5;
    }
    else if (chose == 2)
    {
        return image55;  
    }
}

//rotate imaeg by 90 degree
Image rotate_by_90(Image Original_image) {
	Image rotated_90_degree(Original_image.height, Original_image.width);
	for (int i = 0; i < rotated_90_degree.width; i++) {
		for (int j = 0; j < rotated_90_degree.height; j++) {
			for (int k = 0; k < 3; k++) {

				rotated_90_degree(i, j, k) = Original_image(j, Original_image.height - i, k);
			}
		}
	}
    return rotated_90_degree;
}

//rotate imaeg by 180 degree
Image rotate_by_180(Image Original_image) {
	Image rotated_180_degree(Original_image.width, Original_image.height);
	for (int i = 0; i < Original_image.width; i++) {
		for (int j = 0; j < Original_image.height; j++) {
			for (int k = 0; k < 3; k++) {

				rotated_180_degree(i, j, k) = Original_image(i, Original_image.height - j, k);
			}
		}
	}
    return rotated_180_degree;
	
}

//rotate imaeg by 270 degree
Image rotate_by_270(Image Original_image) {
	Image rotated_270_degree(Original_image.height, Original_image.width);
	for (int i = 0; i < Original_image.width; i++) {
		for (int j = 0; j < Original_image.height; j++) {
			for (int k = 0; k < 3; k++) {

				rotated_270_degree(i, j, k) = Original_image(j, i, k);
			}
		}
	}
    return rotated_270_degree;


}

//rotate image filter 6
Image rotate_image_filter(Image& image) {
	Image Original_image = image;


	short unsigned choise;
	cout << "\t\t\t\t\t welcome to rotate image filter\n";
	cout << "choose the number of the rotation you want to choose\n";
	cout << "1)rotate by 90 degree\n";
	cout << "2)rotate by 180 degree\n";
	cout << "3)rotate by 270 degree\n";
	choise = readNumInRange(1, 3);
	
	if (choise == 1) {
		return rotate_by_90(Original_image);
	}
	if (choise == 2) {
		return rotate_by_180(Original_image);
	}
	if (choise == 3) {
		return rotate_by_270(Original_image);
	}
}


// filter 7 Darken_and_lighten()
Image Darken_and_lighten(Image& imag) {
    Image image = imag;
    int x = 0;
    while (x != 1 && x != 2) {
        cout << "What do you want?\n" << "1) Increase lighting\n" << "2) Decrease lighting\n";
        cin >> x;
        if (x == 1) {
            for (int i = 0; i < image.width; ++i) {
                for (int j = 0; j < image.height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        // Calculate the new pixel value by increasing brightness by 50%
                        float increasedValue = image(i, j, k) + image(i, j, k) * 0.5;
                        // Ensure the increased pixel value does not exceed 255
                        if (increasedValue > 255) {
                            increasedValue = 255;
                        }
                        // Assign the increased pixel value to the image
                        image(i, j, k) = increasedValue;
                    }
                }
            }
        }
        else if (x == 2) {
            for (int i = 0; i < image.width; ++i) {
                for (int j = 0; j < image.height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        // Calculate the new pixel value by decreasing brightness by 50%
                        float decreasedValue = image(i, j, k) * 0.5;

                        // Ensure the decreased pixel value is not less than 0
                        if (decreasedValue < 0) {
                            decreasedValue = 0;
                        }

                        // Assign the decreased pixel value to the image
                        image(i, j, k) = decreasedValue;
                    }
                }
            }
        }
        else {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
        }
    }
    return image;
}

// filter 8 Crop Images
 Image Crop_Images(Image& image)
 {
     Image originalImage = image; // Load the original image

     int x, y, width, height;
     cout << "Enter x-coordinate of upper left corner to crop from: ";
     cin >> x;
     cout << "Enter y-coordinate of upper left corner to crop from: ";
     cin >> y;
     cout << "Enter width of cropped area: ";
     cin >> width;
     cout << "Enter height of cropped area: ";
     cin >> height;

     // Check if the specified crop area is within the bounds of the original image
     while (x < 0 || y < 0 || x + width > originalImage.width || y + height > originalImage.height)
     {
         cerr << "\nError: Crop area exceeds the bounds of the original image." << endl;
         cout << "==========================================================\n" << endl;

         cout << "Enter x-coordinate of upper left corner to crop from: ";
         cin >> x;
         cout << "Enter y-coordinate of upper left corner to crop from: ";
         cin >> y;
         cout << "Enter width of cropped area: ";
         cin >> width;
         cout << "Enter height of cropped area: ";
         cin >> height;
     }

     // Create a new image for the cropped area
     Image croppedImage(width, height);
     // Copy the cropped area from the original image to the new cropped image
     for (int i = 0; i < width; ++i) {
         for (int j = 0; j < height; ++j) {
             for (int k = 0; k < 3; ++k)
             {
                 croppedImage(i,j,k) = originalImage(i+x,j+y,k);
             }
         }
     }
    return croppedImage;


}

// filter 9 ِAdding a Frame to the Picture
Image Framing_Filter(Image &image) {
	short unsigned user_choise;
	Image framed_image = image;
	cout << "please enter the numbe of the frame you want to add to the image\n";
	cout << "1)Frame one\n";
	cout << "2)Frame Two\n";
	cout << "3)Frame Three\n";
	user_choise = readNumInRange(1, 3);
	if (user_choise == 1) {
            //frame one
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < 3; k++) {
                    if (((image.width / 80) > i) || ((image.height / 80) > j) || (image.width-(image.width / 80) < i) || (image.height-(image.height / 80) < j)) {
                        framed_image(i, j, k) = image(i, j, k)=200;
                    }
                    else if ((image.width / 80+(image.width / 80) > i) || (image.height / 80+(image.height / 80) > j) || (image.width - image.width / 80- (image.width / 80) < i) || (image.height - image.width / 80- (image.width / 80) < j)) {
                        if (0 == k)
                            framed_image(i, j, k) = image(i, j, k) = 0;
                        else if (1 == k)
                                framed_image(i, j, k) = image(i, j, k) = 150;
                        else 
                            framed_image(i, j, k) = image(i, j, k) = 255;
                    }
                    else {
                        framed_image(i, j, k) = image(i, j, k);
                    }
                    }
            }
        }
	}
	else if (user_choise == 2) {
            //frame two not finished yet
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < 3; k++) {
                    if (((image.width / 80) > i) || ((image.height / 80) > j) || (image.width - (image.width / 80) < i) || (image.height - (image.height / 80) < j)) {
                        framed_image(i, j, k) = image(i, j, k) = 200;
                    }
                    else if ((image.width / 80 + (image.width / 80) > i) || (image.height / 80 + (image.height / 80) > j) || (image.width - image.width / 80 - (image.width / 80) < i) || (image.height - image.width / 80 - (image.width / 80) < j)) {
                        if (0 == k)
                            framed_image(i, j, k) = image(i, j, k) = 0;
                        else if (1 == k)
                            framed_image(i, j, k) = image(i, j, k) = 150;
                        else
                            framed_image(i, j, k) = image(i, j, k) = 255;
                    }
                    else if ((image.width / 80 + (image.width / 80)  == i) || (image.height / 80 + (image.height / 80) == j) || (image.width - image.width / 80 - (image.width / 80)  == i) || (image.height - image.width / 80 - (image.width / 80)  == j)) {
                        framed_image(i, j, k) = image(i, j, k) = 255;
                    }
                    else if ((image.width / 80 + (image.width / 80) + 2 == i) || (image.height / 80 + (image.height / 80) + 2 == j) ) {
                        framed_image(i, j, k) = image(i+1, j+1, k) = 255;
                    }
                    else if ((image.width - image.width / 80 - (image.width / 80) - 2 == i) || (image.height - image.width / 80 - (image.width / 80) - 2 == j)) {
                        framed_image(i, j, k) = image(i-1, j-1, k) = 255;
                    }
                    else {
                        framed_image(i, j, k) = image(i, j, k);
                    }
                }
            }
        }

	}
	else {
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < 3; k++) {
                    if (((image.width / 80) > i) || ((image.height / 80) > j) || (image.width - (image.width / 80) < i) || (image.height - (image.height / 80) < j)) {
                        framed_image(i, j, k) = image(i, j, k) = 50;
                    }
                    else if ((image.width / 80 + (image.width / 80) > i) || (image.height / 80 + (image.height / 80) > j) || (image.width - image.width / 80 - (image.width / 80) < i) || (image.height - image.width / 80 - (image.width / 80) < j)) {
                        if (0 == k)
                            framed_image(i, j, k) = image(i, j, k) = 200;
                        else if (1 == k)
                            framed_image(i, j, k) = image(i, j, k) = 150;
                        else
                            framed_image(i, j, k) = image(i, j, k) = 20;
                    }
                    else if ((image.width / 80 + (image.width / 80) == i) || (image.height / 80 + (image.height / 80) == j) || (image.width - image.width / 80 - (image.width / 80) == i) || (image.height - image.width / 80 - (image.width / 80) == j)) {
                        framed_image(i, j, k) = image(i, j, k) = 70;
                    }
                    else if ((image.width / 80 + (image.width / 80) + 2 == i) || (image.height / 80 + (image.height / 80) + 2 == j)) {
                        framed_image(i, j, k) = image(i + 1, j + 1, k) = 255;
                    }
                    else if ((image.width - image.width / 80 - (image.width / 80) - 2 == i) || (image.height - image.width / 80 - (image.width / 80) - 2 == j)) {
                        framed_image(i, j, k) = image(i - 1, j - 1, k) = 255;
                    }
                    else {
                        framed_image(i, j, k) = image(i, j, k);
                    }
                }
            }
	    }
	}
    return framed_image;
}


// filter 10 Detect Image Edges
Image Detect(Image& imag) 
{
    Image image = imag;
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

    // Detect edges using Sobel operator
    Image edges(image.width, image.height);
    for (int i = 1; i < image.width - 1; ++i) {
        for (int j = 1; j < image.height - 1; ++j) {
            int gradientX = 0, gradientY = 0;
            for (int k = 0; k < 3; ++k) {
                // Apply Sobel operator
                gradientX += image(i - 1, j - 1, k) - image(i + 1, j - 1, k);
                gradientX += 2 * (image(i - 1, j, k) - image(i + 1, j, k));
                gradientX += image(i - 1, j + 1, k) - image(i + 1, j + 1, k);

                gradientY += image(i - 1, j - 1, k) - image(i - 1, j + 1, k);
                gradientY += 2 * (image(i, j - 1, k) - image(i, j + 1, k));
                gradientY += image(i + 1, j - 1, k) - image(i + 1, j + 1, k);
            }
            // Compute the gradient magnitude
            int magnitude = sqrt(gradientX * gradientX + gradientY * gradientY);
            if (magnitude > threshold) {
                // Set edge pixel to black
                for (int k = 0; k < 3; ++k) {
                    edges(i, j, k) = 0; // Set pixel value to minimum (black)
                }
            }
            else {
                // Set non-edge pixel to white
                for (int k = 0; k < 3; ++k) {
                    edges(i, j, k) = 255; // Set pixel value to maximum (white)
                }
            }
        }
    }

    return edges;
}


//filter 11 Resizing_Images
 Image  Resizing_Images(Image& image)
 {
     int newWid, newHeigh;
     cout << "Enter new width: ";
     cin >> newWid;
     cout << "Enter new height: ";
     cin >> newHeigh;
     while (newWid <= 0 || newHeigh <= 0)
     {
         cout << "Error: Invalid dimensions. Width and height must be positive integers." << endl;
         cout << "=======================================================================" << endl;
         cout << "Enter new width: ";
         cin >> newWid;
         cout << "Enter new height: ";
         cin >> newHeigh;
     }


     // Create a new image with the new dimensions
     Image resizedImage(newWid, newHeigh);
     int sr = image.width / newWid;
     int sc = image.height / newHeigh;


     for (int i = 0; i < newWid; ++i) {
         for (int j = 0; j < newHeigh; ++j) {
             for (int k = 0; k < 3; ++k) {
                 int origX = round(i * sr);
                 int origY = round(j * sc);
                 resizedImage(i,j,k) = image(origX,origY,k);

             }

         }
     }
    return resizedImage;

}


// filter 12  Blur Images
Image Blur_image_Filter(Image& image){ 
	Image Original_image = image;

	for (int tt = 0; tt < 50; tt++) {
		for (int i = 2; i < Original_image.width - 4; i++) {
			for (int j = 2; j < Original_image.height - 4; j++) {
				for (int k = 0; k < 3; k++) {
					Original_image(i, j, k) = (Original_image(i, j, k)
						+ Original_image(i + 1, j + 1, k) + Original_image(i + 1, j, k) + Original_image(i, j + 1, k)
						+ Original_image(i + 2, j + 2, k) + Original_image(i + 2, j + 1, k) + Original_image(i + 1, j + 2, k) + Original_image(i + 2, j, k) + Original_image(i, j + 2, k)
						+ Original_image(i + 3, j + 3, k) + Original_image(i + 2, j + 3, k) + Original_image(i + 3, j + 2, k) + Original_image(i + 1, j + 3, k) + Original_image(i + 3, j + 1, k) + Original_image(i + 3, j, k) + Original_image(i, j + 3, k)
						) / 16;
				}
			}
		}
	}
	return Original_image;
}



// filter 13 Wano doesn’t have good natural sunlight
Image Sun_image_Filter(Image& image) {
	Image Original_image = image;

	for (int i = 0; i < Original_image.width; i++) {
		for (int j = 0; j < Original_image.height; j++) {
			Original_image(i, j, 0) = Original_image(i, j, 0);
			Original_image(i, j, 1) = Original_image(i, j, 1);
			Original_image(i, j, 2) = 130;
		}
	}
	return Original_image;
}



//filter 14 
Image oilPaintingEffect(Image& image) {

    Image oilPainting(image.width, image.height);

    int r = 10;

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int densityCount[3][256] = { 0 };

            for (int x = max(0, i - r); x <= min(image.width - 1, i + r); ++x) {
                for (int y = max(0, j - r); y <= min(image.height - 1, j + r); ++y) {
                    for (int k = 0; k < 3; ++k) {
                        int density = image(x, y, k);
                        densityCount[k][density]++;
                    }
                }
            }

            int maxCount[3] = { 0 };
            for (int k = 0; k < 3; ++k) {
                for (int density = 0; density < 256; ++density) {
                    if (densityCount[k][density] > densityCount[k][maxCount[k]]) {
                        maxCount[k] = density;
                    }
                }
            }

            for (int k = 0; k < 3; ++k) {
                oilPainting(i, j, k) = maxCount[k] / 2 + image(i, j, k) / 2;
            }
        }
    }

    return oilPainting;
}

//filter 15 applyOldTVFilter (televisions) 
Image applyOldTVFilter(Image& imag) {
    Image image = imag;
    srand(time(nullptr));

    int noiseLevel = rand() % 31;
    int scanlineIntensity = rand() % 256;
    int distortionLevel = rand() % 256;

    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            for (int c = 0; c < image.channels; ++c) {
                int noise = rand() % (noiseLevel + 1);
                int pixelValue = image(x, y, c);
                image(x, y, c) = max(0, min(255, pixelValue + noise));
            }
        }
    }

    for (int y = 0; y < image.height; ++y) {
        if (y % 2 == 0) {
            for (int x = 0; x < image.width; ++x) {
                for (int c = 0; c < image.channels; ++c) {
                    image(x, y, c) = max(0, image(x, y, c) - scanlineIntensity);
                }
            }
        }
    }

    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            for (int c = 0; c < image.channels; ++c) {
                int distortion = rand() % (distortionLevel + 1);
                int pixelValue = image(x, y, c);
                image(x, y, c) = max(0, min(255, pixelValue + distortion));
            }
        }
    }

    return image;
}

//filter 16 looks so purple
Image imag_look_purple(Image& image)
 {

         // Load the original image
         Image originalImage = image;

         // Create a new image with the same dimensions as the original image
         Image purpleImage(originalImage.width, originalImage.height);

         // Convert the image to purple
         for (int y = 0; y < originalImage.height; ++y) {
             for (int x = 0; x < originalImage.width; ++x) {
                 // Get the RGB values of the current pixel
                 int red = originalImage.getPixel(x, y, 0);
                 int green = originalImage.getPixel(x, y, 1);
                 int blue = originalImage.getPixel(x, y, 2);

                 green = static_cast<int>(green * 0.65);
                 blue = static_cast<int>(blue * 0.65);


                 purpleImage.setPixel(x, y, 0, static_cast<unsigned char>(red));
                 purpleImage.setPixel(x, y, 1, static_cast<unsigned char>(green));
                 purpleImage.setPixel(x, y, 2, static_cast<unsigned char>(blue));
                }
         }
        return purpleImage;




 }


//filter 17  Samurais are passionate
Image Infrared_Filter(Image& image) {
	Image Original_image = image;

	for (int i = 0; i < Original_image.width; i++) {
		for (int j = 0; j < Original_image.height; j++) {
			Original_image(i, j, 0) = 255;
			Original_image(i, j, 1) = 255 - Original_image(i, j, 1);
			Original_image(i, j, 2) = 255 - Original_image(i, j, 2);
		}
	}
	return Original_image;
}

//filter 18 
Image skewed(Image& imag) {

    Image image = imag;

    double angle = (40 * 3.1416) / 180.0;

    int newWidth = image.width + image.height * tan(angle); 
    int newHeight = image.height;

    Image skewedImage(newWidth, newHeight);

    for (int i = 0; i < newWidth; ++i) {
        for (int j = 0; j < newHeight; ++j) {
            int x = i - j * tan(angle); 

            if (x >= 0 && x < image.width) {
                for (int k = 0; k < image.channels; ++k) {
                    skewedImage(i, j, k) = image(x, j, k);
                }
            }
            else {
                for (int k = 0; k < image.channels; ++k) {
                    skewedImage(i, j, k) = 0;
                }
            }
        }
    }

    for (int i = 0; i < newWidth / 2; ++i) {
        for (int j = 0; j < newHeight; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                swap(skewedImage(i, j, k), skewedImage(newWidth - i - 1, j, k));
            }
        }
    }

    return skewedImage;

 }

Image imag_look_blue(const Image& image)
{
    // Create a new image with the same dimensions as the original image
    Image blueImage(image.width, image.height);

    // Apply the strong blue filter to the image
    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            // Get the RGB values of the current pixel
            int red = image.getPixel(x, y, 0);
            int green = image.getPixel(x, y, 1);
            int blue = image.getPixel(x, y, 2);

            // Increase the blue channel significantly to create a strong blue tint
            blue = std::min(blue + 100, 255); // Increase blue value by 100 (adjust as needed)

            // Set the modified RGB values to the new image
            blueImage.setPixel(x, y, 0, static_cast<unsigned char>(red));
            blueImage.setPixel(x, y, 1, static_cast<unsigned char>(green));
            blueImage.setPixel(x, y, 2, static_cast<unsigned char>(blue));
        }
    }

    return blueImage;
}

Image imag_look_green(const Image& image)
{
    // Create a new image with the same dimensions as the original image
    Image greenImage(image.width, image.height);

    // Apply the green filter to the image
    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            // Get the RGB values of the current pixel
            int red = image.getPixel(x, y, 0);
            int green = image.getPixel(x, y, 1);
            int blue = image.getPixel(x, y, 2);

            // Increase the green channel to create a green tint
            green = std::min(green + 50, 255); // Increase green value by 50 (adjust as needed)

            // Set the modified RGB values to the new image
            greenImage.setPixel(x, y, 0, static_cast<unsigned char>(red));
            greenImage.setPixel(x, y, 1, static_cast<unsigned char>(green));
            greenImage.setPixel(x, y, 2, static_cast<unsigned char>(blue));
        }
    }

    return greenImage;
}

Image imag_look_orange(const Image& image)
{
    // Create a new image with the same dimensions as the original image
    Image orangeImage(image.width, image.height);

    // Apply the orange filter to the image
    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            // Get the RGB values of the current pixel
            int red = image.getPixel(x, y, 0);
            int green = image.getPixel(x, y, 1);
            int blue = image.getPixel(x, y, 2);

            // Increase the red and green channels to create an orange tint
            red = std::min(red + 100, 255); // Increase red value by 100 (adjust as needed)
            green = std::min(green + 50, 255); // Increase green value by 50 (adjust as needed)

            // Set the modified RGB values to the new image
            orangeImage.setPixel(x, y, 0, static_cast<unsigned char>(red));
            orangeImage.setPixel(x, y, 1, static_cast<unsigned char>(green));
            orangeImage.setPixel(x, y, 2, static_cast<unsigned char>(blue));
        }
    }

    return orangeImage;
}

//filter 19
Image chooseColor(Image &image)
{
    cout << "1) Image look Blue\n";
    cout << "2) Image look Green\n";
    cout << "3) Image look Orange\n";
    cout << "Which color you want:";
    int num = readNumInRange(1, 3);
    if (num == 1)
    {
        return imag_look_blue(image);
    }
    else if (num == 2)
    {
        return imag_look_green(image); 
    }
    else if (num == 3)
    {
        return imag_look_orange(image);
    }

}

//filter 20
Image applyWarmDramaticFilter(Image& image) {
    Image filter = image;
    // Loop through each pixel in the image
    for (int y = 0; y < filter.height; ++y) {
        for (int x = 0; x < filter.width; ++x) {
            // Get pixel values
            int red = filter(x, y, 0);
            int green = filter(x, y, 1);
            int blue = filter(x, y, 2);

            // Increase warmth by adjusting red and green channels
            red = min(255, red + 50);
            green = min(255, green + 20);

            // Increase contrast by reducing blue channel
            blue = max(0, blue - 20);

            // Set new pixel values
            filter(x, y, 0) = red;
            filter(x, y, 1) = green;
            filter(x, y, 2) = blue;
        }
    }
    return filter;
    
}


/*main function that call the whole program and 
 go through a infinite loop till the user stops the program*/
Image Magical_filters_function(Image &image) {
	string play_again = "y";
	while (play_again == "y" || play_again == "Y") {
		short unsigned selected_filter;
		// system("cls");
		cout << ">>>>>>>>>>>>>>>>>>>>> what filter you want to use <<<<<<<<<<<<<<<<<<<<<<\n\n";
		cout << "1)  Grayscale Conversion filter\n";
		cout << "2)  Black and White filter\n";
		cout << "3)  Invert filter\n";
		cout << "4)  Merge Images filter\n";
		cout << "5)  Flip Image filter\n";
		cout << "6)  Rotate Image filter\n";
        cout << "7)  Darken and Lighten Image\n";
		cout << "8)  Crop Images\n";
		cout << "9)  Adding a Frame to the Picture\n";
		cout << "10) Detect Image Edges\n";
		cout << "11) Resizing Images\n";
		cout << "12) Blur Images\n";
		cout << "13) Wano doesn’t have good natural sunlight.\n";
		cout << "14) Oil painting is famous in Wano.\n";
		cout << "15) Wano villagers use old Den Den Mushi (televisions) to view the news.\n";
		cout << "16) Wano looks so purple\n";
		cout << "17) Samurais are passionate\n";
		cout << "18) Image Skewing Filter\n";
        cout << "19) filter colors\n";
		cout << "20) Apply WarmDramatic Filter\n";


		selected_filter = readNumInRange(1, 20);
		if (selected_filter == 1) {
			return gray(image);
		}
        else if (selected_filter == 2) {
			return Black_and_White(image);
		}
		else if (selected_filter == 3) {
			return Invert_image_filter(image);
		}
		else if (selected_filter == 4) {
			return marge(image);
		}
		else if (selected_filter == 5) {
			return Flip_Image(image);
		}
		else if (selected_filter == 6) {
			return rotate_image_filter(image);
		}
		else if (selected_filter == 7) {
            return Darken_and_lighten(image);
		}
		else if (selected_filter == 8) {
            return Crop_Images(image);
		}
		else if (selected_filter == 9) {
            return Framing_Filter(image);
		}
		else if (selected_filter == 10) {
            return Detect(image);
		}
		else if (selected_filter == 11) {
            return Resizing_Images(image);
		}
		else if (selected_filter == 12) {
            return Blur_image_Filter(image);
		}
        else if (selected_filter == 13) {
            return Sun_image_Filter(image);
		}
		else if (selected_filter == 14) {
            return oilPaintingEffect(image);
		}
		else if (selected_filter == 15) {
            return applyOldTVFilter(image);
		}
		else if (selected_filter == 16) {
            return imag_look_purple(image);
		}
		else if (selected_filter == 17) {
            return Infrared_Filter(image);
		}
		else if (selected_filter == 18) {
            return skewed(image);
		}
        else if (selected_filter == 19) {
            return chooseColor(image);
		}
        else if (selected_filter == 20) {
            return applyWarmDramaticFilter(image);
		}


        cout << "do you want to run the program again Y/N? if yes enter Y else enter N\n";
        cin >> play_again;
        transform(play_again.begin(), play_again.end(), play_again.begin(), ::toupper);

        while (play_again.size() != 1 || (play_again != "Y" && play_again != "N")) {
            cout << "Invalid input. Please enter Y or N: ";
            cin >> play_again;
            transform(play_again.begin(), play_again.end(), play_again.begin(), ::toupper);
        }
        if (play_again == "N")
        {
            break;
        }
	}
	
    
}
    
int main() {
    string imgname, newname ,savePath;
    Image image;

    do {
        image = processImage();
        Image filteredImage = Magical_filters_function(image);
        newname = saveImageWithExtension();
        filteredImage.saveImage(newname);
        // system(newname.c_str());


        cout << "\nDo you want to run the program again? (Y/N): ";
        cin >> imgname;
        // system("clear"); 
        transform(imgname.begin(), imgname.end(), imgname.begin(), ::toupper);
        while (imgname != "Y" && imgname != "N" ) {
            cout << "Invalid input. Please enter Y or N: ";
            cin >> imgname;
            transform(imgname.begin(), imgname.end(), imgname.begin(), ::toupper);
        }
        system("clear"); 
        
    } while (imgname == "Y");

    cout << "Exiting the program. Goodbye!" << endl;

    return 0;
}
