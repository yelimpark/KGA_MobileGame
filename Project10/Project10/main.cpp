#include <iostream>
#include "NameCard.h"
#include "Ring.h"
#include "Calculator.h"
#include "Printer.h"

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	FruitSeller(int price, int num, int money)
		: APPLE_PRICE(price), numOfApples(num), myMoney(money)
	{
		//empty
	}
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		
		if (numOfApples < num) return -1;
		if (money % APPLE_PRICE != 0) return -1;
		if (money <= 0) return -1;

		numOfApples -= num;
		myMoney += money;
		return num;
	}

	void ShowSalesResult()
	{
		std::cout << "���� ���: " << numOfApples << std::endl;
		std::cout << "�Ǹ� ����: " << myMoney << std::endl << std::endl;
	}
	~FruitSeller() {}
};

class FruitBuyer
{
	int myMoney;		// private:
	int numOfApples;	// private:

public:
	FruitBuyer(int money)
		: myMoney(money), numOfApples(0)
	{

	}

	void BuyApples(FruitSeller& seller, int money)
	{
		if (myMoney < money) {
			std::cout << "���� �����մϴ�." << std::endl << std::endl;
			return;
		}

		int applePlus = seller.SaleApples(money);

		if (applePlus < 0) {
			std::cout << "���� ���ǿ� ���� �ʽ��ϴ�." << std::endl << std::endl;
			return;
		}

		numOfApples += applePlus;
		myMoney -= money;
	}

	void ShowBuyResult()
	{
		std::cout << "���� �ܾ�: " << myMoney << std::endl;
		std::cout << "��� ����: " << numOfApples << std::endl << std::endl;
	}
	~FruitBuyer() {}
};

int main(void)
{
	Point pos1 = { 12, 4 };
	Point pos2 = { 20, 30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition(); // [5, 14]

	pos1.AddPoint(pos2);
	pos1.ShowPosition(); // [25, 44]

	Calculator cal;
	cal.Init();
	std::cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << std::endl;
	std::cout << "3.5 * 1.7 = " << cal.Mul(3.5, 1.7) << std::endl;
	std::cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << std::endl;
	std::cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << std::endl;

	cal.ShowOpCount(); // 4

	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();

	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	std::cout << "���� �Ǹ����� ��Ȳ" << std::endl;
	seller.ShowSalesResult();
	std::cout << "���� �������� ��Ȳ" << std::endl;
	buyer.ShowBuyResult();

	// ���� ����
	buyer.BuyApples(seller, 10000);
	// �Ž�����
	buyer.BuyApples(seller, 1500);

	std::cout << "���� �Ǹ����� ��Ȳ" << std::endl;
	seller.ShowSalesResult();
	std::cout << "���� �������� ��Ȳ" << std::endl;
	buyer.ShowBuyResult();

	Ring ring1(0, 0, 5, 5, 5, 3);
	ring1.ShowRing();

	Ring ring2(1, 1, 5, 1, 1, 3);
	ring2.ShowRing();

	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	manClerk.ShowNameCardInfo();

	return 0;
}