#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include the header file that contains struct definitions and function prototypes
#include "main.h"

// Define constants for maximum name length and maximum records
#define MAX_NAME_LENGTH 50
#define MAX_RECORDS 100

// Main function
int main() {
    // Declare arrays of structs to store patient and appointment information
    struct Patient patients[MAX_RECORDS];
    struct Appointment appointments[MAX_RECORDS];

    // Initialize counters for patient, appointment, and billing records
    int patientCount = 0;
    int appointmentCount = 0;
    int billingCount = 0;

    // Variable to store user's choice
    int choice;

    // Main menu loop
    do {
        // Display menu options
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Schedule Appointment\n");
       
        printf("3. Exit\n");
        printf("Enter your choice: ");

        // Read user's choice
        scanf("%d", &choice);

        // Switch statement to perform actions based on user's choice
        switch (choice) {
            case 1:
                // Call function to add a new patient
                addPatient(patients, &patientCount);
                break;
            case 2:
                // Call function to schedule a new appointment
                scheduleAppointment(appointments, &appointmentCount, patients, patientCount);
                break;
            
            case 3:
                // Display message and exit the program
                printf("Exiting the program.\n");
                break;
            default:
                // Display message for an invalid choice
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);  // Continue the loop until the user chooses to exit

    // Return 0 to indicate successful program execution
    return 0;
}
