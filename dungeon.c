#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <time.h>




int main(void) 
{
    double clock_time = 0.0;

    int game_tick = 0; // Variable to count the game_ticks
    bool exit = false; // Exit variable to know when to quit the programm
    bool redraw = true; // if true -> draw new Frame

    int rows = 24;
    int columns = 80;
    int pixels[24][80]; //Array for the pixels

    //initialize the pixelarray 
    for(int row = 0;row<rows;row++) 
    {
        for(int column = 0; column < columns; column++) 
        {
            pixels[row][column] = 0;
        }
    }

    pixels[12][40] = 1;

    clock_t begin = clock(); // initialize game clock to count frames 
    while (!exit)
    {
        if(redraw)
        {
            system("clear");
            for(int row = 0;row<rows;row++) 
            {
                for(int column = 0; column < columns; column++) 
                {
                    switch (pixels[row][column])
                    {
                    case 1:
                        printf("@");
                        break;
                    
                    default:
                        printf(" ");
                        break;
                    }
                }
                printf("\n");
            }
        }
        redraw = false;


        if (game_tick>100){
            exit = true;
        }

        if (game_tick>30)
        {
            pixels[12][40] = 0;
            pixels[6][40]  = 1;
        }

        
        clock_t end = clock();
        // calculate elapsed time by finding difference (end - begin) and
        // dividing the difference by CLOCKS_PER_SEC to convert to seconds
        clock_time = (double)(end - begin)/CLOCKS_PER_SEC;
        if(clock_time > 0.03)
        {
            begin = clock();
            game_tick++;
            redraw = true;
        }
        
        
    }
    

    
}





