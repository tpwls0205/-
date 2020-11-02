#define _CRT_SECURE_NO_WARNINGS

#include "TelInfo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* Person::getName() {
	return name;
}
void Person::setName(char* _name)
{
	strncpy(name, _name, strlen(_name));
	name[strlen(_name)] = '\0';
}
char* Person::getPhone()
{
	return phone;
}
void Person::setPhone(char* _phone)
{
	strncpy(phone, _phone, strlen(_phone));
	phone[strlen(_phone)] = '\0';
}
void Person::showPerson()
{
	printf("name: %s\n", name);
	printf("phone: %s\n", phone);
}