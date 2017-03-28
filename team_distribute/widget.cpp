#include "widget.h"
#include "ui_widget.h"
#include "model.h"
#include <string>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle(tr("Rand Team"));
    ui->Max_Label->setText(tr("Max"));
    ui->People_Label->setText(tr("How many people in 1 team"));
    ui->Expect_Label->setText(tr("Expect"));

    ui->Rand_pushButton->setText(tr("Start"));
    ui->Out_Edit->setReadOnly(true);

    ui->People_lineEdit->setValidator(new QIntValidator);
    ui->Expect_lineEdit->setValidator(new QIntValidator);
    ui->Max_lineEdit->setValidator(new QIntValidator);

    QFont font = QFont ("Courier");
    font.setPointSize (16);
    ui->Out_Edit->setFont(font);
    setFixedSize(664,350);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Rand_pushButton_clicked()
{
     rand_team rt;
     QString lineEditPeople=ui->People_lineEdit->text();
     QString lineEditMax=ui->Max_lineEdit->text();
     //ui->Expect_lineEdit->Text(tr("Expect"));
     rt.max=lineEditMax.toInt();
     rt.people=lineEditPeople.toInt();
     int s[rt.max];
     rt.creat_array(s);
     rt.rand_algorithm(s);
     std::string str=rt.out_put(s);
     ui->Out_Edit->setText(QString::fromStdString(str));
}

