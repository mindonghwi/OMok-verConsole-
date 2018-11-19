#include "stdafx.h"

C_MAP::C_MAP():
	m_ppMap(nullptr),
	m_ppIsStone(nullptr)
{
}

C_MAP::~C_MAP()
{
}

void C_MAP::init()
{
	m_ppMap = new string*[18];
	for (int i = 0; i < 20; i++)
	{
		m_ppMap[i] = new string[18];
	}
	m_ppMap[0][0] = "¦£ ";
	for (int i = 1; i < 17; i++)
	{
		m_ppMap[0][i] = "¦¨ ";
	}
	m_ppMap[0][17] = "¦¤ ";

	for (int i = 1; i < 17; i++)
	{
		m_ppMap[i][0] = "¦§ ";
		m_ppMap[i][17] = "¦© ";
	}
	for (int i = 1; i < 17; i++)
	{
		for (int j = 1; j < 17; j++)
		{
			m_ppMap[i][j] = "¦« ";
		}
	}

	m_ppMap[17][0] = "¦¦ ";
	for (int i = 1; i < 17; i++)
	{
		m_ppMap[17][i] = "¦ª ";
	}
	m_ppMap[17][17] = "¦¥ ";


	m_ppIsStone = new bool*[18];
	for (int i = 0; i < 18; i++)
	{
		m_ppIsStone[i] = new bool[18];
	}

	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			m_ppIsStone[i][j] = false;
		}
	}
	

	m_ppUSerStone = new int*[18];
	for (int i = 0; i < 18; i++)
	{
		m_ppUSerStone[i] = new int[18];
	}

	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			m_ppUSerStone[i][j] = 2;
		}
	}
	//m_pMap[19] = "   A B C D E F G H I J K N M O P Q R S";

}

void C_MAP::release()
{
	delete[] m_ppMap;
	m_ppMap = nullptr;
}

void C_MAP::printMap()
{
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 18; j++)
		{
			cout << m_ppMap[i][j];
		}
		cout << endl;
	}
}

void C_MAP::upDate(int nRow, int nCol, const string & strShape, int nPlayerNum)
{
	m_ppIsStone[nCol][nRow] = true;
	m_ppMap[nCol][nRow] = strShape;
	m_ppUSerStone[nCol][nRow] = nPlayerNum;
}

bool C_MAP::getIsStone(int nRow, int nCol)
{
	return m_ppIsStone[nCol][nRow];
}

bool C_MAP::searchFive(int nRow, int nCol, int nPlayerNum)
{
	bool bIsFive(false);
	int nTmp(0);

	nTmp = verticalFiveCount(nRow, nCol, nPlayerNum,19,19);
	if (nTmp == 5) {
		return true;
	}
	nTmp = HoriZentalFiveCount(nRow, nCol, nPlayerNum, 19, 19);
	if (nTmp == 5) {
		return true;
	}
	nTmp = leftRightDiagonalLineFiveCount(nRow, nCol, nPlayerNum, 19, 19);
	if (nTmp == 5) {
		return true;
	}
	nTmp = RightLeftDiagonalLineFiveCount(nRow, nCol, nPlayerNum, 19, 19);
	if (nTmp == 5) {
		return true;
	}

	return false;
}

int C_MAP::verticalFiveCount(int nRow, int nCol, int nPlayerNum, int oldRow, int oldCol)
{

	int nCount(1);

	if (nRow != 0 && m_ppUSerStone[nCol][nRow - 1] == nPlayerNum && oldRow != nRow-1 ) {
		nCount += verticalFiveCount(nRow - 1, nCol, nPlayerNum,nRow,nCol);
	}

	if (nRow != E_MAXSIZE - 1 && m_ppUSerStone[nCol][nRow + 1] == nPlayerNum && oldRow != nRow+1) {
		nCount += verticalFiveCount(nRow + 1, nCol, nPlayerNum,nRow,nCol);
	}

	return nCount;
}

int C_MAP::HoriZentalFiveCount(int nRow, int nCol, int nPlayerNum, int oldRow, int oldCol)
{
	int nCount(1);

	if (nCol != 0 && m_ppUSerStone[nCol - 1][nRow] == nPlayerNum && oldCol != nCol-1) {
		nCount += HoriZentalFiveCount(nRow, nCol - 1, nPlayerNum, nRow, nCol);
	}

	if (nCol != E_MAXSIZE - 1 && m_ppUSerStone[nCol + 1][nRow] == nPlayerNum && oldCol != nCol+1) {
		nCount += HoriZentalFiveCount(nRow, nCol + 1, nPlayerNum, nRow, nCol);
	}

	return nCount;
}

int C_MAP::leftRightDiagonalLineFiveCount(int nRow, int nCol, int nPlayerNum, int oldRow, int oldCol)
{
	int nCount(1);

	if (nRow != 0 && nCol != 0 && m_ppUSerStone[nCol-1][nRow - 1] == nPlayerNum && oldCol != nCol-1 && oldRow != nRow-1) {
		nCount += leftRightDiagonalLineFiveCount(nRow - 1, nCol-1, nPlayerNum, nRow, nCol);
	}

	if (nRow != E_MAXSIZE - 1 && nCol != E_MAXSIZE - 1 && m_ppUSerStone[nCol + 1][nRow + 1] == nPlayerNum && oldCol != nCol+1 && oldRow != nRow + 1) {
		nCount += leftRightDiagonalLineFiveCount(nRow + 1, nCol+1, nPlayerNum, nRow, nCol);
	}

	return nCount;
}

int C_MAP::RightLeftDiagonalLineFiveCount(int nRow, int nCol, int nPlayerNum, int oldRow, int oldCol)
{
	int nCount(1);

	if (nRow != 0 && nCol != E_MAXSIZE - 1 && m_ppUSerStone[nCol + 1][nRow - 1] == nPlayerNum && oldCol != nCol+1 && oldRow != nRow-1) {
		nCount += RightLeftDiagonalLineFiveCount(nRow - 1, nCol - 1, nPlayerNum, nRow, nCol);
	}

	if (nRow != E_MAXSIZE -1 && nCol !=0 && m_ppUSerStone[nCol - 1][nRow + 1] == nPlayerNum && oldCol != nCol-1 && oldRow != nRow+1) {
		nCount += RightLeftDiagonalLineFiveCount(nRow + 1, nCol + 1, nPlayerNum, nRow, nCol);
	}

	return nCount;
}

