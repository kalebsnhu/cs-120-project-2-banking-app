/*
 * main.cpp
 *
 *  Date: 11-27-22
 *  Author: Kaleb Ward
 */

#include <iostream>
using namespace std;

#include "bankingapp.h"
#include <iomanip>

// I created the functions above main, I like having main at the top so I defined the functions so it would not throw errors in compiling/running
void printDetails(int year, double yearEndBalance, double interestEarned);
double balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears);
double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears);
void centeredPrint(const char* stringtoCenter);
void mainMenu();


int main() {

	mainMenu();
	return 0;
}

/**
 * Function (failureCallbackDouble) this function (double) is for the cin.failure, it allows the user to input callback text and re-entry for the input
 *
 * @param validCommand: intial text for cin.error
 * @param commandNotification: the text for the user to input a new command
 * @param cinInput: the cin.input variable for the user to re-entry
 */
void failureCallbackDouble(const char* validCommand, const char* commandNotification, double cinInput) {
	std::cout << validCommand << endl;
	std::cin.clear();
	std::cin.ignore(256, '\n');
	cout << commandNotification;
	std::cin >> cinInput;
}

/**
 * Function (failureCallbackInt) this function (integer) is for the cin.failure, it allows the user to input callback text and re-entry for the input
 *
 * @param validCommand: intial text for cin.error
 * @param commandNotification: the text for the user to input a new command
 * @param cinInput: the cin.input variable for the user to re-entry
 */
void failureCallbackInt(const char* validCommand, const char* commandNotification, int cinInput) {
	std::cout << validCommand << endl;
	std::cin.clear();
	std::cin.ignore(256, '\n');
	cout << commandNotification;
	std::cin >> cinInput;
}

/**
 * Function (mainMenu) this function (double) is for the cin.failure, it allows the user to input callback text and re-entry for the input
 *
 * Description: This is the brains of the banking application, this is the user interface and all commands to set/get for the banking application
 */
void mainMenu() {
	while (1) {
		cout << string(70, '-') << endl;
		centeredPrint("> Data Input");
		cout << string(70, '=') << endl;

		double initialInvestment; // initialize variable for initial investment
		double monthlyDeposit; // initialize variable for monthly deposit
		double annualInterest; // initialize variable for annual interest
		int numberofYears; // initialize variable for number of years

		cout << "> Initial Investment Amount: $"; // Receive the intial investment amount from the user
		cin >> initialInvestment;

		while (std::cin.fail()) { // if the user enters an invalid command we can use failureCallbackDouble to receive a new response
			failureCallbackDouble("You did not enter a valid amount.", "> Initial Investment Amount: $", initialInvestment);
		}

		cout << "> Monthly Deposit: $"; // Receive the intial monthly deposit from the user
		cin >> monthlyDeposit;

		while (std::cin.fail()) { // if the user enters an invalid command we can use failureCallbackDouble to receive a new response
			failureCallbackDouble("You did not enter a valid monthly deposit.", "> Monthly Deposit: $", monthlyDeposit);
		}

		cout << "> Annual Interest: %"; // Receive the intial annual interest from the user
		cin >> annualInterest;

		while (std::cin.fail()) { // if the user enters an invalid command we can use failureCallbackDouble to receive a new response
			failureCallbackDouble("You did not enter a valid annual interest.", "> Annual Interest: %", annualInterest);
		}

		cout << "> Number of Years: ";  // Receive the intial number of years from the user
		cin >> numberofYears;

		while (std::cin.fail()) { // if the user enters an invalid command we can use failureCallbackInt to receive a new response
			failureCallbackInt("You did not enter a valid number of years.", "> Number of Years: ", numberofYears);
		}

		BankingApp bankingApp = BankingApp(initialInvestment, monthlyDeposit, annualInterest, numberofYears); // create the banking application

	backtoEnd: // create a coroutine/goto function to go back to this position from the future
			
			// print the balances with and without monthly deposit.
			calculateBalanceWithoutMonthlyDeposit(bankingApp.GetInitialInvestment(), bankingApp.GetAnnualInterest(), bankingApp.GetNumberOfYears());
			cout << endl;
			balanceWithMonthlyDeposit(bankingApp.GetInitialInvestment(), bankingApp.GetMonthlyDeposit(), bankingApp.GetAnnualInterest(), bankingApp.GetNumberOfYears());

			cout << "Type 'q' or 'quit' to exit or type 'r' or 'reset' to reset all amounts. You can also type 'other' or 'edit' to edit individual amounts." << endl;
			string userEntry;
			cout << "> ";
			cin >> userEntry;

			while (cin.fail()) { // if the user enters an invalid command we can use cin.fail() to receive a new response
				cout << "You did not enter a valid answer." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cout << ">";
				cin >> userEntry;
			}

			if (userEntry == "q" or userEntry == "quit") { // if the user types q or quit then exit the banking application
				break;
			}
			else if (userEntry == "r" or userEntry == "reset") { // if the user types reset then we can reset the entire banking application
				system("cls");
				mainMenu();
			}
			else if (userEntry == "other" or userEntry == "edit") { // if the user types edit or other then we can ask the user to edit/change individual values
				cout << "What would you like to edit? Type a corresponding number to edit that option." << endl;
				cout << "[1] Initial Investment Amount\n[2] Monthly Deposit\n[3] Annual Interest\n[4] Number of Years" << endl;

				int userEntry;
				cout << "> ";
				cin >> userEntry;
				while (std::cin.fail()) { // if the user enters an invalid command we can use failureCallbackInt to receive a new response
					failureCallbackInt("You did not enter a valid option.", "> ", userEntry);
				}

				switch (userEntry) { // create a switch case to receive commands from the user
				case 1: // if the user chose case 1 then we can edit the initial investment amount
					double userCaseInitialInvestment;
					cout << "> Initial Investment Amount: $";
					cin >> userCaseInitialInvestment;

					while (std::cin.fail()) { // if the user enters an invalid command we can use failureCallbackDouble to receive a new response
						failureCallbackDouble("You did not enter a valid amount.", "> Initial Investment Amount: $", userCaseInitialInvestment);
					}

					bankingApp.SetInitialInvestment(userCaseInitialInvestment); // use the setter function to set the initial investment
					system("cls"); // clear the console window
					goto backtoEnd; // we can use the coroutine/goto we created earlier to reset and show the balances and ask the user for input

				case 2: // if the user chose case 2 then we can edit the monthly deposit
					double userCaseMonthlyDeposit;
					cout << "> Monthly Deposit: $";
					cin >> userCaseMonthlyDeposit;

					while (std::cin.fail()) { // if the user enters an invalid command we can use failureCallbackDouble to receive a new response
						failureCallbackDouble("You did not enter a valid monthly deposit.", "> Monthly Deposit: $", userCaseMonthlyDeposit);
					}
					bankingApp.SetMonthlyDeposit(userCaseMonthlyDeposit); // use the setter function to set the monthly deposit
					system("cls"); // clear the console window
					goto backtoEnd; // we can use the coroutine/goto we created earlier to reset and show the balances and ask the user for input

				case 3: // if the user chose case 2 then we can edit the annual interest
					double userCaseAnnualInterest;
					cout << "> Annual Interest: %";
					cin >> userCaseAnnualInterest;

					while (std::cin.fail()) { // if the user enters an invalid command we can use failureCallbackDouble to receive a new response
						failureCallbackDouble("You did not enter a valid annual interest.", "> Annual Interest: %", userCaseAnnualInterest);
					}
					bankingApp.SetAnnualInterest(userCaseAnnualInterest); // use the setter function to set the annual interest
					system("cls"); // clear the console window
					goto backtoEnd; // we can use the coroutine/goto we created earlier to reset and show the balances and ask the user for input

				case 4: // if the user chose case 2 then we can edit the number of years
					int userCaseNumberOfYears;
					cout << "> Number of Years: ";
					cin >> userCaseNumberOfYears;

					while (std::cin.fail()) { // if the user enters an invalid command we can use failureCallbackInt to receive a new response
						failureCallbackInt("You did not enter a valid number of years.", "> Number of Years: ", userCaseNumberOfYears);
					}
					bankingApp.SetNumberOfYears(userCaseNumberOfYears); // use the setter function to set the number of years
					system("cls"); // clear the console window
					goto backtoEnd; // we can use the coroutine/goto we created earlier to reset and show the balances and ask the user for input

				}

			}

		break;

	}
}

/**
 * Function (centeredPrint) this function allows us to center text
 *
 * @param stringtoCenter: the string for us to center in a 70 character limit
 */
void centeredPrint(const char *stringtoCenter) {
	int charLen = strlen(stringtoCenter);
	
	printf("%*s\n", ((70 - charLen) / 2 + charLen), stringtoCenter);
}

/**
 * Function (printDetails) this function prints the years with the corresponding year end balance and interest earned
 *
 * @param year: the year for the corresponding year to print
 * @param yearEndBalance: the year end balance for the corresponding year to print
 * @param interestEarned: the interest earned for the corresponding year to print
 */
void printDetails(int year, double yearEndBalance, double interestEarned) {
	cout << fixed << right << setw(9) << setfill(' ') << year << "\t";
	cout << fixed << right << setw(11) << setfill(' ') << ' '; printf("$%.2f", yearEndBalance); cout << "\t\t";
	cout << fixed << right << setw(7) << setfill(' ') << ' '; printf("$%.2f", interestEarned);
	cout << endl;
}

/**
 * Function (balanceWithMonthlyDeposit) this function prints the yearly balance with monthly deposit
 *
 * @param initialInvestment: the initial investment for the banking application
 * @param monthlyDeposit: the monthly deposit for the banking application
 * @param interestRate: the interest rate for the banking application
 * @param numberOfYears: the number of years to print
 */
double balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {
	cout << string(70, '-') << endl;
	centeredPrint("> Balance and Interest With Additional Monthly Deposits");
	cout << string(70, '=') << endl;
	printf("%10s%30s%30s\n", "Year", "Year End Balance", "Year End Earned Interest");
	cout << string(70, '-') << endl;

	double yearEndBalance = initialInvestment; // create variable yearEndBalance so we can edit in the future

	for (int i = 0; i < numberOfYears; i++) { // create a for loop for less than number of years
		double yearInterest = 0;
		for (int m = 0; m < 12; m++) { // create a for loop looping through 12 months
			double monthlyInterest = (yearEndBalance + monthlyDeposit) * ((interestRate / 100) / 12); // calculate monthly interest
			yearInterest += monthlyInterest;
			yearEndBalance += monthlyDeposit + monthlyInterest;
		}

		printDetails(i + 1, yearEndBalance, yearInterest); // print the details we calculated before
	}

	cout << string(70, '-') << endl;

	return yearEndBalance;

}

/**
 * Function (calculateBalanceWithoutMonthlyDeposit) this function prints the yearly balance without monthly deposit
 *
 * @param initialInvestment: the initial investment for the banking application
 * @param interestRate: the interest rate for the banking application
 * @param numberOfYears: the number of years to print
 */
double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {
	cout << string(70, '-') << endl;
	centeredPrint("> Balance and Interest Without Additional Monthly Deposits");
	cout << string(70, '=') << endl;
	printf("%10s%30s%30s\n", "Year", "Year End Balance", "Year End Earned Interest");
	cout << string(70, '-') << endl;

	double yearEndBalance = initialInvestment; // create variable yearEndBalance so we can edit in the future
	double yearInterest = 0; // create variable yearInterest set to 0

	for (int i = 0; i < numberOfYears; i++) { // create a for loop for less than number of years

		yearInterest = yearEndBalance * (interestRate / 100);
		yearEndBalance += yearInterest;
		printDetails(i + 1, yearEndBalance, yearInterest); // print the details we calculated before
	}

	cout << string(70, '-') << endl;

	return yearEndBalance;
}