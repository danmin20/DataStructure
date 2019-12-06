#include "fileout.h"
#include "ui_fileout.h"
#include <QMessageBox>

FileOut::FileOut(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileOut)
{
    ui->setupUi(this);
}

FileOut::~FileOut()
{
    delete ui;
}

void FileOut::applyAccount(Account *acc){
    this->acc=acc;
}

void FileOut::on_pushButton_clicked()
{
    MusicType item;

    const char* filename;
    filename=ui->lineEdit->text().toStdString().c_str();

    if (!OpenOutFile(filename))
        QMessageBox::information(this,"ERROR","File Error!");

    else{
        acc->MusicList.ResetList();

        int curIdx = acc->MusicList.GetNextItem(item);

        while (curIdx != -1) {
            item.WriteDataToFile(m_oFile);
            curIdx = acc->MusicList.GetNextItem(item);
        }

        m_oFile.close();
        QMessageBox::information(this,"SUCCESS","File Out Success!");
    }
}

int FileOut::OpenOutFile(const char* fileName) {
    m_oFile.open(fileName);

    if (!m_oFile)
        return 0;
    else return 1;
}
