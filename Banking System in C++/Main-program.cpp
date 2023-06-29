#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <fstream>
#include<windows.h>
#include"take_inpute_of_accounttype.cpp"
#include<ctype.h>
#include<string.h>
#include"date of birth.cpp"
using namespace std;

class name
{
	protected:
	char f_name[20];
	char l_name[20];	
};

class money
{
		public:
		char username[40];
		long long int amount;
		
};

class userpass
{
	protected:
	char username[40];
	char password[40];	
};

class father_name
{
	protected:
	char father_f_name[20];
	char father_l_name[20];
};

class mother_name
{
	protected:
	char mother_f_name[20];
	char mother_l_name[20];
};

class address
{
	protected:
	char flat_no[20];
	char Area[50];
	char landmark[50];
	char city[50];
	char state[50];
	long long int pincode;
};

class personal_detail:public userpass,public name , public father_name ,public mother_name,public address
{
	long long int mobile_no;
	long long int adhar_no;
	
	char nominee[20];
	int date,month,year;
	
	char ac[40];
	
	public:
	char c;
	int menu_interface();   
	void start_menu_animation();
	int login_page();	
	int sucessful();
	int correction_data_interface(char us[]);
	int correction_data(char us[]);
	void loading();
	bool check_username(char us[], char pw[]);
	int home_page(char us[]);
	int display_info(char us[]);
	bool security(char us[]);
	int home_page_selection(char us[]);
	int menu_interface_selection();
	void menu_animation();
	personal_detail read_from_file(char us[]);

//Take a information from the user
	int getinfo()
	{
		gotoxy(10,0);
		cout<<"*****Fill Personal Detail*****";
		
		gotoxy(0,3);
		cout<<"Enter the First name: ";
		cin.getline(f_name,20);
	
		gotoxy(50,3);
		cout<<"Enter the Last name: ";
		cin.getline(l_name,20);	
		
		gotoxy(0,7);
		cout<<"Enter the Father's First name: ";
		cin.getline(father_f_name,20);
	
		gotoxy(50,7);
		cout<<"Enter the Father's Last name: ";
		cin.getline(father_l_name,20);
		
		
		gotoxy(0,11);
		cout<<"Enter the Mother's First name: ";
		cin.getline(mother_f_name,20);
	
		gotoxy(50,11);
		cout<<"Enter the Mother's Last name: ";
		cin.getline(mother_l_name,20);
		
		gotoxy(0,16);
		cout<<"Phone No.: (+91) ";
		cin>>mobile_no;
		
		
		
		
		gotoxy(29,20);						//20
		cout<<"Date";
		gotoxy(37,20);	//5					//25
		cout<<"Month";
		gotoxy(48,20);		//2				//38
		cout<<"Year";	
		gotoxy(0,22);
		cout<<"Date of Birth ";
		dob();
		date=d;
		month=mo;
		year=y;
		
	
		accounttype();		//calling the function form another program file that is 				
		strcpy(ac,account_type);
	
		cin.ignore();	
		gotoxy(0,29);
		cout<<"Adhaar No.: ";
		cin>>adhar_no;
		cin.ignore();
		
		gotoxy(0,31);
		cout<<"Enter the Name Of Nominee: ";
		cin.getline(nominee,20);
		
		
		address();
		userpas();
		loading();
		sucessful();
		getchar();
		
		return 0;
		
	}
	
	int address()
	{
		system("cls");
		gotoxy(10,0);
		cout<<"*****Address*****";
		
		gotoxy(0,3);
		cout<<"Enter Flat no./House no./Apartment no.: ";
		cin.getline(flat_no,20);
		gotoxy(0,5);
		
		cout<<"Enter Area: ";
		cin.getline(Area,50);
		gotoxy(0,7);
		
		cout<<"Enter Landmark: ";
		cin.getline(landmark,50);
		gotoxy(0,9);
		
		cout<<"Enter City: ";
		cin.getline(city,40);
		gotoxy(0,11);
		
		cout<<"Enter State: ";
		cin.getline(state,40);
		gotoxy(0,13);
		
		cout<<"Enter Pincode: ";
		cin>>pincode;
		cin.ignore();
		
		return 0;
		
	}
	
	int userpas()
	{
		system("cls");
//		assign(username,'\0');
		
		gotoxy(23,2);
			
		cout<<"*************Account Sign Up Page*************";
		gotoxy(23,3);
		cout<<"**********************************************";
		gotoxy(28,6);
		cout<<"==============Sign Up==============";
		gotoxy(30,8);
		cout<<"Enter the Username: ";
		cin.getline(username,40);
			
		gotoxy(30,10);
    	int i = 0;

    	cout << "Enter password: ";
    // Loop to read and mask each character of the password
    	while (true)
    	{
        	char c = getch();  // Read a character without displaying it on the screen
        	if(c == '\r')  // If user presses Enter, terminate the loop
            	break;
            
        	else if (c == '\b')  // If user presses Backspace, erase the last character
        	{
            	if (i > 0)
            	{
                	i--;
                	cout << "\b \b";
            	}
        	}
        	
			else if (i < 99)  // Otherwise, add the character to the password
        	{
            	password[i] = c;
            	i++;
            	cout << "*";
        	}
    	}

    	password[i] = '\0';
		
		
		if(check_username(username, password))
			{
				gotoxy(30,18);
				cout<<"!This username already taken"<<endl;
				gotoxy(31,20);
				cout<<"Press enter for continue";
				for(int i=0;i<20;i++)
				{
					username[i]='\0';
				}
				getchar();
				loading();
				userpas();
				return 0;
			}
			 
		return 0;
	}
	
	void outinfo()
	{
		
		
		gotoxy(0,8);
		cout<<"1.. Name: "<<f_name<<" "<<l_name;	
		
		gotoxy(0,10);
		cout<<"2.. Father's name: "<<father_f_name<<" "<<father_l_name;
		
		gotoxy(0,12);
		cout<<"3.. Mother's name: " <<mother_f_name<<" "<<mother_l_name;
		
		gotoxy(0,14);
		cout<<"4.. Phone No.:"<< mobile_no;
		
		gotoxy(0,16);
		cout<<"5.. Adhaar No.: "<<adhar_no;
		
		gotoxy(0,18);
		cout<<"6.. Account Type: "<<ac;;
		
		gotoxy(0,20);
		cout<<"7.. Name Of Nominee: "<<nominee;
		
		gotoxy(0,22);
		cout<<"8.. Date of Birth: "<<date<<"-"<<month<<"-"<<year;
		
		
		
		
		gotoxy(40,8);
		cout<<"9.. Address:";
		
		gotoxy(44,9);
		cout<<flat_no<<", "<<Area<<", "<<landmark<<endl;
		gotoxy(44,10);
		cout<<city<<", "<<state<<endl;
		gotoxy(44,11);
		cout<<pincode;
		
		gotoxy(40,14);
		cout<<"10.. Username: "<<username;
		
		
		string str;
    	str.assign(strlen(password), '*');
    	gotoxy(40,16);
		cout <<"11.. Password: " <<str << endl;
				gotoxy(10,30);
		
	}		

};

int write_in_file(personal_detail& pd) 
{
	FILE *fp, *fu;
   	fp = fopen("username.txt", "ab");
    fwrite(&pd, sizeof(pd),1, fp);

	// Closing fil
	fclose(fp);
return 0;
}

personal_detail personal_detail::read_from_file(char us[]) {
	personal_detail pd;
	FILE *fp, *fu;
    fp = fopen("username.txt","rb");	
	while (fread(&pd, sizeof(pd),1, fp)) 
	{
		if (strcmp(us,pd.username)== 0) 
		{
			break;
		}
	}
	
    	fclose(fp);
    	return pd;
}


int personal_detail::menu_interface() 
{
//	system("cls");
	
	gotoxy(35,7);
	printf("1.... Creating Account\n");
	gotoxy(35,9);
	printf("2.... Already have an Account ?\n");
	gotoxy(35,11);
	printf("3.... Exit");  
	gotoxy(24,15);
	cout <<"(*)Use " << char(24) << char(25) <<" key for moving a cursor and";
	gotoxy(24,16);
	cout<< "Select the option"<<endl; 
	gotoxy(40,7);
	personal_detail::menu_interface_selection();  
    return 0;
}


int personal_detail::menu_interface_selection() 
{
	int i=40,j=7,a=0;
	while(1)
	{
		a=getch();
		if(a==72)               //up arrow
		{
			if(j>7)
			{
				j-=2;
				gotoxy(i,j);
			}
		}
		
		else if(a==80)               //up arrow
		{
			if(j<11)
			{
				j+=2;
				gotoxy(i,j);
			}
		}
		
		else if(a==13)
		{
			loading();
				
			if(j==7)
			{
				system("cls");
				personal_detail pd;
				pd.getinfo();
				write_in_file(pd);
				menu_animation();
				
			}
			
			else if(j==9)
			{
				login_page();
				break;
				
			}
			
			else if(j==11)
			{
				system("cls");
				gotoxy(23,2);
			cout<<"**************Thanks For Visiting**************";
			gotoxy(23,3);
			cout<<"***********************************************";
			gotoxy(28,6);
			cout<<"==============Verma Bank==============";
			gotoxy(30,8);
			cout<<"Developed By Gautam Verma";
			getchar();
				exit(0);
			}
		}
	
	}
	
}

int personal_detail::login_page() 
{
	system("cls");
	
	char pw[50],c=0,k,us[15],ch;

	FILE *fp, *fu;
    fp = fopen("username.txt","rb");
	
	gotoxy(23,2);
	cout<<"**************Account Login Page**************";
	gotoxy(23,3);
	cout<<"**********************************************";
	gotoxy(28,6);
	cout<<"==============Log In==============";
	gotoxy(30,8);
	printf("Enter the Username : ");
	cin.getline(us,15);
	gotoxy(30,10);
    int i = 0;

    cout << "Enter password: ";
    // Loop to read and mask each character of the password
    while (true)
    {
        char c = getch();  // Read a character without displaying it on the screen

        if (c == '\r')  // If user presses Enter, terminate the loop
            break;
            
        else if (c == '\b')  // If user presses Backspace, erase the last character
        {
            if (i > 0)
            {
                i--;
                cout << "\b \b";
            }
        }
        else if (i < 99)  // Otherwise, add the character to the password
        {
            pw[i] = c;
            i++;
            cout << "*";
        }
    }

    pw[i] = '\0';  // Add null terminator to end of password string


	
	
    if(check_username(us,pw))
    {
		 
				home_page(us);
		}
		
		
		
			
		
		
		while(1)
		{
			gotoxy(33,16);
		cout<<"Press Enter for Continue"<<endl;
			gotoxy(33,17);
		cout<<"Press Esc for Continue"<<endl;
		ch=getch();
		
		if(ch==27)
		{
			loading();
			menu_animation();
			break;
		}
		else if(ch==13){
			login_page();
			break;
		}
	}
	

	
}



int personal_detail::display_info(char us[])
{
	system("cls");
	FILE* fp;
	int choice, i;
	fp = fopen("username.txt", "rb");
	
	personal_detail pd ;
	
	pd=read_from_file(us);

	
		if (pd.check_username(us,pd.password)) 
		{
			
			gotoxy(15,1);
			cout<<"============================User Information============================";
			gotoxy(15,2);
			cout<<"************************************************************************";
	
    		gotoxy(30,4);
			cout<<" Welcome "<<pd.f_name<<" "<<pd.l_name<<" in Verma Bank"<<endl;
		
			pd.outinfo();
			
			
				gotoxy(10,26);
				cout<<"Press enter for back to menu";
					gotoxy(10,27);
				cout <<"2..Use " << "Up" << "Down" <<" key for moving a cursor"<<endl; 
			getchar();
				 home_page(us);
	}
			return 0;
}

int personal_detail::home_page(char us[])
{
	system("cls");
	FILE* fp;
	int choice, i;
	fp = fopen("username.txt", "rb");
	
	personal_detail pd ;
	pd=read_from_file(us);
	if(check_username(us,pd.password))
	{
			gotoxy(15,1);
			cout<<"====================Home Page====================";
			gotoxy(15,2);
			cout<<"*************************************************";
	
    		gotoxy(25,3);
			cout<<"Welcome to "<<pd.f_name<<" "<<pd.l_name<<endl;
			
			gotoxy(20,6);
			cout<<"1....Check Balance.(Under Progress)"<<endl;
			gotoxy(20,7);
			cout<<"2....Transfer money.(Under Progress)"<<endl;
			gotoxy(20,8);
			cout<<"3....Display Data."<<endl;
			gotoxy(20,9);
			cout<<"4....Change Data."<<endl;
			gotoxy(20,10);
			cout<<"5....log out."<<endl;
			gotoxy(20,11);
			cout<<"6....Go to Menu."<<endl;
			home_page_selection(us);
				
		}
		return 0;
}

int personal_detail::home_page_selection(char us[])
{
	
	int a,i=19,j=6;
	while(1)
	{
	a=getch();
	
	if(a==72)        			//UP Key
	{
		if(j>6)
		{
		j--;
		gotoxy(i,j);	
		}	
	}	
	else if(a==80)
	{
		if(j<11)
		{
			j++;
			gotoxy(i,j);
		}
	}
	
	else if(a==13)
	{
		if(j==6)
		{
			system("cls");
			cout<<"Amount "<<endl;
			home_page(us);
		}
		
		else if(j==7)
		{
			system("cls");
			cout<<"Transfer amount "<<endl;
			home_page(us);
		}
		
		else if(j==8)
		{
			system("cls");
			 display_info(us);
			break;
		}
		
		else if(j==9)
		{
			system("cls");
			correction_data_interface(us);
			break;
			
		}
		
		else if(j==10)
		{
			system("cls");
			loading();
			login_page();
		}
		
		else if(j==11)
		{
			system("cls");
			loading();
			menu_animation();
		}
	}
}
	
	
}
int personal_detail::correction_data_interface(char us[])
{
	system("cls");
	FILE* fp;
	int choice, i;
	fp = fopen("username.txt", "rb");
	
	personal_detail pd ;
	pd=read_from_file(us);
	
			if (check_username(us,pd.password)) 
		{
			gotoxy(5,1);
			cout<<"====================User's Information====================";
			gotoxy(5,2);
			cout<<"**********************************************************";
	
    		gotoxy(15,3);
			cout<<"Welcome to "<<pd.f_name<<" "<<pd.l_name<<endl;
			
			pd.outinfo();
			
				gotoxy(10,26);
				cout<<"1..Press esc for back to menu";
			gotoxy(10,27);
				cout <<"2..Use " << "Up" << "Down" <<" key for moving a cursor"<<endl; 
			gotoxy(10,28);
				cout <<"3..Press Enter When you to change the Info "<<endl;
			correction_data(us);
	}
	return 0;
	
		
}



bool personal_detail::check_username(char us[], char pw[])
{
	FILE* fp;
	int choice, i;
	fp = fopen("username.txt", "rb");
	
	personal_detail pd ;
	pd=read_from_file(us);
		if (strcmp(us,pd.username)== 0) 
		{
			personal_detail pd;
			pd=read_from_file(us);
		 		if (strcmp(pw,pd.password)== 0 )
		 		{
		 			loading();
		 			system("cls");
					return true;
				}
			
				else
				{
					gotoxy(30,14);
					cout<<"! Please Write a Valid Password ";		
					return false;
				}
						
		}
		else
		{
			gotoxy(30,14);
			cout<<"! Please Write a Valid Username ";
			return false;
		}
	
	return false;
}
 




void personal_detail::start_menu_animation()
{
	system("cls");
	personal_detail pd;
	string header = "Welcome To Verma Bank    ";
	string footer = "Develoved By Gautam Verma"; 
	int u=32;
//
		
		for(int l = 20; l<71; l++)
		{
			for(long long int j=0;j<2000000;j++)
			{
				j++;
				j--;
			}
			gotoxy(l,2);
			printf("*");
			gotoxy(l,4);
			printf("=");
		
			gotoxy(l,20);
			printf("*");
			gotoxy(l,22);
			printf("=");
		}
	
		for(int l = 3; l<23; l++)
		{
			for(long long int j=0;j<20000000;j++)
		{
			j++;
			j--;
		}
			
			gotoxy(20,l);
			printf("*");
			gotoxy(70,l);
			printf("*");
		
	}

		
		for (int k = 0; header[k]!='\0' && footer[k]!='\0'; k++)
		{
			
			for(long long int j=0;j<20000000;j++)
		{
			j++;
			j--;
		}
			gotoxy(u,3);
      		printf("%c",header[k]);
      		
      		
			gotoxy(u,21);
      		printf("%c",footer[k]);
      		u++;
	}

		
//	}
	
	
	pd.menu_interface();
}


int main()
{
	
	
	personal_detail pd;
	pd.start_menu_animation();
    return 0;
}



void personal_detail::menu_animation()
{
	system("cls");
	personal_detail pd;
	string header = "Welcome To Verma Bank    ";
	string footer = "Develoved By Gautam Verma"; 
	int u=32;
//	for(int i=0;i<4;i++)
//	{
		
		for(int l = 20; l<71; l++)
		{
			
			
			gotoxy(l,2);
			printf("*");
			gotoxy(l,4);
			printf("=");
		
			gotoxy(l,20);
			printf("*");
			gotoxy(l,22);
			printf("=");
		}
	
		for(int l = 3; l<23; l++)
		{
		
			
			gotoxy(20,l);
			printf("*");
			gotoxy(70,l);
			printf("*");
		
	}

		
		for (int k = 0; header[k]!='\0' && footer[k]!='\0'; k++)
		{
			
			gotoxy(u,3);
      		printf("%c",header[k]);
      		
      		
			gotoxy(u,21);
      		printf("%c",footer[k]);
      		u++;
	}

		
//	}
	
	
	pd.menu_interface();
}
	







bool personal_detail::security(char us[])
{
	system("cls");
	
	char pw[50],c=0,k,us1[15];
	
	FILE *fp, *fu;
    fp = fopen("username.txt","rb");
	
	gotoxy(23,2);
	cout<<"**************Account Login Page**************";
	gotoxy(23,3);
	cout<<"**********************************************";
	gotoxy(23,6);
	cout<<"*=============For Security Reason=============*";
	gotoxy(30,10);
	printf("Enter the Username : ");
	cin.getline(us1,15);
	gotoxy(30,12);
    int i = 0;
    cout << "Enter password: ";
    // Loop to read and mask each character of the password
    while (true)
    {
        char c = getch();  // Read a character without displaying it on the screen

        if (c == '\r')  // If user presses Enter, terminate the loop
            break;
            
        else if (c == '\b')  // If user presses Backspace, erase the last character
        {
            if (i > 0)
            {
                i--;
                cout << "\b \b";
            }
        }
        else if (i < 99)  // Otherwise, add the character to the password
        {
            pw[i] = c;
            i++;
            cout << "*";
        }
    }

    pw[i] = '\0';  // Add null terminator to end of password string


	
	if(strcmp(us,us1)== 0)
	{
    	if(check_username(us,pw))
    	{
    		return true;
		}
		
		else
		{
				return false;	
		}
	
	}

	else
	{
		return false;	
	}
}

	
int personal_detail::correction_data(char us[])
{
//	personal_detail pd ;
//	pd=read_from_file();
	
	int a,i=0,j=8;
	while(1)
	{
	a=getch();
	
	if(a==72)        			//UP Key
	{
		if(j>8 && i==0)
		{
		j-=2;
		gotoxy(i,j);	
		}
		else if(i==40 && j>8)
		{
			if(j==14)
			{
			j-=6;
			}
			else
			{
				j-=2;
			}
//			j-=6;
			gotoxy(i,j);
			
		}	
	}
	else if(a==80)			//Down Key
	{
		if(j<22 && i==0)
		{
			j+=2;
			gotoxy(i,j);
		}
		else if(i==40 && j<16)
		{
			if(j<14)
			{
			j+=6;
			}
			else
			{
				j+=2;
			}
			gotoxy(i,j);
		}
	}
	else if(a==77)
	{
		if(i<40 )
		{
			j=8;
			i+=40;
			gotoxy(i,j);
		}
	}
	
	
	else if(a==75)
	{
		if(i>0)
		{
			j=8;
			i-=40;
			gotoxy(i,j);
		}
	}
	else if(a==27)
	{
		system("cls");
		home_page(us);
	}
	
	else if(a==13)
	{
		if(j==8 && i==0)
		{
			system("cls");
			int ch=0;
			
    		
    		if(security(us))
    		{
    			ch=1;
    		}
    
    		if(ch==1)
    		{
    			system("cls");
    			FILE *fp,*fa;
				personal_detail pd;
			
				fp = fopen("username.txt", "rb+");
    			
			
				while (fread(&pd, sizeof(personal_detail), 1, fp)) {
        			if (strcmp(pd.username, us)==0)  {
        				cout<<"Hii";
            			break;
        			}}
			
			
				gotoxy(23,2);
				cout<<"**************Correction in Name**************";
				gotoxy(23,3);
				cout<<"**********************************************";
			
				gotoxy(30,8);
				cout<<"Enter the First name: ";
				cin.getline(pd.f_name,20);
				gotoxy(30,10);
				cout<<"Enter the LAst name: ";
				cin.getline(pd.l_name,20);
			
    			fseek(fp, -static_cast<long long>(sizeof(personal_detail)), SEEK_CUR);
    			fwrite(&pd, sizeof(personal_detail), 1, fp);

    			fclose(fp);
    			system("cls");
    			correction_data_interface(us);
    			break;
}


}
			
				
		
	
		
		else if(j==10 && i==0)
		{
			system("cls");
			int ch=0;
			
    		
    		if(security(us))
    		{
    			ch=1;
    		}
    
    		if(ch==1)
    		{
    			system("cls");
				personal_detail pd;
				FILE *fp;

			fp = fopen("username.txt", "rb+");
			if (!fp) {
    			cout << "Error opening file" << endl;
    			getchar();
    			return 1;
			}

			bool found = false;

			while (fread(&pd, sizeof(personal_detail), 1, fp)) {
        			if (strcmp(pd.username, us)==0)  {
        				cout<<"Hii";
            			break;
        			}} 
        			
    			
    			gotoxy(23, 2);
    			cout << "**************Correction in Father Name**************" << endl;
    			gotoxy(23, 3);
    			cout << "**********************************************" << endl;
    			gotoxy(30, 8);
    			cout << "Enter the Father First name: ";
    			cin.getline(pd.father_f_name, 20);
    			gotoxy(30, 10);
    			cout << "Enter the FAther Last name: ";
    			cin.getline(pd.father_l_name, 20);

    			fseek(fp, -static_cast<long long>(sizeof(personal_detail)), SEEK_CUR);
    			if (fwrite(&pd, sizeof(personal_detail), 1, fp) != 1) {
        		cout << "Error writing to file" << endl;
        		fclose(fp);
        		return 1;
    			}
			

			fclose(fp);
			system("cls");
    		correction_data_interface(us);
    		break;
			}
		}
	
	else if(j==12 && i==0)
	{
		system("cls");
			int ch=0;
			
    		
    		if(security(us))
    		{
    			ch=1;
    		}
    
    		if(ch==1)
    		{
    			system("cls");
    			FILE *fp,*fa;
				personal_detail pd;
			
				fp = fopen("username.txt", "rb+");
    			
			
				while (fread(&pd, sizeof(personal_detail), 1, fp)) {
        			if (strcmp(pd.username, us)==0)  {
        				cout<<"Hii";
            			break;
        			}}
			
			
				gotoxy(23,2);
				cout<<"**********Correction in Mother Name**********";
				gotoxy(23,3);
				cout<<"**********************************************";
			
				gotoxy(30,8);
				cout<<"Enter the Mother's First name: ";
				cin.getline(pd.mother_f_name,20);
				gotoxy(30,10);
				cout<<"Enter the Mother's Last name: ";
				cin.getline(pd.mother_l_name,20);
			
    			fseek(fp, -static_cast<long long>(sizeof(personal_detail)), SEEK_CUR);
    			fwrite(&pd, sizeof(personal_detail), 1, fp);

    			fclose(fp);
    			system("cls");
    			correction_data_interface(us);
    			break;
		}
	}
	
	else if(j==14 && i==0)
	{
		system("cls");
			int ch=0;
			
    		
    		if(security(us))
    		{
    			ch=1;
    		}
    
    		if(ch==1)
    		{
    			system("cls");
    			FILE *fp,*fa;
				personal_detail pd;
			
				fp = fopen("username.txt", "rb+");
    			
			
				while (fread(&pd, sizeof(personal_detail), 1, fp)) {
        			if (strcmp(pd.username, us)==0)  {
            			break;
        			}}
			
			
				gotoxy(23,2);
				cout<<"*********Correction in Mobile Number*********";
				gotoxy(23,3);
				cout<<"**********************************************";
			
				gotoxy(30,8);
				cout<<"Enter the new Mobile number: ";
				cin>>pd.mobile_no;
				cin.ignore();
    			fseek(fp, -static_cast<long long>(sizeof(personal_detail)), SEEK_CUR);
    			fwrite(&pd, sizeof(personal_detail), 1, fp);

    			fclose(fp);
    			system("cls");
    			correction_data_interface(us);
    			break;
		}
	} 
	
	else if(j==16 && i==0)
	{
		system("cls");
			int ch=0;
			
    		
    		if(security(us))
    		{
    			ch=1;
    		}
    
    		if(ch==1)
    		{
    			system("cls");
    			FILE *fp,*fa;
				personal_detail pd;
			
				fp = fopen("username.txt", "rb+");
    			
			
				while (fread(&pd, sizeof(personal_detail), 1, fp)) {
        			if (strcmp(pd.username, us)==0)  {
            			break;
        			}}
			
			
				gotoxy(23,2);
				cout<<"**********Correction in Adhar Number**********";
				gotoxy(23,3);
				cout<<"**********************************************";
			
				gotoxy(30,8);
				cout<<"Enter the new Adhar number: ";
				cin>>pd.adhar_no;
				cin.ignore();
    			fseek(fp, -static_cast<long long>(sizeof(personal_detail)), SEEK_CUR);
    			fwrite(&pd, sizeof(personal_detail), 1, fp);

    			fclose(fp);
    			system("cls");
    			correction_data_interface(us);
    			break;
	}
	}
	
	else if(j==18 && i==0)
	{
		system("cls");
				int ch=0;
    			FILE *fp,*fa;
				personal_detail pd;
			
					if(security(us))
    		{
    			ch=1;
    		}
    
    		if(ch==1)
    		{
				fp = fopen("username.txt", "rb+");
    			
			
				while (fread(&pd, sizeof(personal_detail), 1, fp)) {
        			if (strcmp(pd.username, us)==0)  {
        				
            			break;
        			}}
			
					system("cls");
				gotoxy(23,2);
				cout<<"**********Correction in Account Type**********";
				gotoxy(23,3);
				cout<<"**********************************************";
			
				gotoxy(30,8);
				cout<<"Select the new Account Type: ";
				accounttype();
		
				strcpy(pd.ac,account_type);
    			fseek(fp, -static_cast<long long>(sizeof(personal_detail)), SEEK_CUR);
    			fwrite(&pd, sizeof(personal_detail), 1, fp);

    			fclose(fp);
    			system("cls");
    			correction_data_interface(us);
    			break;
			}
	}
	
	else if(j==20 && i==0)
	{
		system("cls");
    			FILE *fp,*fa;
    			int ch=0;
				personal_detail pd;
			
			
					if(security(us))
    				{
    					ch=1;
    				}
    
    				if(ch==1)
    				{
				fp = fopen("username.txt", "rb+");
    			
			
				while (fread(&pd, sizeof(personal_detail), 1, fp)) {
        			if (strcmp(pd.username, us)==0)  {
        				
            			break;
        			}}
			
				system("cls");
				gotoxy(23,2);
				cout<<"**********Correction in Nomienee name**********";
				gotoxy(23,3);
				cout<<"**********************************************";
			
				gotoxy(30,8);
				cout<<"Enter the new Nomeniee: ";
				cin.getline(pd.nominee,20);
		
				strcpy(pd.ac,account_type);
    			fseek(fp, -static_cast<long long>(sizeof(personal_detail)), SEEK_CUR);
    			fwrite(&pd, sizeof(personal_detail), 1, fp);

    			fclose(fp);
    			system("cls");
    			correction_data_interface(us);
    			break;
		}
	}
	
	else if(j==22 && i==0)
	{
		system("cls");
    			int ch=0;
				FILE *fp,*fa;
				personal_detail pd;
				if(security(us))
    			{
    				ch=1;
    			}
    
    		if(ch==1)
    		{
				fp = fopen("username.txt", "rb+");
    			
			
				while (fread(&pd, sizeof(personal_detail), 1, fp)) 
				{
        			if (strcmp(pd.username, us)==0)  
					{
        				
            			break;
        			}
				}
					
				system("cls");
			
				gotoxy(23,2);
				cout<<"**********Correction in Date of Birth**********";
				gotoxy(23,3);
				cout<<"**********************************************";
			
				gotoxy(30,8);
				cout<<"Select the new Date Of Birth: ";
				gotoxy(30,14);
				dob();
				pd.date=d;
				pd.month=mo;
				pd.year=y;
		
				strcpy(pd.ac,account_type);
    			fseek(fp, -static_cast<long long>(sizeof(personal_detail)), SEEK_CUR);
    			fwrite(&pd, sizeof(personal_detail), 1, fp);

    			fclose(fp);
    			system("cls");
    			correction_data_interface(us);
    			break;
			}
	}
	
	
	else if(j==8 && i==40)
	{
		system("cls");
    			int ch=0;
				FILE *fp,*fa;
				personal_detail pd;
				if(security(us))
    			{
    				ch=1;
    			}
    
    		if(ch==1)
    		{
				fp = fopen("username.txt", "rb+");
    			
			
				while (fread(&pd, sizeof(personal_detail), 1, fp)) 
				{
        			if (strcmp(pd.username, us)==0)  
					{
        				
            			break;
        			}
				}
					
				system("cls");
			
				gotoxy(23,2);
				cout<<"**********Correction in Address**********";
				gotoxy(23,3);
				cout<<"**********************************************";
			
				gotoxy(30,8);
				cout<<"Enter the New Address ";
				gotoxy(30,14);
				cout<<"Press Enter key ";
				getchar();
				pd.address();
		
				strcpy(pd.ac,account_type);
    			fseek(fp, -static_cast<long long>(sizeof(personal_detail)), SEEK_CUR);
    			fwrite(&pd, sizeof(personal_detail), 1, fp);

    			fclose(fp);
    			system("cls");
    			correction_data_interface(us);
    			break;
			}
	}
	
	
	
	
}
	else if(a==27)
	{
		system("cls");
		loading();
		system("cls");
		home_page(us);
	}
}
return 0;
}




void personal_detail::loading()
{
		system("cls");
		gotoxy(10, 15);
		printf("Please Wait\n");
		gotoxy(10, 16);
		for (int i = 0; i < 70; i++) 
		{	
			for (int j = 0; j< 1000000; j++) 
			{
				j++;
				j--;
			}
			printf("*");
		}
}

int personal_detail::sucessful()
{
	system("cls");
	gotoxy(24, 4);
	cout<<"*************************************************************";
	gotoxy(24, 5);
	cout<<"****************Thanks For Creating a Account****************";
	gotoxy(24, 6);
	cout<<"*************************************************************";

	gotoxy(35, 15);
	cout<<"Created Account Succesfully";
	
	
	
	gotoxy(30, 18);
	cout<<"Press Enter For Continue";
	
	return 0;
}



