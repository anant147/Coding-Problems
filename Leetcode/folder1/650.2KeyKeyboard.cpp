#include<iostream>
#include<vector>
using namespace std;

int minSteps(int n)
{
	int i,j,k,u,v,answer;

	int temp[1001];

	if (n==0||n==1)
		return 0;

	for(i=0;i<1001;i++)
		temp[i]=0;

	u=n;

	for (i=2;i<1001;i++)
	{
		if (u%i==0)
		{
			while(u%i==0)
			{
				temp[i]++;
				u=u/i;
			}
		}
	}

	answer=0;

	for (i=2;i<1001;i++)
	{
		if(temp[i]!=0)
			answer=answer+(i*temp[i]);
	}
	return answer;
}

int main()
{
	int i,j;
	int n = 3;
	cout<<" 650. 2 Keys Keyboard problem -- "<<endl;
	cout<<" n = "<<n<<endl;
	int answer = minSteps(n);
	cout<<" answer = "<<answer<<endl;
}