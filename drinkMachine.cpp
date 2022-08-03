#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <cstdlib>

using namespace std;

class Machine
{
private:
    string drinkName;
    int price;
    int price_sum;
    int input_num;
    int user_money;
    int user_money_sum;
    int pay;
    int pay_change;

public:
    Machine() : user_money(0), user_money_sum(0), price_sum(0), pay_change(0), pay(0) {} //초기화
    void MenuInit(string _drinkName, int _price)                                         //초기화
    {
        drinkName = _drinkName;
        price = _price;
    }

    void MenuList(Machine* drink) //출력
    {
        drink[0].MenuInit("1) 콜라 ", 1200);
        drink[1].MenuInit("2) 우주맛 콜라 ", 1900);
        drink[2].MenuInit("3) 제로 콜라 ", 1200);
        drink[3].MenuInit("4) 스프라이트 ", 1100);
        drink[4].MenuInit("5) 환타 ", 900);
        drink[5].MenuInit("6) 닥터페퍼 ", 1100);
        drink[6].MenuInit("7) 몬스터 ", 1800);
        drink[7].MenuInit("8) 파워에이드 ", 1900);
        drink[8].MenuInit("9) 네스티 ", 1600);
        drink[9].MenuInit("10) 글라소 비타민 워터 ", 2100);
        drink[10].MenuInit("11) 미닛메이드 ", 1700);
        drink[11].MenuInit("12) 조지아 커피 ", 900);
        drink[12].MenuInit("13) 암바사 ", 900);
        drink[13].MenuInit("14) 마테차 ", 1700);

        cout << "=== Drink Machine ===" << endl;

        for (int i = 0; i < 14; i++)
            drink[i].MenuPrint();
    }

    void MenuPrint() //출력
    {
        cout << drinkName << price << endl;
    }

    void ComeIn() //첫 화면
    {
        cout << '\n';
        cout << "=== Enter a number ===" << endl;
        cout << "1. 현금 투입 " << endl;
        cout << "2. 음료 선택" << endl;
        cout << "3. 계산 " << endl;
        cout << "4. 종료" << endl;
        cout << "입력 : ";
    }

    int Choice(Machine* drink) // 선택 메인
    {
        cin >> input_num;
        cin.ignore();

        switch (input_num)
        {
        case 1:
            cout << "현금 투입: ";
            user_money_sum += ReadyMoney(); //투입
            cout << "투입금 합계: " << user_money_sum << "원" << endl;
            sleep(2);
            system("clear");

            break;

        case 2:
            cout << "(뒤로:0)음료 선택 : ";
            price_sum = DrinkChoice(drink); //메뉴선택
            sleep(2);
            system("clear");

            break;
        case 3:
            cout << "결제를 진행합니다 " << endl;
            pay_change = UserPay(user_money, price_sum); //결제
            sleep(2);
            system("clear");

            break;
        case 4:
            cout << "종료합니다" << endl;
            sleep(2);
            system("clear");

            return 1;

        default:
            cout << "재 입력 요망" << endl;
            break;
        }
    }

    int ReadyMoney() // 1 현금
    {
        cin >> user_money;
        cout << user_money << "원 투입됬습니다" << endl;

        return user_money;
    }

    int DrinkChoice(Machine* drink) // 2 선택
    {
        while (1)
        {
            cin >> input_num;
            cin.ignore();

            if (input_num == 0)
            {
                cout << "메뉴로 이동합니다" << endl;
                return price_sum;
            }
            else if (input_num > 15)
            {
                cout << "재 입력 요망" << endl;
                continue;
            }
            cout << drink[input_num - 1].drinkName << drink[input_num - 1].price << endl;
            price_sum += drink[input_num - 1].price;
            cout << "총 금액: " << price_sum << "원" << endl;
        }
    }
    int UserPay(int _user_money, int _price_sum) // 3 계산
    {
        if (_user_money < _price_sum)
        {
            cout << _price_sum - _user_money << "원 부족합니다" << endl;
            return _price_sum - _user_money;
        }
        else
        {
            cout << "거스름돈 : " << _user_money - _price_sum << "원" << endl;
            return _user_money - _price_sum;
        }
    }
};

// int Machine::user_money = 0;

int main()
{
    int exitMain;
    Machine drink[14], machine; //객체

    machine.MenuList(drink); //음료 리스트
    while (1)
    {
        machine.ComeIn();                 //메뉴
        exitMain = machine.Choice(drink); //선택

        if (exitMain == 1) //종료
            break;
    }
    return 0;
}
