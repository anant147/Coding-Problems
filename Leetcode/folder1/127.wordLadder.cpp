#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<utility>
#include<algorithm>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> wordList)
{
	int i,j,k,u,v,x,y,z;

	int n = endWord.size();

	if (n==0)
		return 0;

	if (beginWord == endWord)
		return 0;

	int cond = 0;

	sort(wordList.begin(), wordList.end());

	for (i=0;i<wordList.size();i++)
	{
		if (wordList[i] == endWord)
		{
			cond=1;
			break;
		}
	}

	if (cond == 0)
		return 0;

	int arr1[n];
	int cnt = 0;
	int totalWord = wordList.size();

	for (i=0;i<n;i++)
	{
		if (beginWord[i] == endWord[i])
			arr1[i] = 0;
		else
		{
			arr1[i] = 1;
			cnt++;
		}
	}

	if (cnt > totalWord)
	{
		cout<<" cond1 "<<endl;
		return 0;
	}

	int arr2[n];

	for (i=0;i<n;i++)
		arr2[i] = 0;

	for (i=0;i<totalWord;i++)
	{
		for (j=0;j<n;j++)
		{
			if (wordList[i][j] == endWord[j])
				arr2[j]++;
		}
	}

	int cond2 = 0;

	for (i=0;i<n;i++)
	{
		if (arr1[i]==1 && arr2[i]==0)
		{
			cond2 = 1;
			break;
		}
	}

	if (cond2 == 1)
	{
		cout<<" cond2 "<<endl;
		return 0;
	}

	cout<<" printing arr1 array --- "<<endl;
	for (i=0;i<n;i++)
		cout<<arr1[i]<<" ";
	cout<<endl;

	cout<<endl;
	cout<<" printing arr2 array --- "<<endl;
	for (i=0;i<n;i++)
		cout<<arr2[i]<<" ";
	cout<<endl;

	// cout<<" list of words we have in the function -- "<<endl;
	for (int i = 0;i<wordList.size();i++)
	{
		cout<<wordList[i]<<endl;
	}
	cout<<endl;

	queue<string> q1;

	for (i=0;i<totalWord;i++)
	{
		if (wordList[i] != beginWord)
			q1.push(wordList[i]);
	}

	int count = 0;
	int pos1 = -1;
	int pos2;
	int qlen1;
	int qlen2;

	string s1;
	string itstr;
	string temp;
	string input = beginWord;
	int cond3;
	int cond4 = 0;
	cout<<"queue size --- "<<q1.size()<<endl;

	for (i=0;i<n;i++)
		arr1[i] = 1;

	vector<string> vstrg;

	while (true)
	{
		k=0;
		qlen1 = q1.size();

		while (k != qlen1)
		{
			s1 = q1.front();
			cout<<" input = "<<input<<endl;
			cout<<" s1 = "<<s1<<endl;
			q1.pop();
			cond3 = 0;
			cout<<"queue size in loop--- "<<q1.size()<<endl;

			for (i=0;i<n;i++)
			{
				if (arr1[i] ==1)
				{
					if (i==0)
					{
						itstr = s1[i] + input.substr(1,n-1);
					}
					else if (i==n-1)
					{
						itstr = input.substr(0,n-1) + s1[i];
					}
					else
					{
						itstr = input.substr(0,i) + s1[i] + input.substr(i+1,n-i-1); 
					}

					if (itstr == s1)
					{
						cond3 = 1;
						pos2 = i;
						break;
					}
			    }
			}

			if (cond3 == 1)
			{
				cout<<" for cond3 , "<<s1<<endl;
				input = s1;
				if (pos1 != pos2)
				{
					pos1 = pos2;
					count++;
				}

				if (input[pos1] == endWord[pos1])
					arr1[pos1] = 0;

				break;
			}
			else
				q1.push(s1);

			if (input == endWord)
				break;

			k++;
		}
		cout<<endl;

		qlen2 = q1.size();

		cout<<endl;
		cout<<"input -- "<<input<<endl;
		cout<<" endWord -- "<<endWord<<endl;
		cout<<endl;

		if (input == endWord)
			break;

		if (qlen2 == qlen1 || q1.empty())
		{
			cond4 =1;
			break;
		}

		while(!q1.empty())
		{
			temp = q1.front();
			q1.pop();
			vstrg.push_back(temp);
		}

		sort(vstrg.begin(),vstrg.end());

		if (q1.empty())
		{
			for (i=0;i<vstrg.size();i++)
			{
				q1.push(vstrg[i]);
			}
			
			vstrg.clear();
		}
    }

    if (cond4==1)
    {
    	cout<<" cond3 "<<endl;
    	return 0;
    }
    else
    {
    	cout<<" cond4 "<<endl;
    	return (count + 1);
    }
}

int main()
{
    // example 1
	// string beginWord = "hit";
	// string endWord = "cog";
	// vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    // example 2
	// string beginWord = "hit";
	// string endWord = "cog";
	// vector<string> wordList = {"hot","dot","dog","lot","log"};

	// example 3
	// string beginWord = "hot";
	// string endWord = "dog";
	// vector<string> wordList = {"hot","dog","dot"};

	// example 4
	// string beginWord = "hot";
	// string endWord = "dog";
	// vector<string> wordList = {"hot","cog","dog","tot","hog","hop","pot","dot"};

	// example 5
	// string beginWord = "ymain";
	// string endWord = "oecij";
	// vector<string> wordList = {"ymann","yycrj","oecij","ymcnj","yzcrj","yycij","xecij","yecij","ymanj","yzcnj","ymain"};

	// example 6
	string beginWord = "teach";
	string endWord = "place";
	vector<string> wordList = {"peale","wilts","place","fetch","purer","pooch","peace","poach","berra","teach","rheum","peach"};

	cout<<" 127. Word Ladder "<<endl;
	cout<<" beging word -- "<<beginWord<<endl;
	cout<<" end word -- "<<endWord<<endl;
	cout<<" list of words we have -- "<<endl;
	for (int i = 0;i<wordList.size();i++)
		cout<<wordList[i]<<endl;
	cout<<endl;

	int result = ladderLength(beginWord, endWord, wordList);
	cout<<" result = "<<result<<endl;
}