#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
int mo=1,d=1,y=2000;
//void set_time();
int gotoxy(int a, int b)
{
    COORD c;
    c.X = a;
    c.Y = b;
  
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
return 0;
}


int month(int m)					//We Define a month logic 
{						//in This Function
	switch(m)
	{
		case 1: 
			gotoxy(37,22);
			printf("January  ");
			break;
			
		case 2: 
			gotoxy(37,22);
		printf("February ");
			break;
			
		case 3:
			gotoxy(37,22);
		printf("March    ");
			break;
			
		case 4: 
			gotoxy(37,22);
			printf("April    ");
			break;
			
		case 5: 
			gotoxy(37,22);
			printf("May      ");
			break;
		
		case 6: 
			gotoxy(37,22);
			printf("June     ");
			break;
	
		case 7: 
			gotoxy(37,22);
			printf("July     ");
			break;
	
		case 8: 
			gotoxy(37,22);
			printf("August   ");
			break;
		
		case 9: 
			gotoxy(37,22);
			printf("September");
			break;
	
		case 10: 
			gotoxy(37,22);
			printf("October  ");
			break;
			
		case 11: 
			gotoxy(37,22);
			printf("November ");
			break;
			
		case 12: 
			gotoxy(37,22);
			printf("December ");
			break;
	}
return 0;
}


int value(int d,int m ,int y)			//This Function display the value when 
{								//	we set or change the value from the display
gotoxy(28,22);
		printf("|");
	gotoxy(30,22);
		printf("%d ",d);
	gotoxy(35,22);	//5
		printf("|");
	gotoxy(40,22);		//5
		month(mo);

	gotoxy(46,22);		//6
		printf("|");
	gotoxy(48,22);		//2
		printf("%d ",y);	
//	arrow();
	return 0;
}

	



//In this Function we set date and month year(this is the Backend)	
int set_dob()
{
		int a;
	int i=30,j=22;
//	gotoxy(5,5);
	while(1)
	{
	a=getch();
	
	
	if(a==77)  //When we press Right Arrow key then this function will set cursor 
	{			// position in between date, month and year
		if(i<50&&j==22)
	    {
     		i=i+10;
     		gotoxy(i,j);
        }
	}
	
	
	else if(a==75) //When we press Left Arrow key then this block will set cursor 
	{			// position in between date to month, month to year and vice-versa.
		if(i!=30&&j==22)
   	    {
    		i=i-10;
    		gotoxy(i,j);
   	    }

	}
	
	
	
	else if(a==72) //When we press Up Arrow then this block set the particular date,
	{				//month and year
	
		if(i==30)	
		{
			if(d>1 )
			{
				d--;	
			}
		}
		
		else if(i==40)
		{
			if(mo>1 )
			{
				mo--;
					
				if(mo==2 && d>28)
				{
					if(y%4==0)
					{
						d=29;
					}
					
					else
					d=28;
				}
				else if(mo==4 || mo==6 || mo==9 || mo==11)
				{
					if(d>30)
					{
						d=30;
					}
				}
			
			}
		}
		
		else if(i==50)
		{
			if(y>1)
			{
				y--;
				if(y%4==0 && mo==2)
				{
					
					d=29;
				}
				
				else if(y%4!=0 && mo==2)
				{
					if(d>28)
					d=28;
				}
				
			}
		}
		value(d,mo, y);
			gotoxy(i,j);
		

	}
	
	
	else if(a==80) //Down Arrow
	{
		if(i==30)				//For Days
		{
			if(mo==2)		//This block set the value of february and leap year date
			{
				if(y%4==0)
				{
					if(d<29 )
					{
					d++;
					}	
				}
				
				else
				{
					if(d<28 )
					{
					d++;
					}
				}
			}
			
		//this block Set the VAlue of only those month that have only 30 days		
			else if(mo==4 || mo==6 || mo==9 || mo==11)
			{
				if(d<30 )
				{
					d++;		
				}
			}
			
			//this block set the value of Remaining month's day  
			else 	
			{	
				if(d<31 )
				{
				d++;	
				}	
			}
		}
		
		else if(i==40)			//This block will set the Month
		{
			if(mo<12 )
			{
					mo++;
				if(mo==2 && d>28)	//this block will change the date when curor in feb and leap year
				{
					if(y%4==0)
					d=29;
					
					else
					d=28;
				}
				
				//this block will change the date when curor in those month that end with 30 days
				else if(mo==4 || mo==6 || mo==9 || mo==11)
				{
					if(d>30)
					{
						d=30;
					}
				}
			
			
			}
		}
		
		else if(i==50)			//For Year
		{
			if(y>1)
			{
				y++;
				if(y%4==0 && mo==2)
				{
					
					d=29;
				}
				
				else if(y%4!=0 && mo==2)
				{
					if(d>28)
					d=28;
				}	
			}
		}
		
		value(d,mo, y);		//we call these function and pass the attributes with changable value
		gotoxy(i,j);
	
	}
	
	
	else if(a==13)  //When we press Enter key then this program will terminate
	{						//with 3 return value
		return d,mo,y;
	
	}
}
return 0;
}
int dob()
{				//This is Starting interface of program
	
		gotoxy(28,22);					
		printf("|");
	gotoxy(30,22);						
		printf("%d ",d);
	gotoxy(35,22);						
		printf("|");
	gotoxy(40,22);						
		month(mo);

	gotoxy(46,22);						
		printf("|");
	gotoxy(48,22);		
		printf("%d ",y);	
	set_dob();		//Calling the function for moving cursor
return 0;	
}
