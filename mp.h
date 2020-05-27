#ifndef __ALT_CONIO_H__
#define __ALT_CONIO_H__

#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

void gotoxy(int x,int y);
void setx(int x);
void sety(int y);
void setcolor(unsigned short color,unsigned short bg);
void delay(unsigned long milisec);
void setcursor(int ctype);
void clrscr(void);
int getx(void);
int gety(void);
int assert(int x);

/* Machine Project Functions */

/* MOTION */
int appleGotoXY(int x, int y);      // checks where the apple will land if it is moved to location (x, y).  Returns 0 if the apples lands on a wall, 1 if not
int getDirectionSnake();            // returns the snake's direction.  Possible return values include UP, DOWN, LEFT, RIGHT
void moveSnake(int step);           // moves the snakes by step number of positions
void moveApple(int x, int y);       // moves the apple to location (x, y)
void pointInDirection(int dir);     // makes the snake face dir.  dir could be UP, DOWN, LEFT or RIGHT


/* LOOKS */
void setBackground(unsigned short int color); // sets the background of the screen to color.  Possible values of color include 
                                              // BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, GRAY, LIGHTBLUE, LIGHTGREEN, 
                                              // TURQUOISE, LIGHTRED, PINK, YELLOW, WHITE

void showApple();        // makes the apple visible             
void hideApple();        // makes the apple invisible
void showSnake();        // draws the snake visible
void lengthenSnake();    // increases the length of the snake by 1
void setColorSnake(int color);     // the color of the snake to color.  Possible values of color include 
                                   // BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, GRAY, LIGHTBLUE, LIGHTGREEN, 
                                   // TURQUOISE, LIGHTRED, PINK, YELLOW, WHITE
void drawWall(int x1, int y1, int x2, int y2);  // draws a wall with the top left corner at (x1, x2) and the bottom right corner at (x2, y2)


/* SOUND */
void playSoundBeep();   // produces a beeping sound


/* SENSING */
char getKeypressed();   // returns the key pressed by the user
int touchingApple();    // returns 1 if the snake touched the apple, 0 if it did not
int touchingBody();     // returns 1 if the snake touched its own body, 0 if it did not
int touchingWall();     // returns 1 if the snake touched the wall, 0 if it did not


/* NUMBERS */
int pickRandom(int min, int max);  // generates a random number between min and max


/* VARIABLES */
void setScoreTo(int s);         // sets the score to s
void changeScoreBy(int x);      // increments the score by x.  If x is positive the score is increased.  If x is negative the score is decreased.
void showScore();               // shows the current score  
int getScore();                 // returns the current score
void initializeVariables();     // initializes map to empty, the snake's location to (1,1), the snake's length to 7, and the snake's direction to RIGHT 




#ifndef ALT_OUTPUT
int print(const char *x);
#endif

int align(int align,const char *str);


#define WIN_32_LEAN_AND_MEAN

#define UP 3
#define DOWN 4
#define FOREVER 1

#define KEY_HOME 71
#define KEY_UP 72
#define KEY_PGUP 73
#define KEY_LEFT 75
#define KEY_CENTER 76
#define KEY_RIGHT 77
#define KEY_END 79
#define KEY_DOWN 80
#define KEY_PGDN 81
#define KEY_INSERT 82
#define KEY_DELETE 83
#define KEY_F1 59
#define KEY_F2 60
#define KEY_F3 61
#define KEY_F4 62
#define KEY_F5 63
#define KEY_F6 64
#define KEY_F7 65
#define KEY_F8 66
#define KEY_F9 67
#define KEY_SPC 32
#define KEY_BACKSPACE 8
#define KEY_TAB 9
#define KEY_ENTER 13
#define KEY_ESC 27

#define LEFT 0
#define CENTER 1
#define RIGHT 2

#define _NOCURSOR 0
#define _SOLIDCURSOR 1
#define _MEDIUMCURSOR 2
#define _NORMALCURSOR 3

#ifdef ALT_OUTPUT
#define write(x) printf(x)
#else
#define write(x)
#endif

typedef struct
{
        short int x,y;
}coordType;

coordType snakeCoord[100], apple;
int snakeLength, snakeDir;
unsigned short int consoleMatrix[80][25], snakeColor, BGColor;
int score;

enum colors { BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, GRAY, LIGHTBLUE, LIGHTGREEN, TURQUOISE, LIGHTRED, PINK, YELLOW, WHITE };

union k
{
   char c;
   int i;
} key;


char getKeypressed()
{
     char ch;

     ch = getch();
     if (ch==0)     
         ch = getch();
     return ch;
     
}

void setScoreTo(int s)
{
    score = s;     
}

void changeScoreBy(int x)
{
  score += x;
  setcolor(WHITE, BGColor);
  gotoxy(66, 0); printf(" Score: %d ", score);
}

void showScore()
{
  setcolor(WHITE, BGColor);
  gotoxy(66, 0); printf(" Score: %d ", score);     
}

int getScore()
{
  return score;    
}
int appleGotoXY(int x, int y)
{
    if (  consoleMatrix[x][y] )
       return 0;           /* returns 0 if it lands on a wall */
    else
    {
      apple.x = x;
      apple.y = y;
      return 1;            /*returns 1 if it was successfully placed on the screen */
    }
    
}

void showApple()
{
     gotoxy(apple.x, apple.y) ;
     setcolor(RED, BGColor);
     printf("%c", 3);
}

void hideApple()
{
     gotoxy(apple.x, apple.y) ;
     setcolor(RED, BGColor);
     printf(" ");
}

void moveApple(int x, int y)
{
     hideApple();
     appleGotoXY(x, y);
     showApple();
}


int pickRandom(int min, int max)
{
   int num;
   
   srand(time(NULL));
   num = rand() % (max - min + 1) + min;
   
   return num;     
     
}


int touchingApple()
{ 
     int x,y;
    
     x = snakeCoord[snakeLength-1].x;
     y = snakeCoord[snakeLength-1].y;
    
     if (  apple.x == x && apple.y==y )   
         return 1;
     else
         return 0;
}

void pointInDirection(int dir)
{
      snakeDir = dir;           
}

void initializeVariables()
{
     int i,j ;
     
     for (i=0; i<80; i++)
       for (j=0; j<25; j++)
          consoleMatrix[i][j] = 0;
     
     apple.x = 1;
     apple.y = 1;
     
     snakeLength = 7;
     snakeColor = WHITE;
         
    BGColor = BLACK;
    snakeCoord[6].x  = 41; snakeCoord[0].y = 12;
    snakeCoord[5].x = 40; snakeCoord[1].y = 12;
    snakeCoord[4].x = 39; snakeCoord[2].y = 12;
    snakeCoord[3].x = 38; snakeCoord[3].y = 12;
    snakeCoord[2].x = 37; snakeCoord[4].y = 12;
    snakeCoord[1].x = 36; snakeCoord[5].y = 12;
    snakeCoord[0].x = 35; snakeCoord[6].y = 12;
    
    snakeDir = RIGHT;
     
}

int touchingBody()
{
    int x,y,i;
    
    x = snakeCoord[snakeLength-1].x;
    y = snakeCoord[snakeLength-1].y;
    
    for (i=0; i<snakeLength-1; i++)
        if (  x == snakeCoord[i].x && y == snakeCoord[i].y)
             return 1;
    
    return 0;
    
}

int touchingWall()
{
    int x,y;
    
    x = snakeCoord[snakeLength-1].x;
    y = snakeCoord[snakeLength-1].y;
    
    if (  consoleMatrix[x][y] )
      return 1;
    else
      return 0;
    
}

void swap(int *x, int *y)
{
  int t;
  t = *y;
  *y = *x;
  *x= t;
}

void drawWall(int x1, int y1, int x2, int y2)
{
     float m, b;
     int i,j, t;
     
     if (x1<0)  x1=0;
     if (x2<0)  x2 =0;
     if (x1>80) x1 =80;
     if (x2>80) x2 =80;

     if (y1<0) y1=0;
     if (y2<0) y2 =0;
     if (y1>25) y1 = 25;
     if (y2>25) y2 = 25;


       
   
   if (x1==x2)
   {
      if (y1>y2) swap(&y1,&y2);

      for (i=y1; i<=y2; i++)
      {
        gotoxy(x1, i); consoleMatrix[x1][i] = 1;
        printf("%c",219);
      }  
   }
   else if (y1==y2)
   {   
       if (x1>x2) swap(&x1,&x2);
  
      for (i=x1; i<=x2; i++)
      {
         gotoxy(i, y1); consoleMatrix[i][y1] = 1;
         printf("%c",219);
      }
   }
   else
   {
        m = (y2- y1)*1.0 / (x2- x1); 
        b = y1 - m * x1;
        
//        printf("%f",m);
        if ( m>=1)
        {
           if (y1>y2) swap(&y1,&y2);
           
           for ( i=y1; i<=y2; i++)
                {
                  t = (i - b) / m;
                  gotoxy(t, i);  consoleMatrix[t][i] = 1;
                  printf("%c",219);
                  }
        
        }
        else
        {
           if (x1>x2) swap(&x1,&x2);
           for ( i=x1; i<=x2; i++)
                {
                  t = m*i + b;
                  gotoxy(i, t); consoleMatrix[i][t] = 1;
                  printf("%c",219);
                  }
         }
   }
     
}

void showSnake()
{
     int i;
     
     setcolor(snakeColor, BGColor);
     for (i=0; i<snakeLength; i++)
     {
         gotoxy( snakeCoord[i].x, snakeCoord[i].y);
         printf("*");
     }
     
     
}

void lengthenSnake()
{
     int i;
     
     setcolor(snakeColor, BGColor);

     snakeCoord[snakeLength].x = snakeCoord[snakeLength-1].x;
     snakeCoord[snakeLength].y = snakeCoord[snakeLength-1].y;

     switch (snakeDir)
     {
            case RIGHT :                        
                         snakeCoord[snakeLength].x++;
                         if (snakeCoord[snakeLength].x>80) snakeCoord[snakeLength].x =0;
                         break;
            case LEFT : 
                         snakeCoord[snakeLength].x--;
                         if (snakeCoord[snakeLength].x<0) snakeCoord[snakeLength].x =79;
                         break;
           case UP :                        
                         snakeCoord[snakeLength].y--;
                         if (snakeCoord[snakeLength].y<0) snakeCoord[snakeLength].y =24;
                         break;
           case DOWN :                    
                         snakeCoord[snakeLength].y++;
                         if (snakeCoord[snakeLength].y>24) snakeCoord[snakeLength].y =0;
                         break;
     }     
    
    gotoxy(snakeCoord[snakeLength].x, snakeCoord[snakeLength].y);
    printf("*"); 
    snakeLength++;
}
int getDirectionSnake()
{
 return snakeDir  ;
}

void playSoundBeep()
{
     beep(500);     
}
void moveSnake(int step)
{
     int i;
     
     setcolor(snakeColor, BGColor);
     if (step <= 15)
     delay(310 - step*20);                         
     
     gotoxy( snakeCoord[0].x, snakeCoord[0].y);
     printf(" ");
     for (i=0; i<snakeLength-1; i++)
          snakeCoord[i] =  snakeCoord[i+1];  
          
     switch (snakeDir)
     {
            case RIGHT :     
                         snakeCoord[snakeLength-1].x++;
                         if (snakeCoord[snakeLength-1].x>80) 
                             snakeCoord[snakeLength-1].x =0;
                         break;
            case LEFT :                         
                         snakeCoord[snakeLength-1].x--;
                         if (snakeCoord[snakeLength-1].x<0) 
                             snakeCoord[snakeLength-1].x =79;
                         break;
           case UP : 
                         snakeCoord[snakeLength-1].y--;
                         if (snakeCoord[snakeLength-1].y<0) 
                             snakeCoord[snakeLength-1].y =24;
                         break;
           case DOWN : 
                         snakeCoord[snakeLength-1].y++;
                         if (snakeCoord[snakeLength-1].y>24) 
                             snakeCoord[snakeLength-1].y =0;
                         break;

     }     

     gotoxy( snakeCoord[snakeLength-1].x, snakeCoord[snakeLength-1].y);
     printf("*");
     
}


void setBackground(unsigned short int color)
{
     int i,j;
     BGColor = color;
     setcolor(WHITE, color);
     clrscr();
       
     for (i=1; i<=2000;i++)
          printf(" ");
     gotoxy(0,0); 
   
}


void setColorSnake(int color)
{
   snakeColor = color;                  
}



void gotoxy(int x,int y)
{
if (x!=79||y!=24)
{
setx(x);
sety(y);
}
}

void setx(int x)
{
COORD pos;
pos.X = x;
pos.Y = gety();
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void sety(int y)
{
COORD pos;
pos.X = getx();
pos.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void setcolor(unsigned short int color,unsigned short int bg)
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),((bg*16)+(color)));
}

void delay(unsigned long int milisec)
{
clock_t start,end,loop;
start = clock();
end = (start+milisec);

do {
loop = clock();
} while(loop<end);
}

void setcursor(int ctype)
{
CONSOLE_CURSOR_INFO type;
switch(ctype)
{
case _NOCURSOR:
type.bVisible = 0;
break;
case _SOLIDCURSOR:
type.dwSize = 100;
type.bVisible = 1;
break;
case _MEDIUMCURSOR:
type.dwSize = 50;
type.bVisible = 1;
break;
case _NORMALCURSOR:
type.dwSize = 1;
type.bVisible = 1;
break;
default:
type.dwSize = 1;
type.bVisible = 1;
break;
}
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&type);
}

void clrscr()
{
COORD pos;
COORD cs = { 0, 0 }; 
DWORD written;
CONSOLE_SCREEN_BUFFER_INFO window;
pos.X = 0;
pos.Y = 0;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&window);
FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE),' ',window.dwSize.X*window.dwSize.Y,cs,&written);
gotoxy(0,0);
}

int getx(void)
{
CONSOLE_SCREEN_BUFFER_INFO window;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&window);
return window.dwCursorPosition.X;
}

int gety(void)
{
CONSOLE_SCREEN_BUFFER_INFO window;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&window);
return window.dwCursorPosition.Y;
}

int assert(int x)
{
if(!(x)) return 1;
else if(x) return 0;
}

#ifndef ALT_OUTPUT
int print(const char *x)
{
printf("%s",x);
}
#endif



int align(int align,const char *str)
{
int x;
switch(align)
{
case 0:
x = (0);
break;
case 1:
x = (40-(strlen(str)/2));
break;
case 2:
x = (80-(strlen(str)));
break;
default:
return 1;
break;
}
if(strlen(str) > 79) {
}
else {
gotoxy(x,gety());printf("%s",str);
}
}

#endif
