#include <stdio.h>
#include <math.h>
#include <string.h>

int no_coins;
int no_single_dollars;
int no_half_dollars;
int no_quarters;
int no_dimes;
int no_nickels;
int no_pennies;

int process_change(int change, int coin);
void print_results(float total_change);

int main()
{
    int i, avail_coins[6] = {100, 50, 25, 10, 5, 1};
    float change, total_change;

    printf("*********Cash Register*********\n");
    printf("What is the change: ");
    scanf("%f", &change);

    total_change = change;
    change = round(change * 100);

    for (i = 0; i < 6; i++)
    {
        change = process_change(change, avail_coins[i]);
    }

    print_results(total_change);

    return 0;
}

int process_change(int change, int coin)
{
    while (change >= coin)
    {
        no_coins++;

        if (coin == 100)
        {
            no_single_dollars++;
        }

        if (coin == 50)
        {
            no_half_dollars++;
        }

        if (coin == 25)
        {
            no_quarters++;
        }

        if (coin == 10)
        {
            no_dimes++;
        }

        if (coin == 5)
        {
            no_nickels++;
        }

        if (coin == 1)
        {
            no_pennies++;
        }

        change = change - coin;
    }

    return change;
}

void print_results(float total_change)
{
    printf("Number of Coins: %i\n", no_coins);
    printf("Number of Single Dollar Bills: %i\n", no_single_dollars);
    printf("Number of Half Dollars: %i\n", no_half_dollars);
    printf("Number of Quaters: %i\n", no_quarters);
    printf("Number of Dimes: %i\n", no_dimes);
    printf("Number of Nickels: %i\n", no_nickels);
    printf("Number of Pennies: %i\n", no_pennies);
    printf("\n");
    printf("Total change is: $%.2f", total_change);
}