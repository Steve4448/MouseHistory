#include "widget.h"
#include "ui_widget.h"
#include <QDesktopWidget>
#include <QDebug>
#include <QPainter>
Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui->setupUi(this);
	mouseHistory = QImage(QDesktopWidget().size(), QImage::Format_ARGB32);
	penColor = QColor(0, 0, 0, 50);
	lastMousePos = QCursor::pos();
	mouseSnapshot.setInterval(1000/60);
	mouseSnapshot.start();
	connect(&mouseSnapshot, SIGNAL(timeout()), this, SLOT(tick()));
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(saveImage()));
	ui->label->setText("Recording mouse...");
}

void Widget::tick() {
	QPoint mousePos = QCursor::pos();
	if(mousePos == lastMousePos)
		return;
	QPainter p(&mouseHistory);
	p.setRenderHint(QPainter::Antialiasing);
	p.setPen(penColor);
	p.drawLine(lastMousePos, mousePos);
	lastMousePos = mousePos;
}

void Widget::saveImage() {
	mouseHistory.save("test.png");
}

Widget::~Widget()
{
	delete ui;
}
