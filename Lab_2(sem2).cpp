#include <iostream>

void fillArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 - 50;
    }
}

void fillArrayUniques(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 - 50;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] == arr[i])
            {
                i--;
            }
        }
    }
}

void bubbleSort(int arr[], int size, std::string order = "asc"){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j + 1] && order == "asc"){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            else if (arr[j] < arr[j + 1]  && order == "desc"){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main() {
    srand(time(0));
    while(1) {
        int num;
        std::cout << "Enter number of task(1-4, 0 for exit): \n";
        std::cin >> num;
         switch(num)
           {
            case 0:
                return 0;
            case 1:
            {
                int size;
                std::cout << "Enter size of array: ";
                std::cin >> size;
                int array[size];
                fillArray(array, size);
                std::cout << "Array: ";
                    for (int i = 0; i < size; i++)
                    {
                        std::cout << array[i] << " ";
                    }
                    std::cout << "\n";
                int evenCount = 0;
                int oddCount = 0;
                for (int i = 0; i < size; i++){
                    if (array[i] % 2 == 0){
                        evenCount++;
                    }
                    else{
                        oddCount++;
                    }
                }
                int indexEven = 0;
                int indexOdd = 0;
                int evenArr[evenCount];
                int oddArr[oddCount];
                for (int i = 0; i < size; i++){
                    if(array[i] % 2 == 0){
                        evenArr[indexEven++] = array[i];
                    }
                    else{
                        oddArr[indexOdd++] = array[i];
                    }
                }
                bubbleSort(evenArr, evenCount, "asc");
                bubbleSort(oddArr, oddCount, "desc");
                int final_index = 0;
                int finalArr[size];
                for (final_index; final_index < evenCount; final_index++) {
                    finalArr[final_index] = evenArr[final_index];
                }
                for (int i = 0; i < oddCount; i++) {
                    finalArr[final_index++] = oddArr[i];
                }

                std::cout << "New array: ";
                for (int i = 0; i < size; i++){
                    std::cout << finalArr[i] << " ";
                }
                std::cout << "\n";
            }
            break;
            case 2:
            {
                int size;
                std::cout << "Enter size of array: ";
                std::cin >> size;
                int array[size];
                fillArrayUniques(array, size);
                std::cout << "Array: ";
                    for (int i = 0; i < size; i++)
                    {
                        std::cout << array[i] << " ";
                    }
                std::cout << "\n";
                std::cout << "Enter number x(if number lower than x - delete): \n";
                int x;
                int counter = 0;
                std::cin >> x;
                for (int i = 0; i < size; i++){
                    if (array[i] <= x)
                    {
                        counter++;
                    }
                }

                int newIndex = 0;
                for (int i = 0; i < size; i++){
                    if (array[i] > x)
                    {
                        array[newIndex++] = array[i];
                    }
                }
                for (int i = size - counter; i < size; i++){
                    array[i] = 0;
                }
                std::cout << "New array: ";
                for (int i = 0; i < size; i++){
                    std::cout << array[i] << " ";

                }
                std::cout << "\n";
            }
            break;
            case 3:
            {
                int size;
                std::cout << "Enter size of array: ";
                std::cin >> size;
                int matrix[size][size];
                for (int i = 0; i < size; i++){
                    fillArray(matrix[i], size);
                }
                std::cout << "Matrix: \n";
                for (int i = 0; i < size; i++){
                    for (int j = 0; j < size; j++){
                        std::cout << matrix[i][j] << " ";
                    }
                    std::cout << "\n";
                }
                int max = matrix[0][0];
                int maxIndexI = 0, maxIndexJ = 0;
                for (int i = 0; i < size; i++){
                    for (int j = 0; j < size - 1; j++){
                        if (matrix[i][j] > max){
                            max = matrix[i][j];
                            maxIndexI = i;
                            maxIndexJ = j;
                        }
                    }
                }
                std::cout << "Max element: " << max << "\n";
                int temp = matrix[maxIndexI][maxIndexJ];
                matrix[maxIndexI][maxIndexJ] = matrix[0][maxIndexJ];
                matrix[0][maxIndexJ] = temp;
                maxIndexI = 0;
                std::cout << "New matrix: \n";
                for (int i = 0; i < size; i++){
                    for (int j = 0; j < size; j++){
                        std::cout << matrix[i][j] << " ";
                    }
                    std::cout << "\n";
                }
                int secondTemp = matrix[maxIndexI][maxIndexJ];
                matrix[maxIndexI][maxIndexJ] = matrix[maxIndexI][0];
                matrix[maxIndexI][0] = secondTemp;
                maxIndexJ = 0;
                std::cout << "Final matrix: \n";
                for (int i = 0; i < size; i++){
                    for (int j = 0; j < size; j++){
                        std::cout << matrix[i][j] << " ";
                    }
                    std::cout << "\n";
                }
            }
            break;
            case 4:
            {
                int size;
                std::cout << "Enter size of array: ";
                std::cin >> size;
                int matrix[size][size];
                for (int i = 0; i < size; i++){
                    fillArray(matrix[i], size);
                }
                std::cout << "Matrix: \n";
                for (int i = 0; i < size; i++){
                    for (int j = 0; j < size; j++){
                        std::cout << matrix[i][j] << " ";
                    }
                    std::cout << "\n";
                }

                for (int i = 0; i < size; i++){
                    for (int j = 0; j < size - 1 ; j++){
                        if (i == j){
                            for (int k = j; k < size - 1; k++){
                                int temp = matrix[i][k];
                                matrix[i][k] = matrix[i][k + 1];
                                matrix[i][k + 1] = temp;
                            }
                        }
                    }
                }
                int max = matrix[0][0];
                int maxIndexI = 0;
                for (int i = 0; i < size; i++){
                    for (int j = 0; j < size - 1; j++){
                        if (matrix[i][j] > max){
                            max = matrix[i][j];
                            maxIndexI = i;
                        }
                    }
                }
                
                for (int i = maxIndexI; i < size; i++){
                    for (int j = 0; j < size - 1; j++){
                        int temp = matrix[i][j];
                        matrix[i][j] = matrix[i + 1][j];
                        matrix[i + 1][j] = temp;
                    }
                }
                size--;
                std::cout << "New matrix: \n";
                for (int i = 0; i < size; i++){
                    for (int j = 0; j < size; j++){
                        std::cout << matrix[i][j] << " ";
                    }
                    std::cout << "\n";
                }
            }
            break;
            default:
                std::cout << "Invalid number of task\n";
            break;
            }
        }
return 0;
}