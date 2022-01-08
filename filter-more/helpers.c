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
    //int opposite = width-1;
    image[0][0].rgbtBlue = 255;
    image[0][0].rgbtGreen = 0;
    image[0][0].rgbtRed = 0;

    //image[0][opposite].rgbtRed = 255;
    //image[0][opposite].rgbtBlue = 0;
    //image[0][opposite].rgbtGreen = 0;

    //for (int row=0; row<height; row++) {
    //    image[row][0].rgbtRed = 255;
    //}


    //RGBTRIPLE temp = image[0][opposite];
    //image[0][opposite] = image[0][0];
    //image[0][0] = temp;

    //image[height-1][opposite].rgbtBlue = 255;
    printf("height: %i width: %i\n", height, width);
    //height 400, width: 600




    for (int row=0; row<height; row++) {
        int opposite = width-1;
        int halfway = 0;
        for (int column=0; column<width; column++) {
            if (halfway != width/2) {
                RGBTRIPLE temp = image[row][opposite];
                image[row][opposite] = image[row][column];
                image[row][column] = temp;
                opposite--;
                halfway++;
                //printf("%i ", opposite);

            }

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
