#include <iostream>

using namespace std;

struct stDate {
    short Day;
    short Month;
    short Year;
};

stDate ReadFullDate(){
    stDate Output;
    cout << "Please Enter Date Details:" << endl << "Day: ";
    cin >> Output.Day;
    cout << "Month: ";
    cin >> Output.Month;
    cout << "Year: ";
    cin >> Output.Year;
    return Output;
}

bool isLeapYear(short Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short DaysinYear(short Year) {
    return (isLeapYear(Year)) ? 366 : 365;
}

short DaysInMonth(short Month, short Year) {
    if (Month < 1 || Month > 12) return 0;
    short DaysArr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : DaysArr[Month - 1];
}

bool isDateNewer(stDate New, stDate Old) {
    return (New.Year > Old.Year) ? true : (Old.Year > New.Year) ? false : (New.Month > Old.Month) ? true : (Old.Month > New.Month) ? false : (New.Day > Old.Day);
}

short DaysFromStartYear(stDate Date) {
    short Days = Date.Day;
    for (short i = 1; i < Date.Month; i++) {
        Days += DaysInMonth(i, Date.Year);
    }
     return Days;
}

int DateDifDays(stDate Date1, stDate Date2) {
    int DifDays = DaysFromStartYear(Date1) - DaysFromStartYear(Date2);
    for (short i = Date2.Year + 1; i < Date1.Year; i++) {
        DifDays += DaysinYear(i);
    }
    return DifDays;
}

int DateDifDays_Generic(stDate Date1, stDate Date2) {
    return (isDateNewer(Date1, Date2)) ? DateDifDays(Date1, Date2) : DateDifDays(Date2, Date1);
}

stDate IncreaseDateByXDays(stDate Date, short AddingDays) {
    if (AddingDays <= 0) return Date;
    AddingDays += Date.Day;
    while (AddingDays > DaysInMonth(Date.Month, Date.Year)) {
        if (Date.Month == 12) {
            AddingDays -= DaysInMonth(Date.Month, Date.Year);
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            AddingDays -= DaysInMonth(Date.Month, Date.Year);
            Date.Month++;
        }
    }
    Date.Day = AddingDays;
    return Date;
}

stDate IncreaseDateByXWeeks(stDate Date, short Weeks) {
    return IncreaseDateByXDays(Date, 7 * Weeks);
}

stDate IncreaseDateByXMonths(stDate Date, short Months) {
    while (Months > 0) {
        if (Date.Month == 12)
        {
            Date.Month = 1;
            Date.Year++;
            Months--;
        }
        else
        {
            Date.Month++;
            Months--;
        }
    }
    if (Date.Day > DaysInMonth(Date.Month, Date.Year)) Date.Day = DaysInMonth(Date.Month, Date.Year);
    return Date;
}

stDate IncreaseDateByXYears(stDate Date, short Years) {
    Date.Year += Years;
   if (Date.Day > DaysInMonth(Date.Month, Date.Year)) Date.Day = DaysInMonth(Date.Month, Date.Year);
    return Date;
}

stDate IncreaseDateByXYearsFaster(stDate Date, short Years) {
    Date.Year += Years;
    if (Date.Day > DaysInMonth(Date.Month, Date.Year)) Date.Day = DaysInMonth(Date.Month, Date.Year);
    return Date;
}

stDate IncreaseDateByXDecades(stDate Date, short Decades) {
    return IncreaseDateByXYears(Date, Decades * 10);
}

stDate IncreaseDateByXCentury(stDate Date, short Centuries) {
    return IncreaseDateByXYears(Date, Centuries * 100);
}

stDate IncreaseDateByOneMillennium(stDate Date) {
    return IncreaseDateByXYears(Date, 1000);
}

int main()
{
    stDate Date = ReadFullDate();
    cout << "\n\nDate After:\n" << endl;
    
    Date = IncreaseDateByXDays(Date, 1);
    cout << "01-Adding one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDays(Date, 10);
    cout << "02-Adding 10 days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXWeeks(Date, 1);
    cout << "03-Adding one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXWeeks(Date, 10);
    cout << "04-Adding 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    Date = IncreaseDateByXMonths(Date, 1);
    cout << "05-Adding one month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXMonths(Date, 5);
    cout << "06-Adding 5 months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXYears(Date, 1);
    cout << "07-Adding one year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXYears(Date, 10);
    cout << "08-Adding 10 years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXYearsFaster(Date, 10);
    cout << "09-Adding 10 years (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDecades(Date, 1);
    cout << "10-Adding one decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDecades(Date, 10);
    cout << "11-Adding 10 decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDecades(Date, 10);
    cout << "12-Adding 10 decades (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXCentury(Date, 1);
    cout << "13-Adding one century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneMillennium(Date);
    cout << "14-Adding one millennium is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

}