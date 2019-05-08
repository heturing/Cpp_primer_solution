#include <iostream>
#include <string>

using namespace std;

class my_date{
public:
	using date_type = unsigned;
	my_date() = default;
	my_date(string s);
	void print(){ cout << year << " " << month << " " << day << endl;}
private:
	int translate_month(string);
	date_type year;
	date_type month;
	date_type day;
};

my_date::my_date(string s){
	string numbers = "0123456789";
	if(s.find_first_of(numbers) == 0){
		month = stoi(s.substr(0,s.find_first_of("/")));
		day = stoi(s.substr(s.find_first_of("/")+1, s.find_last_of("/")));
		year = stoi(s.substr(s.find_last_of("/")+1));
	}
	else{
		month = translate_month(s.substr(0,s.find_first_of(" ")));
		day = stoi(s.substr(s.find_first_of(" ")+1, s.find_first_of(",")));
		year = stoi(s.substr(s.find_first_of(",")+1));
	}
}
inline int my_date::translate_month(string m){
		if(m == "January"|| m == "Jan")
			return 1;
		if(m == "Feburary" || m == "Feb")
			return 2;
		if(m ==  "March" || m == "Mar")
			return 3;
		if(m == "April" || m == "Apr")
			return 4;
		return -1;
}

int main(){
	my_date md1("January 1, 1900");
	my_date md2("1/1/1900");
	my_date md3("Jan 1, 1900");
	md1.print();
	md2.print();
	md3.print();
	return 0;
}
