#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_DOCTORS 50
#define MAX_ROOMS 50
#define MAX_BILLS 100

//  STRUCTURES 

typedef struct {
    int id;
    char name[100];
    int age;
    char disease[100];
    int doctorId;
    int roomNumber;
} Patient;

typedef struct {
    int id;
    char name[100];
    char specialization[100];
} Doctor;

typedef struct {
    int roomNumber;
    int isOccupied;
} Room;

typedef struct {
    int billId;
    int patientId;
    float amount;
    char status[20];
} Bill;

//  GLOBAL ARRAYS 

Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
Room rooms[MAX_ROOMS];
Bill bills[MAX_BILLS];

//  COUNTERS 

int patientCount = 0;
int doctorCount = 0;
int roomCount = 0;
int billCount = 0;

//  FUNCTION PROTOTYPES 

void addPatient();
void addDoctor();
void addRoom();
void generateBill();

void displayPatients();
void displayDoctors();
void displayRooms();
void displayBills();

void searchPatient();
void updatePatient();
void deletePatient();

void saveData();
void loadData();

void clearInputBuffer();
void getStringInput(char str[], int size);

int findPatientIndexById(int id);
int findDoctorIndexById(int id);
int findRoomIndexByNumber(int roomNumber);

//  UTILITY FUNCTIONS 

void clearInputBuffer() {
    while (getchar() != '\n');
}

void getStringInput(char str[], int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

//  SEARCH FUNCTIONS 

int findPatientIndexById(int id) {
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            return i;
        }
    }
    return -1;
}

int findDoctorIndexById(int id) {
    for (int i = 0; i < doctorCount; i++) {
        if (doctors[i].id == id) {
            return i;
        }
    }
    return -1;
}

int findRoomIndexByNumber(int roomNumber) {
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            return i;
        }
    }
    return -1;
}

//  ADD FUNCTIONS 

void addDoctor() {
    if (doctorCount >= MAX_DOCTORS) {
        printf("Doctor limit reached.\n");
        return;
    }

    Doctor d;

    d.id = doctorCount + 1;

    clearInputBuffer();

    printf("Enter doctor name: ");
    getStringInput(d.name, sizeof(d.name));

    printf("Enter specialization: ");
    getStringInput(d.specialization, sizeof(d.specialization));

    doctors[doctorCount] = d;
    doctorCount++;

    saveData();

    printf("Doctor added successfully.\n");
}

void addRoom() {
    if (roomCount >= MAX_ROOMS) {
        printf("Room limit reached.\n");
        return;
    }

    Room r;

    printf("Enter room number: ");
    scanf("%d", &r.roomNumber);

    if (findRoomIndexByNumber(r.roomNumber) != -1) {
        printf("Room already exists.\n");
        return;
    }

    r.isOccupied = 0;

    rooms[roomCount] = r;
    roomCount++;

    saveData();

    printf("Room added successfully.\n");
}

void addPatient() {

    if (patientCount >= MAX_PATIENTS) {
        printf("Patient limit reached.\n");
        return;
    }

    if (doctorCount == 0 || roomCount == 0) {
        printf("Please add doctors and rooms first.\n");
        return;
    }

    Patient p;

    p.id = patientCount + 1;

    clearInputBuffer();

    printf("Enter patient name: ");
    getStringInput(p.name, sizeof(p.name));

    do {
        printf("Enter patient age: ");
        scanf("%d", &p.age);

        if (p.age <= 0) {
            printf("Invalid age.\n");
        }

    } while (p.age <= 0);

    clearInputBuffer();

    printf("Enter disease: ");
    getStringInput(p.disease, sizeof(p.disease));

    printf("\n===== AVAILABLE DOCTORS =====\n");
    displayDoctors();

    printf("Enter doctor ID: ");
    scanf("%d", &p.doctorId);

    if (findDoctorIndexById(p.doctorId) == -1) {
        printf("Invalid doctor ID.\n");
        return;
    }

    printf("\n===== AVAILABLE ROOMS =====\n");
    displayRooms();

    printf("Enter room number: ");
    scanf("%d", &p.roomNumber);

    int roomIndex = findRoomIndexByNumber(p.roomNumber);

    if (roomIndex == -1) {
        printf("Room not found.\n");
        return;
    }

    if (rooms[roomIndex].isOccupied == 1) {
        printf("Room already occupied.\n");
        return;
    }

    rooms[roomIndex].isOccupied = 1;

    patients[patientCount] = p;
    patientCount++;

    saveData();

    printf("Patient added successfully.\n");
}

//  DISPLAY FUNCTIONS 

void displayPatients() {

    if (patientCount == 0) {
        printf("No patients available.\n");
        return;
    }

    for (int i = 0; i < patientCount; i++) {

        printf("\n=======\n");
        printf("Patient ID   : %d\n", patients[i].id);
        printf("Name         : %s\n", patients[i].name);
        printf("Age          : %d\n", patients[i].age);
        printf("Disease      : %s\n", patients[i].disease);
        printf("Doctor ID    : %d\n", patients[i].doctorId);
        printf("Room Number  : %d\n", patients[i].roomNumber);
    }
}

void displayDoctors() {

    if (doctorCount == 0) {
        printf("No doctors available.\n");
        return;
    }

    for (int i = 0; i < doctorCount; i++) {

        printf("Doctor ID: %d | Name: %s | Specialization: %s\n",
               doctors[i].id,
               doctors[i].name,
               doctors[i].specialization);
    }
}

void displayRooms() {

    if (roomCount == 0) {
        printf("No rooms available.\n");
        return;
    }

    for (int i = 0; i < roomCount; i++) {

        printf("Room Number: %d | Occupied: %s\n",
               rooms[i].roomNumber,
               rooms[i].isOccupied ? "Yes" : "No");
    }
}

void displayBills() {

    if (billCount == 0) {
        printf("No bills available.\n");
        return;
    }

    for (int i = 0; i < billCount; i++) {

        printf("\n=======\n");
        printf("Bill ID     : %d\n", bills[i].billId);
        printf("Patient ID  : %d\n", bills[i].patientId);
        printf("Amount      : %.2f\n", bills[i].amount);
        printf("Status      : %s\n", bills[i].status);
    }
}

//  BILL FUNCTION 

void generateBill() {

    if (patientCount == 0) {
        printf("No patients available.\n");
        return;
    }

    Bill b;

    b.billId = billCount + 1;

    printf("Enter patient ID: ");
    scanf("%d", &b.patientId);

    if (findPatientIndexById(b.patientId) == -1) {
        printf("Patient not found.\n");
        return;
    }

    do {

        printf("Enter amount: ");
        scanf("%f", &b.amount);

        if (b.amount < 0) {
            printf("Amount cannot be negative.\n");
        }

    } while (b.amount < 0);

    strcpy(b.status, "UNPAID");

    bills[billCount] = b;
    billCount++;

    saveData();

    printf("Bill generated successfully.\n");
}

//  SEARCH FUNCTION 

void searchPatient() {

    int id;

    printf("Enter patient ID: ");
    scanf("%d", &id);

    int index = findPatientIndexById(id);

    if (index == -1) {
        printf("Patient not found.\n");
        return;
    }

    printf("\n===== PATIENT FOUND =====\n");

    printf("Name        : %s\n", patients[index].name);
    printf("Age         : %d\n", patients[index].age);
    printf("Disease     : %s\n", patients[index].disease);
    printf("Doctor ID   : %d\n", patients[index].doctorId);
    printf("Room Number : %d\n", patients[index].roomNumber);
}

//  UPDATE FUNCTION 

void updatePatient() {

    int id;

    printf("Enter patient ID to update: ");
    scanf("%d", &id);

    int index = findPatientIndexById(id);

    if (index == -1) {
        printf("Patient not found.\n");
        return;
    }

    clearInputBuffer();

    printf("Enter new name: ");
    getStringInput(patients[index].name, sizeof(patients[index].name));

    printf("Enter new disease: ");
    getStringInput(patients[index].disease, sizeof(patients[index].disease));

    printf("Enter new age: ");
    scanf("%d", &patients[index].age);

    saveData();

    printf("Patient updated successfully.\n");
}

//  DELETE FUNCTION 

void deletePatient() {

    int id;

    printf("Enter patient ID to delete: ");
    scanf("%d", &id);

    int index = findPatientIndexById(id);

    if (index == -1) {
        printf("Patient not found.\n");
        return;
    }

    int roomIndex = findRoomIndexByNumber(patients[index].roomNumber);

    if (roomIndex != -1) {
        rooms[roomIndex].isOccupied = 0;
    }

    for (int i = index; i < patientCount - 1; i++) {
        patients[i] = patients[i + 1];
    }

    patientCount--;

    saveData();

    printf("Patient deleted successfully.\n");
}

//  FILE HANDLING 

void saveData() {

    FILE *fp;

    fp = fopen("patients.dat", "wb");

    if (fp != NULL) {
        fwrite(&patientCount, sizeof(int), 1, fp);
        fwrite(patients, sizeof(Patient), patientCount, fp);
        fclose(fp);
    }

    fp = fopen("doctors.dat", "wb");

    if (fp != NULL) {
        fwrite(&doctorCount, sizeof(int), 1, fp);
        fwrite(doctors, sizeof(Doctor), doctorCount, fp);
        fclose(fp);
    }

    fp = fopen("rooms.dat", "wb");

    if (fp != NULL) {
        fwrite(&roomCount, sizeof(int), 1, fp);
        fwrite(rooms, sizeof(Room), roomCount, fp);
        fclose(fp);
    }

    fp = fopen("bills.dat", "wb");

    if (fp != NULL) {
        fwrite(&billCount, sizeof(int), 1, fp);
        fwrite(bills, sizeof(Bill), billCount, fp);
        fclose(fp);
    }
}

void loadData() {

    FILE *fp;

    fp = fopen("patients.dat", "rb");

    if (fp != NULL) {
        fread(&patientCount, sizeof(int), 1, fp);
        fread(patients, sizeof(Patient), patientCount, fp);
        fclose(fp);
    }

    fp = fopen("doctors.dat", "rb");

    if (fp != NULL) {
        fread(&doctorCount, sizeof(int), 1, fp);
        fread(doctors, sizeof(Doctor), doctorCount, fp);
        fclose(fp);
    }

    fp = fopen("rooms.dat", "rb");

    if (fp != NULL) {
        fread(&roomCount, sizeof(int), 1, fp);
        fread(rooms, sizeof(Room), roomCount, fp);
        fclose(fp);
    }

    fp = fopen("bills.dat", "rb");

    if (fp != NULL) {
        fread(&billCount, sizeof(int), 1, fp);
        fread(bills, sizeof(Bill), billCount, fp);
        fclose(fp);
    }
}

//  MAIN FUNCTION 

int main() {

    int choice;

    loadData();

    while (1) {

        printf("\n========== HOSPITAL MANAGEMENT SYSTEM ==========\n");

        printf("1. Add Patient\n");
        printf("2. Add Doctor\n");
        printf("3. Add Room\n");
        printf("4. Generate Bill\n");
        printf("5. Display Patients\n");
        printf("6. Display Doctors\n");
        printf("7. Display Rooms\n");
        printf("8. Display Bills\n");
        printf("9. Search Patient\n");
        printf("10. Update Patient\n");
        printf("11. Delete Patient\n");
        printf("12. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addPatient();
                break;

            case 2:
                addDoctor();
                break;

            case 3:
                addRoom();
                break;

            case 4:
                generateBill();
                break;

            case 5:
                displayPatients();
                break;

            case 6:
                displayDoctors();
                break;

            case 7:
                displayRooms();
                break;

            case 8:
                displayBills();
                break;

            case 9:
                searchPatient();
                break;

            case 10:
                updatePatient();
                break;

            case 11:
                deletePatient();
                break;

            case 12:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}