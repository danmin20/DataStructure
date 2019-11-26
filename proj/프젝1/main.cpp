/**
*	@mainpage
*	@date
*	@author
*/

#include"App.h"

/**
*	program main function for data structures course.
*/
int main() {
	App app;	// Program application
	app.Run();			// run program

	app.DeleteAllUserInfo();	//동적할당된 acc 소멸
	return 0;
}