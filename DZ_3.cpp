#include <iostream>

struct employee {
    std::string surname;
    std::string name;
    std::string position;
    double salary;
    double workedTime;
};

const int SIZE = 10;

std::string names[SIZE] = {
    "John", "Alice", "Robert", "Sophia", "Michael",
    "Emma", "David", "Olivia", "James", "Isabella"
};

std::string surnames[SIZE] = {
    "Smith", "Johnson", "Brown", "Williams", "Jones",
    "Miller", "Davis", "Garcia", "Rodriguez", "Martinez"
};

std::string positions[SIZE] = {
    "Manager", "Engineer", "Designer", "Analyst", "Developer",
    "Technician", "Consultant", "Director", "HR", "Accountant"
};

double salaries[SIZE] = {
    1500, 2000, 2500, 3000, 3500,
    4000, 4500, 4700, 4900, 5000
};

double workedTimes[SIZE] = {
    50, 75, 100, 125, 150,
    175, 200, 225, 250, 300
};


struct rectangle {
    double width;
    double height;
    double perimeter()  
    {
    return 2 * (width + height);
    }
};

struct book {
    std::string bookTitle;
    std::string author;
    int year;
    int numberOfPages;
};

int main() {

    std::cout << "Choose task:(1-3, 0 for exit)\n";
    int task;
    std::cin >> task;
    switch (task){
        case 0:
            return 0;
        break;
        case 1:
        {
            std::cout << "Enter number of employees\n";
            int n;
            std::cin >> n;
            employee employees[n];
            for (int i = 0; i < n; i++)
            {
                employees[i].name = names[rand() % SIZE];
                employees[i].surname = surnames[rand() % SIZE];
                employees[i].position = positions[rand() % SIZE];
                employees[i].salary = salaries[rand() % SIZE];
                employees[i].workedTime = workedTimes[rand() % SIZE];
            }
            std::cout << "Your Employees:\n"
            << "Name\tSurname\tPosition\tSalary\tWorked Time\n";
            double averageSalary = 0;
            int fullWorkedTime = 0;
            for (int i = 0; i < n; i++)
            {
                fullWorkedTime += employees[i].workedTime;
                averageSalary += employees[i].salary;
                std::cout << employees[i].name << "\t" << employees[i].surname << "\t" << employees[i].position << "\t" << employees[i].salary << "\t" << employees[i].workedTime << "\n";
            }
            averageSalary /= n;
            std::cout <<"=================================================================================\n";
            std::cout << "All workers with more than 160 hours worked and with salary more that average:"
            << "\nName\tSurname\tPosition\tSalary\tWorked Time\n";
            for (int i = 0; i < n; i++)
            {
                if (employees[i].workedTime > 160 && employees[i].salary > averageSalary)
                {
                    std::cout << employees[i].name << "\t" << employees[i].surname << "\t" << employees[i].position << "\t" << employees[i].salary << "\t" << employees[i].workedTime << "\n";
                }
            }
            std::cout <<"All worked time = " << fullWorkedTime << "\n";
            while (1){
                std::cout << "Enter position to find workers with this position or 0 to exit\n";
                std::string position;
                std::cin >> position;
                if (position == "0")
                    break;
                std::cout << "Workers with position " << position << "\nName\tSurname\tPosition\tSalary\tWorked Time\n";
                for (int i = 0; i < n; i++){
                    if (employees[i].position == position){
                        std::cout << employees[i].name << "\t" << employees[i].surname << "\t" << employees[i].position << "\t" << employees[i].salary << "\t" << employees[i].workedTime << "\n";
                    }
                }
            }
        }
        break;
        case 2:
        {
            std::cout << "Enter sides of first rectangle\n";
            rectangle rect1;
            std::cin >> rect1.width >> rect1.height;
            std::cout << "Enter sides of second rectangle\n";
            rectangle rect2;
            std::cin >> rect2.width >> rect2.height;            
            std::cout << "Perimeter of first rectangle = " << rect1.perimeter() << " \nPerimeter of second rectangle = " << rect2.perimeter() << "\nSum of two = " <<  rect1.perimeter() + rect2.perimeter() <<"\n"; 
        }
        break;
        case 3:
        {

        }
        break;
        default: 
            std::cout << "Wrong task number\n";
        break;
    }
    return 0;
}
