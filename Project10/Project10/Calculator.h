class Calculator {
private:
	int addCouter;
	int mulCounter;
	int minCounter;
	int divCounter;

public:
	void Init();
	float Add(float num1, float num2);
	float Mul(float num1, float num2);
	float Min(float num1, float num2);
	float Div(float num1, float num2);
	void ShowOpCount();
};