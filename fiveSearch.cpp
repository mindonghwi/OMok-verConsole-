// fiveSearch.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

using namespace std;

int main()
{
	C_GAMEMGR::createInstance();

	C_GAMEMGR::getInstence()->createGame();
	C_GAMEMGR::getInstence()->play();
	C_GAMEMGR::getInstence()->release();
	C_GAMEMGR::releaseInstance();
	
    return 0;
}

