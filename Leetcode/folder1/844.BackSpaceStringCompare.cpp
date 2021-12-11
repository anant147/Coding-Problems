#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;

bool backspaceCompare(string S, string T)
{
	int i,j,k,u,v,x,y,z;

	int n = S.size();
	int m = T.size();

	int p = n-1;
	int q = m-1;

	int cond=0;
	int cnt1=0;
	int cnt2=0;

	while ((p>=0) && (q>=0))
	{
		if (S[p]==T[q] && S[p]!='#')
		{
			p--;
			q--;
		}
		else if (S[p]=='#' || T[q]=='#')
		{

			if (S[p]=='#')
			{
				cnt1=0;

				while((p>=0) && S[p]=='#')
				{
					while((p>=0) && S[p]=='#')
					{
						p--;
						cnt1++;
					}

					if (p>=0)
					{
						while (cnt1!=0 && (p>=0))
						{
							if (S[p]!='#')
								cnt1--;
							else
								cnt1++;

							p--;
						}
				    }
		     	}
			}

			if (T[q]=='#')
			{
			    cnt2=0;

			    while((q>=0) && T[q]=='#')
			    {
				    while((q>=0) && T[q]=='#')
				    {
				    	q--;
				    	cnt2++;
				    }

				    if (q>=0)
				    {
				    	while(cnt2!=0 && (q>=0))
				    	{
				    		if (T[q]!='#')
				    			cnt2--;
				    		else
				    			cnt2++;

				    		q--;
				    	}
				    }
			    }
			}
		}
		else
			return false;


		if (p==-1 && q==-1)
			return true;
		else if (p==-1 || q==-1)
		{
			if (p==-1)
			{ 
				if (T[q]!='#')
					return false;
			}
			else if (q==-1)
			{
				if (S[p]!='#')
					return false;
			}
		}
	}

	return true;
}

int main()
{
	cout<<" 844. Backspace String Compare "<<endl;

	// example 1
	// string S = "ab##";
	// string T = "c#d#";

	// example 2
	string S ="nzp#o#g";
	string T = "b#nzp#o#g";

	cout<<" S = "<<S<<endl;
	cout<<" T = "<<T<<endl;

	bool answer = backspaceCompare(S,T);

	if (answer)
		cout<<" strings are comparable "<<endl;
	else
		cout<<" strings are not comparable "<<endl; 

}