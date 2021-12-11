#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

// dp video 40
// weighted job scheduling problem - given n jobs with their profit,starting time and ending time , we have to find maximum profits from these jobs to get maximum profit
// time complexity - o(n*n)
// space complexty -  o(n)

bool sortbyet(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b)
{
	if (a.second.second < b.second.second)
		return true;
	else
		return false;
}

int weightedJobScheduling(vector<pair<int,pair<int,int>>> vjob)
{
	int i,j,k,u,v,x,y,answer;

	int n = vjob.size();

	int temp[n];
	int seq[n];

	sort(vjob.begin(),vjob.end(),sortbyet);

	cout<<" jobs in sorted order of ending time -"<<endl;
	for (i=0;i<vjob.size();i++)
		cout<<"for job no. "<<i<<" , profit = "<<vjob[i].first<<" , starting time = "<<vjob[i].second.first<<" , ending time = "<<vjob[i].second.second<<endl;

	cout<<endl;

	for(i=0;i<n;i++)
	{
		temp[i]=vjob[i].first;
		seq[i]=i;
	}

	for(i=1;i<n;i++)
	{
		x=vjob[i].first; // profit of job i
		y=vjob[i].second.first; // start time of job i

		for (j=0;j<i;j++)
		{
		  k=vjob[j].second.second; // end time of job j

          if ( temp[i]<(temp[j]+x) && (k<=y))
          {
          	temp[i] = temp[j]+x;
          	seq[i]=j;
          }
		}
	}

	// printing the temp array and seq array
	cout<<" print the temp array -- "<<endl;
	for(i=0;i<n;i++)
		cout<<temp[i]<<" ";
	cout<<endl;

	cout<<" print the seq array -- "<<endl;
	for(i=0;i<n;i++)
		cout<<seq[i]<<" ";
	cout<<endl;

	int maxval=0;
	int maxind=-1;

	for (i=0;i<n;i++)
	{
		if (temp[i]>maxval)
		{
			maxval=temp[i];
			maxind=i;
		}
	}

	x=maxind;
	vector<int> vseq;
    
    // tracking the job
	while(true)
	{
		vseq.push_back(x);

		if (x==seq[x])
			break;
		else
			x=seq[x];
	}

	cout<<" job in this maximum scheduling -- "<<endl;
	for(i=vseq.size()-1;i>=0;i--)
	{
		x=vseq[i];
		cout<<"job no. "<<x<<" with profit of "<<vjob[x].first<<endl;
	}
	cout<<endl;

	return maxval;
}

int main()
{
	int i,j,k;
	vector<pair<int,pair<int,int>>> vjob;

	vjob.push_back(make_pair(2,make_pair(7,9)));
	vjob.push_back(make_pair(11,make_pair(5,8)));
	vjob.push_back(make_pair(4,make_pair(6,7)));
	vjob.push_back(make_pair(5,make_pair(4,6)));
	vjob.push_back(make_pair(6,make_pair(2,5)));
	vjob.push_back(make_pair(5,make_pair(1,3)));

	cout<<" weighted job scheduling problem -- "<<endl;
	cout<<" number of jobs -- "<<vjob.size()<<endl;
	cout<<" jobs with their profit,starting and ending time -"<<endl;
	for (i=0;i<vjob.size();i++)
		cout<<"for job no. "<<i<<" , profit = "<<vjob[i].first<<" , starting time = "<<vjob[i].second.first<<" , ending time = "<<vjob[i].second.second<<endl;

	cout<<endl;

	int answer = weightedJobScheduling(vjob);

	cout<<" final answer = "<<answer<<endl;



}