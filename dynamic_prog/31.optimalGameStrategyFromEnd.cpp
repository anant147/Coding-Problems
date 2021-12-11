#include <iostream>
#include <vector>
using namespace std;

// dp video 31
// optimal strategy game pick from ends of array of n elements
// time complexity - o(n*n)
// space complexty - o(n*n)

int optimalGameStrategyPickFromEnd(int val[],int n)
{
	int i,j,k,u,v,x,y,cnt,answer,len;

	int temp[n][n][2]={0};

	for (i=0;i<n;i++)
		temp[i][i][0]=val[i];

	// main code 

    for (len=2;len<=n;len++)
    {
    	for (i=0;i<(n-len+1);i++)
    	{
    		j=i+len-1;

    		if ( (temp[i+1][j][1]+val[i]) >= (temp[i][j-1][1]+val[j]) )
    		{
              temp[i][j][0] = temp[i+1][j][1]+val[i];
              temp[i][j][1] = temp[i+1][j][0];
    		}
    		else
    		{
              temp[i][j][0] = temp[i][j-1][1]+val[j];
              temp[i][j][1] = temp[i][j-1][0];
    		}
    	}
    }

    // printing the temp matrix 
    cout<<" printing the temp matrix -- "<<endl;
    for (i=0;i<n;i++)
    {
    	for (j=0;j<n;j++)
    		cout<<" ( "<<temp[i][j][0]<<" , "<<temp[i][j][1]<<" )   ";
    	cout<<endl;
    }
    cout<<endl;

    x=0;
    y=n-1;
    cnt=n;
    vector<int> vpat;
    vector<int> vseq;

    while(true)
    {
    	if (cnt==0)
    		break;
    	else
    	{
    	  if (cnt==1)
    	  {

    	  	cnt--;
    	  	vpat.push_back(val[x]);
    	  	vseq.push_back(x);
    	  	cout<<"case 1 at cnt -- "<<cnt<<" , x = "<<x<<" ,y = "<<y<<endl;
    	  }
          else if ((temp[x+1][y][1] + val[x] ) == (temp[x][y-1][1] + val[y]) )
          {
          	if (val[x]>val[y])
          	{
              cnt--;
              vpat.push_back(val[x]);
              vseq.push_back(x);
              x=x+1;
              cout<<"case 2 at cnt -- "<<cnt<<" , x = "<<x<<" ,y = "<<y<<endl;
          	}
          	else
          	{
             cnt--;
             vpat.push_back(val[y]);
             vseq.push_back(y);
             y=y-1;
             cout<<"case3 at cnt -- "<<cnt<<" , x = "<<x<<" ,y = "<<y<<endl;
          	}
          }
          else if ((temp[x+1][y][1] + val[x] ) > (temp[x][y-1][1] + val[y]) )
          {
           cnt--;
           vpat.push_back(val[x]);
           vseq.push_back(x);
           x=x+1;
           cout<<"case4 at cnt -- "<<cnt<<" , x = "<<x<<" ,y = "<<y<<endl;
          }
          else
          {
            cnt--;
            vpat.push_back(val[y]);
            vseq.push_back(y);
            y=y-1;
            cout<<"case 5 at cnt -- "<<cnt<<" , x = "<<x<<" ,y = "<<y<<endl;
          }
    	}
    }


    int sum1 = 0;
    int sum2 = 0;

    // printing the pattern obtained
    cout<<"pattern of taking values "<<endl;
    for (i=0;i<vpat.size();i++)
    {
    	if( i%2 ==0)
    	{
    		sum1=sum1+vpat[i];
    		cout<<" player1 chooses "<<vseq[i]<<" th position with value of "<<vpat[i]<<endl;
    	}
    	else
    	{
    		sum2=sum2+vpat[i];
    		cout<<" player2 chooses "<<vseq[i]<<" th position with value of "<<vpat[i]<<endl;
    	}
    }

    cout<<endl;
    cout<<" total value possessed by player1 -- "<<sum1<<endl;
    cout<<" total value possessed by player2 -- "<<sum2<<endl;
    cout<<endl;



    return temp[0][n-1][0];
}

int main()
{
	int i,j;

	// int val[]= {3,9,1,2};
	// int val[] = {4,3,5,2,5};
	int val[] = {3,5,2,1,7,4};

	int n = sizeof(val)/sizeof(val[0]);

	cout<<" optimal strategy game pick from ends of array --- "<<endl;
	cout<<" size of array -- "<<n<<endl;
	for (i=0;i<n;i++)
	cout<<val[i]<<" ";
	cout<<endl;

	int answer = optimalGameStrategyPickFromEnd(val,n);
	cout<<" answer = "<<answer<<endl;
}