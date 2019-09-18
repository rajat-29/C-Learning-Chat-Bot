#include <iostream>
#include<conio.h>
#include<windows.h>
#include<vector>
#include<time.h>
using namespace std;

enum direction{STOP=0,FIRE};
direction dir;
int w;
int s;
int z=0;
string name;

class Moving
{
	char mat[50][50];
    int m,n;      //   co-ordinates of border
    int x,y;     // x and y co-ordinate of fighting plane
    vector<int> buletx,bulety;  // vector of bullets fired
    int prevx,prevy;
    vector<int> enemyx,enemyy;
    int flag;
public:

    int score;
    Moving()
    {
        flag=0;
        score=0;
        cout<<"ENTER NO OF ROWS(REC 20) : ";
        cin >> m ;
        cout<<"ENTER NO OF COLOUMNS(REC 20) : ";
        cin>>n;
        w=m;
        s=n;
        mat[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0 || i==(m-1) || j==(n-1))
                {
                    mat[i][j]='#';
                }
                else
                {
                    mat[i][j]=' ';
                }
            }
        }
    }
    void move_enemy()
    {
        for(int i=0;i<enemyx.size();i++)
        {
            mat[enemyx[i]][enemyy[i]]=' ';
            if(++enemyx[i]==(n-1))
            {
                cout << endl << "GAME OVER "<<name<< endl;
                throw 1;
            }
            mat[enemyx[i]][enemyy[i]]='e';
        }
    }
    void generate_enemy()
    {
        srand(++z);
        if(rand()%2==0 && flag!=2)
        {
            ++flag;
            int x;
            for(int i=0;i<rand()%(n/3);i++)
            {
                enemyx.push_back(1);
                srand(++z);
                if(x=rand()%(n-1)){}
                else{x=1;}
                enemyy.push_back(x);
                mat[1][x]='e';
            }
        }
        else
        {
            flag=0;
        }
    }
    void kill_enemy()
    {
        for(int i=0;i<buletx.size();i++)
        {
            for(int j=0;j<enemyx.size();j++)
            {
                if(buletx[i]==enemyx[j] && bulety[i]==enemyy[j])
                {
                    score=score+10;
                    enemyx.erase(enemyx.begin()+j);
                    enemyy.erase(enemyy.begin()+j);
                    
                }
            }
        }
    }
    void Draw_ob()//FIGHTING PLANE
    {
        x = prevx = m-2;
        y = prevy = n/2;
        w=m-3;
        s=s/2;
        mat[x][y]='^';
    }
    void start()//MOVE FIGHTING PLANE
    {
    	dir=STOP;
        mat[x][y]=' ';
        if(kbhit())
        {
            switch(getch())
            {
            case 'a':
                {
                    if(y>1)
                    {
                        --y;
                        s--;
                    }
                    break;
                }
            case 'd':
                {
                    if(y<(n-2))
                    {
                        ++y;
                        s++;
                    }
                    break;
                }
            case 'w':
                {
                    dir=FIRE;
                }
            }
        }
        mat[x][y]='^';
    }
    void bullet()
    {
       if(dir==FIRE)
		{
		mat[w][s]='|';
		buletx.push_back(w);
		bulety.push_back(s);
     	}
     	
    }
    void Draw()
    {
    	int ch;
        system("cls");
        for(int i=0;i<buletx.size();i++)
        {
            mat[buletx[i]][bulety[i]]=' ';
            --buletx[i];
            ch=buletx[i];
            if(ch==1)
            {
            mat[buletx[i]][bulety[i]]=' ';
            buletx.erase(buletx.begin()+i);
            bulety.erase(bulety.begin()+i);
            }
            else
            mat[buletx[i]][bulety[i]]='|';
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << mat[i][j];
            }
            cout << endl;
        }
        cout << "SCORE: " << score;
    }
};

int main()
{
    int level = 100,l=0,no;
    int m=5,n=0;
    Moving ob1;
    ob1.Draw_ob();
    cout<<"ENTER YOUR NAME = ";
    cin>>name;
    cout<<"ENTER 1 TO READ INSTRUCTIONS : "<<endl;
    cout<<"ENTER 2 TO ENTER THE GAME : "<<endl;
    cout<<"ENTER YOU CHOICE : ";
    cin>>no;
    if(no==1)
    {
    	cout<<"PRESS A TO MOVE BACKWARDS"<<endl;
    	cout<<"PRESS D TO MOVE FORWARDS"<<endl;
    	cout<<"PRESS W TO FIRE THE BULLET"<<endl;
    	cout<<"PRESS 2 TO ENTER THE GAME AGAIN = ";
    	cin>>no;
	}
    if(no==2)
    {
    while(true)
    {
        if(ob1.score==150)
            {
                level-=5;
            }
        try
        {
            ob1.Draw();
            ob1.start();
            ob1.bullet();
            if(++n==m)
            {
                m=m+6;
                ob1.generate_enemy();
                ob1.move_enemy();
            }
            ob1.kill_enemy();
            Sleep(level);
        }
        catch(int i)
        {
            break;
        }
    }
    }
    return 0;
}
