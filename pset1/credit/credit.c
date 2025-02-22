#include <cs50.h>
#include <math.h>
#include <stdio.h>

// card length
#define AMEX_LENGTH 10000000000000
#define MASTERCARD_2DIGITS_LENGHT 100000000000000
#define MASTERCARD_1DIGIT_LENGHT 1000000000000000
#define VISA_MAX_LENGTH 1000000000000000
#define VISA_MIN_LENGTH 1000000000000

// card prefix
#define AMEX_PREFIX_34 34
#define AMEX_PREFIX_37 37
#define MASTERCARD_PREFIX_5 5
#define VISA_PREFIX_4 4

int main(void)
{
    long num = get_long("Number: "), base_div = 10, base_divRest = 1;
    int card, count1 = 0, sum, count2 = 0;
    string card_name;

    if ((num / AMEX_LENGTH == AMEX_PREFIX_34) || (num / AMEX_LENGTH == AMEX_PREFIX_37))
    {
        card = 15;
        card_name = "AMEX";
    }
    else if ((num / MASTERCARD_1DIGIT_LENGHT == MASTERCARD_PREFIX_5) && (num / MASTERCARD_2DIGITS_LENGHT < 56) && (num / MASTERCARD_2DIGITS_LENGHT != 50))
    {
        card = 16;
        card_name = "MASTERCARD";
    }
    else if (num / VISA_MAX_LENGTH == VISA_PREFIX_4)
    {
        card = 16;
        card_name = "VISA";
    }
    else if (num / VISA_MIN_LENGTH == VISA_PREFIX_4)
    {
        card = 13;
        card_name = "VISA";
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }

    long numbers[card];
    int size1 = card / 2, size2 = ceil(card / 2.0);
    int step1[size1], step2[size2];

    for (int i = 0; i < card; i++)
    {
        numbers[i] = num % base_div;
        base_div = base_div * 10;
        numbers[i] = numbers[i] / base_divRest;
        base_divRest = base_divRest * 10;

        if (i % 2 != 0)
        {
            step1[count1] = numbers[i] * 2;
            if (step1[count1] > 9)
            {
                step1[count1] = ((step1[count1] / 10) + (step1[count1] % 10));
            }
            count1++;
        }
        else
        {
            step2[count2] = numbers[i];
            if (step2[count2] > 9)
            {
                step2[count2] = ((step2[count2] / 10) + (step2[count2] % 10));
            }
            count2++;
        }
    }

    sum = step1[0];
    for (int i = 1; i < ((size1)); i++)
    {
        sum = sum + step1[i];
    }

    sum = sum + step2[0];
    for (int i = 1; i < ((size2)); i++)
    {
        sum = sum + step2[i];
    }

    if (sum % 10 == 0)
    {
        printf("%s\n", card_name);
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
