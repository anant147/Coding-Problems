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

string findLongestWord(string s, vector<string>& d)
{
	int i,j,k,u,v,x,y,z;

	int n = d.size();

	if (n==0)
		return "";

	if (s.size()==0)
		return "";

	int len = 0;
	int index = -1;


	for (i=0;i<n;i++)
	{
		string temp = d[i];
		int slen = s.size();
		int tlen = temp.size();
		int count = 0;

		j=0;k=0;

		while (j<slen && k<tlen)
		{
			if (s[j]==temp[k])
			{
				j++; k++; count++;
			}
			else
			{
				j++;
			}
		}

        if (count == tlen)
        {
            if (len < count)
            {
                len = count;
                index = i;
            }
            else if (len == count && count!=0)
            {
                if (d[index] > d[i])
                    index = i;
            } 
        }
	}

	if (index==-1)
		return "";
	else
		return d[index];
}

int main()
{
	cout<<" 524. Longest Word in Dictionary through Deleting "<<endl;

	// example 1
	string s = "abpcplea";
	vector<string> d = {"ale","apple","monkey","plea"};

	// example 2
	// string s = "abpcplea";
	// vector<string> d = {"a","b","c"};

	cout<<" s = "<<s<<endl;
	cout<<" printing the d vector :- "<<endl;
	for (int i=0;i<d.size();i++)
		cout<<d[i]<<" ";
	cout<<endl;
	cout<<endl;

	string answer = findLongestWord(s,d);

	cout<<" answer = "<<answer<<endl;

}