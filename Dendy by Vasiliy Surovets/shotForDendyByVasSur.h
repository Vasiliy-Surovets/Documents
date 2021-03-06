#include <TXlib.h>

class Bullet
{

    public:
    int shot(int a);
    int draw();
    void in(int a, HDC b, int z, int c, int v);
    int naprav(int a);
    void out(int a);
    void shotin(int a);
    int up();
    int right();
    int down();
    int left();
    int napravafter();

    private:
    int x, y, xb, yb, k, wh, now = 0;
    int bank = 1;
    HDC text;


};

int Bullet::shot(int a)
    {
            x = a / 100;
            y = a - a / 100 * 100;
            now = 1;

            return now;
    }
void Bullet::shotin(int a)
    {
        x = a / 100;
        y = a - a / 100 * 100;
        if (a / 100000 == 5)
        {
            x = -1;
            y = -1;
            bank = 5;
        }
    }
int Bullet::draw()
    {
        Win32::TransparentBlt (txDC(), x * k, y * k, k, k, text, 41, 11, wh, wh, TX_BLACK);
        return now;
    }
void Bullet::in(int a, HDC b, int z, int c, int v)
    {
        text = b;
        k = a;
        x = z;
        y = c;
        wh = v;
    }
int Bullet::naprav(int a)
    {
        if (now == 0)
        bank = a;
    }
int Bullet::napravafter()
    {
            if (bank == 1)
            {
                return up();
            }
            else if (bank == 2)
            {
                return right();
            }
            else if (bank == 3)
            {
                return down();
            }
            else if (bank == 4)
            {
                return left();
            }
    }
void Bullet::out(int a)
    {
        if (a == 2 || a == 3 || a == 5)
        {
            now = 0;
            x = -1;
            y = -1;
        }
    }
int Bullet::right()
    {
        if (x + 1 < 18)
        {
            x++;
        }
        return 100 * x + y;
    }
int Bullet::down()
    {
        if (y + 1 < 18)
        {
            y++;
        }
        return 100 * x + y;
    }
int Bullet::left()
    {
        if (x - 1 > -1)
        {
            x--;
        }
        return 100 * x + y;
    }
int Bullet::up()
    {
        if (y - 1 > -1)
        {
            y--;
        }
        return 100 * x + y;
    }
