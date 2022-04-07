#include <iostream>
#include "EmployeeHandler.h"


int main(void)
{
	// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
	EmployeeHandler handler;

	//// 정규직 등록
	//handler.AddEmployee(new PermanentWorker("KIM", 1000));
	//handler.AddEmployee(new PermanentWorker("LEE", 1500));

	//// 임시직 등록
	//TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	//alba->AddWorkTime(5);	// 5시간 일한결과 등록
	//handler.AddEmployee(alba);

	//// 영업직 등록
	//SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	//seller->AddSalesResult(7000);	// 영업실적 7000
	//handler.AddEmployee(seller);

	// 해외 영업직 등록
	SalesWorker* fesller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fesller1->AddSalesResult(7000);
	handler.AddEmployee(fesller1);

	ForeignSalesWorker* fesller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fesller2->AddSalesResult(7000);
	handler.AddEmployee(fesller2);

	ForeignSalesWorker* fesller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fesller3->AddSalesResult(7000);
	handler.AddEmployee(fesller3);

	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	// 이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	return 0;
}