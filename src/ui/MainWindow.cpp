#include "MainWindow.h"

// Qt includes
#include <QPushButton>
#include <QTabWidget>
#include <QVBoxLayout>

// Project includes
#include "StandingsTab.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    initUi();
}

void MainWindow::initUi() {
    // How to custom QTabWidget tab?
    // https://stackoverflow.com/questions/47094871/how-to-custom-qtabwidget-tab
    // Setting containers as parents we ensure objects will be destroyed
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    QTabWidget* tabWidget = new QTabWidget(centralWidget);
    mainLayout->addWidget(tabWidget);
    StandingsTab *firstTab = new StandingsTab(tabWidget);
    QPushButton* button2 = new QPushButton(tr("ble"), tabWidget);
    tabWidget->addTab(firstTab, tr("Competitions"));
    tabWidget->addTab(button2, tr("Second tab"));
    //QGridLayout *gridLayout = new QGridLayout(centralWidget);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}
