#include <iostream>
#include <cmath>
#include <iomanip>

bool isVowel(char letter){
    tolower(letter);
    std::string vowels = "aeiuo";
    for (int i = 0; i < vowels.length(); i++){
        if (letter == vowels[i])
            return true;
    }
}

struct Students {
    std::string studentName;
    int studentGroup;
    int SES[5]; 
    double averageGrade(){
        double sum = 0;
        for (int i = 0; i < 5; i++){
            sum += SES[i];
        }
        return sum / 5;
    }
};

void studentsWithMoreThanAverage(Students* array, int size, double average){
    bool isStudents = false;
    for (int i = 0; i < size; i++)
    {
       
        if (array[i].averageGrade() > 4.0 ){ 
            isStudents = true;
        }
    }
    if (isStudents){
        std::cout << "Students with average grade more than 4:\n"
        << "|"
        << std::setw(19) << "Name|"
        << std::setw(8) << "Group|\n";
    }
    else
        std::cout << "There is no students with grade above 4\n";
    for (int i = 0; i < size; i++)
    {
       
        if (array[i].averageGrade() > 4.0 ){ 
            std::cout << "---------------------------\n";
            std::cout <<"|"
            << std::setw(18) << array[i].studentName << "|"
            << std::setw(6) << array[i].studentGroup << "|\n";
        }
    }
    std::cout << "---------------------------\n";
}

void studentsStartsWithVowel(Students* studentsArray, int size){
    bool studentsWithVowel = false; 
    for (int i = 0; i < size; i++)
    {
        if (isVowel(studentsArray[i].studentName[0])){ 
            studentsWithVowel = true;
        }
    }
    if (studentsWithVowel){
        std::cout << "Your array of students that have vowel on start of their surname: \n";
        std::cout << "|"
        << std::setw(19) << "Name|"
        << std::setw(8) << "Group|"
        << std::setw(7) << "Math|"
        << std::setw(10) << "English|"
        << std::setw(14) << "Programming|"
        << std::setw(12) << "Chemistry|"
        << std::setw(10) << "Biology|"
        << std::setw(10) << "Average|\n";
    }
    else
        std::cout << "There is no students that have vowel on start of their surname \n";

        for (int i = 0; i < size; i++) {
            if(isVowel(studentsArray[i].studentName[0])){
            std::cout << "------------------------------------------------------------------------------------------\n";
            std::cout << "|"
            << std::setw(18) << studentsArray[i].studentName << "|"
            << std::setw(7) << studentsArray[i].studentGroup << "|"
            << std::setw(6) << studentsArray[i].SES[0] << "|"
            << std::setw(9) << studentsArray[i].SES[1] << "|"
            << std::setw(13) << studentsArray[i].SES[2] << "|"
            << std::setw(11) << studentsArray[i].SES[3] << "|"
            << std::setw(9) << studentsArray[i].SES[4] << "|"
            << std::setw(8) << studentsArray[i].averageGrade() << "|\n";
        }
    }
        std::cout << "------------------------------------------------------------------------------------------\n";
}

void bubbleSort(double arr[], int size, std::string order = "asc"){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j + 1] && order == "asc"){
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            else if (arr[j] < arr[j + 1]  && order == "desc"){
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void createGradesArray(Students* studentsArray, int size){
    double* arrayOfAverage = new double[size];
    std::cout << "Average grades in array: \n";
    for (int i = 0; i < size; i++){
        arrayOfAverage[i] = studentsArray[i].averageGrade();
        std::cout << arrayOfAverage[i] << " ";
    }
    std::cout << "\n";
    bubbleSort(arrayOfAverage, size);
    std::cout << "Sorted average grades in array: \n";
    for (int i = 0; i < size; i++)
        std::cout << arrayOfAverage[i] << " ";
    std::cout << "\n";
    std::cout << "Enter positon of number you want to delete\n";
    int position;
    std::cin >> position;
    for (int i = position - 1; i < size - 1; i++ ){
            double temp = arrayOfAverage[i];
            arrayOfAverage[i] = arrayOfAverage[i + 1];
            arrayOfAverage[i + 1] = temp;
    }
    std::cout << "Array with deleted element\n";
    double* secondArray = new double [size - 1];
    for (int i = 0; i < size - 1; i++)
        secondArray[i] = arrayOfAverage[i];
    for (int i = 0; i < size - 1; i++)
        std::cout << secondArray[i] << " ";
    std::cout << "\n";
    delete[] arrayOfAverage;
    delete[] secondArray;
}

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
    "Adriana",
    "Evans",
    "Oven",
    "Andreas"
};

int main() {
    srand(time(0));
    while(1) {
        std::cout << "Enter number of students(0 for exit)\n";
        int number;
        std::cin >>number;
        if (number == 0){
            return 0;
        }
        if (number < 0){
            std::cout << "Array should contain at least one student";
            break;
        }
        Students* studentsArray = new Students[number];
        std::cout << "Your array of students: \n";
        std::cout << "------------------------------------------------------------------------------------------\n";

        std::cout << "|"
        << std::setw(19) << "Name|"
        << std::setw(8) << "Group|"
        << std::setw(7) << "Math|"
        << std::setw(10) << "English|"
        << std::setw(14) << "Programming|"
        << std::setw(12) << "Chemistry|"
        << std::setw(10) << "Biology|"
        << std::setw(10) << "Average|\n";
        
        for (int i = 0; i < number; i++) {
            studentsArray[i].SES[0] = rand() % 5 + 1;
            studentsArray[i].SES[1] = rand() % 5 + 1;
            studentsArray[i].SES[2] = rand() % 5 + 1;
            studentsArray[i].SES[3] = rand() % 5 + 1;
            studentsArray[i].SES[4] = rand() % 5 + 1;
            studentsArray[i].studentName = (surnames[rand() % SIZE] + " " + names[rand() % SIZE]);
            studentsArray[i].studentGroup = rand() % 10 + 1;
            std::cout << "------------------------------------------------------------------------------------------\n";
            std::cout << "|"
            << std::setw(18) << studentsArray[i].studentName << "|"
            << std::setw(7) << studentsArray[i].studentGroup << "|"
            << std::setw(6) << studentsArray[i].SES[0] << "|"
            << std::setw(9) << studentsArray[i].SES[1] << "|"
            << std::setw(13) << studentsArray[i].SES[2] << "|"
            << std::setw(11) << studentsArray[i].SES[3] << "|"
            << std::setw(9) << studentsArray[i].SES[4] << "|"
            << std::setw(8) << studentsArray[i].averageGrade() << "|\n";
        }
        std::cout << "------------------------------------------------------------------------------------------\n";
        studentsWithMoreThanAverage(studentsArray, number, 4);
        studentsStartsWithVowel(studentsArray, number);
        createGradesArray(studentsArray, number);
        delete[] studentsArray;
        }
        return 0;
}
    