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
void collide (Ball *one, Ball *two);

int main() // main
    {
    txCreateWindow (1080, 600);
    txTextCursor(0);

    Ball one = {100, 150, 14, 15, 11, RGB( 200, 35, 67)}; //можно изменять точку старта (x, y),
    Ball two = {55, 300, 15, 12, 10, RGB( 230, 100, 60)}; //радиус,
    Ball three = {500, 250, 16, 13, 12, RGB( 10, 255, 30)}; // скорость (Vx, Vy) и цвет.
    Ball four = {300, 150, 18, 17, 11, RGB( 100, 235, 67)};
    Ball five = {400, 150, 17, 13, 14, RGB( 100, 35, 167)};

    Box first = {10, 100, 1070, 500}; //Изменение размера коробок. Первые два числа координаты верхней левой точки (x, y),
    Box second = {450, 100, 1000, 400}; // последние - координаты нижней правой
    while (GetAsyncKeyState(VK_ESCAPE) == 0)
        {
        draw_box(first);
        //draw_box(second);

        draw(one);
        draw(two);
        draw(three);
        draw(four);
        draw(five);
        txSleep (10);

        one = balls(one, first);
        two = balls(two, first);
        three = balls(three, first);
        four = balls(four, first);
        five = balls(five, first);

        collide(&one, &two);
        collide(&one, &four);
        collide(&one, &five);
        collide(&one, &three);
        collide(&five, &two);
        collide(&five, &four);
        collide(&four, &two);
        collide(&three, &two);
        collide(&three, &four);
        collide(&three, &five);

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
    txRectangle(a.a1, a.b1, a.a2, a.b2);
    }

void collide (Ball *one, Ball *two)
    {
    double tmp;
    if(((one->x - two->x) * (one->x - two->x) + (one->y - two->y) * (one->y - two->y)) <= (one->r + two->r) * (one->r + two->r))
        {
        tmp = one->Vx;
        one->Vx = two->Vx;
        two->Vx = tmp;
        tmp = one->Vy;
        one->Vy = two->Vy;
        two->Vy = tmp;
        }
    }


