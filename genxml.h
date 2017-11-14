#ifndef GENXML_H
#define GENXML_H
#include <QString>
#include <QVector>
#include <QtXml>
#include <QDomDocument>
#include <QDomElement>
#include <QFile>
#include <QTextStream>



class GenXML
{
public:
    GenXML( QVector<QVector< QString>> data, QString file);
    QVector<QVector<QString>> tabledata;
    QString xmlfile;
    int Convert();

private:
    QString current_date();

};

#endif // GENXML_H
