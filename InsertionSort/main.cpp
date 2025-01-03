/*
    Insertion sort
*/
#include <iostream>
#include <vector>

void insertionSort(std::vector<int> &vec, int n);
void vecDisplay(const std::vector<int> &vec);

void insertionSort(std::vector<int> &vec, int n){
    for (int i {1}; i <= n - 1; ++i){
        int value = vec.at(i);
        int hole = i;

        while (hole > 0 && vec.at(hole - 1) > value){
            vec.at(hole) = vec.at(hole - 1);
            hole = hole - 1;
        }
        vec.at(hole) = value;
    }
}

void vecDisplay(const std::vector<int> &vec){
    for(auto const &v: vec){
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();

    std::cout << "Unsorted vector: ";
    vecDisplay(arr);

    insertionSort(arr, n);

    std::cout << "Sorted vector: ";
    vecDisplay(arr);

    return 0;
}