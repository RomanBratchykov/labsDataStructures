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
};


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

void fillList(int size){
    for (int i = 0; i < size; i++){
        addNumber(rand() % 100);
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

void deleteNumber(Numbers*& head){
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
                deleteNumber(head);
                std::cout << "List after deleting first even number: \n";
                showList(head);
                clearList();
            }
            break;
            case 2:
            {

            }
            break;
            case 3:
            {

            }
            break;
            default:
            std::cout << "Invalid number of task\n";
        }
    }
    return 0;
}