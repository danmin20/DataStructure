#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>
#include<string>

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_2_clicked()   //delete user's info
{
    string id=ui->lineEdit->text().toStdString();
    UserType user;
    user.SetID(id);

    if (UserList.Get(user)) {
        UserList.Delete(user);
        QMessageBox::information(this,"SUCCESS","DELETE SUCCESS!");
    }
    else
        QMessageBox::information(this,"ERROR","ITEM NOT FOUND!");
}

void Admin::on_pushButton_clicked()     //display all users' info
{
    //QString str=QString::fromUtf8(UserList.Display().c_str());
    ui->textBrowser->setText(UserList.Display());
}

int Admin::CheckID(UserType& user){
    if(UserList.Get(user))
        return 1;
    else
        return 0;
}

void Admin::AddAccount(UserType user){
    UserList.Add(user);
}

void Admin::DelAccount(UserType &user){
    UserList.Delete(user);
    user.Del();
}

void Admin::on_pushButton_3_clicked()   //delete all users' info
{
    UserList.MakeEmpty();
    if(UserList.IsEmpty())
        QMessageBox::information(this,"SUCCESS","DELETE SUCCESS!");
    else
        QMessageBox::information(this,"ERROR","DELETE FAIL!");
}

void Admin::on_pushButton_4_clicked()   //display all users' musics
{
    ui->textBrowser->setText(UserList.DisplayMusic());
}
