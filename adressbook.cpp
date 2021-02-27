#include <QJsonObject>
#include "adressbook.h"
#include "ui_adressbook.h"


adressbook::adressbook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::adressbook)
{
    textModified = false;
    ui->setupUi(this);

    connect(ui->lineEdit_first_name, &QLineEdit::textChanged, this, &adressbook::markUnsavedChanges);
    connect(ui->lineEdit_second_name, &QLineEdit::textChanged, this, &adressbook::markUnsavedChanges);
    connect(ui->lineEdit_adress, &QLineEdit::textChanged, this, &adressbook::markUnsavedChanges);
    connect(ui->lineEdit_home_phone, &QLineEdit::textChanged, this, &adressbook::markUnsavedChanges);
    connect(ui->lineEdit_mobile_phone, &QLineEdit::textChanged, this, &adressbook::markUnsavedChanges);
    connect(ui->lineEdit_patronymic, &QLineEdit::textChanged, this, &adressbook::markUnsavedChanges);
    connect(ui->plainTextEdit_notes, &QPlainTextEdit::textChanged, this, &adressbook::markUnsavedChanges);

    connect(ui->pushButton_save, &QPushButton::clicked, this, &adressbook::save);
}

void adressbook::fromJson(const QJsonObject &properties)
{
    ui->plainTextEdit_notes->blockSignals(true);

    ui->lineEdit_first_name->setText(properties["firstName"].toString());
    ui->lineEdit_second_name->setText(properties["secondName"].toString());
    ui->lineEdit_patronymic->setText(properties["thirdName"].toString());
    ui->lineEdit_adress->setText(properties["adress"].toString());
    ui->lineEdit_home_phone->setText(properties["homePhoneNumber"].toString());
    ui->lineEdit_mobile_phone->setText(properties["mobilePhoneNumber"].toString());
    ui->plainTextEdit_notes->setPlainText(properties["notes"].toString());

    ui->plainTextEdit_notes->blockSignals(false);
}

QJsonObject adressbook::toJson() const
{
    QJsonObject properties;

    properties["firstName"]			= ui->lineEdit_first_name->text();
    properties["secondName"]		= ui->lineEdit_second_name->text();
    properties["thirdName"]			= ui->lineEdit_patronymic->text();
    properties["adress"]			= ui->lineEdit_adress->text();
    properties["homePhoneNumber"]	= ui->lineEdit_home_phone->text();
    properties["mobilePhoneNumber"] = ui->lineEdit_mobile_phone->text();
    properties["notes"]				= ui->plainTextEdit_notes->toPlainText();

    return properties;
}

adressbook::~adressbook()
{
    delete ui;
}

void adressbook::save()
{
    ui->pushButton_save->setText("Сохранить");
    if(textModified)
    {
        textModified = false;
        emit propertiesChanged(toJson());
    }
}

void adressbook::markUnsavedChanges()
{
    ui->pushButton_save->setText("Сохранить*");
    textModified = true;
}
