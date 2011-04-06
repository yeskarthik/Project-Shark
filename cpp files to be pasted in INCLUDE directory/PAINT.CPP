#include<dos.h>
#include<fstream.h>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<graphics.h>
#include<string.h>
int gd=9,gm=2,maxx,k,maxy,sav=0,abcd=0,x_,y,n=15,&color=n,flag=0,j=0,button,prevx,prevy,
go=0,jo=0,bax=0,bay=0,fo=0,lo=0,dif1=0,dif2=0,p1,q1,yo;
char string[100],string1[100];
union REGS i,o;

initmouse()
{
i.x.ax=0;
int86(0x33,&i,&o);
return(o.x.ax);
}

showmouseptr()
{
i.x.ax=1;
int86(0x33,&i,&o);
return(0);
}

hidemouseptr()
{
i.x.ax=2;
int86(0x33,&i,&o);
return(0);
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

getmousepos(int *button, int *x, int *y)
{
i.x.ax=3;
int86(0x33,&i,&o);

*button=o.x.bx;
*x=o.x.cx;
*y=o.x.dx;
return(0);
}
void elllipse();
void polygon();
void colorselection();
void open();
void save();
void cut(int ,int , int ,int,int &,int &,char []);
void paste(int,int,int &,int &, char[]);
void saveas();
void help();
void input(char string[])
{
	       char    c = getch();
	       char s[2];
       int     i = 0;
	       while (c !='\r')
	       {

		       s[0] = c;
		       s[1] = '\0';
		       setfillstyle(1,GREEN);
		       bar(maxx/2-85+8*i,maxy/2-10,maxx/2+85,maxy/2+15);
		       setcolor(BLACK);
		       outtextxy(maxx/2-85+8*i,maxy/2-10,s);
		       string[i]=c;
		       i++;
		       c = getch();
	       }
}
void help()
{
	cleardevice();
			initgraph(&gd,&gm,"c:\\tc\\bgi");
				cleardevice();

	outtextxy(200,35,"HELP");

	outtextxy(50,55,"To draw in different styles:");
	outtextxy(50,65,"choose the box from the right of the screen");


	outtextxy(50,85,"1.To draw a straight line:");
	outtextxy(50,95,"In the toolbox, click box which shows line to the side .");
	outtextxy(50,105,"Drag the pointer to draw the line.");

	outtextxy(50,125,"2.To draw a freeform line");
	outtextxy(50,135,"In the toolbox, click Line .");
	outtextxy(50,145,"Drag the pointer to draw the line.");

	outtextxy(50,165,"3.To draw a circle ");
	outtextxy(50,175,"In the toolbox, click circle till brown color is seen .");
	outtextxy(50,195,"Drag the pointer to draw the circle. ");


	outtextxy(50,205,"4.To draw an ellipse");
	outtextxy(50,215,"In the toolbox, click circle till brown color is seen.");
	outtextxy(50,225,"Drag the pointer to draw the circle.");

	outtextxy(50,245,"5.To draw a rectangleIn the toolbox,");
	outtextxy(50,255,"click Rectangle  to create a square-cornered shape,");
	outtextxy(50,265,"or click Rounded Rectangle  to create a round-cornered shape.");
	outtextxy(50,275,"To draw a rectangle,");
	outtextxy(50,285,"drag the pointer diagonally in the direction you want.");

	outtextxy(50,305,"6. To erase: In the toolbox,");
	outtextxy(50,315,"click Eraser and start erasing by dragging the pointer ");

	outtextxy(50,335,"7.To cut: choose the cut box and then drag the pointer over ");
	outtextxy(50,345,"an area to choose it to be cut..");

	outtextxy(50,365,"8.To paste: choose the paste box and then drag the pointer");
	outtextxy(50,375,"over an area to paste the recently cut images..");

	outtextxy(50,395,"9.To paint using thick brush choose the option and drag to paint");

	outtextxy(50,415,"10.To draw 3-D :choose a box to the bottom right and behold the suprise..");

	outtextxy(50,435,"11.To change colors:");
	outtextxy(50,445,"choose the color at the left bottom and start drawing with it.. ");
		getch();
	cleardevice();
	settextstyle(0,0,0);
	outtextxy(250,3,"THE SHARK DRAW");
}

void flood_fill(int x, int y, int color, int prevcolor)
{
	int c=getpixel(x,y);
	if(c==prevcolor && color!=prevcolor)
	{
		putpixel(x,y,color);
		flood_fill(x+1,y,color,prevcolor);
		flood_fill(x-1,y,color,prevcolor);
		flood_fill(x,y+1,color,prevcolor);
		flood_fill(x,y-1,color,prevcolor);

	}
}

void colorselection()
{
	while(((x_<=100)&&(y<=sqrt(108*108-(x_-1)*(x_-1))+479)&&(y>=370)))
	{
		prevx=x_;
		prevy=y;
		getmousepos(&button,&x_,&y);
		if(flag==0)
		{
			hidemouseptr();
			setcolor(YELLOW);
			setfillstyle(1,WHITE);
			pieslice(1,maxy,90,0,108);
			setfillstyle(1,YELLOW);
			pieslice(1,maxy,90,0,98);
			setfillstyle(1,RED);
			pieslice(1,maxy,90,0,88);
			setfillstyle(1,BLUE);
			pieslice(1,maxy,90,0,78);
			setfillstyle(1,CYAN);
			pieslice(1,maxy,90,0,68);
			setfillstyle(1,LIGHTBLUE);
			pieslice(1,maxy,90,0,58);
			setfillstyle(1,MAGENTA);
			pieslice(1,maxy,90,0,48);
			setfillstyle(1,GREEN);
			pieslice(1,maxy,90,0,38);
			setfillstyle(1,LIGHTMAGENTA);
			pieslice(1,maxy,90,0,28);
			setfillstyle(1,BROWN);
			pieslice(1,maxy,90,0,18);
			setfillstyle(1,BLACK);
			pieslice(1,maxy,90,0,8);
			flag=1;
		}
		if((button&1)==1)
		{
			 hidemouseptr();
			 n=getpixel(x_,y);
			 showmouseptr();
			 setcolor(n);
		}
		showmouseptr();
	}
}
void saveas()
{

	 setcolor(WHITE);
	 hidemouseptr();
   cut(maxx/2-100,maxy/2-40,maxx/2+100,maxy/2+40,p1,q1,"DUMMY.TXT");
   showmouseptr();
   setfillstyle(1,CYAN);
   hidemouseptr();
   bar(maxx/2-100,maxy/2-40,maxx/2+100,maxy/2+40);
   setfillstyle(1,BLACK);
     setcolor(BLACK);
     settextstyle(0,0,0);
   outtextxy(maxx/2-25,maxy/2-30,"SAVE");
   rectangle(maxx/2-99,maxy/2-39,maxx/2+99,maxy/2+39);
   rectangle(maxx/2-85,maxy/2-10,maxx/2+85,maxy/2+15);
   showmouseptr();
   getmousepos(&button,&x_,&y);
   input(string);
   setcolor(WHITE);
   setfillstyle(1,BLACK);
   bar(maxx/2-100,maxy/2-40,maxx/2+100,maxy/2+40);
   setfillstyle(1,n);
   paste(maxx/2-100,maxy/2-40,p1,q1,"DUMMY.TXT");
   hidemouseptr();
       cut(0,0,maxx,maxy,dif1,dif2,string);
       showmouseptr();
}

void save()
{
       if(string[0]=='\0')saveas();
       else
       {
	cut(0,0,maxx,maxy,dif1,dif2,string);
	showmouseptr();
       }
}

void open()
{

	 setcolor(WHITE);
	 hidemouseptr();
   cut(maxx/2-100,maxy/2-40,maxx/2+100,maxy/2+40,p1,q1,"DUMMY.TXT");
   showmouseptr();
   setfillstyle(1,CYAN);
   hidemouseptr();
   bar(maxx/2-100,maxy/2-40,maxx/2+100,maxy/2+40);
   setfillstyle(1,BLACK);
     setcolor(BLACK);
     settextstyle(0,0,0);
   outtextxy(maxx/2-25,maxy/2-30,"OPEN");
   rectangle(maxx/2-99,maxy/2-39,maxx/2+99,maxy/2+39);
   rectangle(maxx/2-85,maxy/2-10,maxx/2+85,maxy/2+15);
   showmouseptr();
   input(string1);
   setcolor(WHITE);
   setfillstyle(1,BLACK);
   bar(maxx/2-100,maxy/2-40,maxx/2+100,maxy/2+40);
   setfillstyle(1,n);
   paste(maxx/2-100,maxy/2-40,p1,q1,"DUMMY.TXT");
      paste(0,0,dif1,dif2,string);
      settextstyle(0,0,0);
      outtextxy(250,3,"THE SHARK DRAW");

 }
void specialeffects()
{
	while((x_>=maxx-100)&&(y<=sqrt(108*108-(x_-639)*(x_-639))+479)&&(y>=370)&&(flag==0))
	{
	     hidemouseptr();
	     setcolor(WHITE);
	     setfillstyle(1,WHITE);
	     pieslice(maxx,maxy,90,180,108);
	     setcolor(BLACK);
	     for(int i=60;i>=0;i-=30)
	     rectangle(maxx-30,maxy-30-i,maxx-10,maxy-10-i);
	     for(i=50;i>0;i-=30)
	     rectangle(maxx-30-25,maxy-20-i,maxx-30-5,maxy-0-i);
	     rectangle(maxx-30-50,maxy-10-45,maxx-30-30,maxy+10-45);
	     setfillstyle(1,WHITE);
	     setcolor(BLACK);
	     flag=1;
	      if(lo==1)
	    {
		    hidemouseptr();
		    setfillstyle(1,BROWN);
		    floodfill(bax,bay,BLACK);
		    showmouseptr();
	    }
	     showmouseptr();
	  }
	getmousepos(&button,&x_,&y);
	if(x_>=609 && x_<=629 && y>=389 && y<=409 )
	{
		settextstyle(0,0,0);
		setcolor(BLUE);
		outtextxy(542,452,"3D");
		outtextxy(542,467,"Cylinder");
		delay(200);
		setcolor(WHITE);
		outtextxy(542,452,"3D");
		outtextxy(542,467,"Cylinder");
		getmousepos(&button,&x_,&y);
		setcolor(BLACK);
		if(button&1==1)goto b;
	   }
	       if(x_>=609 && x_<=629 && y>=419 && y<=439 )
	       {
		settextstyle(0,0,0);
		setcolor(BLUE);
		outtextxy(542,452,"3D");
		outtextxy(542,467,"Ellipse");
		delay(200);
		setcolor(WHITE);
		outtextxy(542,452,"3D");
		outtextxy(542,467,"Ellipse");
		getmousepos(&button,&x_,&y);
		setcolor(BLACK);
		if(button&1==1)goto b;

	       }

		 if(x_>=609 && x_<=629 && y>=449 && y<=469 )
		 {
		settextstyle(0,0,0);
		setcolor(BLUE);
		outtextxy(542,452,"3D");
		outtextxy(542,467,"Cone");
		delay(200);
		setcolor(WHITE);
		outtextxy(542,452,"3D");
		outtextxy(542,467,"Cone");
		getmousepos(&button,&x_,&y);
		setcolor(BLACK);
		if(button&1==1)goto b;

	       }
		 if(x_>=584 && x_<=604 && y>=409 && y<=429 )
		 {
		settextstyle(0,0,0);
		setcolor(BLUE);
		outtextxy(542,452,"Multi");
		outtextxy(542,467,"Bar");
		delay(200);
		setcolor(WHITE);
		outtextxy(542,452,"Multi");
		outtextxy(542,467,"Bar");
		getmousepos(&button,&x_,&y);
		setcolor(BLACK);
		if(button&1==1)goto b;

	       }
		 if(x_>=584 && x_<=604 && y>=439 && y<=459 )
		 {
		settextstyle(0,0,0);
		setcolor(BLUE);
		outtextxy(542,452,"Multi");
		outtextxy(542,467,"Color");
		delay(200);
		setcolor(WHITE);
		outtextxy(542,452,"Multi");
		outtextxy(542,467,"Color");
		getmousepos(&button,&x_,&y);
		setcolor(BLACK);
		if(button&1==1)goto b;

	       }
		if(x_>=559 && x_<=579 && y>=424 && y<=444 )
		 {
		settextstyle(0,0,0);
		setcolor(BLUE);
		outtextxy(542,452,"Clear");
		outtextxy(542,467,"Screen");
		delay(200);
		setcolor(WHITE);
		outtextxy(542,452,"Clear");
		outtextxy(542,467,"Screen");
		getmousepos(&button,&x_,&y);
		setcolor(BLACK);
		if(button&1==1)goto b;
	}

	b:     if((button&1)==1)
		{
		     lo=1;
		     if(x_>=609 && x_<=629 && y>=389 && y<=409 )
		{
			jo=1;go=0; fo=0;
			hidemouseptr();
			setfillstyle(1,WHITE);
			floodfill(bax,bay,BLACK);
			setfillstyle(1,BROWN);
			floodfill(x_,y,BLACK);

			bax=x_;bay=y;
			showmouseptr();
		}
		else if(x_>=609 && x_<=629 && y>=419 && y<=439 )
		{
			jo=2;go=0;fo=0;
			hidemouseptr();
			setfillstyle(1,WHITE);
			floodfill(bax,bay,BLACK);
			setfillstyle(1,BROWN);
			floodfill(x_,y,BLACK);
			bax=x_;bay=y;
			showmouseptr();
		}
		else   if(x_>=609 && x_<=629 && y>=449 && y<=469 )
		{
			jo=3;go=0;fo=0;
			hidemouseptr();
			setfillstyle(1,WHITE);
			floodfill(bax,bay,BLACK);
			setfillstyle(1,BROWN);
			floodfill(x_,y,BLACK);
			bax=x_;bay=y;
			showmouseptr();
		}
		else  if(x_>=584 && x_<=604 && y>=409 && y<=429 )
		{
			jo=4;go=0;fo=0;
			hidemouseptr();
			setfillstyle(1,WHITE);
			floodfill(bax,bay,BLACK);
			setfillstyle(1,BROWN);
			floodfill(x_,y,BLACK);
			bax=x_;bay=y;
			showmouseptr();
		}
		else  if(x_>=584 && x_<=604 && y>=439 && y<=459 )
		{
			jo=5;go=0;fo=0;
			hidemouseptr();
			setfillstyle(1,WHITE);
			floodfill(bax,bay,BLACK);
			setfillstyle(1,BROWN);
			floodfill(x_,y,BLACK);
			bax=x_;bay=y;
			showmouseptr();
		}
		 else if(x_>=559 && x_<=579 && y>=424 && y<=444 )
		{
			jo=6;go=0;fo=0;
			hidemouseptr();
			setfillstyle(1,WHITE);
			floodfill(bax,bay,BLACK);
			setfillstyle(1,BROWN);
			floodfill(x_,y,BLACK);
			bax=x_;bay=y;
			showmouseptr();
		}

	     }

}

void sidebar()
{

   while((x_>=540)&&((pow((x_-750),2))+(pow((y-185),2))-(pow(210,2))<=0)&&flag==0)
   {


	     hidemouseptr();
	    setcolor(WHITE);
	    setfillstyle(1,WHITE);
	    pieslice(750,185,90,270,210);
	    setcolor(BLACK);
	    for(int i=160;i>=-40;i-=40)
	    rectangle(maxx-40,maxy/2-i,maxx-20,maxy/2-i+20);
	    for(i=120;i>0;i-=40)
	    rectangle(maxx-70,maxy/2-i-20,maxx-50,maxy/2-i);
	    rectangle(maxx-70,maxy/2-20,maxx-50,maxy/2+0);
	    rectangle(maxx-70,maxy/2+20,maxx-50,maxy/2+40);
	    prevx=x_;prevy=y;
	    getmousepos(&button,&x_,&y);
	    flag=1;
	     if(fo==1)
	    {
		    hidemouseptr();
		    setfillstyle(1,BROWN);
		    floodfill(bax,bay,BLACK);
		    showmouseptr();
	    }
	    showmouseptr();
	   }
	   prevx=x_;prevy=y;
	   getmousepos(&button,&x_,&y);

	   if(x_>=599 && x_<=619 && y>=79 && y<=99)
	   {
		settextstyle(0,1,0);
		setcolor(BLUE);
		outtextxy(630,280,"Line");
		delay(200);
		setcolor(WHITE);
		outtextxy(630,280,"Line");
		 settextstyle(0,1,0);
		getmousepos(&button,&x_,&y);
		setcolor(BLACK);
		if(button&1==1)goto a;
	   }
	   if(x_>=599 && x_<=619 && y>=119 && y<=139 )
	   {
		settextstyle(0,1,0);
		setcolor(BLUE);
		outtextxy(630,280,"Pencil");
		delay(200);
		setcolor(WHITE);
		outtextxy(630,280,"Pencil");
		 settextstyle(0,1,0);
		getmousepos(&button,&x_,&y);
		if(button&1==1)goto a;
	    }
	    if(x_>=599 && x_<=619 && y>=159 && y<=179 )
	    {
		settextstyle(0,1,0);
		setcolor(BLUE);
		outtextxy(630,280,"Rectangle");
		delay(200);
		setcolor(WHITE);
		outtextxy(630,280,"Rectangle");
		 settextstyle(0,1,0);
		getmousepos(&button,&x_,&y);
		setcolor(BLACK);
		if(button&1==1)goto a;
	    }

	    if(x_>=599 && x_<=619 && y>=199 && y<=219 )
	    {
	    settextstyle(0,1,0);
		setcolor(BLUE);
		outtextxy(630,280,"Circle");
		delay(200);
		setcolor(WHITE);
		outtextxy(630,280,"Circle");
		 settextstyle(0,1,0);
		getmousepos(&button,&x_,&y);
				setcolor(BLACK);
		if(button&1==1)goto a;
	    }
	    if(x_>=599 && x_<=619 && y>=239 && y<=259 )
	    {

		settextstyle(0,1,0);
		setcolor(BLUE);
		outtextxy(630,280,"Ellipse");
		delay(200);
		setcolor(WHITE);
		outtextxy(630,280,"Ellipse");
		 settextstyle(0,1,0);
		getmousepos(&button,&x_,&y);
				setcolor(BLACK);
		if(button&1==1)goto a;
	    }

	    if(x_>=599 && x_<=619 && y>=279 && y<=299 )
		    {

		settextstyle(0,1,0);
		setcolor(BLUE);
		outtextxy(630,280,"Eraser");
		delay(200);
		setcolor(WHITE);
		outtextxy(630,280,"Eraser");
		 settextstyle(0,1,0);
		getmousepos(&button,&x_,&y);
				setcolor(BLACK);
		if(button&1==1)goto a;
	    }
	    if(x_>=569 && x_<=589 && y>=99 && y<=119 )
	    {

		settextstyle(0,1,0);
		setcolor(BLUE);
		outtextxy(630,280,"Brush");
		delay(200);
		setcolor(WHITE);
		outtextxy(630,280,"Brush");
		 settextstyle(0,1,0);
		getmousepos(&button,&x_,&y);
				setcolor(BLACK);
		if(button&1==1)goto a;
	    }

	    if(x_>=569 && x_<=589 && y>=139 && y<=159 )
	     {

		settextstyle(0,1,0);
		setcolor(BLUE);
		outtextxy(630,280,"Fill");
		delay(200);
		setcolor(WHITE);
		outtextxy(630,280,"Fill");
		 settextstyle(0,1,0);
		getmousepos(&button,&x_,&y);
				setcolor(BLACK);
		if(button&1==1)goto a;
	    }
		if(x_>=569 && x_<=589 && y>=179 && y<=199 )
	     {

		settextstyle(0,1,0);
		setcolor(BLUE);
		outtextxy(630,280,"Cut");
		delay(200);
		setcolor(WHITE);
		outtextxy(630,280,"Cut");
		 settextstyle(0,1,0);
		getmousepos(&button,&x_,&y);
				setcolor(BLACK);
		if(button&1==1)goto a;
	    }

	     if(x_>=569 && x_<=589 && y>=219 && y<=239 )
	    {

		settextstyle(0,1,0);
		setcolor(BLUE);
		outtextxy(630,280,"Copy");
		delay(200);
		setcolor(WHITE);
		outtextxy(630,280,"Copy");
		 settextstyle(0,1,0);
		getmousepos(&button,&x_,&y);
				setcolor(BLACK);
		if(button&1==1)goto a;
	    }
	      if(x_>=569 && x_<=589 && y>=259 && y<=279 )
	    {

		settextstyle(0,1,0);
		setcolor(BLUE);
		outtextxy(630,280,"Paste");
		delay(200);
		setcolor(WHITE);
		outtextxy(630,280,"Paste");
		 settextstyle(0,1,0);
		getmousepos(&button,&x_,&y);
				setcolor(BLACK);
		if(button&1==1)goto a;
	    }
  a:	if((button&1)==1)
	   {
		fo=1;
	      if(x_>=599 && x_<=619 && y>=79 && y<=99 )
		{
			go=1;
			hidemouseptr();
			setfillstyle(1,WHITE);
			floodfill(bax,bay,BLACK);
			setfillstyle(1,BROWN);
			floodfill(x_,y,BLACK);

			bax=x_;bay=y;
			showmouseptr();
		}
		 else if(x_>=599 && x_<=619 && y>=119 && y<=139 )
		{
			go=2;
			hidemouseptr();
			setfillstyle(1,WHITE);
			floodfill(bax,bay,BLACK);
			setfillstyle(1,BROWN);
			floodfill(x_,y,BLACK);
			bax=x_;bay=y;
			showmouseptr();
		}
		else if(x_>=599 && x_<=619 && y>=159 && y<=179 )
		{
			go=3;
			hidemouseptr();
			setfillstyle(1,WHITE);
			floodfill(bax,bay,BLACK);
			setfillstyle(1,BROWN);
			floodfill(x_,y,BLACK);
			bax=x_;bay=y;
			showmouseptr();
		}
		else if(x_>=599 && x_<=619 && y>=199 && y<=219 )
		{
			go=4;
			hidemouseptr();
			setfillstyle(1,WHITE);
			floodfill(bax,bay,BLACK);
			setfillstyle(1,BROWN);
			floodfill(x_,y,BLACK);
			bax=x_;bay=y;
			showmouseptr();
		}
		else if(x_>=599 && x_<=619 && y>=239 && y<=259 )
		{
			go=5;
			hidemouseptr();
			setfillstyle(1,WHITE);
			floodfill(bax,bay,BLACK);
			setfillstyle(1,BROWN);
			floodfill(x_,y,BLACK);
			bax=x_;bay=y;
			showmouseptr();
		}
		else if(x_>=599 && x_<=619 && y>=279 && y<=299 )
		{
			go=6;
			hidemouseptr();
			setfillstyle(1,WHITE);
			floodfill(bax,bay,BLACK);
			setfillstyle(1,BROWN);
			floodfill(x_,y,BLACK);
			bax=x_;bay=y;
			showmouseptr();
		}

		else if(x_>=569 && x_<=589 && y>=99 && y<=119 )
		{
			go=7;
			hidemouseptr();
			setfillstyle(1,WHITE);
			floodfill(bax,bay,BLACK);
			setfillstyle(1,BROWN);
			floodfill(x_,y,BLACK);
			bax=x_;bay=y;
			showmouseptr();
		}
		else if(x_>=569 && x_<=589 && y>=139 && y<=159 )
		{
			go=8;
			hidemouseptr();
			setfillstyle(1,WHITE);
			floodfill(bax,bay,BLACK);
			setfillstyle(1,BROWN);
			floodfill(x_,y,BLACK);
			bax=x_;bay=y;
			showmouseptr();
		}
		else if(x_>=569 && x_<=589 && y>=179 && y<=199 )
		{
			go=9;
			hidemouseptr();
			setfillstyle(1,WHITE);
			floodfill(bax,bay,BLACK);
			setfillstyle(1,BROWN);
			floodfill(x_,y,BLACK);
			bax=x_;bay=y;
			showmouseptr();
		}

		else if(x_>=569 && x_<=589 && y>=219 && y<=239 )
		{
			go=10;
			hidemouseptr();
			setfillstyle(1,WHITE);
			floodfill(bax,bay,BLACK);
			setfillstyle(1,BROWN);
			floodfill(x_,y,BLACK);
			bax=x_;bay=y;
			showmouseptr();
		}
			else if(x_>=569 && x_<=589 && y>=259 && y<=279 )
		{
			go=11;
			hidemouseptr();
			setfillstyle(1,WHITE);
			floodfill(bax,bay,BLACK);
			setfillstyle(1,BROWN);
			floodfill(x_,y,BLACK);
			bax=x_;bay=y;
			showmouseptr();
		}

	    }
}

int p,qq;
void cut(int x1,int y1,int x2,int y2,int &p, int &qq,char st[35])
{
	ofstream f;
	p=x2-x1;qq=y2-y1;
	outtextxy(1,1,"Please wait..");
	f.open(st,ios::out);
	for(;x1<=x2;x1++)
	{
		for(int t = y1;t<=y2;t++)
		{
			f<<getpixel(x1,t)<<' ';
		}
	}
	f.close();
	setcolor(BLACK);
	outtextxy(1,1,"Please wait..");
	setfillstyle(1,BLACK);
	bar(1,1,7,1);
	setfillstyle(1,n);
}



void paste(int x1,int y1,int &p,int &qq,char st[35])
{
	ifstream f;
	int k=99,t;
	f.open(st,ios::in);
	p--;
	   hidemouseptr();
	   if(f)
	   {
	for(;x1<=x1+p&&!f.eof();x1++)
	{
		for( t = y1;t<=y1+qq;t++)
		{
			f>>k;
		       //	cout<<k<<'\n';
			putpixel(x1,t,k);
		}
	}
	}
	else
	{
		setcolor(YELLOW);
		settextstyle(3,0,3);
		outtextxy(1,1,"File Not Found");
		setcolor(BLACK);
		getch();
		outtextxy(1,1,"File Not Found");
	}

		setcolor(BLACK);
	rectangle(p,qq,x1-1,t-1);
	line(x1,qq,x1,t-1);
	line(x1-2,qq,x1-2,t-1);
	setcolor(n);
	showmouseptr();
}
void lowbar()
{

       while(x_>=110 && x_<=530 && y>=460 && y<=480 && flag==0)
       {

		settextstyle(0,0,0);
		setcolor(BLACK);
		hidemouseptr();
		setfillstyle(1,WHITE);
		setcolor(BLACK);
		bar(110,460,530,480);
		rectangle(115,465,205,475);
		rectangle(220,465,310,475);
		rectangle(330,465,420,475);
		rectangle(435,465,525,475);

		     outtextxy(145,467,"OPEN") ;
		     outtextxy(250,467,"SAVE") ;
		     outtextxy(350,467,"SAVE AS") ;
		     outtextxy(460,467,"HELP") ;
		flag=1;

		 showmouseptr();

	}
	getmousepos(&button,&x_,&y);
	if(button&1==1)
	{
	 if(x_>=115 && x_<=205 && y>=465 && y<=475) open() ;
	    else if(x_>=220 && x_<=310 && y>=465 && y<=475)save();
	       else if(x_>=330 && x_<=420 && y>=465 && y<=475)saveas();
		  else if(x_>=435 && x_<=525 && y>=465 && y<=475)help();

	       }




}





void blank()
{
    int dum1,dum2;

					setcolor(BLACK);
					setfillstyle(1,BLACK);

				       pieslice(maxx,maxy,90,180,108);
				       pieslice(1,maxy,90,0,108);
				       pieslice(750,185,90,270,210);
					bar(110,460,530,480);
				       flag=0;

			     if(go==1)
			     {
					 int h,k;
					 getmousepos(&button,&x_,&y);
					 if((button&1)==1)
					 {
						prevx=x_;
						prevy=y;
						h=x_;k=y;
						while((button&1)==1)
						{
							setcolor(n);
							prevx=x_;
							prevy=y;
							getmousepos(&button,&x_,&y);
						}
						hidemouseptr();
						line(h,k,x_,y);
						showmouseptr();      //Draw Line
					  }
			     }
			     else if(go==2)
			     {
					getmousepos(&button,&x_,&y);
					prevx=x_;prevy=y;
					while((button&1)==1)
					{
						hidemouseptr();
						setcolor(n);
						setfillstyle(1,n);
						line(prevx,prevy,x_,y);
						prevx=x_;
						prevy=y;
						getmousepos(&button,&x_,&y);
						showmouseptr();
					}
			     }
	   else	if(go==3)
	   {
		 int h,k;
		getmousepos(&button,&x_,&y);
		if((button&1)==1)
		{
		    prevx=x_;
		    prevy=y;
		    h=x_;k=y;
		    while((button&1)==1)
		    {
			setcolor(n);
			prevx=x_;
			prevy=y;
			getmousepos(&button,&x_,&y);

		    }
			hidemouseptr();
			rectangle(h,k,x_,y);
			showmouseptr();      //Draw Rectangle
		 }
	   }
		 else if(go==4)
		 {
		 int h,k,r;
		 getmousepos(&button,&x_,&y);
		 if((button&1)==1)
		{
			prevx=x_;
			prevy=y;
			h=x_;k=y;
			while((button&1)==1)
			{
				setcolor(n);
				prevx=x_;
				prevy=y;
				getmousepos(&button,&x_,&y);
			 }
			hidemouseptr();
		      if(x_!=h&&y!=k)
		      {
				int u,v;
				u=(h>x_)?h-x_:x_-h;
				v=(k>y)?k-y:y-k;
				 r=sqrt(pow(u,2)+pow(v,2));
				circle((h+x_)/2,(k+y)/2,r/2);    //To draw circle
		      }
			  showmouseptr();           //Draw Circle
		 }

		}

		 else if(go==5)
		 {
			getmousepos(&button,&x_,&y);
			if((button&1)==1)
			{
				prevx=x_;prevy=y;
				while((button&1)==1)
				{
					hidemouseptr();
					setcolor(n);
					getmousepos(&button,&x_,&y);
					showmouseptr();
				}
				hidemouseptr();
				ellipse(prevx,prevy,0,360,abs((x_-prevx)/2),abs((y-prevy)/2));
				showmouseptr();
			}
	       }

		 else if(go==6)
		 {
			      getmousepos(&button,&x_,&y);
				prevx=x_;prevy=y;
				while((button&1)==1)
				{
					hidemouseptr();
					setcolor(BLACK);
					setfillstyle(1,BLACK);
					bar(prevx-10,prevy-10,x_+10,y+10);
					prevx=x_;
					prevy=y;
					getmousepos(&button,&x_,&y);
					showmouseptr();
				}
			 }
		 else if(go==7)
		 {
				getmousepos(&button,&x_,&y);
				prevx=x_;prevy=y;
				while((button&1)==1)
				{
					hidemouseptr();
					setcolor(n);
					setfillstyle(1,n);
				    //	fillellipse(prevx+x_/2,prevy+y/2,,5);
					line(prevx,prevy,x_,y);
					line(prevx+1,prevy+1,x_+1,y+1);
					line(prevx+2,prevy+2,x_+2,y+2);
					line(prevx+3,prevy+3,x_+3,y+3);
					prevx=x_;
					prevy=y;
					getmousepos(&button,&x_,&y);
					showmouseptr();
				}
		}
		else if(go==8)
		{
			getmousepos(&button,&x_,&y);
		if (button&1==1)
		{
			getmousepos(&button,&x_,&y);
			hidemouseptr();
		int	prevcolor=getpixel(x_,y);
			setfillstyle(1,n);
			flood_fill(x_,y,n,prevcolor);
			showmouseptr();
		}
       }
       else if(go==9)
       {
       int h,k;
		getmousepos(&button,&x_,&y);
		if((button&1)==1)
		{
		    prevx=x_;
		    prevy=y;
		    h=x_;k=y;
		    while((button&1)==1)
		    {
			setcolor(n);
			prevx=x_;
			prevy=y;
			getmousepos(&button,&x_,&y);

		    }
			hidemouseptr();
			rectangle(h,k,x_,y);
			cut(h,k,x_,y,p1,q1,"KAR.TXT");
			 dum1=h;dum2=k;
                        setfillstyle(1,BLACK);
                        setcolor(BLACK);
			bar(h,k,x_,y);
			showmouseptr();      //Draw Rectangle
		 }
	}
       else if(go==10)
       {
       int h,k;
		getmousepos(&button,&x_,&y);
		if((button&1)==1)
		{
		    prevx=x_;
		    prevy=y;
		    h=x_;k=y;
		    while((button&1)==1)
		    {
			setcolor(n);
			prevx=x_;
			prevy=y;
			getmousepos(&button,&x_,&y);

		    }
			hidemouseptr();
			rectangle(h,k,x_,y);
			cut(h,k,x_,y,p1,q1,"KAR.TXT");
                         dum1=h;dum2=k;
			showmouseptr();      //Draw Rectangle
		 }
	}

	else if(go==11)
        {
	    getmousepos(&button,&x_,&y);
           if((button&1)==1)
	      paste(x_,y,p1,q1,"KAR.TXT");
	}




			     else	     if(jo==1)
			     {
					getmousepos(&button,&x_,&y);
					prevx=x_;prevy=y;
					while((button&1)==1)
					{
						hidemouseptr();
						setcolor(n);
						setfillstyle(1,n);
						line(prevx,-prevy,x_,y);
						prevx=x_;
						prevy=y;
						getmousepos(&button,&x_,&y);
						showmouseptr();
					}
			     }
			     else if(jo==2)
			     {
					getmousepos(&button,&x_,&y);
					prevx=x_;prevy=y;
					while((button&1)==1)
					{
						hidemouseptr();
						setcolor(n);
						setfillstyle(1,n);
						ellipse(prevx/2,prevy/2,-10,350,x_/2,y/2);
						prevx=x_;
						prevy=y;
						getmousepos(&button,&x_,&y);
						showmouseptr();
					}
			     }
			     else if(jo==3)
			     {
					getmousepos(&button,&x_,&y);
					prevx=x_;prevy=y;
					while((button&1)==1)
					{
						hidemouseptr();
						setcolor(n);
						setfillstyle(1,n);
						line(-prevx,-prevy,x_,y);
						prevx=x_;
						prevy=y;
						getmousepos(&button,&x_,&y);
						showmouseptr();
					}
			     }
			     else if(jo==4)
			     {
					getmousepos(&button,&x_,&y);
					prevx=x_;prevy=y;
					while((button&1)==1)
					{
						hidemouseptr();
						setcolor(n);
						setfillstyle(1,n);
						bar3d(prevx,prevy,x_,y,20,1);
						prevx=x_;
						prevy=y;
						getmousepos(&button,&x_,&y);
                                                n++;
						showmouseptr();
					}
			     }
			     else if(jo==5)
			     {
					getmousepos(&button,&x_,&y);
					prevx=x_;prevy=y;
					while((button&1)==1)
					{
						hidemouseptr();
						setcolor(n);
						setfillstyle(1,n);
						line(prevx,prevy,x_,y);
						prevx=x_;
						prevy=y;
						getmousepos(&button,&x_,&y);
						n++;
						showmouseptr();
					}
			     }
			     else if(jo==6)
			     {
				  cleardevice();
				  setcolor(WHITE);
				  settextstyle(0,0,0);
				  outtextxy(250,3,"THE SHARK DRAW");

				  if(yo==0)
				  {
					rectangle(0,0,maxx,maxy);
					setviewport(1,1,maxx-1,maxy-1,1);
					yo=1;
				  }
			     }


       }

void paintmain()
{

		initgraph(&gd,&gm,"d:\\tc1\\bgi");
		maxx=getmaxx();
		maxy=getmaxy();
		rectangle(0,0,maxx,maxy);
		settextstyle(0,0,0);
		outtextxy(250,3,"THE SHARK DRAW");
		setviewport(1,1,maxx-1,maxy-1,1);
		if(initmouse()==0)
		{
			closegraph();
			exit(1);
		}
		restrictmouseptr(1,1,maxx-1,maxy-1);
		showmouseptr();
		while(kbhit())
		{
			getch();

		}
		while(!kbhit())
		{
			getmousepos(&button,&x_,&y);
			if((button&1)==0)
			{
				if((x_<=100)&&(y<=sqrt(108*108-(x_-1)*(x_-1))+479)&&(y>=370))
				{
				     colorselection();
				}
				else if((x_>=maxx-100)&&(y<=sqrt(108*108-(x_-639)*(x_-639))+479)&&(y>=370))
				{

				     specialeffects();
				}
				else if((x_>=540)&&(pow((x_-750),2))+(pow((y-185),2))-(pow(210,2))<=0)
				{
				     sidebar();
				}
				else if(x_>=110 && x_<=530 && y>=460 && y<=480)
				{
				   lowbar();
				}
				else
				{
				     blank();
				}
		       }
	      }
		closegraph();
}

