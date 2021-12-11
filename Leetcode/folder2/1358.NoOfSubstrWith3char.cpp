#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<unordered_map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
using namespace std;

int numberOfSubstrings(string s)
{
	int i,j,k;

	int n = s.size();

	if (n<=2)
		return 0;

	// cout<<" n = "<<n<<endl;

	vector<vector<int>> astor;
	vector<int> temp;

	for (i=0;i<n;i++)
	{
		temp.resize(3,0);

		k = (int)(s[i])-97;

		temp[k]=1;

		if (i==0)
			astor.push_back(temp);
		else
		{
			for (j=0;j<3;j++)
				temp[j] = temp[j] + astor[i-1][j];

			astor.push_back(temp);
		}

		temp.clear();
	}

	// cout<<" printing the astor vector :- "<<endl;
	// for (i=0;i<astor.size();i++)
	// 	cout<<astor[i][0]<<" "<<astor[i][1]<<" "<<astor[i][2]<<endl;
	// cout<<endl;

	int sum = 0;

	int count = 0;
	int cond = 0;
	int mcond = 0;

	for (i=0;i<(n-2);)
	{
		cond = 0;
		j = i+2;

		if (i==0)
		{

			while (j<n)
			{
				// cout<<"hello1"<<endl;
				if (astor[j][0]>0 && astor[j][1]>0 && astor[j][2]>0)
				{
					cond=1;
					break;
				}
				else
					j++;
			}

			if (cond==1)
			{
				if ((j-i)==2)
				{
					sum = sum + (n-j);
					i = i+1;
				}
				else
				{
					k = j-2;

					mcond = 0;

					while (i<=k)
					{
						// cout<<"hello2"<<endl;
						if (k==0)
						{
							if (astor[j][0]>0 && astor[j][1]>0 && astor[j][2]>0)
								mcond=1;
						}
						else
						{
							if ((astor[j][0]-astor[k-1][0])>0 && (astor[j][1]-astor[k-1][1])>0 && (astor[j][2]-astor[k-1][2])>0 )
								mcond=1;
						}

						if (mcond==1)
							break;

						k--;
					}

					sum = sum + (k+1)*(n-j);

					i = k+1;
				}
			}
		}
		else
		{
			while (j<n)
			{
				// cout<<"hello3"<<endl;
				// cout<<"j = "<<j<<endl;
				if ((astor[j][0]-astor[i-1][0])>0 && (astor[j][1]-astor[i-1][1])>0 && (astor[j][2]-astor[i-1][2])>0)
				{
					cond=1;
					break;
				}
				else
					j++;
			}

			if (cond==1)
			{
				if ((j-i)==2)
				{
					sum = sum + (n-j);
					i = i+1;
				}
				else
				{
					k = j-2;
					mcond = 0;

					while (i<=k)
					{
						// cout<<"hello4"<<endl;
						if ((astor[j][0]-astor[k-1][0])>0 && (astor[j][1]-astor[k-1][1])>0 && (astor[j][2]-astor[k-1][2])>0 )
						{
							mcond = 1;
							break;
						}
						else
							k--;
					}

					sum = sum + (k-i+1)*(n-j);
					i = k+1;
				}
			}

		}

		if (j==n && cond==0)
			break;
	}

	// cout<<" printing the vtemp vectpr :-"<<endl;
	// for (i=0;i<vtemp.size();i++)
	// 	cout<<vtemp[i]<<" ";
	// cout<<endl;

	return sum;

}

int main()
{
	cout<<" 1358. Number of Substrings Containing All Three Characters "<<endl;

	// example1
	// string s = "abcabc";

	// example2
	// string s = "aaacb";

	// example3
	// string s = "abc";

	// example 4
	// string s = "ababbbc";

	// example 5
	string s = "acbbcac";

	cout<<" s = "<<s<<endl;

	int answer = numberOfSubstrings(s);

	cout<<" answer = "<<answer<<endl;


}