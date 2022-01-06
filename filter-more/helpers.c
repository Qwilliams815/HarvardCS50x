#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Loop through height / width
    for (int row=0; row<width-1; row++) {
        for (int column=0; column<height-1; column++) {
            //take avg of each pixel rgbtRed, rgbtGreen, and rgbtBlue values

            //round them

        }
    }

    //take avg of each pixel rgbtRed, rgbtGreen, and rgbtBlue values
    //roung them
    //set them all to that new rounded avg

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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
