#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

bool canCross(vector<int>& stones)
{
	int i,j,k,m,u,v,x,y,sz,p,q,r;

	int n = stones.size();

	vector<int> vst[n];
	vector<int> vk;
	vst[0].push_back(0);

	int maxvl;

	for (i=1;i<n;i++)
	{
		// cout<<"at i = "<<i<<endl;
		for (j=i-1;j>=0;j--)
		{
			sz = vst[j].size();
			if (sz==0)
				continue;

			x=vst[j][0];
			y=vst[j][sz-1];

			p = stones[j]-x-1;
			q = stones[j]+y+1;
			// cout<<"x = "<<x<<" y = "<<y<<endl;
			// cout<<"p = "<<p<<" q = "<<q<<" st-i = "<<stones[i]<<endl;

			if (p<=stones[i] && stones[i]<=q)
			{
				for (m=0;m<vst[j].size();m++)
				{
					k=vst[j][m];
					// cout<<k<<endl;

					if(stones[i]==(stones[j]+k-1))
						vk.push_back(k-1);
					else if (stones[i]==(stones[j]+k))
						vk.push_back(k);
					else if (stones[i]==(stones[j]+k+1))
						vk.push_back(k+1);
				}
	    	}
	    	else
	    		break;
		}

		sort(vk.begin(),vk.end());
        
  //       cout<<endl;
		// cout<<" at i = "<<i<<endl;
		// cout<<" size = "<<vk.size()<<endl;
		for (m=0;m<vk.size();m++)
		{
			if (m==0)
			{
				// cout<<vk[m]<<" ";
				vst[i].push_back(vk[m]);
			}
			else
			{
				if (vk[m]!=vk[m-1])
				{
					// cout<<vk[m]<<" ";
					vst[i].push_back(vk[m]);
				}
			}
		}
		// cout<<endl;
		// cout<<" size = "<<vst[i].size()<<endl;

		vk.clear();
		// if (vst[i].size()==0)
		// 	return false;
	}

	// printing the vst vector 
	// cout<<" printing the vst vector array -- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<vst[i].size();j++)
	// 		cout<<vst[i][j]<<" ";
	// 	cout<<endl;
	// }

	// cout<<endl;

	if (vst[n-1].size()!=0)
		return true;
    else
    	return false;
}

int main()
{
	int i,j,k;
	// vector<int> stones = {0,1,3,5,6,8,12,17};
	vector<int> stones = {0,1,2,3,4,8,9,11};
	int n = stones.size();

	cout<<" frog jump problem "<<endl;
	cout<<" n = "<<n<<endl;
	cout<<" position of stones -- "<<endl;
	for (i=0;i<stones.size();i++)
	cout<<stones[i]<<" ";
	cout<<endl;

	bool answer = canCross(stones);

	if (answer)
	cout<<" we can reach at starting postion "<<endl;
	else
	cout<<" we can not reach at starting position "<<endl;
}