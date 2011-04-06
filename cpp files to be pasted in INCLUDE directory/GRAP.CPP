#include<dos.h>
#include<process.h>
#include<fstream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>

# define PI M_PI
int	w,z,button;
union REGS i,o;
int initmouse()
{
 i.x.ax=7;
 int86(0x33,&i,&o);
 return(o.x.ax);
}
void showmouseptr()
{
 i.x.ax=1;
 int86(0x33,&i,&o);
}

void getmousepos(int *button, int *x, int *y)
{
 *button = 0;
 i.x.ax=3;
 int86(0x33,&i,&o);
 *button=o.x.bx;
 *x=o.x.cx;
 *y=o.x.dx;
}
void HideMouse(void)
{
    union REGS regs;

    regs.x.ax = 2;
    int86(0x33,&regs,&regs);
}

void dontshowmouseptr()
{
i.x.ax=20;
 int86(0x33,&i,&o);
}
restrictmouseptr(int x1,int y1, int x2, int y2)
{
i.x.ax=7;
i.x.cx=x1;
i.x.dx=x2;
int86(0x33,&i,&o);

i.x.ax=8;
i.x.cx=y1;
i.x.dx=y2;
int86(0x33,&i,&o);

return(0);
}

char string[40];
int theta=60,phi=330;
char dummy[30];
char result[30];
int flag=0,aflag=0;
int j,k,k1,cx,cy,q=0;


void input()
{
	setfillstyle(1,1);
	bar(30,40,610,79);
	setcolor(14);
	settextstyle(2,0,5);
	outtextxy(50,50,"Enter Function :: z = ");
	setcolor(15);
	rectangle(30,40,610,79);
	rectangle(30,80,610,420);
	char ch;
	int p =0;
	ch = getch();
	char st[2];
	setcolor(12);
	while(ch!='\r')
	{
		if((int)ch == 8)
		{
			setfillstyle(1,1);
			bar(250+8*p,48,242+8*p,72);
			p--;
			ch = getch();
			string[p]='\0';
			continue;
		}
		st[0] = ch;
		st[1] = '\0';
		outtextxy(250+8*p,50,st);
		string[p++] = ch;
		ch = getch();
	}
}


void coord_show(int color,float r)
{
	float x1,y1;
	float angle1 = (theta * PI)/180.0;
	float angle2 = (phi * PI)/180.0;
	int i = 1;
	setcolor(color);
	while(i<4)
	{
		switch(i)
		{
			case 1:{
						y1 = r*cos(angle1)*cos(angle2); // X Axis
						x1 = -r*sin(angle2);
						break;
					}
			case 2:{
						y1 = r*cos(angle1)*sin(angle2); // Y Axis
						x1 = r*cos(angle2);
						break;
					}
			case 3:{
						x1 = 0;							// Z Axis
						y1 = -r*sin(angle1);
						break;
					}
		}
		line(320-x1,240-y1,320+x1,240+y1);
		i++;
	}
}
void point_3d(float x1,float y1,float z1,int color)
{
		float angle1 = (theta * PI)/180.0;
		float angle2 = (phi * PI)/180.0;
		float a1 = sin(angle1)*cos(angle2)*x1 + sin(angle1)*sin(angle2)*y1 + cos(angle1)*z1;
		float a2 = cos(angle1)*cos(angle2)*x1 + cos(angle1)*sin(angle2)*y1 - sin(angle1)*z1;
		float a3 = -sin(angle2)*x1 + cos(angle2)*y1;
		float xx1 = 320+10*a3;
		float xx2 = 240+10*a2;
		setcolor(color);
		putpixel(xx1,xx2,color);
}



float getres(float p1,float p2)
{
	if(k>=0)
	{
		switch(result[k])
		{
			case 's':
					{
						k--;
						return sin(getres(p1,p2));
					}
			case 'c':
					{
						k--;
						return cos(getres(p1,p2));
					}
			case 'e':
					{
						k--;
						return exp(getres(p1,p2));
					}
			case 'l':
					{
						k--;
						float b=getres(p1,p2);
						if(b>0)
						{
							flag=0;
							return log(b);
						}
						else
						{
							flag=1;
							return 0;
						}
					}
			case 'f':
					{
						k--;
						return floor(getres(p1,p2));
					}
			case 'a':
					{
						k--;
						return fabs(getres(p1,p2));
					}
			case 't':
					{
						k--;
						return tan(getres(p1,p2));
					}
			case '+':
					{
						k--;
						return getres(p1,p2) + getres(p1,p2);
					}
			case '-':
					{
						k--;
						return -getres(p1,p2) + getres(p1,p2);
					}
			case '*':
					{
						k--;
						return getres(p1,p2) * getres(p1,p2);
					}
			case '/':
					{
						k--;
						return (1/getres(p1,p2)) * getres(p1,p2);
					}
			case '^':
					{
						k--;
						float a = getres(p1,p2);
						float b = getres(p1,p2);
						if((a<1)&&(a>-1)&&(b<0))
							return 0;
						else
							return pow(b,a);
					}
			case 'x':
					{
						k--;
						return p1;
					}
			case 'y':
					{
						k--;
						return p2;
					}
			default :
					{
						k--;
						return (result[k+1] - '0');
					}
		}
	}
}



float eval(float p1,float p2)
{
	k = strlen(result) - 1;
	float b = getres(p1,p2);
	return b;
}

void push(char ch,int n)
{
	for(int p=strlen(string);p>=n;p--)
		string[p+1] = string[p];
	string[n] = ch;
}

void delet(int n)
{
	dummy[n] = '\0';
}

void itop()
{
	j = 0;
	k = 0;
	int i = 0;
	push('(',0);
	push(')',strlen(string));
	while(string[i]!='\0')
	{
		switch(string[i])
		{
			case '(':
			case '+':
			case '*':
			case '/':
			case '-':
			case '^':
					{
						dummy[j++] = string[i++];
						dummy[j] = '\0';
						break;
					}
			case 's':
			case 'c':
			case 't':
			case 'l':
			case 'e':
			case 'f':
			case 'a':
					{
						dummy[j++] = '(';
						dummy[j++] = string[i];
						dummy[j] = '\0';
						i+=4;
						break;
					}
			case ')':
					{
						j=strlen(dummy) - 1 ;
						for(;dummy[j] != '(';)
						{
							result[k++] = dummy[j--];
						}
						delet(j);
						i++;
						break;
					}
			default :
					{
						result[k++] = string[i++];
						break;
					}
		}
	}
}
void intro()
{
    cleardevice();
    settextstyle(0,0,0);
    outtextxy(100,100,"How to draw a 3-D graph :");
    outtextxy(110,120," Type in the function whose grpah u want to draw : ");
    outtextxy(110,140," while drawing to obtain powers use ^...for eg:for xý type x^2 ");
    outtextxy(110,160,"to draw trig graphs  type sinex or tanx or cosx");
    outtextxy(110,180," When the graph appears press Y to draw the x,y and z axes");
    outtextxy(110,200,"use the keys W,S,A and D to rotate the grpahs along the 3-D axes ");
    outtextxy(110,220," We can also convert the 3-D into 2-D by moving it suitably");
    outtextxy(110,240,"So now that u know start of...");
    outtextxy(110,260,"To draw please press enter");
    getch();
   }
void choose()
{
	setfillstyle(1,BLUE);
	settextstyle(0,0,0);
	outtextxy(100,100,"Welcome to the world of 3-D graphing...");
    outtextxy(110,120,"We have all seen a lot of 2-D graphs in textbooks but ");
    outtextxy(110,135,"we have rarely come across 3-D graphs...here we present it to you");
    outtextxy(110,150,"Our program is capable of drawing most arithmetic graphs and quite");
    outtextxy(110,165,"a number of other graphs like trig functions");
	rectangle(100,200,250,250);
	outtextxy(130,225,"Back to menu");

	rectangle(260,200,410,250);
	outtextxy(290,225," Draw graph");

	rectangle(430,200,580,250);
	outtextxy(460,225,"Instructions");

      int n=0;
			showmouseptr();
		getmousepos(&button,&w,&z);

		while(button==0)
		{
			getmousepos(&button,&w,&z);
                        settextstyle(2,0,4);
			 setcolor(n);
                          n++;
			  outtextxy(500,500,"3D GRAPH");

			if(button==1)

			{
				getmousepos(&button,&w,&z);
				if( w>430 && w<580 && z>200 && z<250)
				{
					HideMouse();
					cleardevice();
					intro();
					getch();
					cleardevice();
					input();



				}
				  else if(w>260 && w<410 && z>200 && z<250)
				  {
					HideMouse();
					cleardevice();
					input();
				  }
				    else if(w>100 && w<250 && z>200 && z<250) goto er;
			  er:


			}
		}



}
void grapmain()
{
	int gd=9,gm=2;
	initgraph(&gd,&gm,"d:/tc1/bgi");
	setfillstyle(1,8);
	restrictmouseptr(0,0,640,480);
	choose();
	cleardevice();
	char dum[30];
	strcpy(dum,string);
	itop();
	outtextxy(10,10,"3dPlot");
	outtextxy(400,10,"z =");
	outtextxy(430,10,dum);
	float ox,oy,oz;
	outtextxy(140,450,"w,a,s,d to rotate the graph , enter to return , y for axes");
	theta = 60;phi = 330;
	char ch;
	do
	{
		if(ch=='w') theta = theta - 5;
		if(ch=='s') theta = theta + 5;
		if(ch=='d') phi = phi +5;
		if(ch=='a') phi = phi -5;
		if((theta)>180) theta = theta - 5;
		if((theta)<0) theta = theta + 5;
		if((phi)>360) phi = 0;
		if((phi)<0) phi = 360;
		if(ch=='y') aflag = 1-aflag;
		setcolor(15);
		if(aflag==1)
			coord_show(11,150);
		for(float x=-2;x<2;x+=.06)
			for(float y=-2;y<2;y+=.06)
			{
				flag=0;
				float z = 5*eval(x,y);
				int col=(x+y)*5+50;
					if(flag==0)
						point_3d(5*x,5*y,z,col);
			}
		ch=getch();
		if(aflag==1)
			coord_show(0,150);
		for(x=-2;x<2;x+=.06)
			for(y=-2;y<2;y+=.06)
			{
				flag=0;
				float z = 5*eval(x,y);
					if(flag==0)
						point_3d(5*x,5*y,z,0);
			}
	}while(ch!='\r');
}
