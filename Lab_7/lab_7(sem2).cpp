#include <iostream>
#include <iomanip>
#include <cmath>


struct Numbers {
    double number;
    Numbers* next;
}*top = nullptr;

bool areEqual(double a, double b){
    return fabs(a - b) < 1e-9;
}
void push(double number) {
    Numbers* newNumber = new Numbers;
    newNumber->number = number;
    newNumber->next = top;
    top = newNumber;
}
void fillStack(int size){
    for (int i = 0; i < size; i++){
        push((rand() % 171-60) / 10.0);
    }
}
void popElements(Numbers*& top){
    Numbers* temp = top;
    top = top->next;
    delete temp;
}
void deleteLowerThan(Numbers*& top, double value) {
    while (top && top->number < value) {
        popElements(top);
    }
    
    if (top == nullptr) return;

    Numbers* temp = top;
    while (temp->next) {
        if (temp->next->number < value) {
            Numbers* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }
}
void clearStack(){
    Numbers* temp = top;
    while (temp){
        Numbers* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    top = nullptr;
}
void showStack(Numbers* top){
    while (top){
        std::cout << top->number << (top->next == nullptr ? " " : "->");
        top = top->next;
    }
    std::cout << "\n";
}
double getAverage(Numbers* top){
    Numbers* temp = top;
    double sum = 0;
    int counter = 0;
    while (temp != nullptr){
        sum += temp->number;
        counter++;
        temp = temp->next;
    }
    return sum / counter;
}

std::string holders[5] = {"CD", "Vinyl", "Tape", "Digital", "Streaming"};
std::string names[5] = {"Symphony No. 5", "The Four Seasons", "Moonlight Sonata", "Clair de Lune", "The Nutcracker Suite"};
std::string authors[5] = {"Beethoven", "Vivaldi", "Beethoven", "Debussy", "Tchaikovsky"};
double prices[5] = {10.99, 15.50, 12.75, 8.99, 20.00};
double durations[5] = {35.5, 40.0, 30.0, 25.0, 50.0};

struct Compositions {
    std::string holder;
    std::string name;
    std::string author;
    double price;
    double duration;
    int numberOfCopies;
    Compositions* next;
}*compositionsTop = nullptr;

void pushComposition(std::string holder, std::string name, std::string author, double price, double duration, int numberOfCopies){
    Compositions* newComposition = new Compositions;
    newComposition->holder = holder;
    newComposition->name = name;
    newComposition->duration = duration;
    newComposition->price = price;
    newComposition->author = author;
    newComposition->numberOfCopies = numberOfCopies;
    newComposition->next = compositionsTop;
    compositionsTop = newComposition;
}

void fillCompositions(int size){
    for (int i = 0; i < size; i++){
        pushComposition(holders[rand() % 5], names[rand() % 5], authors[rand() % 5], prices[rand() % 5], durations[rand() % 5], rand() % 100 + 1);
    }
}

void showCompositions(Compositions* compositionsTop){
    while (compositionsTop){
        std::cout << "Holder: " << compositionsTop->holder << ", Name: " << compositionsTop->name << ", Author: " << compositionsTop->author << ", Price: " << std::fixed << std::setprecision(2) << compositionsTop->price << ", Duration: " << compositionsTop->duration << ", Number of Copies: " << compositionsTop->numberOfCopies << "\n";
        compositionsTop = compositionsTop->next;
    }
    std::cout << "\n";
}

double allTime(Compositions* compositionsTop, std::string name = "Beethoven"){
    Compositions* temp = compositionsTop;
    double sum = 0;
    while (temp){
        if (temp->author == name){
            sum += temp->duration * temp->numberOfCopies;
        }
        temp = temp->next;
    }
    return sum;
} 

double avgPrice(Compositions* compositionsTop, std::string holder= "Tape")   {
    Compositions* temp = compositionsTop;
    double sum = 0;
    int counter = 0; 
    while (temp){
        if (temp->holder == holder){
            counter++;
            sum += temp->price * temp->numberOfCopies;
        }
        temp = temp->next;
    }
    return sum / counter;
}


void popCompositions(Compositions* compositionsTop){
    Compositions* temp = compositionsTop;
    compositionsTop = compositionsTop->next;
    delete temp;
}

void clearCompositions(Compositions* compositionsTop){
    Compositions* temp = compositionsTop;
    while (temp){
        Compositions* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    compositionsTop = nullptr;
}

int main() {
    srand(time(0));
    while (1)
    {
        std::cout << "Enter number of task(1-4, 0 for exit):\n";
        int num;
        std::cin >> num;
        switch (num)
        {
            case 0:
            return 0;
            case 1:
            {
                std::cout << "Enter number of elements in stack:\n";
                int numbers;
                std::cin >> numbers;
                if (numbers <= 0){
                    std::cout << "Stack should contain at least 1 element\n";
                    break;
                }
                fillStack(numbers);
                std::cout << "Your stack: ";
                showStack(top);
                std::cout << "Enter number and which elements are lower than that element will be deleted:\n";
                double number;
                std::cin >> number;
                deleteLowerThan(top, number);
                std::cout << "Stack after deleting elements lower than " << number << ":\n ";
                showStack(top);
                std::cout << "Average value: " <<std::fixed << std::setprecision(2) << getAverage(top) << "\n";
                clearStack();
            }
            break;
            case 2:
            {
                std::cout << "Enter number of elements in list:\n";
                int num;
                std::cin >> num;
                if (num <=0){
                    std::cout << "List should contain at least 1 element\n";
                    break;
                }
                fillCompositions(num);
                std::cout << "Your list: \n";
                showCompositions(compositionsTop);
                std::cout << "Total time of all compositions by Beethoven: " << allTime(compositionsTop) << "\n";
                std::cout << "Average price of all compositions on Tape: " << avgPrice(compositionsTop) << "\n";
                clearCompositions(compositionsTop);
            }
            break;
            // case 3:
            // {
            //     std::cout << "Enter number of elements in list:\n";
            //     int num;
            //     std::cin >> num;
            //     if (num <=0){
            //         std::cout << "List should contain at least 1 element\n";
            //         break;
            //     }
            //     fillList(num);
            //     std::cout << "Your list: \n";
            //     showList(head);
            //     Numbers* temp = head;
            //     std::cout << "numbers with duplicates: \n";
            //     int* duplicates = new int[num];
            //     int i = 0;
            //     int counter = 0;
            //     while (temp){
            //         bool foundDuplicate = false;
            //         Numbers* secondTemp = temp->next;
            //         while(secondTemp){
            //             if (temp->number == secondTemp->number){
            //                 foundDuplicate = true;
            //                 break;
            //             }
            //             secondTemp = secondTemp->next;
            //         }

            //         if (foundDuplicate) {
            //             bool alreadyPrinted = false;
            //             for (int j = 0; j < i; j++) {
            //                 if (duplicates[j] == temp->number) {
            //                     alreadyPrinted = true;
            //                     break;
            //                 }
            //             }
            //             if (!alreadyPrinted) {
            //                 std::cout << temp->number << " ";
            //                 duplicates[i++] = temp->number;
            //             }
            //         }
            //         temp = temp->next;
            //     }
            //     std::cout << "\n";
            //     deleteEvenNumbers(head);
            //     std::cout << "List after deleting even numbers: \n";
            //     showList(head);
            //     clearList();
            //     delete[] duplicates;
            // }
            // break;
            case 4:
            {

            }
            break;
            default:
            std::cout << "Invalid number of task\n";
        }
    }
    return 0;
}