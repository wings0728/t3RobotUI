#ifndef T3_AF_USERDATABASE_H
#define T3_AF_USERDATABASE_H

#include "t3_af_config.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

class T3_AF_userDatabase
{
public:
    bool createConnection();
    bool removeConnection();
    bool createTable();
    bool insert();
    void queryAll();
    QSqlRecord searchByUserName(QString user);
};

#endif // T3_AF_USERDATABASE_H
