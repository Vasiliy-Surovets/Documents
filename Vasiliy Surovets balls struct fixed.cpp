#include <TXlib.h>

struct Ball
    {
    int x, y, r;
    double Vx, Vy;
    COLORREF color;
    };
struct Box
    {
    int a1, b1, a2, b2;
    };

Box draw_box(Box a);
Ball draw(Ball one);
Ball balls(Ball one, Box first);


int main() // main
    {
    txCreateWindow (1080, 600);
    txTextCursor(0);

    Ball one = {100, 150, 20, 9, 4, RGB( 100, 35, 67)}; //можно изменять точку старта (x, y),
    Ball two = {55, 300, 40, 3, 7, RGB( 130, 100, 60)}; //радиус,
    Ball three = {500, 250, 13, 15, 7, RGB( 10, 255, 30)}; // скорость (Vx, Vy) и цвет.
    Box first = {10, 100, 400, 400}; //Изменение размера коробок. Первые два числа координаты верхней левой точки (x, y),
    Box second = {450, 100, 1000, 400}; // последние - координаты нижней правой
    while (GetAsyncKeyState(VK_ESCAPE) == 0)
        {
        draw_box(first);
        draw_box(second);

        one = balls(one, first);
        two = balls(two, first);
        three = balls(three, second);

        draw(one);
        draw(two);
        draw(three);
        txSleep (10);
        }
    }





Ball balls(struct Ball one, struct Box first)
    {
    txSetColor (one.color);
    txSetFillColor (one.color);
    one.x += one.Vx;
    one.y += one.Vy;

    if (one.x + one.r > first.a2)
        {
        one.x  -= (one.x - first.a2 + one.r) * 2;
        one.Vx *= -1;
        }
    if (one.x - one.r < first.a1)
        {
        one.x  -= (one.x - first.a1 - one.r) * 2;
        one.Vx *= -1;
        }
    if (one.y + one.r > first.b2)
        {
        one.y  -= (one.y - first.b2 + one.r) * 2;
        one.Vy *= -1;
        }
    if (one.y - one.r < first.b1)
        {
        one.y  -= (one.y - first.b1 - one.r) * 2;
        one.Vy *= -1;
        }
    return one;
    }

Ball draw(struct Ball one)
    {
    txSetColor (one.color);
    txSetFillColor (one.color);
    txCircle (one.x, one.y, one.r);
    }

Box draw_box(struct Box a)
    {
    txSetColor (TX_WHITE);
    txSetFillColor (TX_BLACK);
    txRectangle(a.a1 - 1, a.b1 - 1, a.a2 + 1, a.b2 + 1);
    }
