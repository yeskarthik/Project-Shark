
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<paint.cpp>
#include<piano.cpp>
#include<primes.cpp>
#include<bally.cpp>
#include<ballyy.cpp>
#include<puzzle.cpp>
#include<sparkal.cpp>
#include<fade.cpp>
#include<intro.cpp>
int tim=1;


void main();
void menumain();
void border();
void arrow(int);
void move(char);

float ii=125;
char ch;




void introd()
{
	int 	x,y,j,c,e,g,da;
	cleardevice();
	for(int ii=0;ii<=210;ii++)
	{
		sound(ii*10);
		c=random(12);
		setcolor(c);
		circle(320,240,ii);
		delay(50);
		setcolor(BLACK);
		circle(320,240,ii);
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
		da=random(12);
		setcolor(da);
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
}
void main()
{
clrscr();
int a=0,b,flag=0;
initgraph(&a,&b,"d:\\tc1\\bgi");
//if(tim==1)introd();
tim++;
cleardevice();
if(flag==0)
{
flag=1;
cleardevice();
}
menumain();
}



void menumain()
{
cleardevice();
setcolor(GREEN);
cleardevice();
border();
settextstyle(11,HORIZ_DIR,2);
outtextxy(50,125,"1.Sharx Music");
outtextxy(50,150,"2.Shark Draw");
outtextxy(50,175,"3.Puzzle");
outtextxy(50,200,"4.Bally");
outtextxy(50,225,"5.Reflex");
outtextxy(50,250,"6.Exit");
setcolor(RED);
arrow(ii);
while(ch!='q')
{
	ch=getch();
	move(ch);
}

}

int q=0;//160
int w=0;//10
void arrow(int k)
{
line(q+15,k,q+35,k);
line(q+35,k,q+25,k-5);
line(q+35,k,q+25,k+5);
}

void move(char ch)
{
	int a=RED,b=YELLOW;
	if (ch==13)
	{
		if(q==0)
		{
		 if (ii==125)
		 {
			eff3(&a,&b);
			pianomain();
		 }
		 if (ii==150)
		 {
			a++;b++;
			eff2(&a,&b);
			paintmain();
		 }

		 if (ii==175)
		 {
			a++;b++;
			eff2(&a,&b);
			puzzlemain();
		}
		 if (ii==200)
		 {
			a++;b++;
			eff2(&a,&b);
			ballymain();
		}


	 if (ii==250)
	 {
		a++;b++;
		eff2(&a,&b);
		exit(0);
	 }
	 if (ii==225)
	 {     a++;b++;
		eff3(&a,&b);
		bally1main();
	}
      }


	main();
}

 if (ch=='d'|| ch=='D')
 {
 setcolor(BLACK);
 arrow(ii);
 if(ii==250&&q==160)
{
	q=0;w=0;ii=100;
}
 if (ii==250)
 {ii=100;q=0;w=10;}
 ii+=25;
 setcolor(RED);
 arrow(ii);
 }


 if (ch=='a'|| ch=='A')
 {
 setcolor(BLACK);
 arrow(ii);
 if(ii==125&&q==160)
 {
 ii=275;
}
 if (ii==125)
 {ii=275;q=0;w=10;}

 setcolor(RED);
 ii-=25;
 arrow(ii);
 }
}


void border()
{
settextstyle(0,0,0);
setfillstyle(1,BLACK);
rectangle(1,1,600,300);
rectangle(9,9,591,291);
line(350,9,350,291);
line(360,9,360,291);
setcolor(BROWN);
outtextxy(390,55,"TO MOVE ARROW USE");
outtextxy(390,75,"'A' TO MOVE UP AND ");
outtextxy(390,95,"'D' TO MOVE DOWN. ");
outtextxy(390,115,"ENTER TAKES YOU TO ");
outtextxy(390,135,"THE MENU TO WHICH THE");
outtextxy(390,155,"PIONTER IS POINTING.");
outtextxy(390,175,"Q HELPS IN EXITING");
outtextxy(390,195,"ANY TIME.");
setfillstyle(HATCH_FILL,YELLOW);
floodfill(7,7,GREEN);
floodfill(355,15,GREEN);
rectangle(1,330,600,470);
setcolor(RED);
settextstyle(0,0,1);
outtextxy(30,40,"THE SHARK");
setcolor(GREEN);
setcolor(RED);
outtextxy(150,335,"Welcome... Hope U Enjoy using our Package...");
outtextxy(175,355,"For more information mail us at ");
outtextxy(175,375,"karthik.s.sundaram@gmail.com");
outtextxy(175,385,"hariram1207@gmail.com");
outtextxy(175,395,"hariram_1207@hotmail.com");
outtextxy(175,405,"deepak_may_91@hotmail.com");
outtextxy(175,455,"(:Thank you:)");
setcolor(GREEN);
outtextxy(350,455," :-The Sharks Associates-:");
setcolor(GREEN);
}
