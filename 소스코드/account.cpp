#include "account.h"
#include "ui_account.h"
#include "search.h"
#include "addsong.h"
#include "deletesong.h"
#include "playsong.h"
#include "display.h"
#include "fileout.h"
#include <QMessageBox>

Account::Account(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Account)
{
    ui->setupUi(this);
}

Account::~Account()
{
    delete ui;
}

void Account::on_pushButton_clicked()   //AddMusic
{
    AddSong addsong;
    addsong.setModal(true);

    addsong.applyAccount(this);
    addsong.exec();
}


void Account::on_pushButton_2_clicked() //DeleteMusic
{
    DeleteSong delsong;
    delsong.setModal(true);

    delsong.applyAccount(this);
    delsong.exec();
}

void Account::on_pushButton_3_clicked() //MakeMusicListEmpty
{
    MusicList.MakeEmpty();
    QMessageBox::information(this,"SUCCESS","List is empty now!");
}


void Account::on_pushButton_4_clicked() //Search함수들
{
    Search search;
    search.setModal(true);

    search.applyAccount(this);
    search.exec();
}

void Account::on_pushButton_9_clicked() //DisplayRecentAddMusic
{
    Display show;
    show.setModal(true);

    MusicType item;
    string str="";

    MusicList.ResetList();
    int curIdx = MusicList.GetNextItem(item);
    int len = MusicList.GetLength();

    while (curIdx != -1) {
        if (item.GetAddedNum() >= len) {
            str+=item.DisplayRecordOnScreen();
            break;
        }
        curIdx = MusicList.GetNextItem(item);
    }

    QString ans=QString::fromUtf8(str.c_str());

    show.DisplaySong(ans);
    show.exec();
}

void Account::on_pushButton_13_clicked()    //DisplayAllMusic
{
    Display show;
    show.setModal(true);
    show.DisplaySong(DisplayAllMusic());
    show.exec();
}

void Account::on_pushButton_10_clicked()    //PlayMusic
{
    PlaySong ps;
    ps.setModal(true);

    ps.applyAccount(this);
    ps.exec();
}

void Account::on_pushButton_11_clicked()    //DisplayAllMusicInPlayList
{
    if(PlayList.IsEmpty())
        QMessageBox::information(this,"ERROR","LIST IS EMPTY!");

    else{
        Display show;
        show.setModal(true);
        show.DisplaySong(PlayList.Print());
        show.exec();
    }
}

void Account::on_pushButton_12_clicked()    //MakePlayListEmpty
{
    PlayList.MakeEmpty();
    QMessageBox::information(this,"SUCCESS","List is empty now!");
}

QString Account::DisplayAllMusic() {
    MusicType item;

    MusicList.ResetList();
    int curIdx = MusicList.GetNextItem(item);
    string music="";

    while (curIdx != -1) {
        string str="";
        str+=item.DisplayRecordOnScreen();
        str+='\n';
        music+=str;
        curIdx = MusicList.GetNextItem(item);
    }
    QString display=QString::fromUtf8(music.c_str());

    return display;
}

void Account::on_pushButton_5_clicked()     //WriteDataToFile
{
    FileOut fo;
    fo.setModal(true);

    fo.applyAccount(this);
    fo.exec();
}
