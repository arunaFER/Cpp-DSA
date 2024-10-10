#include <iostream>
#include <vector>

// prototypes
void vecDisplay(const std::vector<int> &vec);
void merge(std::vector<int> &A, const std::vector<int> &L, const std::vector<int> &R);
void mergeSort(std::vector<int> &A);

void vecDisplay(const std::vector<int> &vec){
    for(auto const &v: vec){
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void merge(std::vector<int> &A, const std::vector<int> &L, const std::vector<int> &R){
    int nL = L.size();
    int nR = R.size();
    int i = 0, j = 0, k = 0;

    // merging subarrays back into A
    while (i < nL && j < nR){
        if (L[i] <= R[j]){
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
        }
        ++k;
    }

    // if one array is exhausted
    // once first while is over only one of below loops
    // will activate
    while (i < nL){
        A[k] = L[i];
        ++i;
        ++k;
    }
    while (j < nR){
        A[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(std::vector<int> &A){
    int n = A.size();

    if (n < 2){
        return;
    }

    int mid = n / 2;

    std::vector<int> left(A.begin(), A.begin() + mid);
    std::vector<int> right(A.begin() + mid, A.end());

        // Recursively sort both subarrays
    mergeSort(left);
    mergeSort(right);

    // Merge the sorted subarrays
    merge(A, left, right);
}

int main(){
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    std::cout << "Unsorted vector: ";
    vecDisplay(arr);

    mergeSort(arr);

    std::cout << "Sorted vector: ";
    vecDisplay(arr);

    return 0;
}