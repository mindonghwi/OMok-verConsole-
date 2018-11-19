#pragma once

#include "stdafx.h"

using namespace std;


class C_MAP
{
public:
	C_MAP();
	~C_MAP();

private:
	C_MAP & operator= (const C_MAP&);
	C_MAP(const C_MAP&);

private:
	string ** m_ppMap;
	bool **m_ppIsStone;
	int **m_ppUSerStone;
public:
	void init();
	void release();
	void printMap();
	void upDate(int nRow,int nCol,const string& strShape,int nPlayerNum);
	bool getIsStone(int nRow, int nCol);

	bool searchFive(int nRow, int nCol, int nPlayerNum);
	int verticalFiveCount(int nRow, int nCol, int nPlayerNum, int oldRow, int oldCol);
	int HoriZentalFiveCount(int nRow, int nCol, int nPlayerNum, int oldRow, int oldCol);
	int leftRightDiagonalLineFiveCount(int nRow, int nCol, int nPlayerNum, int oldRow, int oldCol);
	int RightLeftDiagonalLineFiveCount(int nRow, int nCol, int nPlayerNum, int oldRow, int oldCol);
};
