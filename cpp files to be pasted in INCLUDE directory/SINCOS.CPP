#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>

void insnegsign(char s[])
{
	char p[5];
	p[0]='-';
	for(int i=0;s[i]!='\0';i++)
	{
		p[i+1]=s[i];
	}
	p[i+1]='\0';
	strcpy(s,p);

}



void getinfo(char s[],int x,int y,int a,int b)
{
	char	c = getch();
	int	i = 0;
		while (c !='\r')
		{
			s[i] = c;
			s[i+1] ='\0';
			setfillstyle(1,0);
			bar (x+a,y,x+400,y+20);
			setcolor(WHITE);
			outtextxy(x+a,y,s);
			i++;
			c = getch();
		}

}



void drawsine()
{
	float a[401];
	int b,c,d=1,n,j=0;
	for(float i=0;i<=10;i+=0.025,j++)
	{
		a[j]=sin(i);
	}
	char s[4],p[4];
	cleardevice();
	outtextxy(getmaxx()/2-75,getmaxy()/2-100," Sine Curve ");
	outtextxy(getmaxx()/2-140,getmaxy()/2-80,"  Enter Amplitude :");
	getinfo(s,getmaxx()/2-210,getmaxy()/2-80,getmaxx()/2-80,getmaxy()/2-70);
	outtextxy(getmaxx()/2-140,getmaxy()/2-60,"  Enter Frequency :");
	n = atoi(s);
	getinfo(p,getmaxx()/2-210,getmaxy()/2-60,getmaxx()/2-80,getmaxy()/2-50);
	d = atoi(p);
	cleardevice();
	line(10,0,10,getmaxy());
	outtextxy(0,230-n,s);
	insnegsign(s);
	outtextxy(0,230,"0");
	outtextxy(0,230+n,s);
	for(j=0;j<252;j++)
	{
		putpixel(10+j/d,240-n*a[j],YELLOW);
		delay(2);
	}
	while(j/d<=540)
	{
		for(int k=0;k<252;k++,j++)
		{


			putpixel(10+j/d,240-n*a[k],YELLOW);
			delay(2);
		}

		line(10,240,getmaxx(),240);
	}
	getch();
}



void drawcosine()
{
	float a[401];
	int b,c,d=1,n,j=0;
	for(float i=0;i<=10;i+=0.025,j++)
	{
		a[j]=cos(i);
	}
	char s[5],p[5];
	cleardevice();
	outtextxy(getmaxx()/2-75,getmaxy()/2-100," Cosine Curve ");
	outtextxy(getmaxx()/2-140,getmaxy()/2-80,"  Enter Amplitude :");
	getinfo(s,getmaxx()/2-210,getmaxy()/2-80,getmaxx()/2-80,getmaxy()/2-70);
	outtextxy(getmaxx()/2-140,getmaxy()/2-60,"  Enter Frequency :");
	n = atoi(s);
	getinfo(p,getmaxx()/2-210,getmaxy()/2-60,getmaxx()/2-80,getmaxy()/2-50);
	d = atoi(p);
	cleardevice();
	line(10,0,10,getmaxy());
	outtextxy(0,230-n,s);
	outtextxy(0,230,"0");
	insnegsign(s);
	outtextxy(0,230+n,s);

	for(j=0;j<252;j++)
	{
		putpixel(10+j/d,240-n*a[j],YELLOW);
		delay(2);
	}
	while(j/d<=540)
	{
		for(int k=0;k<252;k++,j++)
		{
			putpixel(10+j/d,240-n*a[k],YELLOW);
			delay(2);
		}

		line(10,240,getmaxx(),240);
	}
	getch();
}


void drawtan()
{
	float a[401];
	int b,c,d=1,n,j=0;
	for(float i=0;i<=10;i+=0.025,j++)
	{
		a[j]=tan(i);
	}
	char s[4];
	cleardevice();
	outtextxy(getmaxx()/2-75,getmaxy()/2-100," Tangent Curve ");
	outtextxy(getmaxx()/2-140,getmaxy()/2-80,"  Enter Amplitude :");
	getinfo(s,getmaxx()/2-210,getmaxy()/2-80,getmaxx()/2-80,getmaxy()/2-70);
	outtextxy(getmaxx()/2-140,getmaxy()/2-60,"  Enter Frequency :");
	n = atoi(s);
	char p[3];
	getinfo(p,getmaxx()/2-210,getmaxy()/2-60,getmaxx()/2-80,getmaxy()/2-50);
	d = atoi(s);
	cleardevice();
	for(j=0;j<252;j++)
	{
		putpixel(10+j/d,240-n*a[j],YELLOW);
		delay(2);
	}
	while(j/d<=540)
	{
		for(int k=0;k<252;k++,j++)
		{
			putpixel(10+j/d,240-n*a[k],YELLOW);
			delay(2);
		}

		line(10,240,getmaxx(),240);
	}
	getch();
}
void chooose();
void menusin()
{
	cleardevice();
	settextstyle(6,0,1);
	outtextxy(100,100,"Hey!");
	outtextxy(100,130,"This is a program to draw graphs of trigonometric functions");
	outtextxy(100,150,"You Can draw Sine,Cos And Tan Graphs with given frequency and");
	outtextxy(100,170,"amplitude.");
	outtextxy(100,190,"This can be used to teach mathematical & physical relations");
	outtextxy(100,210,"There is a lower and upper limit to assign the frequency and");
	outtextxy(100,230,"amplitude being 2,50 and 5,250 respectively");
	outtextxy(100,260,"Thanking You");
	outtextxy(100,280,"The Shark Group Associates TM");
	outtextxy(100,310,"Loading...");

	for(int j=0;j<=30;j++)
	{
		setcolor(WHITE);
		outtextxy(200+j*10,310,".");
		delay(500);
	}
	outtextxy(100,330,"Press any Key to Continue");
	chooose();
}


void chooose()
{
    a:	cleardevice();
	outtextxy(250,150,"GRAPHING");
	outtextxy(200,200,"Enter Option and enter key");
	outtextxy(200,230,"1.Sine Curve");
	outtextxy(200,250,"2.Cosine Curve");
	outtextxy(200,270,"3.Tangent Curve");
	outtextxy(200,290,"4.Exit");
	char s[2];
	getinfo(s,300,290,340,270);
	int n;
	n=atoi(s);
	if(n==1||n==2||n==3||n==4)
	{
		outtextxy(200,320,s);
		delay(1000);
		if(n==1)drawsine();
		else if(n==2)drawcosine();
		else if(n==3)drawtan();
		else if(n==4)goto end;
	}
	else
	{
		outtextxy(200,320,"Enter Correct Option");
		getch();
		goto a;
	}
	end:
}





void sinemain()
{

	int driver=DETECT,mode;
	initgraph(&driver,&mode,"d:\\tc1\\bgi");
	menusin();
	chooose();
	getch();
	closegraph();
}
