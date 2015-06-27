#ifndef _Book_H_
#define _Book_H_
#include<string>
using namespace std;

class Book
{
	protected:
		string name;
		string ISBN;
		string Area;
		bool CanBorrow;
		bool Borrowed;
};



#endif
