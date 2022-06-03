/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include <iostream>
#include <string>

#include "image.h"
#include "ppmio.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc != 4) {
      cout << "Invalid number of arguments!" << endl;
      return 1;
    } 
    else {
      // Capture the arguments provide by the user
      string inputFileName = argv[1]; 
      string transformation = argv[2]; 
      string outputFileName = argv[3];

      // Read the file and capture the image's pixel data and dimensions
      int* imagePixelData = read_ppm(inputFileName); 
      int imageWidth = ppm_width(inputFileName);
      int imageHeight = ppm_height(inputFileName); 
      
      // Transform the initial ppm file based on the transformation argument
      // provided
      if (transformation == "noRed") {
        noRed(imageWidth, imageHeight, imagePixelData);
      } else if (transformation == "noGreen") {
        noGreen(imageWidth, imageHeight, imagePixelData);
      } else if (transformation == "noBlue") {
        noBlue(imageWidth, imageHeight, imagePixelData);
      } else if (transformation == "invert") {
        invert(imageWidth, imageHeight, imagePixelData);
      } else if (transformation == "grayscale") {
        grayscale(imageWidth, imageHeight, imagePixelData);
      } else if (transformation == "flipHorizontally") {
        flipHorizontally(imageWidth, imageHeight, imagePixelData);
      } else if (transformation == "flipVertically") {
        flipVertically(imageWidth, imageHeight, imagePixelData);
      } else {
        cout << "Please provide a supported image transformation." << endl;
        delete[] imagePixelData;
        return 1;
      } 
      
      // Write to the new file 
      write_ppm(outputFileName, imageWidth, imageHeight, imagePixelData);

      // Clean up memory
      delete[] imagePixelData;
    }
    return 0;
}
