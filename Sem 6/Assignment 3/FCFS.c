#include <stdio.h>
#include <math.h>

int main()
{
    int queue[100], i, n, seek = 0, head, count = 0;
    float avg;
    printf("Enter the number of Requests : \n");
    scanf("%d", &n);
    printf("Enter the Requests sequence : \n");
    for (i = 0; i < n; i++)
        scanf("%d", &queue[i]);
    printf("Enter head head position : \n");
    scanf("%d", &head);

    while (count != n)
    {
        int min = 1000, d, index;
        for (i = 0; i < n; i++)
        {
            d = abs(queue[i] - head);
            if (min > d)
            {
                min = d;
                index = i;
            }
        }
        seek = seek + min;
        printf("\nDisk head moves from %d to %d with  seek %d", head, queue[index], min);
        head = queue[index];
        queue[index] = 1000;
        count++;
    }

    printf("\n\nTotal head movement is %d \n", seek);
    avg = seek / (float)n;
    printf("Average seek time is %0.2f\n", avg);
    return 0;
}
