#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

// dp video 42
//word break problem - given a word , we have to tell whether the given word exist in dictionary or can be broken into multiple words or not
// time complexity - o(n*n*n*(size of dictionary))
// space complexty -  o(n*n)

bool searchInDict(string text)
{
	int i;
	string dict[]={"I","a","am","ace","you","will","have","win","what","you","want"};
	int n = sizeof(dict)/sizeof(dict[0]);

	for (i=0;i<n;i++)
	{
		if(dict[i].compare(text)==0)
			return true;

	}
	return false;
}

void printWord(bool *temp,int *tracer,string text,int n,int st,int ed)
{
	bool val = *((temp+st*n)+ed);
	int k = *((tracer+st*n)+ed);

	if (val==true)
	{
		if(k==-1)
		{
          int len=ed-st+1;
          cout<<"word in given string -- "<<text.substr(st,len)<<endl;
          return;
		}
		else
		{
			printWord((bool *)temp,(int *)tracer,text,n,st,k);
			printWord((bool *)temp,(int *)tracer,text,n,k+1,ed);
		}
	}
}

bool wordBreaking(string text)
{
	int i,j,k,u,v,x,y,answer;

	int n = text.length();
	bool temp[n][n];
	int tracer[n][n];

	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			temp[i][j]=false;
			tracer[i][j]=-2;
		}
	}

	for (int len=1;len<=n;len++)
	{
		for(i=0;i<(n-len+1);i++)
		{
			j=i+len-1;

			string textstr = text.substr(i,len);

			bool val = searchInDict(textstr);

			if (val==true)
			{
				temp[i][j]=true;
				tracer[i][j]=-1;
			}
			else
			{

				for (k=i;k<j;k++)
				{
					if ( temp[i][k] && temp[k+1][j] )
					{
						temp[i][j]=true;
						tracer[i][j]=k;
						break;
					}
				}
			}
		}
	}

	// printing the temp and tracer matrix
	cout<<"print the temp matrix "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	cout<<"print the tracer matrix "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<tracer[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
    
	if (temp[0][n-1])
	{
     if (tracer[0][n-1]==-1)
     	cout<<" this word is present in the dictionary "<<endl;
     else
     {
     	cout<<"given string  break into multiple words "<<endl;
     	cout<<"multiple words of given words -- "<<endl;
     	printWord((bool *)temp,(int *)tracer,text,n,0,n-1);
     }

	}
	else
	{
		cout<<"given string donot break into multiple words "<<endl;
	}
	cout<<endl;
	return temp[0][n-1];
}

int main()
{
	int i,j,k;
	// string text="Iamace";
	// string text = "youwillwin";
	string text = "will";

	cout<<" word break problem -- "<<endl;
	cout<<" string text -- "<<text<<" , of length "<<text.length()<<endl;
	cout<<endl;

	int answer = wordBreaking(text);

	if (answer == true)
	cout<<" text string can be in dictionary or broken into multiple words "<<endl;
	else
	cout<<" text string can not be in dictionary or broken into multiple words"<<endl;
}