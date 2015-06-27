#include<iostream>
#include<string>
#include<stdio.h>
#include"Student.h"
using namespace std;

void Student::changeName()
{
	cout<<"The present name is:";
	cout<<name<<endl;
	cout<<"Please enter the new name(不能有空格):";
	cin>>name;
	cout<<"Successfully Change the name!"<<endl;
	cout<<"Press any key to continue!";
	fflush(stdin);
	char temp=getchar();
}
void Student::changePassword()
{
	while(1)
	{
		string newpassword1,newpassword2;
		cout<<"The present password is:";
		cout<<password<<endl;
		cout<<"Please enter the new password(6-digit):";
		cin>>newpassword1;
		cout<<"Please enter again:";
		cin>>newpassword2;
		if(newpassword1==newpassword2)
		{
			password=newpassword1;
			break;
		}
		else
		{
			cout<<"Error:The second one is different from the first!"<<endl;
		}
	}
	
	cout<<"Successfully Change the password!"<<endl;
	cout<<"Press any key to continue!";
	fflush(stdin);
	char temp=getchar();
}
Student::~Student()
{
	FILE *fp;
	fp=fopen("Student.txt","r+");
	char newdata[100];
	char prepassword[7]={'\0'};
	char preNum[12]={'\0'};
	char prename[20]={'\0'};
	char preBY=BorY;
	int i;
	for(i=0;i<12;i++)
		preNum[i]=ID[i];
	for(i=0;i<7;i++)
		prepassword[i]=password[i];
	for(i=0;i<name.length();i++)
		prename[i]=name[i];
	for(;i<19;i++)
		prename[i]=' ';
	prename[19]='\0';
	
	//newdata
	for(i=0;i<11;i++)
		newdata[i]=preNum[i];
	newdata[11]=' ';
	newdata[12]=preBY;
	newdata[13]=' ';
	for(i=14;i<=19;i++)
		newdata[i]=prepassword[i-14];
	newdata[20]=' ';
	for(i=21;prename[i-21]!='\0';i++)
		newdata[i]=prename[i-21];
	newdata[i]='\n';
	newdata[i+1]='\0';
	
	
	char a[100];
	fgets(a,100,fp);
	char Num[12];
	strncpy(Num,a,11);
	Num[11]='\0';
	while(strncmp(a,preNum,11)!=0)
	{
		fgets(a,100,fp);
		strncpy(Num,a,11);
		Num[11]='\0';
	}
	
	fseek(fp,-(strlen(a)+1),1);
	fputs(newdata,fp);
	fclose(fp);
}

void Student::showInfo()
{
	int i;
	for(i=0;name[i]!=' '&&name[i]!='\0';i++)
		cout<<name[i];
	int len=i;
	cout<<"("<<ID<<")";
	for(i=1;i<=52-len-ID.length();i++)
		cout<<" ";
	cout<<"|   "<<endl;
}
