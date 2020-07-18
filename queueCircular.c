#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int front;
    int rear;
    int cap;
    int *array;
};
struct queue* createQueue(int capacity)
{
    struct queue *q;
    q=(struct queue*)malloc(sizeof(struct queue));
    q->front=-1;
    q->rear=-1;
    q->cap=capacity;
    q->array=(int *)malloc(capacity*sizeof(int));
    return q;
}
int isFull(struct queue *q)
{
    if((q->rear+1)%q->cap==q->front)
        return 1;
    else return 0;
}
int isEmpty(struct queue *q)
{
    if(q->rear==-1)
        return 1;
    else return 0;
}
void enqueue(struct queue *q,int item)
{
    if(isFull(q))
        printf("\nQueue is Full.");
    else if(q->rear==-1)
    {
        q->rear=0;
        q->front=0;
        q->array[q->rear]=item;
    }
    else
    {
        q->rear=(q->rear+1)%q->cap;
        q->array[q->rear]=item;
    }
}
int dequeue(struct queue *q)
{
    int item;
    if(isEmpty(q))
    {
        return -1;
    }
    else if(q->rear==q->front)
    {
        item=q->array[q->front];
        q->rear=-1;
        q->front=-1;
        return item;
    }
    else
    {
        item=q->array[q->front];
        q->front=(q->front+1)%q->cap ;
        return item;
    }
}
void peek(struct queue *q)
{
    printf("\nFront value is %d",q->front);
    printf("\nRear value is %d",q->rear);
}
void display(struct queue *q)
{
    int i;
    if(isEmpty(q))
        printf("\nQueue is empty.");
    else
    {
        i=q->front;
        while(i!=q->rear)
        {
            printf("\t%d",q->array[i]);
            i=(i+1)%q->cap;
        }
        printf("\t%d",q->array[q->rear]);
    }
}
void init()
{
    int capacity;
    struct queue *q;
    printf("\nEnter capacity of Queue");
    scanf("%d",&capacity);
    q=createQueue(capacity);
}
void main()
{
    int choice,item,capacity;
    struct queue *q;
    printf("\nEnter capacity of Queue");
    scanf("%d",&capacity);
    q=createQueue(capacity);
    do
    {
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Check if full");
        printf("\n4.Check if empty");
        printf("\n5.Peek");
        printf("\n6.Display Queue");
        printf("\n7.Reinitialize Q");
        printf("\n8.Exit");
        printf("\nEnter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                printf("\nEnter element to be entered:");
                scanf("%d",&item);
                enqueue(q,item);
                break;
            }
        case 2:
            {
                item=dequeue(q);
                if(item==-1)
                    printf("\nQueue was Empty");
                else
                    printf("\nRemoved value is %d",item);
                    break;
            }
        case 3:
            {
                if(isFull(q))
                    printf("\nQueue is Full.");
                else
                    printf("\nQueue is not Full.");
                    break;
            }
        case 4:
            {
                if(isEmpty(q))
                    printf("\nQueue is Empty.");
                else
                    printf("\nQueue is not Empty.");
                break;
            }
        case 5:
            {
                peek(q);
                break;
            }
        case 6:
            {
                display(q);
                break;
            }
        case 7:
            {
                init();
                break;
            }
        case 8:
            {
                exit(0);
            }
        default:
            {
                printf("Invalid choice.");
                break;
            }
        }
    }while(1);
}

