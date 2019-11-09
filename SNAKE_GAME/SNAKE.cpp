#include<iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <conio.h>
#include <windows.h>
using namespace std;

int foodx=10;
int foody=20;
int x=1;
int y=1;
int score=0;
int fru=0;
vector<int> coX,coY;
vector<char> f;

class food;
class body;

enum direction{STOP=0,LEFT,RIGHT,DOWN,UP,OVER};
direction dir;
       
class board
{
   protected:
   char mat[40][40];
   public:
   	board()
   	{
	    for(int i=0;i<40;i++)
   		{	   
    	for(int j=0;j<40;j++)
    	{
    		if(i==0 || j==39 || i==39 || j==0)
    		mat[i][j]='*';
    		else
    		mat[i][j]=' ';
		}
	   }
	f.push_back('F');
   f.push_back('A');
   f.push_back('M');
   f.push_back('B');
   f.push_back('P'); 
	}
   friend class food; 
   friend class body;
};

class food
{
	public:
	void drawfood(board &ob9)
	{
		ob9.mat[foodx][foody]=f[fru];
	}
	void popfood(board &ob10)
	{	
	    if(x==foodx && y==foody)
	    { 
	    srand(time(0));
	    fru=rand()%4+1; 
     	foodx=rand()%40+1;
     	foody=rand()%40+1;
     	
     	if(foodx==0 || foody==0){
		 foodx=35;foody=29;}
        if(foodx==37 || foody==39){
	     foodx=27;foody=16;	}
     	
        for(int i=0;i<coX.size();i++)
        {
        	if(foodx==coX[i] && foody==coY[i])
        		popfood(ob10);
		}
		drawfood(ob10);
     	coX.insert(coX.begin(),x);
     	coY.insert(coY.begin(),y);
     	 score = score+10; 	
        }
    }		
};

class body
{
	public:
	    body()
	    {
	    	 dir=STOP;
		}
		void base(board &ob6)
		{
			ob6.mat[1][1]='R';
		}
		void start(board &ob1)
		{
			if(kbhit())
			{
				switch(getch())
				{
					case'a':
						{
						dir=LEFT;
						break;
					    }
					case'd':
						{
						dir=RIGHT;
						break;
					    }
					case'w':
						{
						dir=UP;
						break;
					    }
					case'z':
						{
						dir=DOWN;
						break;
					    }	
					case'o' :
					{
						dir=OVER;
						break;
					}		    
				}
			}
			ob1.mat[x][y]=' ';
			if(coX.size()!=0)
			{
				int a,b;
				a=coX[0];
				b=coY[0];
				coX[0]=x;
				coY[0]=y;
				ob1.mat[x][y]='o';
				for(int i=1;i<coX.size();i++)
				{
					int p=coX[i];
					int r=coY[i];
					coX[i]=a;
					coY[i]=b;
					ob1.mat[a][b]='o';
					a=p;
					b=r;
				}
			ob1.mat[a][b]=' ';
			}
			if(dir==LEFT)
			{
				if(--y<1)
				y=38;
				ob1.mat[x][y]='<';
			}
			else if(dir==RIGHT)
			{
				if(++y>38)
				y=1;
			}
			else if(dir==UP)
			{
				if(--x<1)
				x=38;
			}
			else if(dir==DOWN)
			{
				if(++x>38)
				x=1;
			}
			else if(dir==OVER)
			{
				throw 1;
			}
			ob1.mat[x][y]='R';
			system("CLS");
			for(int i=0;i<40;i++)
			{
				for(int j=0;j<40;j++)
				{
					cout<<ob1.mat[i][j];
				}
				cout<<endl;
			}
			cout<<"Score = "<<score;			
		}
};

int main()
{
	enum speed{EASY=130,MEDIUM=100,HARD=70};
	speed raj;
	int no,n=120;
	string name;
	char a;
	cout<<"ENTER NAME = ";
	cin>>name;
	cout<<"CHOOSE DIFFICULTY (E,M,H) = ";
	cin>>a;
	if(a=='e')
	raj=EASY;
	if(a=='m')
	raj=MEDIUM;
	if(a=='h')
	raj=HARD;
	
	cout<<"INSTRUCTIONS FOR GAME : "<<endl;
	cout<<"PRESS W FOR UPWARDS"<<endl;
	cout<<"PRESS Z FOR DOWNWARDS"<<endl;
	cout<<"PRESS A FOR BACKWARDS"<<endl;
	cout<<"PRESS D FOR FORWARDS"<<endl;
	cout<<"PRESS O FOR GAME OVER"<<endl;
	cout<<"PRESS 1 TO ENTER THE GAME = ";
	cin>>no;
	board ob1;
	food ob2;
    body ob3;
    ob3.base(ob1);
    while(true)
    {
    	ob2.popfood(ob1);
    	ob2.drawfood(ob1);
    	try
    	{
    		ob3.start(ob1);
		}
		catch(int x)
		{
			cout<<endl<<"GAME OVER PLAYER "<<name;
			break;
		}
		
		Sleep(raj);
	}
	return 0;
}
