#pragma once
#include <iostream>
#include <sstream>
#ifdef WIN32
	#include <windows.h>
#else
#endif
#include <string>
using namespace std;

class ChineseChess{
private:
	enum Side{
		Red=0x0,
		Black=0x8,
	};
	enum Piece{
		Shuai=1,Ju,Ma,Pao,Xiang,Shi,Bing,MAX
	};

	struct Element
	{
		Side side;
		Piece piece;
	};
	

	Element getelment(char c){
		return {Side(c&0x8),Piece(c&0x7)};
	}

	char getc(Side s,Piece p){
		return s + p;
	}

	bool InBoard(char pos){
		return (pos>>4) >= 3 && (pos>>4) <= 12 && (pos & 0xF)>=3 && (pos & 0xF)<=11;
	}

	char initboard[256]={
		0,0,0,Black+Ju,Black+Ma,Black+Xiang,Black+Shi,Black+Shuai,Black+Shi,Black+Xiang,Black+Ma,Black+Ju,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,Black+Pao,0,0,0,0,0,Black+Pao,0,0,0,0,0,
		0,0,0,Black+Bing,0,Black+Bing,0,Black+Bing,0,Black+Bing,0,Black+Bing,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,Red+Bing,0,Red+Bing,0,Red+Bing,0,Red+Bing,0,Red+Bing,0,0,0,0,
		0,0,0,0,Red+Pao,0,0,0,0,0,Red+Pao,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,Red+Ju,Red+Ma,Red+Xiang,Red+Shi,Red+Shuai,Red+Shi,Red+Xiang,Red+Ma,Red+Ju,0,0,0,0
	};
};