//Generic insertion sort-Ascending order

#include<iostream>
#include<conio.h>
#include<vector>
#include<string>

template<typename T>
struct store_value {
	std::vector<T> vec;
	T val;
	inline std::vector<T> insertion(int size, std::vector<T> v); 
};

template<typename T>
std::vector<T> store_value<T>::insertion(int size, std::vector<T> v) {
	for (int i = 1;i < size;i++) {
		T key = v[i];
		int j = i - 1;
		while (j >= 0 && v[j]>key) {
			T hold;
			hold = v[j];
			v[j] = key;
			v[j + 1] = hold;
			j -= 1;
			key = v[j + 1];
		}
	}
	return v;
}

int main() {
	struct store_value<int> store1;
	std::vector<int> vec;
	int size;
	std::cout << "Enter the number of elements to be entered" << std::endl;
	std::cin >> size;
	for (int i = 0;i < size;i++) {
		//std::getline(std::cin, store1.val);
		std::cin >> store1.val;
		store1.vec.push_back(store1.val);
	}
	vec=store1.insertion(size, store1.vec);	//Sorting working
	for (int i = 0;i < size;i++) {
		std::cout << vec[i]<<" ";
	}
	_getch();
}