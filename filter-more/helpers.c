#include "helpers.h"
#include "math.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Loop through height / width
    printf("test helloooooooo\n");
    for (int row=0; row<height; row++) {
        for (int column=0; column<width; column++) {
            RGBTRIPLE pixel = image[row][column];

            //take avg of each pixel rgbtRed, rgbtGreen, and rgbtBlue values and round them
            int pixel_color_avg = round(pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue);
            pixel_color_avg /= 3;

            // Asign new values
            pixel.rgbtRed = pixel_color_avg;
            pixel.rgbtGreen = pixel_color_avg;
            pixel.rgbtBlue = pixel_color_avg;
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
