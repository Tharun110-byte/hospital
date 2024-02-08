/*
    Patient Management and Appointment Scheduling System

    This C program provides a simple implementation for managing patient records
    and scheduling appointments in a healthcare system. It utilizes structures to
    organize patient and appointment information and includes functions for adding
    patients and scheduling appointments.

    The program includes constants for maximum name length and maximum records to
    control the size of data structures. It uses structures to represent dates,
    patients, and appointments, each with specific attributes.

    Function Prototypes:
    - void addPatient(struct Patient patients[], int *patientCount);
    - void scheduleAppointment(struct Appointment appointments[], int *appointmentCount, struct Patient patients[], int patientCount);

    Note: The date of birth (dob) is expected to be formatted as "dd/mm/yyyy" in both
    the Patient and Appointment structures.



    Feel free to modify and extend the program according to specific requirements.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define constants for maximum name length and maximum records
#define MAX_NAME_LENGTH 50
#define MAX_RECORDS 100

// Define struct for Date
struct Date {
    int day;
    int month;
    int year;
};

// Define struct for Patient
struct Patient {
    int id;
    char name[MAX_NAME_LENGTH];
    char dob[12];
    char gender;
};

// Define struct for Appointment
struct Appointment {
    int id;
    int patientId;
     char type[20];
    char time[10];
};

// Function prototypes
void addPatient(struct Patient patients[], int *patientCount);
void scheduleAppointment(struct Appointment appointments[], int *appointmentCount);
int getMaxID();
void display();
void display2();

