#include <iostream>
#include <vector>
#include <iomanip>

void printGraph(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    std::cout << "Adjacency matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            std::cout << std::setw(3) << matrix[i][j] << " ";
        std::cout << "\n";
    }
}

void fillGraph(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            if (i == j)
                matrix[i][j] = 0;
            if (i != j && matrix[i][j] == -1){
                std::cout << "Enter distance between cities " << i + 1 << " and " << j + 1 << ": ";
                int distance;
                std::cin >> distance;  
                if (distance < 0) {
                    std::cout << "Distance cannot be negative. Please enter a valid distance: ";
                    std::cin >> distance;
                } 
                matrix[i][j] = distance;
                matrix[j][i] = distance;
            }
        }
}


bool isCompleteGraph(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && matrix[i][j] == 0)
                return false;
    return true;
}

double averagePathLength(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int sum = 0, count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (matrix[i][j] > 0) {
                sum += matrix[i][j];
                ++count;
            }
    return count > 0 ? double(sum / count) : 0.0;
}

void listOfAdjacency(const std::vector<std::vector<int>>& matrix){
    int n = matrix.size();
    for (int i = 0; i < n; i++){
        std::vector<int> temp;
        for (int j = 0; j < n; j++){
            if (matrix[i][j] != 0){
                temp.push_back(matrix[i][j]);
            }
        }
        std::cout << "Cities connected to " << i + 1 << " city is ";
        if (temp.empty()){
            std::cout << "None\n";
        }
        else {
            for (auto element : temp){
                std::cout << element << " ";
            }
            std::cout << "\n";
        }
    }
}

std::vector<int> findIsolated(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    std::vector<int> isolated;
    for (int i = 0; i < n; ++i) {
        int connections = 0;
        for (int j = 0; j < n; ++j)
            if (matrix[i][j] > 0)
                ++connections;
        if (connections == 1)
            isolated.push_back(i);
    }
    return isolated;
}

void longestPathThreeCities(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int maxDistance = -1;
    int a = -1, b = -1, c = -1;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k) {
                if (i != j && j != k && i != k &&
                    matrix[i][j] > 0 && matrix[j][k] > 0) {
                    int distance = matrix[i][j] + matrix[j][k];
                    if (distance > maxDistance) {
                        maxDistance = distance;
                        a = i; b = j; c = k;
                    }
                }
            }
    if (maxDistance != -1)
        std::cout << "(" << a + 1 << ") --- " << matrix[a][b] << " --- (" << b + 1 << ") --- " << matrix[b][c] << " --- (" << c + 1 << ")\n";
    else
        std::cout << "No valid route between three cities.\n";
}

bool isConnected(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    std::vector<bool> visited(n, false);
    std::vector<int> stack;

    stack.push_back(0);
    visited[0] = true;

    while (!stack.empty()) {
        int v = stack.back();
        stack.pop_back();
        for (int i = 0; i < n; ++i) {
            if (matrix[v][i] > 0 && !visited[i]) {
                visited[i] = true;
                stack.push_back(i);
            }
        }
    }

    for (bool v : visited)
        if (!v)
            return false;
    return true;
}

int main() {
    while (1){
        std::cout << "Enter the number of settlements, 0 for exit: ";
        int n;
        std::cin >> n;
        if (n <= 0) {
            return 0;
        }
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, -1));
        std::cout << "Enter the adjacency matrix \n";
        fillGraph(matrix);
        printGraph(matrix);
        std::cout << "List:\n";
        listOfAdjacency(matrix);
        std::cout << "\nIs the graph complete? " << (isCompleteGraph(matrix) ? "Yes" : "No") << "\n";
        std::cout << "Average path length: " << averagePathLength(matrix) << "\n";
    
        std::vector<int> isolated = findIsolated(matrix);
        if (!isolated.empty()) {
            std::cout << "Isolated settlements: ";
            for (int idx : isolated)
                std::cout << (idx + 1) << " ";
            std::cout << "\n";
        } else {
            std::cout << "No isolated settlements.\n";
        }
    
        std::cout << "\nLongest route between three cities:\n";
        longestPathThreeCities(matrix);
    
        std::cout << "\nCan we visit all settlements exactly once? ";
        std::cout << (isConnected(matrix) ? "Yes" : "No") << "\n";
    }
    return 0;
}
