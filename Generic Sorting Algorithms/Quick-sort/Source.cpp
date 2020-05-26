#include<iostream>
#include<conio.h>
#include<vector>
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
	int	partition(std::vector<int>&, int, int);

	void tripleSwap(std::vector<int>&, int&, int&);

	void QSort(std::vector<int>&, int, int);

};


int main() {
	//std::vector<int> vec = {9,1,3,2,4};
	std::vector<int> vec = { 9,1,3,2};
	QuickSort* entity = new QuickSort(vec);
	entity->QSort(vec, 4, 0);
	for (int i = 0; i < 5; i++) {
		std::cout << vec[i]<<" ";
	}
	_getch();
}

//std::vector<int>& 
//void 
int QuickSort::partition(std::vector<int>& vec, int end,int start)
{
	//int hold_s = start;
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
	//carriers = { hold_s,end,hold_e };
	//return carriers[1];
	return end;
}

void QuickSort::tripleSwap(std::vector<int>& vec, int& e, int& s) {
	int hold_s;
	hold_s = vec[s];
	vec[s]=vec[e - 1];
	vec[e - 1] = vec[e];
	vec[e] = hold_s;
	e--;
	s++;
}

void QuickSort::QSort(std::vector<int>& array, int end, int start)
{

	if (end > start) {
		int q=partition(array, end, start);
		//QSort(array, (carriers[1] - 1), (carriers[0]));
			/*QSort(array, (carriers[2]), (carriers[1] + 1));*/
		QSort(array, (q - 1), actual_s);
		QSort(array, actual_e, (q + 1));
	}
	//else{}
}
