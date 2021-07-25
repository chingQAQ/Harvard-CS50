#include <cs50.h>
#include <stdio.h>

// check user input limit.
int checkHeight(int number)
{
    int max = 8;
    int min = 1;
    return min <= number && number <= max;
};

// get user input.
int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("height: ");
    }
    while (!checkHeight(n));
    return n;
};

// make pyramids function
int makePyramids(int height)
{
    int spaceAmount = 2;
    int pyramisHeight = height;
    int printLength = (height * 2) + spaceAmount;
    int middleSpaceRight = (printLength / 2);
    int middleSpaceLeft = (printLength / 2) - 1;

    // put hash in one char, and print it.
    for (int i = 1; i <= pyramisHeight; i++)
    {
        int small = pyramisHeight - i - 1;
        int big = printLength - small - 1;
        char result[printLength];
        for (int j = 0; j < printLength; j++)
        {
            // if current char is mid or not hash.
            if ((j == middleSpaceRight || j == middleSpaceLeft) || j <= small)
            {
                result[j] = ' ';
            }
            else if(j >= big)
            {
                break;
            }
            else
            {
                result[j] = '#';
            }
        };
        printf("%s\n", result);
    }
    return height;
};

int main(void)
{
    int ans = get_positive_int();
    return makePyramids(ans);
};
