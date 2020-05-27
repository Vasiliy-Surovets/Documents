#include <TXlib.h>

struct T90
    {
    HDC  dest;
    int  x, y, width, height;
    HDC  src;
    int  xSrc, ySrc, wSrc, hSrc;
    COLORREF  color;
    int bx, by, bw, bh, bxsrc, bysrc, wsrc, hsrc, mxsrc, mysrc, bplace, bank, time;
    void uprav();
    void conthead();
    void drawbody();
    void up();
    void down();
    void right();
    void left();
    void leftup();
    void rightup();
    void rightdown();
    void leftdown();

    };








int main()
    {
        txTextCursor(0);
        txCreateWindow(1080, 600);
        HDC tank = txLoadImage("TankAndBak1000.bmp");
        T90 body = {txDC(), 540, 300, 150, 115, tank, 222, 0, 30, 23, RGB(0, 0, 0), 555, 260, 35 * 5, 35 * 5, 131, 66, 35, 35, 300, 300};

        while (GetAsyncKeyState(VK_ESCAPE) == 0)
        {
         body.uprav();
         body.conthead();
         body.drawbody();


         txSleep(10);
         txClear();
        }
        txDeleteDC(tank);
        return 0;
    }



void T90::drawbody()
    {
        Win32::TransparentBlt (dest, 0, 0, 1080, 600, src, mxsrc, mysrc, 108, 60, TX_PINK);
        Win32::TransparentBlt (dest, x, y, width, height, src, xSrc, ySrc, wSrc, hSrc, color);
        Win32::TransparentBlt (dest, bx, by, bw, bh, src, bxsrc, bysrc, wsrc, hsrc, color);
    }

void T90::conthead()
    {
        if (GetAsyncKeyState(75))
        {
            bxsrc = 242;
            bysrc = 66;
        }
        if (GetAsyncKeyState(79))
        {
            bxsrc = 131;
            bysrc = 66;
        }
        if (GetAsyncKeyState(186))
        {
            bxsrc = 168;
            bysrc = 66;
        }
        if (GetAsyncKeyState(76))
        {
            bxsrc = 205;
            bysrc = 66;
        }
        if (GetAsyncKeyState(75) && GetAsyncKeyState(79))
        {
            bxsrc = 242;
            bysrc = 102;
        }
        if (GetAsyncKeyState(75) && GetAsyncKeyState(76))
        {
            bxsrc = 205;
            bysrc = 102;
        }
        if (GetAsyncKeyState(79) && GetAsyncKeyState(186))
        {
            bxsrc = 131;
            bysrc = 102;
        }
        if (GetAsyncKeyState(186) && GetAsyncKeyState(76))
        {
            bxsrc = 168;
            bysrc = 102;
        }
    }


void T90::up()
    {
        int b = 10;
        int a = 5;
        if (y - b > 200)
            {
                y -= b;
            }
        else
            {
                if (mysrc - 2 > 212)
                    {
                        mysrc -= 2;
                    }
                else if (y - b >= 0)
                    {
                        y -= b;
                    }
            }
        wSrc = 23;
        hSrc = 30;
        width = 23 * a;
        height = 30 * a;
        ySrc = 0;
        bx = x - 6 * a;
        by = y - 9 * a;

        if (bank == 1)
        {
            xSrc = 131;
            bank = 0;
        }
        else
        {
            xSrc = 160;
            bank = 1;
        }
    }
void T90::down()
    {
        int b = 10;
        int a = 5;
        if (y + b < 400)
            {
                y += b;
            }
        else
            {
                if (mysrc + 2 < 652)
                    {
                        mysrc += 2;
                    }
                else if (y + b <= 600 - height)
                    {
                        y += b;
                    }
            }
        wSrc = 23;
        hSrc = 30;
        width = 23 * a;
        height = 30 * a;
        ySrc = 31;
        bx = x - 6 * a;
        by = y + 4 * a;

        if (bank == 1)
        {
            xSrc = 131;
            bank = 0;
        }
        else
        {
            xSrc = 160;
            bank = 1;

        }
    }

void T90::right()
    {
        int b = 10;
        int a = 5;
        if (x + b < 840)
            {
                x += b;
            }
        else
            {
                if (mxsrc + 2 < 392)
                    {
                        mxsrc += 2;
                    }
                else if (x + b <= 1080 - width)
                    {
                        x += b;
                    }
            }
        wSrc = 30;
        hSrc = 23;
        width = 30 * a;
        height = 23 * a;
        ySrc = 0;
        bx = x + 4 * a;
        by = y - 6 * a;

        if (bank == 1)
        {
            xSrc = 188;
            bank = 0;
        }
        else
        {
            xSrc = 222;
            bank = 1;
        }
    }
void T90::left()
    {
        int b = 10;
        int a = 5;
        if (x - b > 240)
            {
                x -= b;
            }
        else
            {
                if (mxsrc - 2 > 0)
                    {
                        mxsrc -= 2;
                    }
                else if (x - b >= 0)
                    {
                        x -= b;
                    }
            }
        wSrc = 30;
        hSrc = 23;
        width = 30 * a;
        height = 23 * a;
        ySrc = 31;
        bx = x - 9 * a;
        by = y - 6 * a;

        if (bank == 1)
        {
            xSrc = 188;
            bank = 0;
        }
        else
        {
            xSrc = 222;
            bank = 1;
        }
    }
void T90::leftup()
    {
        x += 3;
        y += 3;
        int a = 5;
        wSrc = 36;
        hSrc = 35;
        width = 36 * a;
        height = 35 * a;
        ySrc = 6;
        bx = x - 2 * a;
        by = y - 3 * a;

        if (bank == 1)
        {
            xSrc = 363;
            bank = 0;
        }
        else
        {
            xSrc = 403;
            bank = 1;
        }
    }

void T90::rightup()
    {
        x -= 3;
        y += 3;
        int a = 5;
        wSrc = 35;
        hSrc = 36;
        width = 35 * a;
        height = 36 * a;
        ySrc = 6;
        bx = x + 3 * a;
        by = y - 2 * a;

        if (bank == 1)
        {
            xSrc = 324;
            bank = 0;
        }
        else
        {
            xSrc = 285;
            bank = 1;
        }
    }
void T90::rightdown()
    {
        x -= 3;
        y -= 3;
        int a = 5;
        wSrc = 36;
        hSrc = 35;
        width = 36 * a;
        height = 35 * a;
        ySrc = 46;
        bx = x + 3 * a;
        by = y + 3 * a;

        if (bank == 1)
        {
            xSrc = 403;
            bank = 0;
        }
        else
        {
            xSrc = 363;
            bank = 1;
        }
    }
void T90::leftdown()
    {
        x += 3;
        y -= 3;
        int a = 5;
        wSrc = 35;
        hSrc = 36;
        width = 35 * a;
        height = 36 * a;
        ySrc = 46;
        bx = x - 3 * a;
        by = y + 3 * a;

        if (bank == 1)
        {
            xSrc = 324;
            bank = 0;
        }
        else
        {
            xSrc = 285;
            bank = 1;
        }
    }

void T90::uprav()
    {
        if (GetAsyncKeyState(87))
        {
            up();
        }
        if (GetAsyncKeyState(68))
        {
            right();
        }
        if (GetAsyncKeyState(83))
        {
            down();
        }
        if (GetAsyncKeyState(65))
        {
            left();
        }
        if (GetAsyncKeyState(87) && GetAsyncKeyState(68))
        {
            rightup();
        }
        if (GetAsyncKeyState(83) && GetAsyncKeyState(68))
        {
            rightdown();
        }
        if (GetAsyncKeyState(83) && GetAsyncKeyState(65))
        {
            leftdown();
        }
        if (GetAsyncKeyState(65) && GetAsyncKeyState(87))
        {
            leftup();
        }
    }


