#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QChar>
#include <QVector>
#include <QMap>
#include <QStringList>
#include <QFileDialog>
#include <QDesktopWidget>
#include "about.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QtXlsx>
#include <QMessageBox>
#include <QDomDocument>
#include <QDateTime>
#include "genxml.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_BtnBrowse_clicked();
    void on_actionExit_triggered();
    void on_actionAbout_triggered();
    void on_BtnSaveAs_clicked();

private:
    Ui::MainWindow *ui;
    QString filename = "";
    int ReadExcel(QString file);
    int WriteXML();
    QVector<QVector<QString>>  *tabledata = new QVector<QVector<QString>>;
};

#endif // MAINWINDOW_H
