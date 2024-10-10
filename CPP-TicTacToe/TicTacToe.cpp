#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe()
    : m_currentPlayer(0), m_gameOver(false)
{
    for (int i = 0; i < 9; i++) 
    {
        m_Board[i] = ' ';
    }
}

void TicTacToe::TakeTurn()
{
    if (m_gameOver) 
    {
        std::cout << "Game is already over.\n";
        return;
    }

    int position;
    char player = (m_currentPlayer == 0) ? 'X' : 'O';

    while (true) 
    {
        std::cout << "Player " << player << ", enter a position (1-9): ";
        std::cin >> position;

        if (position >= 1 && position <= 9 && m_Board[position - 1] == ' ') 
        {
            m_Board[position - 1] = player;
            break;
        }

        else 
        {
            std::cout << "Invalid Position, Try again.\n";
        }
    }

    if (CheckWin())
    {
        m_gameOver = true;
        std::cout << "Player " << player << " wins!\n";
    } else if (IsBoardFull())

    {
        m_gameOver = true;
        std::cout << "Tie!\n";
    } else 

    {
        SwitchPlayer();
    }
}

void TicTacToe::SwitchPlayer()
{
    m_currentPlayer = 1 - m_currentPlayer; // Switch players after each turn.
}

bool TicTacToe::CheckWin()
{
	system("cls"); // clear the console

    char player = (m_currentPlayer == 0) ? 'X' : 'O';

    // check if a player has won with columns, rows, or diagonals.
    for (int i = 0; i < 3; i++) 
    {

        if (m_Board[i * 3] == player && m_Board[i * 3 + 1] == player && m_Board[i * 3 + 2] == player)
            return true;

        if (m_Board[i] == player && m_Board[i + 3] == player && m_Board[i + 6] == player)
            return true;
    }

    if (m_Board[0] == player && m_Board[4] == player && m_Board[8] == player)
        return true;

    if (m_Board[2] == player && m_Board[4] == player && m_Board[6] == player)
        return true;

    return false;
}

void TicTacToe::Display() const
{
    // Displaying the initial board
    std::cout << "Tic Tac Toe Game:\n";
    std::cout << "Player 0 (X) - Player 1 (O)\n\n";

    std::cout << "     |     |     \n";
    std::cout << "  " << m_Board[0] << "  |  " << m_Board[1] << "  |  " << m_Board[2] << "\n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << m_Board[3] << "  |  " << m_Board[4] << "  |  " << m_Board[5] << "\n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << m_Board[6] << "  |  " << m_Board[7] << "  |  " << m_Board[8] << "\n";
    std::cout << "     |     |     \n\n";
}

bool TicTacToe::IsBoardFull() const
{
	// Check if board is full (no empty spaces and no player has won)
    for (int i = 0; i < 9; ++i) 
    {
        if (m_Board[i] == ' ') 
        {
            return false;
        }
    }
    return true;
}

bool TicTacToe::IsGameOver() const
{
    return m_gameOver;
}
