#include <iostream>
#include <stack>
#include <queue>

bool isBalanced(std::string info, std::string type){
    std::stack<char> stack;
    for (char ch : info){
        if (ch == type[0]){
            stack.push(ch);
        } 
        if (ch == type[1]){
            if (stack.empty() || stack.top() != type[0]){
                return false;
            }
            stack.pop();
        }
    }
    return stack.empty();
}

void checkBalanced(std::string info){
    std::cout << "Enter element to check:() or [] or {} or all: ";
    std::string type;
    std::getline(std::cin, type);
    std::cout << type << "\n";
    int counterForRound = 0;
    int counterForSquare = 0;
    int counterForCurly = 0;
    for (char ch : info){
        if (ch == '(' || ch == ')'){
            counterForRound++;
        }
        if (ch == '[' || ch == ']'){
            counterForSquare++;
        }
        if (ch == '{' || ch == '}'){
            counterForCurly++;
        }

    }
    
    if (type == "all" || type == "All"){
        if (counterForRound == 0){
            std::cout << "There are no () brackets.\n";
        } 
        else{
            std::cout << "Checking () brackets...\n";
            if (isBalanced(info, "()")){
                std::cout << "() brackets are balanced.\n";
            } else {
                std::cout << "() brackets are not balanced.\n";
            }
        }

        if (counterForSquare == 0){
            std::cout << "There are no [] brackets.\n";
        } 
        else{
            std::cout << "Checking [] brackets...\n";
            if (isBalanced(info, "[]")){
                std::cout << "[] brackets are balanced.\n";
            } else {
                std::cout << "[] brackets are not balanced.\n";
            }
        }
        if (counterForCurly == 0){
            std::cout << "There are no {} brackets.\n";
        } 
        else{
            std::cout << "Checking {} brackets...\n";
            if (isBalanced(info, "{}")){
                std::cout << "{} brackets are balanced.\n";
            } else {
                std::cout << "{} brackets are not balanced.\n";
            }
        }
    } 
    
    else if (type == "()"){
        if (counterForRound == 0){
            std::cout << "There are no () brackets.\n";
        }
        else{
            std::cout << "Checking () brackets...\n";
            if (isBalanced(info, "()")){
                std::cout << "() brackets are balanced.\n";
            } else {
                std::cout << "() brackets are not balanced.\n";
            }
        }
    } 
    
    else if (type == "[]"){
        if (counterForSquare == 0){
            std::cout << "There are no [] brackets.\n";
        } 
        else{
            std::cout << "Checking [] brackets...\n";
            if (isBalanced(info, "[]")){
                std::cout << "[] brackets are balanced.\n";
            } else {
                std::cout << "[] brackets are not balanced.\n";
            }
        }
    } 
    
    else if (type == "{}"){
        if (counterForCurly == 0){
            std::cout << "There are no {} brackets.\n";
        } 
        else{
            std::cout << "Checking {} brackets...\n";
            if (isBalanced(info, "{}")){
                std::cout << "{} brackets are balanced.\n";
            } else {
                std::cout << "{} brackets are not balanced.\n";
            }
        }
    } 
    
    else {
        std::cout << "Invalid type entered. Please enter () or [] or {} or all.\n";
    }
}

class Student{
    std::string name;
    int mark;
    public:
    Student(std::string name, int mark) : name(name), mark(mark) {}
    std::string getName() { return name;}
    int getMark() { return mark; }
};

std::queue<Student> reverse(std::queue<Student> q){
    std::stack<Student> stack;
    while (!q.empty()){
        stack.push(q.front());
        q.pop();
    }
    while(!stack.empty()){
        q.push(stack.top());
        stack.pop();
    }
    return q;
}

class Auto{
    std::string model;
    int year;
    public:
    Auto(std::string model, int year) : model(model), year(year) {}
    std::string getModel() const { return model;}
    int getYear() const { return year; }
    bool operator<(const Auto& other) const {
        return year < other.year;
    }
    bool operator>(const Auto& other) const 
    {
        return year > other.year;
    }
};

int main(){
    srand(time(0));
    while (1){
        std::cout << "Enter number of task(1-3, 0 for exit): \n";
        int num;
        std::cin >> num;
        if (num == 0){
            return 0;
        }
        switch(num)
        {
            case 1:
            {
                std::cin.ignore();
                std::cout << "Enter string to check: ";
                std::string info;
                std::getline(std::cin, info);
                checkBalanced(info);
            }
            break;
            case 2:
            {
                std::queue<Student> q;
                std::queue<Student> p;
                std::cout << "Enter number of students:\n";
                int num;
                std::cin >> num;
                std::cin.ignore(); 
                for (int i = 0; i < num; i++){
                    std::cout << "Enter name and mark of student " << i + 1 << ": ";
                    std::string name;
                    int mark;
                    
                    std::cin >> name >> mark;
                    if (mark > 100 || mark < 0){
                        std::cout << "Invalid mark. Please enter a mark between 0 and 100.\n";
                        i--;
                        continue;
                    }
                    q.push(Student(name, mark));
                }
                p = reverse(q);
                std::cout << "Queue of students:\n";
                while (!q.empty()){
                    std::cout << q.front().getName() << " " << q.front().getMark() << "\n";
                    q.pop();
                }
                std::cout << "Reversing queue...\n";
                
                std::cout << "Reversed queue:\n";
                while (!p.empty()){
                    std::cout << p.front().getName() << " " << p.front().getMark() << "\n";
                    p.pop();
                }
            }
            break;
            case 3:
            {
                std::priority_queue<Auto> pq;
                std::cout << "Enter number of cars:\n";
                int num; 
                std::cin >> num;
                std::cin.ignore();
                for (int i = 0; i < num; i++){
                    std::cout << "Enter model of " << i + 1 << " car(rand year): ";
                    std::string model;
                    int year;
                    year = rand() % 26 + 2000;
                    std::cin >> model;
                    pq.push(Auto(model, year));
                }
                std::cout << "Queue of cars:\n";
                while (!pq.empty()){
                    std::cout << pq.top().getModel() << " " << pq.top().getYear() << "\n";
                    pq.pop();
                }

            }
            break;
            default:
            std::cout << "Invalid number of task.\n";
            break;
        }
    }
    return 0;
}