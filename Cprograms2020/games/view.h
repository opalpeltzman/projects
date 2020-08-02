#pragma once
#include<stdlib.h>
#include <iostream>
#include <vector>
#include <memory>



using namespace std;

class view {
public:
	view() = default;
	~view() = default;
	virtual void printBoard(const std::vector<std::vector<char>>& board) const = 0;
	virtual void getcoordinate(int &x, int &y) = 0;
	virtual void printErrors(const string error) const = 0;
};

class graphicalInterface : public view {
public:
	virtual void printBoard(const std::vector<std::vector<char>>& board) const = 0;
	virtual void getcoordinate(int &x, int &y) ;
	virtual void printErrors(const string error) const ;
};

class console : public view {
public:
	virtual void printBoard(const std::vector<std::vector<char>>& board) const = 0;
	virtual void getcoordinate(int &x, int &y);
	virtual void printErrors(const string error) const ;
};

class xoConsole : public console {
public:
	virtual void printBoard(const std::vector<std::vector<char>>& board) const ;
};

class catchBunnyConsole : public console {
public:
	virtual void printBoard(const std::vector<std::vector<char>>& board) const ;
};