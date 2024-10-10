#pragma once
#include "Game.h"

class TicTacToe : public Game
{
public:
    TicTacToe();
    virtual bool IsGameOver() const override;
    virtual void TakeTurn() override;
    virtual void Display() const override;

private:
    bool CheckWin();
    void SwitchPlayer();
    bool IsBoardFull() const;

    char m_Board[9];
    int m_currentPlayer; 
    bool m_gameOver;
};
