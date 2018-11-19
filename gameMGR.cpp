#include "stdafx.h"

C_GAMEMGR* C_GAMEMGR::m_pGameMgr = nullptr;

C_GAMEMGR::C_GAMEMGR()
{
}

C_GAMEMGR::~C_GAMEMGR()
{
}

void C_GAMEMGR::createInstance()
{
	if (m_pGameMgr == nullptr) {
		m_pGameMgr = new C_GAMEMGR();
	}
}
void C_GAMEMGR::createGame()
{
	m_cMap.init();

	m_pPlayer = new C_PLAYER[2];
	
	m_pPlayer[0].init("●");
	m_pPlayer[1].init("○");
	nTurnPlayers = 0;
	m_nRow = 0;
	m_nCol = 0;
	m_bIsGaming = true;
}

void C_GAMEMGR::releaseInstance()
{
	if (m_pGameMgr != nullptr) {
		delete m_pGameMgr;
		m_pGameMgr = nullptr;
	}
}

void C_GAMEMGR::release()
{
	m_cMap.release();
	m_pPlayer[0].release();
	m_pPlayer[1].release();
	delete[] m_pPlayer;
	m_pPlayer = nullptr;
	
}

C_GAMEMGR * C_GAMEMGR::getInstence()
{
	if (m_pGameMgr == nullptr) {
		return nullptr;
	}
	return m_pGameMgr;
}

void C_GAMEMGR::play()
{
	
	while (m_bIsGaming) {
		system("cls");
		m_cMap.printMap();
		cout << "=================================" << endl;
		cout <<nTurnPlayers<<"번 유저의 턴: "<<endl<< "좌표를 입력해주세요.(가로축 세로축)" << endl;
		cin >> m_nCol >> m_nRow;

		//자리에 돌이 있냐 없냐 확인
		if (!m_cMap.getIsStone(m_nRow,m_nCol)) {
			m_cMap.upDate(m_nRow, m_nCol, m_pPlayer[nTurnPlayers].getShape(),nTurnPlayers);
			m_cMap.printMap();

			m_pPlayer[nTurnPlayers].putStone(m_nRow, m_nCol);
			update();

			nTurnPlayers++;
			if (nTurnPlayers == 2) {
				nTurnPlayers = 0;
			}

		}
	}

	system("pause");
}

void C_GAMEMGR::update()
{
	bool bIsGameEnd = false;
	bIsGameEnd = m_cMap.searchFive(m_nRow, m_nCol, nTurnPlayers);
	
	if (bIsGameEnd)
	{
		m_bIsGaming = false;
		system("cls");
		cout << nTurnPlayers << "가 이겼습니다." << endl;
	}
}

