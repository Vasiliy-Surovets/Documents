#include <TXlib.h>
#include "tankForDendyByVasSur.h"
#include "mapForDendyByVasSur.h"
#include "shotForDendyByVasSur.h"
#include "botForDendyByVasSur.h"

int main()
{
    txTextCursor(0);
    txCreateWindow(900, 900);

    Tank tank;
    Bot bot;
    Map card;
    Bullet gold;
    int i, z = 0, s;
    HDC a = txLoadImage("dendyForDendyByVasSur.bmp");

    tank.sprite(a);
    bot.sprite(a);
    card.sprite(a);
    gold.sprite(a);


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
