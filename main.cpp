#include <QApplication>
#include <QJsonObject>
#include <QString>
#include <QJsonDocument>
#include <QFile>

#include "adressbook.h"

void saveJsonToFile(const QString &filename, const QJsonObject &json)
{
    QFile file(filename);
    if(file.open(QFile::WriteOnly))
    {
        QJsonDocument document(json);
        file.write(document.toJson());
        file.close();
    }
}

QJsonObject loadFromJson(const QString &filename)
{
    QFile file(filename);
    QJsonObject json;

    if(file.open(QFile::ReadOnly))
    {
        QJsonDocument document = QJsonDocument::fromJson(file.readAll());
        file.close();
        json = document.object();
    }
    return json;
}

void saveAdressbookToFile(const QJsonObject &properties)
{
    saveJsonToFile("Adressbook.json", properties);
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    adressbook w;

    QObject::connect(&w, &adressbook::propertiesChanged, &saveAdressbookToFile);

    QJsonObject properties;

    properties["firstName"]			= "firstName";
    properties["secondName"]		= "secondName";
    properties["thirdName"]			= "secondName";
    properties["adress"]			= "secondName";
    properties["homePhoneNumber"]	= "secondName";
    properties["mobilePhoneNumber"] = "secondName";
    properties["notes"]				= "secondName";

    w.show();

    w.fromJson(properties);
    return a.exec();
}
