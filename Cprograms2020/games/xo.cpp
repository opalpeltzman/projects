#include "xo.h"


////////////////////////////////////////////////// x\0 /////////////////////////////////////////////////////////////////////////////
xo::xo() : BoardGame(3, 3) {

	char num = '1';

	for (int i = 0; i < _rows; i++) {

		std::vector<char> _tmp;

		for (int j = 0; j < _colums; j++) {
			_tmp.push_back(num);
			num += 1;
		}
		_board.push_back(_tmp);
	}

}

void xo::playerMove(std::vector<int> move) {

	//if (!gameIsOver()) {

		if (!isdigit(move[0]) == 0 || !isdigit(move[1]) == 0)
			throw NotValidPlayerMove();

		if (move[0] < 0 || move[0] > 2)
			throw NotValidPlayerMove();

		else if (move[1] < 0 || move[1] > 2)
			throw NotValidPlayerMove();

		else if (_board[move[0]][move[1]] == _player || _board[move[0]][move[1]] == _computer) {	//the place is already taken
			throw NotValidPlayerMove();
		}

		

		_board[move[0]][move[1]] = _player;
		return;
	//}
	//throw "the game is over";
}

bool xo::gameIsOver() const {
	gameState curentState;
	curentState = getGameState();
	if (curentState == 3)
		return false;

	else
		return true;
}

void xo::gameroles(){
	cout << "GAME ROLES:" << endl;
	cout << "you'r goal is to place three of your marks in a horizontal, vertical, or diagonal row" << endl;
	cout << "the player with the mark 'X' start first" << endl;
	cout << "in order to enter the coordinate you want to move to, first enter ROW and then COLUM" << endl;
	cout << "the Row and Colum can be a number in the range of '1 - 3' " << endl;
	cout << "please enter your player mark X or O :" << "\n";
	cin >> _player;

	if (_player != 'X' && _player != 'O' && _player != 'x' && _player != 'o') {
		throw NotValidPlayerMark();
	}
	cout << "Good luck!" << endl;

	if (_player == 'X' || _player == 'x')
		_computer = 'O';

	else if (_player == 'O' || _player == 'o') {
		_computer = 'X';
		cout << "computer turn..." << endl;
		computerMove();
	}
	
}

gameState xo::getGameState() const {
	if (_board[0][0] == _board[0][1] && _board[0][1] == _board[0][2]) {			//row 1 
		if (_board[0][0] == _player)
			return PlayerWins;
		else
			return ComputerWins;
	}

	else if (_board[1][0] == _board[1][1] && _board[1][1] == _board[1][2]) {	//row 2
		if (_board[1][0] == _player)
			return PlayerWins;
		else
			return ComputerWins;
	}

	else if (_board[2][0] == _board[2][1] && _board[2][1] == _board[2][2]) {	//row 3
		if (_board[2][0] == _player)
			return PlayerWins;
		else
			return ComputerWins;
	}

	else if (_board[0][0] == _board[1][0] && _board[1][0] == _board[2][0]) {	//colum 1
		if (_board[0][0] == _player)
			return PlayerWins;
		else
			return ComputerWins;
	}

	else if (_board[0][1] == _board[1][1] && _board[1][1] == _board[2][1]) {	//colum 2
		if (_board[0][1] == _player)
			return PlayerWins;
		else
			return ComputerWins;
	}

	else if (_board[0][2] == _board[1][2] && _board[1][2] == _board[2][2]) {	//colum 3
		if (_board[0][2] == _player)
			return PlayerWins;
		else
			return ComputerWins;
	}

	else if (_board[0][0] == _board[1][1] && _board[1][1] == _board[2][2]) {	//diagonal 1
		if (_board[1][1] == _player)
			return PlayerWins;
		else
			return ComputerWins;
	}

	else if (_board[0][2] == _board[1][1] && _board[1][1] == _board[2][0]) {	//diagonal 2
		if (_board[0][2] == _player)
			return PlayerWins;
		else
			return ComputerWins;
	}

	for (int i = 0; i < _rows; i++) {

		for (int j = 0; j < _colums; j++) {
			if (_board[i][j] != _player || _board[i][j] != _computer)
				return inProgress;
		}
	}
	return Tie;
}

void xoRand::computerMove() {
	for (int i = 0; i < _rows; i++) {

		for (int j = 0; j < _colums; j++) {
			if (_board[i][j] != _player)
			{
				if (_board[i][j] != _computer) {
					_board[i][j] = _computer;
					return;
				}
						
			}
		}
	}

}

void xoEducate::computerMove() {
	int i, j;

	//check for rows
	j = 0;
	for (i = 0; i < 3; i++) {
		
		if (_board[i][j] == _board[i][j + 1] && _board[i][j + 1] == _player) {
			if (_board[i][j + 2] != _player && _board[i][j + 2] != _computer) {
				_board[i][j + 2] = _computer;
				return;
			}
		}

		else if (_board[i][j] == _board[i][j + 2] && _board[i][j + 2] == _player) {
			if (_board[i][j + 1] != _player && _board[i][j + 1] != _computer) {
				_board[i][j + 1] = _computer;
				return;
			}
		}

		else if (_board[i][j + 2] == _board[i][j + 1] && _board[i][j + 1] == _player) {
			if (_board[i][j] != _player && _board[i][j] != _computer) {
				_board[i][j] = _computer;
				return;
			}
		}
	}
	
	// check for colums
	i = 0;
	for (j = 0; j < 3; j++) {
		
		if (_board[i][j] == _board[i + 1][j] && _board[i + 1][j] == _player) {
			if (_board[i + 2][j] != _player && _board[i + 2][j] != _computer) {
				_board[i + 2][j] = _computer;
				return;
			}
		}

		else if (_board[i][j] == _board[i + 2][j] && _board[i + 2][j] == _player) {
			if (_board[i + 1][j] != _player && _board[i + 1][j] != _computer) {
				_board[i + 1][j] = _computer;
				return;
			}
		}

		else if (_board[i + 1][j] == _board[i + 2][j] && _board[i + 2][j] == _player) {
			if (_board[i][j] != _player && _board[i][j] != _computer) {
				_board[i][j] = _computer;
				return;
			}
		}
	}

	for (int i = 0; i < _rows; i++) {

		for (int j = 0; j < _colums; j++) {
			if (_board[i][j] != _player)
			{
				if (_board[i][j] != _computer) {
					_board[i][j] = _computer;
					return;
				}

			}
		}
	}
}


