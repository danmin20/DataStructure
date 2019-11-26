#include "UserType.h"

string UserType::GetID() {
	return ID;
}

int UserType::GetPW() {
	return PW;
}

string UserType::GetName() {
	return name;
}

int UserType::GetAge() {
	return age;
}

string UserType::GetGen() {
	return gender;
}

void UserType::SetID(string id) {
	ID = id;
}

void UserType::SetPW(int pw) {
	PW = pw;
}

void UserType::SetIDFrKB() {
	cout << "\tID        : ";
	cin >> ID;
}

void UserType::SetPWFrKB() {
	cout << "\tPassWord  : ";
	cin >> PW;
}

void UserType::SetNameFrKB() {
	cout << "\tName      : ";
	cin >> name;
}

void UserType::SetAgeFrKB() {
	cout << "\tAge       : ";
	cin >> age;
}

void UserType::SetGenFrKB() {
	cout << "\tGender    : ";
	cin >> gender;
}

void UserType::SetUser() {
	SetIDFrKB();
	SetPWFrKB();
	SetNameFrKB();
	SetAgeFrKB();
	SetGenFrKB();
}

void UserType::AccountRun() {
	acc->Run();
}

void UserType::DisplayRecord() {
	cout << "\tID        : " << ID << '\n';
	cout << "\tPassWord  : " << PW << '\n';
	cout << "\tName      : " << name << '\n';
	cout << "\tAge       : " << age << '\n';
	cout << "\tGender    : " << gender << '\n';
}

void UserType::DisplayMusic() {
	this->acc->DisplayAllMusic();
}