#ifndef ENGINE_H
#define ENGINE_H

#include <QJsonArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QMainWindow>

class Engine : QObject
{
public:
    Engine(QString apiKey);
    QJsonArray getWeatherDataForCity(QString cityName);

private:
    int getTemperatureFromReply();
    QString apiKey;
    QNetworkAccessManager* networkManager;

};

#endif // ENGINE_H
