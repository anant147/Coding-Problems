#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int getdir(string test1,string test2,string keychr,int k,int pos1,int pos2)
{
	int i,j,u,v,x,y,cord1,cord2;

	int n1 = test1.length();
	int n2 = test2.length();
	int n3 = keychr.length();

	// cout<<" test1 -- "<<test1<<endl;
	// cout<<" test2 -- "<<test2<<endl;
	// cout<<" keychr -- "<<keychr<<endl;
	// cout<<" k = "<<k<<endl;


	int min1=n1-1;
	int min2=n2-1;

	int answer;

	for (i=0;i<n1;i++)
	{
		if (keychr[k]==test1[i])
		{
			x=i;
			y=n1-i;

			if (x<y)
				u=x;
			else
				u=y;

			if(u<min1)
			{
				min1=u;
				cord1=i;
			}
		}
	}

	for (i=0;i<n2;i++)
	{
		if (keychr[k]==test2[i])
		{
			x=i;
			y=n2-i;

			if(x<y)
				u=x;
			else
				u=y;

			if(u<min2)
			{
				min2=u;
				cord2=i;
			}
		}
	}

	// cout<<" min1 -- "<<min1<<endl;
	// cout<<" min2 -- "<<min2<<endl;
	// cout<<" cord1 -- "<<cord1<<endl;
	// cout<<" cord2 -- "<<cord2<<endl;


	if (min1<min2)
		return pos1;
	else if(min1>min2)
		return pos2;
	else
	{
		if (k==(n3-1))
			return pos1;

		// cout<<"in func "<<endl;
		
	    string test3 = test1.substr(cord1,n1-cord1) + test1.substr(0,cord1);
	    // cout<<"test3 -- "<<test3<<endl;
	    string test4 = test2.substr(cord2,n2-cord2) + test2.substr(0,cord2);
	    // cout<<"test4 -- "<<test4<<endl;

	    return getdir(test3,test4,keychr,k+1,pos1,pos2);
		
	}
}

int findRotateSteps(string ring,string key)
{
	int i,j,k1,u,v,x,y,p,1q,answer,steps,min,pos1,pos2,pos,mpos,cord1,cord2,pos3;

	int n = ring.length();
	int m = key.length();

	steps = 0;

	string test = ring;
	// cout<<"steps = "<<steps<<endl;

	string keychr = "";

	for (i=0;i<m;i++)
	{
		if (i==0)
			keychr=keychr+key[i];
		else
		{
			if (key[i]!=key[i-1])
				keychr=keychr+key[i];
		}
	}

	int klen = keychr.length();

	k=0;
	steps=0;
	for (i=0;i<m;i++)
	{
		if (keychr[k]==key[i] && k!=klen)
			k++;

		min=n-1;
		for (j=0;j<n;j++)
		{
			if (key[i]==test[j])
			{
				x=j;
				y=n-j;

				if (x<y)
				{
					u=x;
					pos1=0;
					cord1=j;
				}
				else
				{
					u=y;
					pos1=1;
					cord1=j;
				}
				

				if (u<=min)
				{
					if (u<min || k==klen)
					{
						min=u;
						pos2=pos1;
						cord2=cord1;
					}
					else
					{
						if (pos1!=pos2)
						{
							// cout<<"hello "<<endl;
							string test1 = test.substr(cord1,n-cord1) + test.substr(0,cord1);
							string test2 = test.substr(cord2,n-cord2) + test.substr(0,cord2);

							pos3 = getdir(test1,test2,keychr,k,pos1,pos2);

							
							if(pos3==pos1)
							{
								pos2=pos1;
								cord2=cord1;
							}
						}
					}
				}
			}
		}

		steps=steps+1+min;

		if (pos2==0)
		{
			p=n-cord2;
			q=cord2;
			test=test.substr(cord2,n-cord2) + test.substr(0,cord2);
		}
		else
		{
			p=n-cord2;
			q=cord2;
			test=test.substr(cord2,n-cord2) + test.substr(0,cord2);
		}

		// cout<<"test string -- "<<test<<" with steps -- "<<steps<<endl;
	}

	// cout<<"final value -- "<<steps<<endl;

	return steps;
}

int main()
{
	string ring = "godding";
	string key = "gd";

	// string ring = "abcde";
	// string key = "ade";

    // string ring = "nyngl";
    // string key = "yyynnnnnnlllggg";

	cout<<"514. Freedom Trail problem -- "<<endl;
	cout<<" ring string -- "<<ring<<endl;
	cout<<" key string -- "<<key<<endl;

	int answer = findRotateSteps(ring,key);

	cout<<" answer = "<<answer<<endl;
}