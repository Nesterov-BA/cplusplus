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
  ui->label->setText(QString::number(value));

  // METHOD 2: Get the value directly from the slider (if you need it later)
  // int currentValue = m_slider->value();
  // m_label->setText(QString::number(currentValue));
}
