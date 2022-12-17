/*
 * bankingapp.cpp
 *
 *  Date: 11-27-22
 *  Author: Kaleb Ward
 */

#include <iostream>
using namespace std;

#include "bankingapp.h"
#include <iomanip>

/**
 * Initialize default BankingApp() variables.
 */
BankingApp::BankingApp() {
	initialInvestment = 0;
	monthlyDeposit = 0;
	annualInterest = 0;
	numberofYears = 0;
}

/**
 * Function (BankingApp) initialize banking app class with variables provided.
 *
 * @param initialInvestment: initial investment for the banking app
 * @param monthlyDeposit: monthly deposit for the banking app
 * @param annualInterest: annual interest for the banking app
 * @param numberofYears: number of years for the banking app
 */
BankingApp::BankingApp(double initialInvestment, double monthlyDeposit, double annualInterest, int numberofYears) {
	this->initialInvestment = initialInvestment;
	this->monthlyDeposit = monthlyDeposit;
	this->annualInterest = annualInterest;
	this->numberofYears = numberofYears;
}

/**
 * Setter (SetInitialInvestment) sets the initial investment for the banking app
 *
 * @param initialInvestment: initial investment for the banking app
 */
void BankingApp::SetInitialInvestment(double initialInvestment) {
	this->initialInvestment = initialInvestment;
}

/**
 * Getter (SetInitialInvestment) gets the initial investment for the banking app
 *
 * @return initialInvestment: initial investment for the banking app
 */
double BankingApp::GetInitialInvestment() {
	return this->initialInvestment;
}

/**
 * Setter (SetMonthlyDeposit) sets the monthly deposit for the banking app
 *
 * @param monthlyDeposit: monthly deposit for the banking app
 */
void BankingApp::SetMonthlyDeposit(double monthlyDeposit) {
	this->monthlyDeposit = monthlyDeposit;
}

/**
 * Getter (GetMonthlyDeposit) gets the monthly deposit for the banking app
 *
 * @return monthlyDeposit: monthly deposit for the banking app
 */
double BankingApp::GetMonthlyDeposit() {
	return this->monthlyDeposit;
}

/**
 * Setter (SetAnnualInterest) sets the annual interest for the banking app
 *
 * @param monthlyDeposit: annual interest for the banking app
 */
void BankingApp::SetAnnualInterest(double annualInterest) {
	this->annualInterest = annualInterest;
}

/**
 * Getter (GetAnnualInterest) gets the annual interest for the banking app
 *
 * @return monthlyDeposit: annual interest for the banking app
 */
double BankingApp::GetAnnualInterest() {
	return this->annualInterest;
}

/**
 * Setter (SetNumberOfYears) sets the number of years for the banking app
 *
 * @param numberofYears: number of years for the banking app
 */
void BankingApp::SetNumberOfYears(int numberofYears) {
	this->numberofYears = numberofYears;
}

/**
 * Getter (GetNumberOfYears) gets the number of years for the banking app
 *
 * @return numberofYears: number of years for the banking app
 */
int BankingApp::GetNumberOfYears() {
	return this->numberofYears;
}

