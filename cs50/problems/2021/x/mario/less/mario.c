#include <stdio.h>
#include <cs50.h>

// check user prompt height are correct.
int checkLimit(int x)
{
    return 8 >= x && x > 0;
};

// user input pyramid height.
int userInputHeight(void)
{
    int num;
    do
    {
        num = get_int("height: ");
    }
    while (!checkLimit(num));
    return num;
};

// make pyramid.
int makePyramid(int amount)
{
    int totalHeight = amount;
    for (int i = 1; i <= totalHeight; i++)
    {
        int dot = totalHeight - i;
        for (int j = 1; j <= totalHeight; j++)
        {
            if (j <= dot)
            {
                printf("%c", ' ');
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
    return totalHeight;
}

// start
int main(void)
{
    int height = userInputHeight();
    return makePyramid(height);
}

