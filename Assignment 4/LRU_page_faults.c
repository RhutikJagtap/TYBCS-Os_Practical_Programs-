/*Set A
2) Implement LRU
1.Write the simulation program to implement demand paging and show the page
scheduling and total number of page faults for the following given page reference string.
Give input n as the number of memory frames.

Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8

*/
#include <stdio.h>
#define MAX 20

int frames[MAX], ref[MAX], mem[MAX][MAX], faults,
    sp, m, n, time[MAX];
void accept()
{
    int i;
    printf("Enter no.of frames:");
    scanf("%d", &n);
    printf("Enter no.of references:");
    scanf("%d", &m);
    printf("Enter reference string:\n");
    for (i = 0; i < m; i++)
    {
        printf("[%d]=", i);
        scanf("%d", &ref[i]);
    }
}
void disp()
{
    int i, j;
    for (i = 0; i < m; i++)
        printf("%3d", ref[i]);
    printf("\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (mem[i][j])
                printf("%3d", mem[i][j]);
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", faults);
}
int search(int pno)
{
    int i;
    for (i = 0; i < n; i++)
    {

        if (frames[i] == pno)
            return i;
    }
    return -1;
}
int get_lru()
{
    int i, min_i, min = 9999;
    for (i = 0; i < n; i++)
    {
        if (time[i] < min)
        {
            min = time[i];
            min_i = i;
        }
    }
    return min_i;
}

void lru()
{
    int i, j, k;
    for (i = 0; i < m && sp < n; i++)
    {
        k = search(ref[i]);
        if (k == -1)
        {
            frames[sp] = ref[i];
            time[sp] = i;
            faults++;
            sp++;
            for (j = 0; j < n; j++)
                mem[j][i] = frames[j];
        }
        else
            time[k] = i;
    }
    for (; i < m; i++)
    {
        k = search(ref[i]);
        if (k == -1)
        {
            sp = get_lru();

            frames[sp] = ref[i];
            time[sp] = i;
            faults++;
            for (j = 0; j < n; j++)
                mem[j][i] = frames[j];
        }
        else
            time[k] = i;
    }
}

int main()
{
    accept();
    lru();
    disp();
    return 0;
}

// @Code By Rj
/*
Output:
Enter no.of frames:4
Enter no.of references:12 15 12 18 6 8 11 12 19 12 6 8 12 15 19 8
Enter reference string:
[0]=[1]=[2]=[3]=[4]=[5]=[6]=[7]=[8]=[9]=[10]=[11]= 15 12 18  6  8 11 12 19 12  6  8 12

 15 15 15 15  8  8  8  8     6  6
    12 12 12 12 11 11 11    11  8
       18 18 18 18 12 12    12 12
           6  6  6  6 19    19 19
Total Page Faults: 10

*/
