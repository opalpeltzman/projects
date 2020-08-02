#include "gameController.h"


void GameController::play() {

	for (;;) {
		try {
			chooseGame();
			break;
		}
		catch (NotValidChooseGame & e) {
			cout << e.getDescription() << endl;
		}
	}

		newGame();

		for (;;) {
			try {
				_m_game->gameroles();
				break;
			}
			catch (NotValidPlayerMark & e) {
				_m_view->printErrors(e.getDescription());
			}
		}
		initializeBoard(_m_game->getBoard());

		while (!_m_game->gameIsOver()) {
			int row;
			int colum;
			std::vector<int> _pMove;

			for (;;) {
				try {
					_m_view->getcoordinate(row, colum);

					_pMove.push_back(row - 1);
					_pMove.push_back(colum - 1);


					_m_game->playerMove(_pMove);
					break;
				}
				catch (NotValidPlayerMove & e) {
					_m_view->printErrors(e.getDescription());
					_pMove.erase(_pMove.begin(), _pMove.begin() + 2);
				}
			}

			//after player move
			_m_view->printBoard(_m_game->getBoard());


			getGameState();									//print game state
			if (_m_game->gameIsOver())
				return;

			cout << "computer turn..." << endl;
			_m_game->computerMove();

			//after computer move
			_m_view->printBoard(_m_game->getBoard());

			getGameState();									//print game state
		}

}

void GameController::chooseGame() {
	cout << "WELCOME! please choose which game would you like to play:" << "\n";
	cout << "To play x/0 please press 1" << "\n";
	cout << "To play catch the bunny please press 2" << "\n";

	cin >> _theChoosenGame;
	if (_theChoosenGame != 1 && _theChoosenGame != 2) {
		throw NotValidChooseGame();
	}

	cout << "GREAT! please choose difficulty level:" << "\n";
	cout << "For level 1 please press 1" << "\n";
	cout << "For level 2 please press 2" << "\n";

	cin >> _gameLevel;	

	if (_gameLevel != 1 && _gameLevel != 2) {
		throw NotValidChooseGame();
	}


}

void GameController::newGame() {

	if (_theChoosenGame == 1) {
		if (_gameLevel == 1) 
			_m_game = make_shared <xoRand>();

		if (_gameLevel == 2)
			_m_game = make_shared<xoEducate>();

		_m_view = make_shared<xoConsole>();
	}

	if (_theChoosenGame == 2) {
		if(_gameLevel == 1)
			_m_game = make_shared <catchBunnyRand>();

		if (_gameLevel == 2)
			_m_game = make_shared<catchBunnyEducate>();

		_m_view = make_shared<catchBunnyConsole>();
	}

}

void GameController::initializeBoard(std::vector<std::vector<char>> board) const {
	_m_view->printBoard(board);
}

void GameController::getGameState() const {
	int state;
	state = _m_game->getGameState();

	if (state == 0)
		cout << "GAME OVER! its a tie" << endl << endl;

	if (state == 1)
		cout << "YOU WON! good job" << endl << endl;

	if (state == 2)
		cout << "GAME OVER! you lost this time :(" << endl << endl;

	if (state == 3)
		cout << "Game in Progress" << endl << endl;
}