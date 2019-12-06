#ifndef PLAYSONG_H
#define PLAYSONG_H

#include <QDialog>
#include"account.h"

namespace Ui {
class PlaySong;
}

class PlaySong : public QDialog
{
    Q_OBJECT

public:
    explicit PlaySong(QWidget *parent = 0);
    ~PlaySong();

    /**
    *	@brief	get acc.
    *	@pre	None.
    *	@post	this->acc를 멤버변수 acc로 가져오기 위한 함수.
    */
    void applyAccount(Account* acc);

private slots:
    /**
    *	@brief	MusicList의 음악 재생.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_clicked();

private:
    friend class Account;

    Ui::PlaySong *ui;
    Account* acc;
};

#endif // PLAYSONG_H
