#include <stdio.h>

void print_queue_order(int n)
{
    int queue[n];
    int front = 0;
    int rear = -1;

    for (int i = 1; i <= n; i++)
    {
        rear++;
        queue[rear] = i;
    }

    for (int i = front; i <= rear; i++)
    {
        printf("%d", queue[i]);
        if (i < rear)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int main()
{
    printf("Queue order for n = 5: ");
    print_queue_order(5);

    printf("Queue order for n = 10: ");
    print_queue_order(10);

    printf("Queue order for n = 1: ");
    print_queue_order(1);

    return 0;
}