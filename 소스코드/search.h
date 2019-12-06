#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include"account.h"

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = 0);
    ~Search();

    /**
    *	@brief	get acc.
    *	@pre	None.
    *	@post	this->acc를 멤버변수 acc로 가져오기 위한 함수.
    */
    void applyAccount(Account* acc);

private slots:
    /**
    *	@brief	곡 PK로 검색.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_clicked();

    /**
    *	@brief	곡 제목으로 검색.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_2_clicked();

    /**
    *	@brief	곡 가수로 검색.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_3_clicked();

    /**
    *	@brief	곡 앨범으로 검색.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_4_clicked();

    /**
    *	@brief	곡 장르로 검색.
    *	@pre	None.
    *	@post	None.
    */
    void on_pushButton_5_clicked();

private:
    friend class Account;

    Ui::Search *ui;
    Account* acc;
};

#endif // SEARCH_H
