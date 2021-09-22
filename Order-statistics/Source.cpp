#include <iostream>
#include <vector>

using namespace std;

int32_t partition(vector<int32_t>& vec, int32_t start, int32_t end, int32_t index) 
{
	int32_t ptr1 = start, ptr2 = end;
	while(ptr2 > ptr1)
	{
		if (vec[ptr2] > vec[ptr1]) { ptr1++; }
		else 
		{
			int hold = vec[ptr2 - 1];
			vec[ptr2 - 1] = vec[ptr2];
			vec[ptr2] = hold;
			if (ptr2 - ptr1 > 1) {
				hold = vec[ptr2];
				vec[ptr2] = vec[ptr1];
				vec[ptr1] = hold;
			}
			ptr2--;
		}
	}
	return ptr2;
}

int32_t orderStatistic(vector<int32_t>& vec, int32_t start, int32_t end, int32_t index)
{
	if (vec.size() == 1) { return 0; }
	if(index <= vec.size())
	{
		int32_t pos = partition(vec, start, end, index);
		if (pos + 1 == index) { return pos; }
		else if (pos + 1 > index) { return orderStatistic(vec, start, pos - 1, index); }
		else { return orderStatistic(vec, pos + 1, end, index); }
	}
	else { return -1; }
}

int main() 
{
	vector<int32_t> vec = { 2, 3, 10, 6, 11 };
	int32_t position = orderStatistic(vec, 0, vec.size() - 1, 3); // finds 3rd smallest value from vec
	int32_t third_smallest = vec[position];
}
