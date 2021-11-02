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
        QJsonParseError parseError;
        QJsonDocument replyAsJson = QJsonDocument::fromJson(reply->readAll(), &parseError);
        qDebug() << replyAsJson.object().value("main");
    });
}

QJsonArray Engine::getWeatherDataForCity(QString cityName)
{
    QString url = "https://api.openweathermap.org/data/2.5/weather?q=";
    url = url.append(cityName).append("&appid=").append(apiKey).append("&units=metric");
    QNetworkRequest weatherRequest{QUrl(url)};
    networkManager->get(weatherRequest);

}

