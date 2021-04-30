#pragma once
#include "UserRepository.h"
#include "LoginModel.h"

class LoginController : public UserRepository
{
public:
	LoginController();
	~LoginController();

	void SelectData() override;

	void setUserModel(LoginModel userModel);
	LoginModel getUserOutputModel();

private:

	LoginModel userInputModel;
	LoginModel userOutputModel;
};

