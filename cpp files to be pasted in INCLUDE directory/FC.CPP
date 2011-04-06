# include<fstream.h>

void fc(char *target,char *source)
{
//char source[67],target[67];
//char ch;

//cout<<endl<<"Enter source filename = ";
//cin>>source;

//cout<<endl<<"Enter target filename = ";
//cin>>target;

ifstream infile(source);
ofstream outfile(target);
outfile<<infile.rdbuf();
}
