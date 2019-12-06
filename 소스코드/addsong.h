#ifndef ADDSONG_H
#define ADDSONG_H

#include <QDialog>
#include"musictype.h"
#include"account.h"

namespace Ui {
class AddSong;
}

class AddSong : public QDialog
{
    Q_OBJECT

public:
    explicit AddSong(QWidget *parent = 0);
    ~AddSong();

    /**
    *	@brief	get acc.
    *	@pre	None.
    *	@post	this->acc를 멤버변수 acc로 가져오기 위한 함수.
    */
    void applyAccount(Account* acc);

private slots:

    /**
    *	@brief	MusicList에 음악 추가.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_clicked();

private:
    friend class Account;

    Ui::AddSong *ui;
    Account *acc;
};

#endif // ADDSONG_H
