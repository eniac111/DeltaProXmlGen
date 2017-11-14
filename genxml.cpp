#include "genxml.h"

GenXML::GenXML( QVector<QVector<QString>> data, QString file )
{
    tabledata = data;
    xmlfile = file;
}


int GenXML::Convert () {
    QDomDocument xmldoc;
    QString direction;
    QString detail_number;
    QString sum;
    xmldoc.appendChild(xmldoc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\""));

    QDomElement TransferData = xmldoc.createElement("TransferData");
    TransferData.setAttribute("xmlns", "urn:Transfer");
    QDomElement Accounts = xmldoc.createElement("Accounts");
    QDomElement Accountings = xmldoc.createElement("Accountings");
//    qDebug (xmldoc.toString().toLatin1());

//    qDebug("RAZMER: %i", tabledata[1].size());
//    qDebug(QString(current_date()).toLatin1());

    for( int i=1; i<tabledata.size()-1; i++) {
        QString DocType;

        if(tabledata[i][0] == QString("Фактура")) {
            DocType = "1";
        }
        else if (tabledata[i][0] == QString("Дебитна нота")) {
            DocType = "2";
        }
        else if (tabledata[i][0] == QString("Кредитна нота")) {
            DocType = "3";
        }

        QDomElement Accounting = xmldoc.createElement("Accounting");
        Accounting.setAttribute("AccountingDate",  tabledata[i][1]);
        Accounting.setAttribute("Term", "Продажба на СМЦ");
        Accountings.appendChild(Accounting);

        QDomElement Document = xmldoc.createElement("Document");
        Document.setAttribute("DocumentType", DocType);
        Document.setAttribute("Number", tabledata[i][2]);
        Document.setAttribute("Date", tabledata[i][1]);
        Accounting.appendChild(Document);

        QDomElement Company = xmldoc.createElement("Company");
        Company.setAttribute("Name", "НАСЕЛЕНИЕ");
        Accounting.appendChild(Company);

        QDomElement AccountingDetails = xmldoc.createElement("AccountingDetails");
        Accounting.appendChild(AccountingDetails);

        for( int j=0; j<=2; j++){
            if (j == 0){
                detail_number = "702";
                direction = "Credit";
                sum = tabledata[i][7].replace(",", ".");
//                qDebug(tabledata[i][7].toLatin1());
            }
            else if(j == 1) {
                detail_number = "453/5";
                direction = "Credit";
                sum = tabledata[i][8].replace(",", ".");
//                qDebug(tabledata[i][8].toLatin1());
            }
            else if (j == 2){
                detail_number = "411";
                direction = "Debit";
                sum = tabledata[i][6].replace(",", ".");
            }

            QDomElement AccountingDetail = xmldoc.createElement("AccountingDetail");
            AccountingDetail.setAttribute("AccountNumber", detail_number);
            AccountingDetail.setAttribute("Direction", direction);
            AccountingDetail.setAttribute("Amount", sum);
            AccountingDetails.appendChild(AccountingDetail);

        }

    }

    TransferData.appendChild(Accounts);
    TransferData.appendChild(Accountings);
    xmldoc.appendChild(TransferData);

    QFile outfile(xmlfile);
    if( !outfile.open( QIODevice::WriteOnly | QIODevice::Text ) )
     {
       qDebug( "Failed to open file for reading." );
       return 0;
     }

    QTextStream stream( &outfile );
    stream.setCodec("UTF-8");
    stream << xmldoc.toString();
    outfile.close();
    return 0;
}

QString GenXML::current_date(){
    QString current_day;
    QString current_month;
    QString current_year;

    QDate date = QDate::currentDate();
    if (date.day() < 10) {
        current_day = QString("0") + QString::number(date.day());
    }
    else {
        current_day = QString::number(date.day());
    }
    if (date.month() < 10 ) {
        current_month =  QString("0") + QString::number(date.month());
    }
    else {
        current_month = QString::number(date.month());
    }
    current_year = QString::number(date.year());

    return current_year + QString("-") + current_month +  QString("-") + current_day;
}
