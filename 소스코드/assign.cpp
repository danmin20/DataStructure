#include "assign.h"
#include "ui_assign.h"
#include "application.h"
#include <QDate>
#include <QString>

Assign::Assign(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Assign)
{
    ui->setupUi(this);
}

Assign::~Assign()
{
    delete ui;
}

void Assign::applyAdmin(Admin *ad){
    this->ad=ad;
}

void Assign::on_pushButton_clicked()
{
    string ID=ui->lineEdit->text().toStdString();
    string PW=ui->lineEdit_2->text().toStdString();
    string name=ui->lineEdit_3->text().toStdString();

    QDate date=ui->dateEdit->date();
    QString str=date.toString();
    string birth=str.toStdString();

    string gen;
    if(ui->radioButton->isChecked())
        gen=ui->radioButton->text().toStdString();
    else if(ui->radioButton_2->isChecked())
        gen=ui->radioButton_2->text().toStdString();

    if(ID==""||PW==""||name==""||gen=="")
        QMessageBox::information(this,"ERROR","Fill In All Blanks!");
    else{
        UserType user;
        user.SetRecord(ID,PW,name,birth,gen);

        if(ad->CheckID(user))
            QMessageBox::information(this,"ERROR","Already Existent ID!");
        else{
            ad->AddAccount(user);
            QMessageBox::information(this,"SUCCESS","ASSIGN SUCCESS!");
        }
    }
}
