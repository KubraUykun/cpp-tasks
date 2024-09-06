#include <iostream>

template<typename T>

// Template function to find the index of the smallest element in an array
size_t smallest(const T* arr, size_t length) {
    size_t min_idx = 0;
    for (size_t i = 1; i < length; i++) {  
        // Update min_idx if the current element is smaller than the previous smallest element
        if(arr[i] < arr[i-1])
            min_idx = i;
    }

    return min_idx; 
}


int main() {
    // Define and initialize arrays of different types
    const int arr1[] = { 3, 5, 7, 1 };
    const size_t len1 = sizeof(arr1) / sizeof(arr1[0]); 

    const double arr2[] = { 2.3, 3.6, 5.2, -1.7, 0.0 };
    const size_t len2 = sizeof(arr2) / sizeof(arr2[0]); 

    const float arr3[] = { 2.55, -13.3, 0.5, 0.7, 1.1, 9.99 };
    const size_t len3 = sizeof(arr3) / sizeof(arr3[0]); 

    // Find and print the index of the smallest element in each array
    std::cout << "Index of the smallest element in arr1 is: " << smallest(arr1, len1) << "\n";
    std::cout << "Index of the smallest element in arr2 is: " << smallest(arr2, len2) << "\n";
    std::cout << "Index of the smallest element in arr3 is: " << smallest(arr3, len3) << "\n";

    return 0;
}