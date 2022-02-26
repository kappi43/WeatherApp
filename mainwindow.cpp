#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , engine("d194df2aacc80f1757cd0a17ea580e51")
{
    ui->setupUi(this);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
    QObject::connect(engine.getNetworkManager(),  &QNetworkAccessManager::finished, this,[=](QNetworkReply *reply)
    {
        ui->progressBar->setValue(99);
        if (reply->error())
        {
            qDebug() << reply->errorString();
            return;
        }
        QJsonParseError parseError;
        QJsonDocument replyAsJson = QJsonDocument::fromJson(reply->readAll(), &parseError);
        QJsonObject jsonObject = replyAsJson.object();
        setTemp(jsonObject["main"].toObject()["temp"].toDouble());
        ui->progressBar->reset();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_commandLinkButton_clicked()
{
    ui->label_3->setText(ui->comboBox->currentText());
    ui->progressBar->setValue(20);
    engine.getWeatherDataForCity(ui->comboBox->currentText());
    ui->progressBar->setValue(80);
}

void MainWindow::setTemp(double temperature)
{
     ui->label_4->setText(QString::number(temperature));
}
