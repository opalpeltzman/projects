#pragma once
#include "Game.h"


////////////////////////////////////////////////// catch the Bunny /////////////////////////////////////////////////////////////////////////////

class catchBunny : public BoardGame {
public:
	catchBunny();
	virtual void computerMove() = 0;
	virtual void playerMove(std::vector<int> move);
	virtual bool gameIsOver() const;
	virtual void gameroles();
	virtual gameState getGameState() const;
protected:
	int _numberOfPlayerTurns;
	std::vector<int> _playerMove;
	std::vector<int> _computerMove;
};

class catchBunnyRand : public catchBunny {
public:
	catchBunnyRand() : catchBunny() {};
	virtual void computerMove();
};

class catchBunnyEducate : public catchBunny {
public:
	catchBunnyEducate() : catchBunny() {};
	virtual void computerMove();
};
