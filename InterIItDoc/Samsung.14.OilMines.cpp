#include<iostream>
using namespace std;
#define lim 50

int N,M;
int oilMines[2*lim];
int DP_max[lim][lim][lim];
int DP_min[lim][lim][lim];
int verbose = 0;

void debug()
{
	cout<<" \n oil mines : "<<endl;
	for (int i=0;i<M;i++)
	{
		cout<<oilMines[i]<<" ";
	}
	cout<<endl;

	for (int x = 0;x<=N;x++)
	{
		cout<<" \n dp max for no. of partitions = "<<x<<endl;

		for (int i=0;i<M;i++)
		{
			for (int j=0;j<M;j++)
			{
				if (DP_max[i][j][x] == -1)
					cout<<"N ";
				else
					cout<<DP_max[i][j][x]<<" ";
			}
			cout<<endl;
		}

		cout<<" \n dp min for no. of partitions = "<<x<<endl;

		for (int i=0;i<M;i++)
		{
			for (int j=0;j<M;j++)
			{
				if (DP_min[i][j][x] == -1)
					cout<<"N ";
				else
					cout<<DP_min[i][j][x]<<" ";
			}
			cout<<endl;
		}
	}
}

void DP()
{
	// Always j>=num_part
	// j => length of array starting from i 0<=j<=M

	for (int i=0;i<M;i++)
	{
		for (int num_part=1;num_part<=N;num_part++)
		{
			DP_max[i][i][num_part] = oilMines[i];
			DP_min[i][i][num_part] = oilMines[i];
		}
	}

	for (int i=0;i<M;i++)
	{
		for (int j=i+1;j<M;j++)
		{
			int sum = 0;

			for (int x=i;x<=j;x++)
				sum += oilMines[x];

			DP_max[i][j][1] = sum;
			DP_min[i][j][1] = sum;
		}
	}


	for (int num_part = 2; num_part <= N; num_part++)
	{
		for (int i=0;i<M;i++)
		{
			for (int j=i+1;j<M;j++)
			{
				int num_elems = j-i+1;

				if (num_elems < num_part)
					continue;

				int absMax = -1, absMin = 999999, minDiff = 999999;

				if (verbose)
				{
					cout<<" \n For num_part = "<<num_part<<" i = "<<i<<" j = "<<j<<endl;
				}

				for (int x=1;x <= num_elems-num_part+1; x++)
				{
					int start_ind = i;
					int end_ind = i+x-1;

					int maxV = max( DP_max[end_ind+1][j][ num_part-1], DP_max[i][end_ind][1] );
					int minV = min( DP_min[end_ind+1][j][ num_part-1], DP_min[i][end_ind][1] );

					int diff = maxV - minV;

					if (verbose)
					{
						cout<<" \n for x = "<<x<<endl;
						cout<<"  start_ind = "<<start_ind<<" , end_ind = "<<end_ind<<" , maxV = "<<maxV<<" , minV = "<<minV<<" , diff = "<<diff<<endl;
					}

					if (diff < minDiff)
					{
						minDiff = diff;
						absMax = maxV;
						absMin = minV;

						if (verbose)
							cout<<" minDiff = "<<minDiff<<" , absMax = "<<absMax<<" , absMin = "<<absMin<<endl;

					}
				}

				if (verbose)
					cout<<" \n updated DP_max and DP_min for i, j, num_part = "<<i<<" , "<<j<<" , "<<num_part<<" to : "<<absMax<<" , "<<absMin<<endl;

				DP_max[i][j][num_part] = absMax;
				DP_min[i][j][num_part] = absMin;
			}
		}
	}

	if (verbose)
		debug();

	return;
}

int main()
{
	cout<<" Samsung question 14"<<endl;
	cout<<" Allocate oil mines to companies "<<endl;

	// There is an island surrounded by oil mines. You will be 
	// given n companies and m oil mines having values. You have
	// to distribute the mines to “n” companies in a fair manner. 
	// Remember the companies can have oil mines adjacent to each 
	// other but not in between of each other. After distributing 
	// them compute the difference of oil mines from the company 
	// getting highest and company getting lowest. This number 
	// should be minimum.(then only the distribution can be termed 
	// as fair).

	int t;
	cin>>t;

	int ctr = 1;
	while (t>0)
	{
		t--;
		cin>>N>>M;

		for (int i=0;i<M;i++)
		{
			int x;
			cin>>x;
			oilMines[i] = x;
			oilMines[M+i] = x;
		}

		M*=2;

		for (int i=0;i<M;i++)
		{
			for (int j=0;j<M;j++)
			{
				for (int k=1;k<M;k++)
				{
					DP_max[i][j][k] = -1;
					DP_min[i][j][k] = 999999;
				}
			}
		}

		DP();

		// debug();

		int minDiff = 999999;
		M/=2;

		for (int i=0;i<M;i++)
		{
			int diff = DP_max[i][M+i-1][N] - DP_min[i][M+i-1][N];

			if (diff < minDiff)
				minDiff = diff;
		}

		cout<<"#"<<ctr<<" "<<minDiff<<endl;

		ctr += 1;
	}
}