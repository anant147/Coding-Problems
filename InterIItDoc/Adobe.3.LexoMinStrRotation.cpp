#include<bits/stdc++.h>
using namespace std;

string minLexRotation( string str)
{
	int n = str.length();

	string arr[n];

	string concat = str + str;

	for (int i=i;i<n;i++)
		arr[i] = concat.substr(i, n);

	sort(arr, arr+n);

	return arr[0];
}

int main()
{
	cout<<" Adobe question 3 "<<endl;
	cout<<" Lexicographically minimum string rotation ";
	cout<<endl;

	string str = "GEEKSFORGEEKS";

	cout<<" str = "<< str<< endl;

	string answer = minLexRotation(str);

	cout<<" answer = "<< answer<<endl;
}