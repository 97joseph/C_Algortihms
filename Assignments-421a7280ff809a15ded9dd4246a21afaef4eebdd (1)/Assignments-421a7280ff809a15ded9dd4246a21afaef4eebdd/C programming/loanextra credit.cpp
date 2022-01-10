// Program name: Amortized loan extra credit
// 
// Author: Dillon Pinto 

// Course:  Computer Science 217
// 
// 
// Description: 
//               
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double calc_new_balance(int payment_no,double old_balance,double payment_amount, double interest_rate_per_period){
		double period_interest_amount=old_balance*interest_rate_per_period;
		double new_principle_payment=payment_amount-period_interest_amount;
		double new_balance= old_balance- new_principle_payment;
		printf("\n%i\t%.2lf\t    %.2lf\t\t%.2lf\t\t%.2lf",payment_no,payment_amount,period_interest_amount,new_principle_payment,new_balance);
		return new_balance;
						}

int main(void) 
{
double old_balance,payment_amount,interest_rate_per_period,i;
int num_payments_per_year,total_num_of_payment_periods,p,payment_no;

printf("Amortized loan calculator\n\n");

printf("Enter the loan amount>");
scanf("%lf",&old_balance);
printf("Enter the annual interest rate>");
scanf("%lf",&i);
printf("Enter total loan payments>");
scanf("%i",&total_num_of_payment_periods);
printf("Enter the payments per year>");
scanf("%i",&p);
printf("Enter the interest compounds per year < o<compounds =<365>>");
scanf("%i",&num_payments_per_year);


printf("no#\tPayment\tInterest_paid\t    Principle_paid\tBalance");
interest_rate_per_period=(1+ pow((float)((i/100.0)/num_payments_per_year),(float)(num_payments_per_year/p )))-1;
payment_amount=old_balance*( (interest_rate_per_period*pow(1+interest_rate_per_period,total_num_of_payment_periods) )/\
							(pow(1+interest_rate_per_period,total_num_of_payment_periods) -1)  );
for (payment_no=1;payment_no<=total_num_of_payment_periods;payment_no++){
	
	old_balance=calc_new_balance(payment_no,old_balance, payment_amount,  interest_rate_per_period);
}

return 0;
}
