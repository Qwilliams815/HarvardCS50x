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
    //RGBTRIPLE test = image[0][0];
    //printf("%i\n", test.rgbtRed);
    image[0][0].rgbtBlue = 255;
    image[0][width-1].rgbtRed = 255;
    image[height-1][0].rgbtBlue = 255;
    printf("height: %i width: %i\n", height, width);



    for (int row=0; row<height-1; row++) {
        int opposite = width-1;
        printf("%i ", opposite);
        for (int column=0; column<width-1; column++) {
            //RGBTRIPLE left_most_pixel = image[row][column];
            //RGBTRIPLE right_most_pixel = image[row][opposite];
            //printf("Row: %i Column: %i", row, column); 398 598
            //printf("Row: %i Column: %i", row, column);

            RGBTRIPLE temp = image[row][opposite];
            temp.rgbtRed = image[row][opposite].rgbtRed;
            temp.rgbtGreen = image[row][opposite].rgbtGreen;
            temp.rgbtBlue = image[row][opposite].rgbtBlue;

            image[row][opposite].rgbtRed = image[row][column].rgbtRed;
            image[row][opposite].rgbtGreen = image[row][column].rgbtGreen;
            image[row][opposite].rgbtBlue = image[row][column].rgbtBlue;

            image[row][column].rgbtRed = temp.rgbtRed;
            image[row][column].rgbtGreen = temp.rgbtGreen;
            image[row][column].rgbtBlue = temp.rgbtBlue;

            //first pixel is image[row][0], last pixel is image[width-1]
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
