/* fcfs
    55, 58, 39, 18, 90, 160, 150, 38, 184
    head 50;
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int total = 0;
    int que[] = {55, 58, 39, 18, 90, 160, 150, 38, 184};
    int currentHead = 50;

    for (int i = 0; i < 9; i++)
    {
        printf("%d -> ", currentHead);
        total += abs(currentHead - que[i]);
        currentHead = que[i];
    }
    printf("%d", currentHead);

    printf("\nTotal head movement : %d", total);

    return 0;
}