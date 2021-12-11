#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
#include<algorithm>
using namespace std;

// median of two sorted array in o(logn) time

float medianOfTwoSortedVector(vector<int> v1,vector<int> v2)
{
	int i,j,k;
	int n = v1.size();
	int m = v2.size();

	if (m<n)
		return medianOfTwoSortedVector(v2,v1);

	int low,high,mid;
	int left1,right1;
	int left2,right2;
	int part1,part2;

	int maxValue = pow(2,sizeof(int)*8-1)-1;
	int minValue = (-1)*maxValue;

	low = 0;
	high = n;
	while (low <= high)
	{
		part1 = (low + high)/2;
		part2 = (n + m + 1)/2 - part1;

		left1 = (part1 == 0)?minValue:v1[part1-1];
		right1 = (part1 == n)?maxValue:v1[part1];

		left2 = (part2==0)?minValue:v2[part2-1];
		right2 = (part2 == m)?maxValue:v2[part2];

		if (left1 <= right2 && left2 <= right1)
		{
			if ((n+m)%2 == 0)
				{
                  return (float(max(left1,left2) + min(right1,right2))/2);
				}
				else
				{
                 return float(max(left1,left2));
				}
		}
		else if (left1 > right2)
			high = part1 -1;
		else
			low = part1 + 1;
	}
}

int main()
{
	// vector<int> v1 = {1, 3, 8, 9, 15};
	// vector<int> v2 = {7, 11, 18, 19, 21, 25};

	// vector<int> v1 = { 23, 26, 31, 35};
	// vector<int> v2 = {3,5,7,9,11,16};

	// vector<int> v1 = { 23, 26, 31, 35};
	// vector<int> v2 = {3,5,7,9,11,12,13,16};

	vector<int> v1 = {3,5,7,9,11,12,13,16};
	vector<int> v2 = { 23, 26, 31, 35};

	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	cout<<" Median of two sorted vector in logn time"<<endl;
	int n = v1.size();
	int m = v2.size();
	int i;

	cout<<" No. of elements in v1 vector -- "<<n<<endl;
	cout<<" elements in the v1 vector -- "<<endl;
	for (i=0;i<n;i++)
	  cout<<v1[i]<<" ";
	cout<<endl;
	cout<<endl;

	cout<<" No. of elements in v2 vector -- "<<m<<endl;
	cout<<" elements in the v2 vector -- "<<endl;
	for (i=0;i<m;i++)
	  cout<<v2[i]<<" ";
	cout<<endl;
	cout<<endl;

	float answer = medianOfTwoSortedVector(v1,v2);
	cout<<" median of given two vector -- "<<answer<<endl;
}