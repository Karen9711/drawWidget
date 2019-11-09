#include "drawarea.h"

DrawArea::DrawArea(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    pix = new QPixmap(size());
    pix->fill(Qt::white);
    setMinimumSize(600,400);
}

void DrawArea::setWidth(int w)
{
    m_width = w;
}

void DrawArea::setStyle(int s)
{
    style = s;

}
void DrawArea::clear()
{
    QPixmap *clrPix = new QPixmap(size());
    clrPix->fill(Qt::white);
    pix = clrPix;
    update();
}
void DrawArea::setColor(QColor c)
{
    color = c;
}

void DrawArea::mousePressEvent(QMouseEvent *event)
{
    startPos = event->pos();
}
void DrawArea::mouseMoveEvent(QMouseEvent *event)
{
    QPainter *painter = new QPainter;
    QPen pen;
    pen.setStyle((Qt::PenStyle)style); //--强制类型转换？
    pen.setWidth(m_width);
    pen.setColor(color);
    painter->begin(pix);//begin之后画笔的状态恢复默认状态
    painter->setPen(pen);
    painter->drawLine(startPos,event->pos());//小段直线连成曲线
    painter->end();
    startPos = event->pos();//重置开始位置
    update();//更新画面
}
void DrawArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,*pix);
}
void DrawArea::resizeEvent(QResizeEvent *event)
{
    if(this->height() > pix->height()||this->width() >pix->width())
    {
        QPixmap *newPix = new QPixmap(size());	//创建一个新的QPixmap对象
        newPix->fill(Qt::white);                //填充新QPixmap对象newPix的颜色为白色背景色
        QPainter p(newPix);
        p.drawPixmap(QPoint(0,0),*pix);         //在newPix中绘制原pix中的内容
        pix = newPix;                           //将newPix赋值给pix作为新的绘制图形接收对象
    }
    QWidget::resizeEvent(event);                //完成其余的工作
}
