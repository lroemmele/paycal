//************************************************************
//  Course Title:  Prg/218
//  Assignment Title:  Week 5 Program
//  Student Name:  Luke Roemmele
//  Date:  7/10/17
//  Professor:  Perry Bates
//  Description:  
//	This program calculates the pay and overtime pay of an employee. 
//	Program will recevie input from user, employees name, hours worked, wage
//  Program will display indvidual employee name, basepay, overtime pay amount, total pay. 
//	Program will also display total employees salaries, hours, overtime hours.
//***********************************************************************


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//
//CLASS DECLARATION SECTION
//Employee class contains payroll info for each employee created
class Employee {
public:
	void CalculatePay(void);
	void DisplayInformation(void);
	string EmployeeName;
	int hours;
	double wage;
	double basepay;
	int overtime_hours;
	double overtime_pay;
	double overtime_extra;
	double iIndividualSalary;
};

//FUNCTION DECLARATION SECTION
//Prototype AddSomethingUp funtion
void AddSomethingUp(Employee[]);
//


// main creates objects of employee class and prompts user for input of employee name, hours worked, wage
int main()
{
	system("cls");

	cout << "\nWelcome to the Employee Pay Center\n\n";

	// creates 3 objects of the employee class
	Employee john;
	Employee mary;
	Employee mark;

	//promt user for input
	cout << "Enter the employee name = ";
	cin >> john.EmployeeName;
	cout << "\nEnter the hours worked = ";
	cin >> john.hours;
	cout << "\nEnter his or her hourly wage =";
	cin >> john.wage;


	cout << "\nEnter the employee name = ";
	cin >> mary.EmployeeName;
	cout << "\nEnter the hours worked = ";
	cin >> mary.hours;
	cout << "\nEnter his or her hourly wage =";
	cin >> mary.wage;


	cout << "\nEnter the employee name = ";
	cin >> mark.EmployeeName;
	cout << "\nEnter the hours worked = ";
	cin >> mark.hours;
	cout << "\nEnter his or her hourly wage =";
	cin >> mark.wage;


	// calls the calculatePay funtion of the employee class to calculate salery and overtime hours
	john.CalculatePay();
	mary.CalculatePay();
	mark.CalculatePay();

	// creates an array of employee objects in empArry
	Employee empArry[] = { john, mary, mark };
	
	// calls the addsomethingup funtion and passes the empArray to calculate totals
	AddSomethingUp(empArry);


} //End of Main Function

//
//Caculatepay checks to see if employee worked over 40 hours, if over 40 hours calculates for overtime and salary
//
void Employee::CalculatePay() {
	//Initialize overtime variables
	overtime_hours = 0;
	overtime_pay = 0;
	overtime_extra = 0;

	if (hours > 40)
	{

		basepay = 40 * wage;
		overtime_hours = hours - 40;
		overtime_pay = wage * 1.5;
		overtime_extra = overtime_hours * overtime_pay;
		iIndividualSalary = overtime_extra + basepay;

	}	// if (hours > 40)
	else
	{
		basepay = hours * wage;
		iIndividualSalary = basepay;



	} // End of the else

	// Calls DisplayInformation to display calculations to user
	DisplayInformation();
	  


} //End of CalculatePay Function

void Employee::DisplayInformation() {
	// This function displays all the employee output information.
	

	cout << "\nEmployee Name ............. = " << EmployeeName;
	cout << "\nBase Pay .................. = " << basepay;
	cout << "\nHours in Overtime ......... = " << overtime_hours;
	cout << "\nOvertime Pay Amount........ = " << overtime_pay * overtime_hours;
	cout << "\nTotal Pay ................. = " << iIndividualSalary;
	cout << endl;
	cout << endl;

} // END OF Display Employee Information


// recevies an array of employee objects for calculations
void AddSomethingUp(Employee emps[]) {
	// This function calculates and displays the total employee output information.

	// Initialize running totals to zero
	double iTotal_salaries = 0.0;
	int iTotal_hours = 0;
	int iTotal_OvertimeHours = 0;

	
	// loops through each employe int the emps array and adds up total for total salaries, total hours, total overtimehours
	for (int i = 0; i < sizeof(emps)-1 ; i++) {
		iTotal_salaries += emps[i].iIndividualSalary;
		iTotal_hours += emps[i].hours;
		iTotal_OvertimeHours += emps[i].overtime_hours;

	}



	// displays total for salaries, hours, overtime hours
	cout<< "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
		<< "%%%% EMPLOYEE SUMMARY DATA%%%%%%%%%%%%%%%%%%%%%%%\n"
		<< "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
		<< "%%%% Total Employee Salaries ..... = " << iTotal_salaries << " %%%%%\n"
		<< "%%%% Total Employee Hours ........ = " << iTotal_hours << " %%%%%%%%\n"
		<< "%%%% Total Overtime Hours......... = " << iTotal_OvertimeHours << " %%%%%%%%%%\n"
		<< "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
		<< "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	
} // End of function


