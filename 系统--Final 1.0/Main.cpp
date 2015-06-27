#include<iostream>
#include<string>
#include<stdio.h>
#include <stdlib.h>
#include"Manager.h"
#include"Student.h"
using namespace std;

extern void FuncofStudent();
extern void FuncofManager();
void ScreenofEntry()
{
	system("cls");
	cout<<"    ----------------------------------------------------------------    "<<endl;
	cout<<"   |                                                                |   "<<endl;
	cout<<"   |            Welcome to the library operation system             |   "<<endl;
	cout<<"   |                                                                |   "<<endl;
	cout<<"   |                   Please select your identity                  |   "<<endl;
	cout<<"   |                                                                |   "<<endl;
	cout<<"   |                      (1) Student                               |   "<<endl;
	cout<<"   |                      (2) Manager                               |   "<<endl;
	cout<<"   |                                                                |   "<<endl;
	cout<<"   |      Press '1' or '2' to continue or press 'q'or 'Q' to exit   |   "<<endl;
	cout<<"    ----------------------------------------------------------------    "<<endl;
	cout<<"   Now enter:";
}


int main()
{
	while(1)
	{
		int ExitFlag=0;
		ScreenofEntry();
		
		fflush(stdin);
		char Select;
		Select=getchar();
		switch(Select)
		{
			case '1':system("cls");FuncofStudent();break;
			case '2':system("cls");FuncofManager();break;
			case 'q':
			case 'Q':ExitFlag=1;break;
			default:cout<<"Error!:Press '1' or '2' to continue or press 'q'or 'Q' to exit"<<endl;		
		}
		if(ExitFlag==1)
			break;	
	}
	return 0;
	
}

