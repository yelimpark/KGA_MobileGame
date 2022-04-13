#include "MyString.h"

my::string::string()
	:str(nullptr), len(0)
{

}

my::string::string(const char* ms)
	: str(nullptr), len(strlen(ms)) 
{
	str = new char[len+1];
	strcpy_s(str, len + 1, ms);
}

my::string::string(const string& ref)
	:len(ref.len)
{
	str = new char[len + 1];
	strcpy_s(str, len + 1, ref.str);
}

my::string::~string()
{
	if (str != nullptr)
		delete[] str;
}

my::string& ::my::string::operator+(const string& ms)
{
	string temp;
	temp.len = len + ms.len;
	temp.str = new char[len + ms.len + 1];
	strcpy_s(temp.str, len + ms.len + 1, str);
	strcat_s(temp.str, len + ms.len + 1, ms.str);

	return temp;
}

my::string& my::string::operator=(const char* ms)
{
	if (str != nullptr) {
		delete[]str;
		str = nullptr;
	}

	len = strlen(ms);
	str = new char[len + 1];
	strcpy_s(str, len + 1, ms);

	return *this;

}

my::string& my::string::operator=(const string& ref)
{
	if (str != nullptr) {
		delete[]str;
		str = nullptr;
	}

	len = ref.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, ref.str);
	
	return *this;
}


std::ostream& my::operator<<(std::ostream& os, const string& ms)
{
	os << ms.str;

	return os;
}

//string& operator += (const string& ref)
////1. + strcat
////2. = strcpy
//{
//	strcat_s(str, strlen(str), ref.str);
//
//}
//
//my::string::bool operator== (const string& ref)
//{
//	strcmp(str, ref.str); //0,1,-1를 반환한다.
//	return true;
//}
