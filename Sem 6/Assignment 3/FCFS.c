// C program for FCFS disk scheduling

#include <stdio.h>
#include <math.h>
int main()
{
    int queue[20], n, head, i, j, k, seek = 0, max, diff;
    float avg;
    gccprintf("\nEnter the max range of disk : \n");
    scanf("%d", &max);
    printf("Enter the size of queue request : \n");
    scanf("%d", &n);
    printf("Enter the queue of disk positions to be read :\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &queue[i]);
    printf("Enter the initial head position : \n");
    scanf("%d", &head);
    queue[0] = head;
    for (j = 0; j <= n - 1; j++)
    {
        diff = abs(queue[j + 1] - queue[j]);
        seek += diff;
        printf("\nDisk head moves from %d to %d with  seek %d", queue[j], queue[j + 1], diff);
    }
    printf("\n\nTotal seek time is %d\n", seek);
    avg = seek / (float)n;
    printf("Average seek time is %0.2f\n", avg);
    return 0;
}
