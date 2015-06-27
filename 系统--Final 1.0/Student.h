#ifndef _Student_H_
#define _Student_H_
#include<string>
using namespace std;
class Student
{
	protected:
		string name;
		string ID;
		string password;
		char BorY;
	public:
		Student(const Student &a)
		{
			name=a.name;
			ID=a.ID;
			password=a.password;
			BorY=a.BorY;
		}
		Student(string preName,string preID,string prePassword,char a):name(preName),ID(preID),password(prePassword),BorY(a)
		{
		}
		~Student();
		void changeName();
		void changePassword();
		
		void showInfo();
		//void Recommend();
		//void ListHistory();
		//void ListBorrowed();
		//void SearchBook();
};

/*class BStudent:public Student
{
	public:
		BStudent(){BorY='0';}
		~BStudent(){}
};

class YStudent:public Student
{
	public:
		YStudent(){BorY='1';}
		~YStudent(){}
};*/

#endif
