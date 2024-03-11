#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define MAX_STRING_LENGTH 50
#define INPUT_SIZE 50
#define INT_TOKEN 50
#define ARRAY_LEN 50

void charPermuHelper(char *cht, int left, int right);

void charPermu(char *cht);

int calculateLength(char* ch);

int findFact(const int n);

int are_friends(const int number1, const int number2);

int is_harshad(int number);

int digital_root(int num);

int isConsecutive(int length, int arr[]);

int findMissingSmallest(int length, int arr[]);

int day_of_year(int day, int mon, int year);

int closest_prime(int value);

void findHardyRamanujanNumbers(int limit);

#endif
