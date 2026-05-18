#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PATIENTS 100
#define MAX_NAME 50
#define MAX_DISEASE 100
#define FILE_NAME "patients.dat"


// STRUCTURE DECLARATION

typedef struct
{
    int id;
    char name[MAX_NAME];
    int age;
    char gender[10];
    char disease[MAX_DISEASE];
    char admissionDate[20];
    float bill;
} Patient;


// FUNCTION PROTOTYPES

void addPatient();
void displayPatients();
void searchPatient();
void updatePatient();
void deletePatient();
void generateBillReport();
void sortPatients();
void backupDatabase();
void login();
void clearInputBuffer();


// MAIN FUNCTION

int main()
{
    login();

    int choice;

    while (1)
    {
        printf("\n===========================================\n");
        printf("     HOSPITAL MANAGEMENT SYSTEM\n");
        printf("===========================================\n");
        printf("1. Add Patient\n");
        printf("2. Display All Patients\n");
        printf("3. Search Patient\n");
        printf("4. Update Patient Record\n");
        printf("5. Delete Patient Record\n");
        printf("6. Generate Billing Report\n");
        printf("7. Sort Patients by Name\n");
        printf("8. Backup Database\n");
        printf("9. Exit\n");
        printf("===========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addPatient();
            break;
        case 2:
            displayPatients();
            break;
        case 3:
            searchPatient();
            break;
        case 4:
            updatePatient();
            break;
        case 5:
            deletePatient();
            break;
        case 6:
            generateBillReport();
            break;
        case 7:
            sortPatients();
            break;
        case 8:
            backupDatabase();
            break;
        case 9:
            printf("\nExiting program... Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}


// LOGIN FUNCTION

void login()
{
    char username[30];
    char password[30];

    printf("===========================================\n");
    printf("        HOSPITAL SYSTEM LOGIN\n");
    printf("===========================================\n");

    while (1)
    {
        printf("Username: ");
        scanf("%s", username);

        printf("Password: ");
        scanf("%s", password);

        if (strcmp(username, "admin") == 0 && strcmp(password, "1234") == 0)
        {
            printf("\nLogin successful!\n");
            break;
        }
        else
        {
            printf("Incorrect username or password. Try again.\n\n");
        }
    }
}


// ADD PATIENT

void addPatient()
{
    FILE *fp;
    Patient p;

    fp = fopen(FILE_NAME, "ab");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Patient ID: ");
    scanf("%d", &p.id);

    clearInputBuffer();

    printf("Enter Name: ");
    fgets(p.name, MAX_NAME, stdin);
    p.name[strcspn(p.name, "\n")] = '\0';

    printf("Enter Age: ");
    scanf("%d", &p.age);

    clearInputBuffer();

    printf("Enter Gender: ");
    fgets(p.gender, sizeof(p.gender), stdin);
    p.gender[strcspn(p.gender, "\n")] = '\0';

    printf("Enter Disease: ");
    fgets(p.disease, MAX_DISEASE, stdin);
    p.disease[strcspn(p.disease, "\n")] = '\0';

    printf("Enter Admission Date (DD/MM/YYYY): ");
    fgets(p.admissionDate, sizeof(p.admissionDate), stdin);
    p.admissionDate[strcspn(p.admissionDate, "\n")] = '\0';

    printf("Enter Bill Amount: ");
    scanf("%f", &p.bill);

    fwrite(&p, sizeof(Patient), 1, fp);
    fclose(fp);

    printf("\nPatient record added successfully!\n");
}


// DISPLAY PATIENTS

void displayPatients()
{
    FILE *fp;
    Patient p;

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        printf("No records found!\n");
        return;
    }

    printf("\n================ ALL PATIENTS ================\n");

    while (fread(&p, sizeof(Patient), 1, fp))
    {
        printf("\nID: %d\n", p.id);
        printf("Name: %s\n", p.name);
        printf("Age: %d\n", p.age);
        printf("Gender: %s\n", p.gender);
        printf("Disease: %s\n", p.disease);
        printf("Admission Date: %s\n", p.admissionDate);
        printf("Bill Amount: %.2f\n", p.bill);
        printf("---------------------------------------------\n");
    }

    fclose(fp);
}


// SEARCH PATIENT

void searchPatient()
{
    FILE *fp;
    Patient p;
    int id;
    int found = 0;

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return;
    }

    printf("\nEnter Patient ID to search: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(Patient), 1, fp))
    {
        if (p.id == id)
        {
            found = 1;

            printf("\nPatient Found!\n");
            printf("ID: %d\n", p.id);
            printf("Name: %s\n", p.name);
            printf("Age: %d\n", p.age);
            printf("Gender: %s\n", p.gender);
            printf("Disease: %s\n", p.disease);
            printf("Admission Date: %s\n", p.admissionDate);
            printf("Bill: %.2f\n", p.bill);

            break;
        }
    }

    if (!found)
    {
        printf("Patient not found!\n");
    }

    fclose(fp);
}


// UPDATE PATIENT

void updatePatient()
{
    FILE *fp;
    Patient p;
    int id;
    int found = 0;

    fp = fopen(FILE_NAME, "rb+");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return;
    }

    printf("\nEnter Patient ID to update: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(Patient), 1, fp))
    {
        if (p.id == id)
        {
            found = 1;

            printf("\nEnter New Disease: ");
            clearInputBuffer();
            fgets(p.disease, MAX_DISEASE, stdin);
            p.disease[strcspn(p.disease, "\n")] = '\0';

            printf("Enter New Bill Amount: ");
            scanf("%f", &p.bill);

            fseek(fp, -(long)sizeof(Patient), SEEK_CUR);
            fwrite(&p, sizeof(Patient), 1, fp);

            printf("\nRecord updated successfully!\n");
            break;
        }
    }

    if (!found)
    {
        printf("Patient ID not found!\n");
    }

    fclose(fp);
}


// DELETE PATIENT

void deletePatient()
{
    FILE *fp, *temp;
    Patient p;
    int id;
    int found = 0;

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return;
    }

    temp = fopen("temp.dat", "wb");

    printf("\nEnter Patient ID to delete: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(Patient), 1, fp))
    {
        if (p.id == id)
        {
            found = 1;
            continue;
        }

        fwrite(&p, sizeof(Patient), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found)
        printf("\nPatient deleted successfully!\n");
    else
        printf("Patient ID not found!\n");
}


// GENERATE BILL REPORT

void generateBillReport()
{
    FILE *fp;
    Patient p;
    float total = 0;
    int count = 0;

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        printf("No records found!\n");
        return;
    }

    printf("\n============= BILLING REPORT =============\n");

    while (fread(&p, sizeof(Patient), 1, fp))
    {
        printf("Patient: %-20s Bill: %.2f\n", p.name, p.bill);
        total += p.bill;
        count++;
    }

    printf("------------------------------------------\n");
    printf("Total Patients: %d\n", count);
    printf("Total Revenue : %.2f\n", total);

    fclose(fp);
}


// SORT PATIENTS BY NAME

void sortPatients()
{
    FILE *fp;
    Patient patients[MAX_PATIENTS];
    Patient temp;
    int count = 0;
    int i, j;

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        printf("No records found!\n");
        return;
    }

    while (fread(&patients[count], sizeof(Patient), 1, fp))
    {
        count++;
    }

    fclose(fp);

    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (strcmp(patients[i].name, patients[j].name) > 0)
            {
                temp = patients[i];
                patients[i] = patients[j];
                patients[j] = temp;
            }
        }
    }

    printf("\n=========== SORTED PATIENTS ===========\n");

    for (i = 0; i < count; i++)
    {
        printf("%d - %s\n", patients[i].id, patients[i].name);
    }
}


// BACKUP DATABASE

void backupDatabase()
{
    FILE *source, *backup;
    char ch;

    source = fopen(FILE_NAME, "rb");

    if (source == NULL)
    {
        printf("No database found to backup!\n");
        return;
    }

    backup = fopen("backup.dat", "wb");

    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, backup);
    }

    fclose(source);
    fclose(backup);

    printf("\nDatabase backup created successfully!\n");
}


void clearInputBuffer()
{
    while (getchar() != '\n');
}
