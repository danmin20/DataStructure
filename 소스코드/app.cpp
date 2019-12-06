#include "app.h"
#include "ui_app.h"
#include<QMessageBox>

string ID;
int PW;
int mPW;

App::App(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::App)
{
    ui->setupUi(this);
}

App::~App()
{
    delete ui;
}

void App::on_pushButton_clicked()
{
    ID=ui->lineEdit->text().toStdString();
    PW=ui->lineEdit_2->text().toInt();

    UserType user;
    user.SetID(ID);
    user.SetPW(PW);

    if(Admin::UserList.Get(user))
        QMessageBox::information(this,"ERROR","Already Existent Account!");
    else{
        Admin::UserList.Add(user);
        user.AccountRun();
    }
}

void App::on_pushButton_2_clicked()
{
    ID=ui->lineEdit->text().toStdString();
    PW=ui->lineEdit_2->text().toInt();

    UserType user;
    user.SetID(ID);
    user.SetPW(PW);

    if(Admin::UserList.Get(user))
        user.AccountRun();
    else
        QMessageBox::information(this,"ERROR","Nonexistent Account!");
}

void App::on_pushButton_3_clicked()
{
    ID=ui->lineEdit->text().toStdString();
    PW=ui->lineEdit_2->text().toInt();

    UserType user;
    user.SetID(ID);
    user.SetPW(PW);

    if(Admin::UserList.Get(user))
        Admin::UserList.Delete(user);
    else
        QMessageBox::information(this,"ERROR","Nonexistent Account!");
}

void App::on_pushButton_4_clicked() //admin
{
    mPW=ui->lineEdit_3->text().toInt();
    if(mPW!=2018102220)
        QMessageBox::information(this,"ERROR","WRONG PASSWORD!");
    else{
        AdminType admin;
        admin.AdminRun();
    }
}
