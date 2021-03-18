#include <stdio.h>
#include <stdlib.h>
struct board
    {
        int no_row;
        int no_column;
        char off_board[100][100],blank_board[100][100];
        int minefield[100][100];
        int totalmines;

    };
struct board b;
void print_minefield(void);
void stages( void );
void easy( void );
void medium( void );
void hard( void );
void custom(void);
void minefield_generator( void );
void print_minefield( void );
void guess( void );
void boom( void );
void print_off_board( void );
void win( void );
void play_again( void );
void game_over( void );

int x, y,z;
float diff;
int mines = 0;

int main()
{
    printf("\t\tWelcome to Minesweeper\n");
    stages();
    return 0;
}

void stages( void )
{

        printf("\t\tChoose a level\n 1->Easy\n 2->Medium\n 3->Hard\n 4->Custom\n ");
        scanf("%f", &diff);

    if( diff == 1 )
    {
        easy();
    }
    else if( diff == 2 )
    {
        medium();
    }
    else if( diff == 3 )
    {
        hard();
    }
    else if( diff == 4)
    {
        custom();
    }
}

void easy( void )
{
    b.no_row = 9;
    b.no_column= 9;
    b.totalmines = 10;
    minefield_generator();
    guess();
}

void medium( void )
{
    b.no_row = 8;
    b.no_column= 8;
    b.totalmines = 20;
    minefield_generator();
    guess();
}

void hard( void )

{
    b.no_row= 10;
    b.no_column= 10;
    b.totalmines = 30;
    minefield_generator();
    guess();
}

void custom( void )
{
    printf("\t\tPlease enter the size of the dimensions you want\n");
    printf("\t\t Enter the no of rows:\n");
    scanf("%d", &b.no_row);
    printf("\t\t Enter the no of column:\n");
    scanf("%d", &b.no_column);
    printf("\t\tNumber of mines you want to assign to the board:\n");
    scanf("%d", &b.totalmines);
    minefield_generator();
    guess();
}

void minefield_generator( void )
{
    int i,j;


   for(i=0;i<b.no_row;i++)
   {
       for(j=0;j<b.no_column;j++)
       {

            b.minefield[i][j] = '-';
            b.off_board[i][j] = b.minefield[i][j];
            b.blank_board[i][j] = b.minefield[i][j];
        }
    }
    mines = 0;
    while( mines < b.totalmines )
    {
        i = rand()%(b.no_row);
       // printf("i=%d",m);
        j = rand()%(b.no_column);
        if(b.minefield[i][j] != '*')
        {
        //printf("i=%d \t j=%d\n",i,j);
            b.minefield[i][j] = '*';
            //printf("\nminefield[i][j]=%c[%d][%d]\t",b[z].minefield[i][j]);
            //printf("minefield[i][j]=%c[%d][%d]",minefield[i][j]);
            b.blank_board[i][j] = b.minefield[i][j];
           // printf("blank_minefield[i][j]=%c[%d][%d]",blank_minefield[i][j]);
            mines++;
        }
    }

    for(i=0;i<b.no_row;i++)
    {
        for(j=0;j<b.no_column;j++)
        {

            if( b.minefield[i][j] != '*')
            {
                b.minefield[i][j] = 0;
            }
            if((b.minefield[i-1][j-1] == '*') && (b.minefield[i][j] != '*'))
            {
                b.minefield[i][j]++;
            }
            if((b.minefield[i-1][j] == '*') && (b.minefield[i][j] != '*'))
            {
                b.minefield[i][j]++;
            }
            if((b.minefield[i][j-1] == '*') && (b.minefield[i][j] != '*'))
            {
                b.minefield[i][j]++;
            }
            if((b.minefield[i-1][j+1] == '*') && (b.minefield[i][j] != '*'))
            {
                b.minefield[i][j]++;
            }
            if((b.minefield[i+1][j-1] == '*') && (b.minefield[i][j] != '*'))
            {
                b.minefield[i][j]++;
            }
            if((b.minefield[i+1][j] == '*') && (b.minefield[i][j] != '*'))
            {
                b.minefield[i][j]++;
            }
            if((b.minefield[i][j+1] == '*') && (b.minefield[i][j] != '*'))
            {
                b.minefield[i][j]++;
            }
            if((b.minefield[i+1][j+1] == '*') && (b.minefield[i][j] != '*'))
            {
                b.minefield[i][j]++;
            }
        }
    }
}

void print_minefield(void)
{
    int i = 0, j = 0, z = 0;
    while( z < b.no_row )
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

   for(i=0;i<b.no_row;i++)
    {
        printf("|%d|\t", i);
        for(j=0;j<b.no_column;j++)
        {
            if( b.off_board[i][j] == '-')
            {
                printf("|%c|\t", b.off_board[i][j]);

            }
            else if( b.minefield[i][j] == 0 )
            {
                b.off_board[i][j] = 'B';
                printf("|%c|\t", b.off_board[i][j]);
            }
            else
            {
                printf("|%d|\t", b.off_board[i][j]);

            }
        }
        printf("\n");
    }
}
void guess( void )
{
    int i,j,match=0;
    print_minefield();
   for(i=0;i<b.no_row;i++)
   {
       for(j=0;j<b.no_column;j++)
       {
            if(b.minefield[i][j] == b.off_board[i][j])
            {
                match++;
            }
        }
    }
    if( match == (( b.no_row* b.no_column ) - b.totalmines))
    {
        win();
    }
    printf("\nEnter the x value, then a space, then the y value:");
    scanf("%d %d", &x, &y);
    if( (x >=b.no_row ) || (x < 0) || (y < 0) || (y >= b.no_column) )
    {
        printf("\nPlease enter a value inside the grid\n");
        guess();
    }
    if( b.minefield[x][y] == '*' )
        boom();
    }
    if( b.off_board[x][y] != '-' )
    {
        printf("\nPlease enter a value that has not already been entered\n");
        guess();
    }

    else
    {
        b.off_board[x][y] = b.minefield[x][y];
        if(b.minefield[x][y] == 0 )
        {
            if( b.minefield[x-1][y-1] == 0 )
            {
                b.off_board[x-1][y] = b.minefield[x-1][y];
            }
            if( b.minefield[x-1][y] == 0 )
            {
                b.off_board[x-1][y] = b.minefield[x-1][y];
            }
            if( b.minefield[x][y-1] == 0 )
            {
                b.off_board[x][y-1] = b.minefield[x][y-1];
            }
            if( b.minefield[x-1][y+1] == 0 )
            {
                b.off_board[x-1][y+1] = b.minefield[x-1][y+1];
            }
            if( b.minefield[x+1][y-1] == 0 )
            {
                b.off_board[x+1][y-1] = b.minefield[x+1][y-1];
            }
            if( b.minefield[x+1][y] == 0 )
            {
                b.off_board[x+1][y] = b.minefield[x+1][y];
            }
            if( b.minefield[x][y+1] == 0 )
            {
                b.off_board[x][y+1] = b.minefield[x][y+1];
            }
            if( b.minefield[x+1][y+1] == 0 )
            {
                b.off_board[x+1][y+1] = b.minefield[x+1][y+1];
            }
        }
        guess();
    }
}

void boom( void )
{
    print_off_board();
    printf("\n\t\tYou hit a mine at %d,%d\n\t\tYOU LOSE!!!!", x, y);
    play_again();
}

void print_off_board( void )
{
    int i = 0, j = 0, k = 0;
  for(i=0;i<b.no_row;i++)
  {
        if( i == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", i);
    }
    printf("\n\n");

    for(j=0;j<b.no_column;j++)
    {
        printf("|%d|\t", j);
      for(i=0;i<b.no_row;i++)
      {
            printf("|%c|\t", b.blank_board[i][j]);
        }
        printf("\n");
    }
}


void win( void )
{
    printf("\n\n\n\t\t\tYOU WIN!!!!!\n\n\n");
    play_again();
}

void play_again( void )
{
    char option[2];
    printf("\n\t\tWould you like to play again(Y/N)?:");
    scanf("%c", &option[0]);
    if((option[0] == 'Y') || (option[0] == 'y'))
    {
        stages();
    }
    else if( (option[0] == 'N') || (option[0] == 'n'))
    {
        game_over();
    }
    else
    {
        printf("Please enter either Y or N");
        play_again();
    }
}

void game_over( void )
{
    printf("\n\n\t\tGame Over");
    exit(1);
}
