#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

// Insert element at front
void insertFront(int value)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque is Full!\n");
    }
    else if (front == -1)
    {
        front = rear = 0;
        deque[front] = value;
        printf("%d inserted at front.\n", value);
    }
    else if (front == 0)
    {
        front = MAX - 1;
        deque[front] = value;
        printf("%d inserted at front.\n", value);
    }
    else
    {
        front--;
        deque[front] = value;
        printf("%d inserted at front.\n", value);
    }
}

// Insert element at rear
void insertRear(int value)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque is Full!\n");
    }
    else if (front == -1)
    {
        front = rear = 0;
        deque[rear] = value;
        printf("%d inserted at rear.\n", value);
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
        deque[rear] = value;
        printf("%d inserted at rear.\n", value);
    }
    else
    {
        rear++;
        deque[rear] = value;
        printf("%d inserted at rear.\n", value);
    }
}

// Delete element from front
void deleteFront()
{
    if (front == -1)
    {
        printf("Deque is Empty!\n");
    }
    else
    {
        printf("%d deleted from front.\n", deque[front]);

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}

// Delete element from rear
void deleteRear()
{
    if (front == -1)
    {
        printf("Deque is Empty!\n");
    }
    else
    {
        printf("%d deleted from rear.\n", deque[rear]);

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = MAX - 1;
        }
        else
        {
            rear--;
        }
    }
}

// Display deque
void display()
{
    int i;

    if (front == -1)
    {
        printf("Deque is Empty!\n");
        return;
    }

    printf("Deque elements are: ");

    i = front;

    while (1)
    {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- DOUBLE ENDED QUEUE ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

