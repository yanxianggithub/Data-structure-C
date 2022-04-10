#include <stdio.h>
int main()
{
    int i, score, min, max, sum = 0;
    for (i = 1; i < 11; i++)
    {
        printf("Input %d: ", i);
        scanf("%d", &score);
        if (i == 1)
            min = max = score;
        else
        {
            if (score > max)
                max = score;
            if (score < min)
                min = score;
        }
        sum += score;
    }
    printf("Min=%d Max=%d AVG=%.2f", min, max, 1.0 * (sum - max - min) / 8);
}
