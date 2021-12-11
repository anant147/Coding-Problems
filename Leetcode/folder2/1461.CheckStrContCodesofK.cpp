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

bool hasAllCodes(string s, int k)
{
	int i,j,u;

	int n = s.size();

	if (s=="0" || s=="1")
		return false;

	int count = pow(2,k);

	vector<int> numcheck;
	numcheck.resize(count,0);

	int totcnt = count;

	int clen = k;

	int val = 0;

	for (i=clen-1;i<n;i++)
	{
		if (i==clen-1)
		{
			val=0;

			for (j=0;j<clen;j++)
			{
				if (s[j]=='1')
					val = val + pow(2,j);
			}

			if (numcheck[val]==0)
			{
				numcheck[val]=1;
				totcnt--;
			}
		}
		else
		{
			val = val/2;

			if (s[i]=='1')
				val = val + pow(2,clen-1);

			if (numcheck[val]==0)
			{
				numcheck[val]=1;
				totcnt--;
			}
		}

		if (totcnt==0)
			break;
	}



	if (totcnt==0)
		return true;
	else
		return false;
}

int main()
{
	cout<<" 1461. Check If a String Contains All Binary Codes of Size K "<<endl;

	// example 1
	// string s = "00110110";
	// int k = 2;

	// // example 2
	// string s = "00110";
	// int k = 2;

	// // example 3
	// string s = "0110";
	// int k = 1;

	// // example 4
	// string s = "0110";
	// int k = 2;

	// // example 5
	// string s = "0000000001011100";
	// int k = 4;

	// example 6
	string s = "00000000001011100";
	int k = 3;

	cout<<" s = "<<s<<endl;
	cout<<" k = "<<k<<endl;

	bool answer = hasAllCodes(s,k);

	if (answer)
		cout<<" all codes can be hashed "<<endl;
	else
		cout<<" all codes cannot be hashed "<<endl;



}