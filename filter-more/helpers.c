#include "helpers.h"
#include "math.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Loop through height / width
    for (int row=0; row<height; row++) {
        for (int column=0; column<width; column++) {
            //RGBTRIPLE pixel = image[row][column];

            //take avg of each pixel rgbtRed, rgbtGreen, and rgbtBlue values and round them
            int pixel_color_avg = round(image[row][column].rgbtRed + image[row][column].rgbtGreen + image[row][column].rgbtBlue);
            pixel_color_avg /= 3;
            //printf("%i ", pixel_color_avg);

            // Asign new values
            image[row][column].rgbtRed = pixel_color_avg;
            image[row][column].rgbtGreen = pixel_color_avg;
            image[row][column].rgbtBlue = pixel_color_avg;
        }
    }
    //set them all to that new rounded avg

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //printf("Test\n");
    //printf("%i\n", image[0][3].rgbtRed);
    //RGBTRIPLE test = image[0][3];
    //printf("%i\n", test.rgbtRed);

    for (int row=0; row<height; row++) {
        int opposite = width;
        for (int column=0; column<width; column++) {
            //RGBTRIPLE left_most_pixel = image[row][column];
            //RGBTRIPLE right_most_pixel = image[row][opposite];

            RGBTRIPLE temp = image[row][opposite];
            image[row][opposite] = image[row][column];
            image[row][column] = temp;

            //first pixel is image[row][0], last pixel is image[width]
            opposite--;
        }
    }
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
