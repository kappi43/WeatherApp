#include "engine.h"
Engine::Engine(QString key)
{
    apiKey = key;
    networkManager = new QNetworkAccessManager();
    QObject::connect(networkManager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply)
    {
        if (reply->error())
        {
            qDebug() << reply->errorString();
            return;
        }
        QString answer = reply->readAll();
        qDebug() << answer;
    });
}

QJsonArray Engine::getWeatherDataForCity(QString cityName)
{
    QString url = "https://api.openweathermap.org/data/2.5/weather?q=";
    url = url.append(cityName).append("&appid=").append(apiKey);
    QNetworkRequest weatherRequest{QUrl(url)};
    networkManager->get(weatherRequest);

}

