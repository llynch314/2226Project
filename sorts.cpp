#include "sorts.h"
#include <algorithm>
using namespace std;

//Bubble Sort from geeksforgeeks https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}
//Selection Sort from geeksforgeeks https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/
void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {

                min_idx = j;
            }
        }

        swap(arr[i], arr[min_idx]);
    }
}

//Insertion Sort from geeks for geeks https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//Merge Sort helpers from geeks for geeks https://www.geeksforgeeks.org/dsa/iterative-merge-sort/
void merge(vector<int>& arr, int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors
    // for left and right subarrays
    vector<int> arr1(n1), arr2(n2);

    // Copy data to temporary vectors
    for (int i = 0; i < n1; i++)
        arr1[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        arr2[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    // Merge the temp vectors back into arr
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of arr1[] if any
    while (i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    // Copy remaining elements of arr2[] if any
    while (j < n2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

// Main sorting function
void mergeSort(vector<int>& arr) {
    int n = arr.size();

    // Iterate through subarrays of increasing size
    for (int currSize = 1; currSize <= n-1;
    currSize = 2*currSize) {

        // Pick starting points of different
        // subarrays of current size
        for (int leftStart = 0; leftStart < n-1;
        leftStart += 2*currSize) {

            // Find endpoints of the subarrays to be merged
            int mid = min(leftStart + currSize - 1, n-1);
            int rightEnd = min(leftStart + 2*currSize - 1, n-1);

            // Merge the subarrays arr[leftStart...mid]
            // and arr[mid+1...rightEnd]
            merge(arr, leftStart, mid, rightEnd);
        }
    }
}


// Partition helper for QuickSort from geeksforgeeks https://www.geeksforgeeks.org/dsa/iterative-quick-sort/
int partition(vector<int>& arr, int l, int h) {
    int pivot = arr[h];
    int i = l - 1;

    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

// Iterative QuickSort implementation for vector<int>
void quickSort(vector<int>& arr) {
    int l = 0;
    int h = arr.size() - 1;

    if (h <= 0) return; // empty or single element

    vector<int> stack(h - l + 1);
    int top = -1;

    // Push initial range to stack
    stack[++top] = l;
    stack[++top] = h;

    while (top >= 0) {
        h = stack[top--];
        l = stack[top--];

        int p = partition(arr, l, h);

        // Push left subarray if needed
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // Push right subarray if needed
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

//Shell Sort from geeksforgeeks https://www.geeksforgeeks.org/dsa/shell-sort/
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}