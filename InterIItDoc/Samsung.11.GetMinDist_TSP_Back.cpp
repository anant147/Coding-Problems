#include<iostream>
using namespace std;

int d[12][12];
int x[12],y[12];
int visited[12];
int n;
int min_distance = 1e9;

int abs(int x)
{
	if (x>0)
		return x;
	else
		return -x;
}

void calculate(int source, int destination, int distance_so_far)
{
	distance_so_far = distance_so_far + d[source][destination];

	if (distance_so_far > min_distance)
	{
		// cout<<" case1"<<endl;
		return;
	}

	if (destination == n+1)
	{
		for (int i=0;i<=n+1;i++)
		{
			if (visited[i] == 0)
			{
				// cout<<" case 2"<<endl;
				return;
			}
		}

		if (distance_so_far < min_distance)
		{
			// cout<<" case 3"<<endl;
			min_distance = distance_so_far;
		}

		return;
	}

	for (int i=1;i<=n+1;i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			calculate(destination, i, distance_so_far);
			visited[i] = 0;
		}
	}
}

void preprocess_distacne()
{
	for (int i=0;i<n+2;i++)
	{
		for (int j=0;j<n+2;j++)
		{
			d[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
		}
	}
}

int main()
{
	cout<<" Samsung 11 and 15 question :- "<<endl;
	cout<<" Get minimum distance from office to all the custormer , and then to home of Kim "<<endl;
	cout<<" Variation of traveling salesman solved using backtracking (Optimization on traveling salesman ). "<<endl;
	cout<<endl;

	// question 15
	// A delivery boy wants to deliver some items on his way from office to home. You need to find the optimized path 
	// he should take from office to home and deliver all his deliveries on his way. It is 101 X 101 grid. Office, home
	 // , delivery points are represented via coordinated (x,y) where 0 <= x <= 100, 0 <= y <= 100. Distance between two points 
	// (x1, y1) and (x2,y2) is computed as |x1 – x2| + |y1 – y2| .You need to find the optimized path from office to home covering 
	// all delivery locations and return the optimized path length as output. You will be given the input in the 2 lines.

	// question 11
	// Mr. Kim has to deliver refrigerators to N customers. From the office, he is going to visit all the customers and then 
	// return to his home. Each location of the office, his home, and the customers is given in the form of integer coordinates 
	// (x,y) (0≤x≤100, 0≤y≤100) . The distance between two arbitrary locations (x1, y1) and (x2, y2) is computed by |x1-x2| +
	 // |y1-y2|, where |x| denotes the absolute value of x; for instance, |3|=|-3|=3. The locations of the office, his home, 
	// and the customers are all distinct. You should plan an optimal way to visit all the N customers and return to his among 
	// all the possibilities. You are given the locations of the office, Mr. Kim’s home, and the customers; the number of the customers
	// is in the range of 5 to 10. Write a program that, starting at the office, finds a (the) shortest path visiting all the customers 
	// and returning to his home. Your program only have to report the distance of a (the) shortest path. You don’t have to solve this
	 // problem efficiently. You could find an answer by looking up all the possible ways. If you can look up 
	// all the possibilities well, you will get a perfect score.




	int t;
	cin>>t;

	for (int i=1;i<=t;i++)
	{
		min_distance = 1e9;
		cin>>n;
		cin>>x[0]>>y[0];
		cin>>x[n+1]>>y[n+1];

		for (int j=1;j<=n;j++)
		{
			cin>>x[j]>>y[j];
			visited[j] = 0;
		}

		preprocess_distacne();
		visited[0] = 1;
		visited[n+1] = 0;

		calculate(0,0,0);

		cout<<"\n #"<<i<<" "<<min_distance<<endl;

	}
}