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
void start_screen();
Ball draw(struct Ball one);
Ball balls(struct Ball one, struct Box first);
void control(Bit *theOne, int a, int b, int c, int d, int verh, int niz, int left, int right);
Bit ddraw_bit(struct Bit a);
void menu (Bit *one, Bit *two);
void draw_box();

int main()
    {

    Ball one = {540, 300, 15, 5, 0, RGB( 255, 255, 255), 0, 0};
    Bit theOne = {40, 30, 42, 130, 1, 0, 0, 0, 0, RGB( 255, 255, 255)};
    Bit theTwo = {1038, 30, 1040, 130, 2, 0, 0, 0, 0, RGB( 255, 255, 255)};
    Box first {25, 25, 1055, 575};
    txTextCursor(0);
    txCreateWindow(1080, 600);




    start_screen();
    menu(&theOne, &theTwo);

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
         if (GetAsyncKeyState(80))
            {
            menu(&theOne, &theTwo);
            }
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
            if (one->Vx < 0)
                {
                one->x  -= (one->x - two->x1 - one->r) * 2;
                one->Vx *= -1;
                one->Vx += (two->v12 + two->v11);
                one->Vy += (two->v21 + two->v22);
                }
                else
                {
                one->Vx += (two->v12 + two->v11);
                one->Vy += (two->v21 + two->v22);
                }
            }
            else
            {
            if (one->Vx > 0)
                {
                one->x  -= (one->x - two->x + one->r) * 2;
                one->Vx *= -1;
                one->Vx += (two->v11 + two->v12);
                one->Vy += (two->v22 + two->v21);
                }
                else
                {
                one->Vx += (two->v11 + two->v12);
                one->Vy += (two->v22 + two->v21);
                }
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


void start_screen()
    {
    int i = 30, j = 30, l = 30, a = 1;
    const COLORREF RAIBOW = RGB ( i, j, l);
    while(GetAsyncKeyState(32) == 0)
        {
            const COLORREF RAIBOW = RGB ( i, j, l);
            txSetFillColor (RAIBOW);
            txSetColor (RAIBOW);

            if (i > 100 || i < 30) {
            a = -a;
            }
            if (j > 100 || j < 30) {
            a = -a;
            }
            if (l > 100 || l < 30) {
            a = -a;
            }


            txSetColor(RAIBOW);
            txSetFillColor(RAIBOW);
            txRectangle(0, 0, 1090, 600);
            txSetColor(TX_WHITE);
            txSetFillColor(TX_WHITE);
            txDrawText(420, 200, 620, 300, "Пинг понг.\n"
                                       "Управление:\n"
                                       "Игрок один - WASD,    Игрок два - стрелочки\n\n"
                                       "Нажмите пробел для входа в меню");
            txSleep(10);
            i += a;
            j += a;
            l += a;
        }
    while(i != 0 && l != 0 && j != 0)
        {
            const COLORREF RAIBOW = RGB ( i, j, l);
            txSetColor(RAIBOW);
            txSetFillColor(RAIBOW);
            txRectangle(0, 0, 1090, 600);

            if (i > 0)
                {
                i--;
                }
            if (j > 0)
                {
                j--;
                }
            if (l > 0)
                {
                l--;
                }
            txSleep(10);
        }
    }

void menu (Bit *one, Bit *two)
    {
    int strok = 1, time = 0, choose = 0, i = 1, j = 1, l = 1;

    while(time == 0)
        {
        txSetColor(TX_BLACK);
        txSetFillColor(TX_BLACK);
        txRectangle(0, 0, 1090, 600);
        if (strok == 0)
            {
            txSetColor(TX_WHITE);
            txSetFillColor(TX_WHITE);
            txRectangle(400, 205, 410, 210);
            txDrawText(420, 200, 620, 300, "Старт\n"
                                           "Цвет платформ\n"
                                           "нажмите X для выбора");

            if (GetAsyncKeyState(88))
                {
                time = 1;
                }
            }
         if (strok == 1)
            {
            txSetColor(TX_WHITE);
            txSetFillColor(TX_WHITE);
            txRectangle(400, 215, 410, 220);
            txDrawText(420, 200, 620, 300, "Старт\n"
                                           "Цвет платформ\n"
                                           "нажмите X для выбора");

            if (GetAsyncKeyState(88))
                {
                strok = 3;
                }
            }
         if (strok == 3)
            {
            txSetColor(TX_WHITE);
            txSetFillColor(TX_WHITE);
            if (choose == 0)
                {
                txRectangle(400, 205, 410, 210);
                txDrawText(420, 200, 620, 300, "Игрок Один\n"
                                           "Игрок Два\n"
                                           "Выход\n"
                                           "нажмите -> для выбора");
                if (GetAsyncKeyState(VK_RIGHT))
                    {
                    while (GetAsyncKeyState(32) == 0)
                        {
                        if (GetAsyncKeyState(VK_UP))
                            {
                            i += 5;
                            j += 7;
                            l += 9;
                            one->color = RGB (i, j, l);
                            }
                        txSetColor(one->color);
                        txSetFillColor(one->color);
                        txRectangle(0, 0, 1090, 600);
                        txSleep(10);
                        }

                    }
                }
              else if (choose == 1)
                {
                txRectangle(400, 215, 410, 220);
                txDrawText(420, 200, 620, 300, "Игрок Один\n"
                                           "Игрок Два\n"
                                           "Выход\n"
                                           "нажмите -> для выбора");
                if (GetAsyncKeyState(VK_RIGHT))
                    {
                    while (GetAsyncKeyState(32) == 0)
                        {
                        if (GetAsyncKeyState(VK_UP))
                            {
                            i += 5;
                            j += 7;
                            l += 9;
                            two->color = RGB (i, j, l);
                            }
                        txSetColor(two->color);
                        txSetFillColor(two->color);
                        txRectangle(0, 0, 1090, 600);
                        txSleep(10);
                        }
                    }
                }
             else if (choose == 2)
                {
                txRectangle(400, 230, 410, 235);
                txDrawText(420, 200, 620, 300, "Игрок Один\n"
                                           "Игрок Два\n"
                                           "Выход\n"
                                           "нажмите пробел для выбора");
                if (GetAsyncKeyState(32))
                    {
                    strok = 1;
                    }
                }

            }
        if (GetAsyncKeyState(49) && strok != 3)
            {
            strok = 0;
            }

        if (GetAsyncKeyState(50) && strok != 3)
            {
            strok = 1;
            }

         if (strok == 3)
            {
            if (GetAsyncKeyState(49))
                {
                choose = 0;
                }
            if (GetAsyncKeyState(50))
                {
                choose = 1;
                }
            if (GetAsyncKeyState(51))
                {
                choose = 2;
                }
            }
            txSleep(10);
        }
    }

