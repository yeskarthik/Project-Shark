#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void slicebar(int *array,int totno,int sum,char lable[20][15]);
void usebar(int *array,int totno,int max,char lab[15][15]);
void slicechart(int *array,int totno,int sum,char lable[20][15]);
void piemain()
{
   int i,n,value[10],max=0;
   int gd=DETECT,gm=CGAC0  ;
   int totval=0;
   char lab[20][15];
   gd=9;gm=2;
   initgraph(&gd,&gm,"d:\\tc1\\bgi");
   gotoxy(10,5);
   value[0]=0;
   cout<<"Hey..\n\t This is a Program to create pie charts and bar graph \n\twith the given data .You can give a maximum of 8 datas.\n\t";
   getch();
   cleardevice();
   cout<<"\nTitle of chart:";
   gets(lab[0]);
   cout<<" Total no. of values:";
   do
   {
	cin>>n;
   } while(n>10);
   cout<<"To get a sectorgraph,type label and corresponding value:";
   for(i=1;i<=n;i++)
   {
	cout<<'\n'<<i<<". ";
	cin>>lab[i]>>value[i];
     if(value[i]>max)
	max=value[i];
	totval+=value[i];
   }
   slicechart(value,n,totval,lab);
   usebar(value,n,max,lab);

}
void slicechart(int *array,int totno,int sum,char lable[20][15])
{
  int i=1,x,y;
  char t[10];
  float angle[11],xdir,ydir,totang=0;

  x=getmaxx();
  y=getmaxy();
  while(i<=totno)
  {
    angle[i]= (array[i]*360.0/ sum);
    totang+=angle[i];
    setfillstyle(1,i);
    pieslice(x/2,y/2, totang-angle[i],totang,150);

    xdir=cos((totang - angle[i]/2.0) *3.14/180.0);  /*to get x-y coordinates */
    ydir=sin(( totang - angle[i]/2.0) *3.14/180.0);
    itoa(angle[i]*100/360,t,10);       /* convrt to string */
    moveto(x/2+ xdir*170-7, y/2-ydir*170);
    outtext( t);
    outtext("%");

    bar(10,300+20*i,20,300+20*i+10);
    outtextxy(35,300+20*i,lable[i]);
    itoa(array[i],t,10);
    outtextxy(120,300+20*i,t);
    i++;
  }
  setcolor(YELLOW);
  rectangle(5,315,150,290+20*i);


  settextstyle(1,0,5);
  outtextxy(x/2,5,lable[0]);
  getch();
}
void usebar(int *array,int totno,int max,char lab[15][15])
{
   int i;
   float length;
   char t[5];

   cleardevice();
   line(50,40,50,450);
   line(50,450,600,450);
   for(i=1;i<=totno;i++)
   {
     setcolor(YELLOW);
     setfillstyle(i,i);
     length=array[i]*400/max;
     bar3d(i*70,450-length,50+i*70,450,10,10);
     itoa(array[i],t,10);
     settextstyle(2,0,8);
     setcolor(WHITE);
     outtextxy(i*70+25,420-length,t);

     settextstyle(2,0,5);
     outtextxy(i*70+25,455,lab[i]);
  }
  for(i=0;i<=10;i++)
  {
    moveto(40,40*i+50);
    itoa(max*(10-i)/10,t,10);
    outtext(t);
    lineto(50,40*i+50);

  }
  getch();

}