#include <QCoreApplication>
#include <QSqlDatabase>
#include <iostream>
#include <QSqlQuery>
#include <QNetworkAccessManager>
#include <QNetworkRequest>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    bool ok = db.open();
    if (ok){
    QSqlQuery query;
    query.exec("SELECT name from musician_genre");
    while (query.next()) {
        QString name = query.value(0).toString();
        qDebug() << name;
    }};
    QNetworkRequest request (QUrl("http://netology.ru"));
    QNetworkAccessManager net;

   auto out = net.get(request);
   std::cout << &out;
    return 0;
}
