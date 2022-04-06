#include <iostream>
#include <cstring>
#include "NameCard.h"

NameCard::NameCard(const char* name, const char* componyName, const char* phoneNumber, int jobGrade)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) +1, name);

	this->componyName = new char[strlen(componyName) + 1];
	strcpy_s(this->componyName, strlen(componyName) + 1, componyName);

	this->phoneNumber = new char[strlen(phoneNumber) + 1];
	strcpy_s(this->phoneNumber, strlen(phoneNumber) + 1, phoneNumber);

	this->jobGrade = 0;
}

void NameCard::ShowNameCardInfo() const
{
	std::cout << "�̸�: " << name << std::endl;
	std::cout << "ȸ��: " << componyName << std::endl;
	std::cout << "��ȭ��ȣ: " << phoneNumber << std::endl;
	switch (jobGrade) {
	case COMP_POS::CLERK :
		std::cout << "����: ���" << std::endl;
		break;

	case COMP_POS::SENIOR:
		std::cout << "����: ����" << std::endl;
		break;

	case COMP_POS::ASSIST:
		std::cout << "����: �븮" << std::endl;
		break;

	default:
		std::cout << "����: ����" << std::endl;
		break;
	}
}

NameCard::~NameCard()
{
	delete[] name;
	delete[] componyName;
	delete[] phoneNumber;
}
