#include <glc2d.h>

int nTx1;
int nTx2;

int Render()
{
    VEC2 pos1(200, 200);
    VEC2 pos2(500, 200);

    g2_Draw2D(nTx1, NULL, &pos1);
    g2_Draw2D(nTx2, NULL, &pos2);

    return 0;
}

int main()
{
    g2_InitSdk();

    g2_SetClearColor(0xFF336699);
    g2_SetRender(Render);

    g2_CreateWin(100, 100, 800, 600, "Texture Test");

    nTx1 = g2_TextureLoad("Texture/GameStart.png");
    nTx2 = g2_TextureLoad("Texture/lena.png");

    g2_Run();

    g2_TextureRelease(nTx1);
    g2_TextureRelease(nTx2);

    g2_DestroyWin();

    return 0;
}