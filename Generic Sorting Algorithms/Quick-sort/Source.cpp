#include<iostream>
#include<conio.h>
#include<vector>
#include<time.h> 
#include<stdlib.h>
/*
Algorithm -

QuickSort(Arr&,last){
	function Partition(Arr&,last);
	QuickSort(Arr&,last_left);
	QuickSort(Arr&,last_right);
}

Partition algo. needs triple swapper(for lomuto partition)



Partition function(){
//loop start .. end;
	if->vec[start]>=vec[end];
	{tripleswapper(start,end);}
	else{Do nothing;]
	}
*/
class QuickSort {
private:
	std::vector<int> carriers = {};
	std::vector<int> array;
	const int actual_s = 0;
	const int actual_e = (array.size()-1);
public:

	QuickSort(std::vector<int> vec) :array{vec} {};

	//std::vector<int>& 
	//void
	//int	
	std::vector<int>& partition(std::vector<int>&, int, int);

	void tripleSwap(std::vector<int>&, int&, int&);

	void QSort(std::vector<int>&, int, int);

};


int main() {
	//std::vector<int> vec = {9,1,3,2,4};
	srand(time(0));
	std::vector<int> vec;//= { 11,10,1,6,0,-1,14,-99,100 };
	int size=0,val;

	std::cout << "Enter array size"<<std::endl;
	std::cin >> size;
	std::cout << "Enter array" << std::endl;
	for (int i = 0; i < size; i++) {
		val=rand();
		vec.push_back(val);
	}
	QuickSort* entity = new QuickSort(vec);
	entity->QSort(vec, size-1, 0);
	for (int i = 0; i < size; i++) {
		std::cout << vec[i]<<" ";
	}
	_getch();
}

//std::vector<int>& 
//void 
//int
std::vector<int>& QuickSort::partition(std::vector<int>& vec, int end,int start)  //Problematic
{
	int hold_s = start;
	int hold_e = end;
	int pivot = vec[end];
	while(start<end)
		//(vec[start] != pivot) 
	{
		if (vec[start] >= pivot) {
			tripleSwap(vec, end , start); //Does the swapping and the increase and decrease of start and end
		}
		else { start++; }
	}
	return carriers = { hold_s,end,hold_e };
	//return carriers[1];
	//return end;
}

void QuickSort::tripleSwap(std::vector<int>& vec, int& e, int& s) {
	int hold_s;
	hold_s = vec[s];
	vec[s]=vec[e - 1];
	vec[e - 1] = vec[e];
	vec[e] = hold_s;
	e--;
	//s++;
}

void QuickSort::QSort(std::vector<int>& array, int end, int start)
{

	if (end > start) {
		//int q=
		partition(array, end, start);
		QSort(array, (carriers[1] - 1), (carriers[0]));
			QSort(array, (actual_e), (carriers[1] + 1));
		//QSort(array, (q - 1), actual_s);
		//QSort(array, actual_e, (q + 1));
	}
	//else{}
}

