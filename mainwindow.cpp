#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("DeltaPro XML Generator");
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
    QString filepath = QFileDialog::getOpenFileName(this, "Open a file for encryption", QString(), "Excel Spreadsheets (*.xlsx)");
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

    QXlsx::Document *xlsx = new QXlsx::Document(file);
    QString xmlfile = file.left(file.length()-1) + QString(".xml");
    int num_of_row = xlsx->dimension().lastRow();
    int num_of_col = xlsx->dimension().lastColumn();
    QVector<QVector<QString>> xlsdata;

//    if (xlsx.rowHeight(3) != 15) {
//        QMessageBox::warning(this, tr("Warning: Incorrect format"),
//                             tr("The number of cells does not match the format of the document!"),
//                             QMessageBox::Ok);
//        return 2;
//    }

    for(int row=2; row <= num_of_row; ++row)
    {
        for(int col=0; col<=num_of_col; col++){
            if( QXlsx::Cell *cell = xlsx->cellAt(row, col)) {
                QVector<QString> tmp;
                tmp.push_back(cell->value().toString());
                xlsdata.push_back(tmp);
            }
        }
        }


//    QFile file(xmlfile);
//    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
//        return 0;


    return 0;
}

void MainWindow::on_BtnSaveAs_clicked()
{
    ReadExcel(filename);
}
