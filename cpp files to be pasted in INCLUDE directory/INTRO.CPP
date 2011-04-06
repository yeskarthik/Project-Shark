#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
				 /*
void screenshot()
{
	int 	gdriver = 9, gmode=2;
		initgraph(&gdriver, &gmode, "d:\\tc1\\bgi");
	int 	a1x,a1y,j,c,e,g,d;
		cleardevice();
		for(int i=0;i<=210;i++)
		{
			sound(i*10);
			c=random(12);
			setcolor(c);
			circle(320,240,i);
			delay(50);
			setcolor(BLACK);
			circle(320,240,i);
			nosound();
		}
		for(int r=0;r<=640;r+=50)
		{
			sound(r+40);
			setcolor(3);
			line(1,r,640,r);
			line(r,1,r,640);
			line(1,1,840,640);
			line(650,1,1,480);
			delay(80);
			nosound();
		}

		for(int t=0;t<=230;t+=8)
		{
			sound(t*10);
			setcolor(3);
			circle(320,240,t);
			setcolor(3);
			ellipse(320,240,0,360,t,80);
			ellipse(320,240,0,360,80,t);
			delay(80);
			nosound();
		}
		for(int z=0;z<80;z++)
		{
			sound(500+z);
			d=random(12);
			setcolor(d);
			circle(320,240,z);
			delay(50);
			nosound();
		}
		for(int q=80;q<340;q++)
		{
			sound(500*q);
			setcolor(0);
			circle(320,240,q);
			delay(50);
			nosound();
		}

		do
		{
			j=random(12);
			setcolor(j);
			settextstyle(3,0,6);
			outtextxy(250,330,"SRIRAM");
			outtextxy(240,80,"KARTHIK");
			settextstyle(3,1,6);
			outtextxy(150,140,"DEEPAK");
			outtextxy(430,140,"SRIHARI");
		}while(!kbhit());
		getch();
		cleardevice();
}
void main()
{
screenshot();
}                                 */