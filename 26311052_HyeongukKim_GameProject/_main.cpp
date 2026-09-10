// link the 2d game library
#if defined(_DEBUG)
#if defined(_M_X64) // 64-bit 아키텍처
#pragma comment(lib, "glc2d_x64_debug.lib")
#elif defined(_M_IX86) // 32-bit 아키텍처
#pragma comment(lib, "glc2d_win32_debug.lib")
#endif
#else
#if defined(_M_X64)
#pragma comment(lib, "glc2d_x64_release.lib")
#elif defined(_M_IX86)
#pragma comment(lib, "glc2d_win32_release.lib")
#endif
#endif

// include the 2d game header file
#include "glc2d.h"
#include "CApplication.h"

//생성(Create) - 소멸(Destroy) - 초기화(Init) - 갱신(Update) - 랜더링(Render) 순서로
//2d game = Texture, font, Audio, Input
CApplication g_app;

int main()
{
	g_app.Init();
	// 실행
	g2_Run();
	g_app.Destroy();

	return 0;
}