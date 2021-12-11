#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int maxProfit(vector<int>& prices)
{
	return 0;
}

int main()
{
	cout<<" 309. Best Time to Buy and Sell Stock with Cooldown "<<endl;

	vector<int> prices = {1,2,3,0,2};
	int i;
	cout<<" price of the stock at ith day -- "<<endl;
	
	for (i=0;i<prices.size();i++)
		cout<<prices[i]<<" ";
	cout<<endl;

	int answer = maxProfit(prices);

	cout<<" answer = "<<answer<<endl;
}