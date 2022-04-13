#pragma once
#include "MyOs.h"
#include "MyIs.h"

namespace my {
	class string {
	private:
		char* str;

	public:
		string();

		string(const char* str);

		string(const string& ref);

		string& operator= (const char* str);

		string& operator= (string& ref);

		string operator+ (const string& ref);

		const string& operator+= (const string& ref);

		bool operator== (const string& ref);

		friend my::ostream& operator<<(my::ostream& os, const string& ref);

		friend my::istream& operator>>(my::istream& is, string& ref);


		~string();
	};
}