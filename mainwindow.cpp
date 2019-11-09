#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    area = new DrawArea;
    setCentralWidget(area);
    createToolBar();
    setMinimumSize(600,400);
    showStyle();
    area->setWidth(widthSpinBox->value());
    area->setColor(Qt::black);

}

MainWindow::~MainWindow()
{
}

void MainWindow::createToolBar()
{
    QToolBar *toolbar = addToolBar("toolbar");
    styleLabel = new QLabel(QString::fromLocal8Bit("线性风格："),this);
    styleComboBox = new QComboBox;
    styleComboBox->addItem("SolidLine",static_cast<int>(Qt::SolidLine));
    styleComboBox->addItem("DashLine",static_cast<int>(Qt::DashLine));
    styleComboBox->addItem("DotLine",static_cast<int>(Qt::DotLine));
    styleComboBox->addItem("DashDotLine",static_cast<int>(Qt::DashDotLine));
    styleComboBox->addItem("DashDotDotLine",static_cast<int>(Qt::DashDotDotLine));
    void (QComboBox::*intActivated)(int) = &QComboBox::activated;
    connect(styleComboBox,intActivated,this,&MainWindow::showStyle);

    widthLabel = new QLabel(QString::fromLocal8Bit("线宽："),this);
    widthSpinBox = new QSpinBox;
    widthSpinBox->setRange(1,20);
    widthSpinBox->setValue(1);
    void (QSpinBox::*intValueChanged)(int) = &QSpinBox::valueChanged;
    connect(widthSpinBox,intValueChanged,this,&MainWindow::showWidth);

    colorBtn = new QToolButton;
    QPixmap pixmap(20,20);
    pixmap.fill(Qt::black);
    colorBtn->setIcon(QIcon(pixmap));
    connect(colorBtn,&QToolButton::clicked,this,&MainWindow::showColor);


    clearBtn = new QToolButton;
    clearBtn->setText(QString::fromLocal8Bit("清除"));
    connect(clearBtn,&QToolButton::clicked,area,&DrawArea::clear);

    toolbar->addWidget(styleLabel);
    toolbar->addWidget(styleComboBox);
    toolbar->addWidget(widthLabel);
    toolbar->addWidget(widthSpinBox);
    toolbar->addWidget(colorBtn);
    toolbar->addWidget(clearBtn);
}

void MainWindow::showStyle()
{
    int s = styleComboBox->itemData(styleComboBox->currentIndex(),Qt::UserRole).toInt();
    area->setStyle(s);
}

void MainWindow::showWidth(int w)
{
    area->setWidth(w);
}
void MainWindow::showColor()
{
    QColor color = QColorDialog::getColor(Qt::black,this);
    if(color.isValid())
    {
        area->setColor(color);
        QPixmap pixmap(20,20);
        pixmap.fill(color);
        colorBtn->setIcon(QIcon(pixmap));
    }
}
