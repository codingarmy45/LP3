#include <iostream>
using namespace std;

// Recursive function to calculate Fibonacci number
int recursive_fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
    }
}

// Non-recursive function to calculate Fibonacci sequence
void non_recursive_fibonacci(int n) {
    int first = 0, second = 1;
    int step_count = 2;

    if (n >= 1) {
        cout << first << endl;  // Print the first term
    }
    if (n >= 2) {
        cout << second << endl;  // Print the second term
    }

    while (step_count < n) {
        int third = first + second;
        cout << third << endl;  // Print the next term in the sequence
        first = second;
        second = third;
        step_count++;
    }
}

int main() {
    int n;
    cout << "Enter the nth term: ";
    cin >> n;

    cout << "The Fibonacci sequence using recursive function:" << endl;
    for (int i = 0; i < n; i++) {
        cout << recursive_fibonacci(i) << endl;
    }

    cout << "The Fibonacci sequence using non-recursive function:" << endl;
    non_recursive_fibonacci(n);
    
    return 0;
}
