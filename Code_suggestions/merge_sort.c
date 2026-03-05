#include <stdio.h>

// --- Step 2: The Conquer Phase (Merging) ---
// This function takes two ALREADY SORTED halves and merges them into one sorted array.
void merge(int arr[], int left, int mid, int right) {
    
    // Calculate the sizes of the two halves
    int left_size = mid - left + 1;
    int right_size = right - mid;

    // Create temporary arrays to hold the divided halves
    int LeftArray[left_size], RightArray[right_size];

    // Copy the actual data into our temporary arrays
    for (int i = 0; i < left_size; i++) 
        LeftArray[i] = arr[left + i];
        
    for (int j = 0; j < right_size; j++) 
        RightArray[j] = arr[mid + 1 + j];

    // Now, let's merge them back into the main array 'arr'
    int i = 0; // Tracks our position in LeftArray
    int j = 0; // Tracks our position in RightArray
    int k = left; // Tracks our position in the main array

    // Compare elements from both halves and copy the smaller one back into 'arr'
    while (i < left_size && j < right_size) {
        if (LeftArray[i] <= RightArray[j]) {
            arr[k] = LeftArray[i];
            i++; // Move forward in the LeftArray
        } else {
            arr[k] = RightArray[j];
            j++; // Move forward in the RightArray
        }
        k++; // Move forward in the main array
    }

    // If there are any elements left over in the LeftArray, copy them
    while (i < left_size) {
        arr[k] = LeftArray[i];
        i++;
        k++;
    }

    // If there are any elements left over in the RightArray, copy them
    while (j < right_size) {
        arr[k] = RightArray[j];
        j++;
        k++;
    }
}

// --- Step 1: The Divide Phase (Splitting) ---
void mergeSort(int arr[], int left, int right) {
    // Base condition: If left >= right, the array is just 1 element, which is already sorted!
    if (left < right) {
        
        // Find the middle point to divide the array into two halves
        int mid = left + (right - left) / 2;

        // Recursively call mergeSort on the first half
        mergeSort(arr, left, mid);

        // Recursively call mergeSort on the second half
        mergeSort(arr, mid + 1, right);

        // Once divided down to single elements, start merging them back together!
        merge(arr, left, mid, right);
    }
}

// --- Helper function to print the array ---
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// --- Main function to test it ---
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    
    // Calculate the total number of elements in the array
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, size);

    // Call mergeSort starting from index 0 to the last index (size - 1)
    mergeSort(arr, 0, size - 1);

    printf("Sorted array: \n");
    printArray(arr, size);

    return 0;
}