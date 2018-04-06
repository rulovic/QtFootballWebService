//
// Author:  Raul Sanchez
// Created: 5/04/2018
//

#ifndef STANDINGSTAB_H
#define STANDINGSTAB_H

#include <QNetworkAccessManager>
#include <QWidget>

class QNetworkRequest;
class QNetworkReply;
class QPushButton;

class StandingsTab : public QWidget {
    Q_OBJECT
    public:
        StandingsTab(QWidget* parent);
        ~StandingsTab();
    private:
        void createComponents();
        void createRequest();
        QNetworkRequest* _httpRequest;
        QPushButton* _runButton;
        QNetworkAccessManager* _networkManager;
    private slots:
        void doRequest();
        void checkResult(QNetworkReply* reply);
};

#endif // STANDINGSTAB_H
