#include <stdio.h>

// --- Recursive Linear Search Function ---
// arr: the array we are searching
// size: the total number of elements
// index: our current position in the array
// key: the number we are looking for
int recursiveLinearSearch(int arr[], int size, int index, int key) {
    
    // Base Case 1: We reached the end of the array without finding the key
    if (index == size) {
        return -1; // -1 means "Not Found"
    }
    
    // Base Case 2: We found the key at our current index!
    if (arr[index] == key) {
        return index; // Return the position where we found it
    }
    
    // Recursive Step: If it's not at the current index, 
    // call this function again, but move the index forward by 1
    return recursiveLinearSearch(arr, size, index + 1, key);
}

// --- Main function to test it out ---
int main() {
    int arr[] = {15, 23, 7, 45, 89, 12};
    int size = 6; // Total elements in the array
    int key = 45; // The number we want to find
    
    // We start searching from index 0
    int result = recursiveLinearSearch(arr, size, 0, key);
    
    if (result == -1) {
        printf("Element %d was not found in the array.\n", key);
    } else {
        printf("Element %d found at index: %d\n", key, result);
    }
    
    return 0;
}