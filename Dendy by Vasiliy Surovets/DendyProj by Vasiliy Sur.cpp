#include <TXlib.h>
#include "tankForDendyByVasSur.h"
#include "mapForDendyByVasSur.h"
#include "shotForDendyByVasSur.h"

int main()
{
    txTextCursor(0);
    txCreateWindow(900, 900);

    Tank tank;
    Tank bot;
    Map card;
    Bullet gold;
    int i, z = 0, s;
    HDC a = txLoadImage("dendyForDendyByVasSur.bmp");
    tank.sprite(a);
    bot.sprite(a);

    card.sprite(a);
    gold.in(50, a, 7, 16, 9);
    tank.getxyhw(9, 10, 50, 9, 1, 1, 1);
    bot.getxyhw(2, 16, 50, 9, 1, 1, 1);
    card.getk(50, 9);
    card.inc();
    while (GetAsyncKeyState(VK_ESCAPE) == 0)
        {
            txBegin();
            card.draw();

            i = tank.uprav();
            i = card.checkin(i);
            tank.dvish(i);
            tank.draw();
            i = bot.upravbot();
            i = card.checkin(i);
            bot.dvish(i);
            bot.draw();
            s = tank.cell();
            gold.naprav(s);


            i = tank.coord();
            if (GetAsyncKeyState(32) && z == 0)
                z = gold.shot(i);
            if (z == 1)
            {

                i = gold.napravafter();
                i = card.burst(i);
                gold.out(i);
                z = gold.draw();
            }
            txSleep(50);
            txEnd();
        }
    txDeleteDC(a);
    return 0;
}
