#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<QComboBox>
#include<QSpinBox>
#include<QToolButton>
#include<QPushButton>
#include<QToolBar>
#include<QColor>
#include<QColorDialog>
#include"drawarea.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createToolBar();
private:
    DrawArea *area;
    QLabel *styleLabel;
    QComboBox *styleComboBox;
    QLabel *widthLabel;
    QSpinBox *widthSpinBox;
    QToolButton *colorBtn;
    QToolButton *clearBtn;
public slots:
    void showStyle();
    void showWidth(int w);
    void showColor();
};
#endif // MAINWINDOW_H
