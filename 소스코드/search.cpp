#include "search.h"
#include "ui_search.h"
#include "account.h"
#include<QString>

Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
}

Search::~Search()
{
    delete ui;
}

void Search::applyAccount(Account *acc){
    this->acc=acc;
}

void Search::on_pushButton_clicked()       //PK
{
    int id=ui->lineEdit->text().toInt();

    MusicType item;
    item.SetPK(id);

    int n = acc->MusicList.RetrieveBS(item);
    if (n){
        QString str=QString::fromUtf8(item.DisplayRecordOnScreen().c_str());
        ui->textBrowser->setText(str);
    }
    else
        ui->textBrowser->setText("ITEM NOT FOUND!");
}

void Search::on_pushButton_2_clicked()      //name
{
    string name=ui->lineEdit->text().toStdString();

    MusicType Name, item;
    item.SetName(name);

    acc->MusicList.ResetList();
    int curIdx = acc->MusicList.GetNextItem(Name);
    int cnt=0;

    string ans="";
    while (curIdx != -1) {
        if (item.GetName() == Name.GetName()) {
            ans+=Name.DisplayPKOnScreen();
            ans+=Name.DisplayArtistOnScreen();
            ans+=Name.DisplayAlbumOnScreen();
            ans+=Name.DisplayGenreOnScreen();
            cnt++;
        }
        curIdx = acc->MusicList.GetNextItem(Name);
        ans+='\n';
    }

    if(cnt==0)
        ui->textBrowser->setText("ITEM NOT FOUND!");
    else{
        QString str=QString::fromUtf8(ans.c_str());
        ui->textBrowser->setText(str);
    }
}

void Search::on_pushButton_3_clicked()     //artist
{
    string name=ui->lineEdit->text().toStdString();

    MusicType artist, item;
    item.SetArtist(name);

    acc->MusicList.ResetList();
    int curIdx = acc->MusicList.GetNextItem(artist);
    int cnt=0;

    string ans="";
    while (curIdx != -1) {
        if (item.GetArtist() == artist.GetArtist()) {
            ans+=artist.DisplayPKOnScreen();
            ans+=artist.DisplayNameOnScreen();
            ans+=artist.DisplayAlbumOnScreen();
            ans+=artist.DisplayGenreOnScreen();
            cnt++;
        }
        curIdx = acc->MusicList.GetNextItem(artist);
        ans+='\n';
    }

    if(cnt==0)
        ui->textBrowser->setText("ITEM NOT FOUND!");
    else{
        QString str=QString::fromUtf8(ans.c_str());
        ui->textBrowser->setText(str);
    }
}


void Search::on_pushButton_4_clicked()      //album
{
    string name=ui->lineEdit->text().toStdString();

    MusicType album, item;
    item.SetAlbum(name);

    acc->MusicList.ResetList();
    int curIdx = acc->MusicList.GetNextItem(album);
    int cnt=0;

    string ans="";
    while (curIdx != -1) {
        if (item.GetAlbum() == album.GetAlbum()) {
            ans+=album.DisplayPKOnScreen();
            ans+=album.DisplayNameOnScreen();
            ans+=album.DisplayArtistOnScreen();
            ans+=album.DisplayGenreOnScreen();
            cnt++;
        }
        curIdx = acc->MusicList.GetNextItem(album);
        ans+='\n';
    }

    if(cnt==0)
        ui->textBrowser->setText("ITEM NOT FOUND!");
    else{
        QString str=QString::fromUtf8(ans.c_str());
        ui->textBrowser->setText(str);
    }
}

void Search::on_pushButton_5_clicked()      //genre
{
    string name=ui->lineEdit->text().toStdString();

    MusicType genre, item;
    item.SetGenre(name);

    acc->MusicList.ResetList();
    int curIdx = acc->MusicList.GetNextItem(genre);
    int cnt=0;

    string ans="";
    while (curIdx != -1) {
        if (item.GetGenre() == genre.GetGenre()) {
            ans+=genre.DisplayPKOnScreen();
            ans+=genre.DisplayNameOnScreen();
            ans+=genre.DisplayArtistOnScreen();
            ans+=genre.DisplayAlbumOnScreen();
            cnt++;
        }
        curIdx = acc->MusicList.GetNextItem(genre);
        ans+='\n';
    }

    if(cnt==0)
        ui->textBrowser->setText("ITEM NOT FOUND!");
    else{
        QString str=QString::fromUtf8(ans.c_str());
        ui->textBrowser->setText(str);
    }
}
