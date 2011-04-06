#include <stdio.h>
#include<string.h>
#include<dos.h>
#include<conio.h>
#include<bios.h>
#include<graphics.h>
#include<stdlib.h>
#include<iostream.h>
#include<math.h>
float x1=350,y1=400;
float x2=351,y2=0;
int x=0,yy1=0,flag3=0;
int newx,newy;
float m,temp=0;
float dx,dy;
int pstang=180,penang=360,stang=180,enang=360;
int key=0;
int step_count=0;
int last_x2=351,last_y2=0;

void erase(void)
{
	setcolor(16);
	arc(350,400,pstang,penang,10);
}

void draw(void)
{
	setcolor(15);
	arc(350,400,stang,enang,10);
}
void bubmov(void)
{
    randomize();
    int t=1+random(20);
dx=x2-x1,dy=y2-y1;
m=(dy/dx);
	setfillstyle(1,BLACK);
	bar(520,180,560,220);
	setfillstyle(1,WHITE);
	if(x2>x1)
	{
		if(abs(dy)>abs(dx))
		{
			for(int i=0;x+x1<=x2;i++)
			{       delay(t);
				putpixel(x1+x,y1+yy1,15);
				if(y1+yy1>y2)	yy1--;
					else
					{
						newy=y2;
						y2=y2-(y1-y2);
						y1=newy;
						x1=500;
						x2=200;
						temp=0;
						x=0;
						yy1=0;

						bubmov();
					 }
				if(y1+yy1<=0)break;
				temp=temp+1/m;
				x=abs(temp);
				}
				setfillstyle(1,BLACK);
				bar(550,100,640,480);

					outtextxy(540,200,"angle is : ");
				char a[10];

				itoa(pstang-100,a,10);
					outtextxy(540,210,a);
				int y=400/t;
				itoa(y,a,10);
				outtextxy(540,270,"Velocity is : ");
					outtextxy(540,285,a);




		   }
		else
		{
			for(int i=0;yy1+y1>=y2;i++)
			{       delay(2);
				if(y1+yy1<=0)break;
				putpixel(x1+x,y1+yy1,15);
				if(x1+x<x2)x++;
					else
					{
						newy=y2;
						y2=y2-(y1-y2);
						y1=newy;
						x1=500;
						x2=200;
						temp=0;
						x=0;
						yy1=0;
						bubmov();
					}
				temp=temp+m;
				yy1=temp;
			}

				setfillstyle(1,BLACK);
				bar(530,100,630,480);
				outtextxy(540,200,"angle is : ");
				char a[10];

				itoa(pstang-100,a,10);
					outtextxy(540,210,a);
				int y=400/t;
				itoa(y,a,10);
				outtextxy(540,270,"Velocity is : ");
					outtextxy(540,285,a);


		 }
	}
	else if(x2<x1)
	{
		if(abs(dy)>abs(dx))
		{
			for(int i=0;x+x1>=x2;i++)
			{       delay(2);
				if(y1+yy1<=0)break;
				putpixel(x1+x,y1+yy1,15);
				if(y1+yy1>y2)yy1--;
					else
					{
						newy=y2;
						y2=y2-(y1-y2);
						y1=newy;
						x1=200;
						x2=500;
						temp=0;
						x=0;
						yy1=0;
						bubmov();
					}
				temp=temp-1/m;
				x=temp;
			}

				setfillstyle(1,BLACK);
				bar(530,100,630,480);
				outtextxy(540,200,"angle is : ");
				char a[10];
				itoa(pstang-100,a,10);
				outtextxy(540,210,a);
				int y=400/t;
				itoa(y,a,10);
				outtextxy(540,270,"Velocity is : ");
				outtextxy(540,285,a);

				}
		else
		{
			for(int i=0;yy1+y1>=y2;i++)
			{	delay(2);
				if(y1+yy1<=0)break;
				putpixel(x1+x,y1+yy1,15);
				if(x1+x>x2)x--;
					else
					{
						newy=y2;
						y2=y2-(y1-y2);
						y1=newy;
						x1=200;
						x2=500;
						temp=0;
						x=0;
						yy1=0;
						bubmov();
					}
				temp=temp-m;
				yy1=temp;
			}

				setfillstyle(1,BLACK);
				bar(530,100,630,480);
				outtextxy(540,200,"angle is : ");
				char a[10];
				itoa(pstang-100,a,10);
				outtextxy(540,210,a);
				int y=400/t;
				itoa(y,a,10);
				outtextxy(540,270,"Velocity is : ");
				outtextxy(540,285,a);

		}
	}

}
void bally1main()
{
clrscr();
int gdriver =DETECT, gmode;
initgraph(&gdriver, &gmode,"d:\\tc1\\bgi");

rectangle(200,0,500,400);
circle(350,400,2);
setcolor(16);
line(330,400,370,400);
setcolor(15);
	while(7)
	{
       //	setfillstyle(1,BLACK);
       //	bar(540,220,630,420);
	key=0;
	flag3=0;
	draw();
	if(bioskey(1) != 0)
	      {
			key=bioskey(0);
			if(key==6512)
				{
					key=0;
					while(1)
					{
						if(bioskey(1) != 0)
						key=bioskey(0);
						outtextxy(350,470,"Game Paused: press 'P' to continue");
						if(key==6512)break;
					}
					setcolor(16);
					outtextxy(350,470,"Game Paused: press 'P' to continue");
					setcolor(14);
				}
			if(key==19712 && step_count>-18)
				{
				stang=stang-5;
				enang=enang-5;
				if(step_count>-5)
				{
					if(step_count<=5)
					{
					x2+=30;
					y2=0;
					}
				}
				if(step_count<=-5)x2=500;
				if(x2==500)y2+=30;
				if(step_count>5)y2-=30;
				last_x2=x2;
				last_y2=y2;
				step_count--;
				}
			if(key==19200 && step_count<18)//
				{
				stang=stang+5;
				enang=enang+5;
				if(step_count<5)
				{
					if(step_count>=-5)
					{
					x2-=30;
					y2=0;
					}
				}
				if(step_count>=5)x2=200;
				if(x2==200)y2+=30;
				if(step_count<-5)y2-=30;
				last_x2=x2;
				last_y2=y2;
				step_count++;
				}
			if(key==14624)
			{
			bubmov();
			key=0;
			temp=0;
			x=0;
			yy1=0;
			x1=350;
			y1=400;
			x2=last_x2;
			y2=last_y2;
			}
			if(key==283)
			{
			    goto a;
			}
		}
		if(penang!=enang)erase();
		pstang=stang;
		penang=enang;
	}
	a:
}