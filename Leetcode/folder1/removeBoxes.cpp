#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int removeBoxes(vector<int>& boxes)
{
	int i,j,k,u,v,x,y,p,q,m,answer,r,s,len,cnt,sum,total,val1,val2;

	int n = boxes.size();

	if (n==0)
		return 0;
	else if (n==1)
		return 1;
	else if (n==2)
	{
		if (boxes[0]==boxes[1])
			return 4;
		else
			return 2;
	}

	int temp[n][n];

	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (i==j)
				temp[i][j]=1;
			else
				temp[i][j]=0;
		}
	}

	for (len=2;len<=n;len++)
	{
		for (i=0;i<(n-len+1);i++)
		{
			j=i+len-1;

			if(len==2)
			{
				if (boxes[i]==boxes[j])
					temp[i][j]=4;
				else
					temp[i][j]=2;
			}
			else
			{
				if (boxes[i]==boxes[j])
				{
					vector<pair<int,int>> cord;
					cnt=0;
					r=boxes[i];
					u=i;
					v=i-1;

					for (x=i;x<=j;x++)
					{
						if (x==j)
						{
							cord.push_back(make_pair(u,j));
							cnt++;
						}
						else if (boxes[x]==r)
						{
							v++;
							cnt++;
						}
						else if (boxes[x]!=r)
						{
							if (boxes[x-1]==r)
							{
								cord.push_back(make_pair(u,v));
								u=x+1;
								v=x;
							}
							else
							{
								u=x+1;
								v=x;
							}
						}
					}

					if (cnt==2)
						temp[i][j]=temp[i+1][j-1]+4;
					else if (cnt==len)
						temp[i][j]=len*len;
					else if (cord.size()==2)
					{
						int p1=cord[0].first;
						int q1=cord[0].second;
						int y1=q1-p1+1;

						int p2=cord[1].first;
						int q2=cord[1].second;
						int y2=q2-p2+1;

						int cnt1=y1+y2;
						val1 = temp[q1+1][p2-1] + (cnt1*cnt1);
						temp[i][j]=val1;
					}
					else if ( (len%2==0 && cnt>(len/2)) || (len%2==1 && cnt>=(len/2+1)) ) 
					{

						sum=0;

                		u=i+1;
                		v=i;

                		for (x=i+1;x<=j;x++)
                		{
                			if (r!=boxes[x])
                				v++;
                			else
                			{
                				if (boxes[x-1]!=r)
                				{
                                 sum=sum+temp[u][v];
                                 u=x+1;
                                 v=x;
                				}
                				else
                				{
                					u=x+1;
                					v=x;
                				}
                			}
                		}
                		sum=sum+cnt*cnt;
                		temp[i][j]=sum;
					}
					else
					{
						int sz = cord.size();

						int targ = pow(2,sz-2)-1;

						sum = 0;
						int cond;
						int cnt1;
						int m;
						int p1=cord[0].first;
						int q1=cord[0].second;
						int p2=cord[sz-1].first;
						int q2=cord[sz-1].second;

						int y1=q1-p1+1;
						int y2=q2-p2+1;

						for (k=0;k<=targ;k++)
						{
							u=k;
							s=0;
							cnt1=y1+y2;
							cond=2;
							val1=0;
							for (m=1;m<(sz-1);m++)
							{
								p=cord[m].first;
								q=cord[m].second;
								y=q-p+1;

								if (u%2==1)
								{
									cnt1=cnt1+y;
									r=cord[s].second+1;
									val1=val1+temp[r][p-1];

									if (m==sz-2)
									{
										r=cord[m].second+1;
										val1=val1+temp[r][p2-1];
									}

									// if (s!=0)
									// {
									// 	r=cord[s].second+1;
									// 	val1=val1+temp[r][p-1];
									// }
									// else
									// {
									// 	val1=val1+temp[i][p-1];
									// }
								
									s=m;
								}
								else
								{
									if (m==(sz-2))
									{
										r=cord[s].second+1;
										val1=val1+temp[r][p2-1];
									}
								}
								u=u/2;
							}

							val1=val1+(cnt1*cnt1);

							if (sum<val1)
								sum=val1;
						}

						temp[i][j]=sum;

					}

					cord.clear();
				}
				else
				{
	                 sum=0;

	                 for (x=i;x<j;x++)
	                 {
	                 	p=temp[i][x]+temp[x+1][j];

	                 	if (sum<p)
	                 		sum=p;
	                 }

	                 temp[i][j]=sum;
				}
			}
		}
	}

	// cout<<" print the temp matrix -- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<n;j++)
	// 		cout<<temp[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	answer = temp[0][n-1];

	return answer;
}       


int main()
{
	// vector<int> boxes = {1,3,2,2,2,3,4,3,1};
	// vector<int> boxes = {3,8,8,5,5,3,9,2,4,4,6,5,8,4,8,6,9,6,2,8,6,4,1,9,5,3,10,5,3,3,9,8,8,6,5,3,7,4,9,6,3,9,4,3,5,10,7,6,10,7};
	// vector<int> boxes =  {2,5,10,9,4,8,6,9,9,1};
	// vector<int> boxes = {8,1,2,10,8,5,1,10,8,4};
	vector<int> boxes = {1,1,1,1,1,1,1,1,1,1,2,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};


	int n = boxes.size();
	cout<<" 546. Remove boxes -- "<<endl;

	for (int i=0;i<boxes.size();i++)
		cout<<boxes[i]<<" ";
	cout<<endl;

	cout<<" n = "<<n<<endl;

	int answer = removeBoxes(boxes);

	cout<<" answer = "<<answer<<endl;
}