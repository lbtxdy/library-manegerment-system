#include<iostream>
#include<string>
#include<stdio.h>
#include <stdlib.h>
#include"Manager.h"
#include"Student.h"
using namespace std;

void ScreenofStudentStart(Student a)
{
	system("cls");
	cout<<"    ----------------------------------------------------------------    "<<endl;
	cout<<"   |  Welcome,";a.showInfo();
	cout<<"   |     Please select what you want to do:                         |   "<<endl;
	cout<<"   |                                                                |   "<<endl;
	cout<<"   |       (1) Change my name                                       |   "<<endl;
	cout<<"   |       (2) Change my password                                   |   "<<endl;
	cout<<"   |                                                                |   "<<endl;
	cout<<"   |  Press the number above to continue or 'q'/'Q' to exit         |   "<<endl;
	cout<<"    ----------------------------------------------------------------    "<<endl;
	cout<<"   Now enter:";
}
Student EntryofStudent()
{
	while(1)
	{
		char preNum[12];
		char prePassword[7];
		cout<<"Please enter your ID(11-digit):";
		cin>>preNum;
		cout<<"Please enter your password(6-digit):";
		cin>>prePassword;
		
		int Findflag=0;
		int Pass=0;
		FILE*fp;
		fp=fopen("Student.txt","r+");
		char s[100];
		char Num[12]={'\0'};
		char Password[7]={'\0'};
		char name[20]={'\0'};
		fgets(s,100,fp);
		while(s[0]!='*')
		{
			if(s[0]!='#')
			{
				int i;
				strncpy(Num,s,11);
				Num[11]='\0';
				for(i=14;i<=19;i++)
					Password[i-14]=s[i];
				Password[6]='\0';
				//for(i=0;i<19;i++)
				//	name[i]=' ';
				for(i=21;s[i]!='\n';i++)
					name[i-21]=s[i];
			
				name[i-21]='\0';
			
				if(strcmp(preNum,Num)==0)
				{
					Findflag=1;
					if(strcmp(Password,prePassword)==0)
					{
						Pass=1;
					}
					break;
				}
					fgets(s,100,fp);
			}
				else
				fgets(s,100,fp);	
		}
		fclose(fp);
		if(Findflag==0)
		{
			cout<<"Error:The ID does not exist!"<<endl;
		}
		if(Findflag==1)
		{
			if(Pass==0)
			{
				cout<<"Error:The password is wrong!"<<endl;
			}
			else
			{
				string name_=name;
				string Num_=Num;
				string Password_=Password;
				Student t(name_,Num_,Password_,s[12]);
				cout<<"Successfully load in!"<<endl;
				cout<<"Press any key to continue!";
				fflush(stdin);
				char temp=getchar();
				return t;
			}
				
		
		}
	}
}
extern void FuncofStudent()
{
	Student preStu(EntryofStudent());
	while(1)
	{
		int ExitFlag=0;
		ScreenofStudentStart(preStu);
		
		fflush(stdin);
		char Select;
		Select=getchar();
		switch(Select)
		{
			case '1':system("cls");preStu.changeName();break;
			case '2':system("cls");preStu.changePassword();break;
			case 'q':
			case 'Q':ExitFlag=1;break;
			default:cout<<"Error!:Press '1' or '2' to continue or press 'q'or 'Q' to exit"<<endl;		
		}
		if(ExitFlag==1)
			break;	
	}
}
void ScreenofManagerStart(Manager a)
{
	system("cls");
	cout<<"    ----------------------------------------------------------------    "<<endl;
	cout<<"   |  Welcome,";a.showInfo();
	cout<<"   |     Please select what you want to do:                         |   "<<endl;
	cout<<"   |                                                                |   "<<endl;
	cout<<"   |       (1)  Change my name                                      |   "<<endl;
	cout<<"   |       (2)  Change my password                                  |   "<<endl;
	cout<<"   |       (3)  List the books borrowed                             |   "<<endl;
	cout<<"   |       (4)  List all the books                                  |   "<<endl;
	cout<<"   |       (5)  Add/Delete Book                                     |   "<<endl;
	cout<<"   |       (6)  Allow to return                                     |   "<<endl;
	cout<<"   |       (7)  Allow to borrow                                     |   "<<endl;
	cout<<"   |       (8)  Add/Delete Student                                  |   "<<endl;
	cout<<"   |       (9)  List all Students                                   |   "<<endl;
	cout<<"   |                                                                |   "<<endl;
	cout<<"   |  Press the number above to continue or 'q'/'Q' to exit         |   "<<endl;
	cout<<"    ----------------------------------------------------------------    "<<endl;
	cout<<"   Now enter:";
}
Manager EntryofManager()
{
	while(1)
	{
		char preNum[12];
		char prePassword[7];
		cout<<"Please enter your ID(3-digit):";
		cin>>preNum;
		cout<<"Please enter your password(6-digit):";
		cin>>prePassword;
		
		int Findflag=0;
		int Pass=0;
		FILE*fp;
		fp=fopen("Manager.txt","r+");
		char s[100];
		char Num[4]={'\0'};
		char Password[7]={'\0'};
		char name[20]={'\0'};
		fgets(s,100,fp);
		while(s[0]!='*')
		{
				int i;
				strncpy(Num,s,3);
				Num[3]='\0';
				for(i=4;i<=9;i++)
					Password[i-4]=s[i];
				Password[6]='\0';
				//for(i=0;i<19;i++)
				//	name[i]=' ';
				for(i=11;s[i]!='\n';i++)
					name[i-11]=s[i];
			
				name[i-11]='\0';
			
				if(strcmp(preNum,Num)==0)
				{
					Findflag=1;
					if(strcmp(Password,prePassword)==0)
					{
						Pass=1;
					}
					break;
				}
					fgets(s,100,fp);
			
					
		}
		fclose(fp);
		if(Findflag==0)
		{
			cout<<"Error:The ID does not exist!"<<endl;
		}
		if(Findflag==1)
		{
			if(Pass==0)
			{
				cout<<"Error:The password is wrong!"<<endl;
			}
			else
			{
				string name_=name;
				string Num_=Num;
				string Password_=Password;
				Manager t(name_,Num_,Password_);
				cout<<"Successfully load in!"<<endl;
				cout<<"Press any key to continue!";
				fflush(stdin);
				char temp=getchar();
				return t;
			}
		
		}
	}
}
void case5( Manager &a)
{
	cout<<"Press 1 to Add a book or 2 to Delete a book:";
	char Select;
	fflush(stdin);
	Select=getchar();
	switch(Select)
	{
		case '1':a.AddBook();break;
		case '2':a.DelBook();break;
		default:break;
	}
}
void case81( Manager &a)
{
	cout<<"Press 1 to Add a BStudent or 2 to Add a YStudent:";
	char Select;
	fflush(stdin);
	Select=getchar();
	switch(Select)
	{
		case '1':a.AddBStudent();break;
		case '2':a.AddYStudent();break;
		default:break;
	}
}
void case8( Manager &a)
{
	cout<<"Press 1 to Add a Student or 2 to Delete a Student:";
	char Select;
	fflush(stdin);
	Select=getchar();
	switch(Select)
	{
		case '1':case81(a);break;
		case '2':a.DelStudent();break;
		default:break;
	}
}
extern void FuncofManager()
{
	Manager preMan(EntryofManager());
	while(1)
	{
		int ExitFlag=0;
		ScreenofManagerStart(preMan);
		
		fflush(stdin);
		char Select;
		Select=getchar();
		switch(Select)
		{
			case '1':system("cls");preMan.changeName();break;
			case '2':system("cls");preMan.changePassword();break;
			case '3':system("cls");preMan.showBorrowed();break;
			case '4':system("cls");preMan.showAll();break;
			case '5':system("cls");case5(preMan);break;
			case '6':system("cls");preMan.Return();break;
			case '7':system("cls");preMan.Borrow();break;
			case '8':system("cls");case8(preMan);break;
			case '9':system("cls");preMan.ShowAllStudents();break;
			case 'q':
			case 'Q':ExitFlag=1;break;
			default:cout<<"Error!:Press '1' or '2' to continue or press 'q'or 'Q' to exit"<<endl;		
		}
		if(ExitFlag==1)
			break;	
	}
}
