/*
    Bubblesort
*/

#include <iostream>
#include <vector>
#include <utility>

void bubbleSort(std::vector<int> &vec, int n);
void vecDisplay(const std::vector<int> &vec);

void bubbleSort(std::vector<int> &vec, int n){
    for(int i {0}; i < n - 1; ++i){
        bool swap = false;
        for(int j {0}; j < n - i - 1; ++j){
            if (vec.at(j) > vec.at(j + 1)){
                // int temp = vec.at(j);
                // vec.at(j) = vec.at(j + 1);
                // vec.at(j + 1) = temp;

                std::swap(vec.at(j), vec.at(j + 1));
                swap = true;
            }
        }
        if (!swap){
            break;
        }
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

    bubbleSort(arr, n);

    std::cout << "Sorted vector: ";
    vecDisplay(arr);

    return 0;
}