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

string intToRoman(int num)
{
	int i,j,k,u,v,x,y,z;

	vector<int> dval;
	dval.resize(4,0);

	k = num;
	i=0;

	while(k!=0 && i<4)
	{
		dval[i]=k%10;
		k=k/10;
		i++;
	}

	string answer = "";

	for (i=3;i>=0;i--)
	{
		k = dval[i];

		if (i==3)
		{
			if (k>=1 && k<=3)
			{
				j=0;
				while(j<k)
				{
					answer = answer + 'M';
					j++;
				}
			}
		}
		else if (i==2)
		{
			if (k>=1 && k<=3)
			{
				j=0;
				while (j<k)
				{
					answer = answer + 'C';
					j++;
				}
			}
			else if (k==4)
			{
				answer = answer + "CD";
			}
			else if (k==5)
			{
				answer = answer + 'D';
			}
			else if (k>=6 && k<=8)
			{
				answer = answer + 'D';

				k = k-5;
				j=0;

				while (j<k)
				{
					answer = answer + 'C';
					j++;
				}
			}
			else if (k==9)
			{
				answer = answer + "CM";
			}
		}
		else if (i==1)
		{
			if (k>=1 && k<=3)
			{
				j=0;

				while(j<k)
				{
					answer = answer + 'X';
					j++;
				}
			}
			else if (k==4)
			{
				answer = answer + "XL";
			}
			else if (k==5)
			{
				answer = answer + 'L';
			}
			else if (k>=6 && k<=8)
			{
				answer = answer + 'L';

				k = k-5;
				j=0;

				while (j<k)
				{
					answer = answer + 'X';
					j++;
				}
			}
			else if (k==9)
			{
				answer = answer + "XC";
			}
		}
		else if (i==0)
		{
			if (k>=1 && k<=3)
			{
				j=0;
				while(j<k)
				{
					answer = answer + 'I';
					j++;
				}
			}
			else if (k==4)
			{
				answer = answer + "IV";
			}
			else if (k==5)
			{
				answer = answer + 'V';
			}
			else if (k>=6 && k<=8)
			{
				answer = answer + 'V';

				k = k-5;
				j=0;
				while(j<k)
				{
					answer = answer + 'I';
					j++;
				}
			}
			else if (k==9)
			{
				answer = answer + "IX";
			}
		}
	}

	return answer;
}

int main()
{
	cout<<" 12. Integer to Roman "<<endl;

	// example 1
	// int num = 3;

	// example 2
	// int num = 4;

	// example 3
	// int num = 9;

	// example 4
	// int num = 58;

	// example 5
	int num = 1994;

	string answer = intToRoman(num);

	cout<<" answer = "<<answer<<endl;

}