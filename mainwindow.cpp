#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->dateCurrent->setDate(QDate::currentDate());
    ui->dateBirthday->setDate(QDate(1985, 4, 24));
    calculateAge();

    connect(ui->dateBirthday, &QDateEdit::userDateChanged, this, &MainWindow::calculateAge);
    connect(ui->dateCurrent, &QDateEdit::userDateChanged, this, &MainWindow::calculateAge);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateAge()
{
    QDate birthday = ui->dateBirthday->date();
    QDate today    = ui->dateCurrent->date();

    int age = today.year() - birthday.year();
    if (birthday > today.addYears(-age))
        age--;

    ui->lblText->setText(QString("The person is %1 years old.").arg(age));
}

void MainWindow::on_btnInfo_clicked()
{
    QString text("<h1>Age Calculator</h1><h4>License: Public Domain</h4><hr>"
                 "<h2>Praise and thanks to:</h2>"
                 "<p style=\"text-align: right;\"><b>The Lord Jesus Christ<br> and the King James "
                 "Bible</b></p>"
                 "<p style=\"text-align: right;\"><a "
                 "href=\"https://www.youtube.com/watch?v=vzNgaorqo_k\">Brother Mark Hunter</a></p>"
                 "<p style=\"text-align: right;\"><a "
                 "href=\"https://www.youtube.com/channel/UC_QvKE6YsXMD5mbCafJUBKA\">Brother Rick "
                 "Jacoby</a></p>");
    QMessageBox::information(this, "Information", text);
}
