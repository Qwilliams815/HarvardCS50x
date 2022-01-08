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

    image[0][0].rgbtBlue = 255;
    image[0][0].rgbtGreen = 0;
    image[0][0].rgbtRed = 0;

    //printf("height: %i width: %i\n", height, width);
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
            }

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int avg_red = 0;
    int avg_green = 0;
    int avg_blue = 0;

    // Access each pixel
    for (int row=0; row<height; row++) {
        for (int column=0; column<width; column++) {
            // Access surounding 3x3 grid of current pixel.
            for (int local_row = row-1; local_row<=row+1; local_row++) {
                for (int local_column = column-1; local_column<=column+1; local_column++) {
                //if (image[localrow])
                avg_red += image[local_row][local_column].rgbtRed;
                avg_green += image[local_row][local_column].rgbtGreen;
                avg_blue += image[local_row][local_column].rgbtBlue;
            }
            int local_column = column;
            image[row][column];
            for (int pixel=0; pixel<9; pixel++)

        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
