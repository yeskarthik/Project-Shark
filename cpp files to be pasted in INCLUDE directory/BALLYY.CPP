#include <stdio.h>
#include<string.h>
#include<dos.h>
#include<conio.h>
#include<bios.h>
#include<graphics.h>
#include<stdlib.h>
#include<iostream.h>
#include<math.h>
float xx=350,yy=400;
float xxx=351,yyy=0;
int xe=0,ye=0,flag1=0;
int clr=14;
int newx1,newy1;
float mm,temp1=0;
float dx1,dy1;
int p_stang=180,p_enang=360,s_nang=180,e_nang=360;
int key1=0;
int stepcnt=0;
int last__x2=351,last__y2=0;
int rad=10;
int balls=0;
char sun3[8] =
		{0};


char sun2[8] =
		{0};

char solid[8] =
		{0};
char empty[8] = {0};
class cell
{
public :
int xe;
int ye;
int clr;
int same;
cell(void){clr=0;same=1;}
}c[261];
void pac(int xe,int ye)
{
setfillpattern(solid,clr);
setcolor(clr);
circle(xe,ye,rad);
floodfill(xe-2,ye-2,clr);
}
void pac3(int xe,int ye)
{
setfillpattern(sun3,clr);
setcolor(clr);
circle(xe,ye,rad);
floodfill(xe-2,ye-2,clr);
}
void pac2(int xe,int ye)
{
setfillpattern(empty,15);
setcolor(16);
circle(xe,ye,rad);
floodfill(xe-2,ye-2,16);
}
void erase1(void)
{
	setcolor(16);
	arc(350,400,p_stang,p_enang,10);
}

void draw1(void)
{
	setcolor(clr);
	arc(350,400,s_nang,e_nang,10);
}
void go1(void)
{
for(int i=0;i<260;i++)
if(c[i].same==3)pac2(c[i].xe,c[i].ye);
}
int checker1(void)
{
for(int i=0;i<260;i++)
if( ((xe+xx-c[i].xe) * (xe+xx-c[i].xe)) + ((ye+yy-c[i].ye)*(ye+yy-c[i].ye)) <=400)//576)//484)
{
	if(c[i].clr==clr)
	{
		c[i].same++;
		c[balls].xe=xe+xx;
		c[balls].ye=ye+yy;
		c[balls].clr=clr;
		pac3(xe+xx,ye+yy);
		balls++;
		flag1=1;
		c[balls].same=c[i].same;
		if(c[i].same>=3)go1();
	}
return-1;
}


  return 1;
}
void bubmov1(void)
{
dx1=xxx-xx,dy1=yyy-yy;
mm=(dy1/dx1);
if(xxx==350)xxx=351;
	if(xxx>xx)
	{
		if(abs(dy1)>abs(dx1))
			for(int i=0;xe+xx<=xxx;i++)
			{
				pac(xx+xe,yy+ye);
				delay(4);
				if(ye+yy<12 || checker1()==-1)
				{
				if(flag1==0)
				{
				c[balls].xe=xe+xx;
				c[balls].clr=clr;
				c[balls].ye=ye+yy;
				balls++;
				pac3(xe+xx,ye+yy);
				}
				return;
				}
				pac2(xx+xe,yy+ye);
				if(yy+ye>yyy)ye--;
					else
					{
						newy1=yyy;
						yyy=yyy-(yy-yyy);
						yy=newy1;
						xx=500;
						xxx=200;
						temp1=0;
						xe=0;
						ye=0;
						bubmov1();
						return;
					 }
				if(yy+ye<=0)
				{
				break;
				cout<<"break exit 1";
				}
				temp1=temp1+1/mm;
				xe=abs(temp1);
			}
		else
			for(int i=0;ye+yy>=yyy;i++)
			{
				pac(xx+xe,yy+ye);
				delay(4);
				if(ye+yy<12 || checker1()==-1)
				{
				if(flag1==0)
				{
				c[balls].xe=xe+xx;
				c[balls].ye=ye+yy;
				c[balls].clr=clr;
				balls++;
				pac3(xe+xx,ye+yy);
				}
				return;
				}
				pac2(xx+xe,yy+ye);
				if(xx+xe<xxx)xe++;
					else
					{
						newy1=yyy;
						yyy=yyy-(yy-yyy);
						yy=newy1;
						xx=500;
						xxx=200;
						temp1=0;
						xe=0;
						ye=0;
						bubmov1();
						return;
					}
				temp1=temp1+mm;
				ye=temp1;
			}

	}
	else if(xxx<xx)
	{
		if(abs(dy1)>abs(dx1))
			for(int i=0;xe+xx>=xxx;i++)
			{
				pac(xx+xe,yy+ye);
				delay(4);
				if(ye+yy<12 || checker1()==-1)
				{
				if(flag1==0)
				{
				c[balls].xe=xe+xx;
				c[balls].ye=ye+yy;
				c[balls].clr=clr;
				balls++;
				pac3(xe+xx,ye+yy);
				}
				return;
				break;
				}
				pac2(xx+xe,yy+ye);
				if(yy+ye<=0)
				{
				break;
				cout<<"break exit 1";
				}
				if(yy+ye>yyy)ye--;
					else
					{
						newy1=yyy;
						yyy=yyy-(yy-yyy);
						yy=newy1;
						xx=200;
						xxx=500;
						temp1=0;
						xe=0;
						ye=0;
						bubmov1();
						return;
					}
				temp1=temp1-1/mm;
				xe=temp1;
			}
		else
			for(int i=0;ye+yy>=yyy;i++)
			{
				pac(xx+xe,yy+ye);
				delay(4);
				if(ye+yy<12 || checker1()==-1)
				{
				if(flag1==0)
				{
				c[balls].xe=xe+xx;
				c[balls].ye=ye+yy;
				c[balls].clr=clr;
				balls++;
				pac3(xe+xx,ye+yy);
				}
				return;
				}
				pac2(xx+xe,yy+ye);
				if(yy+ye<=0)
				{
				if(flag1==0)
				{
				c[balls].xe=xe+xx;
				c[balls].ye=ye+yy;
				c[balls].clr=clr;
				balls++;
				}
				break;
				}
				if(xx+xe>xxx)xe--;
					else
					{
						newy1=yyy;
						yyy=yyy-(yy-yyy);
						yy=newy1;
						xx=200;
						xxx=500;
						temp1=0;
						xe=0;
						ye=0;
						bubmov1();
						return;
					}
				temp1=temp1-mm;
				ye=temp1;
			}
	}

}
void ballymain()
{
clrscr();

int gdriver =DETECT, gmode;
initgraph(&gdriver, &gmode,"c:\\tc\\bgi");
rectangle(188,0,511,400);
setcolor(16);
line(325,400,375,400);
setcolor(15);
randomize();
	while(7)
	{
	key1=0;
	draw1();
	if(bioskey(1) != 0)
	      {
			key1=bioskey(0);
			if(key1==6512)
				{
					key1=0;
					while(1)
					{	if(bioskey(1) != 0)
						key1=bioskey(0);
						outtextxy(350,470,"Game Paused: press 'P' to continue");
						if(key1==6512)break;
					}
					setcolor(16);
					outtextxy(350,470,"Game Paused: press 'P' to continue");
					setcolor(14);
				}
			if(key1==19712 && stepcnt>-25)
				{
				s_nang=s_nang-3;
				e_nang=e_nang-3;
				if(stepcnt>-10)
				{
					if(stepcnt<=10)
					{
					xxx+=15;
					yyy=0;
					}
				}
				if(stepcnt<=-10)xxx=500;
				if(xxx==500)yyy+=15;
				if(stepcnt>10)yyy-=15;
				last__x2=xxx;
				last__y2=yyy;
				stepcnt--;
				}
			if(key1==19200 && stepcnt<25)
				{
				s_nang=s_nang+3;
				e_nang=e_nang+3;
				if(stepcnt<10)
				{
					if(stepcnt>=-10)
					{
					xxx-=15;
					yyy=0;
					}
				}
				if(stepcnt>=10)xxx=200;
				if(xxx==200)yyy+=15;
				if(stepcnt<-10)yyy-=15;
				last__x2=xxx;
				last__y2=yyy;
				stepcnt++;
				}
			if(key1==14624)
			{
			bubmov1();
			clr=random(5)+1;
			key1=0;
			temp1=0;
			xe=0;
			ye=0;
			xx=350;
			yy=400;
			xxx=last__x2;
			yyy=last__y2;
			flag1=0;
			}
			if(key1==4209)
			{
			for(int j=0;j<261;j++)
			{
			cout<<c[j].clr;
			if(j%11==0 && j!=0)cout<<endl;
			}
			}
			if(key1==283)
			{
			goto b;
			}
		}
		if(p_enang!=e_nang)erase1();
		p_stang=s_nang;
		p_enang=e_nang;
	}
	 b:
}