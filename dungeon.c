#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <time.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>


int game_tick = 0; // Variable to count the game_ticks
int keyinput;

const int rows = 16;
const int columns = 40;
//int pixels[24][80]; //Array for the pixels
int pixels[16][40]; //Array for the pixels

void init_pixels()
{
    //initialize the pixelarray 
    for(int row = 0;row<rows;row++) 
    {
        for(int column = 0; column < columns; column++) 
        {
            pixels[row][column] = 32;
        }
    }
    return;
}

/*
int kbhit() {
    static const int STDIN = 0;
    static int initialized = 0;

    if (! initialized) {
        // Use termios to turn off line buffering
        struct termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = 1;
    }

    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}

int  getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}  */

int main(void) 
{
    double clock_time = 0.0;

    bool exit = false; // Exit variable to know when to quit the programm
    bool redraw = true; // if true -> draw new Frame


    system ("/bin/stty raw"); // deactivates ENTER-Mode

    init_pixels();

    //pixels[12][40] = 64; //sets player postion
    pixels[4][5] = 64; //sets player postion

    clock_t begin = clock(); // initialize game clock to count frames
    while (!exit)
    {
        /*
        if (kbhit())
        {
            keyinput = getch();
            redraw = true;       
        } 
        
        if(keyinput=getch()=='c')
        {
            exit = true;
        } */
        /*
        if(keyinput=getchar()=='c')
        {
            exit = true;
        } */

        //system("clear");
        if(redraw)
        {
            redraw = false;
            system("clear");
            //printf("\e[1;1H\e[2J");
            //printf ("\033[?12l");
            for(int row = 0;row<rows;row++) 
            {
                for(int column = 0; column < columns-1; column++) 
                {
                    printf("%c" , pixels[row][column]);
                }
                printf("a");
                printf("\n");
            }
            
            //printf("%c" , pixels[4][5]);
        }
        else{}
        
      
        clock_t end = clock();
        // calculate elapsed time by finding difference (end - begin) and
        // dividing the difference by CLOCKS_PER_SEC to convert to seconds
        clock_time = (double)(end - begin)/CLOCKS_PER_SEC;
        if(clock_time > 0.5)
        {
            begin = clock();
            game_tick++;
            redraw = true;
            pixels[4][5]++; //sets player postion
        }

        //sleep(0.5);
    }

    system ("/bin/stty cooked"); //back to ENTER Mode
    printf("\n");
    return 0;
    
}





