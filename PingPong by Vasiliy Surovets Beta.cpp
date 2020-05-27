#include <TXlib.h>

struct Ball
    {
    int x, y, r;
    double Vx, Vy;
    COLORREF color;
    int p1, p2;
    };
struct Box
    {
    int a1, b1, a2, b2;
    };
struct Bit
    {
    int x, y, x1, y1, r, v11, v21, v12, v22;
    COLORREF color;
    };

void collide (Ball *one, Bit *two);
Ball draw(struct Ball one);
Ball balls(struct Ball one, struct Box first);
void control(Bit *theOne, int a, int b, int c, int d, int verh, int niz, int left, int right);
Bit ddraw_bit(struct Bit a);
void draw_box();

int main()
    {
    Ball one = {540, 300, 15, 5, 6, RGB( 255, 255, 255), 0, 0};
    Bit theOne = {40, 30, 42, 130, 1, 0, 0, 0, 0, RGB( 255, 255, 255)};
    Bit theTwo = {1038, 30, 1040, 130, 2, 0, 0, 0, 0, RGB( 255, 255, 255)};
    Box first {25, 25, 1055, 575};
    txTextCursor(0);
    txCreateWindow(1080, 600);

    txDrawText(420, 200, 620, 300, "Пинг понг.\n"
                                   "Управление:\n"
                                   "Игрок один - WASD,    Игрок два - стрелочки");
    while (GetAsyncKeyState(32) == 0)
        {

        }

    while (GetAsyncKeyState(VK_ESCAPE) == 0)
        {

         draw_box();

         ddraw_bit(theOne);
         ddraw_bit(theTwo);
         draw(one);

         txSleep(10);
         control(&theOne, 87, 83, 65, 68, 25, 575, 40, 520);
         control(&theTwo, 38, 40, 37, 39, 25, 575, 560, 1040);
         one = balls(one, first);

        collide(&one, &theOne);
        collide(&one, &theTwo);
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
        txDrawText(25, 25, 1020, 60, "Нажмите пробел, чтобы продолжить");
        while (GetAsyncKeyState(32) == 0)
            {

            }
            one.x = 540;
            one. y = 300;
            one.Vx = -5;
            one.Vy = 0;
        }
    if (one.x - one.r < first.a1)
        {
        one.x  -= (one.x - first.a1 - one.r) * 2;
        one.Vx *= -1;
        txDrawText(25, 25, 1020, 60, "Нажмите пробел, чтобы продолжить");
        while (GetAsyncKeyState(32) == 0)
            {

            }
            one.x = 540;
            one.y = 300;
            one.Vx = 5;
            one.Vy = 0;
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
    int a, b;
    if (one->x - one->r < two->x1 && one->y >= two->y && one->y <= two->y1 && one->x + one->r > two->x1)
        {
        if (two->r == 1)
            {
            one->x  -= (one->x - two->x1 - one->r) * 2;
            one->Vx *= -1;
            one->Vx += (two->v12 + two->v11);
            one->Vy += (two->v21 + two->v22);
            }
            else
            {
            one->x  -= (one->x - two->x + one->r) * 2;
            one->Vx *= -1;
            one->Vx += (two->v11 + two->v12);
            one->Vy += (two->v22 + two->v21);
            }

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

void control(Bit *theOne, int a, int b, int c, int d, int verh, int niz, int left, int right)
    {
    if (GetAsyncKeyState(a))
        {
        if (theOne->y - 10 > verh)
            {
            theOne->y -= 10;
            theOne->y1 -= 10;
            theOne->v21 = -3;
            }


        } else {
            theOne->v21 = 0;
        }
    if (GetAsyncKeyState(b))
        {
        if (theOne->y1 + 10 < niz)
            {
            theOne->y += 10;
            theOne->y1 += 10;
            theOne->v22 = 3;
            }
        } else {
            theOne->v22 = 0;
        }
    if (GetAsyncKeyState(c))
        {
        if (theOne->x - 5 > left)
            {
            theOne->x -= 5;
            theOne->x1 -= 5;
            theOne->v11 = -3;
            }
        } else {
            theOne->v11 = 0;
        }
    if (GetAsyncKeyState(d))
        {
        if (theOne->x1 + 5 < right)
            {
            theOne->x += 5;
            theOne->x1 += 5;
            theOne->v12 = 3;
            }
        } else {
            theOne->v12 = 0;
        }
    }
