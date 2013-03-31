#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
        Q_OBJECT

    public:
        explicit Widget(QWidget *parent = 0);
        ~Widget();
        QImage mouseHistory;
        QTimer mouseSnapshot;
        QPoint lastMousePos;
        QColor penColor;
    private:
        Ui::Widget *ui;
    public slots:
        void tick();
        void saveImage();
};

#endif // WIDGET_H
