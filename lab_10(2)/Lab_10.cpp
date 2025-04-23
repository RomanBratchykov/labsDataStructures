#include <iostream>
#include <vector>
#include <list>

int getSum(std::vector<int> vec){
    int sum = 0;
    for (auto element : vec){
        sum += element;
    }
    return sum;
}

struct Car{
    std::string name;
    int year;
    int runningTotal;
    Car(std::string name, int year, int runningTotal){
        this->name = name;
        this->year = year;
        this->runningTotal = runningTotal;
    }
};
int main(){
    srand(time(0));
    while (1){
        std::cout << "Enter task(1-3, 0 for exit): \n";
        int task;
        std::cin >>task;
        if (task == 0) break;
        switch(task){
            case 1: {
                std::vector<int> numbers;
                std::cout << "Enter how much numbers you want:\n";
                int num;
                std::cin >> num;
                if (num < 1){
                    std::cout << "Vector should have at least 1 element\n";
                    break;
                }
                for (int i = 0; i < num; i++){
                    std::cout << "Enter " << i + 1 << " number\n";
                    int numberToEnter;
                    std::cin >> numberToEnter;
                    numbers.push_back(numberToEnter);
                }
                std::cout << "Your vector:\n";
                for (auto element : numbers){
                    std::cout << element << " ";
                }
                std::cout << "\n";
                if (num < 2){
                    std::cout << "Your vector doesn't have second element\n";
                }   
                else{
                    numbers[1] = 10;
                    std::cout << "Your vector after changing second element to 10:\n";
                    for (auto element : numbers){
                    std::cout << element << " ";
                    }
                    std::cout << "\n";
                }
                numbers.pop_back();
                std::cout << "Your vector after deleting last element:\n";
                    for (auto element : numbers){
                    std::cout << element << " ";
                    }
                    std::cout << "\n";
                numbers.insert(numbers.begin(), 25);
                std::cout << "Your vector after adding 25 at start:\n";
                    for (auto element : numbers){
                    std::cout << element << " ";
                    }
                    std::cout << "\n";
            }
            break;
            case 2:{
                std::vector<std::vector<int>> matrix;
                std::cout << "Enter size of matrix:\n";
                int size;
                std::cin >> size;
                if (size < 1){
                    std::cout << "Vector should have at least 1 element\n";
                    break;
                }
                for (int i = 0; i < size; i++){
                    std::vector<int> vec;
                    matrix.push_back(vec);
                }
                for (auto& row : matrix)
                    for (int j = 0; j < size; j++)
                        row.push_back(rand() % 8 + 1);
                

                for (auto& row : matrix){
                    for (auto element : row){
                        std::cout << element << " ";
                    }
                    std::cout << "\n";
                }

                int counter = 0;
                for (auto& row : matrix){
                    std::cout << "sum of " << ++counter << " row is " << getSum(row) << "\n"; 
                }
            }
            break;
            case 3:{
                std::list<Car> cars;
                while (1){
                std::cout << "Enter task 1-8, 9 to exit\n";
                int task;
                std::cin >> task;
                if(task == 9){
                    break;
                }
                switch(task){
                    case 1:{
                        std::cout << "Enter name, year and running total of car\n";
                        std::string name1;
                        int year1, runningTotal1;
                        std::cin.ignore();
                        std::getline(std::cin, name1);
                        std::cin >> year1 >> runningTotal1;
                        cars.push_back(Car(name1, year1, runningTotal1));
                    }
                    break;
                    case 2:{
                        std::cout << "Enter name, year and running total of car\n";
                        std::string name;
                        int year, runningTotal;
                        std::cin.ignore();
                        std::getline(std::cin, name);
                        std::cin >> year >> runningTotal;
                        Car car1 = Car(name, year, runningTotal);
                        cars.insert(cars.begin(), car1);
                    }
                    break;
                    case 3:
                    {
                        std::cout << "Enter name, year and running total of car\n";
                        std::string name;
                        int year, runningTotal;
                        std::cin.ignore();
                        std::getline(std::cin, name);
                        std::cin >> year >> runningTotal;
                        Car car1 = Car(name, year, runningTotal);
                        cars.insert(cars.end(), car1);
                    }
                    break;
                    case 4:
                    {
                        std::cout << "Enter name, year and running total of car, and index of element after one you want insert\n";
                        std::string name;
                        int year, runningTotal, index;
                        std::cin.ignore();
                        std::getline(std::cin, name);
                        std::cin >> year >> runningTotal;
                        Car car1 = Car(name, year, runningTotal);
                        std::cin >> index;
                        cars.insert(cars.begin() + index, car1);
                    }
                    break;
                    case 5:
                    {
                        std::cout << "Enter name, year and running total of car, and index of element before one you want insert\n";
                        std::string name;
                        int year, runningTotal, index;
                        std::cin.ignore();
                        std::getline(std::cin, name);
                        std::cin >> year >> runningTotal;
                        Car car1 = Car(name, year, runningTotal);
                        std::cin >> index;
                        cars.insert(cars.begin() + index - 1, car1);
                    }
                    break;
                    case 6:{
                        std::cout << "Enter name of car\n";
                        std::string name;
                        std::cin >> name;
                        int counter = 0;
                        for (auto& element : cars){
                            if (element.name == name){
                                counter++;
                                std::cout << element.name << " " << element.year << " " << element.runningTotal << "\n";
                            }
                        }
                        if (counter == 0){
                            std::cout << "there is no cars with that name\n";
                        }
                    }
                    break;
                    case 7:
                    {
                        std::cout << "Enter year of car to delete\n";
                        int year;
                        std::cin >> year;
                        int counter = 0;
                        for (auto& element : cars){
                            counter++;
                            if (element.year == year){
                                cars.erase(cars.begin() + counter);
                            }
                        }
                    }
                    break;
                    case 8:
                        std::cout << "vector of cars\n";
                        for (auto& element : cars){
                            std::cout << element.name << " " << element.year << " " << element.runningTotal << "\n";
                        }
                    break;
                    default:
                        std::cout << "Invalid choice\n";
                    break;
                }
            }
            }
            break;
            default: 
                std::cout << "Invalid task\n";
            break;
        }
    }
}