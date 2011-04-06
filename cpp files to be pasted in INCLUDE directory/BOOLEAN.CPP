#include<iostream.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
int and(int a,int b)
{
	if((a==1)&&(b==1))return 1;
	else return 0;
}

int or(int a,int b)
{
	if((a==0)&&(b==0))return 0;
	else return 1;
}

int not(int a)
{
	if(a==0)return 1;
	else return 0;
}

struct kar
{
	int a[16];
}a1,a2,a3;

void assign()
{
for(int i=0;i<16;i++)
{
	if((i+1)%2==0)a1.a[i]=1;
	else a1.a[i]=0;
}

for(i=1;i<=16;i++)
{
	if((i/2)%2==0)a2.a[i]=1;

}


}
void main()
{
	clrscr();
	a1.a={0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
	a2[16]={0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1};
	a3[16]={0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1};
	a4[16]={0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
	kar r[16],r1[16],r2[16];
       /*	for(int i=0;i<16;i++)
	{
		r[i]=and(a1[i],a2[i]);
		r[i]=and(r[i],a3[i]);
		r[i]=and(r[i],a4[i]);
	}
	for(i=0;i<16;i++)
	{
		cout<<a1[i]<<'\t'<<a2[i]<<'\t'<<a3[i]<<'\t'<<a4[i]<<'\t'<<r[i]<<'\n';
	}*/
       //	int n,t=0;
       /*	do
	{
		cout<<"			BOOLEAN ALGEBRA";
		cout<<"\nEnter Number of variables to be used (1 to 4)";
		cin>>n;
		t=0;
		switch(n)
		{
			case 1:do{
						int k,i;
						if(t==0)cout<<"INITIAL VARIABLE :A\nRESULTANT VARIABLE :R\n";
						t=1;
						cout<<"\nEnter option\n1.A\n2.NOT\n3.AND\n4.OR\n5.DISPLAY\n6.EXIT\n\n";
						cin>>k;
						switch(k)
						{
							case 1:
							for(i=0;i<2;i++)
							{
							r[i]=a1[i];
							}
							cout<<"\nA INITIALISED\n";
							break;
							case 2:
							for(i=0;i<2;i++)
							{
							r[i]=not(a1[i]);
							}
							cout<<"\n'NOT(A)' STORED IN THE RESULT\n";
							break;
							case 3:
							for(i=0;i<2;i++)
							{
							r[i]=and(r[i],a1[i]);
							}
							cout<<"'R AND A' STORED IN THE RESULT";
							break;
							case 4:
							for(i=0;i<2;i++)
							{
							r[i]=or(r[i],a1[i]);
							}
							cout<<"'R OR A' STORED IN THE RESULT";
							break;
							case 5:
							cout<<'\n'<<"A"<<'\t'<<"R"<<'\n';
							for(i=0;i<2;i++)
							{
							cout<<'\n'<<a1[i]<<'\t'<<r[i]<<'\n';
							}break;
							case 6:exit(0);
						}
					}while(8);
					break;

			case 2:  	do{
					int jo;
					if(t==0)cout<<"INITIAL VARIABLES :A,B\nRESULTANT VARIABLE :R\nNOTE:TO FIND NOT OF A  VARIABLE AND STORE PUT FIRST AND SECOND VARIABLE SAME";
						t=1;
						cout<<"\nCHOOSE VARIABLE\n1.A\n2.B\n3.R\n";
						cin>>jo;
						if(jo==1)
						{
							for(int i=0;i<4;i++)
							r1[i]=a1[i];
						}
						else if(jo==2)
						{
							for(int i=0;i<4;i++)
							r1[i]=a2[i];
						}
						else if(jo==3)
						{
							for(int i=0;i<4;i++)
							r1[i]=r[i];
						}
						cout<<"\nVARIABLE 1 CHOSEN\nCHOOSE SECOND VARIABLE\n1.A\n2.B\n3.R\n";
						cin>>jo;
						if(jo==1)
						{
							for(int i=0;i<4;i++)
							r2[i]=a1[i];
						}
						else if(jo==2)
						{
							for(int i=0;i<4;i++)
							r2[i]=a2[i];
						}
						else if(jo==3)
						{
							for(int i=0;i<4;i++)
							r2[i]=r[i];
						}
						int k,i;
						cout<<"\nVARIABLE 2 CHOSEN \n";
						cout<<"\nEnter option\n1.NOT\n2.AND\n3.OR\n4.DISPLAY\n5.EXIT\n\n";
						cin>>k;
						switch(k)
						{
							case 1:
							for(i=0;i<4;i++)
							{
							r[i]=not(r1[i]);
							}
							cout<<"\n'NOT(A)' STORED IN THE RESULT\n";
							break;
							case 2:
							for(i=0;i<4;i++)
							{
							r[i]=and(r1[i],r2[i]);
							}
							cout<<"'R1 AND R2' STORED IN THE RESULT";
							break;
							case 3:
							for(i=0;i<4;i++)
							{
							r[i]=or(r1[i],r2[i]);
							}
							cout<<"'R1 OR R2' STORED IN THE RESULT";
							break;
							case 4:
							cout<<'\n'<<"R1"<<'\t'<<"R2"<<'\n'<<"R";
							for(i=0;i<4;i++)
							{
							cout<<'\n'<<r1[i]<<'\t'<<r2[i]<<'\t'<<r[i];
							}break;
							case 5:exit(0);
						}
					cout<<'\n'<<"R1"<<'\t'<<"R2"<<'\t'<<"R"<<'\n';
					for(i=0;i<4;i++)
					{
						cout<<'\n'<<r1[i]<<'\t'<<r2[i]<<'\t'<<r[i];
					}
					}while(8);
		}
	getch();
	}while(8);     */


	int n;
	kar p;
	do
	{
		cout<<"ENTER OPTION\n1.A\n2.B\n3.AND\n4.OR\n5.EXIT";
		cin>>n;
		switch(n)
		{
			case 1:

		}
	}while(8);






}

