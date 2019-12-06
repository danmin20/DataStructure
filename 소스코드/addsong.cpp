#include "addsong.h"
#include "ui_addsong.h"
#include "account.h"
#include <QMessageBox>

AddSong::AddSong(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSong)
{
    ui->setupUi(this);
}

AddSong::~AddSong()
{
    delete ui;
}

void AddSong::applyAccount(Account* acc){
    this->acc=acc;
}

void AddSong::on_pushButton_clicked()
{
    if (acc->MusicList.IsFull()) {
        QMessageBox::information(this,"ERROR","List is full!");
    }
    else{
        int len = acc->MusicList.GetLength();

        MusicType item;
        int id=ui->lineEdit->text().toInt();
        string name=ui->lineEdit_2->text().toStdString();
        string artist=ui->lineEdit_3->text().toStdString();
        string album=ui->lineEdit_4->text().toStdString();
        string genre=ui->lineEdit_5->text().toStdString();

        item.SetRecord(id,name,artist,album,genre);
        item.SetAddedNum(acc->MusicList.GetLength() + 1);
        acc->MusicList.Add(item);

        if(acc->MusicList.GetLength()>len)
            QMessageBox::information(this,"SUCCESS","ADD SUCCESS!");
        else
            QMessageBox::information(this,"ERROR","ADD FAIL!");

    }
}
