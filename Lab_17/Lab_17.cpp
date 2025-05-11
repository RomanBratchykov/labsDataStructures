#include <iostream>
#include <vector>
#include <iomanip>
std::string surnames[5] = {"Johnson", "Smith", "Jackson", "Pitt", "Shevchenko"};
class Student{
    std::string surname;
    std::vector<int> grades;
    double avgGrade;
    public:
    Student(std::string surname, std::vector<int> grades){
        this->surname = surname;
        for (int i = 0; i < grades.size(); i++){
            this->grades.push_back(grades[i]);
        }
        double avg = 0;
        for (auto grade : grades){
            avg += grade;
        }
        this->avgGrade = avg / grades.size();
    }
    Student(){
        this->surname = "Smith";
        for (int i = 0; i < grades.size(); i++){
            this->grades[i] = 50;
        }
        double avg = 0;
        for (auto grade : grades){
            avg += grade;
        }
        this->avgGrade = avg / grades.size();
    }
    void printStudent(){
        std::cout << "------------------------------------------------------\n";
        std::cout << surname << " have grades ";
        for (auto grade : grades){
            std::cout << grade <<" ";
        }
        std::cout <<std::fixed << " with average of " << std::setprecision(2) << avgGrade << "\n";
    }
    int getAvgGrade(){
        return avgGrade;
    }
    bool operator<(Student &other){
        return this->avgGrade < other.avgGrade;
    }
    bool operator>(Student &other){
        return this->avgGrade > other.avgGrade;
    }
    bool operator<=(Student &other){
        return this->avgGrade <= other.avgGrade;
    }
    bool operator>=(Student &other){
        return this->avgGrade >= other.avgGrade;
    }
};

int partition(Student* arr, int start, int end){
    Student pivot = arr[end];
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

void quickSort(Student* arr, int start, int end){
    if (start < end){
        int pivotIndex = partition(arr, start, end);

        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
} 

std::vector<int> studentsWithMax(Student* arr, int size){
   int max = arr[0].getAvgGrade();
   std::vector<int> numbers;
   for (int i = 0; i < size; i++){
        if (arr[i].getAvgGrade() > max){
            max = arr[i].getAvgGrade();
        }
   }
   for (int i = 0; i < size; i++){
    if (arr[i].getAvgGrade() == max){
        numbers.push_back(i);
    }
}
    return numbers;
}

void binarySearch(Student* arr, int start, int end, int element) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int avg = arr[mid].getAvgGrade();

        if (avg == element) {
            arr[mid].printStudent();
            return;
        } else if (avg < element) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    std::cout << "Student with average grade " << element << " not found.\n";
}

int main(){
    srand(time(0));
    std::cout << "Enter number of students\n";
    int number;
    std::cin >> number;
    Student* studentArr = new Student[number];
    for (int i = 0; i < number; i++){
        std::vector<int> gradesArr;
        for (int j = 0; j < 3; j++){
            gradesArr.push_back(rand() % 100);
        }
        std::string surname = surnames[rand() % 5];
        studentArr[i] = Student(surname, gradesArr);
    }
    std::vector<int> studentsWithMaxRes = studentsWithMax(studentArr, number);
    std::cout << "Array of students\n";
    for (int i = 0; i < number; i++){
        studentArr[i].printStudent();
    }   
    std::cout << "Number of students with maximum avg grade = " << studentsWithMaxRes.size() << " and numbers of students: \n";
    for (auto element : studentsWithMaxRes){
        std::cout << element << " ";
    }
    std::cout << "\n";
    std::cout << "Sorted array for binary search\n";
    quickSort(studentArr, 0, number - 1);
    for (int i = 0; i < number; i++){
        studentArr[i].printStudent();
    }  
    std::cout << "Enter avg grade to find with binary search\n";
    int avg;
    std::cin >> avg;
    binarySearch(studentArr, 0, number - 1, avg);
}