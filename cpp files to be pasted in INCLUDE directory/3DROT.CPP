#include<stdio.h>
#include<bios.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#define thala 95
void rotmain();
struct arccoordstype t,boss;
void rtltrot()
{
	int driver=DETECT,mode,i,j=1,k,a[thala],b[thala],c[thala],d[thala],u,v,m,n,flag=0;
	initgraph(&driver,&mode,"d:\\tc\\bgi");
    for(i=265;i<360;i++,j++)
    {
     arc(300,150,i-1,i,100);
     getarccoords(&t);
     a[thala-j]=t.xend;
     b[thala-j]=t.yend;
    }
   for(i=85,j=1;i<180;i++,j++)
    {
     arc(300,150,i-1,i,100);
     getarccoords(&boss);
     c[thala-j]=boss.xend;
     d[thala-j]=boss.yend;
    }
  // cleardevice();
  setfillstyle(1,BLACK);
  bar(0,0,getmaxx(),getmaxy());
    line(200,150,400,150);
    line(200,250,400,250);
    line(200,350,400,350);
    while(flag==0)
    {
    a: for(i=0;i<thala;i++)
       {
       outtextxy(200,50,"  3D ROTATING RECTANGLE");
	line(a[i]-i,b[i]-i,c[i]+i,d[i]+i);
	u=(b[i]-i)-150;
	v=150-(d[i]+i);
	line(a[i]-i,350-u,c[i]+i,350+v);
	line(a[i]-i,b[i]-i,a[i]-i,350-u);
	line(c[i]+i,d[i]+i,c[i]+i,350+v);
	setfillstyle(1,2);
	floodfill(300,250,getmaxcolor());
	delay(100);
       //cleardevice();
	setfillstyle(1,BLACK);
	bar(100,100,500,400);
       }
       if(!kbhit())goto a;
       if(kbhit())	{
				flag=1;
			}
  }
 getch();
 rotmain();
}

void updnrot()
{
int driver=DETECT,mode,i,j=0,k=0,a[95],b[95],c[95],d[95],u,v,h,flag=0;
initgraph(&driver,&mode,"d:\\tc\\bgi");
   for(i=90;i<185;i++,j++)
    {
     arc(400,230,i-1,i,100);
     getarccoords(&t);
     a[j]=t.xend;
     b[j]=t.yend;
     }

    for(i=270;i<365;i++,k++)
     {
      arc(400,230,i-1,i,100);
      getarccoords(&boss);
      c[k]=boss.xend;
      d[k]=boss.yend;
     }
  cleardevice();

  while(flag==0)
   {
  a: for(i=0;i<95;i+=5)
       {
	outtextxy(200,50,"  3D ROTATING RECTANGLE");
	putpixel(400,230,YELLOW);
	line(a[i]+i,b[i]+i,c[i]-i,d[i]-i);
	u=(400-(a[i]+i))+200;
	v=200-((c[i]-i)-400);
	line(u,b[i]+i,v,d[i]-i);
	line(a[i]+i,b[i]+i,u,b[i]+i);
	line(c[i]-i,d[i]-i,v,d[i]-i);
	setfillstyle(1,2);
	floodfill(370,230,getmaxcolor());
	delay(100);
	setfillstyle(1,BLACK);
	bar(100,100,500,400);
      }
      if(!kbhit())goto a;
  else if(kbhit())	{
				flag=1;
			}

  }

getch();
rotmain();
}

void rotmain()
{
	int a,b,driver=VGA,mode=2;
	initgraph(&driver,&mode,"d:\\tc1\\bgi");
	a=getmaxx();
	b=getmaxy();
	int x=40;
	int n=15;
	outtextxy(a/2-35,b/2-30,"Welcome to");
	outtextxy(a/2-25,b/2-15,"Rotation!");
	outtextxy(a/2-50,b/2-5,"1.Vertical axis");
	outtextxy(a/2-65,b/2+5,"2.Horizontal axis");
	outtextxy(a/2-25,b/2+15,"3.Exit");


	for(int j=0;j<200&&!kbhit();j++)
	{
		x=75;
		for(int i=0;i<400&&!kbhit();i++)
		{
			randomize();
			if(i%10==0)setcolor(random(n));
			ellipse(a/2,b/2,0,360,x,x);
			x++;
			n++;
			delay(0);
		}
		delay(10);
	}
	int t=bioskey(0);
	if(t==561||t==20273)rtltrot();
	else if(t==818||t==20530)updnrot();


}