#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>

struct Tree {
    int value;
    Tree* right;
    Tree* left;
}*root = nullptr;

Tree* insertValue(Tree* node, int value){
    if (node == nullptr) {
        node = new Tree;
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;
        std::cout << "Inserted as root " << value << "\n";  
    } else if (value < node->value) {
        node->left = insertValue(node->left, value);
        std::cout << "Inserted as left " << value << "\n";
    } else {
        node->right = insertValue(node->right, value);
        std::cout << "Inserted as right " << value << "\n";
    }
    return node;
}

Tree* insertValueCopy(Tree* node, int value){
    if (node == nullptr) {
        node = new Tree;
        node->value = value;
        node->left = nullptr;
        node->right = nullptr; 
    } else if (value < node->value) {
        node->left = insertValueCopy(node->left, value);
    } else {
        node->right = insertValueCopy(node->right, value);
    }
    return node;
}

Tree* insertValue(int value){
    if (root == nullptr){
        root = new Tree;
        root->value = value;
        root->left = nullptr;
        root->right = nullptr;
    }
    else {
        insertValue(root, value);
    }
    return root;
}

int randomNum(int range, int start){
    return rand() % range + start;
}

bool isExists(Tree* node, int value){
    if (node == nullptr) return false;
    if (node->value == value) return true;
    if (value < node->value) 
        return isExists(node->left, value);
    else
        return isExists(node->right, value);
}

void clearTree(Tree* node){
    if (node == nullptr) return;
    clearTree(node->left);
    clearTree(node->right);
    delete node;
}

void clearTree(){
    clearTree(root);
    root = nullptr;
}

void printTree(Tree* node){
    if (node == nullptr) {
        return;
    }
    printTree(node->left);
    std::cout << node->value << " ";
    printTree(node->right);
}

Tree* copyTree(Tree* original, Tree*& evenTree, Tree*& oddTree){
    if (original == nullptr) return nullptr;
    Tree* newNode = new Tree;
    newNode->value = original->value;
    newNode->left = copyTree(original->left, evenTree, oddTree);
    newNode->right = copyTree(original->right, evenTree, oddTree);
    
    if (original->value % 2 == 0) {
        evenTree = insertValueCopy(evenTree, original->value);
    } else {
        oddTree = insertValueCopy(oddTree, original->value);
    }
    
    return newNode;
}

int findDepth(Tree* node){
    if (node == nullptr) return 0;
    int leftDepth = findDepth(node->left);
    int rightDepth = findDepth(node->right);
    return std::max(leftDepth, rightDepth) + 1;
}

struct Computers{
    int code;
    std::string name;
    int price;
};

struct ComputerTree{
    Computers data;
    ComputerTree* right;
    ComputerTree* left;
}*compRoot = nullptr;

ComputerTree* insertComputer(ComputerTree* node, Computers data){
    if (node == nullptr) {
        node = new ComputerTree;
        node->data = data;
        node->left = nullptr;
        node->right = nullptr;
    } else if (data.code < node->data.code) {
        node->left = insertComputer(node->left, data);
    } else {
        node->right = insertComputer(node->right,data);
    }
    return node;
}

ComputerTree* insertComputer(Computers data){
    if (compRoot == nullptr){
        compRoot = new ComputerTree;
        compRoot->data = data;
        compRoot->left = nullptr;
        compRoot->right = nullptr;
    }
    else
        insertComputer(compRoot, data);
    return compRoot;
}

void printComputers(ComputerTree* node){
    if (node == nullptr) return;
    printComputers(node->left);
    std::cout << "------------------------\n";
    std::cout << node->data.code << " "<< node->data.name << " "<< node->data.price << " \n";
    printComputers(node->right);
}

double averagePrice(ComputerTree* node, double& sum, double& count){
    if (node == nullptr) return 0;
    sum += node->data.price;
    count++;
    averagePrice(node->left, sum, count);
    averagePrice(node->right, sum, count);
    return sum / count;
}

ComputerTree* findNode(ComputerTree* node, int code){
    if (node == nullptr) return nullptr;
    if (node->data.code == code) return node;
    if (code < node->data.code)
        return findNode(node->left, code);
    else   
    return findNode(node->right, code);
}

void clearComputer(ComputerTree* node){
    if (node == nullptr) return;
    clearComputer(node->left);
    clearComputer(node->right);
    delete node;
}

void deleteChildren(ComputerTree* node){
    if (node == nullptr) return;
    clearComputer(node->left);
    node->left = nullptr;
    clearComputer(node->right);
    node->right = nullptr;
}

int findDepth(ComputerTree* node){
    if (node == nullptr) return 0;
    int leftDepth = findDepth(node->left);
    int rightDepth = findDepth(node->right);
    return std::max(leftDepth, rightDepth) + 1;
}

void countNodesAtLevel(ComputerTree* node, int level, int*& count){
    if (node == nullptr) return;
    count[level]++;
    countNodesAtLevel(node->left, level + 1, count);
    countNodesAtLevel(node->right, level + 1, count);
}

int main(){
    srand(time(0));
    while (1){
        std::cout << "Enter number of task(1-2, 0 for exit)\n";
        int task;
        std::cin >> task;
        switch(task){
            case 0:
                return 0;
            case 1:{
                std::cout << "Enter number of elements\n";
                int n;
                std::cin >> n;
                std::cout << "How you want to fill the tree?\n1 - manual\n2 - random\n";
                int fillType;
                std::cin >> fillType;
                switch(fillType){
                    case 1:{
                        for (int i = 0; i < n; i++){
                            std::cout << "Enter " << i + 1 << " element\n"; 
                            int value;
                            std::cin >> value;
                            if (isExists(root, value)){
                                std::cout << "This value (" << value << ") already exists\n";
                                i--;
                                continue;
                            }
                            insertValue(value);
                        }
                    }
                    break;
                    case 2:{
                        std::cout << "Enter start and range\n";
                        int start, range;
                        std::cin >> start >> range;
                        if (n > range){
                            std::cout << "Range cannot be greater than number of elements\n";
                            break;
                        }
                        if (start > range){
                            std::cout << "Start cannot be greater than range\n";
                            break;
                        }
                        for (int i = 0; i < n; i++){
                            int value;
                            value = randomNum(range, start);
                            if (isExists(root, value)){
                                std::cout << "This value (" << value << ") already exists\n";
                                i--;
                                continue;
                            }
                            insertValue(value);
                        }
                    }
                    break;
                    default:
                        std::cout << "Invalid fill type\n";
                        break;
                }
                std::cout << "Tree:\n";
                printTree(root);
                std::cout << "\nDepth of tree: " << findDepth(root) << "\n";

                Tree* evenTree = nullptr;
                Tree* oddTree = nullptr;
                copyTree(root, evenTree, oddTree);
                std::cout << "Even tree:\n";
                printTree(evenTree);
                std::cout << "\nDepth of even tree: " << findDepth(evenTree) << "\n";
                std::cout << "Odd tree:\n";
                printTree(oddTree);
                std::cout << "\nDepth of odd tree: " << findDepth(oddTree) << "\n";
                clearTree(root);
                root = nullptr;
                if (evenTree != nullptr){
                    clearTree(evenTree);
                    evenTree = nullptr;
                }
                if (oddTree != nullptr){
                    clearTree(oddTree);
                    oddTree = nullptr;
                }
                std::cout << "Trees cleared\n";
                }
            break;
            case 2:{
                std::ifstream fileToRead("Lab_9.txt");
                if (!fileToRead.is_open()){
                    std::cout << "File not found\n";
                    break;
                }
                int counter = 0;
                std::string line;
                while(std::getline(fileToRead, line)){
                    std::stringstream stringReading(line);
                    Computers comp;
                    stringReading >> comp.code >> comp.name >> comp.price;
                    insertComputer(comp);
                    counter++;
                }
                fileToRead.close();
                std::cout << "Your computers\n";
                double sum = 0, count = 0; 
                printComputers(compRoot);
                std::cout << "Average price is " << averagePrice(compRoot, sum, count);
                std::cout << "\nNumber of elements per layer\n";
                int* countNodes = new int[findDepth(compRoot)];
                for (int i = 0; i < findDepth(compRoot); i++){
                    countNodes[i] = 0;
                }
                int level = 0;
                countNodesAtLevel(compRoot, level, countNodes);
                for (int i = 0; i < findDepth(compRoot); i++){
                    std::cout << "Level " << i + 1 << ": " << countNodes[i] << "\n";
                }
                std::cout << "\nEnter code for what nodes should be deleted\n";
                int deleteCode;
                std::cin >> deleteCode;
                if (deleteCode > counter){
                    std::cout << "Code can't be higher than number of elements in tree\n";
                    break;
                }
                ComputerTree* deleteNode = findNode(compRoot, deleteCode);
                deleteChildren(deleteNode);
                std::cout << "Computers with deleted code node and deleted kids of node with code\n";
                printComputers(compRoot);
                clearComputer(compRoot);
                compRoot = nullptr;
                std::cout << "Computer tree is cleaned\n";
            }
            break;
            default:
                std::cout << "Invalid task number\n";
                break;
        }
    }
}