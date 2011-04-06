#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#define RIGHT 77
#define LEFT 75
#include<stdlib.h>
#include<math.h>
#define pi M_PI
#define maxx getmaxx()/2
#define maxy getmaxy()/2-30

void count(float &s,float &t,float &u,float i,float j,float r);

struct coord
{
	int x,y;
};
class Sol
{
   private :

	float 	cosa,cosb,sina,sinb;
   public :
	void ini(float cos1,float cos2);
	void plot(float x,float y,float z,int &x1,int &y1);
	void plot1(float x,float y,float z,int xx,int yy,int &x1,int &y1);
	void plot3d1(float x,float y,float z,int xx,int yy,int cl);
	void plot3d(float s,float t,float u,int cl);
};



void Sol::ini(float cos1,float cos2)
{
 cosa=cos(cos1*pi/180);
 cosb=cos((cos2)*pi/180);
 sina=sin(cos1*pi/180);
 sinb=sin((cos2)*pi/180);
}
void Sol::plot(float x,float y,float z,int &x1,int &y1)
{
 x1=x*cosa-y*sina;
 y1=x*sina*sinb+y*cosa*sinb+z*cosb;
 x1=320+int(x1);
 y1=240-int(y1);
}
void Sol::plot1(float x,float y,float z,int xx,int yy,int &x1,int &y1)
{
float xx1,yy1;
 xx1=x*cosa-y*sina;
 yy1=x*sina*sinb+y*cosa*sinb+z*cosb;
 x1=xx+int(xx1);
 y1=yy+int(yy1);
}
void Sol::plot3d(float s,float t,float u,int cl)
{
int x1,y1;
plot(s,t,u,x1,y1);
putpixel(x1,y1,cl);
}
void Sol::plot3d1(float x,float y,float z,int xx,int yy,int cl)
{
float xx1,yy1;
int x1,y1;
 xx1=x*cosa-y*sina;
 yy1=x*sina*sinb+y*cosa*sinb+z*cosb;
 x1=xx+int(xx1);
 y1=yy+int(yy1);
 putpixel(x1,y1,cl);
}
void count(float &s,float &t,float &u,float j,float i,float r)
{
	s=(r)*cos(i*pi/180.0)*sin(j*pi/180.0);
     t=(r)*sin(i*pi/180.0)*sin(j*pi/180.0);
     u=(r)*cos(j*pi/180.0);
     }



void show()
{
int gd=DETECT,gm;
  initgraph(&gd,&gm,"d:\\tc\\bgi");
  Sol a[10],b[10];
  float p[10],p1[10],df,s,t,u,rd[10],r1[10],d,i,j;
   int x[20],y[20];
   for(i=0;i<10;i++)
   {
  p[i]=0.0;
  p1[i]=0.0;
  }
  s=90.0;
  d=1.0;
  rd[0]=55.0;
  rd[1]=18.0;
  rd[2]=23.0;
  rd[3]=22.0;
  rd[4]=24.0;
  rd[5]=40.0;
  rd[6]=40.0;
  r1[1]=100.0;
  r1[2]=155.0;
  r1[3]=210.0;
  r1[4]=270.0;
  r1[5]=250.0;
  r1[6]=250.0;

while(1)
  {

   a[0].ini(p[0],45+90);
   a[1].ini(p[1],45+90);
   a[2].ini(p[2],45+90);
   a[3].ini(p[3],45+90);
   a[4].ini(p[4],45+90);
   a[5].ini(p[5],45+90);
   a[6].ini(p[6],45+90);
   b[1].ini(p1[1],40+90);
   b[2].ini(p1[2],40+90);
   b[3].ini(p1[3],40+90);
  /* b[4].ini(p1[4],p[4]+90);
   b[5].ini(p1[5],p[5]+90);*/
   b[4].ini(p1[4],40+90);
   b[5].ini(p1[5],40+90);
   b[6].ini(p1[6],40+90);
   b[1].plot(r1[1],0,0,x[1],y[1]);
   b[2].plot(r1[2],0,0,x[2],y[2]);
   b[3].plot(r1[3],0,0,x[3],y[3]);
   b[4].plot(r1[4],0,0,x[4],y[4]);
   b[5].plot(r1[5],0,0,x[5],y[5]);
   b[6].plot(r1[6],0,0,x[6],y[6]);
   for( i=0.0,j=0;i<360.0;i+=5.0)
    {
    b[1].plot3d(r1[1]*cos(i*pi/180.0),r1[1]*sin(i*pi/180.0),0,10);

    b[2].plot3d(r1[2]*cos(i*pi/180.0),r1[2]*sin(i*pi/180.0),0,7);
    b[3].plot3d(r1[3]*cos(i*pi/180.0),r1[3]*sin(i*pi/180.0),0,6);
    b[4].plot3d(r1[4]*cos(i*pi/180.0),r1[4]*sin(i*pi/180.0),0,7);
   // b[5].plot3d(r1[5]*cos(i*pi/180.0),r1[5]*sin(i*pi/180.0),0,4);
   // b[6].plot3d(r1[6]*cos(i*pi/180.0),r1[6]*sin(i*pi/180.0),0,3);
    }
  for( j=0.0;j<360.0;j+=15.0)
    {
    for( i=0.0;i<360.0;i+=13.0)
    {
    count(s,t,u,j,i,rd[0]);
     a[0].plot3d(s,t,u,14);
     count(s,t,u,j,i,rd[1]);
     a[1].plot3d1(s,t,u,x[1],y[1],12);
      count(s,t,u,j,i,rd[2]);
     a[2].plot3d1(s,t,u,x[2],y[2],10);
     count(s,t,u,j,i,rd[3]);
     a[3].plot3d1(s,t,u,x[3],y[3],11);
     count(s,t,u,j,i,rd[4]);
     a[4].plot3d1(s,t,u,x[4],y[4],7);
     /*count(s,t,u,j,i,rd[5]);
     a[5].plot3d1(s,t,u,x[5],y[5],5);
     count(s,t,u,j,i,rd[2]);
     a[6].plot3d1(s,t,u,x[6],y[6],6); */

	}
    }
    //delay(1);
   cleardevice();
    p[0]+=2.0;
    p[1]+=0.8;
    p[2]+=0.7;
    p[3]+=0.8;
    p[4]+=0.6;
    p[5]+=0.5;
    p[6]+=0.2;
    p1[1]+=0.2;
     p1[2]-=0.1;
     p1[3]+=0.3;
     p1[4]-=0.4;
     p1[5]+=0.5;
     p1[6]+=0.5;
    // rd[0]+=d;
    if(0)
    {
    rd[0]+=d;
    if(rd[0]>10)
    {d=-1;}
    if(rd[0]<80)
    {
    d=1;
    }
    }
    if(kbhit())
    {
    closegraph();
    break;
    }
  }

}


void menu3()
{
	cleardevice();
	settextstyle(4,0,7);
	outtextxy(80,30,"The Solar System");
	settextstyle(2,0,5);
	outtextxy(100,170,"Hey!");
	outtextxy(100,190,"Welcome to the small 3D model of the solar system");
	outtextxy(100,210,"This is just to give an idea of how it looks and");
	outtextxy(100,230,"it is also interesting to see the planets rotating on");
	outtextxy(100,250,"their axis and revolving around the Sun along their");
	outtextxy(100,270,"orbit. Hope you will enjoy viewing this.");
	outtextxy(100,300,"Thanking You");
	outtextxy(100,320,"The Shark Associates TM");
	outtextxy(100,400,"Press any key to view");
	getch();
	show();
}

void solarmain()
{
	int gd=9,gm=2;
	initgraph(&gd,&gm,"d:/tc1/bgi");
	menu3();
}
