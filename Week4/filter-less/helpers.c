#include "helpers.h"
#include <math.h>



// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, hei = height; i < hei; i++)
    {
        for (int k = 0, wid = width; k < wid; k++)
        {
            int Average_round = round((image[i][k].rgbtBlue + image[i][k].rgbtGreen + image[i][k].rgbtRed)/3.0);

            image[i][k].rgbtRed = Average_round;
            image[i][k].rgbtGreen = Average_round;
            image[i][k].rgbtBlue = Average_round;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, hei = height; i < hei; i++)
    {
        for (int k = 0, wid = width; k < wid; k++)
        {
            int Sepia_Red = round(image[i][k].rgbtBlue * 0.189 + image[i][k].rgbtGreen * 0.769 + image[i][k].rgbtRed * 0.393);
            if (Sepia_Red > 255)
            {
                Sepia_Red = 255;
            }
            int Sepia_Green = round(image[i][k].rgbtBlue * 0.168 + image[i][k].rgbtGreen * 0.686 + image[i][k].rgbtRed * 0.349);
            if (Sepia_Green > 255)
            {
                Sepia_Green = 255;
            }
            int Sepia_Blue = round(image[i][k].rgbtBlue * 0.131 + image[i][k].rgbtGreen * 0.534 + image[i][k].rgbtRed * 0.272);
            if (Sepia_Blue > 255)
            {
                Sepia_Blue = 255;
            }

            image[i][k].rgbtRed = Sepia_Red;
            image[i][k].rgbtGreen = Sepia_Green;
            image[i][k].rgbtBlue = Sepia_Blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     int n = width - 1;
     int tempR[width];
     int tempG[width];
     int tempB[width];
    for (int i = 0, hei = height; i < hei; i++)
    {
        for (int k = n; k >= 0; k--)
        {
             tempR[k] = image[i][k].rgbtRed;
             tempG[k] = image[i][k].rgbtGreen;
             tempB[k] = image[i][k].rgbtBlue;
        }
        for (int k = 0, wid = width; k < wid; k++)
        {
               image[i][k].rgbtRed = tempR[n - k];
               image[i][k].rgbtGreen = tempG[n - k];
               image[i][k].rgbtBlue = tempB[n - k];
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
     int AverageR;
     int AverageG;
     int AverageB;
     int tempR[height][width];
     int tempG[height][width];
     int tempB[height][width];
    for (int i = 0, hei = height; i < hei; i++)
    {
        for (int k = 0, wid = width; k < wid; k++)
        {
             tempR[i][k] = image[i][k].rgbtRed;
             tempG[i][k] = image[i][k].rgbtGreen;
             tempB[i][k] = image[i][k].rgbtBlue;
        }
    }
    for (int i = 0, hei = height; i < hei; i++)
    {
        for (int k = 0, wid = width; k < wid; k++)
        {
             float exist = 0.0;
              AverageR = 0;
              AverageG = 0;
              AverageB = 0;
              for (int c = -1; c < 2 ; c++)
              {
                  for (int d = -1; d < 2 ; d++)
                   {
                      int current_row = i + c;
                      int current_col = k + d;
                      if ( current_row >= 0 && current_row < height && current_col >= 0 && current_col < width )
                      {
                          AverageR += tempR[current_row][current_col];
                          AverageG += tempG[current_row][current_col];
                          AverageB += tempB[current_row][current_col];
                          exist++;
                      }
                   }

              }


              image[i][k].rgbtRed = round(AverageR / exist);
              image[i][k].rgbtGreen = round(AverageG / exist);
              image[i][k].rgbtBlue = round(AverageB / exist);

        }
    }
    return;

}

