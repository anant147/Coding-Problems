#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;

vector<int> countBits(int num)
{
	int i,j;

	if (num == 0)
		return {0};
	else if (num == 1)
		return {0,1};

	vector<int> bitstor;
	bitstor.resize(num+1,0);

	bitstor[0] = 0;  bitstor[1] = 1;

	
	int maxval = pow(2,sizeof(int)*8-1)-1;

	int cond = 0;
	for (i=2;i<=num;)
	{
		for (j=0;j<i;j++)
		{
			bitstor[i+j] = 1 + bitstor[j];

			if ((i+j)==num)
			{
				cond=1;
				break;
			}
		}

		if (cond==1)
			break;

		i = i + j;
	}

	return bitstor;
}

int main()
{
	cout<<" 338. Counting Bits "<<endl;

	// example 1
	// int num = 2;

	// example 2
	int num = 5;

	vector<int> answer = countBits(num);

	cout<<" printing the answer vector :- "<<endl;
	for (int i=0;i<answer.size();i++)
		cout<<answer[i]<<" ";
	cout<<endl;
}