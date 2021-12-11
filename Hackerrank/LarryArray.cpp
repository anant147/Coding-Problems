#include <bits/stdc++.h>        ///   medium problem solved on 5 dec 2019
#include <unordered_map> 

using namespace std;

vector<string> split_string(string);

// Complete the larrysArray function below.
string larrysArray(vector<int> A) {

unordered_map<int,int> valpos;

int i,j,k,u,v;
int val1,val2,val3;
int pos1,pos2,pos3,reqpos,curpos;

int iSorted,canTrip,cond;

int n=A.size();

int sortUp;

for(i=0;i<A.size();i++)
{
    valpos[A[i]]=i;
}

 iSorted=0;canTrip=0;cond=0;
 k=1; 
 sortUp=-1;

 while(cond==0)
 {
   if(valpos[k]==k-1)
   {
       k++;sortUp++;
   }
   else if(k<(n-1)){
       reqpos=k-1;
       curpos=valpos[k];

       while(reqpos!=curpos)
       {
         if(curpos-reqpos==1)
         {
             val1=A[curpos-1];   val2=A[curpos];   val3=A[curpos+1];
             A[curpos-1]=val2;   A[curpos]=val3;   A[curpos+1]=val1;
             valpos[A[curpos-1]]=curpos-1;
             valpos[A[curpos]]=curpos;
             valpos[A[curpos+1]]=curpos+1;
             
             curpos=curpos-1;
             k++; sortUp++;break;
         }
         else if(curpos-reqpos==2)
         {
             val1=A[curpos-2]; val2=A[curpos-1];   val3=A[curpos];
             A[curpos-2]=val3; A[curpos-1]=val1;   A[curpos]=val2;
             valpos[A[curpos-2]]=curpos-2;
             valpos[A[curpos-1]]=curpos-1;
             valpos[A[curpos]]=curpos;
             
             curpos=curpos-2;
             k++;sortUp++;break;

         }
         else
         {
             val1=A[curpos-2]; val2=A[curpos-1];   val3=A[curpos];
             A[curpos-2]=val3; A[curpos-1]=val1;   A[curpos]=val2;
             valpos[A[curpos-2]]=curpos-2;
             valpos[A[curpos-1]]=curpos-1;
             valpos[A[curpos]]=curpos;
             
             curpos=curpos-2;
         }
       }
       
      }

      if(k==n-1)
      {
          cond=1;

          if(valpos[n-1]==n-2 && valpos[n]==n-1)
          iSorted=1;
      }
 }

  if(iSorted==1)
  {
  return "YES";
  }
  else 
  {
  return "NO";
  }
   
   
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string A_temp_temp;
        getline(cin, A_temp_temp);

        vector<string> A_temp = split_string(A_temp_temp);

        vector<int> A(n);

        for (int i = 0; i < n; i++) {
            int A_item = stoi(A_temp[i]);

            A[i] = A_item;
        }

        string result = larrysArray(A);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
