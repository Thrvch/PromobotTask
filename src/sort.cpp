#include "sort.hpp"
#include "shapeClasses.hpp"
#include <algorithm>
#include <mutex>
#include <iostream>

using namespace std;

mutex console_mutex;

void printArray(const vector<Shapes*>& arr){
    for( size_t i = 0; i < arr.size(); i++){
        cout << "Type: " << arr[i] -> getType() << "  |  Area: " << arr[i] -> getArea() << "\n";
    }
    cout << endl;
}

void printOut(const string& sort_name, const vector<Shapes*>& arr){
    lock_guard<mutex> lock(console_mutex);
    cout << "Sort_type:" << sort_name << "\nResult:\n";
    for( size_t i = 0; i < arr.size(); i++){
        cout << "Type: " << arr[i] -> getType() << "  |  Area: " << arr[i] -> getArea() << "\n";
    }
    cout << endl;
}

void merge(vector<Shapes*>& arr, int start, int end, int mid){
    int n1 = mid - start + 1;
    int n2 = end - mid;

    vector<Shapes*> L(n1), R(n2);

    for (int i = 0; i < n1; i++){
        L[i] = arr[start+i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 +j];
    }
    int i = 0 , j = 0, k = start;
    while (i < n1 && j < n2){
        if(L[i] -> getArea() <= R[j] -> getArea()){
            arr[k] = L[i];
            i++;
        } else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void bubble_sort(vector<Shapes*>& arr){
    if (arr.size() <= 1) return;

    for (size_t i = 0; i < arr.size(); i++){
        for(size_t j = 0; j < arr.size() - i - 1; j++){
            if (arr[j] -> getArea() >= arr[j+1] -> getArea()){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    printOut("bubble", arr);
}

int partition(vector<Shapes*>& arr, int start, int end) {
    int mid = start + (end - start) / 2;
    int i = start;
    swap(arr[mid], arr[end]);
    int pivot = arr[end] -> getArea();

    for (int j = start; j < end; j++) {
        if (arr[j] -> getArea() <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[end], arr[i]);
    return i;
}


void quick_sort_impl(vector<Shapes*>& arr, int start, int end){
    if (start < end) {
        int pivot = partition(arr, start, end);
        quick_sort_impl(arr, start, pivot - 1);
        quick_sort_impl(arr, pivot + 1, end);
    }
}



void quick_sort(vector<Shapes*>& arr){
    if (arr.size() <= 1) return;
    quick_sort_impl(arr, 0, arr.size() - 1);
    printOut("quick", arr);
}

void merge_sort_impl(vector<Shapes*>&arr, int start, int end){
    if (start < end){
        int mid = start + (end - start)/2; // Avoid potential overflow
        merge_sort_impl(arr, start, mid);
        merge_sort_impl(arr, mid+1 , end);
        merge(arr,start,end,mid);
    }
}

void merge_sort(vector<Shapes*>& arr) {
    if (arr.size() <= 1) return;
    merge_sort_impl(arr, 0, arr.size() - 1);
    printOut("merge", arr);
}