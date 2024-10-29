#include <stdio.h>

void fibonacci(int, long int, long int);

int main() {
    int n;
    long int i = 0, j = 1;
    
    printf("Enter the range of the Fibonacci series: ");
    scanf("%d", &n);
    
    printf("Fibonacci Series: ");
    printf("%ld %ld ", i, j);
    
    fibonacci(n - 2, i, j); // We already printed the first two numbers, so n - 2 more to generate.
    
    return 0;
}

void fibonacci(int n, long int first, long int second) {
    if (n > 0) {
        long int sum = first + second;
        first = second;
        second = sum;
        printf("%ld ", sum);
        fibonacci(n - 1, first, second);
    }
}
