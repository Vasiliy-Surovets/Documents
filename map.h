#include <TXlib.h>

class Map
{
    public:
    void sprite(HDC a);
    void inc();
    int getk(int a, int c);
    void draw();
    int checkin(int g);
    int burst(int a);
    int up(int a);

    private:
    HDC text;
    int tip, k, whSrc;
    int block[18][18];
};

int Map::getk(int a, int c)
{
    k = a;
    whSrc = c;
}

void Map::sprite(HDC a)
    {
        text = a;
    }

void Map::inc()
    {
        for (int i = 0; i < 18; i++)
            {
                for (int j = 0; j < 18; j++)
                    {
                        if (i == 0 || j == 0 || i == 17 || j == 17)
                            {
                                block[i][j] = 3;
                            }
                        else if (j == i)
                            {
                                block[i][j] = 2;
                            }
                        else
                            {
                                block[i][j] = 1;
                            }
                    }
            }
    }
void Map::draw()
    {
        for (int i = 0; i < 18; i++)
            {
                for (int j = 0; j < 18; j++)
                    {
                        if (block[i][j] == 3)
                            {
                                Win32::TransparentBlt (txDC(), i * k, j * k, k, k, text, 51, 1, whSrc, whSrc, TX_BLACK);
                            }
                        else if (block[i][j] == 2)
                            {
                                Win32::TransparentBlt (txDC(), i * k, j * k, k, k, text, 41, 1, whSrc, whSrc, TX_BLACK);
                            }
                        else
                            {
                                Win32::TransparentBlt (txDC(), i * k, j * k, k, k, text, 61, 1, whSrc, whSrc, TX_BLACK);
                            }
                    }
            }
    }

int Map::checkin(int g)
    {
        int i, j, c;
        i = g / 100;
        j = g - (g / 100) * 100;
        c = block[i][j];
        return c;
    }

int Map::burst(int a)
    {
        int i, j, c;
        i = a / 100 - a / 10000 * 10000;
        j = a - (a / 100) * 100 - a / 10000 * 10000;
        c = a / 10000;
         if (c == 1)
            {
                c = i * 100 + j;
                return up(c);
            }
        else if (c == 2)
            {
                //return right();
            }
        else if (c == 3)
            {
                //return down();
            }
        else if (c == 4)
            {
                //return left();
            }
    }
 int Map::up(int a)
    {
        int i, j;
        i = a / 100;
        j = a - (a / 100) * 100;
        for (j = j - 1; j > -1; j--)
        {
            if (block[j][i] == 3)
                {
                  return 5 * 10000;
                }
            if (block[j][i] == 2)
                {
                  block[j][i] = 1;
                  return 5 * 10000;
                }
         }
         return 100 * j + i;
    }
