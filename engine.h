#ifndef ENGINE_H
#define ENGINE_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QMainWindow>

class Engine : QObject
{
public:
    Engine(QString apiKeyd);
    void getWeatherDataForCity(QString cityName);
    QNetworkAccessManager* getNetworkManager();

private:
    int getTemperatureFromReply();
    QString apiKey;
    QNetworkAccessManager* networkManager;
    QNetworkRequest getWeatherRequestForCity(QString cityName);
};

#endif // ENGINE_H
