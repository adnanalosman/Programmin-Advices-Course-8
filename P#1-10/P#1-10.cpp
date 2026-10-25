#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

// تم إزالة المراجع & من المتغيرات البسيطة لأنها لا توفر مساحة بل قد تعقد التمرير
short ReadInput(string Message) {
    short Input;
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

string SpellNumbers(long long Input) { // تم تغييرها لـ long long لدعم الأرقام الكبيرة
    if (Input == 0) return "";
    if (Input > 0 && Input < 20) {
        string Arr[] = { "", "One", "Two", "Three", "Four", "Five", "Sux", "Seven", "Eight", "Nine", "Ten",
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
    return ""; // حماية للدالة
}

bool isLeapYear(short Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short DaysinYear(short Year) {
    return (isLeapYear(Year)) ? 366 : 365;
}

// تعديل أنواع الإرجاع هنا إلى int و long لإنهاء مشكلة الـ Overflow
int HoursinYear(short Year) {
    return DaysinYear(Year) * 24;
}

int MinutesinYear(short Year) {
    return HoursinYear(Year) * 60;
}

long long SecondsinYear(short Year) {
    return (long long)MinutesinYear(Year) * 60;
}

void PartsOfYear(short Year) {
    cout << "Number of Days is    " << DaysinYear(Year) << endl;
    cout << "Number of Hours is   " << HoursinYear(Year) << endl;
    cout << "Number of Minutes is " << MinutesinYear(Year) << endl;
    cout << "Number of Seconds is " << SecondsinYear(Year) << endl;
}

short DaysInMonth(short Month, short Year) {
    if (Month < 1 || Month > 12) return 0;
    short DaysArr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : DaysArr[Month - 1];
}

short DayOrderOfWeek(short Year, short Month, short Day) {
    const short a = (14 - Month) / 12;
    const short y = Year - a;
    const short m = Month + 12 * a - 2;
    const short dx = Day + y + y / 4 - y / 100 + y / 400 + ((31 * m) / 12);
    return dx % 7;
}

string DayOfWeek(short DayOrder) {
    if (DayOrder >= 0 && DayOrder < 7) {
        string Arr[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
        return Arr[DayOrder];
    }
    return "N/A";
}

string MonthofYear(short Month) {
    if (Month >= 1 && Month <= 12) {
        string Arr[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        return Arr[Month - 1];
    }
    return "N/A";
}

void PrintCalender(short Year, short Month) {
    short Day = 1;
    cout << "\n ------------ " << MonthofYear(Month) << " ------------\n" << endl;
    cout << " Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl << endl << " ";

    short startDay = DayOrderOfWeek(Year, Month, Day);
    for (short y = 0; y < startDay; y++) {
        cout << "     ";
    }

    short totalDays = DaysInMonth(Month, Year);
    for (short d = 1; d <= totalDays; d++) {
        cout << setw(5) << left << d;
        if ((d + startDay) % 7 == 0) cout << "\n ";
    }
    cout << "\n\n";
}

void PrintYearCalender(short Year) {
    for (short i = 1; i <= 12; i++) {
        PrintCalender(Year, i);
        cout << endl;
    }
}

short GetDaysBeginningYear(short Day, short Month, short Year) {
    short TotalDays = 0;
    for (short i = 1; i < Month; i++) {
        TotalDays += DaysInMonth(i, Year);
    }
    return TotalDays + Day;
}

void GetCurrentDate(short TotalDays, short Year) {
    short Month = 1;
    cout << "Date for [" << TotalDays << "] is: ";
    for (short i = 1; i <= 12; i++) {
        if ((TotalDays - DaysInMonth(i, Year)) > 0) { TotalDays -= DaysInMonth(i, Year); Month++; }
    }
    cout << TotalDays << "/" << Month << "/" << Year << endl;
}

void DaysToMonths(short& DaysToAdd, short& Year, short& Month, short& Day) {
    while (DaysToAdd + Day >= DaysInMonth(Month, Year)) {
        DaysToAdd -= DaysInMonth(Month, Year);
        Month++;
        if (Month > 12)
        {
            Month = 1;
            Year++;
        }
    }
}

void GetDateAfterAdding(short& DaysToAdd, short& Day, short& Month, short& Year) {
    if (DaysToAdd <= 0) {
        cout << Day << "/" << Month << "/" << Year << endl;
    }
    else
    {
        DaysToMonths(DaysToAdd, Year, Month, Day);
        cout << Day + DaysToAdd << "/" << Month << "/" << Year << endl;
    }
}


short Days_Start_Year_Today(short& Year, short& Month, short& Day) {
    short Output = 0;
    for (short i = 1; i < Month; i++) {
        Output += DaysInMonth(i, Year);
    }
    Output += Day;
    return Output;
}

struct stDate
{
    short Year; short Month; short Day;
};

stDate Increse_Date(short& Year, short& Month, short& Day, short& AddingDays) {
    stDate Output;
    if (AddingDays == 0)
    {
        Output.Day = Day, Output.Month = Month, Output.Year = Year;
        return Output;
    }
    AddingDays += Days_Start_Year_Today(Year, Month, Day);
    Output.Year = Year;
    while (AddingDays > DaysinYear(Output.Year)) {
        Output.Year++;
        AddingDays -= DaysinYear(Output.Year);
    }
    for (short i = 1; AddingDays >= DaysInMonth(i, Output.Year); i++) {
        Output.Month = i + 1;
        AddingDays -= DaysInMonth(i, Output.Year);
    }
    Output.Day = AddingDays;
    return Output;
}

stDate ReadFullDate() {
    stDate Output;
    cout << "Day: ";
    cin >> Output.Day;
    cout << "Month: ";
    cin >> Output.Month;
    cout << "Year: ";
    cin >> Output.Year;
    return Output;
}

bool CompareDates(stDate& Date1, stDate& Date2) {
    return (Date1.Year > Date2.Year) ? true : (Date1.Year < Date2.Year) ? false : ((Date1.Month > Date2.Month) ? true : ((Date1.Month < Date2.Month) ? false : (Date1.Day > Date1.Day)));
}

bool isDatesEquals(stDate& Date1, stDate& Date2) {
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? Date1.Day == Date2.Day : false) : false;
}

bool isLastDayOfMonth(stDate& Date) {
    return Date.Day == DaysInMonth(Date.Month, Date.Month);
}

bool isLastMonthOfYear(stDate& Date) {
    return Date.Month == 12;
}

int main() {
    //short Year, Month, Day, TotalDays;
    //Year = ReadInput("Year : ");
    //Month = ReadInput("Month: ");
    //Day = ReadInput("Day  : ");
    //TotalDays = GetDaysBeginningYear(Day, Month, Year);

    //P#11
    //cout << "\nDays estimated from the 1st day of year is:" << endl << TotalDays << endl << SpellNumbers(TotalDays) << " Days." << endl;
    //GetCurrentDate(TotalDays, Year);

    //P#12
   /* short AddingDays;
    AddingDays = ReadInput("How many Days to add: ");

    GetDateAfterAdding(AddingDays, Day, Month, Year);*/

    /*stDate Date;
    Date.Year = ReadInput("Year: ");
    Date.Month = ReadInput("Month: ");
    Date.Day = ReadInput("Day: ");
    short DaysToAdd = ReadInput("Days to add: ");
    Date = Increse_Date(Date.Year, Date.Month, Date.Day, DaysToAdd);*/

    //cout << "New date after adding days is: " << Date.Year << "/" << Date.Month << "/" << Date.Day << endl;

    //stDate FirstDate = ReadFullDate();
    //stDate SecondDate = ReadFullDate();

    //(CompareDates(FirstDate, SecondDate)) ? printf("FirstDate is newer!") : printf("SecondDate  is newer!");

    //(isDatesEquals(FirstDate, SecondDate)) ? printf("Dates are equals!") : printf("Dates are not equals!");

    //P#15 is last day/month
    stDate Date = ReadFullDate();
    (isLastDayOfMonth(Date)) ? cout << "Yes this day " << Date.Day << " is the last of month" : cout << "No! this day " << Date.Day << " is not the last of month";
    (isLastMonthOfYear(Date)) ? cout << "\nYes month is the last of this year." : cout << "\nNo! this month is not the last of this year!";

    system("pause>0");
    return 0;
}
