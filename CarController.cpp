#include "CarController.h"

CarController::CarController() : UserRepository()
{
	table = "carsspecification";
}

CarController::~CarController()
{
}

void CarController::SelectData()
{
	QSqlQuery *query = new QSqlQuery();
	query->prepare(QString("SELECT * FROM %1 WHERE carBody=:carBody AND enginePower<=:enginePower AND fuelConsumption<=:fuelConsumption AND carPrice<=:carPrice ORDER BY carPrice DESC LIMIT 3;").arg(table));
	query->bindValue(":carBody", inputCarModel.carBody);
	query->bindValue(":enginePower", inputCarModel.enginePower);
	query->bindValue(":fuelConsumption", inputCarModel.fuelConsumption);
	query->bindValue(":carPrice", inputCarModel.carPrice);

	if (!query->exec())
	{
		qDebug() << "SQL error: " << query->lastError();
	}

	while(query->next()){
		CarModel m;
		m.id = query->value(0).toInt();
		m.carBrand = query->value(1).toString();
		m.carModel = query->value(2).toString();
		m.enginePower = query->value(3).toInt();
		m.carBody = query->value(4).toInt();
		m.fuelConsumption = query->value(5).toFloat();
		m.carPrice = query->value(6).toInt();
		outputCarModel.push_back(m);
	}

	query = NULL;
}

void CarController::setInputCarModel(CarModel inputCarModel)
{
	this->inputCarModel = inputCarModel;
}

CarModel CarController::getInputCarModel()
{
	return this->inputCarModel;
}

QVector<CarModel> CarController::getOutputCarModel()
{
	return this->outputCarModel;
}
