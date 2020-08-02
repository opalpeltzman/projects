#pragma once
#include "Game.h"

////////////////////////////////////////////////// x\0 /////////////////////////////////////////////////////////////////////////////

class NotValidPlayerMark {
	string description = "Invalid Mark for player!!!";

public:
	string getDescription() const { return description; }
};

class xo : public BoardGame {
public:
	xo();
	virtual void computerMove() = 0;
	virtual void playerMove(std::vector<int> move);
	virtual bool gameIsOver() const;
	virtual void gameroles();
	virtual gameState getGameState() const;

protected:
	char _player;
	char _computer;
};

class xoRand : public xo {
public:
	xoRand() : xo() {}
	virtual void computerMove();
};

class xoEducate : public xo {
public:
	xoEducate() : xo() {}
	virtual void computerMove();
};