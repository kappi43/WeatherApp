#include "engine.h"

Engine::Engine(QString key): apiKey(key), networkManager(new QNetworkAccessManager())
{}

QNetworkRequest Engine::getWeatherRequestForCity(QString cityName)
{
    QString url = "https://api.openweathermap.org/data/2.5/weather?q=";
    url = url.append(cityName).append("&appid=").append(apiKey).append("&units=metric");
    QNetworkRequest weatherRequest{QUrl(url)};
    return weatherRequest;
}

void Engine::getWeatherDataForCity(QString cityName)
{
    networkManager->get(getWeatherRequestForCity(cityName));
}

 QNetworkAccessManager* Engine::getNetworkManager()
 {
     return networkManager;
 }

