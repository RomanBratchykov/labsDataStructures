#include <iostream>
#include <vector>
#include <iomanip>
const int MAX_SALARY = 380000;
const int WAREHOUSES = 3;
const int STORES = 3;
struct Position{
    std::string name;
    int coefficient;
    int count;
    double salaryPerPerson;
    double totalSalary;
};

void northwestCorner(const std::vector<int>& supply, const std::vector<int>& demand, const std::vector<std::vector<int>>& prices) {
    std::vector<std::vector<int>> allocation(WAREHOUSES, std::vector<int>(STORES, 0));
    std::vector<int> s = supply;
    std::vector<int> d = demand;

    int i = 0, j = 0;
    int totalCost = 0;

    while (i < WAREHOUSES && j < STORES) {
        int qty = std::min(s[i], d[j]);
        allocation[i][j] = qty;
        totalCost += qty * prices[i][j];
        s[i] -= qty;
        d[j] -= qty;

        if (s[i] == 0) i++;
        else if (d[j] == 0) j++;
    }

    std::cout << "North-West Corner Allocation:\n";
    for (const auto& row : allocation) {
        for (int val : row)
            std::cout << std::setw(6) << val;
        std::cout << '\n';
    }

    std::cout << "\nTotal transportation cost: " << totalCost << " UAH\n";
}

void leastCostMethod(const std::vector<int>& supply, const std::vector<int>& demand, const std::vector<std::vector<int>>& prices) {
    std::vector<std::vector<int>> allocation(WAREHOUSES, std::vector<int>(STORES, 0));
    std::vector<int> s = supply;
    std::vector<int> d = demand;
    std::vector<std::vector<bool>> used(WAREHOUSES, std::vector<bool>(STORES, false));

    int totalCost = 0;

    while (true) {
        int minCost = prices[0][0];
        int row = -1, col = -1;

        for (int i = 0; i < WAREHOUSES; ++i) {
            for (int j = 0; j < STORES; ++j) {
                if (!used[i][j] && prices[i][j] < minCost) {
                    minCost = prices[i][j];
                    row = i;
                    col = j;
                }
            }
        }

        if (row == -1 || col == -1) break;

        int qty = std::min(s[row], d[col]);
        allocation[row][col] = qty;
        totalCost += qty * prices[row][col];
        s[row] -= qty;
        d[col] -= qty;
        if (s[row] == 0)
            for (int j = 0; j < STORES; ++j)
                used[row][j] = true;

        if (d[col] == 0)
            for (int i = 0; i < WAREHOUSES; ++i)
                used[i][col] = true;
    }

    std::cout << "Least-Cost Allocation:\n";
    for (const auto& row : allocation) {
        for (int val : row)
            std::cout << std::setw(6) << val;
        std::cout << '\n';
    }

    std::cout << "\nTotal transportation cost: " << totalCost << " UAH\n";
}

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
                northwestCorner(stocks, need, matrix);
            } else {
                leastCostMethod(stocks, need, matrix);
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
