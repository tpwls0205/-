#pragma once
#define NAME_LEN		20
#define TEL_LEN			20

class Person
{
private:
	char* name;
	char* phone;

public:
	Person() {
		name = new char[NAME_LEN];
		phone = new char[TEL_LEN];
	}
	~Person() {
		delete[] name;
		delete[] phone;
	}

public:

	char* getName();

	void setName(char* _name);

	char* getPhone();

	void setPhone(char* _phone);

	void showPerson();
};
