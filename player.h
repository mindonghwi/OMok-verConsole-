#pragma once

#include "stdafx.h"
class C_STONE;

class C_PLAYER
{
public:
	C_PLAYER();
	~C_PLAYER();

private:
	C_STONE* m_pStones;
	string m_strShape;
	int m_nIndex;
public:
	void init(string strShape);
	void release();
	void putStone(int nPosX, int nPosY);
	const string& getShape() { return m_strShape; };
	void searchFive();
	int verticalFiveCount(int nRow,int nCol);
	int HoriZentalFiveCount(int nRow, int nCol);
	int leftRightDiagonalLineFiveCount(int nRow, int nCol);
	int RightLeftDiagonalLineFiveCount(int nRow, int nCol);
};
