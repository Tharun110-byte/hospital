 /*
 * Hospital Management System

 * Description:
 * This program is a simple hospital management system designed to manage patient
 * information and appointments. It allows users to add new patients, schedule appointments,
 * and perform other administrative tasks. The system utilizes structure to represent
 * patient and appointment records, and provides a menu-driven interface for users to
 * interact with the system.
 *
 * File: main.c
 * - This file contains the main function and serves as the entry point for the program.
 * - It includes necessary header files, defines constants, and implements the main menu loop.
 *
 * Usage:
 * - Compile the program using a C compiler (e.g., gcc).
 * - Execute the compiled binary to run the hospital management system.
 * - Follow the on-screen prompts to add patients, schedule appointments, and exit the program.
 *
 * Note: This program is for educational purposes and may require additional enhancements
 * for real-world use cases such as error handling, data validation, and persistence.
 */

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
    struct Patient patients[MAX_RECORDS];  // Array to store patient records
    struct Appointment appointments[MAX_RECORDS];  // Array to store appointment records

    // Initialize counters for patient, appointment, and billing records
    int patientCount = 0;  // Counter for patient records
    int appointmentCount = 0;  // Counter for appointment records
    int billingCount = 0;  // Counter for billing records

    // Variable to store user's choice
    int choice;

    // Main menu loop
    do {
        // Display menu options
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");  // Option to add a new patient
        printf("2. Schedule Appointment\n");  // Option to schedule a new appointment

        printf("3. Exit\n");  // Option to exit the program
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
    } while (choice != 3);  // Continue the loop until the user chooses to exit

    // Return 0 to indicate successful program execution
    return 0;
}
