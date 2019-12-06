#ifndef FILEOUT_H
#define FILEOUT_H

#include <QDialog>
#include "account.h"

namespace Ui {
class FileOut;
}

class FileOut : public QDialog
{
    Q_OBJECT

public:
    explicit FileOut(QWidget *parent = 0);
    ~FileOut();

    /**
    *	@brief	파일 디스크립터를 이용하여 쓸 파일을 연다.
    *	@pre	쓸 파일이 존재해야 한다.
    *	@post	쓸 파일을 연다.
    *	@param	fileName	쓸 파일을 여는 descriptor.
    *	@return	함수가 제대로 작동 되었으면 1을, 그렇지 않으면 0을 반환한다.
    */
    int OpenOutFile(const char* fileName);

    /**
    *	@brief	get acc.
    *	@pre	None.
    *	@post	this->acc를 멤버변수 acc로 가져오기 위한 함수.
    */
    void applyAccount(Account* acc);

private slots:
    void on_pushButton_clicked();

private:
    friend class Account;
    Ui::FileOut *ui;

    Account* acc;
    ofstream m_oFile;
};

#endif // FILEOUT_H
