#include<iostream>
using namespace std;

class Solution
{
public:

	int L[1000], R[1000], leaf[1000];
	int num_stalls, num_men;
	char stalls[50];

	Solution()
	{
		for (int i=0;i<1000;i++)
		{
			this->L[i] = -1;
			this->R[i] = -1;
			this->leaf[i] = -1;
		}

		for (int i=0;i<50;i++)
		{
			stalls[i] = '_';
		}

		this->num_stalls = 0;
		this->num_men = 0;
		this->leaf[0] = 0;
	}

	int candiate_node()
	{
		int idx = 0, maxDiff = -1;

		for (int i=0;i<50;i++)
		{
			if (this->leaf[i] != -1)
			{
				int diff = R[this->leaf[i]] - L[this->leaf[i]];

				if (diff > maxDiff)
				{
					idx = i;
					maxDiff = diff;
				}
			}
		}

		int result = this->leaf[idx];
		this->leaf[idx] = -1;
		cout<<endl;
		cout<<" in candiate_node function : "<<endl;
		cout<<" idx = "<<idx<<endl;
		cout<<" maxDiff = "<<maxDiff<<endl;
		cout<<" result = "<<result<<endl;
		cout<<endl;

		return result;
	}

	void split(int idx_to_split)
	{
		int left_idx = (2*idx_to_split) + 1;
		int right_idx = (2*idx_to_split) + 2;

		int mid = (this->L[idx_to_split] + this->R[idx_to_split])/2;

		this->L[left_idx] = this->L[idx_to_split];
		this->R[left_idx] = mid-1;

		this->L[right_idx] = mid+1;
		this->R[right_idx] = this->R[idx_to_split];

		cout<<endl;
		cout<<" in split fucntion :- "<<endl;
		cout<<" left_idx = "<<left_idx<<endl;
		cout<<" right_idx = "<<right_idx<<endl;
		cout<<" mid = "<<mid<<endl;
		cout<<" L[left_idx] = "<<this->L[left_idx]<<endl;
		cout<<" R[left_idx] = "<<this->R[left_idx]<<endl;
		cout<<" L[right_idx] = "<<this->L[right_idx]<<endl;
		cout<<" R[right_idx] = "<<this->R[right_idx]<<endl;
		cout<<endl;

		update_leaf( left_idx, right_idx);

		this->stalls[mid] = 'X';
	}

	void update_leaf(int x, int y)
	{
		for (int i=0;i<50;i++)
		{
			if (this->leaf[i] == -1)
			{
				this->leaf[i] = x;
				break;
			}
		}

		for (int i=0;i<50;i++)
		{
			if (this->leaf[i] == -1)
			{
				this->leaf[i] = y;
				break;
			}
		}
	}

	void print_stalls()
	{
		for (int i=0;i<this->num_stalls; i++)
		{
			cout<<this->stalls[i]<<" ";
		}
		cout<<endl;
	}

	int driver()
	{
		this->L[0] = 0;
		this->R[0] = this->num_stalls-1;

		for (int i=0; (i < this->num_men) && (i<this->num_stalls) ; i++)
		{
			int idx = candiate_node();

			cout<<endl;
			cout<<" in driver fucntion :- val of idx = "<<idx<<endl;
			cout<<endl;

			split(idx);
			print_stalls();
		}

		return 1;
	}
};

int main()
{
	cout<<" Samsung 37 question :- "<<endl;
	cout<<" Stall and Man "<<endl;
	cout<<endl;

	// Men's restroom problem : It is a well-researched fact that men
	 // in a restroom generally prefer to maximize their distance from 
	// already occupied stalls, by occupying the middle of the longest 
	// sequence of unoccupied places. For detailed version, check the 
	// following link.

	int T;
	cin>>T;

	while (T>0)
	{
		T--;
		int x,y;

		Solution obj;
		cin>>x>>y;

		obj.num_stalls = x;
		obj.num_men = y;

		cout<<"\n ******************************************************\n";
		obj.driver();
		cout<<"\n ******************************************************\n";
	}



}