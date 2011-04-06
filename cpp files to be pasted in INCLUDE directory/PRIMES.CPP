#include<graphics.h>
#include<iostream.h>
#include<process.h>
#include<math.h>
#include<bios.h>
#include<conio.h>
int prime(long int i)
{
	long int c=0;
	for(int j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)c++;
		}
		if(c==0)return 1;
		else return 0;
}
int factors(long int a,long int n)
{
	if(a%n==0)return 1;
	else return 0;
}

void primemain()
{
	int gd=VGA,gm=2;
	initgraph(&gd,&gm,"l:\\tc1\\bgi");
	cleardevice();
	long int n,p,c=0;
	cout<<"\n\n\n\n\n\tHey!\n\tThis is a Program to find the distinct primes f a given number\n\t It is very useful in mathematical reasoning and logics\n\t Hope You Will Enjoy using this\
		\n\n\tThanking You\n\n\tThe Shark Associates";
	getch();
      do{
      cleardevice();
	cout<<"\r\t\tEnter Number :";
	cin>>n;
	long int t=n;
	cout<<"\t\tPrimes of that number are \n\t\t";
	for(long int i=2;i<=n;i++)
	{
		c=0;
		if(prime(i)==1&&factors(n,i)==1)
		{
			t=n;
			while(t%i==0)
			{
				c++;
				t=t/i;
			}
			cout<<"   "<<i<<'^'<<c;
		}
	}
	cout<<"\t\t\n\n\t\tThank You.\t\t\n\n\t\tPress esc to exit\
	.\n\n\t\tPress Any Key to continue.";
	int u=bioskey(0);
	if(u==283)break;
	gotoxy(10,10);
	}while(7);
}






