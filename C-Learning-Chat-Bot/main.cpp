#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>

using namespace std;

class chat
{
	char name[20];
	int a=0;
	public:		
	void initial()
	{
		cout<<"\t\t\t\t\t\tWELCOME TO THE LEARNING CHATBOT "<<endl<<endl<<endl;
		cout<<"Bot  : Hey User, My name is RAJAT !! Please tell me your name ?"<<endl;
		cout<<"User : ";
		cin>>name;
		cout<<"Bot  : Welcome "<<name<<" How can i help you ?"<<endl;
	}
	void content()
	{
     ofstream ofile;
   	ifstream ifile;

	string str1;
	string str2;
	int c=1;
	ifile.open("textes.txt");
	
	cout<<"User : ";
	cin.ignore();
	getline(cin,str1);
		
	while(a!=10)
	{
		c=0;
		while(!ifile.eof())
		{
			getline(ifile,str2);
			if(str1.compare(str2)==0)
			{
				c=1;
				getline(ifile,str2);
				cout<<"Bot  : ";
				cout<<str2<<endl;
				ifile.close();
				
			}
		}
		if(c==0) 
		{
			cout<<"Bot  : Sorry i don't know about this :( . Can you tell me the answer ?"<<endl;
			ifile.close();
			ofile.open("textes.txt",ios::app);
			ifile.open("textes.txt");
//			ofile<<endl;
			ofile<<str1<<endl;
		    cout<<"User : ";
		    getline(cin,str1);
		    ofile<<str1<<endl;
		    cout<<"Bot  : Thank you "<<name<<" for your kind help !!"<<endl;
		    ofile.close();
		    ifile.close();
		}
		ifile.open("textes.txt");
		cout<<"User : ";
		getline(cin,str1);
		if(str1.compare("exit")==0)
		{
			a=10;
		}
	}
}

void final()
{
	if(a==10)
	{
		cout<<endl<<endl;
		cout<<"\t\t\t\t\t\t Thank you for using chatbot :) ";
	}
}
};


int main()
{
	chat ob1;
	ob1.initial();
	ob1.content();
	ob1.final();
}
