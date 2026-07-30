#include "widget.h"
#include "ui_widget.h"
#include <iostream>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  // boilerplate UI code
  ui->setupUi(this);
  // initialize variables
  count = 0;
  // connect signals
  connect(ui->pushButton, &QPushButton::clicked, this,
          &Widget::onButtonClicked);
  connect(ui->horizontalSlider, &QSlider::valueChanged, this,
          &Widget::onSliderValueChanged);
}

Widget::~Widget() { delete ui; }

void Widget::onButtonClicked() {
  // Do your interactive stuff here
  std::cout << count << "NIGGERS\n";
  count++;
}

void Widget::onSliderValueChanged(int value) {
  // METHOD 1: Use the value passed by the signal (recommended)
  double val = value;
  val = val * 100 / 99;
  val /= 10;
  ui->label->setText(QString::number(val));
}
