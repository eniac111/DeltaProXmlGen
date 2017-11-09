#ifndef GENXML_H
#define GENXML_H
#include <QString>
#include <QMap>
#include <QVector>
#include <QtXml>
#include <QDomDocument>
#include <QDomElement>


class GenXML
{
public:
    GenXML( QVector<QVector< QString>> data, QString file);
    QVector<QVector<QString>> tabledata;
    QString xmlfile;
    int Convert();

private:

};

#endif // GENXML_H
