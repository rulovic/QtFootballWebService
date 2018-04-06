//
// Author:  Raul Sanchez
// Created: 5/04/2018
//
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow {

Q_OBJECT
public:
    MainWindow(QWidget *parent=Q_NULLPTR);
private:
    void initUi();
};

#endif // MAINWINDOW_H
