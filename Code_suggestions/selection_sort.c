#include <stdio.h>

// --- Selection Sort Function ---
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    // Loop through the entire array step by step
    // We only need to go up to n-1 because the last element will naturally be sorted
    for (i = 0; i < n - 1; i++) {
        
        // Assume the first unsorted element is the smallest
        min_idx = i;

        // Loop through the REST of the array to see if there is an even smaller number
        for (j = i + 1; j < n; j++) {
            
            // If we find a smaller number, record its position (index)
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // After checking the rest of the array, we now know the position of the true smallest number.
        // Swap that smallest number with our current position (i).
        
        // This is a simple 3-step swap using a temporary variable
        temp = arr[min_idx];       // Save the smallest value
        arr[min_idx] = arr[i];     // Put the value at 'i' into the smallest value's old spot
        arr[i] = temp;             // Put the smallest value into spot 'i'
    }
}

// --- Helper function to print the array ---
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// --- Main function to test the sort ---
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    
    // Calculate how many elements are in the array
    int n = sizeof(arr) / sizeof(arr[0]); 

    printf("Original array: \n");
    printArray(arr, n);

    // Call the sorting function
    selectionSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}