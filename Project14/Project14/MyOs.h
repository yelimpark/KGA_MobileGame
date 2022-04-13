#pragma once

namespace my {
	class ostream {
	private :

	public :
		ostream& operator<< (char* str);

		ostream& operator<< (const char* str);

		ostream& operator<< (char str);

		ostream& operator<< (int num);

		ostream& operator<< (double e);

		ostream& operator<< (ostream& (*fp)(ostream &ostm));
	};

	ostream& endl(my::ostream& ostm);
}