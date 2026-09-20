#pragma once

enum class BarSide
{
	TOP,
	RIGHT,
	BOTTOM,
	LEFT
};

class SceneGamePlay
{
public:
	int Init();
	int Update();
	int Render();
	int Destroy();

protected:
	// BAR 위치
	int m_barX = 0;
	int m_barY = 0;

	// 가로 BAR 기준 크기
	int m_barLength = 180;
	int m_barThickness = 25;

	// 현재 붙어 있는 벽
	BarSide m_barSide = BarSide::BOTTOM;
};