#include <TXlib.h>



struct Ball
{
    int x, y, r;
    double Vx, Vy;
    COLORREF color;
};

struct Gun
{
    int x, y, x1, y1;
    COLORREF color;
};


void draw_gun(Gun *a);
int main()
{
    txTextCursor(0);
    txCreateWindow(1080, 600);
    Ball one = {-10, -10, 15, 0, 0, RGB( 255, 255, 255)};
    Gun big = {60, 550, 60, 600, RGB( 255, 255, 255)};

    while (GetAsyncKeyState(VK_ESCAPE) == 0)
    {
        draw_gun(&big);
    }

    return 0;
}

void plod(Gun *a, Ball *one)
{

}

void draw_gun(Gun *a)
{
    txSetColor (RGB (255, 255, 255), 5);
    txLine(a->x1, a->y1, a->x, a->y);
}
