#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

void displayBoard()
{
    cout << "\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << board[i][j] << " ";
            if (j < SIZE - 1)
                cout << "| ";
        }
        cout << "\n";
        if (i < SIZE - 1)
            cout << "--+---+--\n";
    }
    cout << "\n";
}

bool placeMarker(int slot)
{
    int row = (slot - 1) / SIZE;
    int col = (slot - 1) % SIZE;

    if (slot < 1 || slot > 9 || board[row][col] == 'X' || board[row][col] == 'O')
    {
        return false;
    }

    board[row][col] = currentPlayer;
    return true;
}

bool checkWin()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    return false;
}

bool checkDraw()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void resetBoard()
{
    char slot = '1';
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = slot++;
        }
    }
    currentPlayer = 'X';
}

int main()
{
    char playAgain;
    do
    {
        resetBoard();
        bool gameWon = false;
        bool gameDraw = false;

        while (!gameWon && !gameDraw)
        {
            displayBoard();
            int slot;
            cout << "Player " << currentPlayer << ", enter a slot (1-9): ";
            cin >> slot;

            if (placeMarker(slot))
            {
                gameWon = checkWin();
                gameDraw = checkDraw();

                if (!gameWon && !gameDraw)
                {
                    switchPlayer();
                }
            }
            else
            {
                cout << "Invalid move. Try again.\n";
            }
        }

        displayBoard();
        if (gameWon)
        {
            cout << "Player " << currentPlayer << " wins!\n";
        }
        else if (gameDraw)
        {
            cout << "The game is a draw!\n";
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
