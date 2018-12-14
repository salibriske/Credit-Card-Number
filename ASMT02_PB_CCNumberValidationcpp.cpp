//
//ASMT02_PB_CCNumberValidation.cpp
//Tommy Tran
//Partner: Brandon Chen
//Due Date 10/18/18
//CSC340 Assignment 2B
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <iomanip>
using namespace std;

bool isvalidcc(const string&);
int evenDigitSum(const string&);
int oddDigitSum(const string&);


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
		"5556551555555557", "6011316011016011",
		//Test cases
		//"12345", "420", "37", "12367126387216836127836127638712636128"
		//
	};

	int i;
	vector<string>::iterator itr;


	for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
		cout << setw(2) << i << " "
			<< setw(17) << *itr;
		cout << ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;
	}


	return 0;
}
bool isvalidcc(const string& cardN) {
	bool check = false;
	//Check to the card number are between 13 and 16
	//Check for card numbers for '4' Visa cards, '5' MasterCard cards, '37' American Express cards, '6' Discover cards.
	//Check to see the cards are valid or not 
	if ((cardN.length() >= 13 && cardN.length() <= 16) && (cardN.substr(0, 1) == "4" || cardN.substr(0, 1) == "5" || cardN.substr(0, 1) == "6" || cardN.substr(0, 2) == "37")){
		check = true;
	}else{
		check = false;
	}
	if (check) {
		if ((evenDigitSum(cardN) + oddDigitSum(cardN)) % 10 == 0) {
			check = true;
		}else if ((evenDigitSum(cardN) + oddDigitSum(cardN)) % 10 != 0) {
			check = false;
		}
	}
	return check;
}
// This method adds all digits in the even places from right to left in the credit card.
int evenDigitSum(const string& cardN) {
	int temp = 0;
	int evenSum = 0;
	for (int i = (cardN.length() - 2); i >= 0; i -= 2) {
		temp = (cardN[i] - '0') * 2;
		//Multiple of 2
		//if it is double digit.
		//adding any 2 digits of double digit to make 1 digit if it is double digit
		if (temp <= 9) {
			evenSum += temp;
		}else if (temp > 9) {
			temp = (temp - 9);
			evenSum += temp;
		}
	}
	return evenSum;
}
// This method adds all digits in the odd places from right to left in the credit card.
int oddDigitSum(const string& cardN) {
	int oddSum = 0;
	for (int i = (cardN.length() - 1); i >= 0; i -= 2) {
		oddSum += (cardN[i] - '0');
	}
	return oddSum;
}