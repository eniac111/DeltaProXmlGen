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
    GenXML( QVector<QVector< QString>> data);
    int Convert();

private:
   QVector<QVector<QString>> tabledata;

};

#endif // GENXML_H
