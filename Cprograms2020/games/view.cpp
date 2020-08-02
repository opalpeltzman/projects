#include "view.h"


void console::getcoordinate(int &x, int &y) {
	cout << "you'r turn, enter move :" << endl;
	cout << "row :" << endl;
	cin >> x;

	cout << "colum :" << endl;
	cin >> y;
}

void console::printErrors(const string error) const {
	cout << error << endl;
}

void xoConsole::printBoard(const std::vector<std::vector<char>>& board) const {

		cout << "     |     |     " << endl;
		cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;

		cout << "_____|_____|_____" << endl;
		cout << "     |     |     " << endl;

		cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;

		cout << "_____|_____|_____" << endl;
		cout << "     |     |     " << endl;

		cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;

		cout << "     |     |     " << endl << endl;


}

void catchBunnyConsole::printBoard(const std::vector<std::vector<char>>& board) const {
	
	cout << "     |     |     |     |     |     |     |     |     " << endl;
	cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  |  " << board[0][3] << "  |  " << board[0][4] << "  |  " << board[0][5] << "  |  " << board[0][6] << "  |  " << board[0][7] << "  |  " << board[0][8] << endl;

	cout << "_____|_____|_____|_____|_____|_____|_____|_____|_____" << endl;
	cout << "     |     |     |     |     |     |     |     |     " << endl;

	cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  |  " << board[1][3] << "  |  " << board[1][4] << "  |  " << board[1][5] << "  |  " << board[1][6] << "  |  " << board[1][7] << "  |  " << board[1][8] << endl;

	cout << "_____|_____|_____|_____|_____|_____|_____|_____|_____" << endl;
	cout << "     |     |     |     |     |     |     |     |     " << endl;

	cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  |  " << board[2][3] << "  |  " << board[2][4] << "  |  " << board[2][5] << "  |  " << board[2][6] << "  |  " << board[2][7] << "  |  " << board[2][8] << endl;


	cout << "_____|_____|_____|_____|_____|_____|_____|_____|_____" << endl;
	cout << "     |     |     |     |     |     |     |     |     " << endl;

	cout << "  " << board[3][0] << "  |  " << board[3][1] << "  |  " << board[3][2] << "  |  " << board[3][3] << "  |  " << board[3][4] << "  |  " << board[3][5] << "  |  " << board[3][6] << "  |  " << board[3][7] << "  |  " << board[3][8] << endl;

	cout << "_____|_____|_____|_____|_____|_____|_____|_____|_____" << endl;
	cout << "     |     |     |     |     |     |     |     |     " << endl;

	cout << "  " << board[4][0] << "  |  " << board[4][1] << "  |  " << board[4][2] << "  |  " << board[4][3] << "  |  " << board[4][4] << "  |  " << board[4][5] << "  |  " << board[4][6] << "  |  " << board[4][7] << "  |  " << board[4][8] << endl;

	
	cout << "_____|_____|_____|_____|_____|_____|_____|_____|_____" << endl;
	cout << "     |     |     |     |     |     |     |     |     " << endl;

	cout << "  " << board[5][0] << "  |  " << board[5][1] << "  |  " << board[5][2] << "  |  " << board[5][3] << "  |  " << board[5][4] << "  |  " << board[5][5] << "  |  " << board[5][6] << "  |  " << board[5][7] << "  |  " << board[5][8] << endl;

	cout << "_____|_____|_____|_____|_____|_____|_____|_____|_____" << endl;
	cout << "     |     |     |     |     |     |     |     |     " << endl;

	cout << "  " << board[6][0] << "  |  " << board[6][1] << "  |  " << board[6][2] << "  |  " << board[6][3] << "  |  " << board[6][4] << "  |  " << board[6][5] << "  |  " << board[6][6] << "  |  " << board[6][7] << "  |  " << board[6][8] << endl;


	cout << "_____|_____|_____|_____|_____|_____|_____|_____|_____" << endl;
	cout << "     |     |     |     |     |     |     |     |     " << endl;

	cout << "  " << board[7][0] << "  |  " << board[7][1] << "  |  " << board[7][2] << "  |  " << board[7][3] << "  |  " << board[7][4] << "  |  " << board[7][5] << "  |  " << board[7][6] << "  |  " << board[7][7] << "  |  " << board[7][8] << endl;

	cout << "_____|_____|_____|_____|_____|_____|_____|_____|_____" << endl;
	cout << "     |     |     |     |     |     |     |     |     " << endl;

	cout << "  " << board[8][0] << "  |  " << board[8][1] << "  |  " << board[8][2] << "  |  " << board[8][3] << "  |  " << board[8][4] << "  |  " << board[8][5] << "  |  " << board[8][6] << "  |  " << board[8][7] << "  |  " << board[8][8] << endl;

	cout << "     |     |     |     |     |     |     |     |     " << endl << endl;

	
}