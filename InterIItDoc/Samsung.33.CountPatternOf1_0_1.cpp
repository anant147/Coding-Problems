#include<iostream>
using namespace std;

int main()
{
	cout<<" Samsung 33 question "<<endl;
	cout<<" count pattern of 1[0]1 in given string "<<endl;
	cout<<endl;

	// Given a string, your task is to find the number of patterns of 
	// form 1[0]1 where [0] represents any number of zeroes (minimum 
	// requirement is one 0) there should not be any other character 
	// except 0 in the [0] sequence.

	int test_cases;
	cin>>test_cases;

	while (test_cases > 0)
	{
		test_cases--;
		string input;
		cin>>input;

		int len = input.size();
		int next_state, current_state = 1, count = 0;

		for (int i=0;i<len;i++)
		{
			char c = input[i];

			if (current_state == 1)
			{
				if (c=='0')
					next_state = 1;
				else if (c == '1')
					next_state = 2;
				else
					next_state = 1;
		    }
		    else if ( current_state == 2)
		    {
		    	if (c == '0')
		    		next_state = 3;
		    	else if (c == '1')
		    		next_state = 2;
		    	else
		    		next_state = 1;
		    }
		    else if (current_state == 3)
		    {
		    	if (c == '0')
		    		next_state = 3;
		    	else if (c == '1')
		    		next_state = 4;
		    	else 
		    		next_state = 1;
		    }
		    else if (current_state == 4)
		    {
		    	if (c == '0')
		    		next_state = 3;
		    	else if (c == '1')
		    		next_state = 2;
		    	else
		    		next_state = 1;
		    }

		    current_state = next_state;

		    if (current_state == 4)
		    	count++;
		}

		cout<<" no. of desired patterns = "<<count<<endl;
		cout<<endl;

	}




}