#include<iostream.h>
#include<grap.cpp>
#include<solar.cpp>
#include<roots.cpp>
#include<sincos.cpp>
#include <FLYBALL.cpp>
#include <3drot.cpp>
#include <PIEBAR.cpp>
#include <PRIMES.cpp>
#include <sparkal.cpp>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<piano.cpp>
#include<stdlib.h>
#include<bios.h>
#include<fade.cpp>
#include<intro.cpp>
void bgmusic(char []);
int next=0;

void main();
void menumain();
void border();
void arrow(int);
void move(char);

int ii=125;
char ch;
void ackno()
{
     cleardevice();
     settextstyle(4,0,7);
     outtextxy(50,20,"The Shark Associates ");
     settextstyle(2,0,5);
     setcolor(CYAN);
     outtextxy(50,160,"We would like to thank");
     outtextxy(50,180,"Our teachers Mrs.Nirmala Devi, Mrs.Harifa Begum,");
     outtextxy(50,200,"Professor TR Subramaniam, ");
     outtextxy(50,220,"Our Parents,our School,");
     outtextxy(50,240,"And last but not the least");
     outtextxy(50,260,"Our Friends S.Jaichander XII B,");
     outtextxy(50,280,"V.Giridhari XII C , Anush XII D ,V.Keshav X C");
     outtextxy(50,300,"for helping us in this Project...");
     outtextxy(50,320,"Thank you !!!!");
     outtextxy(50,380,"COPYRIGHTS -: THE SHARK ASSOCIATES :-");
     getch();
}


void introd()
{
	int 	x,y,j,c,e,g,da;
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
		da=random(12);
		setcolor(da);
		circle(320,240,z);
		delay(50);
		nosound();
	}
	for(int qq=80;qq<340;qq++)
	{
		sound(500*qq);
		setcolor(0);
		circle(320,240,qq);
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
int tie=1;

void main()
{
int a=0,b,flag=0;
initgraph(&a,&b,"d:\\tc\\bgi");
if (tie==1)//introd();
tie++;
cleardevice();
if(flag==0)
{
flag=1;
cleardevice();
}
menumain();
}


void maths()
{
	//roots sincos piebar primes
	char ch;
	cleardevice();
	setcolor(LIGHTMAGENTA);
	settextstyle(0,0,0);
	outtextxy(300,100,"MATHEMAGIC");
	setcolor(BROWN);
	outtextxy(100,200,"Enter Option");
	outtextxy(100,225,"1.Primes Of a Given Number");
	outtextxy(100,250,"2.Roots of a Given nth degree equation");
	outtextxy(100,275,"3.Trigonometric Graphing");
	outtextxy(100,300,"4.Pie Slice and Bar Graphs");
	ch=getch();
	cleardevice();
	if(ch=='1')
	{
	cleardevice();

		primemain();
	}
	else if (ch=='2')
	{
		cleardevice();
		rootmain();
	}
	else if(ch=='3')
	{
		cleardevice();
		sinemain();
	}
	else if(ch=='4')
	{
		cleardevice();
		piemain();
	}
	else main();
}





void menumain()
{
setfillstyle(1,1);
cleardevice();
setcolor(GREEN);
cleardevice();
border();
settextstyle(11,HORIZ_DIR,2);
outtextxy(50,125,"1.Sharx Math");
outtextxy(50,150,"2.3D Graphing");
outtextxy(50,175,"3.Solar System");
outtextxy(50,200,"4.Fly Ball");
outtextxy(50,225,"5.3D Rotation");
outtextxy(50,250,"6.Exit");
setcolor(RED);
arrow(ii);

while(ch!='q')
{
	if(next==0)bgmusic("dhoom.txt");
	else if(next==1)bgmusic("uyirin.txt");
	ch=getch();
	sound(3000);
	delay(50);
	nosound();
	move(ch);
}


}
int qq=0;//160
int w_=0;//10
void arrow(int k)
{
line(qq+15,k,qq+35,k);
line(qq+35,k,qq+25,k-5);
line(qq+35,k,qq+25,k+5);
}

void move(char ch)
{
	int a=RED,b=YELLOW;
	if (ch==13)
	{
		 if (ii==125)
		 {
			eff3(&a,&b);
			maths();
		 }
		 if (ii==150)
		 {
			a++;b++;
			eff2(&a,&b);
			grapmain();
		 }

		 if (ii==175)
		 {
			a++;b++;
			eff2(&a,&b);
				solarmain();
		}
		 if (ii==200)
		 {
			a++;b++;
			eff3(&a,&b);
			flymain();
		 }
		 if (ii==250)
		 {
			a++;b++;
			eff2(&a,&b);
			ackno();
			exit(0);
		 }
		 if (ii==225)
		 {     a++;b++;
			eff3(&a,&b);
			rotmain();
		}

		main();
	}
	 if (ch=='d'|| ch=='D')
	 {
		 setcolor(BLACK);
		 arrow(ii);
		 if(ii==250&&qq==160)
		{
			qq=0;w_=0;ii=100;
		}
		 if (ii==250)
		 {ii=100;qq=0;w_=10;}
		ii+=25;
		 setcolor(RED);
		 arrow(ii);
	}
	if (ch=='a'|| ch=='A')
	{
		setcolor(BLACK);
		 arrow(ii);
		 if(ii==125&&qq==160)
		 {
		ii=275;qq=0;w_=0;
		}
		if (ii==125)
		{ii=275;qq=0;w_=10;}
		 setcolor(RED);
		 ii-=25;
		 arrow(ii);
	}

 }


int tellme=0,endy=0;

void bgmusic(char song[])
{
	char st[5];

	ifstream h(song,ios::in);
   if(!h.eof())
   {
	h.seekg(tellme,ios::beg);
	h>>st;
	while(!h.eof()&&!kbhit())
	{
	    //  nosound();

		if(strcmp(st,"s")==0)	{
						f(s)
					}
		else if(strcmp(st,"r")==0)	{
							f(r1)
						}
		else if(strcmp(st,"r_")==0)	{
							f(r_)
						}
		else if(strcmp(st,"g_")==0)	{
							f(g_)
						}
		else if(strcmp(st,"g")==0)	{
							f(g)
						}
		else if(strcmp(st,"m")==0)	{
							f(m1)
						}
		else if(strcmp(st,"m_")==0)	{
							f(m_)
						}
		else if(strcmp(st,"p")==0)	{
							f(pe)
						}
		else if(strcmp(st,"d1")==0)	{
							f(d1)
						}
		else if(strcmp(st,"d_")==0)	{
							f(d_)
						}
		else if(strcmp(st,"n_")==0)	{
							f(n_)
						}
		else if(strcmp(st,"ne")==0)	{
							f(ne)
						}
		else if(strcmp(st,"sa")==0)	{
							f(sa)
						}
		else if(strcmp(st,"ri_")==0)	{
							f(ri_)
						}
		else if(strcmp(st,"ri")==0)	{
							f(ri)
						}

		else if(strcmp(st,"ga_")==0)	{
							f(ga_)
						}
		else if(strcmp(st,"ga")==0)	{
							f(ga)
						}
		else if(strcmp(st,"ma")==0)	{
							f(ma)
						}
		else if(strcmp(st,"ma_")==0)	{
							f(ma_)
						}
		else if(strcmp(st,"pa")==0)	{
							f(pa)
						}
		else if(strcmp(st,"da")==0)	{
							f(da)
						}
		else if(strcmp(st,"da_")==0)	{
							f(da_)
						}
		else if(strcmp(st,"ni_")==0)	{
							f(ni_)
						}
		else if(strcmp(st,"ni")==0)	{
							f(ni)
						}
		else if(strcmp(st,"saa")==0)	{
							f(saa)
						}
		else if(strcmp(st,"rii_")==0)	{
							f(rii_)
						}
		else if(strcmp(st,"rii")==0)	{
							f(rii)
						}
		else if(strcmp(st,"gaa_")==0)	{
							f(gaa_)
						}
		else if(strcmp(st,"gaa")==0)	{
							f(gaa)
						}
		else if(strcmp(st,"maa")==0)	{
							f(maa)
						}
		else if(strcmp(st,"maa_")==0)	{
							f(maa_)
						}
		else if(strcmp(st,"paa")==0)	{
							f(paa)
						}
		else if(strcmp(st,"daa")==0)	{
							f(daa)
						}
		else if(strcmp(st,"daa_")==0)	{
							f(daa_)
						}
		else if(strcmp(st,"nii_")==0)f(nii_)
		else if(strcmp(st,"nii")==0)f(nii)
		else if(strcmp(st,"d")==0)d
		else if(strcmp(st,"n")==0)nosound();

		h>>st;
		d d d
	}
	tellme=h.tellg();
	nosound();
}
	h.seekg(0,ios::end);
	endy=h.tellg();
	if(tellme==endy){next=1;tellme=0;}


       //	else cout<<"\nFile Not Found";
       //	delay(500);
}



void border()
{
settextstyle(0,HORIZ_DIR,0);
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
outtextxy(390,155,"POINTER IS POINTING.");
outtextxy(390,175,"Q HELPS IN EXITING");
outtextxy(390,195,"ANY TIME.");
setfillstyle(HATCH_FILL,YELLOW);
floodfill(7,7,GREEN);
floodfill(355,15,GREEN);
rectangle(1,330,600,470);
setcolor(RED);

outtextxy(30,40,"THE SHARK");
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
