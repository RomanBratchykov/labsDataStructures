#include <iostream>
#include <cmath>
#include <iomanip>

struct triangle {
    private:
    double firstSide;
    double secondSide;
    double trirdSide;
    public:
    triangle(double firstSide, double secondSide, double trirdSide){
        this->firstSide = firstSide;
        this->secondSide = secondSide;
        this->trirdSide = trirdSide;
    }
    bool isPossible(){
        if (firstSide + secondSide > trirdSide && firstSide + trirdSide > secondSide && secondSide + trirdSide > firstSide){
            return true;
        }
        return false;
    }
    double perimeter(){
        return firstSide + secondSide + trirdSide;
    }

    double area(){
        double halfPerimeter = perimeter() / 2.0;
        return sqrt(halfPerimeter * (halfPerimeter - firstSide) * (halfPerimeter - secondSide) * (halfPerimeter - trirdSide));

    }
};

struct students {
    std::string studentName;
    std::string studentSurname;
    double scolarshipSize;
    int missedHours;
};

struct abiturient {
    std::string abiturientName;
    std::string abiturientSurname;
    std::string abiturientAddress;
    int abiturientMarks[3];

    double averageMark(){
        return (abiturientMarks[0] + abiturientMarks[1] + abiturientMarks[2]) / 3.0;
    }
};

struct worker {
    std::string workerSurname;
    std::string workerInitials;
    std::string position;
    int yearOfStart;
    double salary;

    int experience(int currentYear){
        return currentYear - yearOfStart;
    }

    double finalSalary(){
        double tax = this->salary * 0.66;
        return this->salary - tax;
    }
};

const int SIZE = 10;

std::string names[SIZE] = {
    "John",
    "Michael",
    "Robert",
    "David",
    "James",
    "William",
    "Joseph",
    "Thomas",
    "Charles",
    "Daniel"
};

std::string surnames[SIZE] = {
    "Smith",
    "Johnson",
    "Brown",
    "Williams",
    "Jones",
    "Miller",
    "Davis",
    "Garcia",
    "Rodriguez",
    "Martinez"
};

double scholarships[SIZE] = {
    1000,
    1200,
    1400,
    1600,
    1800,
    2000,
    2200,
    2400,
    2600,
    2800
};

double salaries[SIZE] = {
    1000,
    1200,
    1400,
    1600,
    1800,
    2000,
    2200,
    2400,
    2600,
    2800
};

int missedHours[SIZE] = {
    1, 
    2,
    7,
    9,
    12,
    19,
    30,
    25,
    4
};

std::string addresses[SIZE] = {
    "New York, st 15",
    "Los Angeles, st 20",
    "Chicago, st 25",
    "Houston, st 30",
    "Phoenix, st 35",
    "Philadelphia, st 40",
    "San Antonio, st 45",
    "San Diego, st 50",
    "Dallas, st 55",
    "San Jose, st 60" 
};

int mathGrades[SIZE] = {
    200, 
    190,
    187,
    160,
    159,
    133,
    157,
    145,
    125,
    134
};

int ukrainianGrades[SIZE] = {
    200, 
    194,
    187,
    163,
    152,
    143,
    127,
    149,
    120,
    124
};

int phisycsGrades[SIZE] = {
    180, 
    199,
    177,
    170,
    156,
    143,
    155,
    142,
    115,
    132
};

int yearsOfStart[SIZE] = {
    2000,
    2001,
    2002,
    2003,
    2004,
    2005,
    2006,
    2007,
    2008,
    2009
};

std::string positions[SIZE] = {
    "Manager",
    "Director",
    "Accountant",
    "Secretary",
    "Driver",
    "Engineer",
    "Programmer",
    "Designer",
    "Seller",
    "Consultant"
};

char nameInitials[SIZE] = {
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'G',
    'H',
    'I',
    'J'
};

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
                std::cout << "Enter number of students\n";
                int number;
                std::cin >>number;
                students* studentsArray = new students[number];
                int allSkippedHours = 0;
                for (int i = 0; i < number; i++){
                    studentsArray[i].studentName = names[rand() % SIZE];
                    studentsArray[i].studentSurname = surnames[rand() % SIZE];
                    if (rand() % 2 == 0)
                        studentsArray[i].scolarshipSize = scholarships[rand() % SIZE];
                    else
                        studentsArray[i].scolarshipSize = 0;
                    studentsArray[i].missedHours = missedHours[rand() % SIZE];
                    allSkippedHours += studentsArray[i].missedHours;
                }
                std::cout << "All students:\n" 
                << std::setw(12) <<"Name|"
                << std::setw(12) <<"Surname|"
                << std::setw(15) <<"Scolarship|"
                << std::setw(16) <<"Missed Hours|"<<"\n";
                for (int i = 0; i < number; i++){
                    std::cout << "=======================================================\n";
                    std::cout 
                    << std::setw(11) << studentsArray[i].studentName << "|"
                    << std::setw(11) << studentsArray[i].studentSurname<< "|"
                    << std::setw(14) << studentsArray[i].scolarshipSize<< "|"
                    << std::setw(15) << studentsArray[i].missedHours << "|"<< "\n";
                }
                std::cout << "=======================================================\n";
                
                std::cout << "Students with scholarchip and less than 2 hours skipped:\n";
                int counter = 0;
                for (int i = 0; i < number; i++){
                    if (studentsArray[i].scolarshipSize > 0 && studentsArray[i].missedHours < 2){
                        counter++;
                        std::cout << "=======================================================\n";
                        std::cout 
                        << std::setw(11) << studentsArray[i].studentName << "|"
                        << std::setw(11) << studentsArray[i].studentSurname << "|" 
                        << std::setw(14) << studentsArray[i].scolarshipSize << "|"
                        << std::setw(15) << studentsArray[i].missedHours << "|" << "\n";
                    }
                    
                }
                std::cout << "=======================================================\n";                if (counter == 0){
                    std::cout << "No students with scholarchip and less than 2 hours skipped\n";
                }
                std::cout << "All skipped hours = " << allSkippedHours << "\n";
            }
            break;
            case 2:
            {
                std::cout << "Enter sides of triangles\n";
                double firstSide, secondSide, trirdSide;
                std::cin >> firstSide >> secondSide >> trirdSide;
                triangle tr(firstSide, secondSide, trirdSide);
                if (tr.isPossible()){
                    std::cout << "Area = " << tr.area() << "\n";
                }
                else {
                    std::cout << "Triangle is not possible\n";
                }
            }
            break;
            case 3:
            {
                std::cout << "Enter number of abiturients\n";
                int number;
                std::cin >> number;
                abiturient* abiturientsArray = new abiturient[number];
                for (int i = 0; i < number; i++){
                    abiturientsArray[i].abiturientName = names[rand() % SIZE];
                    abiturientsArray[i].abiturientSurname = surnames[rand() % SIZE];
                    abiturientsArray[i].abiturientAddress = addresses[rand() % SIZE];
                    abiturientsArray[i].abiturientMarks[0] = mathGrades[rand() % SIZE];
                    abiturientsArray[i].abiturientMarks[1] = ukrainianGrades[rand() % SIZE];
                    abiturientsArray[i].abiturientMarks[2] = phisycsGrades[rand() % SIZE];
                }
                std::cout << "All abiturients:\n"
                << std::setw(13) <<"Name|"
                << std::setw(13) <<"Surname|"
                << std::setw(21) << "Address|"
                << std::setw(9)  << "Math|"
                << std::setw(14) << "Ukrainian|"
                << std::setw(12) << "Phisycs|"
                << std::setw(18) << "Average Score|\n";
                for (int i = 0; i < number; i++){
                    std::cout << "==================================================================================================\n";
                    std::cout 
                    << std::setw(12) << abiturientsArray[i].abiturientName     << "|"
                    << std::setw(12) << abiturientsArray[i].abiturientSurname  << "|"
                    << std::setw(20) << abiturientsArray[i].abiturientAddress  << "|"
                    << std::setw(8)  << abiturientsArray[i].abiturientMarks[0] << "|"
                    << std::setw(13) << abiturientsArray[i].abiturientMarks[1] << "|"
                    << std::setw(11) << abiturientsArray[i].abiturientMarks[2] << "|"
                    << std::setw(16) << abiturientsArray[i].averageMark() << "|\n";
                }
                std::cout << "==================================================================================================\n";
                std::cout << "Enter mark to be the passing score\n";
                int passingScore;
                std::cin >> passingScore;
                std::cout << "Abiturients that passed and entered university:\n";
                for (int i = 0; i < number; i++){
                    if (abiturientsArray[i].averageMark() > passingScore){
                        std::cout << "==================================================================================================\n";
                        std::cout 
                        << std::setw(12) << abiturientsArray[i].abiturientName << "|"
                        << std::setw(12) << abiturientsArray[i].abiturientSurname << "|"
                        << std::setw(20) << abiturientsArray[i].abiturientAddress << "|"
                        << std::setw(8)  << abiturientsArray[i].abiturientMarks[0] << "|"
                        << std::setw(13) << abiturientsArray[i].abiturientMarks[1] << "|"
                        << std::setw(11) << abiturientsArray[i].abiturientMarks[2] << "|"
                        << std::setw(16) << abiturientsArray[i].averageMark() << "|\n";                   
                    }
                }
                std::cout << "==================================================================================================\n";
            }
            break;
            case 4:
            {
                std::cout << "Enter number of workers\n";
                int numberOfWorkers;
                std::cin >> numberOfWorkers;
                std::cout << "Enter current year\n";
                int currentYear;
                std::cin >> currentYear;
                worker* workersArray = new worker[numberOfWorkers];
                std::cout << "All workers:\n"
                << std::setw(12) << "Surname|"
                << std::setw(11) << "Initials|"
                << std::setw(12) << "Position|"
                << std::setw(16) << "Year of start|"
                << std::setw(9) << "Salary|"
                << std::setw(13) << "Experience|"
                << std::setw(19) << "Final salary|\n";
                for (int i = 0; i < numberOfWorkers; i++){
                    workersArray[i].workerSurname = surnames[rand() % SIZE];
                    workersArray[i].workerInitials = std::string(1, nameInitials[rand() % SIZE])
                     + "." + std::string(1, workersArray[i].workerSurname[0]);
                    workersArray[i].position = positions[rand() % SIZE];
                    workersArray[i].yearOfStart = yearsOfStart[rand() % SIZE];
                    workersArray[i].salary = salaries[rand() % SIZE];
                    std::cout << "===========================================================================================\n";
                    std::cout << std::setw(11) << workersArray[i].workerSurname << "|"
                    << std::setw(10) << workersArray[i].workerInitials << "|"
                    << std::setw(11) << workersArray[i].position << "|"
                    << std::setw(15) << workersArray[i].yearOfStart << "|"
                    << std::setw(8)  << workersArray[i].salary << "|"
                    << std::setw(12) << workersArray[i].experience(currentYear) << "|"
                    << std::setw(17) << workersArray[i].finalSalary() << "|\n";
                }
                std::cout << "===========================================================================================\n";
            }
            break;
            default:
                std::cout << "Invalid number of task\n";
            break;
            }
        }
return 0;
}