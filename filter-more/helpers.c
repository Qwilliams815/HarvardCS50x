#include "helpers.h"
#include "math.h"
#include "stdio.h"


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Loop through height / width
    for (int row=0; row<height; row++) {
        for (int column=0; column<width; column++) {

            //take avg of each pixel rgbtRed, rgbtGreen, and rgbtBlue values and round them
            float pixel_color_avg = image[row][column].rgbtRed + image[row][column].rgbtGreen + image[row][column].rgbtBlue;
            int final_color_avg = round((pixel_color_avg / 3));
            //printf("%i ", pixel_color_avg);

            // Assign new values
            image[row][column].rgbtRed = final_color_avg;
            image[row][column].rgbtGreen = final_color_avg;
            image[row][column].rgbtBlue = final_color_avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each row
    for (int row=0; row<height; row++) {
        // Establish furthest opposite pixel from current pixel
        int opposite = width-1;
        int halfway = 0;
        for (int column=0; column<width; column++) {
            // If half the image has been filtered, stop.
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

    // Looping through the copy_image, establishing avg color variables and accessing local pixels
    for (int row=0; row<height; row++) {
        for (int column=0; column<width; column++) {

            float avg_blue = 0;
            float avg_green = 0;
            float avg_red = 0;
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
            float gx_blue = 0;
            float gx_green = 0;
            float gx_red = 0;
            
            float gy_blue = 0;
            float gy_green = 0;
            float gy_red = 0;

            // Gx and Gy index trackers
            int sobel_row = 0;
            int sobel_col = 0;

            for (int local_row=-1; local_row<2; local_row++) {
                for (int local_col=-1; local_col<2; local_col++) {
                    //bool imaginary = false;

                    // Check for out-of-bounds rows
                    if (row + local_row < 0 || row + local_row >= height) {
                        sobel_col++;
                        if (sobel_col == 3) {
                        sobel_row++;
                        sobel_col = 0;
                        }
                        continue;
                    }

                    // Check for out-of-bounds columns
                    if (column + local_col < 0 || column + local_col >= width) {
                        sobel_col++;
                        if (sobel_col == 3) {
                        sobel_row++;
                        sobel_col = 0;
                        }
                        continue;
                    }

                    // Conduct gx and gy matrix calculations with current local pixel
                    gx_blue += image_copy[row + local_row][column + local_col].rgbtBlue * gx_array[sobel_row][sobel_col];
                    gx_green += image_copy[row + local_row][column + local_col].rgbtGreen * gx_array[sobel_row][sobel_col];
                    gx_red += image_copy[row + local_row][column + local_col].rgbtRed * gx_array[sobel_row][sobel_col];

                    gy_blue += image_copy[row + local_row][column + local_col].rgbtBlue * gy_array[sobel_row][sobel_col];
                    gy_green += image_copy[row + local_row][column + local_col].rgbtGreen * gy_array[sobel_row][sobel_col];
                    gy_red += image_copy[row + local_row][column + local_col].rgbtRed * gy_array[sobel_row][sobel_col];

                    sobel_col++;

                    if (sobel_col == 3) {
                        sobel_row++;
                        sobel_col = 0;
                    }
                }
            }

            int red_total = round(sqrt(gx_red * gx_red + gy_red * gy_red));
            int green_total = round(sqrt(gx_green * gx_green + gy_green * gy_green));
            int blue_total = round(sqrt(gx_blue * gx_blue + gy_blue * gy_blue));

            // BGR total checker
            if (blue_total > 255) {
                blue_total = 255;
            }

            if (green_total > 255) {
                green_total = 255;
            }

            if (red_total > 255) {
                red_total = 255;
            }

            // Reassign pixel with updated values
            image[row][column].rgbtBlue = blue_total;
            image[row][column].rgbtGreen = green_total;
            image[row][column].rgbtRed = red_total;
        }
    }
    return;
}
