/*The Electricity Bill Calculator is an application-based micro project that calculates
the month’s electricity bill based on the appliances or loads and units consumed.
People who do not have a technical understanding of calculating power bills can use
this program to forecast/calculate their electricity bills. The application should have
the following features:
 To display the Meter Number
 To display the previous meter reading
 Facility to enter present meter-reading
 To display the no. of units consumed
 To display the complete Tariff Structure (Domestic, Non-Domestic, Industrial)
 Provision to input the no. of units consumed per month
 To display the bill-amount payable as per the tariff structure
 To display the due date of the payment*/

// Micro project  By YASHEEB FARIDI

#include <stdio.h>
#include <stdlib.h>

int meter_no = 652689356;

int main(){
    int past_read = 3457;
    float present_read, unit_consumed;
    char ch;
    float chg, total_amt, amt;
    float monthly_consu;
    printf("This project is done by Yasheeb Faridi.\n");
    printf("The Meter no. is: %d\n", meter_no);
    printf("The past reading is: %d\n", past_read);

    printf("Enter present meter reading: ");
    scanf("%f", &present_read);

    unit_consumed = present_read - past_read;
    printf("\nThe no. of units consumed is: %f", unit_consumed);
    
    printf("\n\n***************Tariff charges******************\nType Charges per month consumption\n");
    printf("Domestic 'Less than 200'    @1.2/unit\n");
    printf("upto '400 more than 200'    @1.5/unit\n");
    printf("upto '600 more than 400'    @1.8/unit\n");
    printf("More than 600               @2.0/unit\n");
    printf("Non-domestic                @2.0/unit\n");
    printf("Indrustrial                 @2.5/unit\n");
    printf("Surcharge amount after every 10 days of non repayment: @ Rs 20\n");

    printf("Enter 'D' for Domestic, 'N for Non Domestic and 'I' for industrial: ");
    scanf(" %c", &ch);
    if (ch == 'D' || ch == 'd'){
        if (unit_consumed < 200)
            chg = 1.2;
        else if (200 <= unit_consumed && unit_consumed < 400)
            chg = 1.5;
        else if (400 <= unit_consumed && unit_consumed <= 600)
            chg = 1.8;
        else if (unit_consumed > 600)
            chg = 2.0;
        else
            printf("\nUnit COnsumed must be positive\n");
    } else if (ch == 'N' || ch == 'n'){
        printf("\nNON Domestic Consumption:\n");
        chg = 2.0;
    }else if (ch == 'I' || ch == 'i'){
        printf("\nIndustrial Consumer:\n");
        chg = 2.5;
    }else{
        printf("\nPlease Enter D, N or I");
    }
    
    total_amt = unit_consumed * chg;
    // if due date exceeded   net_amount = amt + surcharge fee

    printf("\n**************Electricity Bill*************\n");
    printf("Total amount due for %f units: %f", unit_consumed, total_amt);

    printf("\nEnter Units Consumed per month: ");
    scanf("%f", &monthly_consu);
    amt = monthly_consu * chg;
    printf("\nBill amount for this months %f: %f", monthly_consu, amt);
    printf("\nDue date for payment :7th of every month\n");

    return 0;
}