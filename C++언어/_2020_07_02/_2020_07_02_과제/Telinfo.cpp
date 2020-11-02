#include "Telinfo.h"
#include <iostream>

using namespace std;

Person::Person()
{
	name = new char[NAME_LEN];
	phone = new char[TEL_LEN];
}
Person::~Person()
{
	delete[] name;
	delete[] phone;
}

char* Person::getName() {
	return name;
}
// setter
void Person::setName(char* _name)
{
	strncpy(name, _name, strlen(_name));
	name[strlen(_name)] = '\0';// 0, NULL
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

void PersonManager::ShowMenu()
{
	ClearScreen();

	printf("\n------------- Menu -------------\n");
	printf("	1. Insert \n");
	printf("	2. Delete \n");
	printf("	3. Search \n");
	printf("	4. Print All \n");
	printf("	5. Exit \n");
}

void PersonManager::InsertTelInfo(Person* par, int* pnum)
{
	char name[NAME_LEN];
	char phone[TEL_LEN];
	printf("[ INSERT ] \n");
	printf("Input Name : ");
	scanf("%s", name);
	printf("Input Tel Number : ");
	scanf("%s", phone);

	par[*pnum].setName(name);
	par[*pnum].setPhone(phone);
	//strcpy(par[*pnum].name, name);
	//strcpy(par[*pnum].phone, phone);
	(*pnum)++;

	printf("-----------> Data Inserted......\n");
}

void PersonManager::DeleteTelInfo(Person* par, int* pnum)
{
	int i = 0, j = 0;
	char name[NAME_LEN];

	printf("[ Delete ] \n");
	printf("Input Name for Removing : ");
	scanf("%s", name);

	for (i = 0; i < *pnum; i++)
	{
		if (strcmp(par[i].getName(), name) == 0)
		{
			for (j = i + 1; j < *pnum; j++)
			{
				strcpy(par[j - 1].getName(), par[j].getName());
				strcpy(par[j - 1].getPhone(), par[j].getPhone());
			}
			(*pnum)--;
			return;
		}
	}

	printf("-------------> Data Not Found..........\n");
}

void PersonManager::SearchTelInfo(Person* par, int num)
{
	int i = 0;
	char name[NAME_LEN];

	printf("[ Search ] \n");
	printf("Input Name for Searching : ");
	scanf("%s", name);

	for (i = 0; i < num; i++)
	{
		if (strcmp(par[i].getName(), name) == 0)
		{
			par[i].showPerson();
			return;
		}
	}

	printf("-------------> Data Not Found..........\n");
}

void PersonManager::PrintAll(Person* par, int num)
{
	int i = 0;

	printf("[ Print All Data ] \n");

	for (i = 0; i < num; i++)
		par[i].showPerson();

	getchar();
	getchar();
}

void PersonManager:: ClearScreen()
{
	system("cls");
}

PersonManager::PersonManager(Person* par)
{
	per = par;
}

void main()
{
	int choice = 0;						// 메뉴선택
	int nPersonNum = 0;
	//Person* perArr = NULL;
	int perNum = 0;						// 저장된 인원수

	printf("저장할 인원수는 몇명입니까? : ");
	scanf("%d", &nPersonNum);
	//perArr = new Person[nPersonNum];
	PersonManager pm(new Person[nPersonNum]);

	while (1)
	{
		pm.ShowMenu();
		printf("Choose the item : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			pm.InsertTelInfo(&pm, &perNum);
			break;
		case 2:
			pm.DeleteTelInfo(&pm, &perNum);
			break;
		case 3:
			pm.SearchTelInfo(&pm, perNum);
			break;
		case 4:
			pm.PrintAll(&pm, perNum);
			break;
		case 5:
			//delete[] perarr;
			return;
			break;
		default:
			printf("illegal selection.. \n");
			break;
		}
	}
}