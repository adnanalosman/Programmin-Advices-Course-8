#include <iostream>
#include <string>
#include <limits>
#include <iomanip>


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

bool isLeapYear(short& Year) {
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
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
	if (Month < 1 || Month > 12)
		return 0;

	short DaysArr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// فبراير هو الوحيد اللي بيتغير حسب السنة الكبيسة
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : DaysArr[Month - 1];
}


short DayOrderOfWeek(short& Year, short& Month, short Day) {
	const short a = (14 - Month) / 12;
	const short y = Year - a;
	const short m = Month + 12 * a - 2;
	const short dx = Day + y + y / 4 - y / 100 + y / 400 + ((31 * m) / 12);
	return dx % 7;
}

string DayOfWeek(short& DayOrder) {
	if (DayOrder >= 0 && DayOrder < 7)
	{
		string Arr[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return Arr[DayOrder];
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

string MonthofYear(short& Month) {
	if (Month >= 0 && Month <= 12)
	{
		string Arr[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return Arr[Month - 1];
	}
	else return "N/A";
}

void PrintCalender() {
	short Year, Month, Day = 1;
	Year = ReadDayInput(Year, "Year: ");
	Month = ReadDayInput(Month, "Month: ");

	cout << "\n ــــــــــــــ " << MonthofYear(Month).c_str() << " ــــــــــــــ\n" << endl;
	cout << " Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl << endl << " ";
	for (short y = 0; y < 7; y++) {
		if (y >= DayOrderOfWeek(Year, Month, Day)) cout << y - DayOrderOfWeek(Year, Month, Day) + 1 << "    ";
		else cout << "     ";
	} cout << endl << endl;

	Day = 8 - DayOrderOfWeek(Year, Month, Day);

	for (int i = 1; i < 5; i++) {
		cout << " ";
		for (int j = 0; j < 7; j++) {
			cout << setw(5) << left << Day;
			Day++;
			if (Day > DaysInMonth(Month, Year)) return;
		}
		cout << endl << endl;
	}

}

void PrintYearCalender() {
	short Year = 0; Year = ReadDayInput(Year, "Year: ");
	for (short i = 1; i <= 12; i++) {
		short Month = i, Day = 1;
		cout << "\n ــــــــــــــ " << MonthofYear(Month).c_str() << " ــــــــــــــ\n" << endl;
		cout << " Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl << endl << " ";
		for (short y = 0; y < 7; y++) {
			if (y >= DayOrderOfWeek(Year, Month, 1)) cout << y - DayOrderOfWeek(Year, Month, 1) + 1 << "    ";
			else cout << "     ";
		} cout << endl << endl;

		Day = 8 - DayOrderOfWeek(Year, Month, 1);
		bool done = false;
		for (short i = 1; i <= 5 && !done; i++) {
			cout << " ";
			for (short j = 0; j < 7 && !done; j++) {
				cout << setw(5) << left << Day;
				Day++;
				if (Day > DaysInMonth(Month, Year)) done = true;
			}
			cout << endl << endl;
		}
		cout << "________________________________" << endl;
	}

}

int main() {

	//PrintCalender();
	PrintYearCalender();
	system("pause>0");
}