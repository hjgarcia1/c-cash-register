#include <stdio.h>
#include <math.h>
#include <string.h>

int no_coins;

int process_change(int change, int coin) {
    while (change >= coin)
    {
        no_coins++;
        change = change - coin;
    }

    return change;
}

int main()
{
    int i, change = 5;
    int avail_coins[4] = {25,10,5,1};

    for ( i = 0; i < 4; i++)
    {
        change = process_change(change, avail_coins[i]);
    }

    printf("Number of Coins: %i\n", no_coins);
    
    return 0;
}