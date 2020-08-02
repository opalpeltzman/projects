#include "catchTheBunny.h"

////////////////////////////////////////////////// catch the Bunny /////////////////////////////////////////////////////////////////////////////

catchBunny::catchBunny() : BoardGame(9, 9) {

	_numberOfPlayerTurns = 20;

	char num = ' ';

	for (int i = 0; i < _rows; i++) {

		std::vector<char> _tmp;

		for (int j = 0; j < _colums; j++) {
			_tmp.push_back(num);
	
		}
		_board.push_back(_tmp);

		
	}
	
	_board[8][5] = 'R';
	_board[0][1] = 'K';

	_playerMove.push_back(0);
	_playerMove.push_back(1);

	_computerMove.push_back(8);
	_computerMove.push_back(5);
	

}

void catchBunny::playerMove(std::vector<int> move) {
	
	_board[_playerMove[0]][_playerMove[1]] = ' ';								//clear the board;

	if (!isdigit(move[0]) == 0 || !isdigit(move[1]) == 0)
		throw NotValidPlayerMove();

	 else if (move[0] < 0 || move[0] > 8)
		throw NotValidPlayerMove();

	 else if (move[1] < 0 || move[1] > 8)
		 throw NotValidPlayerMove();

	 else if (_playerMove[0] - move[0] > 1 || move[0] - _playerMove[0] > 1)
		throw NotValidPlayerMove();

	else if (_playerMove[1] - move[1] > 1 || move[1] - _playerMove[1] > 1)
		throw NotValidPlayerMove();


	 else if (_playerMove[0] == move[0] && _playerMove[1] == move[1])			//can't stay in the same place
		throw NotValidPlayerMove();

	else if (_playerMove[0] == move[0] && _playerMove[1] - move[1] > 1)
		throw NotValidPlayerMove();

	else if (_playerMove[0] == move[0] && move[1] - _playerMove[1] > 1)
		throw NotValidPlayerMove();

	else if (_playerMove[1] == move[1] && _playerMove[0] - move[0] > 1)
		throw NotValidPlayerMove();

	else if (_playerMove[1] == move[1] && move[0] - _playerMove[0] > 1)
		throw NotValidPlayerMove();

	else if(_playerMove[0] > 8 || _playerMove[0] < 0)							//if the move is outside the board
		throw NotValidPlayerMove();

	else if (_playerMove[1] > 8 || _playerMove[1] < 0)							//if the move is outside the board
		throw NotValidPlayerMove();



	_playerMove[0] = move[0];
	_playerMove[1] = move[1];


	_board[move[0]][move[1]] = 'K';												//insert the new step
	_numberOfPlayerTurns--;
}

bool catchBunny::gameIsOver() const {
	gameState curentState = getGameState();

	if (_numberOfPlayerTurns == 0)
		return true;

	else if (curentState == 3)
		return false;

	else
		return true;
}

void catchBunny::gameroles(){
	cout << "GAME ROLES:" << endl;
	cout << "your goal is to catch the Rabbit" << endl;
	cout << "your letter on the board is 'K' and the Rabbit's is 'R'" << endl;
	cout << "you have only " << _numberOfPlayerTurns << " steps in order to catch the Rabbit" << endl;
	cout << "every move you make can be only one step" << endl;
	cout << "in order to enter the coordinate you want to move to, first enter ROW and then COLUM" << endl;
	cout << "the Row and Colum can be a number in the range of '1 - 9' " << endl;

	cout << "Good luck!" << endl;
}

gameState catchBunny::getGameState() const {
	if (_numberOfPlayerTurns == 0) {
		if (_playerMove[0] == _computerMove[0] && _playerMove[1] == _computerMove[1])
			return PlayerWins;

		else
			return ComputerWins;
	}

	if (_playerMove[0] == _computerMove[0] && _playerMove[1] == _computerMove[1])
		return PlayerWins;

	else
		return inProgress;
}

void catchBunnyRand::computerMove() {

	_board[_computerMove[0]][_computerMove[1]] = ' ';								//clear the board;

		if ((_computerMove[0] + 1) < 9 && _board[_computerMove[0] + 1][_computerMove[1]] != 'K'){

			_board[_computerMove[0] + 1][_computerMove[1]] = 'R';

			_computerMove[0] = _computerMove[0] + 1;
		}

		else if ((_computerMove[0] - 1) > -1 && _board[_computerMove[0] - 1][_computerMove[1]] != 'K'){

			_board[_computerMove[0] - 1][_computerMove[1]] = 'R';

			_computerMove[0] = _computerMove[0] - 1;
		}

		else if ((_computerMove[1] + 1) < 9 && _board[_computerMove[0]][_computerMove[1] + 1] != 'K') {

			_board[_computerMove[0]][_computerMove[1] + 1] = 'R';

			_computerMove[1] = _computerMove[1] + 1;
		}

		else if ((_computerMove[1] - 1) > -1 && _board[_computerMove[0]][_computerMove[1] - 1] != 'K') {

			_board[_computerMove[0]][_computerMove[1] - 1] = 'R';

			_computerMove[1] = _computerMove[1] - 1;
		}

}


void  catchBunnyEducate::computerMove() {
	int tmp = 1;

	_board[_computerMove[0]][_computerMove[1]] = ' ';								//clear the board;

	if (_computerMove[0] + 1 < 9 && _computerMove[0] - 1 > -1 && _computerMove[1] + 1 < 9 && _computerMove[1] - 1 > -1) {
		if (_board[_computerMove[0] + 1][_computerMove[1]] == 'K') {
			_board[_computerMove[0] - 1][_computerMove[1]] = 'R';

			_computerMove[0] = _computerMove[0] - 1;
			tmp--;
		}

		else if (_board[_computerMove[0] - 1][_computerMove[1]] == 'K') {
			_board[_computerMove[0] + 1][_computerMove[1]] = 'R';

			_computerMove[0] = _computerMove[0] + 1;
			tmp--;
		}

		else if (_board[_computerMove[0]][_computerMove[1] + 1] == 'K') {
			_board[_computerMove[0]][_computerMove[1] - 1] = 'R';

			_computerMove[1] = _computerMove[1] - 1;
			tmp--;
		}

		else if (_board[_computerMove[0]][_computerMove[1] - 1] == 'K') {
			_board[_computerMove[0]][_computerMove[1] + 1] = 'R';

			_computerMove[1] = _computerMove[1] + 1;
			tmp--;
		}
	}


	if (tmp == 1) {
		if ((_computerMove[0] + 1) < 9 && _board[_computerMove[0] + 1][_computerMove[1]] != 'K') {

			_board[_computerMove[0] + 1][_computerMove[1]] = 'R';

			_computerMove[0] = _computerMove[0] + 1;
		}

		else if ((_computerMove[0] - 1) > -1 && _board[_computerMove[0] - 1][_computerMove[1]] != 'K') {

			_board[_computerMove[0] - 1][_computerMove[1]] = 'R';

			_computerMove[0] = _computerMove[0] - 1;
		}

		else if ((_computerMove[1] + 1) < 9 && _board[_computerMove[0]][_computerMove[1] + 1] != 'K') {

			_board[_computerMove[0]][_computerMove[1] + 1] = 'R';

			_computerMove[1] = _computerMove[1] + 1;
		}

		else if ((_computerMove[1] - 1) > -1 && _board[_computerMove[0]][_computerMove[1] - 1] != 'K') {

			_board[_computerMove[0]][_computerMove[1] - 1] = 'R';

			_computerMove[1] = _computerMove[1] - 1;
		}
	}
}
