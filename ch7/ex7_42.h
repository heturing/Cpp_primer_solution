#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Date{
public:
	//Type alias.
	using date_type = unsigned;
   	//Constructors.	
	Date() = default;
	Date(date_type y, date_type m, date_type d) : _year(y), _month(m), _day(d) {if(!check_date(y,m,d)) reset();}
	Date(istream &);
	//Functions.
	Date &set(date_type y, date_type m, date_type d);
	Date &reset();
	void get() const;
private:
	date_type _year = 1970, _month = 1, _day = 1;
	bool check_date(date_type y, date_type m, date_type d){
		vector<int> v = {1,3,5,7,8,10,12};
		auto iter = find(v.begin(), v.end(), m);
	   	if(iter == v.end()){
			return check_big_month(d);
		}
		else if(m == 2){
			return check_minimal_month(y,d);
		}
		else{
			return check_small_month(d);
		}
	}
	
	bool check_big_month(date_type d){
		return d >= 1 && d <= 31;
	}
	bool check_small_month(date_type d){
		return d >= 1 && d <= 30;
	}
	bool check_minimal_month(date_type y, date_type d){
		if(isLeap(y)){
			return d >= 1 && d <= 29;
		}
		else{
			return d >= 1 && d <= 28;
		}
	}

	bool isLeap(date_type y){
		return y % 400 == 0;
	}
};

Date::Date(istream &is) : Date(){
	is >> _year >> _month >> _day;
   	if(!check_date(_year, _month, _day)){
		_year = 1970;
		_month = 1;
		_day = 1;
	}
}

Date &Date::set(date_type y, date_type m, date_type d){
	_year = y;
	_month = m;
	_day = d;
	return *this;
}

Date &Date::reset(){
	_year = 1970;
	_month = 1;
 	_day = 1;
	return *this;
}

void Date::get() const{
	cout << _year << " " << _month << " " << _day << endl;
}	
