#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <MMsystem.h>
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
void computerMove();
char checkWinner();
void printWinner(char);

int max(int a , int b ){
if (a>b){
    return a;
}else{
return b;
}
}
int min(int a , int b ){
if (a>b){
    return b;
}else{
return a;
}
}
bool isMovesLeft(char board[3][3])
{
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board[i][j]==' ')
                return true;
    return false;
}

int evaluate(char b[3][3])
{
    for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] && b[row][1]==b[row][2])
        {
            if (b[row][0]==COMPUTER)
                return +10;
            else if (b[row][0]==PLAYER)
                return -10;
        }
    }

    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] && b[1][col]==b[2][col])
        {
            if (b[0][col]==COMPUTER)
                return +10;

            else if (b[0][col]==PLAYER)
                return -10;
        }
    }

    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==COMPUTER)
            return +10;
        else if (b[0][0]==PLAYER)
            return -10;
    }

    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==COMPUTER)
            return +10;
        else if (b[0][2]==PLAYER)
            return -10;
    }

    return 0;
}

int minimax(char board[3][3], int depth, bool isMax)
{
    int score = evaluate(board);

    if (score == 10)
        return score;

    if (score == -10)
        return score;

    if (isMovesLeft(board)==false)
        return 0;

    if (isMax)
    {
        int best = -1000;

        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (board[i][j]==' ')
                {
                    board[i][j] = COMPUTER;

                    best = max( best,
                        minimax(board, depth+1, !isMax) );

                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }

    else
    {
        int best = 1000;

        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (board[i][j]==' ')
                {
                    board[i][j] = PLAYER;

                    best = min(best,
                           minimax(board, depth+1, !isMax));

                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

char MovefindBestMove(char board[3][3])
{

    int bestVal = -1000;

    int ro = -1;
    int co = -1;

    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            if (board[i][j]==' ')
            {
                board[i][j] = COMPUTER;

                int moveVal = minimax(board, 0, false);

                board[i][j] = ' ';

                if (moveVal > bestVal)
                {

                    ro = i;
                    co = j;
                    bestVal = moveVal;
                }
            }
        }
    }

board[ro][co] = COMPUTER;

    return board[ro][co];
}

int main()
{
   system("color 0E");
   char winner = ' ';
   char response = ' ';
   int randomnumber;
   int mode=3, turn =1;
   struct player p1;
   struct player p2;
   strcpy(p1.name, "Player 1");
   p1.score;
   p2.score;
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");

   system("cls");

    do
   {
      winner = ' ';
      response = ' ';
      resetBoard();
      while(winner == ' ' && checkFreeSpaces() != 0)
      {

         printBoard();
         if (turn%2 ==0 && mode ==1)
            computerMove();
         if (turn%2 ==0 && mode ==3)
            char besto = MovefindBestMove( board);
            printBoard();
            if (turn%2 ==0 && mode ==2)
            {
                randomnumber = rand() % 10;
                if (randomnumber == 1||randomnumber==3||randomnumber==5||randomnumber==7||randomnumber==9)
                computerMove();
            else
                {
                char besto = MovefindBestMove( board);
                printBoard();
                }
            }


         if (turn%2 !=0)
            playerMove();
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }

         if (mode == 1)
         {
            closegraph();
            system("cls");
            printBoard();
            if (turn%2 ==0)
                playerMove();
            if (turn%2 !=0)
                computerMove();
            strcpy(p2.name, "Computer");
         }

         if (mode == 3)
         {
            closegraph();
            system("cls");
            printBoard();
            if (turn%2 ==0)
                playerMove();
            if (turn%2 !=0)
                char besto = MovefindBestMove( board);
                printBoard();;
            strcpy(p2.name, "Computer");
         }
         if (mode == 2)
         {
            closegraph();
            system("cls");
            printBoard();
            if (turn%2 ==0)
                playerMove();
            if (turn%2 !=0 && mode ==2)
            {
                randomnumber = rand() % 10;
                if (randomnumber == 1||randomnumber==3||randomnumber==5||randomnumber==7||randomnumber==9)
                    computerMove();
            else
            {
                char besto = MovefindBestMove( board);
                printBoard();
            }
            strcpy(p2.name, "Computer");
         }}

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

      if (mode == 1||mode == 2||mode==3)
      {
        printWinner(winner);
        if (winner == PLAYER)
        {
            char str1[3], str2[3];
            outtextxy(0,360,"Player 1       Computer");
            outtextxy(0,380,"Wins:           Wins:");
            sprintf(str1,"%d",++p1.score);
            sprintf(str2,"%d",p2.score);
            outtextxy(45,380,str1);
            outtextxy(130,380,str2);
        }
        else if (winner == COMPUTER)
        {
            char str1[3], str2[3];
            outtextxy(0,360,"Player 1       Computer");
            outtextxy(0,380,"Wins:           Wins:");
            sprintf(str1,"%d",p1.score);
            sprintf(str2,"%d",++p2.score);
            outtextxy(45,380,str1);
            outtextxy(130,380,str2);
        }
      }

      outtextxy(0,400,"\nWould you like to play again? (Y/N): ");
      scanf(" % c ");
      scanf("%c", &response);
      response = toupper(response);
      system("cls");
      turn= turn +1;
   } while (response == 'Y');

   FILE *score=fopen("Scoresheet.txt","w");
   fprintf(score,"Score:\nPlayer1: %d\nComputer: %d\n",p1.score,p2.score);
   fclose(score);
   outtextxy(0,420,"\nThanks for playing!");

   Sleep(2000);

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

        setcolor(9);
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
        outtextxy(0,380,"Invalid Move!");
      }
      else
      {
         board[x][y] = PLAYER;
         break;
      }
   } while (board[x][y] != ' ');

}
void computerMove()
{
   srand(time(0));
   int x;
   int y;

   if(checkFreeSpaces() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;
      } while (board[x][y] != ' ');

      board[x][y] = COMPUTER;
   }
   else
   {
      printWinner(' ');
   }
}
char checkWinner()
{
   for(int i = 0; i < 3; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
         return board[i][0];
      }
   }
   for(int i = 0; i < 3; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
         return board[0][i];
      }
   }
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
void printWinner(char winner)
{
   if(winner == PLAYER)
   {
      outtextxy(0,400,"YOU WIN!");
      Sleep(2000);
   }
   else if(winner == COMPUTER)
   {
      outtextxy(0,400,"YOU LOSE!");
      Sleep(2000);
   }
   else{
      outtextxy(0,400,"IT'S A TIE!!");
      Sleep(2000);
   }
}
