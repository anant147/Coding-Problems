#include<iostream>
using namespace std;

#define lim 100
int overflow_numbers[lim];
int k;
int num_pots;

void merger(int l, int m, int r)
{
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;

	int L[n1],R[n2];

	for (int i=0;i<n1;i++)
		L[i] = overflow_numbers[l+i];

	for (int j=0;j<n2;j++)
		R[j] = overflow_numbers[m+1+j];

	i = 0;
	j = 0;
	k = l;

	while (i<n1 && j<n2)
	{
		if (L[i] <= R[j])
		{
			overflow_numbers[k] = L[i];
			i++;
		}
		else
		{
			overflow_numbers[k] = R[j];
			j++;
		}

		k++;
	}

	while (i<n1)
	{
		overflow_numbers[k] = L[i];
		k++;
		i++;
	}

	while (j<n2)
	{
		overflow_numbers[k] = R[j];
		k++;
		j++;
	}
}

void merge_sort(int l, int r)
{
	if (l<r)
	{
		int m = l+(r-l)/2;
		merge_sort(l,m);
		merge_sort(m+1,r);
		merger(l,m,r);
	}
}

int main()
{
    cout<<" Samsung 16 question "<<endl;
    cout<<" Thirsty crow question "<<endl;
    // There are N pots. Every pot has some water in it. They may be
     // partially filled. Every pot is associated with overflow number 
      // which tell how many minimum no. of stones required for that 
    // pot to overflow. The crow knows O1 to On(overflow no. for all the 
    // ots). Crow wants some K pots to be overflow. So the task is the
     // minimum number of stones he can make K pots overflow in the worst
      // case.




	cin>>num_pots;

	for (int i=0;i<num_pots;i++)
	{
		int x;
		cin>>x;
		overflow_numbers[i] = x;
	}

	cin>>k;
	merge_sort(0, num_pots-1);

	for (int i=num_pots-1; i>0; i--)
	{
		overflow_numbers[i] = max(0, overflow_numbers[i] - overflow_numbers[i-1]);
	}

	int total_stones = 0;

	for (int i=0;i<k;i++)
		total_stones += (overflow_numbers[i])*(num_pots-i);

	cout<<" \n total stones required :- "<<total_stones<<endl;
}