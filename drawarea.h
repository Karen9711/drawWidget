#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include<QPaintEvent>
#include<QPainter>
#include<QPoint>
#include<QPixmap>
#include<QMouseEvent>
class DrawArea : public QWidget
{
    Q_OBJECT
public:
    explicit DrawArea(QWidget *parent = nullptr);
    //重写鼠标事件 resize事件 绘图事件
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
signals:

public slots:
    void setStyle(int s);
    void setWidth(int w);
    void setColor(QColor c);
    void clear();
private:
    QPoint startPos;
    QPoint endPos;
    int style;
    int m_width;
    QColor color;
    QPixmap *pix;
};

#endif // DRAWAREA_H
