#include <cs50.h>
#include <stdio.h>

long askccnumber(void);
int length (long n);

int main(void)
{
    //prompt user for a number until they cooperate by calling function number()
     long ccnumber = askccnumber();
    
     int cclength = length(ccnumber);
    
    
    //check that length of ccnumber is one of three values 13,15,or 16 if not print invalid condition 
     if (cclength != 13 && cclength!= 15 && cclength!= 16)
     {
         printf("INVALID\n");
     }
    
    // declare an array of cc length
    // fimd the nth integers to verify first 2 digits

    int ccarray[cclength];
    int i;

    // for loop up to the length of cc --- for each iteration of i we
    // take the remainder of ccnumber and assign it a position in array

    for ( i = 0; i < cclength; i++)
    {
        ccarray[i] = ccnumber % 10;
        ccnumber = ccnumber / 10;
    }

    int duparray[cclength];

    for ( i = 1; i < cclength; i++)
    {
        duparray[i] = ccarray [i];
    }

    for ( i = 1; i < cclength; i+=2)
    {
        ccarray[i] = ccarray[i] * 2;
    }

    // check sum of each card

    int check = 0;
    int sum;

    if ( cclength == 13)
        {
        for (i=0; i < cclength; i++)
            {
                sum = (ccarray[i] % 10) + (ccarray[i]/10 % 10);
                check = check + sum;   
            }
        if (duparray[12]== 4 && check % 10 ==0)
            {
                printf("VISA\n");
            }

        else 
            {
                printf ("INVALID\n");
            }
        }

    if (cclength == 16)
        {
        for ( i = 0; i < cclength; i++)
            {
                sum = (ccarray[i] % 10) + (ccarray[i]/10 % 10);
                check = check + sum;
            }
        
        if (duparray[15] == 4 && check % 10 == 0 )
            {
                printf("VISA\n");
            }

        else if (duparray[15] == 5 && check % 10 == 0 && (duparray[14] == 1 || duparray[14] == 2                  || duparray[14] == 3 || duparray[14] == 4 || duparray[14] == 5))
            {
                printf("MASTERCARD\n");
            }
        else
            {
                printf("INVALID\n");
            }
        }

    if ( cclength == 15)
        {
        for (i = 0; i < cclength; i++)
            {
                sum = (ccarray[i] % 10) + (ccarray[i]/10 % 10);
                check = check + sum;
            }

        if (duparray[14] == 3 && check % 10 == 0 && (duparray[13] == 4 || duparray[13] == 7))
            {
                printf("AMEX\n");
            } 

        else 
            {
                printf("INVALID\n");
            }
        }

}



long askccnumber(void)
{
    long ccnumber = 0;
    do
    {
        ccnumber =  get_long("Enter card number:");    
    }
    while (ccnumber < 0); 
    return ccnumber;
}
// while condition is false
// function legnth takes in a long variable, n, and divides it by ten
// and increments count by 1
int length (long n)
{
    int count = 0;
    long numbers = n;
    
    while(numbers > 0)
    {
     numbers = numbers/10;
     count++;   
    }
    
     return count;
    
}

// can make if statements to check the count to see if length(n) matches our conditions 
