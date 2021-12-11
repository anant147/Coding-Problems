#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int longestArithSeqLengthSorted(vector<int>& A) // not for leetcode q
{
	int i,j,k,u,v,x,y,z;

	if (A.size() == 0)
		return 0;
	else if (A.size()==1)
		return 1;
	else if (A.size()==2)
		return 2;

	int n = A.size();

	sort(A.begin(),A.end());

	vector<int> elemDiff;

	int arr[10001];

	int elem[10001];

	for (i=0;i<10001;i++)
	{
		arr[i]=0;
		elem[i]=0;
	}

	for (i=0;i<n;i++)
	{
		elem[A[i]] = i+1;
	}

	for (i=1;i<n;i++)
	{
		for (j=0;j<i;j++)
		{
			u = A[i] - A[j];

			if (arr[u] == 0)
			{
				elemDiff.push_back(u);
				arr[u]=1;
			}
		}
	}

	int cnt=0;
	int maxcnt = 0;
	int cond=0;

	for (i=0;i<elemDiff.size();i++)
	{
		u = elemDiff[i];
		cnt = 0;
		cond = 0;
		k = -1;

		for (j=0;j<n-1;)
		{
			v = A[j] + u;

			if (elem[v] != 0)
			{
				if (cond == 0)
				{
					k = j+1;
					cond=1;
					cnt=2;
				}
				else
					cnt++;

				j = elem[v]-1;
				if (u==5)
				{
					cout<<endl;
					cout<<" for u = 5 , v = "<<v<<endl;
					cout<<" for pos -- j = "<<j<<endl;
					cout<<endl;
	
				}
			
				// cout<<" for pos -- j = "<<j<<endl;
			}
			else
			{
				if (k == -1)
					j=j+1;
				else
				{
					j = k;
					k = -1;
				}

				if (u==5)
				{
					cout<<endl;
					cout<<" for neg -- j = "<<j<<endl;
					cout<<endl;
				}

				if (cond==1)
				{
					cond=0;
					cnt=0;
				}
			}

			if (maxcnt < cnt)
				maxcnt = cnt;
		}
	}

	cout<<" sorted vector -- "<<endl;
	for (i=0;i<n;i++)    
		cout<<A[i]<<" ";
	cout<<endl;
	cout<<endl;

	cout<<" diff in sorted array -- "<<endl;
	for (i=0;i<elemDiff.size();i++)
		cout<<elemDiff[i]<<" ";
	cout<<endl;

	return maxcnt;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int binarySearchPos(vector<int> pElem[],int index,int val)
{
	int high,low,mid;

	int n = pElem[index].size();

	if (pElem[index][n-1]<=val)
		return -1;

	if (pElem[index][0] > val)
		return pElem[index][0];

	low = 0;
	high = n-1;

	while(low <= high)
	{
		mid = (low + high)/2;

		if ( (pElem[index][mid] < val) && (pElem[index][mid+1] > val) && ((mid+1)<=(n-1)) )
			return (mid+1);
		else if (pElem[index][mid] < val)
			low = mid+1;
		else if (pElem[index][mid] > val)
			high = mid-1;
	}

	return -1;
}

int binarySearchNeg(vector<int> nElem[],int index,int val)
{
	int high,low,mid;

	int n = nElem[index].size();

	if (nElem[index][n-1]<=val)
		return -1;

	if (nElem[index][0] > val)
		return nElem[index][0];

	low = 0;
	high = n-1;

	while(low <= high)
	{
		mid = (low + high)/2;

		if ( (nElem[index][mid] < val) && (nElem[index][mid+1] > val) && ((mid+1)<=(n-1)) )
			return (mid+1);
		else if (nElem[index][mid] < val)
			low = mid+1;
		else if (nElem[index][mid] > val)
			high = mid-1;
	}

	return -1;
}

int longestArithSeqLength(vector<int>& A)
{
	int i,j,k,u,v,x,y,z;

	if (A.size() == 0)
		return 0;
	else if (A.size()==1)
		return 1;
	else if (A.size()==2)
		return 2;

	int n = A.size();

	int posElem[10001],posDiff[10001],negElem[10001],negDiff[10001];

	vector<int> pElem[10001];
	vector<int> nElem[10001];
	vector<int> diffOfElem;

	for (i=0;i<10001;i++)
	{
		posElem[i] = 0;
		posDiff[i] = 0;
		negElem[i] = 0;
		negDiff[i] = 0;
	}

	for (i=0;i<n;i++)
	{
		if (A[i] >= 0)
		{
			if (posElem[A[i]] == 0)
			{
				posElem[A[i]] =1;
				pElem[A[i]].push_back(i);
			}
			else
			{
				pElem[A[i]].push_back(i);
			}
		}
		else
		{
			u = (-1)*A[i];

			if (negElem[u] == 0)
			{
				negElem[u] =1;
				nElem[u].push_back(i);
			}
			else
			{
				nElem[u].push_back(i);
			}
		}
	}

	for (i=1;i<n;i++)
	{
		for (j=0;j<i;j++)
		{
			u = A[i]-A[j];

			if (u >= 0)
			{
				if (posDiff[u] == 0)
				{
					diffOfElem.push_back(u);
					posDiff[u]=1;
				}
			}
			else
			{
				v = u * (-1);

				if (negDiff[v] == 0)
				{
					diffOfElem.push_back(u);
					negDiff[v]=1;
				}
			}
		}
	}

	int nextIndex;

	int maxcnt = 0;
	int cond = 0;
	int cnt = 0;

	for (i=0;i<diffOfElem.size();i++)
	{
		u = diffOfElem[i];
		cnt = 0;
		cond = 0;
		k = -1;

		for (j=0;j<(n-1);)
		{
			v = A[j] + u;

			if (v >= 0)
			{
				if (posElem[v] == 1)
				{
					nextIndex = binarySearchPos(pElem,v,j);

					if (nextIndex == -1)
					{
						j = j+1;
						cond = 0;
						cnt = 0;
					}
					else
					{
						if (cond == 0)
						{
							k = j+1;
							cond=1;
							cnt=2;
						}
						else
							cnt++;

						j = nextIndex;
					}
				}
				else
				{
					cond = 0;
					cnt = 0;

					if (k == -1)
					{
						j = j+1;
					}
					else
					{
						j = k;
						k=-1;
					}
				}
			}
			else
			{
				x = v*(-1);

				if (negElem[x] == 1)
				{
					nextIndex = binarySearchNeg(nElem,x,j);

					if (nextIndex == -1)
					{
						j = j+1;
						cond = 0;
						cnt = 0;
					}
					else
					{
						if (cond == 0)
						{
							k = j+1;
							cond = 1;
							cnt = 2;
						}
						else
							cnt++;

						j = nextIndex;
					}
				}
				else
				{
					cond = 0;
					cnt = 0;

					if (k == -1)
					{
						j = j+1;
					}
					else
					{
						j = k;
						k = -1;
					}
				}
			}

			if (maxcnt < cnt)
				maxcnt = cnt;
		}

	}

	// cout<<" diff vector --- "<<endl;
	// for (i=0;i<diffOfElem.size();i++)
	// 	cout<<diffOfElem[i]<<" ";
	// cout<<endl;


	return maxcnt;	
} 

int main()
{
	// vector<int> A = {3,6,9,12};
	vector<int> A = {9,4,7,2,10};
	// vector<int> A = {20,1,15,3,10,5,8};

	int n = A.size();

	cout<<" 1027. Longest Arithmetic Sequence "<<endl;
	cout<<" size of vector -- "<<n<<endl;
	cout<<" elements of the vector -- "<<endl;
	for (int i=0;i<n;i++)
	  cout<<A[i]<<" ";
	cout<<endl;
	cout<<endl;
	// cout<<" for type 1 "<<endl;
	// cout<<endl;

	// int answer1 = longestArithSeqLengthSorted(A);  // not for leetcode question
	// cout<<" answer for sorted -- "<<answer1<<endl;
	// cout<<endl;

	cout<<" for type 2 "<<endl;
	cout<<endl;
	int answer2 = longestArithSeqLength(A);
	cout<<" correct answer = "<<answer2<<endl; 
}