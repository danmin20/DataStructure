#include "deletesong.h"
#include "ui_deletesong.h"
#include "account.h"
#include <QMessageBox>

DeleteSong::DeleteSong(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteSong)
{
    ui->setupUi(this);
}

DeleteSong::~DeleteSong()
{
    delete ui;
}

void DeleteSong::applyAccount(Account* acc){
    this->acc=acc;
}

void DeleteSong::on_pushButton_clicked()
{
    if (acc->MusicList.IsEmpty()) {
        QMessageBox::information(this,"ERROR","List is empty!");
        }
    else{
        int len = acc->MusicList.GetLength();
        MusicType item;
        int id=ui->lineEdit->text().toInt();
        item.SetPK(id);
        acc->MusicList.Delete(item);

        if (len > acc->MusicList.GetLength())
            QMessageBox::information(this,"SUCCESS","DELETE  SUCCESS!");
        else
            QMessageBox::information(this,"ERROR","DELETE FAIL!");
    }
}
