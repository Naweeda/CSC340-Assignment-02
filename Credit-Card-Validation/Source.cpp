#include <iostream>
#include <vector>;
#include <iomanip>

using namespace std;

bool isvalidcc(const string& cardVal);
bool cardValdations(const string& cardnums);
int doubleOddsSum(const string& num);
int doubleEvenSum(const string& num);


int main()
{
	//
	// PLEASE DO NOT CHANGE function main
	//

	vector<string> cardnumbers = {
		 "371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
		"4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
		"5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
		"4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
		"5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
		 "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
		"4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
		"5556551555555557", "6011316011016011"
	};



	int i;
	vector<string>::iterator itr;

	for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
		cout << setw(2) << i << " " << setw(17) << *itr
			<< ((isvalidcc(*itr)) ? " is valid " : " is not valid") << endl;
		//cout << "Default : " << char(result) << endl;
		//cout << "RESULT : " << char(result) << endl;
	}

	return 0;
}
bool isvalidcc(const string& cardnumbers)
{
	//The card digit validation condition 
	if (cardnumbers.size() >= 13 && cardnumbers.size() <= 16)
	{   
		//if it is true than return true if the even place added to odd place is divisible by 10
		if (cardValdations(cardnumbers)) {
			//cout << "Double odd sum : " << doubleOddsSum(cardnumbers) << endl;
			//cout << "Double even sum : " << doubleEvenSum(cardnumbers) << endl;

			return ((doubleOddsSum(cardnumbers) + doubleEvenSum(cardnumbers)) % 10 == 0);
		}
		else {
			cout << "card validation failed" << endl;
			return false;
		}
	}
	else
	{
		//cout << "card size failed" << endl;
		return false;
	}
}
/*
Function that checks if starting numbers are: 4 for Visa cards, 5 for
MasterCard cards, 37 for American Express cards, and 6 for Discover cards.
*/
bool cardValdations(const string& cardnumbers)
{

	if (cardnumbers[0] == '4' || cardnumbers[0] == '5' || cardnumbers[0] == '6' || (cardnumbers[0] == '3' && cardnumbers[1] == '7'))
	{
		//cout << " i m in card validation" << endl;
		return true;
	}
	else
	{
		cout << "card vvalidator failed" << endl;
		return false;
	}
}
/*
Function that doubles every second digit from right to left. If doubling of a digit results
in a two-digit number, it adds the two digits to get a single digit number.
*/
int doubleEvenSum(const string& cardnumbers)
{
	int result = 0;
	int sumOfNumbers;

	for (int i = cardnumbers.size() - 2; i >= 0; i -= 2)
	{

		//Converting the Ascii values to int
		sumOfNumbers = (cardnumbers[i] - '0') * 2;

		if (sumOfNumbers > 9)
		{
			sumOfNumbers = (sumOfNumbers / 10) + (sumOfNumbers % 10);
		}
		result += sumOfNumbers;
	}
	return result;
}
/*
Function which adds all digits in the odd places from right to left in the card number
*/
int doubleOddsSum(const string& cardnumbers)
{
	int oddNumSum = 0;
	for (int i = cardnumbers.size() - 1; i >= 0; i -= 2)
	{
		//Converting the Ascii values to int
		oddNumSum += cardnumbers[i] - '0';
	}
	return oddNumSum;
}




