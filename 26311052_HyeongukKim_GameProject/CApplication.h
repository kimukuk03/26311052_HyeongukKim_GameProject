#pragma once
#include <windows.h>
#include <string>

#include "SceneGameBegin.h"
#include "SceneGamePlay.h"


enum class SceneType
{
	BEGIN,
	PLAY
};


class CApplication
{
public:
	bool Init();
	int Update();
	int Render();
	int Destroy();

	void ChangeScene(SceneType scene);

public:
	SIZE GetWinSize();

protected:
	int InitSdk();

protected:
	// windows
	POINT m_winPos{ 250, 100 };						//창 열리는 위치
	SIZE m_winSize{ 1366, 768 };					//창 크기
	std::string m_winName = "Reverse Pong";

	// 현재 Scene
	SceneType m_scene = SceneType::BEGIN;

	// Scene 객체
	SceneGameBegin m_sceneBegin;
	SceneGamePlay m_scenePlay;

protected://사운드 
	
};


// 전역 접근
extern CApplication g_app;