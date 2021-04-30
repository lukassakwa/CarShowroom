#pragma once

#include <QtSql>
#include <QSqlDatabase>

class DatabaseController
{
protected:
	DatabaseController();
	~DatabaseController();

protected:
	QSqlDatabase *qSqlDatabase;

	const QString sqlDriver = "QMYSQL";
	const QString host = "localhost";
	const QString database = "carshowroom";
	const QString username = "username";
	const QString password = "password";
	QString table = "";
	const int port = 3306;
};