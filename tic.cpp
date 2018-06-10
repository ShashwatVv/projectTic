#include<iostream>
#include<cstdlib>
using namespace std;
char A[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char B[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void board();
int check();
void splay(char);
void rep(char,char);
int main()
{   int ch;
     char a='y';
     cout<<"\t\t\tTIC TAC TOE"<<endl;
   do
    { swap(A,B);
    cout<<"Choose \n!.player(X) or 2.Player(O): ";
    cin>>ch;
    if(ch==1)
        splay('X');
    else if (ch==2)
        splay('O');
    else
        cout<<"\nError";
        cout<<"\n Try Again?(Y/N):";
        cin>>a;

} while((a=='y')||(a=='Y'));
return 0;
}
void board()
{
    cout<<"   "<<A[0][0]<<" |"<<" "<<A[0][1]<<" |"<<" "<<A[0][2]<<" "<<endl;
    cout<<"  ___|___|___"<<endl;
    cout<<"   "<<A[1][0]<<" |"<<" "<<A[1][1]<<" |"<<" "<<A[1][2]<<" "<<endl;
    cout<<"  ___|___|___"<<endl;
    cout<<"   "<<A[2][0]<<" |"<<" "<<A[2][1]<<" |"<<" "<<A[2][2]<<" "<<endl;
}
int check()
{   char c='N';
    if((A[0][0]==A[0][1])&&(A[0][1]==A[0][2]))
        c=A[0][0];
    else if((A[1][0]==A[1][1])&&(A[1][1]==A[1][2]))
        c=A[1][0];
    else if((A[2][0]==A[2][1])&&(A[2][1]==A[2][2]))
        c=A[2][0];
    else if((A[0][0]==A[1][0])&&(A[1][0]==A[2][0]))
        c=A[0][0];
    else if((A[0][1]==A[1][1])&&(A[1][1]==A[2][1]))
        c=A[0][1];
    else if((A[0][2]==A[1][2])&&(A[1][2]==A[2][2]))
        c=A[0][2];
     else if((A[0][0]==A[1][1])&&(A[1][1]==A[2][2]))
        c=A[0][0];
     else if((A[2][0]==A[1][1])&&(A[1][1]==A[0][2]))
        c=A[2][0];
      if(c=='X')
                {cout<<"\nPlayer(X) wins."<<endl;
                return 0;}
            else if(c=='O') {cout<<"\nPlayer(O) wins."<<endl;
                               return 0;}
        else
        return 1;

}
void splay(char b)
 {  char k;
     int d;
    int t=0;
    board();
    if(b=='X')
    {while(t<9)
     {if(t>=5)
          {
            d=check();
            if(d!=1)
                break;
          }

      cout<<"\nPlayer(X) move:"<<endl;
      cin>>k;
      rep(k,'X');
      t++;
      if(t>=5)
          {
            d=check();
            if(d!=1)
                break;
          }

      cout<<"\n player(O) move:"<<endl;
        cin>>k;
        rep(k,'O');
        t++;
    }
    }
    else if(b=='O')
    {while(t<9)
     {if(t>=5)
          {
            d=check();
            if(d!=1)
                break;
          }

      cout<<"\nPlayer(O) move:"<<endl;
      cin>>k;
      rep(k,'O');
      t++;
      if(t>=5)
          {
            d=check();
            if(d!=1)
                break;
          }
      cout<<"\n player(X) move:"<<endl;
        cin>>k;
        rep(k,'X');
        t++;
    }
    }
    if(d==1)
        cout<<"MATCH DRAWN!!!";
}
void rep(char c, char d)
{system("cls");
   for(int i=0;i<3;i++)
   {
       for(int j=0;j<3;j++)
       {
           if(A[i][j]==c)
            A[i][j]=d;
       }
   }
   board();
}
