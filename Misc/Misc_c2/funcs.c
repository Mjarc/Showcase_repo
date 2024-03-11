#include "header.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 50
#define INPUT_SIZE 50
#define INT_TOKEN 50
#define ARRAY_LEN 50

void charPermu(char *cht) {
    int length = strlen(cht);
    charPermuHelper(cht, 0, length - 1);
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void charPermuHelper(char *cht, int left, int right) {
    if (left == right) {
        printf("%s\n", cht);
    } else {
        for (int i = left; i <= right; i++) {
            swap(&cht[left], &cht[i]);
            charPermuHelper(cht, left + 1, right);
            swap(&cht[left], &cht[i]); 
        }
    }
}

int calculateLength(char* ch) {
    return strlen(ch);
}

int findFact(const int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * findFact(n - 1);
    }
}

int are_friends(const int number1, const int number2) {
    int sum_div1 = 0;
    for (int i = 1; i <= number1 / 2; i++) {
        if (number1 % i == 0) {
            sum_div1 += i;
        }
    }

    int sum_div2 = 0;
    for (int i = 1; i <= number2 / 2; i++) {
        if (number2 % i == 0) {
            sum_div2 += i;
        }
    }
    return (sum_div1 == number2) && (sum_div2 == number1);
}

int is_harshad(int number) {
    int original_number = number;
    int sum_of_digits = 0;
    
    while (number > 0) {
        sum_of_digits += number % 10;
        number /= 10;
    }
    
    return (original_number % sum_of_digits == 0);
}

int digital_root(int num) {
    while (num > 9) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}

int isConsecutive(int length, int arr[]) {
    for (int i = 1; i < length; i++) {
        if (arr[i] != arr[i - 1] + 1) {
            return 0; 
        }
    }
    return 1; 
}

int findMissingSmallest(int length, int arr[]) {
    int n = length;
    int* present = (int*)calloc(n + 2, sizeof(int));
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0 && arr[i] <= n) {
            present[arr[i]] = 1;
        }
    }
    int smallest = 0;
    while (smallest <= n && present[smallest] == 1) {
        smallest++;
    }
    free(present);
    return smallest;
}






int day_of_year(int day, int mon, int year) {
    if (mon < 1 || mon > 12 || day < 1 || day > 31) {
        return -1; 
    }

    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        days_in_month[2] = 29; 
    }

    if (mon < 1 || mon > 12 || day < 1 || day > days_in_month[mon]) {
        return -1; 
    }

    int day_of_year = day;
    for (int i = 1; i < mon; i++) {
        day_of_year += days_in_month[i];
    }

    return day_of_year;
}

int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

int closest_prime(int value) {
    if (value <= 2) return -1; 
    if (isPrime(value)) return value; 

    int smaller = value - 1;
    while (smaller >= 2) {
        if (isPrime(smaller)) {
            return smaller;
        }
        smaller--;
    }
    return -1; 
}

void findHardyRamanujanNumbers(int limit) {
    for (int N = 1; N <= limit; N++) {
        for (int a = 1; a <= N; a++) {
            for (int b = a; b <= N; b++) {
                int c_start = b;
                int d_start = b;
                while (c_start <= N && d_start <= N) {
                    int sum = pow(a, 3) + pow(b, 3) + pow(c_start, 3) + pow(d_start, 3);
                    if (sum == N) {
                        printf("%d = %d^3 + %d^3 = %d^3 + %d^3\n", N, a, b, c_start, d_start);
                    }
                    if (sum >= N) {
                        break; 
                    }
                    d_start++;
                }
                if (pow(a, 3) + pow(b, 3) >= N) {
                    break; 
                }
            }
        }
    }
}


