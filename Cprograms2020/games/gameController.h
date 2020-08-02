#pragma once
#include<stdlib.h>
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "view.h"
#include "Game.h"
#include "catchTheBunny.h"
#include "xo.h"

class NotValidChooseGame {
	string description = "Invalid Game Input!!!";

public:
	string getDescription() const { return description; }
};

using namespace std;

class GameController{
public:
	GameController() : _theChoosenGame(0), _gameLevel(0) {}
	~GameController() = default;
	void chooseGame();
	void play();						
	void newGame();
	void initializeBoard(std::vector<std::vector<char>> board) const ;
	void getGameState() const;


private:
	int _theChoosenGame;
	int _gameLevel;
	std::shared_ptr<BoardGame> _m_game;
	std::shared_ptr<view> _m_view;

};


