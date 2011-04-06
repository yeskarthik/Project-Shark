#include<graphics.h>
#include<time.h>
#include<dos.h>
#include<stdlib.h>
#include<iostream.h>
#include<iomanip.h>
#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<malloc.h>
void game();
void puzzlemain();
union REGS asi,op;

int initfmouse()
{
	asi.x.ax=0;
	int86(0x33,&asi,&op);
	return(op.x.ax);
}

void show_mouseptr()
{
	asi.x.ax=1;
	int86(0x33,&asi,&op);
}

void hide_mouseptr(void)
{
	union REGS regs;
	regs.x.ax=2;
	int86(0x33,&regs,&regs);
}

void restrict_mouseptr(int x1,int y1, int x2, int y2)
{
	asi.x.ax=7;
	asi.x.cx=x1;
	asi.x.dx=x2;
	int86(0x33,&asi,&op);
	asi.x.ax=8;
	asi.x.cx=y1;
	asi.x.dx=y2;
	int86(0x33,&asi,&op);


}

void get_mousepos(int *button, int *x, int *y)
{
	*button=0;
	asi.x.ax=3;
	int86(0x33,&asi,&op);
	*button=op.x.bx;
	*x=op.x.cx;
	*y=op.x.dx;
}

struct square
{
	int x,y;
	int n;
}a[9];



void menu()
{

	settextstyle(3,0,3);
	outtextxy(100,100,"Welcome to the  '8 puzzle game'");
	settextstyle(2,0,5);
	outtextxy(80,160,"There are 8 blocks arranged in random order");
	outtextxy(80,180,"in a square grid which can fit 9 blocks");
	outtextxy(80,200,"Your goal is to arrange these 8 blocks in ");
	outtextxy(80,220,"ascending order asi.e.1,2,3...8 by moving one");
	outtextxy(80,240,"at a time into the space and lesser the number");
	outtextxy(80,260,"of moves the smarter you are.. So All the Best!!!");
	outtextxy(100,300,"From the Shark group international");
	getch();
	game();

}

int str=0;
int r=8;
int m__,z=1;
void grid()
{
	char st[10];
	rectangle(150,100,450,200);
	rectangle(130,80,470,420);
	rectangle(150,100,250,400);
	rectangle(150,200,450,300);
	rectangle(150,300,450,400);
	rectangle(250,100,350,400);
	//	setfillstyle(3,RED);
	//	floodfill(135,90,WHITE);
	setfillstyle(2,GREEN);
	floodfill(135,90,WHITE);
	settextstyle(1,0,2);
	setcolor(LIGHTBLUE);
	outtextxy(200,30,"level :");
	itoa(z,st,10);
	outtextxy(260,30,st);
	settextstyle(z,0,5);
	setcolor(WHITE);
	for(int k=0;k<9;k++)
	{
	       //	setcolor(k+1);
		itoa(a[k].n,st,10);
		if(a[k].n!=0)outtextxy(a[k].x,a[k].y,st);
	}

}



void swap(int aa,int bb)
{
	a[bb].n=a[aa].n;
	a[aa].n=0;
	setfillstyle(1,BLACK);
	hide_mouseptr();
	bar(150,100,450,400);
	grid();
	show_mouseptr();
	m__=aa;
}



void winner()
{
	int a=getmaxx();
	int b=getmaxy();
	z++;
	for(int j=0;j<100;j++)
	{
	for(int asi=0;asi<10;asi++)
	{

		putpixel(random(a),random(b),random(a));
		putpixel(random(a),random(b),random(b));
		putpixel(random(a),random(b),random(a));
		setcolor(random(a));
		outtextxy(random(a),random(b),"thala");
		if(asi%5==0)circle(random(a),random(b),40);
		if(asi%10==0)rectangle(random(a),random(b),random(a)+10,random(b)+10);

	}
	delay(100);
	}
	cleardevice();
	settextstyle(3,0,3);
	outtextxy(a/2-200,b/2,"You Won The level Press Enter to move on ");
	getch();
	cleardevice();
	game();
}


void level8()
{
	a[0].n=1;
	a[1].n=6;
	a[2].n=4;
	a[3].n=7;
	a[4].n=2;
	a[5].n=8;
	a[6].n=0;
	a[7].n=3;
	a[8].n=5;
	m__=6;

}

void level1()
{
	a[0].n=2;
	a[1].n=6;
	a[2].n=5;
	a[3].n=8;
	a[4].n=1;
	a[5].n=7;
	a[6].n=0;
	a[7].n=3;
	a[8].n=4;
	m__=6;
}


void level3()
{
	a[0].n=8;
	a[1].n=0;
	a[2].n=1;
	a[3].n=7;
	a[4].n=2;
	a[5].n=6;
	a[6].n=5;
	a[7].n=3;
	a[8].n=4;
	m__=1;
}


void level4()
{
	a[1].n=1;
	a[2].n=8;
	a[3].n=5;
	a[4].n=2;
	a[5].n=0;
	a[6].n=3;
	a[7].n=7;
	a[8].n=4;
	a[0].n=6;
	m__=5;
}


void level5()
{
	a[1].n=2;
	a[2].n=7;
	a[3].n=3;
	a[4].n=6;
	a[5].n=1;
	a[6].n=8;
	a[7].n=4;
	a[8].n=0;
	a[0].n=5;
	m__=8;
}



void level6()
{
	a[1].n=3;
	a[2].n=8;
	a[3].n=7;
	a[4].n=0;
	a[5].n=4;
	a[6].n=2;
	a[7].n=5;
	a[8].n=1;
	a[0].n=6;
	m__=4;
}


void level7()
{
	a[1].n=1;
	a[2].n=4;
	a[3].n=5;
	a[4].n=7;
	a[5].n=8;
	a[6].n=0;
	a[7].n=6;
	a[8].n=3;
	a[0].n=2;
	m__=6;
}



void level9()
{
	a[1].n=8;
	a[2].n=7;
	a[3].n=5;
	a[4].n=2;
	a[5].n=1;
	a[6].n=3;
	a[7].n=4;
	a[8].n=6;
	a[0].n=0;
	m__=0;
}


void level2()
{
	a[1].n=3;
	a[2].n=6;
	a[3].n=4;
	a[4].n=0;
	a[5].n=5;
	a[6].n=8;
	a[7].n=2;
	a[8].n=7;
	a[0].n=1;
	m__=4;
}






void game()
{
	int gd=9,gm=2,mx=getmaxx(),my=getmaxy();
	int p=0,x,y,button=0,flag=0;
	restrict_mouseptr(150,100,450,400);
	initgraph(&gd,&gm,"d:/tc1/bgi");
	settextstyle(3,0,0);
	mx=mx/2;
	my=my/2;
	rectangle(150,100,450,200);
	rectangle(150,100,250,400);
	rectangle(150,200,450,300);
	rectangle(150,300,450,400);
	rectangle(250,100,350,400);
	a[0].x=190;a[0].y=130;
	a[1].x=290;a[1].y=130;
	a[2].x=390;a[2].y=130;
	a[3].x=190;a[3].y=230;
	a[4].x=290;a[4].y=230;
	a[5].x=390;a[5].y=230;
	a[6].x=190;a[6].y=330;
	a[7].x=290;a[7].y=330;
	a[8].x=390,a[8].y=330;
	switch(z)
	{

	default:level9();break;
	case 1:	level1();break;
	case 2:	level2();break;
	case 3:	level3();break;
	case 4:	level4();break;
	case 5:	level5();break;
	case 6:	level6();break;
	case 7:	level7();break;
	case 8: level8();break;
	}
start:	grid();
	show_mouseptr();
	int count=0;
	char s[5];
	while(flag==0&&!kbhit())
	{

		get_mousepos(&button,&x,&y);
		if(a[0].n==1&&a[1].n==2&&a[2].n==3&&a[3].n==4&&a[4].n==5&&a[5].n==6&&a[6].n==7&&a[7].n==8)
		{
			cleardevice();
			winner();
		}
		if(button&1==1)
		{

			     if(x>=150&&x<=250&&y>=100&&y<=200)p=0;
			else if(x>=250&&x<=350&&y>=100&&y<=200)p=1;
			else if(x>=350&&x<=450&&y>=100&&y<=200)p=2;
			else if(x>=150&&x<=250&&y>=200&&y<=300)p=3;
			else if(x>=250&&x<=350&&y>=200&&y<=300)p=4;
			else if(x>=350&&x<=450&&y>=200&&y<=300)p=5;
			else if(x>=150&&x<=250&&y>=300&&y<=400)p=6;
			else if(x>=250&&x<=350&&y>=300&&y<=400)p=7;
			else if(x>=350&&x<=450&&y>=300&&y<=400)p=8;
			settextstyle(1,0,1);
			if(count!=0)outtextxy(380,30,s);
			itoa(count,s,10);
			outtextxy(300,30,"Count");
			setfillstyle(1,BLACK);
			bar(360,70,450,10);
			outtextxy(380,30,s);


		switch(m__)
		{
			case 8: switch(p)
				{
					case 5:	swap(5,8);
						count++;
						break;
					case 7: swap(7,8);
						count++;
						break;
				}
				break;

			case 7:	switch(p)
				{
					case 6: swap(6,7);
						count++;
						break;
					case 4:	swap(4,7);
						count++;
						break;
					case 8: swap(8,7);
						count++;
						break;
				}
				break;
			case 6:	switch(p)
				{
					case 3:	swap(3,6);
						count++;
						break;
					case 7:	swap(7,6);
						count++;
						break;
				}
				break;
			case 5:	switch(p)
				{
					case 2:	swap(2,5);
						count++;
						break;
					case 4:	swap(4,5);
						count++;
						break;
					case 8: swap(8,5);
						count++;
						break;
				}
				break;
			case 4: switch(p)
				{
					case 1: swap(1,4);
						count++;
						break;
					case 3:	swap(3,4);
						count++;
						break;
					case 5: swap(5,4);
						count++;
						break;
					case 7: swap(7,4);
						count++;
						break;
				}
				break;
			case 3: switch(p)
				{
					case 0: swap(0,3);
						count++;
						break;
					case 4: swap(4,3);
						count++;
						break;
					case 6: swap(6,3);
						count++;
						break;
				}
				break;
			case 2: switch(p)
				{
					case 1: swap(1,2);
						count++;
						break;
					case 5: swap(5,2);
						count++;
						break;
				}
				break;
			case 1: switch(p)
				{
					case 0: swap(0,1);
						count++;
						break;
					case 4: swap(4,1);
						count++;
						break;
					case 2: swap(2,1);
						count++;
						break;
				}
				break;
			case 0: switch(p)
				{
					case 1:	swap(1,0);
						count++;
						break;
					case 3: swap(3,0);
						count++;
						break;
				}
				break;



			}
	  }



}

closegraph();
}

void puzzlemain()
{
	int gd=9,gm=2;
	initgraph(&gd,&gm,"d:/tc/bgi");
	menu();
	restrictmouseptr(0,0,getmaxx(),getmaxy());

}
