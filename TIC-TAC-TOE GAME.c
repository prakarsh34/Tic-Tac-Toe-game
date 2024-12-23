/* TIC-TAC-TOE 
 Prakarsh Awasthi
   23-12-2024 */

#include <stdio.h>
#include<time.h>
#define SIZE 3

void printBoard(char board[SIZE][SIZE]);
int checkWinner(char board[SIZE][SIZE], char player);
int isFull(char board[SIZE][SIZE]);
void ticTacToe();
int getValidInput(); 

int main() 
{
    ticTacToe();
    return 0;
}

void printBoard(char board[SIZE][SIZE]) // printing board
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
}

int checkWinner(char board[SIZE][SIZE], char player) // checking left to right and right to left
{
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) 
        {
            return 1;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) // checking for diagonals 
    {
        return 1;
    }

    return 0;
}

int isFull(char board[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            if (board[i][j] == ' ') // checking if the board is full at a particular position
            {
                return 0;
            }
        }
    }
    return 1;
}

int getValidInput() 
{
    int input;
    while (scanf("%d", &input) != 1 || input < 0 || input >= SIZE) 
    {
        while (getchar() != '\n');
        printf("Invalid input! Please enter a number between 0 and 2: "); // taking input
    }
    return input;
}

void ticTacToe() // main game function which is called at the starting of the code 
{
    char board[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; 
    char players[] = {'X', 'O'}; 
    int currentPlayer = 0; 
    int row, col;

    printf("Welcome to Tic-Tac-Toe!\n");

    while (1) // while true, the input is printed and shown
    {
        printBoard(board);
        printf("Player %d's turn (%c):\n", currentPlayer + 1, players[currentPlayer]);

        printf("Enter row (0, 1, 2): ");
        row = getValidInput();
        printf("Enter column (0, 1, 2): ");
        col = getValidInput();

        if (board[row][col] != ' ') 
        {
            printf("Invalid move! That position is already taken. Try again.\n");
            continue; 
        }

        board[row][col] = players[currentPlayer];

        if (checkWinner(board, players[currentPlayer])) // checking winner 
        {
            printBoard(board);
            printf("Player %d (%c) wins!\n", currentPlayer + 1, players[currentPlayer]);
            break;
        }

        if (isFull(board)) // if no winner and board is full then draw
        {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = 1 - currentPlayer; // switching player 1 and 2 on the basis of inputs
    } // no return 0 because code opened in the voic function
}








