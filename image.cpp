/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include "image.h"

#include <iostream>
using namespace std;

// Note: see image.h for documentation on functions.

int pixelToIndex(int width, int x, int y) {
    int indicesPerPixel = 3;
    int indicesPerRow = width * indicesPerPixel;
    
    return (x * indicesPerPixel) + (y * indicesPerRow);
}

void noRed(int width, int height, int* ppm) {
     for (int r = 0; r < height; r++) {
         for (int c = 0; c < width; c++) {
             int pixelIndex = pixelToIndex(width, c, r);

             ppm[pixelIndex] = 0;
         }
     }
}

void noGreen(int width, int height, int* ppm) {
     for (int r = 0; r < height; r++) {
         for (int c = 0; c < width; c++) {
             int pixelIndex = pixelToIndex(width, c, r);

             ppm[pixelIndex + 1] = 0;
         }
     }
}

void noBlue(int width, int height, int* ppm) {
     for (int r = 0; r < height; r++) {
         for (int c = 0; c < width; c++) {
             int pixelIndex = pixelToIndex(width, c, r);

             ppm[pixelIndex + 2] = 0;
         }
     }
}

void invert(int width, int height, int* ppm) {
     for (int r = 0; r < height; r++) {
         for (int c = 0; c < width; c++) {
             int pixelIndex = pixelToIndex(width, c, r);
             ppm[pixelIndex] = 255 - ppm[pixelIndex];
             ppm[pixelIndex + 1] = 255 - ppm[pixelIndex + 1];
             ppm[pixelIndex + 2] = 255 - ppm[pixelIndex + 2];
         }
     }
}

void grayscale(int width, int height, int* ppm) {
     for (int r = 0; r < height; r++) {
         for (int c = 0; c < width; c++) {
             int pixelIndex = pixelToIndex(width, c, r);
             
             int red = ppm[pixelIndex];
             int green = ppm[pixelIndex + 1];
             int blue = ppm[pixelIndex + 2];
             int rgbAverage = (red + blue + green) / 3;
             
             ppm[pixelIndex] = rgbAverage;
             ppm[pixelIndex + 1] = rgbAverage;
             ppm[pixelIndex + 2] = rgbAverage;
         }
     }
}

void flipHorizontally(int width, int height, int* ppm) {
     int indicesPerPixel = 3;
     int indicesPerRow = width * indicesPerPixel;

     for (int r = 0; r < height; r++) {
         for (int c = 0; c < (width / 2); c++) {
             int pixelIndex = pixelToIndex(width, c, r);
             int complementPixelIndex = (((1+r) * indicesPerRow) - ((1 + c) * indicesPerPixel));
             
             int pixelRed = ppm[pixelIndex];
             int pixelGreen = ppm[pixelIndex + 1];
             int pixelBlue = ppm[pixelIndex + 2];

             ppm[pixelIndex] = ppm[complementPixelIndex];
             ppm[pixelIndex + 1] = ppm[complementPixelIndex + 1];
             ppm[pixelIndex + 2] = ppm[complementPixelIndex + 2];

             ppm[complementPixelIndex] = pixelRed;
             ppm[complementPixelIndex + 1] = pixelGreen;
             ppm[complementPixelIndex + 2] = pixelBlue;
         }
     }
}

void flipVertically(int width, int height, int* ppm) {
     int indicesPerPixel = 3;
     int indicesPerRow = width * 3;

     for (int r = 0; r < (height / 2); r++) {
         for (int c = 0; c < width; c++) {
             int pixelIndex = pixelToIndex(width, c, r);
             int complementPixelIndex = (((height - 1 - r) * indicesPerRow) + (c * indicesPerPixel));

             int pixelRed = ppm[pixelIndex];
             int pixelGreen = ppm[pixelIndex + 1];
             int pixelBlue = ppm[pixelIndex + 2];

             ppm[pixelIndex] = ppm[complementPixelIndex];
             ppm[pixelIndex + 1] = ppm[complementPixelIndex + 1];
             ppm[pixelIndex + 2] = ppm[complementPixelIndex + 2];

             ppm[complementPixelIndex] = pixelRed;
             ppm[complementPixelIndex + 1] = pixelGreen;
             ppm[complementPixelIndex + 2] = pixelBlue;
         }
     }
}
