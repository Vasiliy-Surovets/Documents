#include <TXlib.h>

class Bot
{
     public:

        void draw();
        void sprite(HDC a);
        int randomizer();
        Bot();
        ~Bot();
        int upravbot();
        int right();
        int down();
        int left();
        int up();
        int coord();
        void dvish(int a);

    private:
        int x, y, wh;
        int xSrc, ySrc, whSrc, time = 1;
        int shot, xtim, ytim;
        int V, bank = 0, poloz, game = 0;
        HDC text;
};

void Bot::sprite(HDC a)
    {
        text = a;
    }

Bot::Bot()
    {
        x = 2;
        y = 16;
        wh = 50;
        whSrc = 9;
        V = 1;
        xSrc = 1;
        ySrc = 1;
        xtim = x;
        ytim = y;

    }
Bot::~Bot()
{
    cout << "Bot OK" << std::endl;
}

int Bot::right()
    {
        if (xtim + 1 < 18)
        {
            xtim++;
        }
        if (time == 1)
        {
            xSrc = 1;
            ySrc = 31;
            time = 0;
        }
        else
        {
            xSrc = 11;
            ySrc = 31;
            time = 1;
        }
        shot = 2;
        return 100 * xtim + ytim;
    }
int Bot::down()
    {
        if (ytim + 1 < 18)
        {
            ytim++;
        }
        if (time == 1)
        {
            xSrc = 21;
            ySrc = 31;
            time = 0;
        }
        else
        {
            xSrc = 31;
            ySrc = 31;
            time = 1;
        }
        shot = 3;
        return 100 * xtim + ytim;
    }
int Bot::left()
    {
        if (xtim - 1 > -1)
        {
            xtim--;
        }
        if (time == 1)
        {
            xSrc = 21;
            ySrc = 21;
            time = 0;
        }
        else
        {
            xSrc = 31;
            ySrc = 21;
            time = 1;
        }
        shot = 4;
        return 100 * xtim + ytim;
    }
int Bot::up()
    {
        if (ytim - 1 > -1)
        {
            ytim--;
        }
        if (time == 1)
        {
            xSrc = 1;
            ySrc = 21;
            time = 0;
        }
        else
        {
            xSrc = 11;
            ySrc = 21;
            time = 1;
        }
        shot = 1;
        return 100 * xtim + ytim;
    }

void Bot::dvish(int a)
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

int Bot::coord()
    {
        return 100 * x + y;
    }
int Bot::upravbot()
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
int Bot::randomizer()
    {
        int a;
        a = rand() % 4 + 1;
    }


void Bot::draw()
    {
        if (game == 0)
        {
            Win32::TransparentBlt (txDC(), x * wh, y * wh, wh, wh, text, xSrc, ySrc, whSrc, whSrc, TX_BLACK);
        }
    }
