#pragma once

namespace my {
	class istream {
	public :
		istream& operator>> (const char* str);

		istream& operator>> (int& n);
	};

	static istream cin;
}