#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
using namespace std;

struct person
{
    string name;
    string number;
    string address;
	string G_Mail;
};

class phonebook
{
	person contact;
	fstream filein;
    fstream fileout;
    fstream tempFile;
public:
	void menu();
	void addContact();
	void listContacts();
	void searchContact();
	void modifyContact();
	void deleteContact();
	void color(int colour);
	person check(person info);
};

int main()
{
	phonebook contact;
	system("color 0f");
    contact.menu();
}

void phonebook::menu()
{
	system("cls");
    cout<<"\n\t\t    ************************************";
    color(8);
	cout<<"\n\n\t\t\t___ WELCOME TO PHONEBOOK ___\n";
	color(5);
	cout<<"\n\t\t    ************************************";
	color(3);
	cout<<"\n\n\t__ MENU __\n";
	color(5);
	cout<<"\n\n\t1. Add Contact"
		<<"\n\n\t2. List"
		<<"\n\n\t3. Search"
		<<"\n\n\t4. Modify"
		<<"\n\n\t5. Delete"
		<<"\n\n\t6. Exit"
		<<"\n\n\t\t Enter Your Choice: ";
	
	switch(getch())
	{
    	case '1': addContact();break;
    	case '2': listContacts();break;
    	case '3': searchContact();break;
    	case '4': modifyContact();break;
    	case '5': deleteContact();break;
    	case '6': system("cls");
				  color(8);
				  cout<<"\n\n\n\n\n\n\t\t Thank You! ";
				  color(5);
				  cout<<"for using Phonebook.\n\n\n\n\n\n";
				  exit(0);break;
    	default:
			system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout<<"\n\n\t\t__ Invalid Choice! __";
			color(5);
			cout<<"\n\n\n\tPlease Enter your Choice between 1 to 6!"
            	<<"\n\n Press Any key to Continue...";
			getch();
			menu();        
    }
}

void phonebook::addContact()
{
	system("cls");
	color(3);
	cout<<"\n\n\t\t__ 1. New Contact __";
	color(5);
    cout<<"\n\n\n Provide the Contact Information:";
	cout<<"\n\n\t\t Name: ";
    getline(cin,contact.name);
	cout<<"\n\t\t Number: ";
	getline(cin,contact.number);
	color(8);
	cout<<"\n   Optional: \n";
	color(5);
	cout<<"\n\t\t Address: ";
    getline(cin,contact.address);
	cout<<"\n\t\t G-Mail: ";
    getline(cin,contact.G_Mail);
	cout<<endl;
	contact=check(contact);

	filein.open("filein.txt",ios::app);
	fileout.open("fileout.txt",ios::app);
	filein<<contact.name<<endl;
	fileout<<contact.name<<endl;
	filein<<contact.number<<endl;
	fileout<<contact.number<<endl;
	filein<<contact.address<<endl;	
	fileout<<contact.address<<endl;
	filein<<contact.G_Mail<<endl;
	fileout<<contact.G_Mail<<endl;
	color(8);
	cout<<"\n\n Contact Saved!!!";
	color(5);
    filein.close();
	fileout.close();
	cout<<"\n\n Press any key...";
	getch();
	menu();
}

void phonebook::listContacts()
{
	system("cls");
	int i=1;
	filein.open("filein.txt");
	color(3);
	cout<<"\n\n\t\t__ 2. List of Contacts __";
	color(5);
	while(getline(filein,contact.name))
	{
		if(contact.name!="")
		{
			color(8);
			cout<<"\n\n\n\tContact  "<<i<<":"<<endl;
			color(5);
			cout<<"\n\t\t   Name: "<<contact.name;
			getline(filein,contact.number);
			cout<<"\n\t\t Number: "<<contact.number;
			getline(filein,contact.address);
			cout<<"\n\t\tAddress: "<<contact.address;
			getline(filein,contact.G_Mail);
			cout<<"\n\t\t E-Mail: "<<contact.G_Mail;
			i++;
		}	
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
						FOREGROUND_RED | FOREGROUND_INTENSITY);
	if(i==1)
	cout<<"\n\n\n\tSorry! No Contact found.\n";
	color(5);
	filein.close();
	cout<<"\n\n   Press any key...";
	getch();
	menu();
}

void phonebook::searchContact()
{
	system("cls");
	int i=0;
	string temp;
	filein.open("filein.txt");
	color(3);
	cout<<"\n\n\t\t__ 3. Search Contact __";
	color(5);
	cout<<"\n\n\n Enter Contact name to 'Search': ";
	getline(cin,temp);
	while(getline(filein,contact.name))
	{
		if(contact.name==temp)
		{
			color(8);
			cout<<"\n\n Searched contact is: \n";
			color(5);
			cout<<"\n\t\t\t   Name: "<<contact.name<<endl;
			getline(filein,contact.number);
			cout<<"\n\t\t\t Number: "<<contact.number<<endl;
			getline(filein,contact.address);
			cout<<"\n\t\t\tAddress: "<<contact.address<<endl;
			getline(filein,contact.G_Mail);
			cout<<"\n\t\t\t E-Mail: "<<contact.G_Mail<<endl;
			i++;
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
						 FOREGROUND_RED | FOREGROUND_INTENSITY);
	if(i==0)
	cout<<"\n\n\tSorry! No Contact found.\n";
	color(5);
	filein.close();
	cout<<"\n\n   Press any key...";
	getch();
	menu();
}

void phonebook::modifyContact()
{
	system("cls");
	string temp,replace;
	tempFile.open("tempFile.txt");
	filein.open("filein.txt");
	fileout.open("fileout.txt");
	int i=0;
	
	while(getline(filein,temp))
    {
        tempFile<<temp<<endl;
    }
	filein.close();
	filein.open("filein.txt");
	tempFile.close();
	tempFile.open("tempFile.txt");
	color(3);
	cout<<"\n\n\t\t__ 4. Modify Contact __";
    color(5);
    
	cout<<"\n\n\n Enter Contact name to 'Modify': ";
    getline(cin,replace);
    while(getline(tempFile,temp))
    {
        if(temp==replace)
		{
            cout<<"\n\n Provide the Contact New Information:"
				<<"\n\n\t\t  Name: ";
			getline(cin,contact.name);
			cout<<"\n\t\t  Number: ";
			getline(cin,contact.number);
			color(8);
			cout<<"\n   Optional: \n";
			color(5);
			cout<<"\n\t\t  Address: ";
    		getline(cin,contact.address);
			cout<<"\n\t\t  E-Mail: ";
    		getline(cin,contact.G_Mail);
        	contact=check(contact);
			color(8);
			cout<<"\n\n Contact Modified!!!";
			color(5);
			i=1;
        }
        
        while(i>0 && i<5)
        {
        	if(i==1)
        	temp=contact.name;
        	else if(i==2)
        	temp=contact.number;
        	else if(i==3)
        	temp=contact.address;
			else if(i==4)
        	temp=contact.G_Mail;
        	i++;
        	break;
		}
		temp += "\n";
        fileout<<temp;
	}
	tempFile.close();
	filein.close();
	fileout.close();
	filein.open("filein.txt");
	fileout.open("fileout.txt");
	while(getline(fileout,temp))
    {
        filein<<temp<<endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
						 FOREGROUND_RED | FOREGROUND_INTENSITY);
    if(i==0)
	cout<<"\n\n\tSorry! No Contact found.";
	color(5);
    filein.close();
	fileout.close();
	cout<<"\n\n Press any key...";
	getch();
	menu();
}
	
void phonebook::deleteContact()
{
	system("cls");
	int i=0;
	string temp,del;
	color(3);
	cout<<"\n\n\t\t__ 5. Delete Contact __";
	color(5);
	cout<<"\n\n   Please select an Option:"
		<<"\n\n\t1. Delete One \t2. Delete All"
		<<"\n\n\tChoice: ";
	switch(getch())
	{
		case '1': 	filein.open("filein.txt");
					fileout.open("fileout.txt",ios::out);
					cout<<"\n\n\n Enter Contant Name to 'Delete': ";
					getline(cin,del);
					while(getline(filein,temp))
					{
        				if(temp==del)
						i=1;
        				while(i>0 && i<5)
        				{
			        		temp="";
        					i++;
        					break;
        				}
						if(i==0 || i>=5)
						{
							temp += "\n";
							fileout<<temp;
    					}
					}
					filein.close();
					fileout.close();
					filein.open("filein.txt",ios::out);
					fileout.open("fileout.txt");
   
					while(getline(fileout,temp))
    				{
        				filein<<temp<<endl;
					}
    				if(i==0)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
						cout<<"\n\n\n\tSorry! No Contact found.";
						color(5);
					}
					else
    				{
						color(8);
						cout<<"\n\n Contact Deleted!!!";
						color(5);
					}
					break;
		
		case '2':	while(getline(filein,temp))
					{
						filein.open("filein.txt");
						fileout.open("fileout.txt");
					}
					remove("filein.txt");
					remove("fileout.txt");
					color(8);
					cout<<"\n\n All Contacts Deleted!!!";
					color(5);
					break;
	}
	filein.close();
	fileout.close();
	cout<<"\n\n Press any key...";
	getch();
	menu();
}

person phonebook::check(person info)
{
	int j=0;
	
	// Name Verification:
	string tempInfo;
	filein.open("filein.txt");
	while(1)
	{
		if(info.name=="")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout<<"\n   Name can not be Empty!";
			color(5);
			cout<<"\n\t\t   Name: ";
			getline(cin,info.name);
			continue;
		}
		filein.close();
		filein.open("filein.txt");
		while(getline(filein,tempInfo))
		{
			if(info.name==tempInfo)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout<<"\n   This Name already Exist, Please choose a different one!";
				color(5);
				cout<<"\n\t\t   Name: ";
				getline(cin,info.name);
				continue;
			}
		}
		for(int i=0; info.name[i]!='\0'; i++)
		{
			if(isalpha(info.name[i]))
			j=1;
		}
		if(j!=1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout<<"\n   Name must consist of Alphabet!";
			color(5);
			cout<<"\n\t\t   Name: ";
			getline(cin,info.name);
		}
		else
		break;
	}
	filein.close();
	
	// Number Verification:
	j=0;
	while(1)
	{
		if(info.number=="")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout<<"\n   Number can not be Empty!";
			color(5);
			cout<<"\n\t\t Number: ";
			getline(cin,info.number);
			continue;
		}
		for(int i=0; info.number[i]!='\0'; i++)
		{
			if(!isdigit(info.number[i]))
			j=1;	
		}
		if(j==1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout<<"\n   You must enter Digits only!";
			color(5);
			cout<<"\n\t\t Number: ";
			getline(cin,info.number);
			j=0;
		}
		else
		break;
	}
	
	// Address Verification:
	j=0;
	while(1)
	{
		if(info.address=="")
		{
			info.address="N/A";
			break;
		}
		for(int i=0; info.address[i]!='\0'; i++)
		{
			if(isdigit(info.address[i]))
			j=1;	
		}
		if(j==1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout<<"\n   Address can not contain Digits!";
			color(5);
			cout<<"\n\t\tAddress: ";
			getline(cin,info.address);
			j=0;
		}
		else
		break;
	}

	// G_Mail Verification:
	j=0;
	int length,special=0,space=0;
	char temp[11];
	char cmp[11] = {'@','g','m','a','i','l','.','c','o','m','\0'};
	while(1)
	{
		
		if(info.G_Mail=="")
		{
			info.G_Mail="N/A";
			break;
		}
		for (int i=0; info.G_Mail[i]!='\0'; i++)
		{
			// Special character '@' check:
			if (isalpha(info.G_Mail[i])==0 && isdigit(info.G_Mail[i])==0 && info.G_Mail[i]=='@')
			special++;
			if(special>0)
			{
				temp[j]=info.G_Mail[i];
				j++;
			}
			if(isspace(info.G_Mail[i]))
			space++;
			length++;
		}
		temp[10]='\0';
		if(j>0)
		{
			for (int i=0; temp[i]!=0; i++)
			if(temp[i]!=cmp[i])
			j=1;
		}
		if(length<=5 || length>=30)
		{
			length=0;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout<<"\n   G_Mail Username must be 6-30 characters long!";
			color(5);
			cout<<"\n\t\t G_Mail: ";
		    getline(cin,info.G_Mail);		
		}
		else if(special==0 || j==1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout<<"\n   G_Mail must contain '@gmail.com'.";
			color(5);
			cout<<"\n\t\t G_Mail: ";
		    getline(cin,info.G_Mail);		
		}
		else if(space>0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout<<"\n   Spaces are not allowed!";
			color(5);
			cout<<"\n\t\t G_Mail: ";
		    getline(cin,info.G_Mail);
		}
		else
		break;
	}
	return info;
}

void phonebook::color(int colour) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour | 10);
}
