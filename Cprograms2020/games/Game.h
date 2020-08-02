#pragma once
#include<stdlib.h>
#include <iostream>
#include <vector>
#include <memory>


using namespace std;

class NotValidPlayerMove {
	string description = "Invalid Move!!!";

public:
	string getDescription() const { return description; }
};

enum gameState { Tie, PlayerWins, ComputerWins, inProgress };

class Game {
public:
	Game() = default;
	~Game() = default;
	virtual void playerMove(std::vector<int> move) = 0;
	virtual void computerMove() = 0;
	virtual gameState getGameState() const = 0;	
};

class BoardGame : public Game {
public:
	BoardGame(int rows = 0, int colums = 0) : Game(){
		_rows = rows;
		_colums = colums;
	}
	virtual void playerMove(std::vector<int> move) = 0;
	virtual void computerMove() = 0;
	virtual gameState getGameState() const = 0;
	virtual bool gameIsOver() const = 0;
	virtual void gameroles() = 0;
	std::vector<std::vector<char>> getBoard() const { return _board; }

protected:
	int _rows;
	int _colums;
	std::vector<std::vector<char>> _board;
};


