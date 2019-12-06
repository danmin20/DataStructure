#ifndef DELETESONG_H
#define DELETESONG_H

#include <QDialog>
#include"account.h"

namespace Ui {
class DeleteSong;
}

class DeleteSong : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteSong(QWidget *parent = 0);
    ~DeleteSong();

    /**
    *	@brief	get acc.
    *	@pre	None.
    *	@post	this->acc를 멤버변수 acc로 가져오기 위한 함수.
    */
    void applyAccount(Account* acc);

private slots:
    /**
    *	@brief	MusicList에서 음악 삭제.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_clicked();

private:
    friend class Account;

    Ui::DeleteSong *ui;
    Account* acc;
};

#endif // DELETESONG_H
