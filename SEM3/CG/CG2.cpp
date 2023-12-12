/*

Write C++ program to implement Cohen Southerland line clipping algorithm.

*/

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>

using namespace std;

class Coordinate
{
    public:
        int x, y;
        int code[4]={0};
};

class Lineclip
{
    public:
        Coordinate PT;
        void drawwindow();
        void drawline(Coordinate p1, Coordinate p2);
        void setcode(Coordinate p);
        int visibility(Coordinate p1, Coordinate p2);
        Coordinate resetendpt(Coordinate p1, Coordinate p2);
};

int main()
{
    Lineclip lc;
    int gd = DETECT, v, gm;
    Coordinate p1, p2, p3, p4, temp;

    cout << "\n Enter x1 and y1\n";
    cin >> p1.x >> p1.y;
    cout << "\n Enter x2 and y2\n";
    cin >> p2.x >> p2.y;

    initgraph(&gd,&gm,NULL);
    lc.drawwindow();
    delay(2000);

    lc.drawline(p1,p2);
    delay(2000);
    cleardevice();

    delay(2000);
    lc.setcode(p1);
    lc.setcode(p2);
    v = lc.visibility(p1, p2);
    delay(2000);

    switch (v)

    {
    case 0:
        lc.drawwindow();
        delay(2000);
        break;

    case 1:
        p3 = lc.resetendpt(p1, p2);
        p4 = lc.resetendpt(p2, p1);
        lc.drawwindow();
        lc.drawline(p3, p4);
        delay(2000);
        break;

    case 2:
        lc.drawwindow();
        lc.drawline(p1, p2);
        delay(2000);
        break;
    }
    delay(2000);
    closegraph();
}

void Lineclip::drawwindow()
{
    line(150, 100, 450, 100);
    line(450, 100, 450, 350);
    line(450, 350, 150, 350);
    line(150, 350, 150, 100);
}

void Lineclip::drawline(Coordinate p1, Coordinate p2)
{
    line(p1.x, p1.y, p2.x, p2.y);
}

void Lineclip::setcode(Coordinate p)
{
    if(p.y<100) p.code[0] = 1;
    if(p.y>350) p.code[1] = 1;
    if(p.x>450) p.code[2] = 1;
    if(p.x<150) p.code[3] = 1;
};

int Lineclip::visibility(Coordinate p1, Coordinate p2)
{
    for (int i=0; i<4; i++)
    {
        if (p1.code[i] && p2.code[i])
            return 0;
        if (p1.code[i] || p2.code[i])
        	return 1;
    }
    return(2);
}

Coordinate Lineclip::resetendpt(Coordinate p1, Coordinate p2)
{
    Coordinate temp;
    int x, y, i;
    float m,k;

    if (p1.code[0]==1) y = 100;
    if (p1.code[1]==1) y = 350;
    if (p1.code[3]==1) x = 150;
    if (p1.code[2]==1) x = 450;
    
    if (p1.code[3] || p1.code[2])
    {
        m = (float)(p2.y-p1.y)/(p2.x-p1.x);
        k = (p1.y+(m*(x-p1.x)));
        temp.y = k;
        temp.x = x;
        if (temp.y<=350 && temp.y>=100)
            return (temp);
    }
    if (p1.code[1] || p1.code[1])
    {
        m = (float)(p2.y-p1.y)/(p2.x-p1.x);
        k = (float)p1.x+(float)(y-p1.y)/m;
        temp.x = k;
        temp.y = y;
        return (temp);
    }
    else
        return(p1);
}
