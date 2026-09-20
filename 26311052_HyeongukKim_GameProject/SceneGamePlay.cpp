#include "SceneGamePlay.h"
#include "glc2d.h"
#include <windows.h>


int SceneGamePlay::Init()
{
	// 게임 화면 배경 검정색
	g2_SetClearColor(0xFF000000);

	return 0;
}


int SceneGamePlay::Update()
{
	int mouseX = g2_GetMouseX();
	int mouseY = g2_GetMouseY();

	int screenW = g2_GetScnW();
	int screenH = g2_GetScnH();


	// 마우스와 각 벽 사이 거리
	int distTop = mouseY;
	int distBottom = screenH - mouseY;
	int distLeft = mouseX;
	int distRight = screenW - mouseX;


	// 가장 가까운 벽 찾기
	int minDist = distTop;
	m_barSide = BarSide::TOP;


	if (distRight < minDist)
	{
		minDist = distRight;
		m_barSide = BarSide::RIGHT;
	}

	if (distBottom < minDist)
	{
		minDist = distBottom;
		m_barSide = BarSide::BOTTOM;
	}

	if (distLeft < minDist)
	{
		minDist = distLeft;
		m_barSide = BarSide::LEFT;
	}

	if (m_barSide == BarSide::TOP)
	{
		m_barX = mouseX - m_barLength / 2;
		m_barY = 0;

		// 화면 밖으로 나가지 않게 제한
		if (m_barX < 0)
			m_barX = 0;

		if (m_barX + m_barLength > screenW)
			m_barX = screenW - m_barLength;
	}


	else if (m_barSide == BarSide::BOTTOM)
	{
		m_barX = mouseX - m_barLength / 2;
		m_barY = screenH - m_barThickness;

		if (m_barX < 0)
			m_barX = 0;

		if (m_barX + m_barLength > screenW)
			m_barX = screenW - m_barLength;
	}


	else if (m_barSide == BarSide::LEFT)
	{
		m_barX = 0;
		m_barY = mouseY - m_barLength / 2;

		if (m_barY < 0)
			m_barY = 0;

		if (m_barY + m_barLength > screenH)
			m_barY = screenH - m_barLength;
	}


	else if (m_barSide == BarSide::RIGHT)
	{
		m_barX = screenW - m_barThickness;
		m_barY = mouseY - m_barLength / 2;

		if (m_barY < 0)
			m_barY = 0;

		if (m_barY + m_barLength > screenH)
			m_barY = screenH - m_barLength;
	}


	return 0;
}


int SceneGamePlay::Render()
{
	HWND hwnd = g2_GetHwnd();
	HDC hdc = GetDC(hwnd);


	// BAR 색상
	HBRUSH barBrush = CreateSolidBrush(
		RGB(255, 255, 255)
	);

	HBRUSH oldBrush =
		(HBRUSH)SelectObject(hdc, barBrush);


	// 테두리도 흰색
	HPEN barPen = CreatePen(
		PS_SOLID,
		1,
		RGB(255, 255, 255)
	);

	HPEN oldPen =
		(HPEN)SelectObject(hdc, barPen);

	if (m_barSide == BarSide::TOP ||
		m_barSide == BarSide::BOTTOM)
	{
		RoundRect(
			hdc,
			m_barX,
			m_barY,
			m_barX + m_barLength,
			m_barY + m_barThickness,
			15,
			15
		);
	}
	else
	{
		RoundRect(
			hdc,
			m_barX,
			m_barY,
			m_barX + m_barThickness,
			m_barY + m_barLength,
			15,
			15
		);
	}
	Ellipse(
		hdc,
		683 - 15,
		384 - 15,
		683 + 15,
		384 + 15
	);
	// GDI 객체 원상복구
	SelectObject(hdc, oldBrush);
	SelectObject(hdc, oldPen);

	DeleteObject(barBrush);
	DeleteObject(barPen);

	ReleaseDC(hwnd, hdc);


	return 0;
}


int SceneGamePlay::Destroy()
{
	return 0;
}