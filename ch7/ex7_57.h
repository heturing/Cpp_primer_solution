#include <iostream>

using namespace std;

class Account{
public:
	void calculate() {amount += amount * interestRate;}
	static double rate() {return interestRate;}
private:
	string owner;
	double amount;
	static double interestRate;
	static double initRate() {return todayRate;}
	static constexpr double todayRate = 0.007;
};

double Account::interestRate = initRate();



