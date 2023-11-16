#include <iostream>
#include <vector>

using namespace std;

// Function to partition the array for quicksort
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Deterministic QuickSort
void quickSortDeterministic(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSortDeterministic(arr, low, pivotIndex - 1);
        quickSortDeterministic(arr, pivotIndex + 1, high);
    }
}

// Randomized QuickSort
int getRandomPivot(int low, int high)
{
    return low + rand() % (high - low + 1);
}

void quickSortRandomized(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // selecting random pivot
        int pivotIndex = getRandomPivot(low, high);
        // swapping it with last elemement and calling partition so 
        // randomized pivot elememt will be at last nd will be used as pivot
        swap(arr[pivotIndex], arr[high]);

        pivotIndex = partition(arr, low, high);

        quickSortRandomized(arr, low, pivotIndex - 1);
        quickSortRandomized(arr, pivotIndex + 1, high);
    }
}

// Function to print an array
void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // Sorting using Deterministic QuickSort
    vector<int> arrDeterministic = arr;
    quickSortDeterministic(arrDeterministic, 0, n - 1);

    cout << "Sorted array using Deterministic QuickSort: ";
    printArray(arrDeterministic);


    // Sorting using Randomized QuickSort
    vector<int> arrRandomized = arr;
    quickSortRandomized(arrRandomized, 0, n - 1);

    cout << "Sorted array using Randomized QuickSort: ";
    printArray(arrRandomized);


    return 0;
}
