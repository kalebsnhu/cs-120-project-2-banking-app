#pragma once
#ifndef BANKING_APP_H
#define BANKING_APP_H
#include <string>

using namespace std;

/**
 * Class (BankingApp) entire class for the banking app
 *
 * @private: variables are private to keep the banking app safe
 * @public: functions are public for getters/setters
 */
class BankingApp {
	private: // create private variables for the class
		double initialInvestment;
		double monthlyDeposit;
		double annualInterest;
		int numberofYears;
	
	public: // create setters/getters for the class
		BankingApp();
		BankingApp(double initialInvestment, double monthlyDeposit, double annualInterest, int numberofYears);
		void SetInitialInvestment(double initialInvestment);
		double GetInitialInvestment();
		void SetMonthlyDeposit(double monthlyDeposit);
		double GetMonthlyDeposit();
		void SetAnnualInterest(double annualInterest);
		double GetAnnualInterest();
		void SetNumberOfYears(int numberofYears);
		int GetNumberOfYears();
};

#endif