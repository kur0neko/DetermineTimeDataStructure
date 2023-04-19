#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono; //function that work with times


void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[n1], R[n2];

        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        i = 0;
        j = 0;
        k = l;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);

        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int n) {
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

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

int main() {

    //srand(time(0)); // to  random generate everytime

    const int SIZE = 10000;
    int arr[SIZE];
    //srand(time(NULL));
    srand(time(0)); // to  random generate everytime

    //Generate and fill the array with random numbers
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % SIZE;
    }

    // print out all random numbers
    cout<<"Here is the random numbers in arrays "<<endl;
    for (int i = 0; i < SIZE; i++) {
        cout<<arr[i]<<" ";
    }


    // merge sort
    auto start = high_resolution_clock::now(); 
    //start time
  

    mergeSort(arr, 0, SIZE - 1);

    auto end = high_resolution_clock::now();
    //Returns a time point representing the current point in time.

    auto duration = duration_cast<milliseconds>(end - start);
    //from the start time - end time to find time duration
    cout << "Time duration by using Merge Sort : " << duration.count() << " ms" << endl;


    // quick sort
    start = high_resolution_clock::now();
    quickSort(arr, 0, SIZE - 1);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "Time duration by using  Quick Sort : " << duration.count() << " ms" << endl;

    // bubble sort
    start = high_resolution_clock::now();
    bubbleSort(arr, SIZE);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "Time duration by using Bubble Sort : " << duration.count() << " ms" << endl;

    // insertion sort
    start = high_resolution_clock::now();
    insertionSort(arr, SIZE);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "Time duration by using Insertion Sort : " << duration.count() << " ms" << endl;

    // selection sort
    start = high_resolution_clock::now();
    selectionSort(arr, SIZE);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "Time duration by using Selection Sort : " << duration.count() << " ms" << endl;

    return 0;
}