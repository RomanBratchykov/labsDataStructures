#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <time.h>
#include <fstream>

bool checkIfMultipleOf(int number, int multiple){
    if (number % multiple == 0){
        return true;
    }
    else{
        return false;
    }
}

void fillArrayRandom(float *arr, int size){
    float minValue = -1.50, maxValue = 4.50;
    for (int i = 0; i < size; i++){
        arr[i] = minValue + (((float)rand() / ((float)RAND_MAX) * (maxValue - minValue)));
    }
}

void showArray(float arr[], int size){
    for (int i = 0; i < size; i++){
        std::cout <<std::fixed<<std::setprecision(2)<< arr[i] << " ";
    }
    std::cout << "\n";
}
//Third parameter is order in which way sort(set ascending by default, if you want descending, set "desc")
void bubbleSort(float arr[], int size, std::string order = "asc"){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j + 1] && order == "asc"){
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            else if (arr[j] < arr[j + 1] && order == "desc"){
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

float findMax(float arr[], int size){
        float max = arr[0];
        for (int i = 1; i < size; i++){
            if (arr[i] > max){
                max = arr[i];
            }
        }
        return max;
}

void arrayToMatrix(float arr[], int size, float matrix[][4]){
    for (int i = 0; i < size; i++){
        matrix[i / 4][i % 4] = arr[i];
    }
}

void sortMatrix(float matrix[][4], int size){
    for (int i = 0; i < size / 4; i++){
        if (i % 2 == 0 && i != 0){
            bubbleSort(matrix[i], 4, "desc");
            }
        else{
            bubbleSort(matrix[i], 4);
        }
    }
}

void showMatrix(float matrix[][4], int size){
    for (int i = 0; i < size / 4; i++){
        for (int j = 0; j < 4; j++){
            std::cout << std::fixed << std::setprecision(2) << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}



int main() {
    clock_t start = clock();
    int i = 0;
    std::ofstream textfile("output.txt");
    !textfile ? std::cerr << "file not opened\n" : std::cout << "file opened\n";
    textfile << "№\tn\tTime, sec.\tSpace, byte\n";
    srand(time(0));
    while (1){
    int size;
    std::cout << "enter size of array: (0 to exit)\n";
    std::cin >> size;
    if (size == 0){
        break;
    }

    if (!checkIfMultipleOf(size, 4)){
        std::cout << "size should be multiple of 4\n";
        break;
    }
    float firstDimensionArray[size];
    fillArrayRandom(firstDimensionArray, size);
    float sortedArray[size];
    for (int i = 0; i < size; i++){
        sortedArray[i] = firstDimensionArray[i];
    }
    showArray(firstDimensionArray, size);
    bubbleSort(sortedArray, size);
    std::cout << "sorted array: \n";
    showArray(sortedArray, size);
    std::cout << "max element: " << findMax(firstDimensionArray, size) << "\n";
    float matrix[size / 4][4];
    std::cout << "array to matrix: \n";
    arrayToMatrix(firstDimensionArray, size, matrix);
    showMatrix(matrix, size);
    std::cout << "max element in each row: \n";
    for (int i = 0; i < size / 4; i++){
        std::cout << i + 1 <<" row: "<<findMax(matrix[i], 4) << " \n";
    } 
    std::cout << "sorted matrix: \n";
    sortMatrix(matrix, size);
    showMatrix(matrix, size);

    clock_t end = clock();
    double time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "time: " << time_elapsed << "s\n";
    size_t memory_size = size * sizeof(float);
    textfile << i + 1 << "\t" << size << "\t   " << time_elapsed << "\t        " << memory_size << "\n";
    
}
    textfile.close();
    std::cout << "data saved to file and file closed\n";
    return 0;
}