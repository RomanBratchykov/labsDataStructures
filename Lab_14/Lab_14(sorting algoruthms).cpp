#include <iostream>

void fillArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }
}
void printArray(int* arr, int size){
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
//Саме базове сортування яке можна придумати, неоптимізоване, але працює. О(n^2) - часова складність. Дуже багато непотрібних перестановок
void bubbleSort(int* arr, int size){
    int counter = 0, swaps = 0;
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            counter++;
            if (arr[j] > arr[j + 1]){
                std::swap(arr[j], arr[j + 1]); 
                swaps++;
            }
        }
    }
    std::cout << "Number of steps " << counter << "\n";
    std::cout << "Number of swaps " << swaps << "\n";
}

//сортування вставками. часова складність O(n^2), але вигідніша по використанню ресурсів ніж бульбашкова не використувує свап а вставляє елемент в необхідну позицію. всі логи показують як він проходить по індесам та елементам
void insertionSort(int* arr, int size){
    int counter = 0, insert = 0;
    for (int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        while ( j >= 0 && arr[j] > key){
            counter++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        insert++;
    }
    std::cout << "Number of steps " << counter << "\n";
    std::cout << "Number of inserts " << insert << "\n";
}

/*Сортування вибором, не складне за написанням. складність О(n^2), але потребує менше ресурсів комп'ютера через те що обмін відбувається лише n разів
    працює за методом проходження масиву та знаходження елемента який відповідає умові і тільки після цього свапати його на перевірене місце. Непоганий для невеликих масивів.
*/
void selectionSort(int* arr, int size){
    int counter = 0, swaps = 0; 
    for (int i = 0; i < size; i++){
        int index = i;
        for (int j = i + 1; j < size; j++){
            counter++;
            if (arr[j] < arr[index]){
                index = j;
            }
        }
        if (index != i){
            std::swap(arr[i], arr[index]);
            swaps++;
        }
    }
    std::cout << "Number of steps " << counter << "\n";
    std::cout << "Number of swaps " << swaps << "\n";
}

/*алгоритм для навчання, має багато непотрібних кроків та працює за методом проходження масиву та за умови 
того що наступний елемент більший/менший за поточний міняє їх місцями та іде на крок назад щоб перевірити таку саму умову, доки елемент точно не стане на позицію де минулий елемент більший/менший. 
складність O(n^2), використовує багато ресурсів пк.
*/
void gnomeSort(int* arr, int size){
    int index = 0, counter = 0, swaps = 0;
    while (index < size){
        counter++;
        if (index == 0)  index++;
        if (arr[index] >= arr[index - 1]) index++;
        else {
            std::swap(arr[index], arr[index - 1]);
            swaps++;
            index--;
        }
    }
    std::cout << "Number of steps " << counter << "\n";
    std::cout << "Number of swaps " << swaps << "\n";
}

/*Часова складність O(nlog(n)) що є досить непоганою для великих та середніх масивів*/
void heap(int* arr, int size, int index){
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]){
        largest = right;
    }
    if (largest != index){
        std::swap(arr[index], arr[largest]);
        heap(arr, size, largest);
    }
}

void heapSort(int* arr, int size){
    int counter = 0;
    for (int i = size / 2 - 1; i >= 0; i--){
        heap(arr, size, i);
    }

    for (int i = size - 1; i >= 0; i--){
        std::swap(arr[0], arr[i]);
        heap(arr, i, 0);
    }
}
/*Сортування злиттям - один з найшвидших сортувальних алгоритмів, але він займає багато пам'яті бо сортування відбувається за принципом створення невеликих масивів в якому вже елементи сортуються
найкраще показує себе на великих та середніх масивах, але його краще використовувати на потужних комп'ютерах. Складність O(nlogn)*/
void merge(int* arr, int left, int mid, int right){
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int* leftArr = new int[size1];
    int* rightArr = new int[size2];

    for (int i = 0; i < size1; i++){
        leftArr[i] = arr[left + i];
    }

    for (int i = 0; i < size2; i++){
        rightArr[i] = arr[mid+ i + 1];
    }
    int i = 0, j = 0, k = left;

    while (i < size1 && j < size2){
        if (leftArr[i] <= rightArr[j]){
            arr[k++] = leftArr[i++];
        }
        else{
            arr[k++] = rightArr[j++];
        }
    }

    while (i < size1){
        arr[k++] = leftArr[i++];
    }

    while(j < size2){
        arr[k++] = rightArr[j++];
    }
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int* arr, int left, int right){
    if (left < right){
        int mid = (right + left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
/*Непоганий алгоритм сортування, найкраще підходить для середніх масивів. Складність в середньому випадку O(Log^2(n)) але в найгіршому може бути і O(n^2)
працює як сортування вставками але використовує принцип того що спочатку сортуються найдвіддаленіші елементи і потрошку скорочується відстань */
void shellSort(int* arr, int size){
    int counter = 0;
    for (int gap = size/2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
                counter++;
            }
            arr[j] = temp;
        }
    }
    std::cout << "Number of steps " << counter << "\n";
}
/*швидке сортування відбувається за схожим принципом як і алгоритм сортування злиттям, але його основна ідея це знаходження основного елементу навколо якого будуть робитись всі обрахунки
(знаходимо елемент і вже в залежності від того чи наступні елементи більші за нього чи менші сортуємо). В середньому складність O(nlogn)*/
int partition(int* arr, int start, int end){
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++){
        if (arr[j] <= pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quickSort(int* arr, int start, int end){
    if (start < end){
        int pivotIndex = partition(arr, start, end);

        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
} 
int main(){
    srand(time(0));
    std::cout << "Enter size of array\n";
    int size;
    std::cin >> size;
    int* arr = new int[size];
    fillArray(arr, size);
    std::cout << "Your array:\n";
    printArray(arr, size);
    std::cout << "Choose sorting method(1 - bubble, 2 - insertion, 3 - selection, 4 - gnome, 5 - heap, 6 - Shell, 7 - quick sort, 8 - merge)\n";
    int choice;
    std::cin >> choice;
    switch (choice){
        break;
        case 1:
            bubbleSort(arr, size);
            std::cout << "Your sorted array(bubble):\n";
            printArray(arr, size);
        break;
        case 2:
            insertionSort(arr, size);
            std::cout << "Your sorted array(insertion):\n";
            printArray(arr, size);
        break;
        case 3:
            selectionSort(arr, size);
            std::cout << "Your sorted array(selection):\n";
            printArray(arr, size);
        break;
        case 4:
            gnomeSort(arr, size);
            std::cout << "Your sorted array(gnome):\n";
            printArray(arr, size);
        break;
        case 5:
            heapSort(arr, size);
            std::cout << "Your sorted array(heap):\n";
            printArray(arr, size);
        break;
        case 6:
            shellSort(arr, size);
            std::cout << "Your sorted array(shell):\n";
            printArray(arr, size);
        break;
        case 7:
            quickSort(arr, 0, size - 1);
            std::cout << "Your sorted array(quick):\n";
            printArray(arr, size);
        break;
        case 8:
            mergeSort(arr, 0, size - 1);
            std::cout << "Your sorted array(merge):\n";
            printArray(arr, size);
        break;
        default:{
            std::cout << "wrong choice\n";
        }
        break;
    }
}