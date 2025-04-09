#include <iostream>

int sumTillNumber(int number){
    if (number == 0) return 0;
    return number + sumTillNumber(number - 1);
}

int reverseNumber(int number){
    if (number == 0) return 0;
    std::cout << number % 10;
    return reverseNumber(number / 10);

}

double power(int base, int exponent){
    if (exponent < 0){
        exponent = -exponent;
    }
    if (exponent == 0) return 1;
    return base * power(base, exponent - 1);
}

int combine (int n, int k){
    if (k == 0 || k == n) return 1;
    return combine(n - 1, k - 1) + combine(n - 1, k);
}

int arithmeticProgression(int a, int d, int n){
    if (n == 0) return a;
    return arithmeticProgression(a, d, n - 1) + d;
}

int main() {
    srand(time(0));
    while (1){
    std::cout << "Enter number of task(1-5, 0 to exit): ";
    int task;
    std::cin >> task;
    switch (task){
        case 1:
        {
            std::cout << "Enter number\n";
            int number;
            std::cin >> number;
            std::cout << "Sum till " << number << " is " << sumTillNumber(number) << "\n";
        }
        break;
        case 2:
        {
            std::cout << "Enter number\n";
            int number;
            std::cin >> number;
            reverseNumber(number);
            std::cout << "\n";
        }
        break;
        case 3:
        {
            std::cout << "Enter base and exponent\n";
            int base, exponent;
            std::cin >> base >> exponent;
            if (exponent < 0){
                std::cout << base << "^" << exponent << " = " << "1/" << power(base, exponent) << " ("<< 1 / power(base, exponent)<< ")\n";
            }
            else {
                std::cout << base << "^" << exponent << " = " << power(base, exponent) << "\n";
            }
        }
        break;
        case 4:
        {
            std::cout << "Enter n and k\n";
            int n, k;
            std::cin >> n >> k;
            if (k > n) {
                std::cout << "k cannot be greater than n\n";
                break;
            }
            std::cout << "C(" << n << ", " << k << ") = " << combine(n, k) << "\n";
        }
        break;
        case 5:
        {
            std::cout << "Enter start, difference and arifmetic progression number\n";
            int a, d, n;
            std::cin >> a >> d >> n;
            n--;
            if (n < -1) {
                std::cout << "n cannot be negative\n";
                break;
            }
            std::cout << "AP(" << a << ", " << d << ", " << n + 1 << ") = " << arithmeticProgression(a, d, n) << "\n";
        }
        break;
        default:
            std::cout << "Wrong choice\n";
        break;
    } 
    }
    return 0;
}