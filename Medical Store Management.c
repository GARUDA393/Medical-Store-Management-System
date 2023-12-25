#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_MEDICINES 100

// Define structures for Customer and Medicine
typedef struct {
    int customerID;
    char name[50];
    char address[100];
    char phone[15];
} Customer;

typedef struct {
    int medicineID;
    char name[50];
    char type[50];
    float price;
    char expiryDate[15];
    int quantity;
} Medicine;

// Global arrays for customers and medicines
Customer customers[MAX_CUSTOMERS];
Medicine medicines[MAX_MEDICINES];
int numCustomers = 0;
int numMedicines = 0;

// Function prototypes
void createCustomer();
void updateCustomer();
void deleteCustomer();
void salesReport();
void medicineStock();
void customerReport();

int main() {
    int choice;

    do {
        printf("\nMedical Store Management System\n");
        printf("1. Create Customer\n");
        printf("2. Update Customer\n");
        printf("3. Delete Customer\n");
        printf("4. Sales Report\n");
        printf("5. Medicine Stock\n");
        printf("6. Customer Report\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createCustomer();
                break;
            case 2:
                updateCustomer();
                break;
            case 3:
                deleteCustomer();
                break;
            case 4:
                salesReport();
                break;
            case 5:
                medicineStock();
                break;
            case 6:
                customerReport();
                break;
            case 7:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

// Function to create a new customer
void createCustomer() {
    if (numCustomers >= MAX_CUSTOMERS) {
        printf("Customer database full. Cannot add more customers.\n");
        return;
    }

    Customer newCustomer;
    printf("Enter customer name: ");
    scanf("%s", newCustomer.name);
    printf("Enter address: ");
    scanf("%s", newCustomer.address);
    printf("Enter phone number: ");
    scanf("%s", newCustomer.phone);

    newCustomer.customerID = numCustomers + 1;
    customers[numCustomers++] = newCustomer;
    printf("Customer created successfully with ID: %d\n", newCustomer.customerID);
}

// Function to update customer information
void updateCustomer() {
    int customerID;
    printf("Enter customer ID to update: ");
    scanf("%d", &customerID);

    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].customerID == customerID) {
            printf("Enter updated name: ");
            scanf("%s", customers[i].name);
            printf("Enter updated address: ");
            scanf("%s", customers[i].address);
            printf("Enter updated phone number: ");
            scanf("%s", customers[i].phone);
            printf("Customer information updated successfully.\n");
            return;
        }
    }
    printf("Customer ID not found. Update failed.\n");
}

// Function to delete a customer
void deleteCustomer() {
    int customerID;
    printf("Enter customer ID to delete: ");
    scanf("%d", &customerID);

    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].customerID == customerID) {
            for (int j = i; j < numCustomers - 1; j++) {
                customers[j] = customers[j + 1];
            }
            numCustomers--;
            printf("Customer deleted successfully.\n");
            return;
        }
    }
    printf("Customer ID not found. Deletion failed.\n");
}

// Function to display sales report
void salesReport() {
    // Write logic to display sales report
    printf("Sales Report Functionality to be implemented.\n");
}

// Function to display medicine stock
void medicineStock() {
    // Write logic to display medicine stock
    printf("Medicine Stock Functionality to be implemented.\n");
}

// Function to display customer report
void customerReport() {
    // Write logic to display customer report
    printf("Customer Report Functionality to be implemented.\n");
}
