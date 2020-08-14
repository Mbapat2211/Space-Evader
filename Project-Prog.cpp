#include<iostream.h>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

char screen[9][79];
int R1,R2,R3,C1,C2,C3,level=0,score=500,R4,C4,temp;

class playerp
{
    private: int pscore;
             char pnm[4];
             int plevel;
             int ppoint;

    public: void ename()
            {
                cout<<"\nEnter your name\t";
                gets(pnm);
                strcpy(nom,pnm);
                plevel=level;
	            pscore=score;
	            ppoint=500-(pscore/plevel);
	        }

	        char nom[4];

            void otpt()
	        {
                cout<<pnm<<"\t"<<plevel<<"\t"<<pscore<<"\t"<<ppoint<<endl;
	        }

	        int plt()
	        {
                plevel=level;
	            return plevel;
	        }

	        int pnt()
            {
                ppoint=500-(pscore/plevel);
	            return ppoint;
	        }

	        int escore()
	        {
                pscore=score;
                return pscore;
            }

};

playerp P;//[10];

void entervalues();
void game();
void display();
void movepieces();
void check();

void Xit()
{
    fstream fl;
    fl.open("GGG.TXT",ios::in|ios::out);
    P.ename();

    fl<<P.nom<<setw(10)<<P.pnt()<<setw(10)<<P.plt()<<setw(10)<<P.escore()<<endl;
    cout<<"\nYour points are\t"<<P.pnt();
    fl.close();
    getch();
}


void Xout()
{
    char c[99];
    fstream fl;
    fl.open("GGG.TXT",ios::out|ios::in);
    fl.seekg(0);
    while(!fl.eof())
    {
        fl.getline(c,80);
        cout<<c<<endl;
    }
    fl.close();
    getch();
}

void main()
{
    int j;
    clrscr();
    cout<<"Main Menu\n\n1. Play Game\n2. View Your Previous Scores\n3. Exit\n";
    cin>>j;
    switch(j)
    {
        case 1: game();break;
        case 2: Xout();main();break;
        case 3: exit(0);break;
    }
}

void game()
{
    randomize();

    R1=random(9);
    C1=random(79);

    R2=random(9);
    C2=random(79);

    R3=random(9);
    C3=random(79);

    while((level>=0))
    {
        level++;
        if(level>10)
        {
            clrscr();
            cout<<"\n\n\n\n\n"<<setw(40)<<"Congrots , You Have Beaten The GAme"<<endl;
            cout<<"YOUR FINAL SCORE IS "<<score;
            Xit();
            main();
            getch();
            exit(0);
        }

        cout<<setw(47)<<"SPACE EVADER"<<endl;
        cout<<"\n\nLevel = "<<level<<endl;
        cout<<setw(45)<<"Press Any Key";
        getch();
        break;
    }

    for( ; ; )
    {
        entervalues();
        display();
        movepieces();
        check();
    }
}

void entervalues()
{
    for(int i=0;i<9;i++)
    for(int j=0;j<79;j++)
    screen[i][j]='.';

    screen[R1][C1]='*';
    screen[R2][C2]=(char)1;
    screen[R3][C3]='0';
}

void display()
{
    clrscr();
    cout<<setw(47)<<"SPACE EVADER"<<endl;

    cout<<"LEVEL="<<level<<setw(65)<<"SCORE="<<score<<endl;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<79;j++)
        cout<<screen[i][j];
        cout<<"\n\n";
    }
}

void movepieces()
{
    char move[1];
    cout<<"Enter your move\t";
    cin>>move;
    score--;
    switch(move[0])
    {
        case 'a': if(C2!=0)
                  C2=C2-1;
	              else
	              C2=78;break;

        case 's': if(R2!=8)
	              R2=R2+1;
	              else
	              R2=0;break;

        case 'w': if(R2!=0)
	              R2=R2-1;
          	      else
	              R2=8;break;

        case 'd': if(C2!=78)
	              C2=C2+1;
	              else
	              C2=0;break;

    case 'x':
    case 'X': clrscr();
              cout<<"\n\n\n\n\n"<<setw(40)<<"Congrots , The GAme Have Beat YoU at level\t"<<level<<endl;
                     cout<<"YOUR FINAL SCORE IS "<<score;
                     Xit();
main();
getch();
  }

  temp=rand()%4;

  R4=R1;
  C4=C1;

  for(int i=1;i<=level;i++)
  {
    // randomize();
    switch(temp)
    {
        case 1: if(C1!=0)
	    C1=C1-1;
	    else
	       C1=78;break;

      case 2: if(R1!=8)
	   R1=R1+1;
	   else
	   R1=0;break;

      case 3: if(R1!=0)
	   R1=R1-1;
	   else
	   R1=8;break;

      case 0: if(C1!=78)
	   C1=C1+1;
	   else
	   C1=0;break;
    }
  }
}

void check()
{
    int lose=0,win;
    win=0;
    switch(temp)
    {
        case 1: if((R2==R1)&&(C2<C4)&&(C1<=C2))
	            lose++;
	            break;

        case 2: if((C2==C1)&&(R2>=R4)&&(R2<=R1))
	            lose++;
	            break;

        case 3: if((C2==C1)&&(R2<=R4)&&(R2>=R1))
	            lose++;
	            break;

        case 0: if((R2==R1)&&(C2>C4)&&(C1>=C2))
	            lose++;
	            break;
    }

    if((R2==R3)&&(C2==C3))
        win++;

    if(lose!=0)
    {
        clrscr();
        cout<<"\n\n\n\n\n"<<setw(45)<<"!YOU HAVE LOST!";
        getch();
    }

    if(win!=0)
    {
        clrscr();
        cout<<"\n\n\n\n\n"<<setw(45)<<"!!!!VICTORY!!!!";
        getch();
    }

    if(win!=0)
    {
        win=0;
        game();
    }

    if((lose!=0)||(score<=0))
    {
        clrscr();
        char a;
        cout<<"\n\n\tPress any key to continue";
        cin>>a;
        Xit();
        main();
    }
}
