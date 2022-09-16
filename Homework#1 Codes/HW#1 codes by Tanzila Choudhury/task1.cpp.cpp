											/* codes submitted for Homework#1 by Tanzila Choudhury */

										/* task 1: Matching paranthesis, Braces, Brackets and check whether the string is valid or not */

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool matchPair(char opening,char closing);
bool validateMatch(char str[]);

bool matchPair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}


bool validateMatch(char str[])
{
	stack<char>  s;
	for(int i =0;i<char_traits<char>::length(str);i++)
	{
	    /* look for openings and push them in stack*/
		if(str[i] == '(' || str[i] == '{' || str[i] == '[')
			s.push(str[i]);

		/*look for the closings and pop openings from stack to match pair*/
		else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
		{

			if(s.empty() || !matchPair(s.top(),str[i]))
				return false;
			else
				s.pop();
		}
	}

	/*if the stack is empty by now, then its a valid string otherwise not*/
	return s.empty() ? true:false;
}


int main()
{
    char s[100];
    cout<<"please input the string: ";

    cin.get(s,100);

    cout<<"\nyour input string is: "<<s<<endl;

	if(validateMatch(s))
		cout<<"The String is Valid!!! \n";
	else
		cout<<"The string is NOT VALID!!!\n";

    return 0;
}
