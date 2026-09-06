#include "SceneGamePlay.h"
#include "glc2d.h"

int SceneGamePlay::Init()
{
	m_txBall = g2_TextureLoad("resource/texture/ball.png");

	m_ball.x = 400;
	m_ball.y = 300;

	m_ball.vx = 3;
	m_ball.vy = 2;

	return 0;
}

int SceneGamePlay::Destroy()
{
	return 0;
}

int SceneGamePlay::Update()
{
	return 0;
}

int SceneGamePlay::Render()
{
	return 0;
}