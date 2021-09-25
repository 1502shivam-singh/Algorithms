#include <iostream>
#include <string>

int stringMatcher(std::string& str, std::string& matchStr) 
{
	/*
	Algorithm explained
	str = abcdeefgh
	      ^(1)

	matchStr = def
	           ^(2)
	stages -
	nm (not match)
	nm
	nm
	m  (put in string matching mode, both 1 and 2 ptr move, set a holdPtr in str from strmatch start)
	m  (keep moving 1 and 2)
	nm (stop (if notMatch localised to string matching mode), in same iteration move 2 back to start and check 1 and 2, if match start same cycle(move holdPtr too in this case, first set to -1 and if match set to the 1 ptr index))
		
	*/

	int ptr1 = 0, ptr2 = 0, ptr3 = 0;
	bool sMode = false;
	for (int ptr1 = 0; ptr1<str.size(); ptr1++)
	{
		if (ptr2 == matchStr.size()) { break; }
		if (str[ptr1] != matchStr[ptr2] && !sMode)	// normal not match if
		{

		}
		if (str[ptr1] == matchStr[ptr2] && sMode)
		{
			ptr2++;
		}

		else if (str[ptr1] == matchStr[ptr2] && !sMode)
		{
			sMode = true;
			ptr3 = ptr1;
			ptr2++;
		}

		else if (str[ptr1] != matchStr[ptr2] && sMode)
		{
			ptr2 = 0;
			ptr3 = -1;
			sMode = false;
			if (str[ptr1] == matchStr[ptr2])
			{
				sMode = true;
				ptr3 = ptr1;
				ptr2++;
			}
		}
		else
		{
			continue;
		}

	}

	if (ptr2 == matchStr.size()) 
	{
		return ptr3;
	} 
	else 
	{
		return -1;
	}

}

int main() 
{
	std::string str = "abcdefefgh";
	std::string strMatch = "def";
	int pointer = stringMatcher(str, strMatch);
}
