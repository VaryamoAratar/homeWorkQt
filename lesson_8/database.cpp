#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{

    dataBase = new QSqlDatabase();

}

DataBase::~DataBase()
{
    delete dataBase;

}

/*!
 * \brief Метод добавляет БД к экземпляру класса QSqlDataBase
 * \param driver драйвер БД
 * \param nameDB имя БД (Если отсутствует Qt задает имя по умолчанию)
 */
void DataBase::AddDataBase(QString driver, QString nameDB)
{

    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);
}

/*!
 * \brief Метод подключается к БД
 * \param для удобства передаем контейнер с данными необходимыми для подключения
 * \return возвращает тип ошибки
 */
void DataBase::ConnectToDataBase(QVector<QString> data)
{

    dataBase->setHostName(data[hostName]);
    dataBase->setDatabaseName(data[dbName]);
    dataBase->setUserName(data[login]);
    dataBase->setPassword(data[pass]);
    dataBase->setPort(data[port].toInt());

    bool status;
    status = dataBase->open( );
    emit sig_SendStatusConnection(status);

}
/*!
 * \brief Метод производит отключение от БД
 * \param Имя БД
 */
void DataBase::DisconnectFromDataBase(QString nameDb)
{

    *dataBase = QSqlDatabase::database(nameDb);
    dataBase->close();

}
/*!
 * \brief Метод формирует запрос к БД.
 * \param request - SQL запрос
 * \return
 */
void DataBase::RequestToDB(QString request)
{
    if (request.isEmpty())
    {
    tableWidgetModel = new QSqlTableModel(this, *dataBase);

    tableWidgetModel->setTable("film");
    tableWidgetModel->select();
    tableWidgetModel->setHeaderData(1, Qt::Horizontal, tr("Название фильма"));
    tableWidgetModel->setHeaderData(2, Qt::Horizontal, tr("Описание фильма"));

    emit sig_SendDataFromDB(tableWidgetModel, requestAllFilms);
    }
    else
    {
        simpleQueryModel = new QSqlQueryModel(this);
        simpleQueryModel->setQuery(request, *dataBase);
        simpleQueryModel->setHeaderData(0, Qt::Horizontal, tr("Название фильма"));
        simpleQueryModel->setHeaderData(1, Qt::Horizontal, tr("Описание фильма"));

    emit sig_SendDataFromDB(simpleQueryModel, ANY);
    }
}


/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}
