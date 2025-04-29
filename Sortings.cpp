#include <iostream>
#include <random>
#include <cstdint>
#include <utility> 

void InputArray(int32_t*, int32_t);
void PrintArray(int32_t*, int32_t);
bool IsSorted(int32_t*, int32_t); 
void BogaSort(int32_t*, int32_t);
void BubbleSort(int32_t*, int32_t);
void ShakeSort(int32_t*, int32_t);
void CombSort(int32_t*,int32_t);
void InsertionSort(int32_t*,int32_t);
void SelectionSort(int32_t*,int32_t);
void BinarySearch(int32_t*,int32_t);

int main() {
    int32_t size{}; 
    std::cout << "Input size of array: ";
    std::cin >> size;
    
    int32_t* array = new int32_t[size]; 
    InputArray(array, size);
    
    char choice{};
    std::cout << "Input choice of sorting:\n1. BogaSort\n2. BubbleSort\n3. ShakeSort\n4. CombSort\n5. InsetrionSort\n6. SelectionSort\n7. Binarysearch\n Choice: ";
    std::cin >> choice;
    
    switch(choice) {
        case '1': 
            BogaSort(array, size);
            PrintArray(array, size);
            break;

        case '2':
            BubbleSort(array, size);
            PrintArray(array, size);
            break;

        case '3':
            ShakeSort(array,size);
            PrintArray(array,size);
            break;

        case '4':
            CombSort(array,size);
            PrintArray(array,size);
            break;

        case '5':
            InsertionSort(array,size);
            PrintArray(array,size);
        break;

        case '6':
            SelectionSort(array,size);
            PrintArray(array,size);
        break;

        case '7':
        if(!IsSorted(array,size))
        {
            BubbleSort(array,size);
            BinarySearch(array,size);
            break;
        }
        else{
            BinarySearch(array,size);
            break;
        }
        default:
            std::cout << "Incorrect answer, try again" << std::endl;
            break;
    }
    
    delete[] array; 
    return 0;
}

void InputArray(int32_t* array, int32_t size) {
    std::cout << "Input array elements" << std::endl;
    for(int32_t i = 0; i < size; ++i) { 
        std::cout << "Element " << i+1 << ": ";
        std::cin >> array[i];
    }
}

void PrintArray(int32_t* array, int32_t size) {
    std::cout << "Sorted array: ";
    for (int32_t i = 0; i < size; ++i) {
        std::cout << array[i] << " "; 
    }
    std::cout << std::endl;
}

bool IsSorted(int32_t* array, int32_t size) {
    for (int32_t i = 0; i < size - 1; ++i) { 
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

void BogaSort(int32_t* array, int32_t size) {
    int32_t counter = 0;
    while(!IsSorted(array, size)) { 
        std::random_device rd;
        std::mt19937 gen(rd());
        for (int32_t i = size - 1; i > 0; --i) {
            std::uniform_int_distribution<int32_t> dist(0, i);
            int32_t j = dist(gen);
            std::swap(array[i], array[j]);
        }
        ++counter;
    }
    std::cout << "Shuffles performed: " << counter << std::endl;
}

void BubbleSort(int32_t* array, int32_t size) {
    int32_t counter = 0;
    if (!IsSorted(array,size)){
    for (int32_t i = 0; i < size - 1; ++i) { 
        for (int32_t j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                ++counter;
            }
        }
    }
}
else {
    std::cout<< "Array is sorted" <<std::endl;
}
    std::cout << "Swaps performed: " << counter << std::endl;
}

void ShakeSort(int32_t* array, int32_t size) {
    int32_t counter = 0;
    int32_t start = 0;
    int32_t end = size - 1;
    
    while (start != end) {
        for (int32_t i = start; i < end; ++i) {
            if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
                ++counter;
            }
        }
        
        for (int32_t j = end - 1; j >= start; --j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                ++counter;
            }
        }
        ++start; 
    }
    std::cout << "Swaps performed: " << counter << std::endl;
}
void CombSort(int32_t* array, int32_t size) {
    int32_t gap = size; 
    int32_t counter = 0;
    while (gap > 1) {
        gap = static_cast<int32_t>(gap / 1.247);    
        for (int32_t i = 0; i < size - gap; ++i) {
            if (array[i] > array[i + gap]) {
                std::swap(array[i], array[i + gap]);
                ++counter;
            }
        }
    }

    std::cout << "Swaps performed: " << counter << std::endl;
}
void InsertionSort(int32_t* array, int32_t size){
    int32_t counter{};
    for (int32_t i = 1; i < size; ++i) {
        int32_t key = array[i]; 
        int32_t j = i - 1;  
        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            --j;
            ++counter;
        }
        
        array[j + 1] = key; 
    }
    std::cout << "Swaps performed: " << counter << std::endl;
    }

    void SelectionSort(int32_t* array, int32_t size){
        int32_t counter{};
        
        while(!IsSorted(array,size)){
            for(int32_t i{};i<size-1;++i){
            int32_t min_idx = i; 
        
           
            for (int32_t j = i + 1; j < size; ++j) {
                if (array[j] < array[min_idx]) {
                    min_idx = j;
                }
            }
          
            if (min_idx != i) {
                std::swap(array[i], array[min_idx]);
                ++counter;
            }
        }
    }
        std::cout << "Swaps performed: " << counter << std::endl;
    }
    
    

    void BinarySearch( int32_t* array, int32_t size) {
        int32_t target{};
        std::cout << "Which element do you want to find? ";
        std::cin >> target;
    
    int32_t left = 0;
    int32_t right = size - 1;
    bool found = false;
    
    while (left <= right) {
        int32_t mid = left + (right - left) / 2;
        
        if (array[mid] == target) {
            std::cout << "The position of target is: " << mid << std::endl;
            found = true;
            break;
        }
        else if (array[mid] < target) {
            left = mid + 1;  
        }
        else {
            right = mid - 1;  
        }
    }
    
    if (!found) {
        std::cout << "The target wasn't found!" << std::endl;
    }
}
    

    
