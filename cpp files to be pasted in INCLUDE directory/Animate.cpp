/*Animation*/
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
void main(void)
{
   clrscr();
   int gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
   int x=0,y=0,r=0,b=0,color=0,midx,midy,maxx,maxy;
   midx=getmaxx()/2;
   midy=getmaxy()/2;
   maxx=getmaxx();
   maxy=getmaxy();
    rectangle(0,0,maxx,maxy);
   do
   {

      delay(10);
      setcolor(color);
      setbkcolor(0);
      arc(midx,midy,999,r,40);
      arc(midx,midy,999,r,42);
      arc(midx,midy,999,r,44);
      arc(midx,midy,999,r,46);
      arc(midx,midy,999,r,48);
      arc(midx,midy,999,r,50);
      arc(midx,midy,999,r,52);
      arc(midx,midy,999,r,54);
      arc(midx,midy,999,r,56);
      arc(midx,midy,500,r,70);
      arc(midx,midy,500,r,72);
      arc(midx,midy,500,r,74);
      arc(midx,midy,500,r,76);
      arc(midx,midy,500,r,78);
      arc(midx,midy,500,r,80);
      moveto(midx-20,midy);
      outtext("WE thank");
      x++;
      y++;
      r++;
      color++;
   }
   while( !kbhit() );
   getch();
   closegraph();
}