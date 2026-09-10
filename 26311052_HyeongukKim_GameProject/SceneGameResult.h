#pragma once
class SceneGameResult
{
public:
	int Init();
	int Update();
	int Render();
	int Destroy();

protected:
	//game texture
	int m_txUI_score = -1;
};