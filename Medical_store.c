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
    char manufacturingDate[15];
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
void deleteCustomer();
void medicineStock();
void CustomerReport();


int main() {
    int choice;

    do {
        printf("\nMedical Store Management System\n");
        printf("1. Create Customer\n");
        printf("2. Delete Customer\n");
        printf("3. Medicine Stock\n");
        printf("4. Customer Report\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createCustomer();
                break;
            case 2:
                deleteCustomer();
                break;
            case 3:
                medicineStock();
                break;
            case 4:
                CustomerReport();
                break;
            case 5:
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

// Function to display medicine stock - from supplier's database(list)
void medicineStock() {
    printf("\nMedicine Stock Details\n");
    printf("-----------------------------------------------------\n");
    printf("Medicine ID | Name          | Type          | Price | Manufacturing Date | Expiry Date\n");
    printf("-----------------------------------------------------\n");
    printf("01     Paracetamol      Tablet       100     12/11/2023   12/11/2026\n");
    printf("02     CoughGel         Syrup        50      09/09/2023   15/08/2025\n");
    printf("03     Cotton Crepe     Bandage      75      10/12/2023   15/12/2030\n");
    printf("04     Zhandu Balm      Ointment     30      20/10/2023   20/04/2024\n");
    printf("05     Crocin           Tablet       10      25/12/2023   20/05/2024\n");
    printf("06     Insulin          Injection    300     18/10/2023   18/05/2024\n");
    printf("07     Sinarest         Tablet       75      12/11/2023   12/11/2026\n");
    printf("08     Cremaffin        Syrup        45      30/08/2023   30/02/2024\n");
    printf("09     Volini           Spray        125     31/08/2023   31/04/2024\n");
    printf("10     Surgical Mask    Mask         10      25/11/2023   ---\n");
    
    
    for (int i = 0; i < numMedicines; i++) {
        printf("%-11d | %-13s | %-13s | %.2f  | %-17s | %-11s\n",
               medicines[i].medicineID, medicines[i].name, medicines[i].type,
               medicines[i].price, medicines[i].manufacturingDate, medicines[i].expiryDate);
    }
    printf("-----------------------------------------------------\n");
}




// Function to display customer report
void CustomerReport() {
    printf("\nCustomer Report\n");
    printf("------------------------------------------------------\n");
    printf("Customer ID | Name          | Address          | Phone\n");
    printf("------------------------------------------------------\n");

    for (int i = 0; i < numCustomers; i++) {
        printf("%-12d | %-14s | %-16s | %-10s\n",
               customers[i].customerID, customers[i].name, customers[i].address, customers[i].phone);
    }
    printf("------------------------------------------------------\n");
}