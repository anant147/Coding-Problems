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

bool canIWin(int maxChoosableInteger, int desiredTotal)
{
	return 0;
}

int main()
{
	cout<<" 464. Can I Win "<<endl;

	// example 1
	int maxChoosableInteger = 10;
	int desiredTotal = 11;

	// example 2
	int maxChoosableInteger = 10;
	int desiredTotal = 1;

	// example 2
	int maxChoosableInteger = 10;
	int desiredTotal = 0;

	cout<<" maxChoosableInteger = "<<maxChoosableInteger<<endl;
	cout<<" desiredTotal = "<<desiredTotal<<endl;

	bool answer = canIWin(maxChoosableInteger, desiredTotal);

	if (answer)
		cout<<" i can win"<<endl;
	else
		cout<<" you can not win "<<endl;

}