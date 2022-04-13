#include "MyString.h"
#include <cstring>
#include <cstdio>

using namespace my;

my::string::string()
	:str(nullptr)
{
	
}

my::string::string(const char* str)
{
	this->str = new char[strlen(str) + 1];
	strcpy_s(this->str, strlen(str) + 1, str);
}

my::string::string(const string& ref)
{
	str = new char[strlen(ref.str) + 1];
	strcpy_s(str, strlen(ref.str) + 1, ref.str);
}

string& my::string::operator=(const char* str)
{
	if (this->str != nullptr) {
		delete[]this->str;
		this->str = nullptr;
	}

	this->str = new char[strlen(str) + 1];
	strcpy_s(this->str, strlen(str) + 1, str);
	return *this;
}

string& my::string::operator=(const string& ref)
{
	if (str != nullptr) {
		delete[]str;
		str = nullptr;
	}

	str = new char[strlen(ref.str) + 1];
	strcpy_s(str, strlen(ref.str) + 1, ref.str);
	return *this;
}

string my::string::operator+(const string& ref)
{
	int len = strlen(str) + strlen(ref.str) + 1;
	string tmp;
	tmp.str = new char[len];
	strcpy_s(tmp.str, len, str);
	strcat_s(tmp.str, len, ref.str);

	return tmp;
}

const string& my::string::operator+=(const string& ref)
{
	string tmp(*this + ref);
	*this = tmp;
	return *this;
}

bool my::string::operator==(const string& ref)
{
	if (strcmp(this->str, ref.str) == 0) return true;
	return false;
}

my::string::~string()
{
	delete[]str;
}

my::ostream& my::operator<<(my::ostream& os, const string& ref)
{
	printf("%s", ref.str);
	return os;
}

my::istream& my::operator>>(my::istream& is, string& ref)
{
	char tmp[500] = "";
	scanf_s("%s", tmp, (int)sizeof(tmp));
	ref = tmp;
	return is;
}
