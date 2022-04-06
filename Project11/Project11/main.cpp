#include <iostream>
#include <cstring>
#include "NameCard.h"

class Car //�⺻ ���� �ڵ���
{
private:
    int gasolineGauge;

public:
    Car(int gasolineGauge) 
        :gasolineGauge(gasolineGauge)
    {

    }

    int GetGasGauge()
    {
        return gasolineGauge;
    }
};


class HybridCar :public Car //���̺긮�� �ڵ���
{
private:
    int electricGauge;
public:
    HybridCar(int gasolineGauge, int electricGauge)
        : Car(gasolineGauge), electricGauge(electricGauge)
    {

    }

    int GetElecGauge()
    {
        return electricGauge;
    }
};


class HybridWaterCar :public HybridCar //���̺긮�� ����ī
{
private:
    int waterGauge;
public:
    HybridWaterCar(int gasolineGauge, int electricGauge, int waterGauge)
        : HybridCar(gasolineGauge, electricGauge), waterGauge(waterGauge)
    {

    }

    void ShowCurrentGauge()
    {

        std::cout << "�ܿ� ���ָ�: " << GetGasGauge() << std::endl;
        std::cout << "�ܿ� ���ⷮ: " << GetElecGauge() << std::endl;
        std::cout << "�ܿ� ���ͷ�: " << waterGauge << std::endl;

    }

};

class MyFriendInfo
{
private:
    char* name;
    int age;
public:
    MyFriendInfo(const char* name, int age) 
        :age(age)
    {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
    }
    void ShowMyFriendInfo()
    {
        std::cout << "�̸�: " << name << std::endl;
        std::cout << "����: " << age << std::endl;
    }
    ~MyFriendInfo() {
        delete []name;
    }
};

class MyFriendDetailInfo :public MyFriendInfo
{
private:
    char* addr;
    char* phone;
public:
    MyFriendDetailInfo(const char* name, int age, const  char* addr, const  char* phone)
        :MyFriendInfo(name, age)
    {
        this->addr = new char[strlen(addr) + 1];
        strcpy_s(this->addr, strlen(addr) + 1, addr);

        this->phone = new char[strlen(phone) + 1];
        strcpy_s(this->phone, strlen(phone) + 1, phone);
    }

    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        std::cout << "�ּ�: " << addr << std::endl;
        std::cout << "��ȭ: " << phone << std::endl << std::endl;
    }

    ~MyFriendDetailInfo() {
        delete []addr;
        delete []phone;
    }
};

int main() {
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSENIOR;
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();

    std::cout << std::endl;

    HybridWaterCar hwc(10, 20, 30);
    hwc.ShowCurrentGauge();

    MyFriendDetailInfo mfdi("kim", 24, "seoul", "010-0000-0000");
    mfdi.ShowMyFriendDetailInfo();

    return 0;
}