#include "SceneGameBegin.h"
#include "glc2d.h"
#include "CApplication.h"

//구현해야될것
//플레이화면 점수 출력
//종료화면 점수 출력

int SceneGameBegin::Init()
{
	this->m_txBG = g2_TextureLoad("resource/texture/begin/BG_Begin.png");
	this->m_txUI_start = g2_TextureLoad("resource/texture/begin/ui_START.png");
	this->m_txUI_exit = g2_TextureLoad("resource/texture/begin/ui_EXIT.png");
	this->m_txUI_chose = g2_TextureLoad("resource/texture/begin/ui_CHOSE.png");

	return 0;
}

int SceneGameBegin::Destroy()
{

	return 0;
}

int SceneGameBegin::Update()
{
	return 0;
}

int SceneGameBegin::Render()
{
	//홈화면 배경 출력
	{
		VEC2 position_BG{ 200.0f, 0.0f };
		VEC2 scale{ 0.75f, 0.75f };
		g2_Draw2D(m_txBG, nullptr, &position_BG, &scale);
	}
	//홈화면 start버튼
	{
		VEC2 position_UI_start{ 840.0f, 330.0f };
		VEC2 scale_UI(0.2f, 0.2f);
		g2_Draw2D(m_txUI_start, nullptr, &position_UI_start, &scale_UI);
	}
	//홈화면 exit버튼
	{
		VEC2 position_UI_exit{ 840.0f, 470.0f };
		VEC2 scale_UI(0.17f, 0.17f);
		g2_Draw2D(m_txUI_exit, nullptr, &position_UI_exit, &scale_UI);
	}
	//선택된거 인식 UI
	{
		VEC2 position_UI_chose{ 840.0f, 470.0f };
		VEC2 scale_UI(0.17f, 0.17f);
		g2_Draw2D(m_txUI_chose, nullptr, &position_UI_chose, &scale_UI);
	}


	//auto winSize = g_app.GetWinSize();

	//auto bgTexW = (float)g2_TextureWidth(m_txUI);
	//auto bgTexH = (float)g2_TextureHeight(m_txUI);
	//
	//VEC2 bgScale{ winSize.cx / bgTexW, winSize.cy / bgTexH };
	//VEC2 position{ 150, 100 };
	//VEC2 scale{ 0.5f, 0.5f };
	//g2_Draw2D(m_txUI, nullptr);

	return 0;
}