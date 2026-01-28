#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void patient();
void bookapp();
void newpat();
void savePatient();
void displayPatients();
void editPatient();
void deletePatient();
void saveMedicalHistory();
void makePayment();
void loadPatients();
void saveAllPatients();
int menu();
void doctor();
void loaddoctors();
void savedoctors();
void showdoctors();
void showappointments();
void setappointment();
void adddoctor();
void removedoctor();
void staff();
void nursing();
void loadNursingStaff();
void saveNursingStaff();
void showNursingStaff();
void addNursingStaff();
void removeNursingStaff();
void working();
void loadworkingStaff();
void saveworkingStaff();
void showworkingStaff();
void addworkingStaff();
void removeworkingStaff();
void inventory();
void loadInventory();
void saveInventory();
void displayInventory();
void addInventoryItem();
void updateInventoryItem();
void deleteInventoryItem();
void bed();
void loadBeds();
void saveBeds();
void displayBeds();
void addBed();
void deleteBed();




struct address{
    int hno;
    char street[40];
    char city[40];
    char state[20];
};

typedef struct patient
{
    char name[40];
    char fname[40];
    int id;
    int age;
    char bg[3];
    char gender[5];
    char ph[10];
    char disease[60];
    char docname[40];
    char history[200];
    char date[10];
    char treatment[40];
    char med[40];
}appo;

typedef struct {
    int id;
    char name[50];
    int age;
    int ph;
    char ailment[100];
    char medicalHistory[500];
    double payment;
} Patient;

Patient patients[100];
int patientCount = 0;

typedef struct {
    int id;
    char name[50];
    char position[50];
} NursingStaff;

NursingStaff staffs[100];
int staffCount = 0;

typedef struct {
    int id;
    char name[50];
    char position[50];
} workingStaff;

workingStaff stafff[100];
int staffCount1 = 0;

typedef struct {
    int itemId;
    char itemName[50];
    int quantity;
} InventoryItem;

InventoryItem inventory1[100];
int itemCount = 0;

typedef struct {
    int bedno;
    int patientId;
    int isOccupied;
} Bed;

Bed beds[25];
int bedCount = 0;

void patient(){
    int c1;
    do{
    printf("\t\t~~~PATIENT~~~\n");
    printf("1.Book appointment\n2.Patient records\n3.main menu\n");
    scanf("%d",&c1);
    
        switch(c1){
            case 1:{ bookapp();
                break;
            }
            case 2:{ newpat();
                break;
            }
            case 3:{ menu();
                break;
            }
            default :{
                printf("\tenter proper choice\n");
                patient();
            }

        }
    }
while(c1!=3);
}

void bookapp(){
FILE *f1;
struct patient appo;
printf("enter the following data\n\t");
printf("NAME : ");
scanf("%s",appo.name);
printf("GUARDIAN NAME : ");
scanf("%s",appo.fname);
printf("I.D. : ");
scanf("%d",&appo.id);
printf("PHONE NUMBER : ");
scanf("%s",appo.ph);
printf("gender : ");
scanf("%s",appo.gender);
printf("BLOOD GROUTP : ");
scanf("%s",appo.bg);
printf("DISEASE : ");
scanf("%s",appo.disease);
printf("DOCTOR : ");
scanf("%s",appo.docname);
printf("MEDICAL HISTORY : ");
scanf("%s",appo.history);
printf("DATE OF APPOINTMENT : ");
scanf("%s",appo.date);
printf("TREATMENT : ");
scanf("%s",appo.treatment);
printf("REGULAR MEDICAL HISTORY : ");
scanf("%s",appo.med);
f1 = fopen("appoint.dat", "ab");
    if (f1 == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fwrite(&appo, sizeof(appo), 1, f1);
    fclose(f1);
    printf("\tAppointment booked successfully!\n");
}

void newpat(){

int choice;

    loadPatients();

    while (1) {
        printf("\t\n~~~Patient records~~~\n");
        printf("1. Save Patient\n");
        printf("2. Display Patients\n");
        printf("3. Edit Patient\n");
        printf("4. Delete Patient\n");
        printf("5. Save/Edit Medical History\n");
        printf("6. Make Payment\n");
        printf("7. Patient menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:{
                savePatient();
                break;}
            case 2:{
                displayPatients();
                break;}
            case 3:{
                editPatient();
                break;}
            case 4:{
                deletePatient();
                break;}
            case 5:{
                saveMedicalHistory();
                break;}
            case 6:{
                makePayment();
                break;}
            case 7:{
                saveAllPatients();
                patient();}
            default:{
                printf("\tInvalid choice!\n");
                newpat();
            }
        }
    }

}

void savePatient() {
    Patient patient;
    printf("Enter patient ID: ");
    scanf("%d", &patient.id);
    printf("Enter patient name: ");
    scanf("%s", patient.name);
    printf("Enter patient age: ");
    scanf("%d", &patient.age);
    printf("Enter phone number: ");
    scanf("%d",&patient.ph);
    printf("Enter ailment: ");
    scanf("%s", patient.ailment);
    strcpy(patient.medicalHistory, "");
    patient.payment = 0.0;

    patients[patientCount++] = patient;
    saveAllPatients();

    printf("\tPatient data saved successfully!\n");
}

void displayPatients() {
    printf("\nPatients:\n");
    for (int i = 0; i < patientCount; i++) {
        printf(" ID: %d\n Name: %s\n Age: %d\n Phone: %d\n Ailment: %s\n Medical History: %s\n Payment: %.2f\n",
               patients[i].id, patients[i].name, patients[i].age, patients[i].ph, patients[i].ailment,
               patients[i].medicalHistory, patients[i].payment);
    }
}

void editPatient() {
    int id, found = 0;
    printf("Enter patient ID to edit: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            found = 1;
            printf("Enter new name: ");
            scanf("%s", patients[i].name);
            printf("Enter new age: ");
            scanf("%d", &patients[i].age);
            printf("Enter new ailment: ");
            scanf("%s", patients[i].ailment);

            saveAllPatients();
            printf("\tPatient data updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\tPatient ID not found!\n");
    }
}

void deletePatient() {
    int id, found = 0;
    printf("Enter patient ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            found = 1;
            for (int j = i; j < patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patientCount--;
            saveAllPatients();
            printf("\tPatient data deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Patient ID not found!\n");
    }
}

void saveMedicalHistory() {
    int id, found = 0;
    printf("Enter patient ID to update medical history: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            found = 1;
            printf("Enter new medical history: ");
            scanf(" %s", patients[i].medicalHistory);

            saveAllPatients();
            printf("Medical history updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Patient ID not found!\n");
    }
}

void makePayment() {
    int id, found = 0;
    double amount;
    printf("Enter patient ID to make payment: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            found = 1;
            printf("Enter payment amount: ");
            scanf("%lf", &amount);
            patients[i].payment += amount;

            saveAllPatients();
            printf("Payment updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Patient ID not found!\n");
    }
}

void loadPatients() {
    FILE *file1 = fopen("patients.dat", "rb");
    if (file1 == NULL) {
        return;
    }

    patientCount = fread(patients, sizeof(Patient), 100, file1);
    fclose(file1);
}

void saveAllPatients() {
    FILE *file1 = fopen("patients.dat", "wb");
    if (file1 == NULL) {
        printf("Error saving patient data!\n");
        return;
    }

    fwrite(patients, sizeof(Patient), patientCount, file1);
    fclose(file1);
}

typedef struct {
    int doctorId;
    char doctorName[50];
    char docspec[50];
    char appointments[100][20];
    int appointmentCount;
} Doctor;

Doctor doctors[25];
int doctorCount = 0;

void loaddoctors(){
    FILE*f3;
    f3=fopen("doctors.dat","rb");
    if(f3==NULL){
        printf("error showing doctors\n");
    return;
    }
    doctorCount = fread(doctors, sizeof(Doctor), 100, f3);
    fclose(f3);
}

void savedoctors(){
     FILE *f4 = fopen("doctors.dat", "wb");
    if (f4 == NULL) {
        printf("Error saving doctor data!\n");
        return;
    }

    fwrite(doctors, sizeof(Doctor), doctorCount, f4);
    fclose(f4);
}

void showdoctors(){
printf("\nDoctors:\n");
    for (int i = 0; i < doctorCount; i++) {
        printf("Doctor ID: %d , Name: %s , Medical Specializations : %s\n", doctors[i].doctorId, doctors[i].doctorName,doctors[i].docspec);
    }
}

void showappointments(){
int doctorId, found = 0;
    printf("Enter doctor ID : ");
    scanf("%d", &doctorId);

    for (int i = 0; i < doctorCount; i++) {
        if (doctors[i].doctorId == doctorId) {
            found = 1;
            printf("Appointments for Dr. %s:\n", doctors[i].doctorName);
            for (int j = 0; j < doctors[i].appointmentCount; j++) {
                printf("Appointment Date: %s\n", doctors[i].appointments[j]);
            }
            break;
        }
    }

    if (!found) {
        printf("Doctor ID not found!\n");
    }
}

void setappointment(){
int doctorId, found = 0;
    char appointmentDate[20];
    printf("Enter doctor ID to set appointment: ");
    scanf("%d", &doctorId);

    for (int i = 0; i < doctorCount; i++) {
        if (doctors[i].doctorId == doctorId) {
            found = 1;
            printf("Enter appointment date (DD/MM/YYYY): ");
            scanf("%s", appointmentDate);
            strcpy(doctors[i].appointments[doctors[i].appointmentCount++], appointmentDate);

            savedoctors();
            printf("Appointment set successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Doctor ID not found!\n");
    }
}

void adddoctor(){
 Doctor doctor;
    printf("Enter doctor ID: ");
    scanf("%d", &doctor.doctorId);
    printf("Enter doctor name: ");
    scanf("%s", doctor.doctorName);
    printf("enter Medical Specializations : ");
    scanf("%s",doctor.docspec);
    doctor.appointmentCount = 0;  

    doctors[doctorCount++] = doctor;
    savedoctors();

    printf("Doctor added successfully!\n");

}

void removedoctor(){
    int doctorId, found = 0;
    printf("Enter doctor ID to remove: ");
    scanf("%d", &doctorId);

    for (int i = 0; i < doctorCount; i++) {
        if (doctors[i].doctorId == doctorId) {
            found = 1;
            for (int j = i; j < doctorCount - 1; j++) {
                doctors[j] = doctors[j + 1];
            }
            doctorCount--;
            savedoctors();
            printf("Doctor removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Doctor ID not found!\n");
    }
}

void doctor(){
    int a;
    loaddoctors();
do{
    printf("\t\t~~DOCTORS~~\n");
    printf("select option\n1.show doctors\n2.set appointment\n3.show appointment\n4.add doctor\n5.remove doctor\n6.main menu\n");
    scanf("%d",&a);
    
        switch(a){
            case 1:{showdoctors();
                break;
            }
            case 2:{setappointment();
                break;
            }
            case 3:{showappointments();
                break;
            }
            case 4:{adddoctor();
                break;  
            }
            case 5:{removedoctor();
                break;
            }
            case 6:{savedoctors();
                menu();
                break;
            }
            default:{
printf("\tentered wrong choice, try again.....\n");
doctor();
            }
        }
    }
    while(a!=6);
return;
}

void staff(){
    int b;
    do{
    printf("\t\t~~STAFF~~\n");
    printf("enter the choise\n1.Nursing staff\n2.Working staff\n3.main menu\n");
    scanf("%d",&b);
    switch(b){
        case 1:{nursing();
            break;
        }
        case 2:{working();
            break;
        }
        case 3:{
            menu();
            break;
        }
        default : {
            printf("\tenter proper choise\n");
            staff();
        }
    }
}
while(b!=3);
return ;
}

void nursing(){
int choice;
loadNursingStaff();

    while (1) {
        printf("\t\t~~Nursing Staff~~\n");
        printf("1. Show Nursing Staff\n");
        printf("2. Add Nursing Staff\n");
        printf("3. Remove Nursing Staff\n");
        printf("4. staff menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:{
                showNursingStaff();
                break;}
            case 2:{
                addNursingStaff();
                break;}
            case 3:{
                removeNursingStaff();
                break;}
            case 4:{
                saveNursingStaff();
                staff();}
            default:{
                printf("\tInvalid choice! try again....\n");
                nursing();              
            }
        }
    }
}

void loadNursingStaff() {
    FILE *f5 = fopen("nursing_staff.dat", "rb");
    if (f5 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    staffCount = fread(staffs, sizeof(NursingStaff), 100, f5);
    fclose(f5);
}

void saveNursingStaff() {
    FILE *f5 = fopen("nursing_staff.dat", "wb");
    if (f5 == NULL) {
        printf("Error saving nursing staff data!\n");
        return;
    }

    fwrite(staffs, sizeof(NursingStaff), staffCount, f5);
    fclose(f5);
}

void showNursingStaff() {
    printf("\nNursing Staff:\n");
    for (int i = 0; i < staffCount; i++) {
        printf("ID: %d, Name: %s, Position: %s\n", staffs[i].id, staffs[i].name, staffs[i].position);
    }
}

void addNursingStaff() {
    NursingStaff newStaff;
    printf("Enter staff ID: ");
    scanf("%d", &newStaff.id);
    printf("Enter staff name: ");
    scanf("%s", newStaff.name);
    printf("Enter staff position: ");
    scanf("%s", newStaff.position);

    staffs[staffCount++] = newStaff;
    saveNursingStaff();

    printf("Nursing staff added successfully!\n");
}

void removeNursingStaff() {
    int id, found = 0;
    printf("Enter staff ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < staffCount; i++) {
        if (staffs[i].id == id) {
            found = 1;
            for (int j = i; j < staffCount - 1; j++) {
                staffs[j] = staffs[j + 1];
            }
            staffCount--;
            saveNursingStaff();
            printf("Nursing staff removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Staff ID not found!\n");
    }
}

void working(){
    int choice;

    loadworkingStaff();

    while (1) {
        printf("\t\t\nNursing Staff Management System\n");
        printf("1. Show working Staff\n");
        printf("2. Add working Staff\n");
        printf("3. Remove working Staff\n");
        printf("4. main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:{
                showworkingStaff();
                break;}
            case 2:{
                addworkingStaff();
                break;}
            case 3:{
                removeworkingStaff();
                break;}
            case 4:{
                saveworkingStaff();
                menu();}
            default:{
                printf("\tInvalid choice! try again....\n");
                working();
        }}
    }
}

void loadworkingStaff() {
    FILE *file = fopen("working_staff.dat", "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    staffCount1 = fread(stafff, sizeof(workingStaff), 100, file);
    fclose(file);
}


void saveworkingStaff() {
    FILE *file = fopen("working_staff.dat", "wb");
    if (file == NULL) {
        printf("Error saving working staff data!\n");
        return;
    }

    fwrite(stafff, sizeof(workingStaff), staffCount1, file);
    fclose(file);
}


void showworkingStaff() {
    printf("\nworking Staff:\n");
    for (int i = 0; i < staffCount1; i++) {
        printf("ID: %d, Name: %s, Position: %s\n", stafff[i].id, stafff[i].name, stafff[i].position);
    }
}


void addworkingStaff() {
    workingStaff newStaff;
    printf("Enter staff ID: ");
    scanf("%d", &newStaff.id);
    printf("Enter staff name: ");
    scanf("%s", newStaff.name);
    printf("Enter staff position: ");
    scanf("%s", newStaff.position);

    stafff[staffCount1++] = newStaff;
    saveworkingStaff();

    printf("working staff added successfully!\n");
}


void removeworkingStaff() {
    int id, found = 0;
    printf("Enter staff ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < staffCount1; i++) {
        if (stafff[i].id == id) {
            found = 1;
            for (int j = i; j < staffCount1 - 1; j++) {
                stafff[j] = stafff[j + 1];
            }
            staffCount1--;
            saveworkingStaff();
            printf("Working staff removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Staff ID not found!\n");
    }
}

void inventory(){
    int d;

    
    loadInventory();

    while (1) {
        printf("\t\t\n~~~Inventory~~~\n");
        printf("enter choice\n1.Displey inventory\n2.Add inventory\n3.Update inventory\n4.delete inventory\n5.Main menu\n");
        scanf("%d", &d);

        switch (d) {
            case 1:{
                displayInventory();
                break;}
            case 2:{
                addInventoryItem();
                break;}
            case 3:{
                updateInventoryItem();
                break;}
            case 4:{
                deleteInventoryItem();
                break;}
            case 5:{
                saveInventory();
                menu();}
            default:{
                printf("\tInvalid choice! try again....\n");
                inventory();}
        }
    }
}

void loadInventory() {
    FILE *file = fopen("inventory.dat", "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    itemCount = fread(inventory1, sizeof(InventoryItem), 100, file);
    fclose(file);
}

void saveInventory() {
    FILE *file = fopen("inventory.dat", "wb");
    if (file == NULL) {
        printf("Error saving inventory data!\n");
        return;
    }

    fwrite(inventory1, sizeof(InventoryItem), itemCount, file);
    fclose(file);
}

void displayInventory() {
    printf("\nInventory:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item ID: %d, Name: %s, Quantity: %d\n", inventory1[i].itemId, inventory1[i].itemName, inventory1[i].quantity);
    }
}

void addInventoryItem() {
    InventoryItem newItem;
    printf("Enter item ID: ");
    scanf("%d", &newItem.itemId);
    printf("Enter item name: ");
    scanf("%s", newItem.itemName);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);

    inventory1[itemCount++] = newItem;
    saveInventory();

    printf("Inventory item added successfully!\n");
}

void updateInventoryItem() {
    int itemId, found = 0;
    printf("Enter item ID to update: ");
    scanf("%d", &itemId);

    for (int i = 0; i < itemCount; i++) {
        if (inventory1[i].itemId == itemId) {
            found = 1;
            printf("Enter new quantity: ");
            scanf("%d", &inventory1[i].quantity);
            saveInventory();
            printf("Inventory item updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item ID not found!\n");
    }
}

void deleteInventoryItem() {
    int itemId, found = 0;
    printf("Enter item ID to delete: ");
    scanf("%d", &itemId);

    for (int i = 0; i < itemCount; i++) {
        if (inventory1[i].itemId == itemId) {
            found = 1;
            for (int j = i; j < itemCount - 1; j++) {
                inventory1[j] = inventory1[j + 1];
            }
            itemCount--;
            saveInventory();
            printf("Inventory item deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item ID not found!\n");
    }
}

void bed(){
int e;

    
    loadBeds();

    while (1) {
        printf("\t\t\n~~~Bed Management~~~\n");
        printf("enter choice\n1.Displlay beds\n2.Add bed\n3.Delete bed\n4.main menu\n");
       
        scanf("%d", &e);

        switch (e) {
            case 1:{
                displayBeds();
                break;}
            case 2:{
                addBed();
                break;}
            case 3:{deleteBed();
                break;}
            case 4:{saveBeds();
                menu();
                break;}
                
            default:{
                printf("\tInvalid choice! try again....\n");
                bed();
        }}
    }
}

void loadBeds() {
    FILE *file = fopen("beds.dat", "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    bedCount = fread(beds, sizeof(Bed), 100, file);
    fclose(file);
}

void saveBeds() {
    FILE *file = fopen("beds.dat", "wb");
    if (file == NULL) {
        printf("Error saving bed data!\n");
        return;
    }

    fwrite(beds, sizeof(Bed), bedCount, file);
    fclose(file);
}

void displayBeds() {
    printf("total beds = 25\n");
    printf("\nBeds:\n");
    for (int i = 0; i < bedCount; i++) {
        printf("{%d}. Bed no.: %d, Patient ID: %d, Is Occupied: %d\n",i, beds[i].bedno, beds[i].patientId, beds[i].isOccupied);
    }
}

void addBed() {
    Bed newBed;
    printf("Enter bed no.: ");
    scanf("%d", &newBed.bedno);
    printf("Enter patient ID : ");
    scanf("%d", &newBed.patientId);
    beds[bedCount++] = newBed;
    saveBeds();

    printf("Bed added successfully!\n");
}

void deleteBed() {
    int bedno, found = 0;
    printf("Enter bed no. to delete: ");
    scanf("%d", &bedno);

    for (int i = 0; i < bedCount; i++) {
        if (beds[i].bedno == bedno) {
            found = 1;
            for (int j = i; j < bedCount - 1; j++) {
                beds[j] = beds[j + 1];
            }
            bedCount--;
            saveBeds();
            printf("Bed deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Bed no. not found!\n");
    }
}

int menu(){
    int option;
do{
    printf("\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("\t\t\t\t**** WELCOME TO GSV HOSPITAL M.S.****\n");
    printf("\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("choose the following option\n1.patient\n2.doctor\n3.staff\n4.inventory\n5.Bed management\n");
    scanf("%d",&option);
    switch(option){
        case 1:{ patient();
            break;
        }
        case 2:{ doctor();
            break;
        }
        case 3:{ staff();
            break;
        }
        case 4:{ inventory();
            break;
        }
        case 5:{ bed();
            break;
        }
        default:{
            printf("\tyou entered wrong option , try again.....\n");
            menu();
        }
    }
}
while(1);
return 0;
}

int main(){
    menu();
    return 0;
}
