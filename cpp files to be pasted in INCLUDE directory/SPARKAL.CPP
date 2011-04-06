
#include<iostream.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
void clear()
{
	int col;
	cleardevice();
	col=rand()%16;
	setfillstyle(1,BLACK);
	floodfill(10,10,col);

}
void eff1(int *three,int *two)
{
		int line=0;
		int col;
		while(line!=+2)
		{
		for(col=640;col>=1;col--)
		{
			if(col==1)
				putpixel(col,line,WHITE);
			if(col%5)
				putpixel(rand()%640,line+rand()%50,WHITE);
			if(col%3)
				putpixel(col,line+rand()%100,*three);
			if(col%2)
				putpixel(col,line+rand()%200,*two);
			if(col%10)
				putpixel(col,line+rand()%10,BLACK);
		}
		line++;
		if(line>=-2)
		{
			*three=rand()%16;
			*two=rand()%16;
			clear();
		}
		}
}
void eff2(int *three,int *two)
{
		int line=0;
		int col;
		while(line!=482)
		{
		for(col=1;col<=640;col++)
		{
			if(col==1)
				putpixel(col,line,WHITE);
			if(col%5)
				putpixel(rand()%640,line+rand()%50,WHITE);
			if(col%3)
				putpixel(col,line-rand()%100,*three);
			if(col%2)
				putpixel(col,line-rand()%200,*two);
			if(col%10)
				putpixel(col,line-rand()%10,BLACK);
		}
		line++;
		if(line>=482)
		{
			*three=rand()%16;
			*two=rand()%16;
			clear();
		}
		}
}
void eff3(int *three,int *two)
{
		int line;
		int col=0;
		while(col!=642)
		{
		for(line=1;line<=480;line++)
		{
			if(line==1)
				putpixel(col,line,WHITE);
			if(line%5)
				putpixel(col+rand()%50,rand()%480,WHITE);
			if(line%3)
				putpixel(col-rand()%100,line,*three);
			if(line%2)
				putpixel(col-rand()%200,line,*two);
			if(line%10)
				putpixel(col-rand()%10,line,BLACK);
		}
		col++;
		if(col>=642)
		{
			*three=rand()%16;
			*two=rand()%16;
			clear();
		}
		}
}
void eff4(int *three,int *two)
{
		int line;
		int col=640;
		while(col!=-2)
		{
		for(line=1;line<=480;line++)
		{
			if(line==1)
				putpixel(col,line,WHITE);
			if(line%5)
				putpixel(col+rand()%50,rand()%480,WHITE);
			if(line%3)
				putpixel(col+rand()%100,line,*three);
			if(line%2)
				putpixel(col+rand()%200,line,*two);
			if(line%10)
				putpixel(col+rand()%10,line,BLACK);
		}
		col--;
		if(col==-2)
		{
			*three=rand()%16;
			*two=rand()%16;
			clear();
		}
		}
}

void screenmain()
{
	int driver=DETECT,mode;
	initgraph(&driver,&mode,"d:\\tc1\\bgi");
	int ef;
	int three,two;
	three=random(16);two=random(16);
	while(!kbhit())
	{
		ef=1;
		switch(ef)
		{
			case 1:
				eff1(&three,&two);
			case 2:
				eff2(&three,&two);
			case 3:
				eff3(&three,&two);
			case 4:
				eff4(&three,&two);
		}
		ef=ef+1;

	}
getch();
}
