
#include <iostream.h>
#include <string.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void fade(int red, int green, int blue, int fontn, int size, int x, int y, char text[]);


void fadeintro()
{
clrscr();
fade(4,0,0,4,5,150,200,"The Shark Associates");
fade(4,4,0,4,5,130,200,"The Origin Productions");
delay(300);
}



void fade(int red, int green, int blue, int font, int size, int x, int y, char text[])
{
int gdriver = 9, gmode =2 , i;
struct palettetype pal;
initgraph(&gdriver, &gmode, "d:\\tc\\bgi");
getpalette(&pal);
for (i=0; i<pal.size; i++)
setrgbpalette(pal.colors[i], i*red, i*green, i*blue);
for (i=0; i<pal.size; i++)
{
	setcolor(i);
	settextstyle(font,0,size);
	outtextxy(x,y, text);
	delay(300);
}
getpalette(&pal);
for (i=0; i<pal.size; i++)
setrgbpalette(pal.colors[i], i*red, i*green, i*blue);
for (i=pal.size-1; i>=0; i--)
	{
	setcolor(i);
	outtextxy(x,y,text);
	delay(300);
}
}