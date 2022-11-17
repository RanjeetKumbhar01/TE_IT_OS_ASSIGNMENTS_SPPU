#include <stdio.h>
//#inlude<Maths.h>
#include <limits.h>
int no_Track, N, Initial_Head_Pos, No_head_move, direction;

void sort(int arr[], int type, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (type == 1)
            {
                if (arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            else
            {
                if (arr[i] < arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
}
void SCAN(int req_que[])
{

    int right[N - 1], left[N - 1], r = 0, l = 0;

    right[r++] = no_Track - 1;
    for (int i = 0; i < N; i++)
    {
        if (req_que[i] > Initial_Head_Pos)
        {
            right[r++] = req_que[i];
        }
    }

    left[l++] = 0;
    for (int i = 0; i < N; i++)
    {
        if (req_que[i] < Initial_Head_Pos)
        {
            left[l++] = req_que[i];
        }
    }

    sort(right, 0, r);
    sort(left, 1, l);

    int completed = 2;
    while (completed > 0)
    {
        if (direction == 0)
        {
            for (int i = 0; i < r; i++)
            {
                No_head_move += abs(Initial_Head_Pos - right[i]);
                Initial_Head_Pos = right[i];
                printf("\t%d", right[i]);
            }
            direction = 1;
        }
        else
        {
            for (int i = 0; i < l; i++)
            {
                No_head_move += abs(Initial_Head_Pos - left[i]);
                Initial_Head_Pos = left[i];
                printf("\t%d", left[i]);
            }
            direction = 0;
        }
        completed--;
    }

    /* printf("\nright");
     for(int i=0;i<r;i++)
         printf("\t%d",right[i]);
         printf("\nleft");
     for(int i=0;i<l;i++)
         printf("\t%d",left[i]);*/
}

void main()
{
    printf("Enter the Number of track on Disk:");
    scanf("%d", &no_Track);
    printf("Enter the Number of process requesting to access Disk:");
    scanf("%d", &N);
    int Request_que[N];
    printf("Enter the Request Queue:");

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &Request_que[i]);
    }

    printf("Enter the initial Head position:");

    scanf("%d", &Initial_Head_Pos);

    printf("enter the Direction of Move (0 for higher otherwise 1):");
    scanf("%d", &direction);
    printf("\n=========================================");
    printf("\n       O U T P U T  ");
    printf("\n SEEK Sequesnce:");
    SCAN(Request_que);
    printf("\n Number of Head Move:%d", No_head_move);
}
