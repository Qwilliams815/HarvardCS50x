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

    //image[0][0].rgbtBlue = 255;
    //image[0][0].rgbtGreen = 0;
    //image[0][0].rgbtRed = 0;

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
    //int i = 0;
    // Create copy of original image
    RGBTRIPLE image_copy[height][width];
    for (int row=0; row<height; row++) {
        for (int column=0; column<width; column++) {
            image_copy[row][column] = image[row][column];
            //i++;
        }
    }

    // Loop through the pixels again, this time establishing avg color variables and accessing local pixels
    for (int row=0; row<height; row++) {
        for (int column=0; column<width; column++) {

            //image_copy[row][column] = image[row][column];
            int avg_blue = 0;
            int avg_green = 0;
            int avg_red = 0;
            int num_of_pixels = 0;

            for (int local_row=-1; local_row<2; local_row++) {
                for (int local_col=-1; local_col<2; local_col++) {

                    // Check for out-of-bounds rows
                    if (row + local_row < 0 || row + local_row >= height) {
                        //if local pixel is outside boundrey of the image, continue/skip that pixel.
                        continue;
                    }
                    // Check for out-of-bounds columns
                    if (column + local_col < 0 || column + local_col >= width) {
                        continue;
                    }

                    // Using the image copy, update the avg color values and increment pixel count
                    avg_blue += image_copy[row + local_row][column + local_col].rgbtBlue;
                    avg_green += image_copy[row + local_row][column + local_col].rgbtGreen;
                    avg_red += image_copy[row + local_row][column + local_col].rgbtRed;
                    num_of_pixels++;

                }
            }
        image[row][column].rgbtBlue = round(avg_blue/num_of_pixels);
        image[row][column].rgbtGreen = round(avg_green/num_of_pixels);
        image[row][column].rgbtRed = round(avg_red/num_of_pixels);
        }
    }


    //printf("pixels: %i\n", i);
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    // Create Gx and Gy 2d arrays
    int gx_array[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
        };

    int gy_array[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
        };

    // Create copy of original image
    RGBTRIPLE image_copy[height][width];
    for (int row=0; row<height; row++) {
        for (int column=0; column<width; column++) {
            image_copy[row][column] = image[row][column];
            //i++;
        }
    }

    // Access each pixel of original image
    for (int row=0; row<height; row++) {
        for (int column=0; column<width; column++) {

            // Initiate gx and gy values
            int gx_blue = 0;
            int gx_green = 0;
            int gx_red = 0;

            int gy_blue = 0;
            int gy_green = 0;
            int gy_red = 0;

            int gx_row = 0;
            int gx_col = 0;
            int gy_row = 0;
            int gy_col = 0;

            for (int local_row=-1; local_row<2; local_row++) {
                for (int local_col=-1; local_col<2; local_col++) {
                    //bool imaginary = false;

                    // Check for out-of-bounds rows
                    if (row + local_row < 0 || row + local_row >= height) {
                        continue;
                    }

                    // Check for out-of-bounds columns
                    if (column + local_col < 0 || column + local_col >= width) {
                        continue;
                    }

                    // Conduct gx and gy matrix calculations with current local pixel
                    gx_blue += image_copy[row + local_row][column + local_col].rgbtBlue * gx_array[gx_row][gx_col];
                    gx_green += image_copy[row + local_row][column + local_col].rgbtGreen * gx_array[gx_row][gx_col];
                    gx_red += image_copy[row + local_row][column + local_col].rgbtRed * gx_array[gx_row][gx_col];

                    gy_blue += image_copy[row + local_row][column + local_col].rgbtBlue * gy_array[gy_row][gy_col];
                    gy_green += image_copy[row + local_row][column + local_col].rgbtGreen * gy_array[gy_row][gy_col];
                    gy_red += image_copy[row + local_row][column + local_col].rgbtRed * gy_array[gy_row][gy_col];

                    gx_col++;
                    gy_col++;

                    if (gx_col == 3) {
                        gx_row++;
                        gx_col = 0;
                    }

                    if (gy_col == 3) {
                        gy_row++;
                        gy_col = 0;
                    }

                    //for (int gx_row = 0; gx_row<3; gx_row++) {
                    //    for (int gx_col = 0; gx_col<3; gx_col++) {
                    //        if (imaginary != true) {
                    //            //set rgb values
                    //            int blue_value = image_copy[row + local_row][column + local_col].rgbtBlue;
                    //            int green_value = image_copy[row + local_row][column + local_col].rgbtGreen;
                    //            int red_value = image_copy[row + local_row][column + local_col].rgbtRed;
                    //        }
                    //        //caluculate rgb values * gx index.
                    //        gx_blue = blue_value * gx_array[gx_row][gx_col]
                    //    }
                    //}
                }
        }
    }

    int blue_total = round()


}
