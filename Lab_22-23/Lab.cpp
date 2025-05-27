#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <ctime>
#include <list>
#include <set>
int main(){
    srand(time(0));
    while (1){
        std::cout << "Enter number of task(1-5, 0 to exit): \n";
        int task;
        std::cin >> task;
        switch(task){
            case 0:
            {
                return 0;
            }
            case 1:{
                std::ifstream file("file.txt");
                if (!file.is_open()){
                    std::cout << "File not found\n";
                    return 0;
                }
                std::cout << "Enter how much numbers you want to be in vector: \n";
                int numbers;
                std::cin >> numbers;
                int count = 0;
                std::vector<int> numbersVector;
                std::string line;
                while (std::getline(file, line)){
                    std::stringstream ss(line);
                    int number;
                    if (count == numbers) break;
                    while (ss >> number){
                        if (count == numbers) break;
                        numbersVector.push_back(number);
                        count++;
                    }
                }
                std::cout << "Numbers in vector: \n";
                for (int i = 0; i < numbersVector.size(); i++){
                    std::cout << numbersVector[i] << " ";
                }
                std::cout << "\n";
                int third = numbersVector.size() / 3;
                std::sort(numbersVector.begin(), numbersVector.begin() + third);
                std::sort(numbersVector.begin() + third, numbersVector.end(), std::greater<int>());
                std::cout << "Sorted vector: \n";
                for (int i = 0; i < numbersVector.size(); i++){
                    std::cout << numbersVector[i] << " ";
                }
                std::cout << "\n";
                numbersVector.erase(std::remove_if(numbersVector.begin(), numbersVector.end(), [](int x) {
                    return x >= -5 && x <= 5;
                }), numbersVector.end());
                std::cout << "Vector after erasing elements between -5 and 5: \n";
                for (int i = 0; i < numbersVector.size(); i++){
                    std::cout << numbersVector[i] << " ";
                }
                std::cout << "\n";
                numbersVector.erase(std::unique(numbersVector.begin(), numbersVector.end()), numbersVector.end());
                std::cout << "Vector with deleted elements: \n";
                for (int i = 0; i < numbersVector.size(); i++){
                    std::cout << numbersVector[i] << " ";
                }
                std::cout << "\n";
                std::partition(numbersVector.begin(), numbersVector.end(), [](int x){ return x >= 10; });
                std::cout << "Vector with after partition: \n";
                for (int i = 0; i < numbersVector.size(); i++){
                    std::cout << numbersVector[i] << " ";
                }
                std::cout << "\n";
                  auto it_split = std::find_if(numbersVector.begin(), numbersVector.end(), [](int x) {
                    return x >= 10;
                });
                std::transform(numbersVector.begin(), it_split, numbersVector.begin(), [](int x) {
                    return x + 100;
                });
                auto min = *std::min_element(numbersVector.begin(), numbersVector.end());
                auto max = *std::max_element(numbersVector.begin(), numbersVector.end());
                std::transform(numbersVector.begin(), numbersVector.end(),numbersVector.begin(), [=](int x){
                    if (x > 100){
                        x = max;
                    }
                    else if (x < -100){
                        x = min;
                    }
                    return x;
                });
                std::cout << "Vector after transforming: \n";
                for (int i = 0; i < numbersVector.size(); i++){
                    std::cout << numbersVector[i] << " ";
                }
                std::cout << "\n";
            }
            break;
            case 2:{
                std::ifstream file("fileNames.txt");
                if (!file.is_open()){
                    std::cout << "File not found\n";
                    return 0;
                }
                std::string line;
                std::vector<std::string> names;
                while (std::getline(file, line)){
                    std::stringstream ss(line);
                    std::string name;
                    while (ss >> name){
                        names.push_back(name);
                    }
                }
                for (auto element : names){
                    std::cout << element << " ";
                }
                std::cout << "\n";
            }
            break;
            case 3:{
                std::list<int> numbersList;
                std::cout << "Enter how much numbers you want to be in list: \n";
                int numbers;
                std::cin >> numbers;
                for (int i = 0; i < numbers; i++){
                    int number;
                    std::cout << "Enter number " << i + 1 << ": ";
                    std::cin >> number;
                    numbersList.push_back(number);
                }
                for (std::list<int>::iterator i = numbersList.begin(); i != numbersList.end(); i++){
                    std::cout << *i << " ";
                }
                std::cout << "\n";
                std::list<int> randNums;
                for (int i = 0; i < numbers; i++){
                    int number = rand() % 10;
                    randNums.push_back(number);
                }
                for (std::list<int>::iterator i = randNums.begin(); i != randNums.end(); i++){
                    std::cout << *i << " ";
                }
                std::cout << "\n";
                numbersList.sort(std::greater<int>());
                randNums.sort(std::greater<int>());
                numbersList.merge(randNums, std::greater<int>());
                std::cout << "Merged list: \n";
                for (std::list<int>::iterator i = numbersList.begin(); i != numbersList.end(); i++){
                    std::cout << *i << " ";
                }
                std::cout << "\n";
                std::list<int> uniques = numbersList;
                uniques.unique();
                std::cout << "Number of unique elements: " << uniques.size() << "\n";
            }
            break;
            case 4:{

            }
            break;
            case 5:{

            }
            break;
        }
    }
    return 0;
}