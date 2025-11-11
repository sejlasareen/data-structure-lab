#include <stdio.h>

int q[5], i, item, front = -1, rear = -1;

void enqueue(int item)
{
    if ((rear + 1) % 5 == front)
    {
        printf("The queue is full\n");
    }
    else
    {
        if ((rear == -1) && (front == -1))
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % 5;
        }
        q[rear] = item;
    }
}

void dequeue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The deleted item is %d\n", q[front]);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % 5;
        }
    }
}

void display()
{
    if ((front == -1) && (rear == -1))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are: ");
        if (front <= rear)
        {
            for (i = front; i <= rear; i++)
                printf("%d ", q[i]);
        }
        else
        {
            for (i = front; i < 5; i++)
                printf("%d ", q[i]);
            for (i = 0; i <= rear; i++)
                printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    do
    {
        printf("\nEnter the choice:");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            enqueue(item);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exit\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}
