#ifndef _APP_H
#define _APP_H

#include<iostream>
#include"UserType.h"
#include"DoublyLinkedList.h"
using namespace std;

class App
{
public:
	App() {
		Command = 0;
		MasterCommand = 0;
	}
	~App() {}

	void Run();

	int GetCom();

	int Assign();	//add 사용

	int LogIn();	//get 사용

	int Withdrawal();

	void MaseterRun();

	int GetMasterCom();

	void DisplayAllUserInfo();	//display 사용

	void DeleteAllUserInfo();

	void DisplayAllUserMusic();

	void DeleteUserInfo();

public:
	int Command;
	int MasterCommand;
	DoublyLinkedList<UserType>UserList;
};


#endif // !_APP_H

