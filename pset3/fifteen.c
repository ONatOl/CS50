/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
int* init(int a, int b[DIM_MAX][DIM_MAX]);
void draw(int a, int b[DIM_MAX][DIM_MAX]);
bool move(int t, int a, int b[DIM_MAX][DIM_MAX]);
bool won(int a, int b[DIM_MAX][DIM_MAX]);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init(d, board);

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw(d, board);

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won(d, board))
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile, d, board))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
int* init(int df, int b[DIM_MAX][DIM_MAX]) 
{
    int step = df * df - 1;
    for (int i = 0; i < df; i++)
    {
        for (int j = 0; j < df; j++)
        {
            b[i][j] = step;
            step--;
        }
    }
    if (df % 2 == 0)
    {
        int temp = b[df-1][df-2];
        b[df-1][df-2] = b[df-1][df-3];
        b[df-1][df-3] = temp;
    }
    return *b;
}

/**
 * Prints the board in its current state.
 */
void draw(int df, int b[DIM_MAX][DIM_MAX])
{
    for (int i = 0; i < df; i++)
    {
        for (int j = 0; j < df; j++)
        {
            if (b[i][j] == 0)
                printf("  _ ");
            else 
                printf(" %2i ", b[i][j]);
            if (j < df - 1)
            {
                printf("|");
            }
        }
        printf("\n");
    }
    return;
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int t, int df, int b[DIM_MAX][DIM_MAX])
{
    int tLine, tColumn, bLine, bColumn;
    for (int i = 0; i < df; i++)
    {
        for (int j = 0; j < df; j++)
        {
            if (b[i][j] == t)
            {
                tLine = i;
                tColumn = j;
            }
            if (b[i][j] == 0)
            {
                bLine = i;
                bColumn = j;
            }
        }
    }
    if (((bLine==tLine) && ((tColumn==bColumn+1) || (tColumn==bColumn-1))) || ((bColumn==tColumn) && ((tLine==bLine+1) || (tLine==bLine-1))))
    {
        int temp1 = b[bLine][bColumn];
        b[bLine][bColumn] = b[tLine][tColumn];
        b[tLine][tColumn] = temp1;
        return true;
    }
    else
        return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(int df, int b[DIM_MAX][DIM_MAX])
{
    int w = 0;
    if (b[0][0] != 1)
        w++;
    for (int i = 0; i < df; i++)
    {
        for (int j = 0; j < df; j++)
        {
            if (! (((i == df - 1) && (j == df - 1)) || ((i == df - 1) && (j == df - 2))))
            {
                if (j == df -1)
                {
                    if (b[i][j] > b[i+1][0])
                        w++;
                }        
                else
                {
                    if (b[i][j] > b[i][j+1])
                        w++;
                }        
            }    
            
        }       
    }
    
    if (w == 0)
        return true;
    else 
        return false;
}
