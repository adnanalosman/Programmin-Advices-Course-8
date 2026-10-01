#include <iostream>
#include <string>
#include <limits>


using namespace std;


short ReadInput(short& Input) {
	cout << "Enter Number? ";
	cin >> Input;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "Wrong Input! Please try again: ";
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

void PartsOfYear(short& Year) {
	cout << "Number of Days is    " << DaysinYear(Year) << endl;
	cout << "Number of Hours is   " << HoursinYear(Year) << endl;
	cout << "Number of Minutes is " << MinutesinYear(Year) << endl;
	cout << "Number of Seconds is " << SecondsinYear(Year) << endl;
}


short DaysInMonth(short& Month, short& Year) {
	return (isLeapYear(Year)) ? ((Month % 2 != 0) ? 31 : (Month == 2) ? 29 : 30) : ((Month % 2 != 0) ? 31 : (Month == 2) ? 28 : 30);
}

enum enDaysName { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

short DayOrderOfWeek(short& Year, short& Month, short& Day) {
	const short a = (14 - Month) / 12;
	const short y = Year - a;
	const short m = Month + 12 * a - 2;
	const short dx = Day + y + y / 4 - y / 100 + y / 400 + ((31 * m) / 12);
	return dx % 7;
}

string DayOfWeek(short& DayOrder) {
	if (DayOrder >= 0 && DayOrder < 7)
	{
		switch (DayOrder) {
		case enDaysName::Sunday:
			return "Sun";
			break;
		case enDaysName::Monday:
			return "Mon";
			break;
		case enDaysName::Tuesday:
			return "Tue";
			break;
		case enDaysName::Wednesday:
			return "Wed";
			break;
		case enDaysName::Thursday:
			return "Thu";
			break;
		case enDaysName::Friday:
			return "Fri";
			break;
		case enDaysName::Saturday:
			return "Sat";
		}
	}
	else return "N/A";
}
short ReadDayInput(short& Input, string Message) {
	cout << Message;
	cin >> Input;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "Wrong Input! Please try again: ";
		cin >> Input;
	}
	return Input;
}
void GetDateDetails() {
	short Year, Month, Day, WeekDay;
	Year = ReadDayInput(Year, "Year: ");
	Month = ReadDayInput(Month, "Month: ");
	Day = ReadDayInput(Day, "Day: ");
	WeekDay = DayOrderOfWeek(Year, Month, Day);
	cout << "Date is: " << Day << "/" << Month << "/" << Year << endl;
	cout << "WeekDay: " << WeekDay << endl;
	cout << "DayName: " << DayOfWeek(WeekDay) << endl;
}

int main() {

	GetDateDetails();

}
