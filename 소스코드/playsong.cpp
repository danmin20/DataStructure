#include "playsong.h"
#include "ui_playsong.h"
#include "account.h"
#include <QMessageBox>


PlaySong::PlaySong(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlaySong)
{
    ui->setupUi(this);
}

PlaySong::~PlaySong()
{
    delete ui;
}

void PlaySong::applyAccount(Account *acc){
    this->acc=acc;
}

void PlaySong::on_pushButton_clicked()
{
    MusicType item;
    int id=ui->lineEdit->text().toInt();
    item.SetPK(id);

    int n=acc->MusicList.RetrieveBS(item);

    if(n){
        SimpleMusicType s_music;
        s_music.SetSongRecord(item.GetPK(), item.GetName(), item.GetArtist());
        s_music.SetSongPlayedTime(1);

        if (!acc->PlayList.FindNPlus(s_music))
            acc->PlayList.AddToPlayList(s_music);

        QString str=QString::fromUtf8(item.GetName().c_str());
        QMessageBox::information(this,"Playing", str+" is Playing..");
    }
    else
        QMessageBox::information(this,"ERROR","ITEM NOT FOUND!");
}
