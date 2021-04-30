#include "AdminController.h"

AdminController::AdminController() : AdminRepository()
{
	table = "carsspecification";
	operation = false;
}

AdminController::~AdminController()
{
}

void AdminController::InsertData()
{
	QSqlQuery* query = new QSqlQuery();
	query->prepare(QString("INSERT INTO %1(carBrand,model,enginePower,carBody,fuelConsumption,carPrice) VALUES(:brand,:model,:engine,:body,:fuel,:price);").arg(table));
	query->bindValue(":brand",carModel.carBrand);
	query->bindValue(":model", carModel.carModel);
	query->bindValue(":engine", carModel.enginePower);
	query->bindValue(":body", carModel.carBody);
	query->bindValue(":fuel", carModel.fuelConsumption);
	query->bindValue(":price", carModel.carPrice);
	if(query->exec())
		operation = true;
	
	delete query;
}

void AdminController::UpdateData()
{
	//QSqlQuery* query = new QSqlQuery();
	//query->prepare(QString("UPDATE %1 SET carBrand=:brand, model=:model, enginePower=:engine, carBody=:body, fuelConsumption=:fuel, carPrice=:price WHERE Id=:id; ").arg(table));
	//query->bindValue(":brand", carModel.carBrand);
	//query->bindValue(":model", carModel.carModel);
	//query->bindValue(":engine", carModel.enginePower);
	//query->bindValue(":body", carModel.carBody);
	//query->bindValue(":fuel", carModel.fuelConsumption);
	//query->bindValue(":price", carModel.carPrice);
	//if (query->exec())
	//	operation = true;

	//delete query;
}

void AdminController::DeleteData()
{
	//usuwanie 
}
