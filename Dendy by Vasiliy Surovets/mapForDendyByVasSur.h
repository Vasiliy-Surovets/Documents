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
                        if (i == 0 || j == 0 || i == 17 || j == 17 || i == 5 && j == 7 || i == 7 && j == 5 || i == 10 && j == 7 || i == 10 && j == 5)
                            {
                                block[i][j] = 3;
                            }
                        else if (j == i || (j + i) == 17)
                            {
                                block[i][j] = 2;
                            }
                        else if (j == 11 && i == 14)
                            {
                                block[i][j] = 5;
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
                        else if (block[i][j] == 4)
                            {
                                Win32::TransparentBlt (txDC(), i * k, j * k, k, k, text, 71, 1, whSrc, whSrc, TX_BLACK);
                            }
                        else if (block[i][j] == 5)
                            {
                                Win32::TransparentBlt (txDC(), i * k, j * k, k, k, text, 51, 11, whSrc, whSrc, TX_BLACK);
                            }
                        else if (block[i][j] == 6)
                            {
                                Win32::TransparentBlt (txDC(), i * k, j * k, k, k, text, 61, 11, whSrc, whSrc, TX_BLACK);
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
        i = a / 100;
        j = a - (a / 100) * 100;

        c = block[i][j];



        if (c == 2)
        {
            block[i][j] = 4;
        }
        if (c == 5)
        {
            block[i][j] = 6;
        }
        return c;

    }

