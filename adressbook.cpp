#include "adressbook.h"
#include "ui_adressbook.h"

adressbook::adressbook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::adressbook)
{
    ui->setupUi(this);
}

adressbook::~adressbook()
{
    delete ui;
}

