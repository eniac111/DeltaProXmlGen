#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("DP XML Generator " + APP_VERSION);
    this->setFixedSize(500,260);
    this->setGeometry(QStyle::alignedRect(
                          Qt::LeftToRight,
                          Qt::AlignCenter,
                          this->size(),
                          qApp->desktop()->availableGeometry()
                          ));
//    if (QCoreApplication::arguments().length() >=2) {
//        QString argvstr = QCoreApplication::arguments().at(1);
//        filename = argvstr.section("/",-1,-1);
//        ui->FileLabel->setText(filename);
//        doEncrypt(QString(filename));
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_BtnBrowse_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this, "Open a file for encryption", QString(), "Comma Separated Value Files (*.csv)");
    filename = filepath;
    ui->FileLabel->setText(filepath.section("/",-1,-1));

}


void MainWindow::on_actionAbout_triggered()
{
    About *AboutWindow = new About(this);
    AboutWindow->show();
}

int MainWindow::ReadExcel(QString file)
{
    QString xmlfile = file.left(file.length()-3) + QString("xml");
    qDebug (xmlfile.toLatin1());
    QVector<QVector<QString>> xlsdata;
    QFile csvf(file);
    if (!csvf.open(QIODevice::ReadOnly)) {
        qDebug () << csvf.errorString();
        return 1;
    }

    QTextStream csvstr(&csvf);
    csvstr.setCodec("UTF-8");

    while(!csvstr.atEnd())
    {
        QString line = csvstr.readLine();
            xlsdata.push_back(line.split(':').toVector());
    }

    csvf.close();

    GenXML *Generator = new GenXML(xlsdata, xmlfile);
    Generator->Convert();
    delete Generator;

//     qDebug(xlsdata[100][0].toLatin1());


    return 0;

}

void MainWindow::on_BtnSaveAs_clicked()
{
    ReadExcel(filename);
}
