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
   - 
  
 *  The program includes constants for maximum name length and maximum records to
    control the size of data structures. It uses structures to represent dates,
    patients, and appointments, each with specific attributes.

    Function Prototypes:
    - void addPatient(struct Patient patients[], int *patientCount);
    - void scheduleAppointment(struct Appointment appointments[], int *appointmentCount, struct Patient patients[], int patientCount);
  
   
* File: add.c
* The code is about adding the patient details
* In this we are adding the patient details which uses a function.
* In this code we are adding patient name,Date of Birth,gender.
* And this details will be printed in the .txt file,with the help of files concept. 
