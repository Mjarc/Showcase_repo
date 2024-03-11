#include "queue.h"
#define MAX_SIZE 10
#define INPUT_SIZE 1

int main() {
    char input[INPUT_SIZE];
    scanf("%s", input);
    int case_no = atoi(input);

    switch (case_no) {
        case 1:
            printf("Using customer and non-customer queues:\n");
            printf("---------------------------------------\n");

            struct queue *bankQueueCustomer = create(5);
            struct queue *bankQueueNonCustomer = create(5);

            for (int i = 0; i < 4; i++) {
                struct person nonCustomer = {false, 0.0};
                add(bankQueueNonCustomer, nonCustomer);
            }

            for (int i = 0; i < 2; i++) {
                struct person customer = {true, 100.0};
                add(bankQueueCustomer, customer);
            }

            while (!is_empty(bankQueueCustomer) || !is_empty(bankQueueNonCustomer)) {
                if (!is_empty(bankQueueCustomer)) {
                    struct person customer = remove_person(bankQueueCustomer);

                } else if (!is_empty(bankQueueNonCustomer)) {
                    struct person nonCustomer = remove_person(bankQueueNonCustomer);

                }
            }

            printf("Customer queue:\n");
            display_all(bankQueueCustomer);
            printf("Non-customer queue:\n");
            display_all(bankQueueNonCustomer);
            printf("\n");
            break;

        case 2:
            printf("Using solely one queue:\n");
            printf("------------------------\n");

            struct queue *bankQueue = create(10);

            for (int i = 0; i < 5; i++) {
                struct person nonCustomer = {false, 0.0};
                add(bankQueue, nonCustomer);
            }

            for (int i = 0; i < 2; i++) {
                struct person customer = {true, 100.0};
                add_customer(bankQueue, customer);
            }

            for (int i = 0; i < 4; i++) {
                struct person nonCustomer = {false, 0.0};
                add(bankQueue, nonCustomer);
            }

            for (int i = 0; i < 2; i++) {
                remove_person(bankQueue);
            }

            struct person nonCustomer = {false, 0.0};
            add(bankQueue, nonCustomer);

            printf("Final queue:\n");
            display_all(bankQueue);
            printf("\n");
            break;
    }

    return 0;
}

