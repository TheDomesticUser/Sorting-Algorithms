#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

template<typename T, typename T2>
inline void swap(T& val1, T2& val2)
{
	const T buffer = val1;
	val1 = val2;
	val2 = buffer;
}

template<typename T>
void bubbleSort(std::vector<T>& dataStruct)
{
	for (unsigned int i = 0; i < dataStruct.size() - 1; i++)
		for (unsigned int j = 0; j < dataStruct.size() - 1; j++)
			if (dataStruct[j] > dataStruct[j + 1]) swap(dataStruct[j], dataStruct[j + 1]);
}

template<typename T>
void selectionSort(std::vector<T>& dataStruct)
{
	for (unsigned int i = 0; i < dataStruct.size() - 1; i++) {
		unsigned int minValIndex = i;
		
		for (unsigned int j = i + 1; j < dataStruct.size(); j++)
			if (dataStruct[minValIndex] > dataStruct[j]) minValIndex = j;
		if (minValIndex != i) swap(dataStruct[minValIndex], dataStruct[i]);
	}
}

template<typename T>
void insertionSort(std::vector<T>& dataStruct)
{
	if (dataStruct.size() <= 1) return;

	for (unsigned int i = 1; i < dataStruct.size(); i++)
		if (dataStruct[i] < dataStruct[i - 1]) {
			for (unsigned int j = 0; j < i; j++)
				if (dataStruct[i] < dataStruct[j]) {
					dataStruct.insert(dataStruct.begin() + j, dataStruct[i]);
					dataStruct.erase(dataStruct.begin() + i + 1);
					continue;
				}
		}
}

template<typename T>
std::vector<T> merge(std::vector<T> left, std::vector<T> right)
{
	std::vector<T> mergedVector;

	unsigned int leftIndex = 0;
	unsigned int rightIndex = 0;
	
	while (true)
	{
		if (left[leftIndex] < right[rightIndex]) {
			mergedVector.push_back(left[leftIndex]);

			if (++leftIndex == left.size()) {
				while (rightIndex < right.size()) mergedVector.push_back(right[rightIndex++]);
				break;
			}
		} else {
			mergedVector.push_back(right[rightIndex]);
			
			if (++rightIndex == right.size()) {
				while (leftIndex < left.size()) mergedVector.push_back(left[leftIndex++]);
				break;
			}
		}
	}
	return mergedVector;
}

template<typename T>
std::vector<T> mergeDivide(const std::vector<T>& dataStruct)
{
	if (dataStruct.size() <= 1) return dataStruct;

	const size_t half = dataStruct.size() / 2;

	std::vector<T> left(dataStruct.begin(), dataStruct.begin() + half);
	std::vector<T> right(dataStruct.begin() + half, dataStruct.end());

	return merge(
		mergeDivide(left),
		mergeDivide(right)
	);
}

template<typename T>
void mergeSort(std::vector<T>& dataStruct)
{
	dataStruct = mergeDivide(dataStruct);
}

template<typename T>
std::vector<T> pivotSort()
{
	
}

// Will be finished soon
template<typename T>
std::vector<T> quickSort(std::vector<T> dataStruct)
{
	{
		bool isSorted = true;

		for (size_t index = dataStruct.begin(); index < dataStruct.size() - 1; index++)
			if (dataStruct[index] > dataStruct[index]) {
				isSorted = false;
				break;
			}
		if (isSorted) return dataStruct;
	}

	size_t pivotIndex = dataStruct.size();

	for (size_t iter = 0; iter < pivotIndex; iter++)
		if (dataStruct.at(iter) > dataStruct[pivotIndex - 1]) {
			dataStruct.insert(dataStruct.begin() + pivotIndex, dataStruct.at(iter));
			dataStruct.erase(dataStruct.begin() + iter);
			pivotIndex--;
			iter--;
		}

	const std::vector<T> leftVector(dataStruct.begin(), dataStruct.begin() + pivotIndex - 1);
	const std::vector<T> rightVector(dataStruct.begin() + pivotIndex, dataStruct.end());

	
}

int main()
{
	// Seed the RNG
	std::srand(std::time(nullptr));

	std::vector<int> nums{ 6, 5, 10, 2, 3, 9, 4, 1, 15, 7 };

	return 0;
}
