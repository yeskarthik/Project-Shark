#include<iostream.h>
#include<graphics.h>
#include<stdlib.h>
#include<bios.h>
#include<dos.h>
#include<math.h>
#include<conio.h>
void rootmain()
{
	int gd=VGA,gm=2;
	initgraph(&gd,&gm,"d:/tc1/bgi");
    long int a[7],n,b[7],t=0;
    cleardevice();
    gotoxy(10,10);
    cout<<"Hey!!";
    cout<<"\n\n\tThis is a Program to find the roots of any nth degree equation\n\tThis may be useful in mathematics and physics very much.\n\tHope You Will Enjoy Using this \n\n\t\tThanking You\n\t\
    The Shark Associates\n\t\t";
	 getch();
    do{
	cleardevice();
	gotoxy(10,10);
	cout<<"Enter degree :";
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		cout<<"Enter coefficient in order :";
		cin>>a[i];
	}

    long int flag=0,f=0;
    long int k=n;
    long int jo,mo;

    cout<<"Enter Expected Range of the Roots lesser to greater if you dunno press 0 0 \n\n";
    cin>>jo>>mo;
    if(jo==0&&mo==0)
    {
	jo=-9999999;
	mo=9999999;
    }


    cout<<"\n\nPlease wait while the computer thinks!:)\n";
	for(long int j=jo-1;j<mo+1&&t<=n-1;j++,f++)
	{
    long double s=0;
		k=n;
		if(j!=0)
		{
			for(i=0;i<=n;i++)
			{
				s=s+pow(j,i)*a[k];
				k--;
			}
			if(s==0)
				{
					b[t]=j;
					t++;
					flag=1;
				}
		}

	 }

	 cout<<endl;
	 if(n==0)cout<<"Root is :"<<0;
	 else if(flag==0)cout<<"No Real or integral Roots !";
	 else
	 {
		cout<<"The Distinct Root(s) of the given equation are :";
		for(i=0;i<t;i++)
		cout<<b[i]<<' ';
	 }
	cout << "\nNo. of times loop ran = " << f ;
	cout<<"\n\tThank You";
	cout<<"\n\nPress Any key to continue ";
	cout<<"\nPress Esc to Exit";
	int u=bioskey(0);
	if(u==283)break;
	getch();
	}while(7);
}
