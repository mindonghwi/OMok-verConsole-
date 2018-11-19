#pragma once

#include "stdafx.h"

class C_PLAYER;

class C_GAMEMGR
{
private:
	C_GAMEMGR();
	~C_GAMEMGR();
	C_GAMEMGR(const C_GAMEMGR&);
	const C_GAMEMGR& operator= (const C_GAMEMGR&);

private:
	C_MAP m_cMap;
	C_PLAYER* m_pPlayer;
	int nTurnPlayers;
	static C_GAMEMGR* m_pGameMgr;
	int m_nRow;
	int m_nCol;
	bool m_bIsGaming;

public:
	static void createInstance();
	void createGame();
	static void releaseInstance();
	void release();
	static C_GAMEMGR* getInstence();
	void play();
	void update();
};
