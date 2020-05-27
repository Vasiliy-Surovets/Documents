#include <TXlib.h>

class Bullet
{

    public:
    void shot(int a);
    void draw();
    void in(int a, HDC b, int z, int c, int v);
    void naprav();
    int out();
    void shotin(int a);

    private:
    int x, y, xb, yb, k, wh, now = 0;
    int bank = 1;
    HDC text;


};

void Bullet::shot(int a)
    {
            x = a / 100;
            y = a - a / 100 * 100;
            now = 1;
    }
void Bullet::shotin(int a)
    {
        x = a / 100;
        y = a - a / 100 * 100;
        if (a / 10000 == 5)
        {
            x = -1;
            y = -1;
            bank = 5;
        }
    }
void Bullet::draw()
    {
        Win32::TransparentBlt (txDC(), x * k, y * k, k, k, text, 41, 11, wh, wh, TX_BLACK);
    }
void Bullet::in(int a, HDC b, int z, int c, int v)
    {
        text = b;
        k = a;
        x = z;
        y = c;
        wh = v;
    }
void Bullet::naprav()
    {
        if (bank == 5)
        {
            now = 0;
        }
        if (now == 0)
        {
            if (GetAsyncKeyState(87))
            {
                bank = 1;
            }
            else if (GetAsyncKeyState(68))
            {
                bank = 2;
            }
            else if (GetAsyncKeyState(83))
            {
                bank = 3;
            }
            else if (GetAsyncKeyState(65))
            {
                bank = 4;
            }
        }
    }
int Bullet::out()
    {
        return 100 * x + y + bank * 10000;
    }

