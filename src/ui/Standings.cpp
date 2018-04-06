#include "StandingsTab.h"

#include <QDialogButtonBox>
#include <QEventLoop>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

// Project includes
#include "StandingsListView.h"

StandingsTab::StandingsTab(QWidget* parent) : QWidget(parent) {
    _networkManager = new QNetworkAccessManager;
    createComponents();
    connect(_runButton, SIGNAL(clicked()), this, SLOT(doRequest()));
}

StandingsTab::~StandingsTab() {
    delete _networkManager;
    _networkManager = Q_NULLPTR;
}

void StandingsTab::createComponents() {
    // When you set a layout on a widget, the widget will take ownership of that layout;
    // When you add widgets on a layout, these widgets will be reparented to the widget the layout is/gets installed upon;
    // When you add a layout inside another layout, the inner layout becomes a child of the outer layout.
    QVBoxLayout *tabLayout = new QVBoxLayout;
    StandingsListView *listView = new StandingsListView(this);
    tabLayout->addWidget(listView);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    _runButton = new QPushButton(tr("Run!"), this);
    buttonLayout->addWidget(_runButton, 0, Qt::AlignRight);
    tabLayout->addLayout(buttonLayout);

    setLayout(tabLayout);
}

void StandingsTab::doRequest() {
    _runButton->setEnabled(false);
    QUrl url("http://api.football-data.org/v1/competitions/449/leagueTable");
    QNetworkRequest request;
    request.setUrl(url);
    //url.setPath("/cgi-bin/mathtran");
    //url.setQueryDelimiters('=', ';');
    //url.addQueryItem("D", "3");
    //url.addQueryItem("tex", QUrl::toPercentEncoding(
    //                         equationEditor->toPlainText()));
    connect(_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(checkResult(QNetworkReply*)));
    // QNetworkAccessManager  calls to get() are asynchronous
    _networkManager->get(request);
}

void StandingsTab::checkResult(QNetworkReply* reply) {
    // json tutorial: https://stackoverflow.com/questions/19822211/qt-parsing-json-using-qjsondocument-qjsonobject-qjsonarray
    // http://api.football-data.org/docs/v1/index.html#_competition
    // http://api.football-data.org
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray bts = reply->readAll();
        qDebug("reply: %s", bts.data());
    }
    _runButton->setEnabled(true);
    _networkManager->disconnect();
    reply->deleteLater();
}
