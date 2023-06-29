#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
using namespace std;
void accounttype();
char account_type[40];



class go
{
	public:
		
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
};
int select()
{ 
	go g;
	int a,i=20,j=25;
	while(1)
	{
	a=getch();
	
	if(a==72)        			//When we press UP Key
	{
		if(j>25)
		{
		j-=2;
		g.gotoxy(i,j);	
		}	
	}	
	else if(a==80)				//when we press Down Key
	{
		if(j<27)
		{
			j+=2;
			g.gotoxy(i,j);
		}
	}
	
	else if(a==77)			//When we press Right Arrow
	{
		if(i<60)
		{
		i+=20;
		g.gotoxy(i,j);		
		}		
	}
	
	
	else if(a==75)			//When we press Left Arrow
	{
		if(i>20)
		{
		i-=20;
		g.gotoxy(i,j);		
		}		
	}
	
	else if(a==13)			//When we press Enter key
	{
		if(i==20 && j==25)
		{
		strcpy(account_type , "Saving Account ");
		break;	
		}
		
		else if(i==40 && j==25)
		{
		strcpy(account_type , "Current Account ");
		break;	
		}
		
		else if(i==60 && j==25)
		{
		strcpy(account_type , "Salary Account ");
		break;	
		}
		
		else if(i==20 && j==27)
		{
		strcpy(account_type , "Fixed Deposite ");
		break;	
		}
		
		else if(i==40 && j==27)
		{
		strcpy(account_type , "Requring Deposite ");
		break;	
		}
		
		else if(i==60 && j==27)
		{
		strcpy(account_type , "NRI Deposite ");
		break;	
		}
	}
}
   return 0; 
}


void accounttype()
{
	go g;
	g.gotoxy(0,25);
	cout<<"Account Type ";
	g.gotoxy(20,25);
	cout<<"Saving Account ";
	g.gotoxy(40,25);
	cout<<"Current Account ";
	g.gotoxy(60,25);
	cout<<"Salary Account ";
	g.gotoxy(20,27);
	cout<<"Fixed Deposite ";
	g.gotoxy(40,27);
	cout<<"Recurring Deposit ";
	g.gotoxy(60,27);
	cout<<"NRI Accounts ";		

	select(); //calling select function for store the data and also for moving cursor
} 


