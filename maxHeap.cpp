#include <iostream>
#include <algorithm>
using namespace std;

// function to create a max heap
void maxHeapify(int arr[], int n, int i)
{
    int largest = i; // initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // if left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // if right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // extract elements from heap one by one
    for (int i = n - 1; i >= 0; i--)
    {
        // move current root to end
        swap(arr[0], arr[i]);

        // call maxHeapify on the reduced heap
        maxHeapify(arr, i, 0);
    }
}

int main()
{
    const int size = 10;
    int arr[size];

    // take 10 inputs from the user
    std::cout << "Enter " << size << " integers:" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    // sort the array using heap sort algorithm
    heapSort(arr, size);

    // print sorted array
    std::cout << "Sorted array in descending order:" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
