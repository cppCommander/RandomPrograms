#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;


int RandomNumber () { return (std::rand()%100); }

void quickSort(int arr[], int left, int right) {

      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

void bubbleSort(int arr[], int n) {

      bool swapped = true;
      int j = 0;
      int tmp;
      while (swapped) {
            swapped = false;
            j++;
            for (int i = 0; i < n - j; i++) {
                  if (arr[i] > arr[i + 1]) {
                        tmp = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = tmp;
                        swapped = true;
                  }
            }
      }
}

void insertionSort(int arr[], int length) {
      int i, j, tmp;
      for (i = 1; i < length; i++) {
            j = i;
            while (j > 0 && arr[j - 1] > arr[j]) {
                  tmp = arr[j];
                  arr[j] = arr[j - 1];
                  arr[j - 1] = tmp;
                  j--;
            }
      }
}

int main()
{
    std::srand ( unsigned ( std::time(0) ) );
    std::vector<int> v1 (10000);
    std::vector<int> v2 (20000);
    std::vector<int> v3 (50000);
    std::vector<int> v4 (100000);
    std::generate (v1.begin(), v1.end(), RandomNumber);
    std::generate (v2.begin(), v2.end(), RandomNumber);
    std::generate (v3.begin(), v3.end(), RandomNumber);
    std::generate (v4.begin(), v4.end(), RandomNumber);

    int arr1[10000];
    int arr2[20000];
    int arr3[50000];
    int arr4[100000];
    std::copy(v1.begin(), v1.end(), arr1);
    std::copy(v2.begin(), v2.end(), arr2);
    std::copy(v3.begin(), v3.end(), arr3);
    std::copy(v4.begin(), v4.end(), arr4);

    int n1 = 10000;
    int n2 = 20000;
    int n3 = 50000;
    int n4 = 100000;

    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;

//Quicksort

   cout << "Quicksort times:" << endl;

//time of arr1

    t1 = high_resolution_clock::now();
    quickSort(arr1, 0, n1-1);
    t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << "10000 array took: " << duration << " microseconds" << endl;

//time of arr2
    t1 = high_resolution_clock::now();
    quickSort(arr2, 0, n2-1);
    t2 = high_resolution_clock::now();

    duration = duration_cast<microseconds>(t2 - t1 ).count();

    cout << "20000 array took: " << duration << " microseconds" << endl;

//time of arr3
    t1 = high_resolution_clock::now();
    quickSort(arr3, 0, n3-1);
    t2 = high_resolution_clock::now();

    duration = duration_cast<microseconds>(t2 - t1 ).count();

    cout << "50000 array took: " << duration << " microseconds" << endl;

//time of arr4
    t1 = high_resolution_clock::now();
    quickSort(arr4, 0, n4-1);
    t2 = high_resolution_clock::now();

    duration = duration_cast<microseconds>(t2 - t1 ).count();

    cout << "100000 array took: " << duration << " microseconds" << endl;


    std::copy(v1.begin(), v1.end(), arr1);
    std::copy(v2.begin(), v2.end(), arr2);
    std::copy(v3.begin(), v3.end(), arr3);
    std::copy(v4.begin(), v4.end(), arr4);


//insertionSort

   cout << endl << "InsertionSort times:" << endl;

//time of arr1
    t1 = high_resolution_clock::now();
    insertionSort(arr1, n1-1);
    t2 = high_resolution_clock::now();

    duration = duration_cast<microseconds>(t2 - t1 ).count();

    cout << "10000 array took: " << duration << " microseconds" << endl;

//time of arr2
    t1 = high_resolution_clock::now();
    insertionSort(arr2, n2-1);
    t2 = high_resolution_clock::now();

    duration = duration_cast<microseconds>(t2 - t1 ).count();


    cout << "20000 array took: " << duration << " microseconds" << endl;

//time of arr3
    t1 = high_resolution_clock::now();
    insertionSort(arr3, n3-1);
    t2 = high_resolution_clock::now();

    duration = duration_cast<microseconds>(t2 - t1 ).count();

    cout << "50000 array took: " << duration << " microseconds" << endl;

//time of arr4
    t1 = high_resolution_clock::now();
    insertionSort(arr4, n4-1);
    t2 = high_resolution_clock::now();

    duration = duration_cast<microseconds>(t2 - t1 ).count();

    cout << "100000 array took: " << duration << " microseconds" << endl;



    std::copy(v1.begin(), v1.end(), arr1);
    std::copy(v2.begin(), v2.end(), arr2);
    std::copy(v3.begin(), v3.end(), arr3);
    std::copy(v4.begin(), v4.end(), arr4);


//Bubblesort

   cout << endl << "Bubblesort times:" << endl;

//time of arr1
    t1 = high_resolution_clock::now();
    bubbleSort(arr1, n1-1);
    t2 = high_resolution_clock::now();

    duration = duration_cast<microseconds>(t2 - t1 ).count();

    cout << "10000 array took: " << duration << " microseconds" << endl;

//time of arr2
    t1 = high_resolution_clock::now();
    bubbleSort(arr2, n2-1);
    t2 = high_resolution_clock::now();

    duration = duration_cast<microseconds>(t2 - t1 ).count();

    cout << "20000 array took: " << duration << " microseconds" << endl;

//time of arr3
    t1 = high_resolution_clock::now();
    bubbleSort(arr3, n3-1);
    t2 = high_resolution_clock::now();

    duration = duration_cast<microseconds>(t2 - t1 ).count();

    cout << "50000 array took: " << duration << " microseconds" << endl;

//time of arr4
    t1 = high_resolution_clock::now();
    bubbleSort(arr4, n4-1);
    t2 = high_resolution_clock::now();

    duration = duration_cast<microseconds>(t2 - t1 ).count();

    cout << "100000 array took: " << duration << " microseconds" << endl;



    return 0;
}
