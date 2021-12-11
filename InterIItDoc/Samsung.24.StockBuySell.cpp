#include<iostream>
using namespace std;

struct Interval
{
	int buy;
	int sell;
};

void stockBuySell(int price[], int n)
{
	if (n==1)
	{
		cout<<" no transaction can be done "<<endl;
		return;
	}

	int count = 0;
	Interval sol[n/2+1];

	int i=0;

	while (i<n-1)
	{
		while ((i<n-1) && (price[i+1] <=  price[i]))
			i++;

		if (i== n-1)
			break;

		sol[count].buy = i++;

		while ((i<n) && (price[i] >= price[i-1]))
			i++;

		sol[count].sell = i-1;

		count++;
	}

	if (count == 0)
	{
		cout<<" no transaction happen"<<endl;
		return;
	}
	else
	{
		cout<<endl;
		cout<<" transaction history :- "<<endl;
		for (int i=0;i<count;i++)
		{
			int u = sol[i].buy;
			int v = sol[i].sell;

			cout<<" buy day = "<<u<<" , sell day = "<<v<<" , cost at buy = "<<price[u]<<" , cost at sell = "<<price[v]<<" , Profit = "<<(price[v]-price[u])<<endl;
		}
	}
}

int main()
{
	cout<<" Samsung question 24 :- "<<endl;
	cout<<" Stock Buy Sell to Maximize Profit "<<endl;
	cout<<endl;

	int price[] = {100, 180, 260, 310, 40, 535,695};
	int n = sizeof(price)/sizeof(price[0]);

	cout<<" printint the price array :- "<<endl;
	for (int i=0;i<n;i++)
		cout<<price[i]<<" ";
	cout<<endl;

	cout<<endl;

	stockBuySell(price, n);

	cout<<endl;
}