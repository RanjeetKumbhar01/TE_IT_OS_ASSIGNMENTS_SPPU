#include <stdio.h>
//#inlude<Maths.h>
#include <limits.h>
int no_Track, N, Initial_Head_Pos, No_head_move;

int min_index(int req_que[], int visited[])
{
    int min = INT_MAX, index = -1;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i] && abs(Initial_Head_Pos - req_que[i]) < min)
        {
            min = abs(Initial_Head_Pos - req_que[i]);
            index = i;
        }
    }
    return index;
}

void SSTF(int request_que[], int visited[])
{
    int min_Index;
    for (int i = 0; i < N; i++)
    {
        min_Index = min_index(request_que, visited);
        visited[min_Index] = 1;
        Initial_Head_Pos = request_que[min_Index];
        printf("\t%d", request_que[min_Index]);
        No_head_move += request_que[min_Index];
    }
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
    int Visited[N];
    for (int i = 0; i < N; i++)
        Visited[i] = 0;
    printf("\n");

    printf("\n=========================================");
    printf("\n       O U T P U T  ");
    printf("\n SEEK Sequesnce:");
    SSTF(Request_que, Visited);
    printf("\n Number of Head Move:%d", No_head_move);
}
