#include "UserType.h"

string UserType::GetID() {
    return ID;
}

string UserType::GetPW() {
    return PW;
}

string UserType::GetName() {
    return name;
}

string UserType::GetBirth() {
    return birth;
}

string UserType::GetGen() {
    return gender;
}

void UserType::SetID(string id) {
    ID = id;
}

void UserType::SetPW(string pw) {
    PW = pw;
}

void UserType::SetRecord(string id, string pw, string n, string b, string g){
    ID=id;
    PW=pw;
    name=n;
    birth=b;
    gender=g;
}

void UserType::AccountRun() {
    this->acc->setModal(true);
    this->acc->exec();
}

QString UserType::DisplayRecord() {
    string str;
    str+= "ID        : " + ID + '\n'
            + "PassWord  : " + PW + '\n'
            + "Name      : " + name + '\n'
            + "Birth     : " + birth + '\n'
            + "Gender    : " + gender + '\n';

    QString ans=QString::fromUtf8(str.c_str());

    return ans;
}

QString UserType::DisplayMusic() {
    QString ans="";
    ans+=this->acc->DisplayAllMusic();

    return ans;
}

void UserType::Del(){
    delete acc;
}
