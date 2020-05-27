#include <TXlib.h>

int main() {
 txCreateWindow (1080, 600);
 txTextCursor(0);
 int x = 6, y = 2, bank = 40, bank2 = 40, r = 40, i = 30, j = 25, l = 29, ii = 3, jj = 5, ll = 10; // x и y - скорость первого шарика, bank и bank2 координаты центра шарика
 int x2 = 3, y2 = 9, bank11 = 100, bank22 = 500, r2 = 15; // всё тоже самое, только для второго шара.
 int x3 = 14, y3 = 5, bank111 = 500, bank222 = 300, r3 = 34; // и для третьего.
 while (GetAsyncKeyState(VK_ESCAPE) == 0) {
    const COLORREF RAIBOW = RGB ( i, j, l); // первый шар
    txSetFillColor (RAIBOW);
    txSetColor (RAIBOW);
    bank += x;
    bank2 += y;

    if (i > 254 || i < 30) {
     ii = -ii;
    }
    if (j > 254 || j < 25) {
     jj = -jj;
    }
    if (l > 254 || l < 29) {
     ll = -ll;
    }
    i += ii;
    j += jj;
    l += ll;

    if (bank + r > 1070) {
        bank = bank - (bank - 1070 + r) * 2;
        x = -x;
    }
    if (bank - r < 10) {
        bank = bank - (bank - 10 - r) * 2;
        x = -x;
    }
    if (bank2 + r > 590) {
        bank2 = bank2 - (bank2 - 590 + r) * 2;
        y = -y;
    }
    if (bank2 - r < 10) {
        bank2 = bank2 - (bank2 - 10 - r) * 2;
        y = -y;
   }


    bank11 += x2; // второй
    bank22 += y2;

    if (bank11 + r2 > 1070) {
        bank11 = bank11 - (bank11 - 1070 + r2) * 2;
        x2 = -x2;
    }
    if (bank11 - r2 < 10) {
        bank11 = bank11 - (bank11 - 10 - r2) * 2;
        x2 = -x2;
    }
    if (bank22 + r2 > 590) {
        bank22 = bank22 - (bank22 - 590 + r2) * 2;
        y2 = -y2;
    }
    if (bank22 - r2 < 10) {
        bank22 = bank22 - (bank22 - 10 - r2) * 2;
        y2 = -y2;
    }




    bank111 += x3; // третий
    bank222 += y3;

    if (bank111 + r3 > 1070) {
        bank111 = bank111 - (bank111 - 1070 + r3) * 2;
        x3 = -x3;
    }
    if (bank111 - r3 < 10) {
        bank111 = bank111 - (bank111 - 10 - r3) * 2;
        x3 = -x3;
    }
    if (bank222 + r3 > 590) {
        bank222 = bank222 - (bank222 - 590 + r3) * 2;
        y3 = -y3;
    }
    if (bank222 - r3 < 10) {
        bank222 = bank222 - (bank222 - 10 - r3) * 2;
        y3 = -y3;
    }




    txCircle (bank, bank2, r); // первый

    txSetFillColor (TX_ORANGE);
    txSetColor (TX_ORANGE);


    txCircle (bank11, bank22, r2); // второй


    txSetFillColor (TX_LIGHTBLUE);
    txSetColor (TX_LIGHTBLUE);

    txCircle (bank111, bank222, r3);

    txSleep(10);
    txSetFillColor (TX_GREEN);
    txRectangle(0, 0, 1080, 600);
    txSetFillColor (TX_BLACK);
    txRectangle(10, 10, 1070, 590);
 }



}
