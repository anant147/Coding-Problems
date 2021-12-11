#include <iostream>
#include <vector>
#include <map>
#include <utility> 
using namespace std;


// dynamic programming video 2
// 0/1 knapsack problem top down approach

int max(int a,int b)
{
	if (a < b)
		return b;
	else
		return a;
}

int recursiveKnapsack(int weight[],int value[],int size,int remainWt,int currentItem,map<pair<int,int>,int> temp)
{
	if (currentItem >= size || remainWt <= 0)
		return 0;

	int remainItem = size - currentItem-1;

	map<pair<int,int>,int> :: iterator it;

	it = temp.find(make_pair(remainWt,remainItem));

	if (it != temp.end())
		return it->second;

	int maxValue;

	if (remainWt < weight[currentItem])
	{
		maxValue = recursiveKnapsack(weight,value,size,remainWt,currentItem+1,temp);
	}
	else
	{
		maxValue = max(value[currentItem]+recursiveKnapsack(weight,value,size,remainWt-weight[currentItem],currentItem+1,temp),
			recursiveKnapsack(weight,value,size,remainWt,currentItem+1,temp));
	}

	temp[make_pair(remainWt,remainItem)]=maxValue;
	cout<<"key -- "<<remainWt<<" , "<<remainItem<<" ,, value - "<<maxValue<<endl;
	return maxValue;
}

int knapsackTopDown(int weight[],int value[],int size,int totalwt)
{
    map<pair<int,int>,int> temp;

    int currentItem = 0;
    int answer = recursiveKnapsack(weight,value,size,totalwt,currentItem,temp);

    map<pair<int,int>,int> :: iterator it;

    cout<<endl;


    cout<<"answer - "<<answer<<endl;

	return answer;
}

int main()
{
	int weight[4] = {2,2,4,5};
	int value[4] = {2,4,6,9};

	int size = 4;
	int totalwt = 8;

	int answer = knapsackTopDown(weight,value,size,totalwt);
	cout<<"answer - "<<answer<<endl;
}