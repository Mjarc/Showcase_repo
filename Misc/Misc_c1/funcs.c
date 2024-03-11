#include "header.h"

bool isPrime(int num) {
    if (num <= 1) {
        return false; 
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}


// QUESTION 2 
void findPrimesInRange(int start, int end) { 
    for (int i = start; i<=end; i++)
    {
        if (isPrime(i)==true)
        {
            printf("%d ", i);
        }
    }
    printf("\n");  
}

// QUESTION 3
int greatestCommonDivisor(int a, int b) {
    if (a == 0) {
        return abs(b);
    }
    if (b == 0) {
        return abs(a);
    }

    int greatestdiv = 1;
    int smallest = (a < b) ? a : b;

    for (int i = 2; i <= smallest; i++) {
        if (a % i == 0 && b % i == 0) {
            greatestdiv = i;
        }
    }

    return greatestdiv;
}


int leastCommonMultiple(int a, int b) {
    int biggestnum;
    if (a >= b) {
        biggestnum = a;
    } else {
        biggestnum = b;
    }
    
    int LCM = (a * b) / greatestCommonDivisor(a, b);
    
    return LCM; 
}


int calculateOKEK(int num1, int num2, int num3) {
    int okek;
    okek = leastCommonMultiple(num1, leastCommonMultiple(num2, num3));
    return okek;
}


// QUESTION 4


int calculateOBEB(int num1, int num2, int num3) {
    int obeb;
    obeb = greatestCommonDivisor(num1, greatestCommonDivisor(num2, num3));
    return obeb;
}


// QUESTION 5
void findPrimeFactors(int num) {
    for (int i = 2; i <= num; i++) {
        while (num % i == 0) {
            if (isPrime(i)) {
                printf("%d", i);
                num = num / i;
                if (num > 1) {
                    printf(", ");
                }
            }
        }
    }
}


// QUESTION 6
int isTriangle(int a, int b, int c) { 
    if((a + b > c)&&(b + c > a)
            &&(c + a > b)) {  
        return 1;
    } else {  
        return 0;
    }  
}

//QUESTION 7
double calculateDistance(struct Point p1, struct Point p2) { 
    double dx = p1.x - p2.x; 
    double dy = p1.y - p2.y;

    double distance = sqrt(dx * dx + dy * dy);

    return distance;
}

// QUESTION 8
int collatz(int num) {
    if (num <= 0) {
        return -1;
    }

    int steps = 0;

    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        steps++;
    }

    return steps;
}



// QUESTION 9
int searchInArray(int arr[], int size, int target) {
    int count = 0;
    int positions[size];
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            positions[count] = i;
            count++;
        }
    }

    return count;
}

// QUESTION 10
// Print the matrix
void printMatrix(int mat[MAX_ROW][MAX_COL], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Calculate the sum of two matrices
int matrixAddition(int A[MAX_ROW][MAX_COL], int B[MAX_ROW][MAX_COL], int result[MAX_ROW][MAX_COL], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return 1; 
}

// Calculate the multiplication of two matrices
int matrixMultiplication(int A[MAX_ROW][MAX_COL], int B[MAX_ROW][MAX_COL], int result[MAX_ROW][MAX_COL], int m, int n, int p) {
    if (n != p) {
        return 0;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return 1;
}



// QUESTION 11
struct Line calculateLine(struct Point p1, struct Point p2) {
    struct Line line;

    if (p1.x == p2.x) {
        line.slope = INFINITY;
        line.y_intercept = NAN; 
    } else {
        line.slope = (p2.y - p1.y) / (p2.x - p1.x);
        line.y_intercept = p1.y - line.slope * p1.x;
    }

    return line;
}


