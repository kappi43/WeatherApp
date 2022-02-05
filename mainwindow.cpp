#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , engine("d194df2aacc80f1757cd0a17ea580e51")
{
    ui->setupUi(this);

    QObject::connect(engine.getNetworkManager(),  &QNetworkAccessManager::finished, this,[=](QNetworkReply *reply)
    {
        if (reply->error())
        {
            qDebug() << reply->errorString();
            return;
        }
        QJsonParseError parseError;
        QJsonDocument replyAsJson = QJsonDocument::fromJson(reply->readAll(), &parseError);
        QJsonObject jsonObject = replyAsJson.object();
        setTemp(jsonObject["main"].toObject()["temp"].toDouble());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_commandLinkButton_clicked()
{
    ui->label_3->setText(ui->comboBox->currentText());
    engine.getWeatherDataForCity(ui->comboBox->currentText());
}

void MainWindow::setTemp(double temperature)
{
     ui->label_4->setText(QString::number(temperature));
}
