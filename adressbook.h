#ifndef ADRESSBOOK_H
#define ADRESSBOOK_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class adressbook; }
QT_END_NAMESPACE

class adressbook : public QWidget
{
    Q_OBJECT

public:
    adressbook(QWidget *parent = nullptr);
    ~adressbook();

private:
    Ui::adressbook *ui;
};
#endif // ADRESSBOOK_H
