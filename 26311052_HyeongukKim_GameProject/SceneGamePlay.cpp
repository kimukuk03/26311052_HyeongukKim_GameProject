#include "SceneGamePlay.h"
#include "glc2d.h"

void DrawWhiteBall(HWND hwnd, int x, int y, int radius)
{
	HDC hdc = GetDC(hwnd);

	HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

	Ellipse(hdc,
		x - radius,
		y - radius,
		x + radius,
		y + radius);

	SelectObject(hdc, oldBrush);
	DeleteObject(brush);
	ReleaseDC(hwnd, hdc);
}

int SceneGamePlay::Init()
{
	g2_SetClearColor(0xFF000000); // °ËÁ¤»ö

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
	DrawWhiteBall(g2_GetHwnd(), 683, 384, 15);

	return 0;
}

