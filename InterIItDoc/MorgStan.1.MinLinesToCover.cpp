#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if (a<b)
		return gcd(b,a);
	else if (b==0)
		return a;
	else
		return gcd(b, a%b);
}

pair<int,int> getReducedForm(int dy, int dx)
{
	int g = gcd(abs(dy), abs(dx));

	bool sign = (dy<0) ^ (dx<0);

	if (sign)
		return make_pair( -abs(dy)/g, abs(dx)/g);
	else
		return make_pair( abs(dy)/g, abs(dx)/g);
}

int minLinesToCoverPoints(int points[][2], int n, int x0, int y0)
{
	set<pair<int,int>> st;
	pair<int,int> temp;

	int minLines = 0;

	for (int i=0;i<n;i++)
	{
		int curX = points[i][0];
		int curY = points[i][1];

		temp = getReducedForm( curY - y0, curX - x0);

		if (st.find(temp) == st.end())
		{
			st.insert(temp);
			minLines++;
		}
	}

	return minLines;
}

int main()
{
	cout<<" Morgan Stanley 1"<<endl;
	cout<<" Minimum lines to cover all points "<<endl;
	cout<<endl;

	int x0, y0;
	x0 = 1;
	y0 = 0;

	cout<<" x0 = "<<x0<<" , y0 = "<<y0<<endl;

	int points[][2] = {
		              {-1,3},
		              {4,3},
		              {2,1},
		              {-1,-2},
		              {3,-3}
	                  };

	int n = sizeof(points) / sizeof(points[0]);
	cout<<" printing the points array "<<endl;
	for (int i=0;i<n;i++)
		cout<<points[i][0]<<" , "<<points[i][1]<<endl;
	cout<<endl;

	int answer = minLinesToCoverPoints(points, n, x0, y0);
	cout<<" Minimum no. of lines = "<<answer<<endl;
}