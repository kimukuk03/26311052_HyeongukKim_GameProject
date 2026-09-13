#include <stdio.h>
#include "glc2d.h"
#include "CApplication.h"

int AppUpdate()
{
	return g_app.Update();
}

int AppRender()
{
	return g_app.Render();
}

bool CApplication::Init()
{
	InitSdk();

	m_sceneBegin.Init();

	return true;
}
	
int CApplication::Update()
{
	if (m_scene == SceneType::BEGIN)
	{
		m_sceneBegin.Update();
	}
	else if (m_scene == SceneType::PLAY)
	{
		m_scenePlay.Update();
	}
	return 0;
}

int CApplication::Render()
{
	if (m_scene == SceneType::BEGIN)
	{
		m_sceneBegin.Render();
	}
	else if (m_scene == SceneType::PLAY)
	{
		m_scenePlay.Render();
	}
	return 0;
}
void CApplication::ChangeScene(SceneType scene)
{
	if (m_scene == SceneType::BEGIN)
	{
		m_sceneBegin.Destroy();
	}
	else if (m_scene == SceneType::PLAY)
	{
		m_scenePlay.Destroy();
	}
	m_scene = scene;

	if (m_scene == SceneType::BEGIN)
	{
		m_sceneBegin.Init();
	}
	else if (m_scene == SceneType::PLAY)
	{
		m_scenePlay.Init();
	}
}

int CApplication::Destroy()
{
	m_sceneBegin.Destroy();

	// 윈도우 해제
	g2_DestroyWin();

	return 0;
}

SIZE CApplication::GetWinSize()
{
	return SIZE();
}

int CApplication::InitSdk()
{
	// SDK 초기화
	g2_InitSdk();	

	g2_SetFrameMove(AppUpdate);
	g2_SetRender(AppRender);

	// 윈도우 생성
	g2_CreateWin(m_winPos.x, m_winPos.y,
				m_winSize.cx, m_winSize.cy,
				m_winName.c_str());

	return 0;
}
	