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
    };
void contbody (T90 *body, T90 *head);
void drawbody (T90 *body, T90 *head);
void conthead (T90 *head);

int main()
    {
        txTextCursor(0);
        txCreateWindow(1080, 600);
        HDC tank = txLoadImage("C:\\Users\\admin\\Downloads\\tank and bak3.bmp");
        T90 body = {txDC(), 30, 100, 70, 60, tank, 1, 1, 7, 6, RGB(0, 0, 0), 1};
        T90 head = {txDC(), 10, 80, 100, 100, tank, 6, 30, 10, 10, RGB(0, 0, 0), 1};

        while (GetAsyncKeyState(VK_ESCAPE) == 0)
        {
         contbody(&body, &head);
         conthead(&head);
         drawbody(&body, &head);

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
            head->x = body->x - 20;
            head->y = body->y - 10;


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
            head->x = body->x - 20;
            head->y = body->y - 20;
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
            head->x = body->x - 20;
            head->y = body->y - 20;
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
            head->x = body->x - 10;
            head->y = body->y - 20;
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
            head->x = body->x - 10;
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
            head->x = body->x - 10;
            head->y = body->y - 10;
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
            head->x = body->x - 10;
            head->y = body->y - 10;
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
            head->xSrc = 45;
            head->ySrc = 30;
        }
        if (GetAsyncKeyState(79))
        {
            head->xSrc = 6;
            head->ySrc = 30;
        }
        if (GetAsyncKeyState(186))
        {
            head->xSrc = 19;
            head->ySrc = 30;
        }
        if (GetAsyncKeyState(76))
        {
            head->xSrc = 32;
            head->ySrc = 30;
        }
        if (GetAsyncKeyState(75) && GetAsyncKeyState(79))
        {
            head->xSrc = 19;
            head->ySrc = 42;
        }
        if (GetAsyncKeyState(75) && GetAsyncKeyState(76))
        {
            head->xSrc = 6;
            head->ySrc = 42;
        }
        if (GetAsyncKeyState(79) && GetAsyncKeyState(186))
        {
            head->xSrc = 32;
            head->ySrc = 42;
        }
        if (GetAsyncKeyState(186) && GetAsyncKeyState(76))
        {
            head->xSrc = 45;
            head->ySrc = 42;
        }
    }
