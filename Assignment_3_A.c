//sjf_preemptive
#include <stdio.h>
#include <stdbool.h>

struct Process
{
	int pid;
	int at;
	int bt;
	int ct, tt, wt, rt, st;
};

int main()
{
	int size = 0;
	printf("Enter number of processes: ");
	scanf("%d", &size);
	struct Process ps[size];

	printf("\nEnter process Details: \n");
	for (int i = 0; i < size; ++i)
	{
		printf("Enter %dth process details: \n", i + 1);
		ps[i].pid = i + 1;

		printf("\tEnter Arrival Time: ");
		scanf("%d", &ps[i].at);

		printf("\tEnter Burst Time: ");
		scanf("%d", &ps[i].bt);
	}

	printf("\n====================================================================================\n\n");
	printf("PID\tAT \t BT\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d \t %d \t %d \n", ps[i].pid, ps[i].at, ps[i].bt);
	}
	printf("\n\n====================================================================================\n\n");

	// Input Done

	int n = size;
	int completed = 0;
	int currentTime = 0;
	int burstTimeR[4];
	bool iscompleted[4] = {false};

	float avgWT = 0, avgTT = 0, avgRT = 0;

	for (int i = 0; i < n; i++)
	{
		burstTimeR[i] = ps[i].bt;
	}

	while (completed != n)
	{

		int minimum = 99999;
		int miniI = -1;
		for (int i = 0; i < n; i++)
		{
			if ((ps[i].at <= currentTime) && (iscompleted[i] == false))
			{
				if (burstTimeR[i] < minimum)
				{
					minimum = burstTimeR[i];
					miniI = i;
				}
				if (burstTimeR[i] == minimum)
				{
					if (ps[i].at < ps[miniI].at)
					{
						minimum = burstTimeR[i];
						miniI = i;
					}
				}
			}
		}

		if (miniI == -1)
		{
			currentTime++;
		}
		else
		{

			if (burstTimeR[miniI] == ps[miniI].bt)
			{
				ps[miniI].st = currentTime;
			}

			burstTimeR[miniI] -= 1;
			currentTime++;

			if (burstTimeR[miniI] == 0)
			{

				ps[miniI].ct = currentTime;
				ps[miniI].tt = ps[miniI].ct - ps[miniI].at;
				ps[miniI].wt = ps[miniI].tt - ps[miniI].bt;
				ps[miniI].rt = ps[miniI].st - ps[miniI].at;

				avgWT += ps[miniI].wt;
				avgTT += ps[miniI].tt;
				avgRT += ps[miniI].rt;

				completed++;
				iscompleted[miniI] = true;
			}
		}
	}

	printf("PID \t AT \t BT \t CT \t TT \t WT \t RT \t\n");
	for (int i = 0; i < n; i++)
	{

		printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t\n", ps[i].pid, ps[i].at, ps[i].bt, ps[i].ct, ps[i].tt, ps[i].wt, ps[i].rt);
	}
	printf("\n\n====================================================================================\n");

	printf("\n\n AVG WT: %f", avgWT / n);
	printf("\n\n AVG TT: %f", avgTT / n);
	printf("\n\n AVG RT: %f", avgRT / n);
	printf("\n\n====================================================================================\n");
}

/*

ranjeet@vmbox:~/Documents/os/Assignment - 03$ gcc pract.c
ranjeet@vmbox:~/Documents/os/Assignment - 03$ ./a.out
Enter number of processes: 4

Enter process Details:
Enter 1th process details:
	Enter Arrival Time: 0
	Enter Burst Time: 5
Enter 2th process details:
	Enter Arrival Time: 1
	Enter Burst Time: 3
Enter 3th process details:
	Enter Arrival Time: 2
	Enter Burst Time: 4
Enter 4th process details:
	Enter Arrival Time: 4
	Enter Burst Time: 1

====================================================================================

PID      AT      BT
1      0      5
2      1      3
3      2      4
4      4      1


====================================================================================
PID      AT      BT      CT      TT      WT      RT
1        0       5       9       9       4       0
2        1       3       4       3       0       0
3        2       4       13      11      7       7
4        4       1       5       1       0       0


====================================================================================


 AVG WT: 2.750000

 AVG TT: 6.000000

 AVG RT: 1.750000

====================================================================================

*/

// #include <stdio.h>
// #include <stdbool.h>

// struct Process
// {
// 	int pid;
// 	int arrivalTime;
// 	int burstTime;
// 	int completionTime, waitingTime, turnaroundTime, responseTime, startTime;
// } ps[6];

// int main()
// {
// 	ps[0].pid = 0;
// 	ps[0].arrivalTime = 0;
// 	ps[0].burstTime = 8;

// 	ps[1].pid = 1;
// 	ps[1].arrivalTime = 1;
// 	ps[1].burstTime = 4;

// 	ps[2].pid = 2;
// 	ps[2].arrivalTime = 2;
// 	ps[2].burstTime = 2;

// 	ps[3].pid = 3;
// 	ps[3].arrivalTime = 3;
// 	ps[3].burstTime = 1;

// 	ps[4].pid = 4;
// 	ps[4].arrivalTime = 4;
// 	ps[4].burstTime = 3;

// 	ps[5].pid = 5;
// 	ps[5].arrivalTime = 5;
// 	ps[5].burstTime = 2;

// 	// main program
// 	int n = 6;			 // total number of process
// 	int completed = 0;	 // number of completed process
// 	int currentTime = 0; // current time

// 	float avgTurnaroundTime = 0, avgWaitingTime = 0, avgResponseTime = 0;

// 	int burstTimeRemaining[6];	   // contain remaining burst time of each process
// 	bool isCompleted[6] = {false}; // check process is completed (executed totally) or not

// 	// adding burst time of each process to remaing burst time array
// 	for (int i = 0; i < n; i++)
// 	{
// 		burstTimeRemaining[i] = ps[i].burstTime;
// 	}

// 	while (completed != n)
// 	{
// 		// find process with minimum burst time in ready queue

// 		int minimum = 1e9;	   // contain process with minimum burst time
// 		int minimumIndex = -1; // contain index of process with minimum burst time
// 		for (int i = 0; i < n; i++)
// 		{
// 			if (ps[i].arrivalTime <= currentTime && isCompleted[i] == false)
// 			{
// 				if (burstTimeRemaining[i] < minimum)
// 				{
// 					minimum = burstTimeRemaining[i];
// 					minimumIndex = i;
// 				}
// 				if (burstTimeRemaining[i] == minimum)
// 				{
// 					if (ps[i].arrivalTime < ps[minimumIndex].arrivalTime)
// 					{
// 						minimum = burstTimeRemaining[i];
// 						minimumIndex = i;
// 					}
// 				}
// 			}
// 		}

// 		if (minimumIndex == -1)
// 		{
// 			currentTime++;
// 		}
// 		else
// 		{
// 			if (burstTimeRemaining[minimumIndex] == ps[minimumIndex].burstTime)
// 			{
// 				ps[minimumIndex].startTime = currentTime;
// 			}

// 			burstTimeRemaining[minimumIndex] -= 1;
// 			currentTime++;

// 			if (burstTimeRemaining[minimumIndex] == 0)
// 			{
// 				ps[minimumIndex].completionTime = currentTime;
// 				ps[minimumIndex].turnaroundTime = ps[minimumIndex].completionTime - ps[minimumIndex].arrivalTime;
// 				ps[minimumIndex].waitingTime = ps[minimumIndex].turnaroundTime - ps[minimumIndex].burstTime;
// 				ps[minimumIndex].responseTime = ps[minimumIndex].startTime - ps[minimumIndex].arrivalTime;

// 				avgTurnaroundTime += ps[minimumIndex].turnaroundTime;
// 				avgWaitingTime += ps[minimumIndex].waitingTime;
// 				avgResponseTime += ps[minimumIndex].responseTime;

// 				completed++;
// 				isCompleted[minimumIndex] = true;
// 			}
// 		}
// 	}

// 	printf("PID \t AT \t BT \t TT \t WT \t CT \t RT\n");
// 	for (int i = 0; i < n; i++)
// 	{
// 		printf("%d \t %d \t %d \t %d \t %d \t %d \t %d\n", ps[i].pid, ps[i].arrivalTime, ps[i].burstTime, ps[i].turnaroundTime, ps[i].waitingTime, ps[i].completionTime, ps[i].responseTime);
// 	}

// 	printf("\nAverage turnaround time: %f\n", avgTurnaroundTime / n);
// 	printf("Average waiting time: %f\n", avgWaitingTime / n);
// 	printf("Average response time: %f\n", avgResponseTime / n);

// 	return 0;
// }
