#include <TXlib.h>

class Tank
{
    public:

        int randomizer();
        int getxyhw(int a, int b, int c, int d, int i, int f, int j);
        int uprav();
        int upravbot();
        int up();
        void sprite(HDC a);
        void draw();
        int right();
        int down();
        int left();
        void dvish(int a);
        int cell();
        int coord();

    private:
        int x, y, wh;
        int xSrc, ySrc, whSrc, time = 1;
        int shot, xtim, ytim;
        int V, bank = 0, poloz;
        HDC text;
};

int Tank::getxyhw(int a, int b, int c, int d, int i, int f, int j)
    {
        x = a;
        y = b;
        wh = c;
        whSrc = d;
        V = i;
        xSrc = f;
        ySrc = j;
        xtim = x;
        ytim = y;

    }

int Tank::uprav()
    {
        if (GetAsyncKeyState(87))
        {
            return up();
        }
        else if (GetAsyncKeyState(68))
        {
            return right();
        }
        else if (GetAsyncKeyState(83))
        {
            return down();
        }
        else if (GetAsyncKeyState(65))
        {
            return left();
        }
        else
        {
            return 100 * x + y;
        }
    }

void Tank::draw()
    {
        Win32::TransparentBlt (txDC(), x * wh, y * wh, wh, wh, text, xSrc, ySrc, whSrc, whSrc, TX_BLACK);
    }
void Tank::sprite(HDC a)
    {
        text = a;
    }
int Tank::right()
    {
        if (xtim + 1 < 18)
        {
            xtim++;
        }
        if (time == 1)
        {
            xSrc = 1;
            ySrc = 11;
            time = 0;
        }
        else
        {
            xSrc = 11;
            ySrc = 11;
            time = 1;
        }
        shot = 2;
        return 100 * xtim + ytim;
    }
int Tank::down()
    {
        if (ytim + 1 < 18)
        {
            ytim++;
        }
        if (time == 1)
        {
            xSrc = 21;
            ySrc = 11;
            time = 0;
        }
        else
        {
            xSrc = 31;
            ySrc = 11;
            time = 1;
        }
        shot = 3;
        return 100 * xtim + ytim;
    }
int Tank::left()
    {
        if (xtim - 1 > -1)
        {
            xtim--;
        }
        if (time == 1)
        {
            xSrc = 21;
            ySrc = 1;
            time = 0;
        }
        else
        {
            xSrc = 31;
            ySrc = 1;
            time = 1;
        }
        shot = 4;
        return 100 * xtim + ytim;
    }
int Tank::up()
    {
        if (ytim - 1 > -1)
        {
            ytim--;
        }
        if (time == 1)
        {
            xSrc = 1;
            ySrc = 1;
            time = 0;
        }
        else
        {
            xSrc = 11;
            ySrc = 1;
            time = 1;
        }
        shot = 1;
        return 100 * xtim + ytim;
    }
void Tank::dvish(int a)
    {
        if (a == 3 || a == 5)
        {
            xtim = x;
            ytim = y;
        }
        else if (a == 2)
        {
            xtim = x;
            ytim = y;
        }
        else if (a == 1 || a == 4 || a == 6)
        {
            x = xtim;
            y = ytim;
        }
    }
int Tank::cell()
    {
        int c;
        c = shot;
        return c;
    }
int Tank::coord()
    {
        return 100 * x + y;
    }
int Tank::upravbot()
    {
        if (bank == 0)
        {
            poloz = randomizer();
            bank = 6;
        }
        bank--;
        if (poloz == 1)
        {
            return up();
        }
        else if (poloz == 2)
        {
            return right();
        }
        else if (poloz == 3)
        {
            return down();
        }
        else if (poloz == 4)
        {
            return left();
        }
        else
        {
            return 100 * x + y;
        }
    }
int Tank::randomizer()
    {
        int a;
        a = rand() % 4 + 1;
    }
