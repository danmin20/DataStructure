#include "withdrawal.h"
#include "ui_withdrawal.h"
#include "ctime"
#include<QMessageBox>

Withdrawal::Withdrawal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Withdrawal)
{
    ui->setupUi(this);

    srand((unsigned int)time(0));
    ran=rand()%1000+10000;
    QString str=QString::fromUtf8(to_string(ran).c_str());
    ui->textBrowser->setText(str);
}

Withdrawal::~Withdrawal()
{
    delete ui;
}

void Withdrawal::applyAdmin(Admin *ad){
    this->ad=ad;
}


void Withdrawal::on_pushButton_clicked() {
    string ID=ui->lineEdit->text().toStdString();
    string PW=ui->lineEdit_2->text().toStdString();
    int num=ui->lineEdit_3->text().toInt();

    UserType user;
    user.SetID(ID);
    user.SetPW(PW);

    if(ad->CheckID(user)){
        if(user.GetPW()==PW){
            if(num!=ran)
                QMessageBox::information(this,"ERROR","Wrong Security Code!");
            else{
                ad->DelAccount(user);
                QMessageBox::information(this,"SUCCESS","WITHDRAWAL SUCCESS!");
            }
        }
        else
            QMessageBox::information(this,"ERROR","Nonexistent Account!");
    }
    else
        QMessageBox::information(this,"ERROR","Nonexistent Account!");
}
