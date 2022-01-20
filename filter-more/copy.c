// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
     //RGBTRIPLE image_copy = image;
     //printf("%i\n", image_copy[0][0].rgbtRed);

    //int image_copy[] = {image};
    //printf("%i\n", sizeOf(image));


    int top = 0;
    int bottom = 0;
    int left = 0;
    int right = 0;
    //int i = 1;
    //test

    printf("height: %i, width: %i\n", height, width);
    if (image[0][0].rgbtRed > 0) {
        printf("row does exist\n");
    } else {
        printf("row doesnt exist\n");
    }

    // Access each pixel
    for (int row=0; row<height; row++) {
        for (int column=0; column<width; column++) {
            //if top left
            //if top right
            //if bottom left
            //if bottom right
            //if top
            //if bottom

            //int copy_row[height];
            //int copy_col[width];
            //RGBTRIPLE image_copy[copy_row][copy_col] = image[row][column];

            // Access surounding 3x3 grid of current pixel.
            for (int local_row = row-1; local_row<=row+1; local_row++) {
                for (int local_column = column-1; local_column<=column+1; local_column++) {
                    int avg_red = 0;
                    int avg_green = 0;
                    int avg_blue = 0;
                    int num_of_pixels = 0;

                    // Check if top Left
                    if (local_row == -1 && local_column == -1) {
                        printf("Top Left \n");
                        for (int i = 0; i<=1; i++) {
                            for (int j=0; j<= 1; j++) {
                                avg_red += image[i][j].rgbtRed;
                                avg_green += image[i][j].rgbtGreen;
                                avg_blue += image[i][j].rgbtBlue;
                                num_of_pixels++;
                            }
                        }
                        printf("%i\n", num_of_pixels);
                        image[row][column].rgbtRed = avg_red/num_of_pixels;
                        image[row][column].rgbtGreen = avg_green/num_of_pixels;
                        image[row][column].rgbtBlue = avg_blue/num_of_pixels;

                    // Check if top Right
                    } else if (local_row == -1 && local_column == width) {
                        printf("Top Right \n");
                        for (int i=0; i<=1; i++) {
                            for (int j=width-2; j<= width-1; j++) {
                                avg_red += image[i][j].rgbtRed;
                                avg_green += image[i][j].rgbtGreen;
                                avg_blue += image[i][j].rgbtBlue;
                                num_of_pixels++;
                            }
                        }
                        printf("%i\n", num_of_pixels);
                        image[row][column].rgbtRed = avg_red/num_of_pixels;
                        image[row][column].rgbtGreen = avg_green/num_of_pixels;
                        image[row][column].rgbtBlue = avg_blue/num_of_pixels;

                    // Check if bottom Left
                    } else if (local_row == height && local_column == -1) {
                        printf("Bottom Left \n");
                    // Check if bottom Right
                    } else if (local_row == height && local_column == width) {
                        printf("Bottom Right \n");
                    // Check if along Top/Bottom
                    } else if (local_row == -1 || local_row == height) {
                        if (local_row == -1) {
                            top++;
                        } else {
                            bottom++;
                        }
                        //printf("Top/ Bottom \n");
                    // Check if along Right/Left
                    } else if (local_column == -1 || local_column == width) {
                        if (local_column == -1) {
                            //left++;
                        } else {
                            //right++;
                        }
                        //printf("Right/ Left \n");
                    // all the rest complete 3x3's (local_row >=0 && local_column >=0)
                    } else {
                        avg_red += image[local_row][local_column].rgbtRed;
                        avg_green += image[local_row][local_column].rgbtGreen;
                        avg_blue += image[local_row][local_column].rgbtBlue;
                    }

                    //if (local_row >=0 && local_column >=0) {
                    //    //printf("row does exist\n");
                    //    break;
//
                    //}
                //avg_red += image[local_row][local_column].rgbtRed;
                //avg_green += image[local_row][local_column].rgbtGreen;
                //avg_blue += image[local_row][local_column].rgbtBlue;
                }
            }
            //image[row][column].rgbtRed = avg_red/num_of_pixels;
            //image[row][column].rgbtGreen = avg_green/num_of_pixels;
            //image[row][column].rgbtBlue = avg_blue/num_of_pixels;
        }



    }
    printf("top: %i bottom: %i right: %i left: %i\n", top, bottom, left, right);
    return;
}