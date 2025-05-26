#include <iostream>
#include <vector>
#include <iomanip>
const int MAX_SALARY = 380000;
struct Position{
    std::string name;
    int coefficient;
    int count;
    double salaryPerPerson;
    double totalSalary;
};
int main(){
    std::cout << "Enter number of task(1-2, 0 for exit): \n";
    int task;
    std::cin >> task;
    if (task == 0){
        return 0;
    }
    switch(task){
        case 1:{
            std::vector<Position> positions = {
        {"Cleaner", 1, 7},
        {"Nurse", 2, 10},
        {"Doctor", 4, 10},
        {"Head of Pharmacy", 5, 1},
        {"Department Head", 6, 3},
        {"Chief Doctor", 8, 1},
        {"Head of Operations", 3, 1},
        {"Hospital Manager", 7, 1}
    };

    int totalCoefficient = 0;
    for (const auto& pos : positions) {
        totalCoefficient += pos.coefficient * pos.count;
    }

    double baseSalary = MAX_SALARY / totalCoefficient;

    for (auto& pos : positions) {
        pos.salaryPerPerson = baseSalary * pos.coefficient;
        pos.totalSalary = pos.salaryPerPerson * pos.count;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Base Salary: " << baseSalary << " UAH\n\n";
    std::cout << std::left << std::setw(20) << "Position"
         << std::setw(10) << "Count"
         << std::setw(12) << "Coeff."
         << std::setw(22) << "Salary per Person"
         << std::setw(20) << "Total Salary" << "\n";

    std::cout << std::string(80, '-') << "\n";

    for (const auto& pos : positions) {
        std::cout << std::setw(20) << pos.name
             << std::setw(10) << pos.count
             << std::setw(12) << pos.coefficient
             << std::setw(22) << pos.salaryPerPerson
             << std::setw(20) << pos.totalSalary << "\n";
    }

        }
        break;
        case 2:{
            std::vector<int> stocks = {1500, 1900, 1600};
            std::vector<int> need = {1800, 1200, 2000};
            std::vector<std::vector<int>> matrix = {{8, 7, 2},
                                                    {1, 4, 3},
                                                    {5, 1, 6}};
            int sum = 0;
            std::cout << "choose algorythm(1 - northwest corner, 2 - minimal value):\n";
            int choice;
            std::cin >> choice;
            if (choice != 1 && choice != 2){
                std::cout << "invalid choice\n";
                return 0;
            }
            if (choice == 1){

            }
        }
        break;
        default:{
            std::cout << "invalid choice\n";
            return 0;
        }
    }
    return 1;
}
