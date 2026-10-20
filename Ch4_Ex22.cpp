/* Program File Name: Ch4_Ex22
Programmer: Frank Sonsini
Date : October 2026
Requirements : For mobile phone plans billing, write a program that inputs the customer's name, plan chosen and gigabytes used.
Calculate and output the customer's monthly bill.
If a customer in Plans A or B would have saved by being in a higher plan, calculate and output the savings.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string first_name, last_name;
    char plan;
    double gigabytes_used, monthly_bill, what_if_plan_B_cost;

    const double plan_A_monthly_cost = 39.99, plan_B_monthly_cost = 59.99, plan_C_monthly_cost = 79.99, additional_gigabyte_cost = 8.00;
    const int plan_A_gigabytes_allotment = 2, plan_B_gigabytes_allotment = 8;

    cout << fixed << showpoint << setprecision(2);

    cout << "What is your first name?" << endl;
    cin >> first_name;
    cout << "What is your last name?" << endl;
    cin >> last_name;
    cout << "What mobile phone plan do you have - A, B or C?" << endl;
    cin >> plan;
    cout << "How many gigabytes of data did you use last month?" << endl;
    cin >> gigabytes_used;

    if (gigabytes_used < 0)
        cout << "The number of gigabytes you used must be a non-negative number.  Please rerun the program with a valid number of gigabytes used." << endl;
    else
    {

        switch (plan)
        {
        case 'a':
        case 'A':
            monthly_bill = plan_A_monthly_cost + ((gigabytes_used >= plan_A_gigabytes_allotment) ? (gigabytes_used - plan_A_gigabytes_allotment) : 0) * additional_gigabyte_cost;

            what_if_plan_B_cost = plan_B_monthly_cost + ((gigabytes_used >= plan_B_gigabytes_allotment) ? (gigabytes_used - plan_B_gigabytes_allotment) : 0) * additional_gigabyte_cost;

            cout << first_name << " " << last_name << "  Your Plan A monthly bill for using " << gigabytes_used << " gigabytes is $" << monthly_bill << endl;

            if (what_if_plan_B_cost < monthly_bill)
                cout << "You would have saved $" << monthly_bill - what_if_plan_B_cost << " if you were in plan B." << endl;

            if (plan_C_monthly_cost < monthly_bill)
                cout << "You would have saved $" << monthly_bill - plan_C_monthly_cost << " if you were in plan C." << endl;
            break;

        case 'b':
        case 'B':
            monthly_bill = plan_B_monthly_cost + ((gigabytes_used >= plan_B_gigabytes_allotment) ? (gigabytes_used - plan_B_gigabytes_allotment) : 0) * additional_gigabyte_cost;
            cout << first_name << " " << last_name << "  Your Plan B monthly bill for using " << gigabytes_used << " gigabytes is $" << monthly_bill << endl;

            if (plan_C_monthly_cost < monthly_bill)
                cout << "You would have saved $" << monthly_bill - plan_C_monthly_cost << " if you were in plan C." << endl;
            break;

        case 'c':
        case 'C':
            monthly_bill = plan_C_monthly_cost;
            cout << first_name << " " << last_name << "  Your Plan C monthly bill is $" << monthly_bill << endl;
            break;

        default:
            cout << "Your choice of mobile phone plan must be A, B or C. Please rerun the program with a valid phone plan choice." << endl;
        }
    }

    return 0;
}

