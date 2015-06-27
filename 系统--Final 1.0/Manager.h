#ifndef _Manager_H_
#define _Manager_H_
#include<string>
using namespace std;
class Manager
{
	protected:
		string name;
		string ID;
		string password;
	public:
		Manager(const Manager &a)
		{
			name=a.name;
			ID=a.ID;
			password=a.password;
		}
		Manager(string prename,string preID,string prepassword);
		~Manager();
		
		void Borrow();
		void Return();
		
		void changePassword();	
		void changeName();
		
		void ShowAllStudents();
		void AddBStudent();
		void AddYStudent();
		void DelStudent();
		
		
		void AddBook();
		void DelBook();
		void showBorrowed();
		void showAll();
		
		void showInfo();
		//void showRecommendation();
	
};


#endif
