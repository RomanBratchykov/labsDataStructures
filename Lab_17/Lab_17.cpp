#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
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

int simpleSearch(std::string text, std::string pattern){
    int textLength = text.length();
    int patternLength = pattern.length();
    for (int i = 0; i <= textLength - patternLength; i++){
        int j;
        for (j = 0; j < patternLength; j++){
            if (text[i + j] != pattern[j]){
                break;
            }
        }
        if (j == patternLength){
            return i;
        }
    }
    return -1;
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

std::vector<int> buildKMPTable(const std::string& pattern) {
    std::vector<int> lps(pattern.length(), 0);
    int len = 0;
    for (int i = 1; i < pattern.length(); ) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
    return lps;
}

int KMPSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> lps = buildKMPTable(pattern);
    int i = 0, j = 0;
    while (i < text.length()) {
        if (pattern[j] == text[i]) {
            i++; j++;
        }
        if (j == pattern.length()) {
            return i - j;
        } else if (i < text.length() && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return -1;
}

std::vector<int> buildBadCharTable(const std::string& pattern) {
    const int ALPHABET_SIZE = 256;
    std::vector<int> badChar(ALPHABET_SIZE, -1);
    for (int i = 0; i < pattern.length(); ++i)
        badChar[(unsigned char)pattern[i]] = i;
    return badChar;
}

int BoyerMooreSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> badChar = buildBadCharTable(pattern);
    int m = pattern.length();
    int n = text.length();

    int shift = 0;
    while (shift <= n - m) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }
        if (j < 0) {
            return shift;
        } else {
            shift += std::max(1, j - badChar[(unsigned char)text[shift + j]]);
        }
    }
    return -1;
}
int main(){
    srand(time(0));
    std::cout << "Choose task(1-2)\n";
    int task;
    std::cin>>task;
    if (task != 1 && task != 2){
        std::cout << "Invalid task\n";
        return 0;
    }
    switch (task){
        case 1:{
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
            delete[] studentArr;
            break;  
        }
        case 2:{
            std::ifstream fileToRead("file.txt");
            if (!fileToRead.is_open()){
                std::cout << "File not found\n";
                return 0;
            }
            std::string text;
            std::string finalLine;
            while (std::getline(fileToRead, text)){
                finalLine += text + "\n";
            }
            std::cout << "Enter pattern to find\n";
            std::cin.ignore();
            std::string pattern;
            std::getline(std::cin, pattern);
            std::cout << "Text from file:\n" << finalLine << "\n";
            std::cout << "Pattern to find: " << pattern << "\n";
            std::cout << "Choose search method(1 - simple, 2 - KMP, 3 - Boyer Moore)\n";
            int searchMethod;
            std::cin >> searchMethod;
            switch (searchMethod){
                case 1: {
                    int index = simpleSearch(finalLine, pattern);
                    if (index != -1){
                        std::cout << "Pattern found at index " << index << "\n";
                    } else {
                        std::cout << "Pattern not found\n";
                    }
                
                }
                break;
                case 2:{
                    int index = KMPSearch(finalLine, pattern);
                    if (index != -1){
                        std::cout << "Pattern found at index " << index << "\n";
                    } else {
                        std::cout << "Pattern not found\n";
                    }
                }
                break;
                case 3:{
                    int index = BoyerMooreSearch(finalLine, pattern);
                    if (index != -1){
                        std::cout << "Pattern found at index " << index << "\n";
                    } else {
                        std::cout << "Pattern not found\n";   
                 } 
                }
                break;
                default:
                    std::cout << "Invalid search method\n";
                    return 0;
            break;
        }
    }
}
}