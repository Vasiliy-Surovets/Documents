#include <TXlib.h>

struct T90
    {
    HDC  dest;
    int  x;
    int  y;
    int  width;
    int  height;
    HDC  src;
    int  xSrc;
    int  ySrc;
    int  wSrc;
    int  hSrc;
    COLORREF  color;
    int bank;
    int time;
    int b;
    int c;
    };
void contbody (T90 *body, T90 *head);
void drawbody (T90 *body, T90 *head);
void conthead (T90 *head);
void smoke(T90 *a);

int main()
    {
        txTextCursor(0);
        txCreateWindow(1080, 600);
        HDC tank = txLoadImage("C:\\Users\\Vasya\\Pictures\\фотошоп\\tank and bak555.bmp");
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

            if (body->bank == 1)
            {
                body->xSrc = 131;
                body->ySrc = 0;
                body->wSrc = 23;
                body->hSrc = 30;
                body->bank = 0;
                body->width = 115;
                body->height = 150;
            }
            else
            {
                body->xSrc = 160;
                body->ySrc = 0;
                body->wSrc = 23;
                body->hSrc = 30;
                body->bank = 1;
                body->width = 115;
                body->height = 150;
            }
            if (body->y - 10 >= 0)
            {
                body->y -= 10;
            }
            head->x = body->x - 30;
            head->y = body->y - 45;


        }
        if (GetAsyncKeyState(68))
        {

            if (body->bank == 1)
            {
                body->xSrc = 188;
                body->ySrc = 0;
                body->wSrc = 30;
                body->hSrc = 23;
                body->bank = 0;
                body->width = 150;
                body->height = 115;
            }
            else
            {
                body->xSrc = 222;
                body->ySrc = 0;
                body->wSrc = 30;
                body->hSrc = 23;
                body->bank = 1;
                body->width = 150;
                body->height = 115;
            }
            if (body->x + body->width + 10 <= 1080)
            {
                body->x += 10;
            }
            head->x = body->x + 20;
            head->y = body->y - 30;
        }
        if (GetAsyncKeyState(83))
        {

            if (body->bank == 1)
            {
                body->xSrc = 131;
                body->ySrc = 31;
                body->wSrc = 23;
                body->hSrc = 30;
                body->bank = 0;
                body->width = 115;
                body->height = 150;
            }
            else
            {
                body->xSrc = 160;
                body->ySrc = 31;
                body->wSrc = 23;
                body->hSrc = 30;
                body->bank = 1;
                body->width = 115;
                body->height = 150;
            }
            if (body->y + body->height + 10 <= 600)
            {
                body->y += 10;
            }
            head->x = body->x - 30;
            head->y = body->y + 20;
        }
        if (GetAsyncKeyState(65))
        {

            if (body->bank == 1)
            {
                body->xSrc = 188;
                body->ySrc = 31;
                body->wSrc = 30;
                body->hSrc = 23;
                body->bank = 0;
                body->width = 150;
                body->height = 115;
            }
            else
            {
                body->xSrc = 222;
                body->ySrc = 31;
                body->wSrc = 30;
                body->hSrc = 23;
                body->bank = 1;
                body->width = 150;
                body->height = 115;
            }
            if (body->x - 10 >= 0)
            {
                body->x -= 10;
            }
            head->x = body->x - 45;
            head->y = body->y - 30;
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
        Win32::TransparentBlt (head->dest, head->x, head->y, head->width, head->height, head->src, head->xSrc, head->ySrc, head->wSrc, head->hSrc, head->color);
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
