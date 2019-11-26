#include "App.h"

void App::Run() {
	while (1) {
		Command = GetCom();

		switch (Command) {
		case 1:
			Assign();
			break;
		case 2:
			LogIn();
			break;
		case 3:
			Withdrawal();
			break;
		case 4:
			MaseterRun();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

int App::GetCom() {
	int command;
	cout << '\n' << '\n';
	cout << "\t------------ User Mode ------------\n";
	cout << "\t   1 : Assign Account\n";
	cout << "\t   2 : Login\n";
	cout << "\t   3 : Membership Withdrawal\n";
	cout << "\t-----------------------------------\n";
	cout << "\t   4 : Master Mode\n";
	cout << "\t   0 : Quit\n";
	cout << "\t-----------------------------------\n";

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << '\n';

	return command;
}

int App::Assign() {
	UserType user;
	user.SetUser();

	if (UserList.Get(user)) {
		cout << "\t이미 존재하는 계정입니다. 로그인해주세요.\n";
		return 0;
	};
	UserList.Add(user);
	cout << "\t회원가입 완료!\n";
	user.AccountRun();
	return 1;
}

int App::LogIn() {
	UserType user;
	user.SetIDFrKB();
	user.SetPWFrKB();

	if (UserList.Get(user)) {
		user.AccountRun();
		return 1;
	}
	cout << "\t아이디 또는 비밀번호가 잘못 입력되었습니다.\n";
	return 0;
}

int App::Withdrawal() {
	UserType user;
	user.SetIDFrKB();
	user.SetPWFrKB();

	if (UserList.Get(user)) {
		UserList.Delete(user);
		cout << "\n\t탈퇴 완료!\n";
		return 1;
	}
	cout << "\n\t아이디 또는 비밀번호가 잘못 입력되었습니다.\n";
	return 0;
}



void App::MaseterRun() {
	string pw;
	cout << "\tMaster Password : ";
	cin >> pw;
	if (pw != "2018102220") {
		cout << "\n\tWrong Password!\n";
		return;
	}

	while (1) {
		MasterCommand = GetMasterCom();

		switch (MasterCommand) {
		case 1:
			DisplayAllUserInfo();
			break;
		case 2:
			DeleteUserInfo();
		case 3:
			DeleteAllUserInfo();
			break;
		case 4:
			DisplayAllUserMusic();
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

int App::GetMasterCom() {
	int command;
	cout << '\n' << '\n';
	cout << "\t-----------------------------------\n";
	cout << "\t   1 : Display All Users' Information\n";
	cout << "\t   2 : Delete User's Information\n";
	cout << "\t   3 : Delete All Users' Information\n";
	cout << "\t   4 : Display All Users' Musics\n";
	cout << "\t   0 : Quit\n";
	cout << "\t-----------------------------------\n";

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << '\n';

	return command;
}

void App::DisplayAllUserInfo() {
	UserList.Display();
}

void App::DeleteAllUserInfo() {
	UserList.MakeEmpty();
	if (UserList.GetLength() == 0)
		cout << "\n\t<======== DELETE SUCCESS! =========>" << endl;
	else
		cout << "\n\t<========== DELETE FAIL! ==========>" << endl;
}

void App::DeleteUserInfo() {
	UserType user;
	user.SetIDFrKB();

	if (UserList.Get(user)) {
		UserList.Delete(user);
		cout << "\n\t<======== DELETE SUCCESS! =========>" << endl;
	}
	else
		cout << "\n\t아이디 또는 비밀번호가 잘못 입력되었습니다.\n";
}

void App::DisplayAllUserMusic() {
	UserList.DisplayMusic();
}