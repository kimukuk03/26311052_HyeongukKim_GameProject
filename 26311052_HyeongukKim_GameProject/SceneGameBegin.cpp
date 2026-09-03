#include "SceneGameBegin.h"
#include "glc2d.h"

int SceneGameBegin::Init()
{
	this->m_txPong = g2_TextureLoad("resource/texture/PongBackground.jpg");

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
	g2_Draw2D(m_txPong, nullptr);

	return 0;
}