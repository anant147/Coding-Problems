#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon)
{
	int i,j,k,u,v,x,y,answer;

	int n = dungeon.size();

	if (n==0)
		return 0;

	int m = dungeon[0].size();

	if (m==0)
		return 0;

	int cond1 = 0;
	int cond2 = 0;
	int cond3 = 0;

	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (dungeon[i][j]<0)
				cond1=1;
			else if (dungeon[i][j]>0)
				cond2=1;
			else
				cond3=1;
		}
	}

	if (cond1==0 && cond2==0 && cond3==1)
		return 1;
	else if (cond1==0 && cond2==1 && cond3==0)
		return 1;

	int rcost[n][m];
	int negcost[n][m];

	rcost[0][0]=dungeon[0][0];

	if (dungeon[0][0]<=0)
		negcost[0][0]=dungeon[0][0];
	else
		negcost[0][0]=0;

	for (i=1;i<n;i++)
	{
		if (dungeon[i][0]<0)
			negcost[i][0]=negcost[i-1][0]+dungeon[i][0];
		else
			negcost[i][0]=negcost[i-1][0];

		rcost[i][0]=rcost[i-1][0]+dungeon[i][0];
	}

	for (i=1;i<m;i++)
	{
		if (dungeon[0][i]<0)
			negcost[0][i]=negcost[0][i-1]+dungeon[0][i];
		else
			negcost[0][i]=negcost[0][i-1];

		rcost[0][i]=rcost[0][i-1]+dungeon[0][i];
	}

	for (i=1;i<n;i++)
	{
		for (j=1;j<m;j++)
		{
			if (negcost[i-1][j]<negcost[i][j-1])
			{
				rcost[i][j]=rcost[i][j-1]+dungeon[i][j];

				if (dungeon[i][j]<0)
					negcost[i][j]=negcost[i][j-1]+dungeon[i][j];
				else
					negcost[i][j]=negcost[i][j-1];
			}
			else if (negcost[i-1][j]>negcost[i][j-1])
			{
				rcost[i][j] = rcost[i-1][j] + dungeon[i][j];

				if (dungeon[i][j] < 0)
					negcost[i][j] = negcost[i-1][j] + dungeon[i][j];
				else
					negcost[i][j] = negcost[i-1][j];
			}
			else
			{
				if (rcost[i-1][j] > rcost[i][j-1] )
					rcost[i][j] = rcost[i-1][j] + dungeon[i][j];
				else
					rcost[i][j] = rcost[i][j-1] + dungeon[i][j];

				if (dungeon[i][j]<0)
					negcost[i][j] = negcost[i-1][j] + dungeon[i][j];
				else
					negcost[i][j] = negcost[i-1][j];
			}
		}
	}

	// printing the rcost matrix 
	cout<<" printing the rcost matrix - "<<endl;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
			cout<<rcost[i][j]<<" ";
		cout<<endl;
	}

	// printing the negcost matrix 
	cout<<" printing the negcost matrix - "<<endl;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
			cout<<negcost[i][j]<<" ";
		cout<<endl;
	}

	vector<int> vhval;

	x=n-1;
	y=m-1;

	while(true)
	{
		vhval.push_back(dungeon[x][y]);

		if (x==0 && y==0)
			break;
		else
		{
			if (x==0)
				y=y-1;
			else if (y==0)
				x=x-1;
			else
			{
				if (negcost[x-1][y]>negcost[x][y-1])
					x=x-1;
				else if (negcost[x-1][y]<negcost[x][y-1])
					y=y-1;
				else
				{
					if (rcost[x-1][y]>rcost[x][y-1])
						x=x-1;
					else
						y=y-1;
				}
			}
		}
	}

	int minval = 0;
	int sum = 0;
    
    // printing element contributing to min health
    cout<<" printing element contributing to min health "<<endl;
	for (i=vhval.size()-1;i>=0;i--)
	{
		sum=sum+vhval[i];
		cout<<"for i = "<<vhval.size()-i<<" , val = "<<vhval[i]<<endl;

		if (sum<minval)
			minval=sum;
	}
	cout<<endl;

	answer = minval*(-1)+1;
	return answer;
}

int main()
{
	int i,j,k;

	// vector<vector<int>> dungeon = {{-2,-3,3},
	//                                {-5,-10,1},
	//                                {10,30,-5}};

	// vector<vector<int>> dungeon = {{0,0,0},
	//                                {1,1,-1}};

	vector<vector<int>> dungeon =  {{1,-3,3},{0,-2,0},{-3,-3,-3}};

    int n = dungeon.size();
    int m = dungeon[0].size();

    cout<<" dungeon game -- "<<endl;
    cout<<" n = "<<n<<endl;
    cout<<" m = "<<m<<endl;
    cout<<" elements of dungeon -- "<<endl;

    for (i=0;i<dungeon.size();i++)
    {
    for (j=0;j<dungeon[i].size();j++)
    	cout<<dungeon[i][j]<<" ";
    cout<<endl;
    }
    // cout<<endl;

    int answer = calculateMinimumHP(dungeon);

    cout<<" answer = "<<answer<<endl;	                               
}