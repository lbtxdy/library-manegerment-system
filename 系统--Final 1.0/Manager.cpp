#include<iostream>
#include<string>
#include<stdio.h>
#include"Manager.h"
using namespace std;

Manager::Manager(string prename,string preID,string prepassword):name(prename),ID(preID),password(prepassword)
{
}
Manager::~Manager()
{
	FILE *fp;
	fp=fopen("Manager.txt","r+");
	char newdata[100];
	char prepassword[7]={'\0'};
	char preNum[4]={'\0'};
	char prename[20]={'\0'};
	int i;
	for(i=0;i<4;i++)
		preNum[i]=ID[i];
	for(i=0;i<7;i++)
		prepassword[i]=password[i];
	for(i=0;i<name.length();i++)
		prename[i]=name[i];
	for(;i<19;i++)
		prename[i]=' ';
	prename[19]='\0';

	//newdata
	for(i=0;i<4;i++)
		newdata[i]=preNum[i];
	newdata[3]=' ';
	for(i=4;i<=9;i++)
		newdata[i]=prepassword[i-4];
	newdata[10]=' ';
	for(i=11;prename[i-11]!='\0';i++)
		newdata[i]=prename[i-11];
	newdata[i]='\n';
	newdata[i+1]='\0';
	
	
	char a[100];
	fgets(a,100,fp);
	char Num[4];
	strncpy(Num,a,3);
	Num[3]='\0';
	while(strncmp(a,preNum,3)!=0)
	{
		fgets(a,100,fp);
		strncpy(Num,a,3);
		Num[3]='\0';
	}
	
	fseek(fp,-(strlen(a)+1),1);
	fputs(newdata,fp);
	fclose(fp);
}
void Manager::changePassword()
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
void Manager::changeName()
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
void Manager::Borrow()
{
	FILE *fp;
	
	
	char preISBN[7];
	char preNum[12];
	cout<<"Please enter the Book\'s ISBN:";
	cin>>preISBN;
	cout<<"Please enter the Student\'s ID:";
	cin>>preNum;
	
	
	
	cout<<"Searching the Student......."<<endl;
	fp=fopen("Student.txt","r+");
	char Stus[100];
	char StuNum[12]={'\0'};
	char StuPassword[7]={'\0'};
	char Stuname[20]={'\0'};
	int Findflag=0;
	fgets(Stus,100,fp);
	while(Stus[0]!='*')
	{
		if(Stus[0]!='#')
		{
			strncpy(StuNum,Stus,11);
			StuNum[11]='\0';
			if(strcmp(StuNum,preNum)==0)
			{
				Findflag=1;
				break;
			}
			else
			    fgets(Stus,100,fp);
		}
		else
		fgets(Stus,100,fp);	
	}
	if(Findflag==1)
		cout<<"The Student exist!"<<endl;
	else
		cout<<"Error:The Student does not exist!"<<endl;
	fclose(fp);
	
	
	cout<<"Searching the book......."<<endl;
	
	fp=fopen("Book.txt","r+");//Search the book
	char s[100];
	char ISBN[7]={'\0'};
	char area[3]={'\0'};
	char name[20]={'\0'};
	int Findflag1=0;//find or not
	int Findflag2=0;//borrowed or not
	int Findflag3=0;//can or cannot borrow
	fgets(s,100,fp);
	while(s[0]!='*')
	{
		if(s[0]=='#')
		{
			fgets(s,100,fp);
			continue;
		}
		int i;
		for(i=4;i<=9;i++)
			ISBN[i-4]=s[i];
		for(i=0;i<19;i++)
			name[i]=' ';
		for(i=14;s[i]!='\n';i++)
			name[i-14]=s[i];
		for(i=11;i<=13;i++)
			area[i-11]=s[i];
		
		if(strcmp(ISBN,preISBN)==0)
		{
			Findflag1=1;
			if(s[0]=='0')
			{
				Findflag2=1;
			}
			if(s[2]=='1')
			{
				Findflag3=1;
			}
		
			break;
		}
		else
		{
			fgets(s,100,fp);
		}	
	}
	if(Findflag1==0||Findflag2==0||Findflag3==0)
	{
		if(Findflag1==0)
			cout<<"Error:The book doesn\'t exist!"<<endl;
		if(Findflag3==1&&Findflag2==0)
			cout<<"Error:The book has been borrowed!"<<endl;
		if(Findflag3==0)
			cout<<"Error:The book cannot be borrowed!"<<endl;
	}
	else
	{
		cout<<"BookName:"<<name;
		cout<<"ISBN:"<<ISBN;
		cout<<"  Area:"<<area<<endl;
		cout<<"The book can be borrowed!"<<endl;
		fseek(fp,-(strlen(s)+1),1);
		fputc('1',fp);
	}
	fclose(fp);
	
	
	if(Findflag==1&&Findflag1==1&&Findflag2==1&&Findflag3==1)
	{
		fp=fopen("Borrowed.txt","r+");
		char sBor[100];
		int i;
		for(i=0;i<6;i++)
			sBor[i]=preISBN[i];
		sBor[6]=' ';
		for(i=7;i<=17;i++)
			sBor[i]=preNum[i-7];
		sBor[18]=' ';
		for(i=19;name[i-19]!='\0';i++)
			sBor[i]=name[i-19];
		sBor[i]='\n';
		sBor[i+1]='\0';
		
		
		char a[100];
		fgets(a,100,fp);
		while(a[0]!='*')
		{
			fgets(a,100,fp);
		}
		fseek(fp,-(strlen(a)+1),1);
		puts(sBor);
		fputs(sBor,fp);
		fputs("******************\n",fp);
	}
	fclose(fp);
	cout<<"Successfully Borrow a Book!"<<endl;
	cout<<"Press any key to continue!";
	fflush(stdin);
	char temp=getchar();
	
}
void Manager::Return()
{
	FILE *fp;
	
	char preISBN[7];
	cout<<"Please enter the Book\'s ISBN:";
	cin>>preISBN;
	
	fp=fopen("Borrowed.txt","r+");
	char a[100];
	fgets(a,100,fp);
	while(strncmp(a,preISBN,6)!=0)
	{
		fgets(a,100,fp);
	}
	fseek(fp,-(strlen(a)+1),1);
	fputs("######################################\n",fp);
	fclose(fp);
	
	fp=fopen("Book.txt","r+");
	char b[100];
	char ISBN[7];
	fgets(b,100,fp);
	while(b[0]!='*')
	{
		if(b[0]=='#')
		{
			fgets(b,100,fp);
			continue;
		}
		int i;
		for(i=4;i<=9;i++)
			ISBN[i-4]=b[i];
		ISBN[6]='\0';
		puts(ISBN);
		if(strcmp(ISBN,preISBN)==0)
			break;
		else
			fgets(b,100,fp);;
	}
	fseek(fp,-(strlen(b)+1),1);
	fputc('0',fp);
	fclose(fp);
	cout<<"Successfully Return a Book!"<<endl;
	cout<<"Press any key to continue!";
	fflush(stdin);
	char temp=getchar();
	
}
void Manager::ShowAllStudents()
{
	FILE *fp;
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
			for(i=0;i<19;i++)
				name[i]=' ';
			for(i=21;s[i]!='\n';i++)
				name[i-21]=s[i];
			
			name[19]='\0';
			
			cout<<"Name:"<<name<<"Password:"<<Password<<"  ID:"<<Num;
			if(s[12]=='1')
			{
				
				cout<<"  graduate student\n";
			}
			else
			{
				
				cout<<"  undergraduate student\n";
			}
			fgets(s,100,fp);
		}
		else
		fgets(s,100,fp);	
	}
	fclose(fp);
	
	cout<<endl;
	cout<<"These are all the Students!"<<endl;
	cout<<"Press any key to continue!";
	fflush(stdin);
	char temp=getchar();
}
void Manager::AddBStudent()
{
	FILE *fp;
	fp=fopen("Student.txt","r+");
	char s[50]={'\0'};
	int i;
	
	char Num[12]={'\0'};
	cout<<"Please enter the ID(11-digit):";
	cin>>Num;	
	
	for(i=0;i<=10;i++)
		s[i]=Num[i];
	s[11]=' ';
	s[12]='0';
	s[13]=' ';
	for(i=14;i<=19;i++)
		s[i]='1';
	s[20]=' ';
	s[21]='K';
	for(i=22;i<40;i++)
		s[i]=' ';
	s[40]='\n';
	s[41]='\0';
	
	char a[100];
	fgets(a,100,fp);
	while(a[0]!='*')
	{
		fgets(a,100,fp);
	}
	
	fseek(fp,-(strlen(a)+1),1);
	fputs(s,fp);
	fputs("**********************\n",fp);
	fclose(fp);
	cout<<"Successfully Add a Undergraduate Student!"<<endl;
	cout<<"Press any key to continue!";
	fflush(stdin);
	char temp=getchar();
}
void Manager::AddYStudent()
{
	FILE *fp;
	fp=fopen("Student.txt","r+");
	char s[50]={'\0'};
	int i;
	
	char Num[12]={'\0'};
	cout<<"Please enter the ID(11-digit):";
	cin>>Num;	
	
	for(i=0;i<=10;i++)
		s[i]=Num[i];
	s[11]=' ';
	s[12]='1';
	s[13]=' ';
	for(i=14;i<=19;i++)
		s[i]='1';
	s[20]=' ';
	s[21]='K';
	for(i=22;i<40;i++)
		s[i]=' ';
	s[40]='\n';
	s[41]='\0';
	
	
	char a[100];
	fgets(a,100,fp);
	while(a[0]!='*')
	{
		fgets(a,100,fp);
	}
	
	fseek(fp,-(strlen(a)+1),1);
	fputs(s,fp);
	fputs("**********************\n",fp);
	fclose(fp);
	cout<<"Successfully Add a Graduat Student!"<<endl;
	cout<<"Press any key to continue!";
	fflush(stdin);
	char temp=getchar();
}
void Manager::DelStudent()
{
	FILE *fp;
	fp=fopen("Student.txt","r+");
	char s[12];
	cout<<"Please enter the Student\'s ID(11-digit):";
	cin>>s;
	
	char a[100];
	fgets(a,100,fp);
	char Num[12];
	strncpy(Num,a,11);
	Num[11]='\0';
	while(strncmp(a,s,11)!=0)
	{
		fgets(a,100,fp);
		strncpy(Num,a,11);
		Num[11]='\0';
	}
	
	fseek(fp,-(strlen(a)+1),1);
	fputs("########################################\n",fp);
	fclose(fp);
	cout<<"Successfully Delete a Student!"<<endl;
	cout<<"Press any key to continue!";
	fflush(stdin);
	char temp=getchar();
}

void Manager::AddBook()
{
	FILE *fp;
	fp=fopen("Book.txt","r+");
	char s[100];
	char a;
	char ISBN[7]={'\0'};
	char area[3]={'\0'};
	char name[20]={'\0'};
	cout<<"Please enter the Name(不能有空格):";
	cin>>name;
	int i;
	for(i=strlen(name);i<19;i++)
		name[i]=' ';
	name[19]='\0';
	cout<<"Please enter the ISBN(6 digits):";
	cin>>ISBN;
	cout<<"Please enter the Store Area(one alphabet and one digit):";
	cin>>area;
	cout<<"Can of cannot be borrow(Y/N):";
	fflush(stdin);
	a=getchar();
	if(a=='Y')
	{
		s[2]='1';
	}
	else
	{
		s[2]='0';
	}
	s[0]='0';
	s[1]=' ';
	
	s[3]=' ';
	for(i=4;i<=9;i++)
		s[i]=ISBN[i-4];
	s[10]=' ';
	s[11]=area[0];
	s[12]=area[1];
	s[13]=' ';
	for(i=14;name[i-14]!='\0';i++)
	{
		s[i]=name[i-14];
	}
	s[i]='\n';
	s[i+1]='\0';
	
	char b[100];
	fgets(b,100,fp);
	while(b[0]!='*')
	{
		fgets(b,100,fp);
	}
	fseek(fp,-(strlen(b)+1),1);
	fputs(s,fp);
	fputs("********************\n",fp);
	fclose(fp);
	cout<<"Successfully Delete a Book!"<<endl;
	cout<<"Press any key to continue!";
	fflush(stdin);
	char temp=getchar();
}
void Manager::DelBook()
{
	FILE *fp;
	fp=fopen("Book.txt","r+");
	char s[100];
	char ISBN[7]={'\0'};
	char a[7]={'\0'};
	
	cout<<"Please enter the Book\'s ISBN(6-digit):";
	cin>>ISBN;
	
	fgets(s,100,fp);
	int i;
	for(i=4;i<=9;i++)
		a[i-4]=s[i];
	a[6]='\0';
	while(strcmp(a,ISBN)!=0)
	{
		fgets(s,100,fp);
		for(i=4;i<=9;i++)
		a[i-4]=s[i];
		a[6]='\0';
	}
	fseek(fp,-(strlen(s)+1),1);
	fputs("#################################\n",fp);
	fclose(fp);
	cout<<"Successfully Add a Book!"<<endl;
	cout<<"Press any key to continue!";
	fflush(stdin);
	char temp=getchar();
}
void Manager::showBorrowed()
{
	FILE *fp;
	fp=fopen("Borrowed.txt","r+");
	char s[100];
	char ISBN[7]={'\0'};
	char name[20]={'\0'};
	char Num[12]={'\0'};
	fgets(s,100,fp);
	while(s[0]!='*')
	{
		if(s[0]!='#')
		{
			int i;
			for(i=0;i<6;i++)
				ISBN[i]=s[i];
			for(i=8;i<=18;i++)
				Num[i-8]=s[i];
			for(i=0;i<19;i++)
				name[i]=' ';
			for(i=19;s[i]!='\n';i++)
				name[i-19]=s[i];
			cout<<"BookName:"<<name;
			cout<<"ISBN:"<<ISBN;
			cout<<" StudentID:"<<Num<<endl;
			fgets(s,100,fp);
		}
		else
			fgets(s,100,fp);
	}
	fclose(fp);
	
	cout<<endl;
	cout<<"These are all the Borrowed Books!"<<endl;
	cout<<"Press any key to continue!";
	fflush(stdin);
	char temp=getchar();
}
		
void Manager::showAll()
{
	FILE *fp;
	fp=fopen("Book.txt","r+");
	char s[100];
	char ISBN[7]={'\0'};
	char area[3]={'\0'};
	char name[20]={'\0'};
	
	fgets(s,100,fp);
	while(s[0]!='*')
	{
		if(s[0]!='#')
		{
			int i;
			for(i=4;i<=9;i++)
				ISBN[i-4]=s[i];
			for(i=0;i<19;i++)
				name[i]=' ';
			for(i=14;s[i]!='\n';i++)
				name[i-14]=s[i];
			for(i=11;i<=13;i++)
				area[i-11]=s[i];
			cout<<"BookName:"<<name;
			cout<<"ISBN:"<<ISBN;
			cout<<"  Area:"<<area;
			if(s[0]=='1')
			{
				cout<<" Borrowed  ";
			}
			else
			{
				cout<<" UnBorrowed";
			}
			if(s[2]=='1')
			{
				cout<<" Can Borrow  \n";
			}
			else
			{
				cout<<" Can\'t Borrow\n";
			}
			fgets(s,100,fp);
		}
		else
			fgets(s,100,fp);
	}
	fclose(fp);
	
	cout<<endl;
	cout<<"These are all the Books!"<<endl;
	cout<<"Press any key to continue!";
	fflush(stdin);
	char temp=getchar();
}
void Manager::showInfo()
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
