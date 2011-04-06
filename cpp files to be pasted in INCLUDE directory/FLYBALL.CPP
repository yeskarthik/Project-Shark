#include<iostream.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>

const double piy=M_PI;
void loaddy()
{

	settextstyle(10,0,8);
	pieslice(50,290,0,360,10);
	pieslice(620,290,0,360,10);
	pieslice(50,110,0,360,10);
	pieslice(620,110,0,360,10);
	for(int i=0;i<100;i++)
	{
		setcolor(i);
		outtextxy(60,100,"FLYBALL");
		setfillstyle(1+random(12),1+random(15));
		floodfill(100,200,i);
		setfillstyle(1+random(12),1+random(15));
		floodfill(140,200,i);
		setfillstyle(1+random(12),1+random(15));
		floodfill(240,200,i);
		setfillstyle(1+random(12),1+random(15));
		floodfill(300,200,i);
		setfillstyle(1+random(12),1+random(15));
		floodfill(390,200,i);
		setfillstyle(1+random(12),1+random(15));
		floodfill(470,200,i);
		setfillstyle(1+random(12),1+random(15));
		floodfill(540,200,i);
		delay(100);
	}
	nosound();
	getch();
     //	exit(0);
     }
     void passage()
     {
	setcolor(WHITE);
	cleardevice();
	settextstyle(3,0,2);
	outtextxy(90,80,"FLYBALL");
	 outtextxy(90,120,"This is a game called Flyball.");
	 outtextxy(90,140,"It is a strategy game, that allows");
	 outtextxy(90,160,"you to move a ball only left and right.");
	 outtextxy(90,180,"While moving the ball the you will have");
	 outtextxy(90,200,"obstacles of blocks. The blocks will move");
	 outtextxy(90,220,"up while the ball falls down. If the block");
	 outtextxy(90,240,"hit the bottom on the circle then the ball");
	 outtextxy(90,260,"will scrool up with it. If the balls top ");
	 outtextxy(90,280,"hits the top of the screen then you will lose");
	 outtextxy(90,320,"Thanking You");
	 outtextxy(90,350,"The Shark Associates");
	 getch();
}
int DisplayScore();
void Splash_Screen();
void graphicsinit();
typedef struct
{
	int X;
	int Y;
	int Right;
	int Bottom;
	int Speed;
}BLOCK;
typedef struct
{
	int X;
	int Y;
	int Radius;
	int Speed;
	int LastX;
	int LastY;
}CIRCLE;

const char keyup = 72;
const char keyleft = 75;
const char keyright = 77;
const char keydown = 80;
void Check_Game_Over();
double Score = 0;
int Splash = 0;

void flymain()
{
	graphicsinit();
	cleardevice();
	int Counter = 0;
	int Temp1 = 0,Temp2 = 0,Temp3 = 0,Temp4 = 0;
		Score = 0;
		graphicsinit();
		int XCor = getmaxx()/2;
		int YCor = 300;
		int Rad = 10;
		int BWidth = 50;
		int BHeight = 30;
		int Level;
		palettetype Pal;
		getpalette(&Pal);
		CIRCLE Circle;
		BLOCK Block[25];


		if (Splash == 0)
		{
			passage();
			cleardevice();
			Splash_Screen();
			cleardevice();
			loaddy();
			cleardevice();
		}

		do {

			cout<<"\n\n\n\n\n";
			cout<<"\t\t\tEnter your level of difficlty."<<endl;
			cout<<"\n\t\t1). Easy   (Im not that good. :])"<<endl;
			cout<<"\n\t\t2). Medium (Cant stand things to easy) "<<endl;
			cout<<"\n\t\t3). Hard   (True skills come from within!!!)"<<endl;
			cout<<"\n\t\t4). Quit   (Cant take the pressure can we...)"<<endl<<"\t\t";
			cin>>Level;

		}while(Level < 0 && Level > 4);
		if( Level == 4)
		   {
		    exit(1);
		   }
		setwritemode(1);
		cleardevice();

		setwritemode(1);
		for(int Angle = 0; Angle < 360; Angle ++)
		{
			Temp1 = cos(Angle * piy/180) *180.1;
			Temp2 = sin(Angle * piy/180) *180.1;
			Temp3 = -Temp1;
			Temp4 = -Temp2;
			setcolor(4);
			circle(Temp1+320,Temp2+240,Angle/6);
			circle(Temp3+320,Temp4+240,Angle/6);
			setlinestyle(1,3,4);
			line(Temp3+320,Temp4+230,Temp1+320,Temp2+240);
			delay(5);
		}

		setcolor(BLUE);
		settextstyle(0,0,5);
		outtextxy(getmaxx()/2-18,getmaxy()/2-18,"3");
		delay(1000);
		setcolor(RED);
		outtextxy(getmaxx()/2-18,getmaxy()/2-18,"3");
		delay(1000);
		setcolor(BLUE);
		outtextxy(getmaxx()/2-18,getmaxy()/2-18,"2");
		delay(1000);
		setcolor(RED);
		outtextxy(getmaxx()/2-18,getmaxy()/2-18,"2");
		delay(1000);
		setcolor(BLUE);
		outtextxy(getmaxx()/2-18,getmaxy()/2-18,"1");
		delay(500);
		for (int Grow = 63; Grow > 0; Grow--)
		{
			Counter+=13;
			setrgbpalette(Pal.colors[4],Grow,0,0);
			setfillstyle(1,4);
			setcolor(4);
			fillellipse(getmaxx()/2,getmaxy()/2,Counter,Counter);
			delay(1);
		}
		setbkcolor(BLACK);

		Circle.X = XCor;
		Circle.Y = YCor;
		Circle.Radius = Rad;
		Circle.Speed = 2;
		graphicsinit();

		for(int I = 0; I < 25; I++)
		   {
			Block[I].X = random(620);
			Block[I].Y = random(460);
			if (Level == 1)
			{
			  BWidth = 50;
			  BHeight = 30;
			  Block[I].Right = Block[I].X + BWidth;
			  Block[I].Bottom = Block[I].Y + BHeight;
			  Block[I].Speed = 1+random(5);
			}
			else if (Level == 2)
			{
			  BWidth = 60;
			  BHeight = 30;
			  Block[I].Right = Block[I].X + BWidth;
			  Block[I].Bottom = Block[I].Y + BHeight;
			  Block[I].Speed = random(5)+1;
			}
			else if (Level == 3)
			{
			  BWidth = 70;
			  BHeight = 30;
			  Block[I].Right = Block[I].X + BWidth;
			  Block[I].Bottom = Block[I].Y + BHeight;
			  Block[I].Speed = random(6)+1;
			}




    }//end loop
	  char Key = 0;

	  while(Key != 27 || Level ==4)

	  {
	      Circle.LastX=Circle.X;
	      Circle.LastY=Circle.Y-36;
	      if( kbhit() )
	       {
		Key = getch();
		if (Key == keyleft)
		{
		 if(Circle.X + Circle.Radius  > 2)
		 {
			    Circle.LastY=Circle.Y-37;
			    Circle.LastX=Circle.X;
			    Circle.X-=18;
		  }
	}
	if (Key == keyright)
	{
	   if(Circle.X + Circle.Radius < getmaxx())
	    {
		    Circle.LastY=Circle.Y-37;
		    Circle.LastX=Circle.X;
		    Circle.X+=18;
	    }
    }
     }


	      for(I = 0; I <25; I++)
	 {
		Block[I].Y-=Block[I].Speed;
		Block[I].Bottom-=Block[I].Speed;
		if(Block[I].Bottom < 0)
		 {
			Block[I].X = random(620);
			Block[I].Y = 600-BHeight;

			Block[I].Right = Block[I].X + BWidth;
			Block[I].Bottom = Block[I].Y + BHeight;
			Block[I].Speed = random(4)+1;
			if(Level ==2)
			Block[I].Speed = random(4)+3;
			if(Level ==3)
			Block[I].Speed = random(5)+4;
		}
			if (Circle.Y - Circle.Radius < 0)
		    {
				Circle.Speed = 0;
				Block[I].Speed = 0;
				DisplayScore();
		    }
		    if (Circle.Y + Circle.Radius >= getmaxy())
		    {
			    Circle. Y = getmaxy() ;
			    Block[I].Speed = 5;
		    }
		    if (Circle.X + Circle.Radius <= 7)
		    Circle.X = 10;
		    if (Circle.X + Circle.Radius >= getmaxx() - 7)
		    Circle.X = getmaxx() - 10;
		if (((Circle.X >= Block[I].X) && (Circle.X <= Block[I].Right) ||
		   (Circle.X+Circle.Radius >= Block[I].X) && (Circle.X + Circle.Radius <= Block[I].Right)) &&
		     ((Circle.Y >= Block[I].Y) && (Circle.Y <= Block[I].Bottom) ||
		     (Circle.Y + Circle.Radius >= Block[I].Y) && (Circle.Y + Circle.Radius <=Block[I].Bottom)))
		     {
				Circle.Speed = 0;
				Circle.Y = Block[I].Y+5;
				Circle.Speed -=Block[I].Speed;
		       }
		       else
			       Circle.Speed = 2;

		setfillstyle(1,I);
		setcolor(2);
		bar(Block[I].X,Block[I].Y,Block[I].Right,Block[I].Bottom);
		setcolor(BLACK);
		setfillstyle(1,BLACK);
		bar(Block[I].X,Block[I].Bottom,Block[I].Right,Block[I].Bottom+Block[I].Speed); /*The paramenters are used by the fields*/
		}
		setcolor(BLACK);
		setfillstyle(1,BLACK);
		fillellipse(Circle.LastX,Circle.LastY+18,Rad+2,Rad+2);
		setcolor(BLUE);
		setfillstyle(1,BLUE);
		fillellipse(Circle.X,Circle.Y-18,Rad,Rad);
		Circle.Y+=Circle.Speed;
		delay(5);
		Splash = 1;
		Score+=1;
	 }

}

void Check_Game_Over()
{
	   palettetype Pal;
	   getpalette(&Pal);
	   int Counter=0;
	   for (int Grow = 63; Grow > 0; Grow--)
	{
		Counter+=13;
		setrgbpalette(Pal.colors[4],Grow,0,0);
		setfillstyle(1,4);
		setcolor(4);
		fillellipse(getmaxx()/2,getmaxy()/2,Counter,Counter);
		delay(1);
	}
	setbkcolor(BLACK);
	}




void graphicsinit()
{
		int gd = 9, gm=2;
		initgraph(&gd, &gm, "d:\\TC1\\BGI");
}

void Splash_Screen()
{
	palettetype Pal;
	getpalette(&Pal);
	settextstyle(0,0,3);

	for(int FadeLoop = 0; FadeLoop < 63; FadeLoop++)
	{
		setrgbpalette(Pal.colors[12],FadeLoop,FadeLoop,FadeLoop);
		setbkcolor(LIGHTMAGENTA);
		delay(50);
	}
	for(FadeLoop = 63; FadeLoop > 0; FadeLoop--)
	{


		setrgbpalette(Pal.colors[13],FadeLoop,FadeLoop,63);
		setcolor(13);
		outtextxy(20,210,"   The Shark Associates");
		outtextxy(155,260,"   PRESENTS");
		delay(50);
	}

	for(FadeLoop = 0; FadeLoop < 63; FadeLoop++)
	{
		setrgbpalette(Pal.colors[13],FadeLoop,FadeLoop,63);
		setcolor(RED);
		outtextxy(20,210,"   The Shark Associates");
		outtextxy(155,260,"   PRESENTS");
		delay(50);
	}

	cleardevice();
	for(FadeLoop = 63; FadeLoop > 0; FadeLoop--)
	{
		setrgbpalette(Pal.colors[8],FadeLoop,FadeLoop,FadeLoop);
		setbkcolor(8);
		delay(50);
		sound(FadeLoop*20);
	}
			nosound();

			delay(1000);
			cleardevice();




}

int DisplayScore()
{
		cout<<"You didnt beat your old score"<<endl;
		cout<<"Score: "<<ceil(Score/12);
		cin.get();
		cin.get();
		flymain();
		return 0;

}

