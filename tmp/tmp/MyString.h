#pragma once
#include <iostream>
#include <cstring>

namespace my 
{
	class string
	{

	private:
		char* str;
		int len;

	public:
		string();

		string(const char* ms);

		string(const string& ref);

		~string();

		string& operator+ (const string& ms);

		string& operator=(const char* ms);

		string& operator=(const string& ref);
			
		friend std::ostream& operator<< (std::ostream& os, const string& ms);
		
	};
}
