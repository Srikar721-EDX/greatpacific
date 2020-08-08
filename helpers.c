#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
        {
            float average = (image[row][col].rgbtBlue + image[row][col].rgbtRed + image[row][col].rgbtGreen)/3.00;
            int avg = round(average);
            
            image[row][col].rgbtBlue = avg;
            image[row][col].rgbtRed = avg;
            image[row][col].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
