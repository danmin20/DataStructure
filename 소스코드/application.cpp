#include "application.h"
#include "ui_application.h"
#include<QMessageBox>
#include"admin.h"
#include"assign.h"
#include"withdrawal.h"

int mPW;

Application::Application(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Application)
{
    ui->setupUi(this);
    admin=new Admin();
}

Application::~Application()
{
    delete ui;
    delete admin;
}

void Application::on_pushButton_clicked()   //assign
{
    Assign assign;
    assign.setModal(true);

    assign.applyAdmin(admin);
    assign.exec();
}

void Application::on_pushButton_2_clicked() //login
{
    string ID=ui->lineEdit->text().toStdString();
    string PW=ui->lineEdit_2->text().toStdString();

    UserType user;
    user.SetID(ID);

    if(admin->CheckID(user)){
        if(PW==user.GetPW())
            user.AccountRun();
        else
            QMessageBox::information(this,"ERROR","Nonexistent Account!");
    }
    else
        QMessageBox::information(this,"ERROR","Nonexistent Account!");
}

void Application::on_pushButton_3_clicked() //withdrawal
{
    Withdrawal with;
    with.setModal(true);

    with.applyAdmin(admin);
    with.exec();
}

void Application::on_pushButton_4_clicked() //admin
{
    mPW=ui->lineEdit_3->text().toInt();
    if(mPW!=2018102220)
        QMessageBox::information(this,"ERROR","WRONG PASSWORD!");
    else{
        admin->setModal(true);
        admin->exec();
    }
}
