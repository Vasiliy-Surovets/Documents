#include <TXlib.h>

struct Ball
    {
    int x, y, r;
    double Vx, Vy;
    COLORREF color;
    };
struct Box
    {
    int a1, b1, a2, b2;
    };
struct Bit
    {
    int x, y, x1, y1, r;
    COLORREF color;
    };

void collide (Ball *one, Bit *two);
Ball draw(struct Ball one);
Ball balls(struct Ball one, struct Box first);
Bit ddraw_bit(struct Bit a);
void draw_box();

int main()
    {
    Ball one = {100, 150, 15, 5, 0, RGB( 255, 255, 255)};
    Bit theOne = {30, 30, 32, 130, 50, RGB( 255, 255, 255)};
    Box first {25, 25, 1055, 575};
    txTextCursor(0);
    txCreateWindow(1080, 600);

    while (GetAsyncKeyState(VK_ESCAPE) == 0)
        {
         draw_box();
         ddraw_bit(theOne);
         draw(one);

         txSleep(10);

         one = balls(one, first);
         if (GetAsyncKeyState(VK_UP))
            {
            theOne.y -= 5;
            theOne.y1 -= 5;
            }
         if (GetAsyncKeyState(VK_DOWN))
            {
            theOne.y += 5;
            theOne.y1 += 5;
            }
         if (GetAsyncKeyState(VK_LEFT))
            {
            theOne.x -= 5;
            theOne.x1 -= 5;
            }
         if (GetAsyncKeyState(VK_RIGHT))
            {
            theOne.x += 5;
            theOne.x1 += 5;
            }
        collide(&one, &theOne);
        }
    }






Ball balls(struct Ball one, struct Box first)
    {
    txSetColor (one.color);
    txSetFillColor (one.color);
    one.x += one.Vx;
    one.y += one.Vy;

    if (one.x + one.r > first.a2)
        {
        one.x  -= (one.x - first.a2 + one.r) * 2;
        one.Vx *= -1;
        one.x = 540;
        one. y = 300;
        }
    if (one.x - one.r < first.a1)
        {
        one.x  -= (one.x - first.a1 - one.r) * 2;
        one.Vx *= -1;
        one.x = 540;
        one. y = 300;
        }
    if (one.y + one.r > first.b2)
        {
        one.y  -= (one.y - first.b2 + one.r) * 2;
        one.Vy *= -1;
        }
    if (one.y - one.r < first.b1)
        {
        one.y  -= (one.y - first.b1 - one.r) * 2;
        one.Vy *= -1;
        }
    return one;
    }

void collide (Ball *one, Bit *two)
    {
    double tmp;
    int i, j;
    if(one->x - one->r < two->x1)
        {
         one->x  -= (one->x - two->x1 - one->r) * 2;
         one->Vx *= -1;
        }
    }

Ball draw(struct Ball one)
    {
    txSetColor (one.color);
    txSetFillColor (one.color);
    txCircle (one.x, one.y, one.r);
    }

void draw_box()
    {
    txSetColor(TX_GREEN, 50);
    txSetFillColor(TX_BLACK);
    txRectangle(0, 0, 1080, 600);
    txSetColor(TX_WHITE);
    txSetFillColor(TX_WHITE);
    txLine(540, 25, 540, 575);
    txSetFillColor(TX_TRANSPARENT);
    txCircle(540, 300, 100);
    }

Bit ddraw_bit(struct Bit a)
    {
    txSetColor (a.color);
    txSetFillColor (a.color);
    txRectangle (a.x, a.y, a.x1, a.y1);
    }
