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

vector<string> getInput(string input)
{
	vector<string> result;
	string word = "";

	int i,j,k;

	int n = input.size();

	for (i=0;i<n;i++)
	{
		if (input[i]==' ')
		{
			if (word != "")
			{
				result.push_back(word);
				word = "";
			}
		}
		else
			word.push_back(input[i]);
	}

	if (word != "")
		result.push_back(word);

	return result;
}

// get integer list
vector<int> getIntlist(vector<string>& intlist, int index)
{
	vector<int> temp;
	int i,j,k;
	int n = intlist.size();

	for (i=index;i<n;i++)
	{
		k = stoi(intlist[i]);
		temp.push_back(k);
	}

	int cond = 0;

	for (i=0;i<temp.size();i++)
	{
		if (temp[i]<=0)
		{
			cond = 1;
			break;
		}
	}

	if (cond==1)
	{
		// cout<<" failure 0"<<endl;
		return {-1};
	}
	else
		return temp;
}

// add screen 
vector<vector<int>> addScreen(vector<int>& intlist)
{
	int n = intlist[0];
	int m = intlist[1];

	int i,j,k,u,v,x,y,z;

	vector<vector<int>> screen;
	screen.resize(n+1, vector<int> (m+1,0));

	if (intlist.size()==2)
		return screen;

	for (i=1;i<=n;i++)
	{
		for (j=2;j<intlist.size();j++)
		{
			k = intlist[j];
			screen[i][k] = 1;
		}
	}

	return screen;
}

// reserving seats
int reseveeSeats(vector<vector<vector<int>>>& scrtor, int sno, vector<int>& intlist)
{
	int rno = intlist[0];

	int i,j,k,u,v;

	int cond = 0;

	for (i=1;i<intlist.size();i++)
	{
		k = intlist[i];

		if (scrtor[sno][rno][k]==2)
		{
			cond=1;
			break;
		}
	}

	if (cond==1)
		return 0;

	for (i=1;i<intlist.size();i++)
	{
		k = intlist[i];
		scrtor[sno][rno][k] = 2;
	}

	return 1;
}

// get unreserved seats
vector<int> getUnreservedSeats(vector<vector<vector<int>>>& scrtor, int sno, vector<int>& intlist)
{
	int rno = intlist[0];

	vector<int> seat;

	int i,j,k;

	for (i=1;i<scrtor[sno][rno].size();i++)
	{
		if (scrtor[sno][rno][i] != 2)
			seat.push_back(i);
	}

	return seat;
}

// suggest contiguous seats 
vector<int> suggestContiguousSeats(vector<vector<vector<int>>>& scrtor, int sno, vector<int>& intlist)
{
	int nos = intlist[0];
	int rno = intlist[1];
	int cosno = intlist[2];

	int i,j,k,u,v,x,y,z;

	int vlen = scrtor[sno][rno].size();

	int cond1=0;
	int cond2=0;
	int count1=0;
	int count2=0;

	vector<int> seat;

	i = cosno;

	while(i>=1 && cond1==0)
	{
		if (scrtor[sno][rno][i] != 2 && i==cosno)
			count1++;
		else if (scrtor[sno][rno][i] == 0)
			count1++;
		else
		{
			cond1=1; break;
		}

		if (count1==nos)
			break;

		i--;
	}

	if (cond1==0 && count1==nos)
	{
		i = cosno;
		while (count1!=0)
		{
			seat.push_back(i);
			i--;
			count1--;
		}

		sort(seat.begin(),seat.end());

		return seat;
	}

	i = cosno;

	while(i<vlen && cond2==0)
	{
		if (scrtor[sno][rno][i] != 2 && i==cosno)
			count2++;
		else if (scrtor[sno][rno][i]==0)
			count2++;
		else
		{
			cond2=1; break;
		}

		if (count2==nos)
			break;

		i++;
	}

	if (cond2==0 && count2==nos)
	{
		i=cosno;
		while(count2!=0)
		{
			seat.push_back(i);
			i++;
			count2--;
		}

		return seat;
	}

	return {-1};
}

int main()
{
	cout<<" Udaan - Movie Ticket System :- "<<endl;

	int n = 9;
	int i,j,k,u,v;
	vector<string> inputs = {"add-screen Screen1 12 10 4 5 8 9",
                             "add-screen Screen2 20 25 3 4 12 13 17 18",
                             "reserve-seat Screen1 4 5 6 7",
                             "reserve-seat Screen2 13 6 7 8 9 10",
                             "reserve-seat Screen2 13 4 5 6",
                             "get-unreserved-seats Screen2 13",
                             "suggest-contiguous-seats Screen1 3 3 4",
                             "suggest-contiguous-seats Screen2 4 12 4",
                             "suggest-contiguous-seats Screen2 4 10 3"};

    unordered_map<string,int> mp;
    vector<vector<vector<int>>> scrtor;
    vector<vector<int>> vtemp;

    string cname;
    string sname;
    int sno;

    vector<int> seat;
    vector<int> intlist;
    vector<string> inpword;

    cout<<" n = "<<n<<endl;

    int count = 0;

    for (i=0;i<n;i++)
    {
    	cout<<" command = "<<inputs[i]<<endl;

    	inpword = getInput(inputs[i]);
    	cname = inpword[0];
    	sname = inpword[1];

    	if (cname=="add-screen")
    	{
    		cout<<" case 1"<<endl;
    		if (mp.find(sname) == mp.end())
    		{
    			intlist = getIntlist(inpword,2);

    			if (intlist[0]==-1 || intlist.size()<2)
    				cout<<"failure 1"<<endl;
    			else
    			{
    				mp[sname] = count;
    				count++;
    				vtemp = addScreen(intlist);
    				scrtor.push_back(vtemp);
    				u = scrtor.size();
    				cout<<"u = "<<u<<endl;
    				cout<<"success"<<endl;
    			}
    		}
    		else
    		{
    			cout<<"failure 2"<<endl;
    		}
    	}
    	else if (cname=="reserve-seat")
    	{
    		cout<<" case 2"<<endl;

    		if (mp.find(sname) != mp.end())
    		{
    			intlist = getIntlist(inpword,2);

    			if (intlist[0]==-1)
    				cout<<"failure"<<endl;
    			else
    			{
    				sno = mp[sname];
    				u = reseveeSeats(scrtor,sno,intlist);

    				if (u==0)
    					cout<<"failure"<<endl;
    				else
    					cout<<"success"<<endl;
    			}
    		}
    		else
    		{
    			cout<<"failure"<<endl;
    		}
    	}
    	else if (cname=="get-unreserved-seats")
    	{
    		cout<<" case 3"<<endl;

    		if (mp.find(sname) != mp.end())
    		{
    			intlist = getIntlist(inpword,2);

    			if (intlist[0]==-1)
    				cout<<"failure"<<endl;
    			else
    			{
    				sno = mp[sname];
    				seat = getUnreservedSeats(scrtor,sno,intlist);

    				for(j=0;j<seat.size();j++)
    					cout<<seat[j]<<" ";
    				cout<<endl;
    			}
    		}
    		else
    		{
    			cout<<"failure"<<endl;
    		}
    	}
    	else if (cname=="suggest-contiguous-seats")
    	{
    		cout<<" case 4"<<endl;

    		if (mp.find(sname) != mp.end())
    		{
    			intlist = getIntlist(inpword,2);

    			if (intlist[0]==-1)
    				cout<<"failure"<<endl;
    			else
    			{
    				sno = mp[sname];
    				seat = suggestContiguousSeats(scrtor, sno, intlist);

    				if (seat[0]==-1)
    					cout<<"None"<<endl;
    				else
    				{
    					for (j=0;j<seat.size();j++)
    						cout<<seat[j]<<" ";
    					cout<<endl;
    				}
    			}
    		}
    		else
    		{
    			cout<<"failure"<<endl;
    		}
    	}

    	cout<<endl;

    }

}

// export http_proxy="http://proxy62.iitd.ac.in:3128"