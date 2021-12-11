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

bool checkValidString(string s)
{
	int i,j,k,u,v,x,y,z;

	int n = s.size();

	int val1 = 0;
	int val2 = 0;
	int val3 = 0;

	int cond = 0;

	for (i=0;i<n;i++)
	{
		if (s[i]=='(')
			val1++;
		else if (s[i]=='*')
			val2++;
		else if (s[i]==')')
			val3++;
	}

	cout<<"val1 = "<<val1<<endl;
	cout<<"val2 = "<<val2<<endl;
	cout<<"val3 = "<<val3<<endl;

	if (val1>(val2+val3))
		return false;
	else if (val3>(val1+val2))
		return false;

	val1=0;
	val2=0;
	val3=0;

	for (i=0;i<n;i++)
	{
		if (s[i]=='(')
        {   
        	if (val1==0)
        		val2=0;
        	
			val1++;
        }
		else if (s[i]=='*')
			val2++;
		else if (s[i]==')')
		{
			if (val1 != 0)
				val1--;
			else if (val2 != 0)
				val2--;
			else if (val1==0 && val2==0)
				cond=1;
		}
        

		if (cond==1)
			break;
	}

	if (cond==1)
		return false;
	else
	{
		if (val1==0)
			return true;
		else
		{
			if (val1 > val2)
				return false;
			else
				return true;
		}
	}
}

int main()
{
	cout<<" 678. Valid Parenthesis String "<<endl;

	// example 1
	// string s = "()";

	// example 2
	// string s = "(*)";

	// example 3
	// string s = "(*))";

	// example 4
	string s = "(())(())(((()*()()()))()((()()(*()())))(((*)()";


	cout<<" s = "<<s<<endl;

	bool answer = checkValidString(s);

	if (answer)
		cout<<" given string is valid"<<endl;
	else
		cout<<" given string is not valid "<<endl;

}