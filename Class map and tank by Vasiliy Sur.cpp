#include <TXlib.h>
#include "tank.h"
#include "map.h"
#include "shot.h"

int main()
{
    txTextCursor(0);
    txCreateWindow(900, 900);

    Tank tank;
    Map card;
    Bullet gold;
    int i, z;
    HDC a = txLoadImage("dendy.bmp");
    tank.sprite(a);
    card.sprite(a);
    gold.in(50, a, 2, 10, 9);
    tank.getxyhw(9, 10, 50, 9, 1, 1, 1);
    card.getk(50, 9);
    card.inc();
    while (GetAsyncKeyState(VK_ESCAPE) == 0)
        {
            txBegin();
            card.draw();
            i = tank.uprav();
            gold.naprav();
            if (GetAsyncKeyState(32))
            gold.shot(i);

            i = card.checkin(i);

            tank.dvish(i);
            tank.draw();
            z = gold.out();
            z = card.burst(z);
            gold.shotin(z);
            gold.draw();
            txSleep(50);
            txEnd();
        }
    txDeleteDC(a);
    return 0;
}
