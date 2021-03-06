//Binary search

#include<iostream>
#include<conio.h>
#include<vector>

int Binary_Search(const std::vector<int>&, int, int, int);  //Function declartion for Binary search 

int main() {
	std::vector<int> vector{ 2,3,4,5,6,7,8,9,10,11,12,34,556,780,1000,1001,2000,3000,4000,5000,6000,7000,8000,9000};	//input array must be sorted for the algorithm to work
	std::cout << Binary_Search(vector, 8, 0, vector.size() - 1);	
//function calling sequence (vector storing values, target, start index of section of vector in which you have to search, end index of section of vector in which you have to search)
	_getch();
}

int Binary_Search(const std::vector<int>& vec, int target, int start, int end)  //Function definition
{
	if (start == end&&vec[start] != target) {
		return -1;
	}
	else if (vec[start] == target) { return start; }
	else if (vec[(start + end) / 2] > target) {
		return Binary_Search(vec, target, start, ((start + end) / 2)-1);
	}
	else { return Binary_Search(vec, target, ((start + end) / 2)+1, end); }
}
