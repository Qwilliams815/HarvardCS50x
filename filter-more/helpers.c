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
    int i = 0;
    RGBTRIPLE image_copy[height][width];

    // Create copy of original image
    for (int row=0; row<height; row++) {
        for (int column=0; column<width; column++) {
            image_copy[row][column] = image[row][column];
            i++;
        }
    }

    for (int row=0; row<height; row++) {
        for (int column=0; column<width; column++) {
            //image_copy[row][column] = image[row][column];
            int avg_blue = 0;
            int avg_green = 0;
            int avg_red = 0;
            int num_of_pixels = 0;

            for (int local_row=-1; local_row<2; local_row++) {
                for (int local_col=-1; local_col<2; local_col++) {

                    // Check loop through local rows, compared to current pixel
                    if (row + local_row < 0 || row + local_row >= height) {
                        //if local pixel is outside boundrey of the image, continue/skip that pixel.
                        continue;
                    }
                    // Check loop through local columns, compared to current pixel
                    if (column + local_col < 0 || column + local_col >= width) {
                        continue;
                    }

                    avg_blue = 0;
                    avg_green = 0;
                    avg_red = 0;
                    num_of_pixels = 0;

                    avg_red += image[i][j].rgbtRed;
                                avg_green += image[i][j].rgbtGreen;
                                avg_blue += image[i][j].rgbtBlue;




                }
            }
        }
    }


    printf("pixels: %i\n", i);
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
