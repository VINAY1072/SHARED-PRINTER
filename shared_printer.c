/*----------------------------------------------- SHARED PRINTER
----------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define PRINTER_MAX_SIZE 10

struct Printer
{
    int data;
    int task_number;
    struct Printer *next;
};

struct Printer *front;
struct Printer *rear;

void insert();
void delete ();
void display();
int count_tasks(struct Printer *p);

void main()
{
    int choice, a;
    printf("\033[0;31m");
    printf("\n*************************Main Menu*****************************\n");
    printf("\n=================================================================\n");
    printf("\033[0;32m");
    printf("\n1.INSERT YOUR TASK\n2.COLLECT FIRST FILE\n3.DISPLAY THE TASKS\n4.Exit\n");
    while (choice != 4)
    {
        printf("\033[0;33m");
        printf("\nEnter your choice ?");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (count_tasks(front) > PRINTER_MAX_SIZE) /* if tasks are
            10 you have to try again */
                printf("-------sorry there are already 10 tasks filled try again-------");
            else
                insert();
            break;
        case 2: /* Dequeue option enables only when it prints pages of
        particular completely */
            if (front == NULL)
                printf("------There are no tasks----------");
            else
            {
                a = front->data;
                printf("---------please collect your %d pages----------\n", a);
                delete ();
            }
            break;
        case 3:
            if (front == NULL)
                printf("------There are no tasks----------");
            else
            {
                printf("-------------These are the tasks in queue-------------\n");
                display();
            }
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nEnter valid choice??\n");
        }
    }
}
void insert()
{

    struct Printer *ptr;
    int pages;
    int task;
    ptr = (struct Printer *)malloc(sizeof(struct Printer));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        printf("\nEnter your coupon number and Number of pages?\n");
        scanf("%d %d", &task, &pages);
        ptr->data = pages;
        ptr->task_number = task;
        if (front == NULL)
        {
            front = ptr;
            rear = ptr;
            front->next = NULL;
            rear->next = NULL;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
}
void delete ()
{
    struct Printer *ptr;
    if (front == NULL)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        ptr = front;
        front = front->next;
        free(ptr);
    }
}
void display()
{
    struct Printer *ptr;
    ptr = front;
    if (front == NULL)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        printf(" Coupon Number | Number of pages ");
        while (ptr != NULL)
        {
            printf("\n[         %d     ,       %d      ]\n",
                   ptr->task_number, ptr->data);
            ptr = ptr->next;
        }
    }
}
int count_tasks(struct Printer *p)
{
    struct Printer *temp = p;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}