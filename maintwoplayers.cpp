#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <MMsystem.h>
#include <unistd.h>
#include <conio.h>
#include <graphics.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

struct player
{
    char name[20];
    int score=0;
};

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void player2Move();
char checkWinner();
void printWinner2(char);

int main()
{
   system("color 0E");
   char winner = ' ';
   char response = ' ';
   int mode=2, turn =1;
   struct player p1;
   struct player p2;
   strcpy(p1.name, "Player 1");
   p1.score;
   p2.score;

   system("cls");

    do
   {
      winner = ' ';
      response = ' ';
      resetBoard();
      while(winner == ' ' && checkFreeSpaces() != 0)
      {

         printBoard();
         if (turn%2 ==0 && mode ==2)
            player2Move();
         if (turn%2 !=0)
            playerMove();
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }
         if (mode == 2)
         {
            closegraph();
            system("cls");
            printBoard();
            if (turn%2 ==0)
            playerMove();
            if (turn%2 !=0)
                player2Move();
            strcpy(p2.name, "Player 2");
         }

         system("cls");
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }
      }
      closegraph();
      system("cls");
      printBoard();
      if (mode == 2)
      {
        printWinner2(winner);
        if (winner == PLAYER)
        {
        //printf("\n\n%s\t%s", p1.name, p2.name);

        char str1[3], str2[3];
        //printf("\nWins: %d\t\tWins: %d", ++p1.score, p2.score);
        outtextxy(0,360,"Player 1       Player 2");
        outtextxy(0,380,"Wins:           Wins:");
        sprintf(str1,"%d",++p1.score);
        sprintf(str2,"%d",p2.score);
        outtextxy(45,380,str1);
        outtextxy(130,380,str2);
        }
        else if (winner == COMPUTER)
        {
        //printf("\n\n%s\t%s", p1.name, p2.name);
        //printf("\nWins: %d\t\tWins: %d", p1.score, ++p2.score);

        char str1[3], str2[3];
        outtextxy(0,360,"Player 1       Player 2");
        outtextxy(0,380,"Wins:           Wins:");
        sprintf(str1,"%d",p1.score);
        sprintf(str2,"%d",++p2.score);
        outtextxy(45,380,str1);
        outtextxy(130,380,str2);
        }
      }

      //printf("\nWould you like to play again? (Y/N): ");
      outtextxy(0,400,"\nWould you like to play again? (Y/N): ");
      scanf(" % c ");
      scanf("%c", &response);
      response = toupper(response);
      system("cls");
      turn= turn +1;
   } while (response == 'Y');
   //printf("Thanks for playing!");
   outtextxy(0,420,"\nThanks for playing!");

   sleep(2);


   return 0;
}

void resetBoard()
{
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         board[i][j] = ' ';
      }
   }
}
void printBoard()
{
           int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    line(150, 140, 450, 140);
    line(150, 250, 450, 250);
    line(250, 50, 250, 350);
    line(350, 50, 350, 350);

   //printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    setcolor(4);
    if (board[0][0] == COMPUTER)
         circle (195, 85, 40);
    if (board[0][1] == COMPUTER)
         circle (302, 85, 40);
    if (board[0][2] == COMPUTER)
         circle (405, 85, 40);
    if (board[1][0] == COMPUTER)
         circle (195, 195, 40);
    if (board[1][1] == COMPUTER)
         circle (302, 195, 40);
    if (board[1][2] == COMPUTER)
         circle (405, 195, 40);
    if (board[2][0] == COMPUTER)
         circle (195, 305, 40);
    if (board[2][1] == COMPUTER)
         circle (302, 305, 40);
    if (board[2][2] == COMPUTER)
         circle (405, 305, 40);

    setcolor(2);
    if (board[0][0] == PLAYER)
        {line (150, 140, 250, 50); line (150, 50, 250, 140);}
    if (board[0][1] == PLAYER)
        {line (250, 140, 350, 50); line (250, 50, 350, 140);}
    if (board[0][2] == PLAYER)
        {line (350, 140, 450, 50); line (350, 50, 450, 140);}
    if (board[1][0] == PLAYER)
        {line (150, 250, 250, 140); line (150, 140, 250, 250);}
    if (board[1][1] == PLAYER)
        {line (250, 250, 350, 140); line (250, 140, 350, 250);}
    if (board[1][2] == PLAYER)
        {line (350, 250, 450, 140); line (350, 140, 450, 250);}
    if (board[2][0] == PLAYER)
        {line (150, 350, 250, 250); line (150, 250, 250, 350);}
    if (board[2][1] == PLAYER)
        {line (250, 350, 350, 250); line (250, 250, 350, 350);}
    if (board[2][2] == PLAYER)
        {line (350, 350, 450, 250); line (350, 250, 450, 350);}
    setcolor(15);
/*
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
   printf("\n");*/
}
int checkFreeSpaces()
{
   int freeSpaces = 9;

   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         if(board[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}
void playerMove()
{
   int x;
   int y;
   char z;
   do
   {
      //printf("(Player 1) Enter position number (1-9):");
        outtextxy(0,360,"(Player 1) Enter position number (1-9):");
      scanf(" %c", &z);
      if (z=='1')
      {x=0; y=0;}
      if (z=='2')
      {x=0; y=1;}
      if (z=='3')
      {x=0; y=2;}
      if (z=='4')
      {x=1; y=0;}
      if (z=='5')
      {x=1; y=1;}
      if (z=='6')
      {x=1; y=2;}
      if (z=='7')
      {x=2; y=0;}
      if (z=='8')
      {x=2; y=1;}
      if (z=='9')
      {x=2; y=2;}

      if(board[x][y] != ' ')
      {
         //printf("Invalid Move!\n");
        outtextxy(0,380,"Invalid Move!");
      }
      else
      {
         board[x][y] = PLAYER;
         break;
      }
   } while (board[x][y] != ' ');

}
void player2Move()
{
   int x;
   int y;
   char z;

   do
   {
      //printf("(Player 2) Enter position number (1-9):");
      outtextxy(0,360,"(Player 2) Enter position number (1-9):");
      scanf(" %c", &z);
      if (z=='1')
      {x=0; y=0;}
      if (z=='2')
      {x=0; y=1;}
      if (z=='3')
      {x=0; y=2;}
      if (z=='4')
      {x=1; y=0;}
      if (z=='5')
      {x=1; y=1;}
      if (z=='6')
      {x=1; y=2;}
      if (z=='7')
      {x=2; y=0;}
      if (z=='8')
      {x=2; y=1;}
      if (z=='9')
      {x=2; y=2;}

      if(board[x][y] != ' ')
      {
         //printf("Invalid move!\n");
        outtextxy(0,380,"Invalid Move!");
      }
      else
      {
         board[x][y] = COMPUTER;
         break;
      }
   } while (board[x][y] != ' ');

}
char checkWinner()
{
   //check rows
   for(int i = 0; i < 3; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
         return board[i][0];
      }
   }
   //check columns
   for(int i = 0; i < 3; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
         return board[0][i];
      }
   }
   //check diagonals
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {
      return board[0][0];
   }
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {
      return board[0][2];
   }

   return ' ';
}
void printWinner2(char winner)
{
   if(winner == PLAYER)
   {
      //printf("PLAYER 1 WINS!");
      outtextxy(0,400,"PLAYER 1 WINS!");

      sleep(2);

   }
   else if(winner == COMPUTER)
   {
      //printf("PLAYER 2 WINS!");
      outtextxy(0,400,"PLAYER 2 WINS!");

      sleep(2);
   }
   else{
      //printf("IT'S A TIE!");
      outtextxy(0,400,"IT'S A TIE!!");

      sleep(2);

   }
}
