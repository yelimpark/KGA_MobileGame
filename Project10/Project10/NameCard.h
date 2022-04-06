enum COMP_POS { CLERK, SENIOR, ASSIST, MANAGER };

class NameCard {
private:
	char* name;
	char* componyName;
	char* phoneNumber;
	int jobGrade;

public:
	
	NameCard(const char* name, const char componyName[], const char* phoneNumber, int jobGrade);

	void ShowNameCardInfo() const;

	~NameCard();
};