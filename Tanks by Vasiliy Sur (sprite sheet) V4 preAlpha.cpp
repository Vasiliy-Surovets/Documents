#include <TXlib.h>

struct T90
    {
    HDC  dest;
    int  x, y, width, height;
    HDC  src;
    int  xSrc, ySrc, wSrc, hSrc;
    COLORREF  color;
    int bank, time, b, c, bx, by, bplace;
    void up();
    void down();
    void left();
    void right();

    };



void contbody (T90 *body, T90 *head);
void drawbody (T90 *body, T90 *head);
void conthead (T90 *head);
void smoke(T90 *a);

int main()
    {
        txTextCursor(0);
        txCreateWindow(1080, 600);
        HDC tank = txLoadImage("C:\\Users\\admin\\Downloads\\tank and bak555.bmp");
        T90 body = {txDC(), 30, 100, 150, 115, tank, 222, 0, 30, 23, RGB(0, 0, 0), 1, 0, 0, 0};
        T90 head = {txDC(), 50, 70, 175, 175, tank, 168, 66, 35, 35, RGB(0, 0, 0), 1, 0, 0, 0};

        while (GetAsyncKeyState(VK_ESCAPE) == 0)
        {
         contbody(&body, &head);
         conthead(&head);
         drawbody(&body, &head);
         //smoke(&head);

         txSleep(10);
         txSetFillColor(TX_WHITE);
         txSetColor(TX_WHITE);
         txRectangle(0, 0, 1080, 600);
        }
        txDeleteDC(tank);
        return 0;
    }

void contbody (T90 *body, T90 *head)
    {
        if (GetAsyncKeyState(87))
        {

            body->up();


        }
        if (GetAsyncKeyState(68))
        {

            body->left();
        }
        if (GetAsyncKeyState(83))
        {

            body->down();
        }
        if (GetAsyncKeyState(65))
        {

            body->right();
        }
        if (GetAsyncKeyState(87) && GetAsyncKeyState(68))
        {

            if (body->bank == 1)
            {
                body->xSrc = 286;
                body->ySrc = 6;
                body->wSrc = 35;
                body->hSrc = 36;
                body->bank = 0;
                body->width = 175;
                body->height = 180;
            }
            else
            {
                body->xSrc = 324;
                body->ySrc = 6;
                body->wSrc = 35;
                body->hSrc = 36;
                body->bank = 1;
                body->width = 175;
                body->height = 180;
            }
            if (body->y + 3 > 3)
            {
                body->y += 3;
            }
            else
            {
                body->y = 0;
            }
            if (body->x - 3 + body->width <= 1080)
            {
                body->x -= 3;
            }
            else
            {
                body->x = 1080 - body->width;
            }
            head->x = body->x + 15;
            head->y = body->y - 10;
        }
        if (GetAsyncKeyState(83) && GetAsyncKeyState(68))
        {

            if (body->bank == 1)
            {
                body->xSrc = 363;
                body->ySrc = 46;
                body->wSrc = 36;
                body->hSrc = 35;
                body->bank = 0;
                body->width = 180;
                body->height = 175;
            }
            else
            {
                body->xSrc = 403;
                body->ySrc = 46;
                body->wSrc = 36;
                body->hSrc = 35;
                body->bank = 1;
                body->width = 180;
                body->height = 175;
            }
            if (body->y - 3 + body->height <= 600)
            {
                body->y -= 3;
            }
            else
            {
                body->y = 600 - body->height;
            }
            if (body->x - 3 + body->width <= 1080)
            {
                body->x -= 3;
            }
            else
            {
                body->x = 1080 - body->width;
            }
            head->x = body->x + 15;
            head->y = body->y + 15;
        }
        if (GetAsyncKeyState(83) && GetAsyncKeyState(65))
        {

            if (body->bank == 1)
            {
                body->xSrc = 286;
                body->ySrc = 46;
                body->wSrc = 35;
                body->hSrc = 36;
                body->bank = 0;
                body->width = 175;
                body->height = 180;
            }
            else
            {
                body->xSrc = 324;
                body->ySrc = 46;
                body->wSrc = 35;
                body->hSrc = 36;
                body->bank = 1;
                body->width = 175;
                body->height = 180;
            }
            if (body->y - 3 + body->height <= 600)
            {
                body->y -= 3;
            }
            else
            {
                body->y = 600 - body->height;
            }
            if (body->x + 3 > 3)
            {
                body->x += 3;
            }
            else
            {
                body->x = 0;
            }
            head->x = body->x - 15;
            head->y = body->y + 15;
        }
        if (GetAsyncKeyState(65) && GetAsyncKeyState(87))
        {

            if (body->bank == 1)
            {
                body->xSrc = 363;
                body->ySrc = 6;
                body->wSrc = 36;
                body->hSrc = 35;
                body->bank = 0;
                body->width = 175;
                body->height = 180;
            }
            else
            {
                body->xSrc = 403;
                body->ySrc = 6;
                body->wSrc = 36;
                body->hSrc = 35;
                body->bank = 1;
                body->width = 175;
                body->height = 180;
            }
            if (body->y + 3 > 3)
            {
                body->y += 3;
            }
            else
            {
                body->y = 0;
            }
            if (body->x + 3 > 3)
            {
                body->x += 3;
            }
            else
            {
                body->x = 0;
            }
            head->x = body->x - 10;
            head->y = body->y - 10;
        }
    }

void drawbody (T90 *body, T90 *head)
    {
        Win32::TransparentBlt (body->dest, body->x, body->y, body->width, body->height, body->src, body->xSrc, body->ySrc, body->wSrc, body->hSrc, body->color);
        Win32::TransparentBlt (head->dest, body->bx, body->by, head->width, head->height, head->src, head->xSrc, head->ySrc, head->wSrc, head->hSrc, head->color);
    }

void conthead (T90 *head)
    {
        if (GetAsyncKeyState(75))
        {
            head->xSrc = 242;
            head->ySrc = 66;

        }
        if (GetAsyncKeyState(79))
        {
            head->xSrc = 131;
            head->ySrc = 66;
            head->bank = 1;
        }
        if (GetAsyncKeyState(186))
        {
            head->xSrc = 168;
            head->ySrc = 66;
        }
        if (GetAsyncKeyState(76))
        {
            head->xSrc = 205;
            head->ySrc = 66;
        }
        if (GetAsyncKeyState(75) && GetAsyncKeyState(79))
        {
            head->xSrc = 242;
            head->ySrc = 102;
        }
        if (GetAsyncKeyState(75) && GetAsyncKeyState(76))
        {
            head->xSrc = 205;
            head->ySrc = 102;
        }
        if (GetAsyncKeyState(79) && GetAsyncKeyState(186))
        {
            head->xSrc = 131;
            head->ySrc = 102;
        }
        if (GetAsyncKeyState(186) && GetAsyncKeyState(76))
        {
            head->xSrc = 168;
            head->ySrc = 102;
        }
    }

void smoke(T90 *a)
    {
        int b, c;
        if (GetAsyncKeyState(32) && a->time == 0)
        {
            if (a->bank == 1)
            {
                a->b = a->x + 18 * 5 - 5;
                a->c = a->y;
            }
            else if (a->bank == 2)
            {
                a->b = a->x + 34 * 5;
                a->c = a->y + 17 * 5;
            }
            a->time = 4;
            Win32::TransparentBlt (a->dest, a->b, a->c, 55, 55, a->src, 131, 143, 11, 11, a->color);
        }
        else
        {
            if (a->time == 4)
            {
                Win32::TransparentBlt (a->dest, a->b, a->c, 55, 55, a->src, 143, 143, 11, 11, a->color);
                a->time = 0;
            }
        }
    }
void T90::up()
    {
        int a = 5;
        y -= 10;
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
        int a = 5;
        y += 10;
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

void T90::left()
    {
        int a = 5;
        x += 10;
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
void T90::right()
    {
        int a = 5;
        x -= 10;
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
