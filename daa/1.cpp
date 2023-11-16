#include <iostream>
#include <vector>
using namespace std;

vector<int> f; // Declare the Fibonacci sequence vector globally

int iStepFibbonacci(int n) {
    f.push_back(0);
    f.push_back(1);
    
    for (int i = 2; i <= n; i++) {
        f.push_back(f[i - 1] + f[i - 2]);
    }
    
    return f[n]; // Return the nth Fibonacci number, not 'n'
}

int rSteps = 0; // Count recursive steps

int rStepFibbonacci(int n) {
    rSteps++;
    if (n < 0)
        return 0;
    if (n == 1 || n == 0)
        return 1;
    return rStepFibbonacci(n - 1) + rStepFibbonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter NO: ";
    cin >> n;

    // Clear the global vector before each run
    f.clear();

    // Calculate Fibonacci values and steps
    int fibI = iStepFibbonacci(n);
    int fibR = rStepFibbonacci(n);

    cout << "Fibonacci Value (Iteration): " << fibI << '\n';
    cout << "Fibonacci Value (Recursion): " << fibR << '\n';
    cout << "Steps required using Iteration: " << n << '\n';
    cout << "Steps required using Recursion: " << rSteps << '\n';

    return 0;
}
