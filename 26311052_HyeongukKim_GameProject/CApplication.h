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

protected:
	int InitSdk();

protected:
	//windows
	POINT m_winPos  { 100, 100 };
	SIZE m_winSize  { 800, 600 };
	std::string m_winName = "Reverse Pong";

	SceneGameBegin m_sceneBegin;
};

