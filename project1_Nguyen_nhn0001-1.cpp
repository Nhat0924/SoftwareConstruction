/* FILE NAME: project1_Nguyen_nhn0001.cpp
 * AUTHOR: Nhat Nguyen - nhn0001
 * Edit using C++ Online Compiler/VS Code and compile using g++ in Linux bash shell/server.
 * Format used from Project 1_hint by Dr. Li
 * Comment: Learned to use while loop to prevent program from moving forward from Brady Hauglie
 * Talked with Nathan Hunter about the interest rate.
 * Minor tweak for total interest rates after discussing with John Gunasekaran.
 */

#include <iostream>
using namespace std;

int
main ()
{
  // VARIABLE INITIALIZATION 
   int month = 0;
   double loan = 0;
   double interest, interestRate = -1, interestRateC;
   double monthlyPaid = 0;
   double principal;
   double interestTotal;


  // CURRENCY FORMATTING 
   cout.setf (ios::fixed);
   cout.setf (ios::showpoint);
   cout.precision (2);

  // USER INPUT 
  // NOTE: For valid input, the loan, interest, and monthly payment must 
  // be positive. The monthly payment must also be large enough to 
  // terminate the loan. 

  //Comment: Learned to use while loop to prevent program from moving forward from Brady Hauglie.
   while (loan <= 0) 
   {
      cout << "\nLoan Amount: ";
      cin >> loan;
   }

  //Your program will not move forward until a positive load is entered 
   while (interestRate <= -1) 
   {
      cout << "Interest Rate (% per year): ";
      cin >> interestRate;
   }

//Your program will not move forward until a positive interest rate is entered 

  // GET PROPER INTEREST RATES FOR CALCULATIONS 
   interestRate /= 12;
   interestRateC = interestRate / 100;
   interest = interestRateC * loan;
   while (monthlyPaid <= 0 || monthlyPaid <= interest)
   {
      cout << "Monthly Payments: ";
      cin >> monthlyPaid;
   }

  //Your program will not move forward until a monthly payment is sufficient 
   cout << endl;

  // Talked with Nathan Hunter about calculating interest rates.
  // Minor tweak for total interest rates after discussing with John Gunasekaran.
  // AMORTIZATION TABLE 
   cout <<
      "*****************************************************************\n" <<
      "\tAmortization Table\n" <<
      "*****************************************************************\n" <<
      "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

  // LOOP TO FILL TABLE 
   while (loan > 0)
   {
      if (month == 0)
      {
         cout << month++ << "\t$" << loan;
         if (loan < 1000)
            cout << "\t";	// Formatting MAGIC 
         cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
      }
      else
      {
         if (loan >= monthlyPaid)
         {
            interest = interestRateC * loan;
            principal = monthlyPaid - interest;
            loan -= principal;
            interestTotal += interest;
         }
         if (loan < monthlyPaid)
         {
            if (loan != 0)
            {
               cout << month++ << "\t$" << loan;
               if (loan < 1000)
                  cout << "\t";	// Formatting MAGIC 
               cout << "\t$" << monthlyPaid << "\t" << interestRate << "\t$" <<
                  interest << "\t\t$" << principal << "\n";
            }
            interest = interestRateC * loan;
            monthlyPaid = loan + interest;
            principal = loan;
            loan = 0;
            interestTotal += interest;
         }
         cout << month++ << "\t$" << loan;
         if (loan < 1000)
            cout << "\t";	// Formatting MAGIC 
         cout << "\t$" << monthlyPaid << "\t" << interestRate << "\t$" <<
            interest << "\t\t$" << principal << "\n";
      }
   }
   cout <<
      "****************************************************************\n";
   cout << "\nIt takes " << --month << " months to pay off " << "the loan.\n"
      << "Total interest paid is: $" << interestTotal;
   cout << endl << endl;
   return 0;
}
