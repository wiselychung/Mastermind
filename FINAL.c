/* Programmed by : Wisely Chung
   Description : This is the code to the game Mastermind
   Last modified: April 9, 2015
   Version No. :  added random source code
                  arranged the logic of displaying G and W
                  added some other features such as : level of difficulty,  play again, instructions.
                  added cheat mode
                  added the choice of duplication of numbers
                  customizing colors
                  Finalize
                  arranged the brackets and parenthesises
                  
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include"mp.h"
#include<windows.h>
#include<time.h>


void instructions()
{
    printf("INSTRUCTIONS:\n");
    printf("\nG means the guess combination includes a peg with the correct number,");
    printf("\nAnd placed at the correct position.");
    printf("\nYou want to have four of light green pegs to win.");
    printf("\nW This means the guess combination includes a peg with the correct number,");
    printf("\nBut placed at the wrong position.");
    printf("\nA blank space means the guess number is incorrect");
}
void difficulty()
{
    printf("\n\neasy numbers    1-6");
    printf("\nmedium numbers  1-8");
    printf("\nhard numbers    1-10");
}

main()
{/*main*/
    int start;
    int secret1=0,secret2=0,secret3=0,secret4=0;
    int guess1,guess2,guess3,guess4;
    int i;
    int again;
    int level;
    int L;
    int Duplicate;
    int cheat;
    
    printf("WELCOME TO MASTERMIND!!!\n\n");
    instructions();
    difficulty();
    
    do
    {/*do*/
      printf("\n\nchoose level");
      printf("\n1 - Easy");
      printf("\n2 - Medium");
      printf("\n3 - Hard\n");
      scanf("%d",&level);
      if(level==1)
      L=6;
      else if (level==2)
      L=8;
      else if (level==3)
      L=10;
      printf("\nTurn on duplicate numbers?");
      printf("\n1-NO");
      printf("\n2-YES\n");
      scanf("\n%d",&Duplicate);
      printf("\n\npress 1 to start ");
      scanf("%d",&start);
      system("cls");
      if(start==1)
      {/*if start==1*/
        if(level==1||level==2||level==3)
        {/*if level==1,2,3*/
         if(Duplicate==1)
         {/*if DUPLICATE*/
          srand(time(NULL));
          secret1=rand()%L+1;
          secret2=rand()%L+1;
          while(secret2==secret1)
          {
          secret2=rand()%L+1;
          }
          secret3=rand()%L+1;
          while(secret3==secret2||secret3==secret1)
          {
          secret3=rand()%L+1;
          }
          secret4=rand()%L+1;
          while(secret4==secret3||secret4==secret2||secret4==secret1)
          {
          secret4=rand()%L+1; 
          }
          }/*if DUPLICATE*/
          else
          {
              srand(time(NULL));
              secret1=rand()%L+1;
              secret2=rand()%L+1;
              secret3=rand()%L+1;
              secret4=rand()%L+1;
          }
          }/*if level==1,2,3*/
          setcolor(LIGHTGRAY,BLACK);
          printf("Do you want to activate cheat mode?");
          printf("\n1-YES,2-NO\n");
          scanf("%d",&cheat);
          if(cheat==1)
          {
          setcolor(LIGHTRED,BLACK);
          printf("THE CODE IS: %d,%d,%d,%d\n",secret1,secret2,secret3,secret4);
          }
          else
          {
          setcolor(LIGHTRED,BLACK);
          printf("* * * *\n");
          }
          for(i=1;i<=10;i++)
          {/*(i=1;i<=10;i++)*/
             {
             setcolor(LIGHTGRAY,BLACK);
             printf("\n%d)enter your guess: ",i);
             scanf("%d %d %d %d",&guess1,&guess2,&guess3,&guess4);
             }
             if(guess1<=L&&guess2<=L&&guess3<=L&&guess4<=L)
             {/*if guess1<=L*/
                        if(guess1==secret1||guess1==secret2||guess1==secret3||guess1==secret4||guess2==secret1||guess2==secret2||guess2==secret3||guess2==secret4||guess3==secret1||guess3==secret2||guess3==secret3||guess3==secret4||guess4==secret1||guess4==secret2||guess4==secret3||guess4==secret4)    
                        {
                                  if(guess1==secret1)
                                  {
                                  setcolor(LIGHTGREEN,BLACK);
                                  printf("G ");
                                  }
                                  if(guess2==secret2)
                                  {
                                  setcolor(LIGHTGREEN,BLACK);
                                  printf("G ");
                                  }
                                  if(guess3==secret3)
                                  {
                                  setcolor(LIGHTGREEN,BLACK);
                                  printf("G ");
                                  }
                                  if(guess4==secret4)
                                  {
                                  setcolor(LIGHTGREEN,BLACK);
                                  printf("G ");
                                  }
                                  if(guess1==secret2||guess1==secret3||guess1==secret4)
                                  {
                                  setcolor(WHITE,BLACK);
                                  printf("W ");
                                  }
                                  if(guess2==secret1||guess2==secret3||guess2==secret4)
                                  {
                                  setcolor(WHITE,BLACK);
                                  printf("W ");
                                  }
                                  if(guess3==secret1||guess3==secret2||guess3==secret4)
                                  {
                                  setcolor(WHITE,BLACK);
                                  printf("W ");
                                  }
                                  if(guess4==secret1||guess4==secret2||guess4==secret3)
                                  {
                                  setcolor(WHITE,BLACK);
                                  printf("W ");
                                  }
                                  if(guess1==secret1&&guess2==secret2&&guess3==secret3&&guess4==secret4)
                                  {/*if correct all */
                                              printf("\n\n\nYou won the game in %d tries.",i);
                                              i=10;
                                  }/*if correct all */
                        }/*if(guess1==secret1||....*/        
              }/*if guess1<=L*/
              else
              printf("you have entered an invalid number");
          }/*for(i=1;i<=10;i++)*/
                       if(i==11)
                       {/*if i==10*/
                             if(guess1!=secret1||guess2!=secret2||guess3!=secret3||guess4!=secret4)
                             {/*if guess1 != secret1...*/
                                   if(cheat==1)
                                   {
                                               {
                                               setcolor(YELLOW,BLACK);
                                               printf("\n\n\n\n\n\n\n\n\n\n                           **************************");
                                               printf("\n                           *** CHEATERS NEVER WIN ***");
                                               printf("\n                           **************************\n\n\n\n\n");
                                               }
                                               {
                                               setcolor(LIGHTGRAY,BLACK);
                                               printf("\n\n\n\n\n\n\n");
                                               system("PAUSE");
                                               }
                                               printf("\nGAME OVER");
                                               printf("\nThe code is ");
                                               {
                                               setcolor(YELLOW,BLACK);
                                               printf("%d,%d,%d,%d",secret1,secret2,secret3,secret4);
                                               }
                                   }
                                   else
                                   {
                                               printf("\nGAME OVER");
                                               printf("\nThe code is ");
                                               {
                                               setcolor(YELLOW,BLACK);
                                               printf("%d,%d,%d,%d",secret1,secret2,secret3,secret4);
                                               }
                                   }
                             }/*if guess1 != secret1...*/
                             else if(guess1==secret1&&guess2==secret2&&guess3==secret3&&guess4==secret4)
                             {
                                  if(cheat==1)
                                  {
                                  printf("\nYOU CHEATER!!!");
                                  printf("\nThe code is ");
                                  {
                                  setcolor(YELLOW,BLACK);
                                  printf("%d,%d,%d,%d",secret1,secret2,secret3,secret4);
                                  }
                                  }
                                  else
                                  {
                                  printf("\nCONGRATULATIONS ! ! !");
                                  printf("\nThe code is ");
                                  {
                                  setcolor(YELLOW,BLACK);
                                  printf("%d,%d,%d,%d",secret1,secret2,secret3,secret4);
                                  }
                                  }
                             }
                       }/*if i==10*/
      {
      setcolor(LIGHTGRAY,BLACK);
      printf("\n\nGame Over");
      printf("\nDo you want to play again?");
      printf("\n\n1=yes");
      printf("\n2=no\n");
      scanf("\n%d",&again);
      }
      }/*if start==1*/
      }/*do*/
      while(again==1);
      printf("\nThank you for playing.");
getch();
}/*main*/


                                             
