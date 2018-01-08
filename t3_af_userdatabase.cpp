#include "t3_af_userdatabase.h"

//建立链接
bool T3_AF_userDatabase::createConnection()
{
    QSqlDatabase userDatabase_ = QSqlDatabase::addDatabase("QSQLITE","connectToUserDatabase");
    userDatabase_.setDatabaseName("T3_AF_userDatabase");
    if(!userDatabase_.open())
    {
        T3LOG("userDatabase创建失败");
        return false;
    }
    else
    {
        T3LOG("userDatabase创建成功");
        return true;
    }
}

//断开链接
bool T3_AF_userDatabase::removeConnection()
{
    QSqlDatabase::removeDatabase("connectToUserDatabase");
    T3LOG("UserDatabase断开链接");
    return true;
}

//创建表单
bool T3_AF_userDatabase::createTable()
{
    QSqlDatabase userDatabase_ = QSqlDatabase::database("connectToUserDatabase");
    QSqlQuery query(userDatabase_);
    bool success_ = query.exec("create table userInfo(userName QString primary key,"
                                                     "password QString)");
    if(success_)
    {
        T3LOG("tabel创建成功");
        return true;
    }
    else
    {
        T3LOG("tabel创建失败");
        return false;
    }
}

//插入行
bool T3_AF_userDatabase::insert()
{
    QSqlDatabase userDatabase_ = QSqlDatabase::database("connectToUserDatabase");
    QSqlQuery query(userDatabase_);
    query.exec("insert into userInfo values('cc', '666')");
    query.exec("insert into userInfo values('ccmorning', 'a000000A')");
    return true;
}

//查询全部
void T3_AF_userDatabase::queryAll()
{
    QSqlDatabase userDatabase_ = QSqlDatabase::database("connectToUserDatabase");
    QSqlQuery query(userDatabase_);
    query.exec("select * from userInfo");
    while(query.next())
    {
        qDebug() << query.value(0).toString()
                 << query.value(1).toString();
    }
}

//根据用户名查询
QSqlRecord T3_AF_userDatabase::searchByUserName(QString user)
{
    QSqlDatabase userDatabase_ = QSqlDatabase::database("connectToUserDatabase");
    QSqlQuery query(userDatabase_);

    query.prepare("select * from userInfo where userName = ?");
    query.addBindValue(user);
    query.exec();
    query.last();

    return query.record();
}
