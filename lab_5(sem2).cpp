#include <iostream>


struct Numbers {
    int number;
    Numbers* next;
}*head = nullptr, *tail = nullptr;

struct Students {
    std::string studentName;
    int studentHeight;
    int studentWeight;
    Students* next;
}*studentsHead = nullptr, *studentsTail = nullptr;


void addStudent(std::string studentName, int studentHeight, int studentWeight){
    Students* newStudent = new Students;
    newStudent->studentName = studentName;
    newStudent->studentHeight = studentHeight;
    newStudent->studentWeight = studentWeight;
    newStudent->next = nullptr;
    if (studentsHead == nullptr){
        studentsHead = newStudent;
        studentsTail = newStudent;
    }
    else{
        studentsTail->next = newStudent;
        studentsTail = newStudent;
    }
}

void addNumber(int number) {
    Numbers* newNumber = new Numbers;
    newNumber->number = number;
    newNumber->next = nullptr;
    if (head == nullptr)
    {
        head = newNumber;
        tail = newNumber;
    }
    else
    {
        tail->next = newNumber;
        tail = newNumber;
    } 
}

void addNumberAtStart(int number){
    Numbers* newNumber = new Numbers;
    newNumber->number = number;
    newNumber->next = head;
    head = newNumber;

    if (tail == nullptr) {
        tail = newNumber;
    }
}

void addNumberAtIndex(int number, int index){
    Numbers* temp = head;
    for (int i = 0; i < index - 1; i++){
        if (temp == nullptr){
            std::cout << "Index out of range\n";
            return;
        }
        temp = temp->next;
    }

    if (temp == nullptr){
        std::cout << "Index out of range\n";
        return;
    }

    Numbers* newNumber = new Numbers;
    newNumber->number = number;
    newNumber->next = temp->next;
    temp->next = newNumber;

    if (newNumber->next == nullptr){
        tail = newNumber;
    }

}

void fillList(int size){
    int number;
    std::cout << "Enter number for start:\n";
    std::cin >> number;
    addNumberAtStart(number);
    for (int i = 1; i < size; i++){
            int number;
            std::cout << "Enter number:\n";
            std::cin >> number;
            std::cout << "Where you want to add number? (1 - start, 2 - end, 3 - at index)\n";
            int choice;
            std::cin >> choice;
            switch (choice) {
                case 1:
                    addNumberAtStart(number);
                    break;
                case 2:
                    addNumber(number);
                    break;
                case 3:
                    int index;
                    std::cout << "Enter index:\n";
                    std::cin >> index;
                    addNumberAtIndex(number, index);
                    break;
                default:
                    std::cout << "Invalid choice\n";
            }
        }
}

double findAverage(Numbers* head){
    Numbers* temp = head;
    double sum = 0;
    int count = 0;
    while (head != nullptr){
        sum += head->number;
        count++;
        head = head->next;
    }
    return sum / count;
}

void deleteFirstEvenNumber(Numbers*& head){
    Numbers* temp = head;
    while (temp != nullptr){
        if (temp->number % 2 == 0){
            Numbers* toDelete = temp;
            temp = temp->next;
            head = temp;
            delete toDelete;
            return;
            break;
        }
        if (temp->next->number % 2 == 0){
            Numbers* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return;
            break;
        }
        temp = temp->next;
    }
}

void deleteNumberWithValue(Numbers*& head, int value){
    Numbers* temp = head;
    while (temp != nullptr){
        if (temp->number == value){
            Numbers* toDelete = temp;
            temp = temp->next;
            head = temp;
            delete toDelete;
            return;
            break;
        }
        if (temp->next->number == value){
            Numbers* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return;
            break;
        }
        temp = temp->next;
    }
}

void clearList(){
    Numbers* temp = head;
    while (temp != nullptr){
        Numbers* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    head = nullptr;
    tail = nullptr;
}

void showList(Numbers* head){
    Numbers* temp = head;
    while (temp != nullptr){
        std::cout << temp->number << (temp->next == nullptr ? " " : "->");
        temp = temp->next;
    }
    std::cout << "\n";
}
int main() {
    srand(time(0));
    while (1)
    {
        std::cout << "Enter number of task(1-3, 0 for exit):\n";
        int num;
        std::cin >> num;
        switch (num)
        {
            case 0:
            return 0;
            case 1:
            {
                std::cout << "Enter size of list\n";
                int size;
                std::cin >> size;
                if (size <= 0){
                    std::cout << "Size should be more than 0\n";
                    break;
                }
                fillList(size);
                std::cout << "List: \n";
                showList(head);
                std::cout << "Average: " << findAverage(head) << "\n";
                deleteFirstEvenNumber(head);
                std::cout << "List after deleting first even number: \n";
                showList(head);
                clearList();
            }
            break;
            case 2:
            {
                std::cout << "Enter first element of list:\n";
                int firstElement, secondElement, thirdElement;
                std::cin >> firstElement;
                addNumberAtStart(firstElement);
                std::cout << "Enter second element of list:\n";
                std::cin >> secondElement;
                std::cout << "Enter third element of list:\n";
                std::cin >> thirdElement;
                if (firstElement < 0){
                    addNumberAtStart(secondElement);
                    addNumberAtStart(thirdElement);
                }
                else{
                    addNumber(secondElement);
                    addNumber(thirdElement);
                }
                std::cout << "List: \n";
                showList(head);
                int middle = firstElement;
                if (secondElement > middle && secondElement < thirdElement) {
                    middle = secondElement;
                }
                else if (thirdElement > middle && thirdElement < secondElement){
                    middle = thirdElement;
                }

                deleteNumberWithValue(head, middle);
                std::cout << "List after deleting middle element: \n";
                showList(head);
                clearList();
            }
            break;
            case 3:
            {
                std::cout << "Enter number of students\n";
                int number;
                std::cin >> number;
                if (number <= 0){
                    std::cout << "Number of students should be more than 0\n";
                    break;
                }
                for (int i = 0; i < number; i++){
                    std::string studentName;
                    int studentHeight, studentWeight;
                    std::cout << "Enter student name:\n";
                    std::cin >> studentName;
                    std::cout << "Enter student height:\n";
                    std::cin >> studentHeight;
                    std::cout << "Enter student weight:\n";
                    std::cin >> studentWeight;
                    addStudent(studentName, studentHeight, studentWeight);
                }
                Students* temp = studentsHead;
                int minWeight = temp->studentWeight;
                int counterForA = 0;
                std::cout << "Students: \n";
                while (temp != nullptr){
                    if (temp->studentName[0] == 'a' && temp->studentHeight > 170)
                        counterForA++;
                    if (temp->studentWeight < minWeight){
                        minWeight = temp->studentWeight;
                    }
                    std::cout << "Name: " << temp->studentName << " Height: " << temp->studentHeight << " Weight: " << temp->studentWeight << "\n";
                    temp = temp->next;
                }
                temp = studentsHead;
                if (counterForA == 0){
                    std::cout << "There is no students that have name starting with 'a' and height more than 170\n";
                }
                else{
                    std::cout << "Students with height more than 170 and whose name starts with 'a':\n";
                    while (temp != nullptr){
                        if (temp->studentName[0] == 'a' && temp->studentHeight > 170)
                            std::cout << "Name: " << temp->studentName << " Height: " << temp->studentHeight << " Weight: " << temp->studentWeight << "\n";
                        temp = temp->next;
                    }
                }
                temp = studentsHead;
                while (temp != nullptr){
                    if (temp->studentWeight == minWeight){
                        Students* toDelete = temp;
                        temp = temp->next;
                        studentsHead = temp;
                        delete toDelete;
                        break;
                    }
                    else if (temp->next->studentWeight == minWeight){
                        Students* toDelete = temp->next;
                        temp->next = temp->next->next;
                        delete toDelete;
                        break;
                    }
                    temp = temp->next;
                }   
                std::cout << "List without student with min weight: \n";
                temp = studentsHead;
                while (temp != nullptr){
                    std::cout << "Name: " << temp->studentName << " Height: " << temp->studentHeight << " Weight: " << temp->studentWeight << "\n";
                    temp = temp->next;
                }
                clearList();
            }
            break;
            default:
            std::cout << "Invalid number of task\n";
        }
    }
    return 0;
}