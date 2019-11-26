#ifndef _USERTYPE_H
#define _USERTYPE_H
#include"Account.h"

class UserType
{
public:
	UserType() {
		ID = "";
		PW = 0;
		name = "";
		age = 0;
		gender = "";
		acc = new Account();
	}
	~UserType() {}

	string GetID();
	int GetPW();
	string GetName();
	int GetAge();
	string GetGen();

	void SetID(string id);
	void SetPW(int pw);

	void SetIDFrKB();
	void SetPWFrKB();
	void SetNameFrKB();
	void SetAgeFrKB();
	void SetGenFrKB();
	void SetUser();
	void AccountRun();
	void DisplayRecord();
	void DisplayMusic();

private:
	string ID;
	int PW;
	string name;
	int age;
	string gender;
	Account *acc;
};


#endif // !_USERTYPE_H



