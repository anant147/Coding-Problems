#include<iostream>
using namespace std;

int color[1000];
bool edge[1000][1000];
int E,V;

class Queue
{
public:
	int num_elems,front,end;
	int arr[10000];

	Queue()
	{
		num_elems = 0;
		front = 0;
		end = 0;
		for (int i=0;i<10000;i++)
		{
			arr[i] = -1;
		}
	}

	bool isEmpty()
	{
		if (num_elems == 0)
			return true;
		else
			return false;
	}

	void enqueue(int x)
	{
		arr[end++] = x;
		num_elems++;
	}

	int dequeue()
	{
		if (num_elems == 0)
			return -1;
		else
		{
			num_elems--;
			return arr[front++];
		}
	}
};

void reset()
{
	for (int i=0;i<1000;i++)
	{
		for (int j=0;j<1000;j++)
			edge[i][j] = false;
		color[i] = -1;
	}
}

bool isBipart(int src)
{
	Queue q;

	color[src] = 0;
	q.enqueue(src);
	cout<<" hello "<<endl;

	while (!q.isEmpty())
	{
		int node = q.dequeue();

		if (edge[node][node] == true)
			return false;

		for (int i=0;i<V;i++)
		{
			if (edge[node][i] == true)
			{
				if (color[i] == -1)
				{
					color[i] = 1-color[node];
					q.enqueue(i);
				}
				else if (color[node] == color[i])
					return false;
			}
		}
	}

	return true;
}

int main()
{
	cout<<" Samsung 6"<<endl;
	cout<<" Find if given graph is bipartite or not, if it is bipartite then print either white color nodes or black color nodes. "<<endl;
	cout<<endl;

	reset();

	cin>>V>>E;

	for (int i=0;i<E;i++)
	{
		int x,y;
		cin>>x>>y;
		edge[x][y] = true;
	}

	int flag = 0;

	for (int i=0;i<V;i++)
	{
		if (color[i] == -1)
		{
			if (!isBipart(i))
			{
				flag = 1;
				cout<<" graph is not bipartite "<<endl;
				break;
			}
	    }
	}

	if (flag == 0)
	{
		cout<<" printing the color of the graph :- "<<endl;
		cout<<"for color 0, nodes are :"<<endl;
		for (int i=0;i<V;i++)
		{
			if (color[i]==0)
				cout<<i<<" ";
		}
		cout<<endl;
		cout<<endl;

		cout<<"for color 1, nodes are :-"<<endl;
		for (int i=0;i<V;i++)
		{
			if (color[i]==1)
				cout<<i<<" ";
		}
		cout<<endl;
	}



}