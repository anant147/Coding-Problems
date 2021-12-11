#include<iostream>
#include<vector>
#include<cstring>
#include<utility>
#include<algorithm>
using namespace std;

bool checkCharInStr(string s1,string s2)
{
	int i,j,k,u,v;
	int a1[256]={0};
	int a2[256]={0};

	for (i=0;i<s1.length();i++)
	{
		k=(int)s1[i];
		a1[k]++;
	}

	for (i=0;i<s2.length();i++)
	{
		k=(int)s2[i];
		a2[k]++;
	}

	for (i=0;i<256;i++)
	{
		if (a1[i]!=a2[i])
			return false;
	}
	return true;
}

// int count = 0;

bool isScramble(string s1,string s2)
{
	int len1 = s1.length();
	int len2 = s2.length();

	if (len1!=len2)
	{
		// cout<<"case1"<<endl;
		// cout<<"s1 = "<<s1<<endl;
		// cout<<"s2 = "<<s2<<endl;
		// cout<<"false"<<endl;
		// cout<<endl;
		return false;

	}
	else if (s1.compare(s2)==0)
	{
		// cout<<"case2"<<endl;
		// cout<<"s1 = "<<s1<<endl;
		// cout<<"s2 = "<<s2<<endl;
		// cout<<"true"<<endl;
		// cout<<endl;
		return true;
	}
	else if (len1==1 && s1.compare(s2)!=0)
	{
		// cout<<"case3"<<endl;
		// cout<<"s1 = "<<s1<<endl;
		// cout<<"s2 = "<<s2<<endl;
		// cout<<"false"<<endl;
		// cout<<endl;
		return false;
	}
	else
	{
		bool val = checkCharInStr(s1,s2);
		// cout<<"case4"<<endl;
		// cout<<"s1 = "<<s1<<endl;
		// cout<<"s2 = "<<s2<<endl;
		int mid;

		if (val==true)
		{
			// int mid = len1/2;
			for (mid=1;mid<len1;mid++)
			{

				string s11 = s1.substr(0,mid);
				string s12 = s1.substr(mid,len1-mid);

				string s13 = s1.substr(0,len1-mid);
				string s14 = s1.substr(len1-mid,mid);

				string s21 = s2.substr(0,mid);
				string s22 = s2.substr(mid,len1-mid);

				string s23 = s2.substr(0,len1-mid);
				string s24 = s2.substr(len1-mid,mid);

				// cout<<"s11 = "<<s11<<endl;
				// cout<<"s12 = "<<s12<<endl;
				// cout<<"s13 = "<<s13<<endl;
				// cout<<"s14 = "<<s14<<endl;

				// cout<<"s21 = "<<s21<<endl;
				// cout<<"s22 = "<<s22<<endl;
				// cout<<"s23 = "<<s23<<endl;
				// cout<<"s24 = "<<s24<<endl;
				// cout<<endl;

				if (isScramble(s11,s21) && isScramble(s12,s22))
				{
					// cout<<"true 1"<<endl;
					return true;
				}
				else if (isScramble(s11,s24) && isScramble(s12,s23))
				{
					// cout<<"true 2"<<endl;
					return true;
				}
				else if (isScramble(s13,s23) && isScramble(s14,s24))
				{
					// cout<<"true 3"<<endl;
					return true;
				}
				else if (isScramble(s13,s22) && isScramble(s14,s21))
				{
					// cout<<"true 4"<<endl;
					return true;
				}
     		}

     		if (mid==len1)
     			return false;
		}

		// cout<<"false"<<endl;
		return false;
	}
}

int main()
{
	// string s1 = "great";
	// string s2 = "rgeat";

	// string s1 = "great";
	// string s2 = "rgtae";

	// string s1 = "abcde";
	// string s2 = "caebd";

	// string s1 = "abb";
	// string s2 = "bab";

	string s1 = "abab";
	string s2 = "aabb";

	cout<<" string scrambling -- "<<endl;
	cout<<" s1 = "<<s1<<endl;
	cout<<" s2 = "<<s2<<endl;

	cout<<endl;

	

	if (s1.length()==s2.length())
	{
		bool answer = isScramble(s1,s2);

		if (answer)
			cout<<" both strings can be scrambled "<<endl;
		else
			cout<<" both strings cannot be scrambled "<<endl;
	}
	else
	{
		cout<<" both strings have differnet length "<<endl;
	}

}