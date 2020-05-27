#include <TXlib.h>

class Tank
{
    public:

        int stolk(int a);
        int randomizer();
        void smoke();
        Tank();
        ~Tank();
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
        int V, bank = 0, poloz, smokex = -1, smokey = -1, sx, sy;
        HDC text;
};

Tank::Tank()
    {
        x = 2;
        y = 10;
        wh = 50;
        whSrc = 9;
        V = 1;
        xSrc = 1;
        ySrc = 1;
        xtim = x;
        ytim = y;


    }
Tank::~Tank()
{
    cout << "Tank OK" << std::endl;
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
            smokey = y;
            smokex = x;
            return 100 * x + y;
        }
    }

void Tank::draw()
    {
        Win32::TransparentBlt (txDC(), smokex * wh, smokey * wh, wh, wh, text, sx, sy, whSrc, whSrc, TX_BLACK);
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
        smokey = y;
        smokex = x;
        sx = 81;
        sy = 11;
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
        smokey = y;
        smokex = x;
        sx = 91;
        sy = 1;
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
        smokey = y;
        smokex = x;
        sx = 81;
        sy = 1;
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
        smokey = y;
        smokex = x;
        sx = 91;
        sy = 11;
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
        else if (a == 1 || a == 4 || a == 6 || a == 7)
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
int Tank::stolk(int a)
    {
        int i = a / 100;
        int j = a - a / 100 * 100;
        if (xtim == i && ytim == j)
        {
            xtim == x;
            ytim == y;
        }
    }
