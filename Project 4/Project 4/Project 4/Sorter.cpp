/****************************************************************************************************************************

Description    :   implementation file of an integer array container class that
                   contains implementations of some sorting algorithms
Dependencies   :   Sorter.cpp
****************************************************************************************************************************/

#include "Sorter.hpp"
#include <vector>
using namespace std;

Sorter::Sorter(array_type type, size_t array_size, int *arr) : type_(type), SIZE_(array_size), values_(arr)
{
}

/***************************s* Selection Sort ****************************/
template <typename Comparator>
int Sorter::getPosOfMinOrMax(int arr[], int from, int to, const Comparator &comp)
{
    int min_or_max = from;
    for (int i = from + 1; i <= to; i++)
    {   //comp is bool func!!!!
        if (comp(arr[i], arr[min_or_max]))
        {
            min_or_max = i;
        }
    }
    return min_or_max;
}

template <typename Comparator>
int Sorter::selectionSort(int arr[], size_t size, const Comparator &comp)
{
    for(int i=0;i<size-1;i++){
        int MinMaxPos=getPosOfMinOrMax(arr, i, size-1, comp);
        if(i!=MinMaxPos){
            std::swap(arr[i], arr[MinMaxPos]);
            selectionCount_++;
        }
    }
    return selectionCount_;
}
/************************************************************************/

/**************************** Insertion Sort ****************************/
template <typename Comparator>
int Sorter::insertionSort(int arr[], size_t size, const Comparator &comp)
{
    for(int i=0;i<size;i++){
        int key=arr[i];
        int j=i-1;
        //compare key with each element on left until smaller or larger is found
        while(comp(key,arr[j])&&j>=0){
            int temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
            
            j--;
            insertionCount_++;
        }
        
    }

    return insertionCount_;
}
/************************************************************************/

// /****************************** Merge Sort ******************************/
template <typename Comparator>
void Sorter::merge(int arr[], int from, int mid, int to, const Comparator &comp)
{
    std::vector<int> temp;//temporary vector
    int i=from;
    int j=mid+1;
    
    while(i<=mid && j<=to){
        
        if(comp(arr[i],arr[j])){
            mergeCount_++;
            temp.push_back(arr[i]);
            i++;
        }
        else{
            mergeCount_++;
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        mergeCount_++;
        temp.push_back(arr[i]);
        i++;
    }
    while (j<=to) {
        mergeCount_++;
        temp.push_back(arr[j]);
        j++;
    }
    for(i=from;i<=to;i++){
       
        arr[i]=temp[i-from];
    }
    
}

template <typename Comparator>
int Sorter::mergeSort(int arr[], int from, int to, const Comparator &comp)
{
    
    if(from<to){
        
        int mid=(from+to)/2;
        mergeSort(arr, from, mid, comp);
        mergeSort(arr, mid+1, to, comp);
        merge(arr, from, mid, to, comp);
    }
    
    return mergeCount_;
}
// /************************************************************************/

void Sorter::runSorts(sort_order order)
{
    //initialzing arrays for sorting
    int selectionValues[SIZE_];
    int insertionValues[SIZE_];
    int mergeValues[SIZE_];

    if (type_ == RANDOM)
    {
        //creating array with random numbers
        srand(static_cast<unsigned>(time(0)));//randomizer fucntion
        for (int i = 0; i < SIZE_; i++)
        {
            //one array for each type of sort
            selectionValues[i] = rand() % 100;
            insertionValues[i] = rand() % 100;
            mergeValues[i] = rand() % 100;
        }
    }

    else
    {
        for (int i = 0; i < SIZE_; i++)
        {   //copying array for sorting
            selectionValues[i] = values_[i];
            insertionValues[i] = values_[i];
            mergeValues[i] = values_[i];
        }
    }

    // Selection Sort Display
    std::cout << "******** Selection Sort ********\nOriginal Array:\n";
    displayArr(selectionValues);
    if (order == INCREASING)
    {
        selectionSort(selectionValues, SIZE_, std::less<int>());
    }
    else
    {
        selectionSort(selectionValues, SIZE_, std::greater<int>());
    }
    std::cout << "\nSorted Array:\n";
    displayArr(selectionValues);
    std::cout << "\nNumber of swaps: " << selectionCount_ << "\n********************************\n\n";

    // Insertion Sort Display
    std::cout << "\n******** Insertion Sort ********\nOriginal Array:\n";
    displayArr(insertionValues);
    if (order == INCREASING)
    {
        insertionSort(insertionValues, SIZE_, std::less<int>());
    }
    else
    {
        insertionSort(insertionValues, SIZE_, std::greater<int>());
    }
    std::cout << "\nSorted Array:\n";
    displayArr(insertionValues);
    std::cout << "\nNumber of swaps: " << insertionCount_ << "\n********************************\n\n";

   
    // Merge Sort Display
    
    std::cout << "\n********** Merge Sort **********\nOriginal Array:\n";
    displayArr(mergeValues);
    if (order == INCREASING)
    {
        mergeSort(mergeValues, 0, SIZE_ - 1, std::less<int>());
    }
    else
    {
        mergeSort(mergeValues, 0, SIZE_ - 1, std::greater<int>());
    }
    std::cout << "\nSorted Array:\n";
    displayArr(mergeValues);
    std::cout << "\nNumber of comparisons: " << mergeCount_ << "\n********************************\n\n";


}
 
//displaying array
void Sorter::displayArr(const int array[]) const
{
    for (size_t i = 0; i < SIZE_; i++)
    {
        std::cout << array[i];
        (i < SIZE_ - 1) ? (cout << " ") : (cout << "\n");
    }
}
