#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;

bool checkWordInDict(string s,vector<string>& wordDict)
{
	int i;

	for (i=0;i<wordDict.size();i++)
	{
		if (s==wordDict[i])
			return true;
	}

	return false;
}

void getWordFromTemp(int row,int col,int n,string s,int *temp,vector<string>& vstrg,stack<string>& stkstrg)
{
	int i,j,k,u,v,x,y,z; 

	string kstrg = "";
	string word;

	stack<string> stemp;

	if (row>n || col>n)
		return;

	// cout<<" temp matrix in the second function --> "<<endl;
	for (i=col;i<n;i++)
	{
		k = *((temp+row*n)+i);

		if (k==1)
		{
			if (i==(n-1))
			{
				kstrg = s.substr(col,i-col+1);

				while(!stkstrg.empty())
				{
					word = stkstrg.top();
					stkstrg.pop();
					stemp.push(word);
					kstrg = word + " " + kstrg;
				}
				// cout<<" kstring ---"<<kstrg<<endl;

				vstrg.push_back(kstrg);

				kstrg = "";

				while(!stemp.empty())
				{
					word = stemp.top();
					stemp.pop();
					stkstrg.push(word);
				}
			}
			else
			{
				j = i+1;
				u = *((temp+j*n)+(n-1));

				if (u==1 || u==2)
				{
					stkstrg.push(s.substr(col,i-col+1));
					getWordFromTemp(j,j,n,s,temp,vstrg,stkstrg);
					stkstrg.pop();
				}
		    }
		}
	}
}

vector<string> wordBreak(string s,vector<string>& wordDict)
{
	int i,j,k,u,v,x,y,z,len;

	if (s.size()==0)
		return {};

	int n = s.size();

	int temp[n][n];

	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			temp[i][j]=0;
	}

	for (len=1;len<=n;len++)
	{
		for (i=0;i<n-len+1;i++)
		{
			j=i+len-1;

			bool cond = checkWordInDict(s.substr(i,len),wordDict);

			if (cond==true)
			{
				temp[i][j] = 1;
			}
			else 
			{
				for (k=i;k<j;k++)
				{
					if ((temp[i][k]!=0) && (temp[k+1][j]!=0))
					{
						temp[i][j]=2;
						break;
					}
				}
			}
		}
	}

	// cout<<endl;
	// cout<<" temp matrix --> "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<n;j++)
	// 		cout<<temp[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	if (temp[0][n-1]==0)
		return {};
	else
	{
		// cout<<" case 2"<<endl;
		vector<string> vstrg;
		stack<string> stkstrg;

		getWordFromTemp(0,0,n,s,&temp[0][0],vstrg,stkstrg);

		// cout<<" size of vstrg --> "<<vstrg.size()<<endl;

		// for (i=0;i<vstrg.size();i++)
		// 	cout<<vstrg[i]<<endl;

		return vstrg;
	}
}

int main()
{
	cout<<" 140. Word Break II "<<endl;

	int i,j,k,u,v,x,y,z;

	// example 1
	string s = "catsanddog";
	vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};

	// example 2
	// string s = "pineapplepenapple";
	// vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};

	// example 3
	// string s = "catsandog";
	// vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

	cout<<" string s = "<<s<<endl;
	cout<<" words of the wordDict --> "<<endl;
	for (i=0;i<wordDict.size();i++)
		cout<<wordDict[i]<<endl;
	cout<<endl;

	vector<string> answer = wordBreak(s,wordDict);

	if (answer.size()==0)
		cout<<" no string possible ."<<endl;
	else
	{
		cout<<" Possible string ---> "<<endl;
		for (i=0;i<answer.size();i++)
			cout<<answer[i]<<endl;
	}
}