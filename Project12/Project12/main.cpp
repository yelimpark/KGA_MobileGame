#include <iostream>
#include "EmployeeHandler.h"


int main(void)
{
	// ���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����
	EmployeeHandler handler;

	//// ������ ���
	//handler.AddEmployee(new PermanentWorker("KIM", 1000));
	//handler.AddEmployee(new PermanentWorker("LEE", 1500));

	//// �ӽ��� ���
	//TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	//alba->AddWorkTime(5);	// 5�ð� ���Ѱ�� ���
	//handler.AddEmployee(alba);

	//// ������ ���
	//SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	//seller->AddSalesResult(7000);	// �������� 7000
	//handler.AddEmployee(seller);

	// �ؿ� ������ ���
	SalesWorker* fesller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fesller1->AddSalesResult(7000);
	handler.AddEmployee(fesller1);

	ForeignSalesWorker* fesller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fesller2->AddSalesResult(7000);
	handler.AddEmployee(fesller2);

	ForeignSalesWorker* fesller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fesller3->AddSalesResult(7000);
	handler.AddEmployee(fesller3);

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();
	return 0;
}