#pragma once
#include <windows.h>
#include <string>
#include "SceneGameBegin.h"

class CApplication
{
public:
	bool Init();
	int Update();
	int Render();
	int Destroy();

public:
	SIZE GetWinSize();

protected:
	int InitSdk();

protected:
	//windows
	POINT m_winPos  { 250, 100 };
	SIZE m_winSize  { 1366, 768 };
	std::string m_winName = "Reverse Pong";

	SceneGameBegin m_sceneBegin;
};

//전역 접근
extern CApplication g_app;