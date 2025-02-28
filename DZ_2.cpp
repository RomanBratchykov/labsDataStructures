#include <iostream>

void fillArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        arr[i] = rand() % 201-100;
    }
}

void bubbleSort(int* ptr, int size, std::string order = "asc"){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (*(ptr + j) > *(ptr + j + 1) && order == "asc"){
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
            else if (*(ptr + j) < *(ptr + j + 1) && order == "desc"){
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
}
int main()
{
    while (1){
        std::cout <<"choose task(1-3, 0 for exit)\n";
        int num;
        std::cin >> num;
        if (num == 0){
            return 0;
        }

        switch (num){
            case 1:
        {
        std::cout << "Enter the size of the array: \n";
        int size;
        std::cin >> size;
        int arr[size];
        fillArray(arr, size);
        std::cout << "Enter k(if element is multiple of k delete it)\n";
        int k;
        std::cin >> k;
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size - i - 1; j++){
                if (arr[j] % k == 0){
                    for (int l = j; l < size - 1; l++){
                        int temp = arr[l];
                        arr[l] = arr[l + 1];
                        arr[l + 1] = temp;
                    }
                    size--;
                }
            }
        }
        bubbleSort(arr, size, "desc");
        for (int i = 0; i < size; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
        break;
        case 2:
        {
            std::cout << "Enter the size of the array: \n";
            int size;
            std::cin >> size;
            int arr[size];
            fillArray(arr, size);
            std::cout << "Array: ";
                for (int i = 0; i < size; i++)
                    {
                        std::cout << arr[i]<< " ";
                    }
            std::cout << "\n";
            int min = arr[0];
            for (int i = 1; i < size; i++){
                if (arr[i] < min){
                    min = arr[i];
                }
            }
            int counter = 0;
            for (int i = 0; i < size; i++){
                if (arr[i] - arr[i] / 100 * 100 == 3 )
                {
                    counter++;
                }
            }
            int j = 0;
            int newArray[size + counter];
            for (int i = 0; i < size; i++){
                newArray[j] = arr[i];
                j++;
                if (arr[i] - ((arr[i] / 10) * 10) == 3){
                    newArray[j] = min;
                    j++;
                }
            }
            std::cout<<"New array: \n";
            for (int i = 0; i < size + counter; i++){
                std::cout << newArray[i] << " ";
            }
        }
        break;
        case 3:
        {
            
        }
        default:
        {
            std::cout << "Invalid input\n";
        };
        break;
    }
}
}