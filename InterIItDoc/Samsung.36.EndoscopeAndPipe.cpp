#include<stdio.h>
#include<iostream>
using namespace std;

class Solution
{
private:
	/* data */

public:
	int N,M,R,C,L, maxNumPipes;
	int distro[50][50];
	Solution();

	int numPipes(int entry_row, int entry_column, int pipesVisited, int comingFrom);

};

Solution :: Solution()
{
	N = 0;
	M = 0;
	R = 0;
	C = 0;
	L = 0;

	maxNumPipes = 0;

	for (int i=0; i<50;i++)
	{
		for (int j=0; j<50; j++)
		{
			distro[i][j] = 0;
		}
	}
}

int Solution :: numPipes(int entry_row, int entry_column, int pipesVisited, int comingFrom)
{

	if (pipesVisited > maxNumPipes)
	{
		maxNumPipes = pipesVisited;
	}

	if (pipesVisited == L)
	{
		maxNumPipes = L;
		return 1;
	}

	if (entry_row >= N)
	{
		if (pipesVisited > maxNumPipes)
		{
			maxNumPipes = pipesVisited;
		}

		return 1;
	}

	if (entry_column >= M)
	{
		if (pipesVisited > maxNumPipes)
		{
			maxNumPipes = pipesVisited;
		}

		return 1;
	}

	int pipeType = distro[entry_row][entry_column];
    // Make sure to check if the pipe you are about to visit next has not been visited before.
    distro[entry_row][entry_column] = 0;
    if (pipeType == 0){
        if (pipesVisited > maxNumPipes){
            maxNumPipes = pipesVisited;
        }
        return 1;
    }
    if (pipeType == 1)
    {

        if (entry_row - 1 >= 0 && ((distro[entry_row - 1][entry_column] == 1) || (distro[entry_row - 1][entry_column] == 2) || (distro[entry_row - 1][entry_column] == 5) || (distro[entry_row - 1][entry_column] == 6)))
        {
            //Go UP
            numPipes(entry_row - 1, entry_column, pipesVisited + 1, 3);
        }
        if (entry_row + 1 < N && ((distro[entry_row + 1][entry_column] == 1) || (distro[entry_row + 1][entry_column] == 2) || (distro[entry_row + 1][entry_column] == 4) || (distro[entry_row + 1][entry_column] == 7)))
        {
            //Go Down
            numPipes(entry_row + 1, entry_column, pipesVisited + 1, 1);
        }
        if (entry_column - 1 >= 0 && ((distro[entry_row][entry_column - 1] == 1) || (distro[entry_row][entry_column - 1] == 3) || (distro[entry_row][entry_column - 1] == 4) || (distro[entry_row][entry_column - 1] == 5)))
        {
            //Go Left
            numPipes(entry_row, entry_column - 1, pipesVisited + 1, 2);
        }
        if (entry_column + 1 < M && ((distro[entry_row][entry_column + 1] == 1) || (distro[entry_row][entry_column + 1] == 3) || (distro[entry_row][entry_column + 1] == 6) || (distro[entry_row ][entry_column + 1] == 7)))
        {
            //Go Right
            numPipes(entry_row, entry_column + 1, pipesVisited + 1, 4);
        }
    }
    else if (pipeType == 2){
        if (entry_row - 1 >= 0 && ((distro[entry_row - 1][entry_column] == 1) || (distro[entry_row - 1][entry_column] == 2) || (distro[entry_row - 1][entry_column] == 5) || (distro[entry_row - 1][entry_column] == 6)))
        {
            //Go UP
            numPipes(entry_row - 1, entry_column, pipesVisited + 1, 3);
        }
        if (entry_row + 1 < N && ((distro[entry_row + 1][entry_column] == 1) || (distro[entry_row + 1][entry_column] == 2) || (distro[entry_row + 1][entry_column] == 4) || (distro[entry_row + 1][entry_column] == 7)))
        {
            //Go Down
            numPipes(entry_row + 1, entry_column, pipesVisited + 1, 1);
        }
    }
    else if (pipeType == 3){
        if (entry_column - 1 >= 0 && ((distro[entry_row][entry_column - 1] == 1) || (distro[entry_row][entry_column - 1] == 3) || (distro[entry_row][entry_column - 1] == 4) || (distro[entry_row][entry_column - 1] == 5)))
        {
            //Go Left
            numPipes(entry_row, entry_column - 1, pipesVisited + 1, 2);
        }
        if (entry_column + 1 < M && ((distro[entry_row][entry_column + 1] == 1) || (distro[entry_row][entry_column + 1] == 3) || (distro[entry_row][entry_column + 1] == 6) || (distro[entry_row][entry_column + 1] == 7)))
        {
            //Go Right
            numPipes(entry_row, entry_column + 1, pipesVisited + 1, 4);
        }
    }   
    else if (pipeType == 4){
        if (entry_row - 1 >= 0 && ((distro[entry_row - 1][entry_column] == 1) || (distro[entry_row - 1][entry_column] == 2) || (distro[entry_row - 1][entry_column] == 5) || (distro[entry_row - 1][entry_column] == 6)))
        {
            //Go UP
            numPipes(entry_row - 1, entry_column, pipesVisited + 1, 3);
        }
        if (entry_column + 1 < M && ((distro[entry_row][entry_column + 1] == 1) || (distro[entry_row][entry_column + 1] == 3) || (distro[entry_row][entry_column + 1] == 6) || (distro[entry_row][entry_column + 1] == 7)))
        {
            //Go Right
            numPipes(entry_row, entry_column + 1, pipesVisited + 1, 4);
        }
    }
    else if (pipeType == 5){
        if (entry_row + 1 < N && ((distro[entry_row + 1][entry_column] == 1) || (distro[entry_row + 1][entry_column] == 2) || (distro[entry_row + 1][entry_column] == 4) || (distro[entry_row + 1][entry_column] == 7)))
        {
            //Go Down
            numPipes(entry_row + 1, entry_column, pipesVisited + 1, 1);
        }
        if (entry_column + 1 < M && ((distro[entry_row][entry_column + 1] == 1) || (distro[entry_row][entry_column + 1] == 3) || (distro[entry_row][entry_column + 1] == 6) || (distro[entry_row][entry_column + 1] == 7)))
        {
            //Go Right
            numPipes(entry_row, entry_column + 1, pipesVisited + 1, 4);
        }
    }
    else if (pipeType == 6){
        if (entry_row + 1 < N && ((distro[entry_row + 1][entry_column] == 1) || (distro[entry_row + 1][entry_column] == 2) || (distro[entry_row + 1][entry_column] == 4) || (distro[entry_row + 1][entry_column] == 7)))
        {
            //Go Down
            numPipes(entry_row + 1, entry_column, pipesVisited + 1, 1);
        }
        if (entry_column - 1 >= 0 && ((distro[entry_row][entry_column - 1] == 1) || (distro[entry_row][entry_column - 1] == 3) || (distro[entry_row][entry_column - 1] == 4) || (distro[entry_row][entry_column - 1] == 5)))
        {
            //Go Left
            numPipes(entry_row, entry_column - 1, pipesVisited + 1, 2);
        }
    }
    else if (pipeType == 7){
        if (entry_row - 1 >= 0 && ((distro[entry_row - 1][entry_column] == 1) || (distro[entry_row - 1][entry_column] == 2) || (distro[entry_row - 1][entry_column] == 5) || (distro[entry_row - 1][entry_column] == 6)))
        {
            //Go UP
            numPipes(entry_row - 1, entry_column, pipesVisited + 1, 3);
        }
        if (entry_column - 1 >= 0 && ((distro[entry_row][entry_column - 1] == 1) || (distro[entry_row][entry_column - 1] == 3) || (distro[entry_row][entry_column - 1] == 4) || (distro[entry_row][entry_column - 1] == 5)))
        {
            //Go Left
            numPipes(entry_row, entry_column - 1, pipesVisited + 1, 2);
        }
    }
    //restore the value
    distro[entry_row][entry_column] = pipeType;
    return 0;
}



int main()
{
	cout<<" Samsung 36 question :- "<<endl;
	cout<<" Endoscope and pipe "<<endl;
    cout<<" galat h "<<endl;
	cout<<endl;

	// Company S has developed an industrial endoscope available to
	 // explore inner part of the decrepit water pipes. It is possible
	  // to explore the inner part of the pipes putting the endoscope
	   // in a certain part of the pipe. The endoscope can be moved in
	    // the pipe only. Meanwhile, when the pipes are connected to
	 // each other, if the length of the endoscope is long enough to
	  // explore ,then it is able to inspect the connected pipes. 
	// However, we cannot observe every pipe because the length of
	 // endoscope is limited.

	int T;

	scanf("%d",&T);

	while (T>0)
	{
		T--;
		Solution s;

		int N,M,R,C,L;
		scanf("%d %d %d %d %d",&N,&M,&R,&C,&L);

		s.N = N;
		s.M = M;
		s.R = R;
		s.C = C;
		s.L = L;

		for (int i=0;i<N;i++)
		{
			for (int j=0;j<M;j++)
			{
				scanf("%d",&s.distro[i][j]);
			}
		}

		if (s.distro[R-1][C-1] != 0)
		{
			s.numPipes(R-1,C-1, 1, -1);
		}

		printf("\n \n Answer : %d \n", s.maxNumPipes);
	}
}