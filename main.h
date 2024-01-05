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
    char dob[12];
    char time[10];
};

// Function prototypes
void addPatient(struct Patient patients[], int *patientCount);
void scheduleAppointment(struct Appointment appointments[], int *appointmentCount, struct Patient patients[], int patientCount);