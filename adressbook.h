#ifndef ADRESSBOOK_H
#define ADRESSBOOK_H

#include <QWidget>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui { class adressbook; }
QT_END_NAMESPACE

class adressbook : public QWidget
{
    Q_OBJECT

public slots:
    void save();

    void fromJson(const QJsonObject&);

    QJsonObject toJson() const;

private slots:
    void markUnsavedChanges();

signals:
    void propertiesChanged(const QJsonObject&);

public:
    adressbook(QWidget *parent = nullptr);
    ~adressbook();

private:
    Ui::adressbook *ui;
};
#endif // ADRESSBOOK_H
