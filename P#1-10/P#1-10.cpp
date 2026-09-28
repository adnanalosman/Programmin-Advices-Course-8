#include <iostream>
#include <string>
#include <limits>

using namespace std;


short ReadInput(short& Input) {
	cout << "Enter Number? ";
	cin >> Input;
	while (cin.fail()) {
		cin.clear();
		cin >> Input;
	}
	return Input;
}

string SpellNumbers(short Input) {
	if (Input == 0) return "";
	if (Input > 0 && Input < 20) {
		string Arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
			"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
		return Arr[Input];
	}
	if (Input >= 20 && Input < 100) {
		string Arr[] = { "", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
		return Arr[Input / 10] + " " + SpellNumbers(Input % 10);
	}
	if (Input >= 100 && Input < 200) return SpellNumbers(Input / 100) + " Hundred " + SpellNumbers(Input % 100);
	if (Input >= 200 && Input < 1000)  return SpellNumbers(Input / 100) + " Hundreds " + SpellNumbers(Input % 100);
	if (Input >= 1000 && Input < 1000000) return SpellNumbers(Input / 1000) + " Thousand " + SpellNumbers(Input % 1000);
	if (Input >= 1000000 && Input < 1000000000) return SpellNumbers(Input / 1000000) + " Million " + SpellNumbers(Input % 1000000);
	if (Input >= 1000000000) return SpellNumbers(Input / 1000000000) + " Billion " + SpellNumbers(Input % 1000000000);
	}

bool LeapYear(short& Year) {
	if (Year % 100 == 0 && Year % 400 == 0)
		{
		return true;
		}
	else if (Year % 4 == 0) return true;
	else return false;
	}

bool isLeapYear(short& Year) {
	return ((Year % 100 == 0 && Year % 400 == 0) || Year % 4 == 0);
	}

short DaysinYear(short& Year) {
	return (isLeapYear(Year)) ? 366 : 365;
	}

short HoursinYear(short& Year) {
	return DaysinYear(Year) * 24;
	}

short MinutesinYear(short& Year) {
	return HoursinYear(Year) * 60;
}

short SecondsinYear(short& Year) {
	return MinutesinYear(Year) * 60;
	}
}


short DaysInMonth(short& Month, short& Year) {
	return (isLeapYear(Year)) ? ((Month % 2 != 0) ? 31 : (Month == 2) ? 29 : 30) : ((Month % 2 != 0) ? 31 : (Month == 2) ? 28 : 30);
}



}