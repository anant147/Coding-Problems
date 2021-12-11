#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

bool sortvect(const vector<int>& v1,const vector<int>& v2)
{
	return (v1[0]<v2[0]);
	// if (v1[0]<v2[0] && v1[1]<v2[1])
	// 	return true;
	// else
	//    return false;
}

int maxEnvelopes(vector<vector<int>>& envelopes) 
{
	int i,j,k,u,v,x,y,answer;

	int n = envelopes.size();

	if (n==0)
		return 0;
	else if (n==1)
		return 1;

	int temp[n];

	for (i=0;i<n;i++)
		temp[i]=1;

	sort(envelopes.begin(),envelopes.end(),sortvect);

	cout<<" width and height of the envelopes --"<<endl;
	for (i=0;i<n;i++)
	{
	  cout<<"for i -- ( "<<envelopes[i][0]<<" , "<<envelopes[i][1]<<" ) "<<endl;	
	}

	for (i=1;i<n;i++)
	{
		for (j=0;j<i;j++)
		{
			k=1+temp[j];

			if (envelopes[j][0]<envelopes[i][0] && envelopes[j][1]<envelopes[i][1])
			{
				if (temp[i]<k)
					temp[i]=k;
			}
		}
	}

	int max=0;

	for (i=0;i<n;i++)
	{
		if (max<temp[i])
			max=temp[i];
	}

	cout<<" print the temp array -- "<<endl;
	for (i=0;i<n;i++)
		cout<<temp[i]<<" ";
	cout<<endl;

	return max;        
}

int main()
{
	int i,j,k;
	// vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};

	vector<vector<int>> envelopes = {{8,3},{3,20},{15,5},{11,2},{19,6},{9,18},{1,19},{13,3},{14,20},{6,7}};

	int n = envelopes.size();
	cout<<" 354. Russian Doll Envelopes "<<endl;
	cout<<" printing the sizes of the envelopes --  "<<endl;
	cout<<" size of vector -- "<<n<<endl;
	for (i=0;i<n;i++)
	{
	 cout<<"for i -- ( "<<envelopes[i][0]<<" , "<<envelopes[i][1]<<" ) "<<endl;
	}
	cout<<endl;

	int answer = maxEnvelopes(envelopes);
	cout<<" answer = "<<answer<<endl;
}