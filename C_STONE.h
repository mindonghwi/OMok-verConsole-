#pragma once

#include "stdafx.h"

class C_STONE
{
public:
	C_STONE();
	~C_STONE();


private:
	int m_nPosX;
	int m_nPosY;
	string m_arShape;
public:
	void setPos(int nPosX, int nPosY) { m_nPosX = nPosX; m_nPosY = nPosY; };
	int getPosX() { return m_nPosX; };
	int getPosY() { return m_nPosY; };
};

