//Matteo Podesta
//Lab #6

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

int fractionCount = 0;

void printFractionCount() {
	cout << "Current amount of fraction classes in memory is: " << fractionCount << endl;
}

class fraction {
public:
	fraction();
	fraction(fraction& fraction);
	fraction(int wholeInput);
	fraction(int numeratorInput, int denominatorInput);
	fraction(int numeratorInput, int denominatorInput, int wholeInput);
	~fraction();

	void setNumerator(int input) { numerator = input; }
	void setDenominator(int input) { denominator = input; }

	void setFraction(int numeratorInput, int denominatorInput, int wholeInput);
	void setFraction(int NumeratorInput, int DenominatorInput);
	void setFraction(int NumeratorInput);

	void catchFunction(int Numerator, int Nenominator, int Whole);

	string printFraction();
	string toString();

private:
	const int DEFAULT_NUMERATOR = 1;
	const int DEFAULT_DENOMINATOR = 1;
	const int DEFAULT_WHOLE = 0;

	int numerator = DEFAULT_NUMERATOR;
	int denominator = DEFAULT_DENOMINATOR;
	int whole = DEFAULT_WHOLE;
};

enum {
	DENOMINATOR_ZERO = 1,
	NUMERATOR_ZERO,
	NEGATIVE,
	TOO_BIG,
	QUIT
};

int main() {

	int input = 0;
	while (input != QUIT) {
		
		cout << "\nMenu:\n"
			"1. Denominator of 0\n"
			"2. Numerator of 0\n"
			"3. Negative number in the fraction\n"
			"4. Numerator is larger then whole\n"
			"5. Quit\n"
			"Input: ";
		cin >> input;
		
		switch (input) {
		case DENOMINATOR_ZERO:
			{
				fraction Cheese(3, 0);
			}
			printFractionCount();
			break;
		case NUMERATOR_ZERO:
			{
				fraction Cheese(0, 3);
			}
			printFractionCount();
			break;
		case NEGATIVE:
			{
				fraction Cheese(2, 5, -1);
			}
			printFractionCount();
			break;
		case TOO_BIG:
			{
				fraction Cheese(3, 1, 5);
			}
			printFractionCount();
			break;
		case QUIT:
			break;
		}
	}
}

fraction::fraction() {
	fractionCount++;
	setFraction(DEFAULT_NUMERATOR, DEFAULT_DENOMINATOR, whole);
}
fraction::~fraction() {
	numerator = 0;
	denominator = 1;
	fractionCount--;
}
fraction::fraction(int NumeratorInput) {
	fractionCount++;
	setFraction(NumeratorInput, denominator, whole);
}
fraction::fraction(int NumeratorInput, int DenominatorInput) {
	fractionCount++;
	setFraction(NumeratorInput, DenominatorInput, whole);
}
fraction::fraction(int NumeratorInput, int DenominatorInput, int WholeInput) {
	fractionCount++;
	setFraction(NumeratorInput, DenominatorInput, WholeInput);
}
fraction::fraction(fraction& fraction) {
	fractionCount++;
	fraction.numerator = numerator;
	fraction.denominator = denominator;
	fraction.whole = whole;
}

string fraction::printFraction() {

	ostringstream text;
	text << numerator << "/" << denominator;
	return text.str();

}
string fraction::toString() {

	ostringstream text;
	text << whole << " " << numerator << "/" << denominator;
	return text.str();

}

void fraction::catchFunction(int Numerator, int Denominator, int Whole) {
	if (Numerator < 0) {
		cout << "Error: numerator is set to " << Numerator << endl;
		throw Numerator;
	}
	if (Denominator < 0) {
		cout << "Error: denominator is set to " << Denominator << endl;
		throw Denominator;
	}
	if (Whole < 0) {
		cout << "Error: whole is set to " << Whole << endl;
		throw Whole;
	}

	if (Numerator == 0) {
		cout << "Error: numerator is set to " << Numerator << endl;
		throw Numerator;
	}
	else if (Denominator == 0) {
		cout << "Error: denominator is set to " << Denominator << endl;
		throw Denominator;
	}

	if (Numerator > Denominator) {
		if (Whole > 0) {
			cout << "Error: Improper fraction formatting\n";
			throw Whole;
		}
	}
}
void fraction::setFraction(int numeratorInput, int denominatorInput, int wholeInput){
	
	numerator = numeratorInput;
	denominator = denominatorInput;
	whole = wholeInput;
	printFractionCount();
	try {
		catchFunction(numeratorInput, denominatorInput, wholeInput);
	}
	catch (...) {
		cout << "The fraction " << toString() << " is Invalid\n";
	}
	
}
void fraction::setFraction(int NumeratorInput, int DenominatorInput) {
	setFraction(NumeratorInput, DenominatorInput, whole);
}
void fraction::setFraction(int NumeratorInput) {
	setFraction(NumeratorInput, denominator, whole);
}
//Function defenitions---------------------------------------------------------------
