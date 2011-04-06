#include<graphics.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<dos.h>
#include<iostream.h>
#include<bios.h>


void table();
void blackkey(int,int);
void redkey(int,int);
void greenkey(int);
void piano();


enum swara1{s=262,r1=277,r_=294,g_=311,g=330,m1=349,m_=370,pe=392,d1=415,d_=440,n_=466,ne=494}s1;
enum swara2{sa=523,ri_=553,ri=589,ga_=622,ga=658,ma=695,ma_=740,pa=782,da=833,da_=880,ni_=930,ni=983} s2;
enum swara3{saa=1046,rii=1106,rii_=1178,gaa_=1244,gaa=1316,maa=1390,
	maa_=1480,paa=1564,daa=1666,daa_=1760,nii_=1860,nii=1966}s3;
#define d delay(50);
#define f(x) sound(x);

void table()
{
	line(100,150,496,150);
	line(100,150,75,300);
	line(496,150,481,300);
	line(75,300,481,300);
	line(88,225,489,225);
	line(190,150,180,220);
	line(180,220,88,220);
	circle(140,185,30);
	setfillstyle(11,WHITE);
	floodfill(140,185,WHITE);
	line(410,150,400,220);
	line(400,220,490,220);
	circle(450,185,30);
	floodfill(440,185,WHITE);

	setfillstyle(1,WHITE);
	floodfill(100,250,WHITE);
	floodfill(350,250,WHITE);
	setcolor(BLACK);
	blackkey(106,93);
	blackkey(124,111);
	line(142,225,129,300);
	blackkey(160,147);
	blackkey(178,165);
	blackkey(196,183);
	line(214,225,201,300);
	blackkey(232,219);
	blackkey(250,237);
	line(268,225,255,300);
	blackkey(286,273);
	blackkey(304,291);
	blackkey(322,309);
	line(340,225,327,300);
	blackkey(358,345);
	blackkey(376,363);
	line(394,225,381,300);
	blackkey(412,399);
	blackkey(430,417);
	blackkey(448,435);
	line(466,225,453,300);
	line(484,225,471,300);
	setcolor(WHITE);
	settextstyle(0,0,3);
	outtextxy(230,170,"SHARK");
	settextstyle(2,0,7);
	outtextxy(200,400,"F1 for help2 ");
	outtextxy(200,440,"Esc twice to Exit");
	outtextxy(200,420,"Enter to open a file");
}



void show(int a)
{
char sw[10];
switch(a)
{

	case 262:strcpy(sw,"S");break;
	case 277:strcpy(sw,"R");break;
	case 294:strcpy(sw,"R'");break;
	case 311:strcpy(sw,"G'");break;
	case 330:strcpy(sw,"G");break;
	case 349:strcpy(sw,"M'");break;
	case 370:strcpy(sw,"M'");break;
	case 392:strcpy(sw,"P");break;
	case 415:strcpy(sw,"D");break;
	case 440:strcpy(sw,"D'");break;
	case 466:strcpy(sw,"N'");break;
	case 494:strcpy(sw,"N");break;
	case 523:strcpy(sw,"SA");break;
	case 553:strcpy(sw,"RI'");break;
	case 589:strcpy(sw,"RI");break;
	case 622:strcpy(sw,"GA'");break;
	case 658:strcpy(sw,"GA");break;
	case 695:strcpy(sw,"MA");break;
	case 740:strcpy(sw,"MA'");break;
	case 782:strcpy(sw,"PA");break;
	case 833:strcpy(sw,"DA");break;
	case 880:strcpy(sw,"DA'");break;
	case 930:strcpy(sw,"NI'");break;
	case 983:strcpy(sw,"NI");break;
	case 1046:strcpy(sw,"SAA");break;
	case 1106:strcpy(sw,"RII");break;
	case 1178:strcpy(sw,"RII_");break;
	case 1244:strcpy(sw,"GAA_");break;
	case 1316:strcpy(sw,"GAA");break;
	case 1390:strcpy(sw,"MAA");break;
	case 1480:strcpy(sw,"MAA_");break;
	case 1564:strcpy(sw,"PAA");break;
	case 1666:strcpy(sw,"DAA");break;
	case 1760:strcpy(sw,"DAA_");break;
	case 1860:strcpy(sw,"NII_");break;
	case 1966:strcpy(sw,"NII");break;


}
	settextstyle(1,0,3);
	setcolor(WHITE);
	outtextxy(200,100,sw);
	d d
	setcolor(BLACK);
	outtextxy(200,100,sw);

}



void blackkey(int a,int b)
{
	setcolor(BLACK);
	line(a-6,263,b,300);
	line(a-5,225,a-11,263);
	line(a+5,225,a-1,263);
	line(a-11,263,a-1,263);
	setfillstyle(1,BLACK);
	floodfill(a-6,235,BLACK);
}

void greenkey(int a)
{
	setfillstyle(1,GREEN);
	floodfill(a+1,227,BLACK);
	settextstyle(0,0,0);
	d    d
	setfillstyle(1,WHITE);
	floodfill(a+1,227,BLACK);
}

void redkey(int a,int b)
{
	setcolor(RED);
	line(a-6,263,b,300);
	line(a-5,225,a+5,225);
	line(a-5,225,a-11,263);
	line(a+5,225,a-1,263);
	line(a-11,263,a-1,263);
	setfillstyle(1,RED);
	floodfill(a-6,235,RED);
	d     d
	blackkey(a,b);
}

void song(char song[])
{
	char st[5];
	ifstream h(song,ios::in);
	if(h)
	{
	h>>st;
	cleardevice();
	table();
	while(!h.eof())
	{
	    //  nosound();

		if(strcmp(st,"s")==0)	{
						f(s)
						greenkey(88);
					}
		else if(strcmp(st,"r")==0)	{
							f(r1)
							redkey(106,93);
						}
		else if(strcmp(st,"r_")==0)	{
							f(r_)
							greenkey(112);
						}
		else if(strcmp(st,"g_")==0)	{
							f(g_)
							redkey(124,111);
						}
		else if(strcmp(st,"g")==0)	{
							f(g)
							greenkey(130);
						}
		else if(strcmp(st,"m")==0)	{
							f(m1)
							greenkey(147);
						}
		else if(strcmp(st,"m_")==0)	{
							f(m_)
							redkey(160,147);
						}
		else if(strcmp(st,"p")==0)	{
							f(pe)
							greenkey(166);
						}
		else if(strcmp(st,"d1")==0)	{
							f(d1)
							redkey(178,165);
						}
		else if(strcmp(st,"d_")==0)	{
							f(d_)
							greenkey(186);
						}
		else if(strcmp(st,"n_")==0)	{
							f(n_)
							redkey(196,183);
						}
		else if(strcmp(st,"ne")==0)	{
							f(ne)
							greenkey(206);
						}
		else if(strcmp(st,"sa")==0)	{
							f(sa)
							greenkey(214);
						}
		else if(strcmp(st,"ri_")==0)	{
							f(ri_)
							redkey(232,219);
						}
		else if(strcmp(st,"ri")==0)	{
							f(ri)
							greenkey(242);
						}

		else if(strcmp(st,"ga_")==0)	{

							f(ga_)
							redkey(250,237);
						}
		else if(strcmp(st,"ga")==0)	{
							f(ga)
							greenkey(260);
						}
		else if(strcmp(st,"ma")==0)	{
							f(ma)
							greenkey(268);
						}
		else if(strcmp(st,"ma_")==0)	{
							f(ma_)
							redkey(286,273);
						}
		else if(strcmp(st,"pa")==0)	{
							f(pa)
							greenkey(296);
						}
		else if(strcmp(st,"da")==0)	{
							f(da)
							redkey(304,291);
						}
		else if(strcmp(st,"da_")==0)	{
							f(da_)
							greenkey(314);
						}
		else if(strcmp(st,"ni_")==0)	{
							f(ni_)
							redkey(322,309);
						}
		else if(strcmp(st,"ni")==0)	{
							f(ni)
							greenkey(332);
						}
		else if(strcmp(st,"saa")==0)	{
							f(saa)
							greenkey(340);
						}
		else if(strcmp(st,"rii_")==0)	{
							f(rii_)
							redkey(358,345);
						}
		else if(strcmp(st,"rii")==0)	{
							f(rii)
							greenkey(368);
						}
		else if(strcmp(st,"gaa_")==0)	{
							f(gaa_)
							redkey(376,363);
						}
		else if(strcmp(st,"gaa")==0)	{
							f(gaa)
							greenkey(386);
						}
		else if(strcmp(st,"maa")==0)	{
							f(maa)
							greenkey(394);
						}
		else if(strcmp(st,"maa_")==0)	{
							f(maa_)
							redkey(412,399);
						}
		else if(strcmp(st,"paa")==0)	{
							f(paa)
							greenkey(422);
						}
		else if(strcmp(st,"daa")==0)	{
							f(daa)
							redkey(430,417);
						}
		else if(strcmp(st,"daa_")==0)	{
							f(daa_)
							greenkey(440);
						}
		else if(strcmp(st,"nii_")==0)f(nii_)
		else if(strcmp(st,"nii")==0)f(nii)
		else if(strcmp(st,"d")==0)d
		else if(strcmp(st,"n")==0)nosound();

		h>>st;
		delay(130);
	}
	nosound();
	}
	else cout<<"\nFile Not Found";
	delay(10);
	piano();
}


void help2()
{
  //	int gd=9,gm=2;
//	initgraph(&gd,&gm,"d:/tc1/bgi");
	cleardevice();
	settextstyle(1,0,1);
	outtextxy(100,100,"Help");
	outtextxy(100,120,"KEY      Swara(Note)");
	outtextxy(100,140,"OCTET 1");
	outtextxy(100,160,"Q        Sa");
	outtextxy(100,180,"2        Ri sharp");
	outtextxy(100,200,"W        Ri ");
	outtextxy(100,220,"3        Ga sharp");
	outtextxy(100,240,"E        Ga ");
	outtextxy(100,260,"R        Ma");
	outtextxy(100,280,"5        Ma sharp");
	outtextxy(100,300,"T        Pa");
	outtextxy(100,320,"6        Da sharp");
	outtextxy(100,340,"Y        Da");
	outtextxy(100,360,"7        Ni Sharp");
	outtextxy(100,380,"U        Ni");
	outtextxy(300,120,"KEY      Swara(Note)");
	outtextxy(300,140,"OCTET 2");
	outtextxy(300,160,"Z        Sa");
	outtextxy(300,180,"S        Ri sharp");
	outtextxy(300,200,"X        Ri ");
	outtextxy(300,220,"D        Ga sharp");
	outtextxy(300,240,"C        Ga ");
	outtextxy(300,260,"V        Ma");
	outtextxy(300,280,"G        Ma sharp");
	outtextxy(300,300,"B        Pa");
	outtextxy(300,320,"H        Da sharp");
	outtextxy(300,340,"N        Da");
	outtextxy(300,360,"J        Ni Sharp");
	outtextxy(300,380,"M        Ni");
	outtextxy(300,400,"<        Saa");
	getch();
	piano();
}



void piano()
{

	int driver=VGA,mode=2;
	initgraph(&driver,&mode,"d://tc1//bgi");
	setfillstyle(0,WHITE);
	table();

	setfillstyle(1,GREEN);
	setcolor(WHITE);
	settextstyle(8,0,3);
	char st[100];

	for (int i = 1 ; i <=1000; i++)
	{
	int j=bioskey(0);
	switch(j)

	{

		case 4209: f(s)show(s); greenkey(88); break;
		case 818: f(r_)show(r_); redkey(106,93);break;
		case 4471: f(r1)show(r1); greenkey(112);break;
		case 1075: f(g_)show(g_); redkey(124,111);  break;
		case 4709: f(g)show(g); greenkey(130);break;
		case 4978: f(m1)show(m1); greenkey(147);break;
		case 1589: f(m_)show(m_); redkey(160,147); break;
		case 5236: f(pe)show(pe); greenkey(166); break;
		case 1846: f(d1)show(d1); redkey(178,165); break;
		case 5497: f(d_)show(d_); greenkey(186); break;
		case 2103: f(n_)show(n_); redkey(196,183); break;
		case 5749: f(ne)show(ne); greenkey(206); break;
		case 5993: f(sa)show(sa); greenkey(214); break;
		case 11386: f(sa)show(sa); greenkey(214); break;
		case 8051: f(ri_)show(ri_); redkey(232,219); break;
		case 11640: f(ri)show(ri); greenkey(242); break;
		case 8292: f(ga_)show(ga_); redkey(250,237); break;
		case 11875: f(ga)show(ga); greenkey(260); break;
		case 12150: f(ma)show(ma); greenkey(268); break;
		case 8807: f(ma_)show(ma_); redkey(286,273); break;
		case 12386: f(pa)show(pa); greenkey(296); break;
		case 9064: f(da)show(da); redkey(304,291); break;
		case 12654: f(da_)show(da_); greenkey(314); break;
		case 9322: f(ni_)show(ni_); redkey(322,309); break;
		case 12909: f(ni)show(ni); greenkey(332); break;
		case 13100: f(saa)show(saa); greenkey(340); break;
		case 21248: f(saa)show(saa); greenkey(340); break;
		case 18176: f(rii_)show(rii_); redkey(358,345); break;
		case 20224: f(rii)show(rii); greenkey(368); break;
		case 18668: f(gaa_)show(gaa_); redkey(376,363); break;
		case 20736: f(gaa)show(gaa); greenkey(386); break;
		case 19252: f(maa)show(maa); greenkey(394); break;
		case 18488: f(maa_)show(maa_); redkey(412,399); break;
		case 19509: f(paa)show(paa); greenkey(422); break;
		case 18745: f(daa)show(daa); redkey(430,417); break;
		case 19766: f(daa_)show(daa_); greenkey(440); break;
		case 7181 : cout<<"\r\rEnter Destination Path :";
			    cin>>st;song(st);break;
		case 283  : goto end;break;
		case 15104: help2();break;
		}
	delay(0);
	nosound();
	}
	end:
	nosound();
	getch();
	closegraph();

}






void menup()
{
	int gd=9,gm=2;
	initgraph(&gd,&gm,"h:/tc1/bgi");
	settextstyle(6,0,3);
	outtextxy(90,100,"Welcome to Shark Music Solutions TM");
	settextstyle(2,0,5);
	outtextxy(60,140,"Here is a keyboard operated Software with which you");
	outtextxy(60,160,"can enter the world of music that stirs your soul!");
	outtextxy(60,180,"You can also play some tunes by just typing the ");
	outtextxy(60,200,"swaras in a notepad file..Its Simple But yet complicated!");
	outtextxy(60,220,"A Nice way to improve your musical talents");
	outtextxy(60,250,"Thanking you");
	outtextxy(60,270,"The Shark Group Associates");

	outtextxy(60,320,"Loading...");
	for(int i=0;i<20;i++)
	{
		setfillstyle(1,BLACK);
		bar(340,305,370,335);
		for(int j=0;j<=360;j+=5)
		{
			pieslice(355,320,0,j,15);
			//delay(10);
		}
	}
	getch();
	cleardevice();
	piano();


}

void  pianomain()
{

	menup();
//	return 0;

}

/*
swara1{}s1;
enum swara2{} s2;
enum swara3{saa=1046,rii=1106,rii_=1178,gaa_=1244,gaa=1316,maa=1390,

  */
