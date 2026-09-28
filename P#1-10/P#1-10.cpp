#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Problem 1 Number to text (Spelling Number)
int ReadInput_int(int&Input) {
	cout << "Please enter number to spell: ";
	cin >> Input;
	while (Input >= std::numeric_limits<int>::max())
	{
		cout << "Out of bound.." << "\nPlease try again: ";
		cin.clear();
		cin >> Input;
	}
	return Input;
}

string SpellNumber(int Input) {
	
	if (Input == 0) return "";

	if (Input > 0 && Input <= 19) {
		string Arr[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
						"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
		return Arr[Input];
	}

	if (Input > 19 && Input <= 99) {
		string Arr[] = { "", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
		return Arr[Input / 10] + " " + SpellNumber(Input % 10);
	}

	if (Input >= 100 && Input < 200) {
		if (SpellNumber(Input % 100) != "")
		{
			return SpellNumber(Input / 100) + " hundred and " + SpellNumber(Input % 100);
		}
		else return SpellNumber(Input / 100) + " hundred" + SpellNumber(Input % 100);
	}

	if (Input >= 200 && Input < 1000) {
		if (SpellNumber(Input % 100) != "")
		{
			return SpellNumber(Input / 100) + " hundreds and " + SpellNumber(Input % 100);
		}
		else return SpellNumber(Input / 100) + " hundreds" + SpellNumber(Input % 100);
	}

	if (Input >= 1000 && Input < 1000000) {
		if (SpellNumber(Input % 1000) != "")
		{
			return SpellNumber(Input / 1000) + " thousand and " + SpellNumber(Input % 1000);
		}
		else return SpellNumber(Input / 1000) + " thousand" + SpellNumber(Input % 1000);
	}

	if (Input >= 1000000 && Input < 1000000000) {
		if (SpellNumber(Input % 1000000) != "")
		{
			return SpellNumber(Input / 1000000) + " million and " + SpellNumber(Input % 1000000);
		}
		else return SpellNumber(Input / 1000000) + " million" + SpellNumber(Input % 1000000);
	}

	if (Input >= 1000000000) {
		if (SpellNumber(Input % 1000000000) != "")
		{
			return SpellNumber(Input / 1000000000) + " billion and " + SpellNumber(Input % 1000000000);
		}
		else return SpellNumber(Input / 1000000000) + " billion" + SpellNumber(Input % 1000000000);
	}
}

string SpellGenericNumber(int Input) {
	if (Input >= 0) {
		return SpellNumber(Input);
	}
	else
	{
		return "Negative " + SpellNumber(-Input);
	}
}

int main() {

	int Num = 0; Num = ReadInput_int(Num);
	cout << SpellGenericNumber(Num);



}