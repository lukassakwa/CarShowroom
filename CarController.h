#pragma once

#include "UserRepository.h"
#include "CarModel.h";

class CarController : public UserRepository
{
public:
	CarController();
	~CarController();

	virtual void SelectData() override;
	
	//setters & getters
	void setInputCarModel(CarModel inputCarModel);
	CarModel getInputCarModel();
	QVector<CarModel> getOutputCarModel();

private:

	CarModel inputCarModel;
	QVector<CarModel> outputCarModel;
};

