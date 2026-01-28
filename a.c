#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define MAX_USER 50
#define MAX_PATIENTS 50
#define MAX_ROOM 50
#define MAX_DOCTORS 50
#define MAX_STAFF 50

void Receptionist();
void signUp();
void login();
void patient_login();
void Patient();
void view_appointment_ID();
void Reception();
void Patient_Management();
void Room_Management();
void Doctor_Management();
void Appointment_Management();
void Medical_Staff_Management();
void Inventory_Management();
void Payment_Billing_Management();
void History_Management();
void Add_Patient();
void Remove_patient();
void Display_patient();
void Room_Allocation();
void Room_Disallocation();
void Display_Room();
void Add_Doctor();
void Remove_doctor();
void Display_doctor();
void Add_Medical_Staff();
void Display_medical_staff();
void Remove_medical_staff();
void Display_All_Doctor();
void Display_doctor_by_ID();
void Add_Appointment();
void View_Appointments();
void Remove_Appointment();
void Appointment_All();
void Appointment_Patient();
void Display_all_Bills();
void Display_Bill_by_ID();
void Process_Payment();
void Display_Bills();
void Generate_Bill();
void Display_Staff_All();
void Display_Staff_ID();
void view_Medical();
void saveData();
void loadData();


typedef struct{
    int id;
    char Gender[10];
    char name[25];
    int age;
    char DOB[15];
    char Illness[50];
    char address[100];
    char mobile[15];
    char blood_group[3];
    char Aadhaar_Card[15];
} patient;

typedef struct{
    char username[50];
    char password[50];
} User;

typedef struct{
    int roomNumber;
    int Room_occupied;
    int patientID;
    char Aadhaar_Card[15];
} Room;

typedef struct{
    int id;
    char name[25];
    char specialization[50];
    char contact[15];
    int age;
    char Aadhaar_Card[15];
} doctor;

typedef struct{
    int id;
    char name[25];
    char contact[15];
    char designation[50];
    int age;
    char Aadhaar_Card[15];
} staff;

typedef struct{
    int id;
    char name[50];
    int quantity;
    int price;
    char Manufacturing_Date[30];
    char Expiry_Date[30];
} inventory;

typedef struct{
    int PatientID;
    int amount;
    int Status;
    char name[25];
    char Aadhaar_Card[15];
} Bill;

typedef struct{
    int Appointment_ID;
    int Patient_ID;
    int Doctor_ID;
    char Date[15];
    char Time[10]; 
    int Status;
    char Aadhaar_Card[15];
} Appointments;

typedef struct{
    int Patient_id;
    char Gender[10];
    char name[25];
    int age;
    char DOB[15];
    char Illness[50];
    char address[100];
    char mobile[15];
    char blood_group[3];
    char status[15];
    char Aadhaar_Card[15];
} History;

User users[MAX_USER];
patient patients[MAX_PATIENTS];
doctor doctors[MAX_DOCTORS];
Room rooms[MAX_ROOM];
staff staffs[MAX_STAFF];
inventory inventorys[MAX_PATIENTS];
Bill bills[MAX_PATIENTS];
Appointments appointments[MAX_PATIENTS];
History histories[MAX_PATIENTS];

int usercount = 0;
int patientcount = 0;
int roomcount = 0;
int doctorcount = 0;    
int staffcount = 0;
int inventorycount = 0;
int billcount = 0;
int appointmentcount = 0;
int historycount = 0;

int main(){
    loadData();

    int choice;
    
    printf("\n\n\n\n");
    printf("______________________________________________________________________________________________________________________________________________________________\n\n\n");


    
    printf("                                                $$$     $$$    $$$$$$       $$$$$$    $$$$$$$$$$   \n");
    printf("                                                $$$     $$$    $$$ $$$     $$$ $$$    $$$          \n");
    printf("                                                $$$     $$$    $$$  $$$   $$$  $$$    $$$          \n");
    printf("                                                $$$$$$$$$$$    $$$   $$$ $$$   $$$    $$$$$$$$$$   \n");
    printf("                                                $$$     $$$    $$$    $$$$     $$$           $$$   \n");
    printf("                                                $$$     $$$    $$$             $$$           $$$   \n");
    printf("                                                $$$     $$$    $$$             $$$    $$$$$$$$$$   \n");

    do{
    printf("______________________________________________________________________________________________________________________________________________________________\n\n\n");
    printf("<------------------ welcome to hospital management system ------------------>\n");
    printf("To sign up and log in, please choose one of the following options:\n");
    printf("1. Receptionist\n");
    printf("2. Patient\t\t\t\t\t\t\tNOTE : If you are part of hospital as a patient then you can excess Patient Window\n");
    printf("3. Exit \n\n");

    printf("Please enter your choice: ");
    scanf("%d",&choice);
    
        switch(choice){

        case 1 : Receptionist();
        break;

        case 2 : patient_login();
        break;

        case 3 : printf("<---- THANK YOU FOR VISITING ---->\n");
        break;

        default : printf("You pressed an incorrect key .........\n");
        break;

        }
    }while( choice != 3);
    
    saveData();
    return 0; 
}

void signUp() {
    printf("____________________________________________________________________________________________________________________________________________________\n\n\n");
    if (usercount >= MAX_USER) {
        printf("User limit reached!\n");
        return;
    }

    User new_user;

    printf("Create username : ");
    scanf("%s", new_user.username);
    printf("Create password : ");
    scanf("%s", new_user.password);

    users[usercount] = new_user;
    usercount++;
    printf("Sign-up successful! Now you can login %s\n",new_user.username);
    
    login();
    return;
}

void login(){                                                                                                                                     
    printf("_______________________________________________________________________________________________________________________________________________________\n\n\n");
    User old_user;
    printf("Enter username : ");
    scanf("%s", old_user.username);

    printf("Enter password : ");
    scanf("%s", old_user.password);

    for(int i=0; i<usercount; i++){
        if(strcmp(users[i].username,old_user.username)== 0 && strcmp(users[i].password,old_user.password) == 0){
            printf("Login successfully ! Welcome %s\n", old_user.username);
            Reception();
            return;
        }
    }
    printf("Invalid username or password \n\n");
    return ;
}

void Receptionist(){
    int choice;
    do{
        printf("_______________________________________________________________________________________________________________________________________________________\n\n\n");
        printf("1. Sign Up\n");
        printf("2. Login\n");
        printf("3. Back\n\n");
        printf("Please enter your choice : ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: signUp();
            break;

            case 2: login();
            break;

            case 3: return;
            break;

            default : printf("Invalid choice ! Try again \n");
            break;
        }

    }while(choice !=3);
}

void Reception(){
    int option_Reception;

    do{
            printf("________________________________________________________________________________________________________________________________________________\n\n\n");
            printf("\n\n<--------  Welcome in Reception window  -------->\n\n");
            printf("1. Patient Management\n");
            printf("2. Room Management\n");
            printf("3. Doctor Management\n");
            printf("4. Appointment Management\n");
            printf("5. Medical Staff Management\n");
            printf("6. Inventory Management\n");
            printf("7. payment and Billing Management\n");
            printf("8. History Management\n");
            printf("9. Back\n\n\n");
                
            printf("\t\t\t\tChoose one option : ");
            scanf("%d",&option_Reception);

            switch(option_Reception){
                case 1: Patient_Management(); 
                break;
                
                case 2: Room_Management();
                break;

                case 3: Doctor_Management();
                break;

                case 4: Appointment_Management();
                break;

                case 5: Medical_Staff_Management();
                break;

                case 6: Inventory_Management();
                break;

                case 7: Payment_Billing_Management();
                break;
                
                case 8: History_Management();
                break;

                case 9: return;
                break;

                default : printf("Invalid option. Please try again .....\n\n");
                break;
            }
        }while(option_Reception != 9);
    return;
}

void Patient_Management(){
    int option_Patient;
    printf("________________________________________________________________________________________________________________________________________________\n\n\n");
    printf("<--------  Welcome in Patient Management window  -------->\n\n");
    do{
        printf("1. Add Patient\n");
        printf("2. View Patient\n");
        printf("3. Update Patient\n");
        printf("4. Back\n");
        printf("\n\n");
        printf("\t\tChoose One Option : ");
        scanf("%d",&option_Patient);
        switch(option_Patient){
            case 1: Add_Patient();
            break;

            case 2: Display_patient();
            break;

            case 3: Remove_patient();
            break;

            case 4: return;
            break;

            default : printf("Invalid option. Please try again .....\n\n");
            break;

        }
    }while(option_Patient != 4);
}

void Room_Management(){
    int option_Room;
    printf("\n\n________________________________________________________________________________________________________________________________________________\n\n\n");
    printf("<------------- Welcome in Room Management window ------------->\n\n");
    do{
        printf("\n1. Room Allocation\n");
        printf("2. Room Disallocation\n");
        printf("3. View Room\n");
        printf("4. Back\n\n");
        printf("\n\n");
        printf("\t\tChoose One Option : ");
        scanf("%d",&option_Room);

        switch(option_Room){
            case 1: Room_Allocation();
            break;

            case 2: Room_Disallocation();
            break;

            case 3: Display_Room();
            break;

            case 4: return;
            break;

            default : printf("Invalid option. Please try again .....\n\n");
            break;
        }
    }while(option_Room != 4);
}

void Doctor_Management(){
    int option_Doctor;
    printf("________________________________________________________________________________________________________________________________________________\n\n\n");
    printf("<---------------- Welcome in Doctor Management window ----------------->\n\n");
    do{
        printf("1. Doctor Registration\n");
        printf("2. Doctor Upadatation\n");
        printf("3. View Doctors\n");
        printf("4. Back\n");
        printf("\n\n");
        printf("\t\tChoose One Option : ");
        scanf("%d",&option_Doctor);

        switch(option_Doctor){
            case 1: Add_Doctor();
            break;

            case 2: Remove_doctor();
            break;

            case 3: Display_doctor();
            break;

            case 4: return;
            break;

            default : printf("Invalid option. Please try again .....\n\n");
            break;

        }
    }while(option_Doctor != 4);
}

void Appointment_Management(){
    int option_Appointment;
    printf("________________________________________________________________________________________________________________________________________________\n\n\n");
    printf("<----------------- Welcome in Appointment Management window ----------------->\n\n");
    do{
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Cancel Appointment\n");
        printf("4. Back\n\n");
        printf("\t\tChoose One Option : ");
        scanf("%d",&option_Appointment);

        switch(option_Appointment){
            case 1: Add_Appointment();
            break;

            case 2: View_Appointments();
            break;

            case 3: Remove_Appointment();
            break;

            case 4: return;
            break;

            default : printf("Invalid option. Please try again .....\n\n");
            break;
        }
    }while(option_Appointment != 4);
}

void Medical_Staff_Management(){
    int option_Staff;
    printf("________________________________________________________________________________________________________________________________________________\n\n\n");
    printf("<----------------- Welcome in Medical Staff Management window ----------------->\n\n");
    do{
        printf("1. Add Medical Staff\n");
        printf("2. View Medical Staff\n");
        printf("3. Update Medical Staff\n");
        printf("4. Back\n\n");
        printf("\t\tChoose One Option : ");
        scanf("%d",&option_Staff);

        switch(option_Staff){
            case 1: Add_Medical_Staff();
            break;

            case 2: Display_medical_staff();
            break;

            case 3: Remove_medical_staff();
            break;

            case 4: return;
            break;

            default : printf("Invalid option. Please try again .....\n\n");
            break;

        }
    }while(option_Staff != 4);
}

void Add_Patient(){
    printf("\n\n\n________________________________________________________________________________________________________________________________________________\n\n\n");
    if(patientcount >= MAX_PATIENTS){
        printf("patients level reached !.....\n\n");
        return ;
    }

    patient new_patient;
    new_patient.id = patientcount + 1 ;
    
    for(int i=0; i<patientcount; i++){
        if(patients[i].id == new_patient.id){
            new_patient.id++;
            i=-1;
        }
    }

    printf("patient id number : %d\n",new_patient.id);
    printf("patient name : ");
    scanf("%s",new_patient.name);
    printf("patient age : ");
    scanf("%d",&new_patient.age);
    printf("patient D.O.B.(DD/MM/YYYY) : ");
    scanf("%s",new_patient.DOB);
    printf("patient Aadhaar Card : ");
    scanf("%s",new_patient.Aadhaar_Card);
    printf("patient Blood group : ");
    scanf("%s",new_patient.blood_group);
    printf("patient Illness : ");
    scanf("%s",new_patient.Illness);
    printf("patient mobile Number : ");
    scanf("%s",new_patient.mobile);
    printf("patient Gender : ");
    scanf("%s",new_patient.Gender);
    printf("patient Address : ");
    scanf("%s",new_patient.address);

    patients[patientcount] = new_patient;
    patientcount++;

    printf("\n\nPatient added successfully.....\t patient's id number is ( %d )\n\n",new_patient.id);
    return ;
}

void save_history(int patient_id){
    History new_history;
    patient patient_data = patients[patient_id- 1];

    new_history.Patient_id = patient_data.id;
    strcpy(new_history.Gender, patient_data.Gender);
    strcpy(new_history.name, patient_data.name);
    new_history.age = patient_data.age;
    strcpy(new_history.DOB, patient_data.DOB);
    strcpy(new_history.Illness, patient_data.Illness);
    strcpy(new_history.address, patient_data.address);
    strcpy(new_history.mobile, patient_data.mobile);
    strcpy(new_history.blood_group, patient_data.blood_group);
    strcpy(new_history.status, "Discharged");
    
    histories[historycount] = new_history;
    historycount++;
}

void Remove_patient(){
    int option_Remove_patients;
    do{
        printf("\n\n\n________________________________________________________________________________________________________________________________________________\n\n\n");
        printf("1. Remove all patients\n");
        printf("2. Remove a patient by id\n");
        printf("3. Back\n");
        printf("4. Exit\n");
        printf("\t\t\t\tEnter your choice : ");
        scanf("%d",&option_Remove_patients);

        switch(option_Remove_patients){
            case 1: 
                patientcount = 0;
                printf("All patients have been removed Successfully .......\n");
                break;

            case 2:
                printf("Enter the ID of the patient you want to remove : ");
                int id;
                scanf("%d",&id);
                
                if(id < 1 || id > patientcount){
                    printf("Patient not found\n");
                }
                else{
                    for(int i = 0; i < appointmentcount; i++){
                        if(appointments[i].Patient_ID == id){
                            appointments[i].Status = 1;
                        }
                    }

                    for(int i = id - 1 ; i < patientcount - 1 ; i++){
                        patients[i] = patients[i+1];
                    }
                    patientcount--;

                    save_history(id);

                    printf("Patient removed successfully .......\n");
                }
                break;
            
            case 3:
                return;
                break;

            case 4:
                printf("Exiting .......\n");
                break;
            default : printf("You are presses wrong key....\n");
                break;
        }
    }while(option_Remove_patients != 4);
    return;
}

void Display_patient(){
    int option_Display_patient;
    do{
        printf("1. Display all patients\n");
        printf("2. Display patient by id\n");
        printf("3. Back\n");
        printf("4. Exit\n");
        printf("\t\t\t\t\tEnter your choice : ");
        scanf("%d",&option_Display_patient);

        switch(option_Display_patient){

            case 1 : if(patientcount == 0){
                printf("No patients found.....\n");
                return;
            }
            for(int i=0; i<patientcount; i++){
                printf("patient id number : %d\n",patients[i].id);
                printf("patient name : %s\n",patients[i].name);
                printf("patient age : %d\n",patients[i].age);
                printf("patient D.O.B.(DD/MM/YYYY) : %s\n",patients[i].DOB);
                printf("patient Blood group : %s\n",patients[i].blood_group);
                printf("patient Illness : %s\n",patients[i].Illness);
                printf("patient Address : %s\n",patients[i].address);
                printf("patient Gender : %s\n",patients[i].Gender);
                printf("patient mobile : %s\n\n\n",patients[i].mobile);
            }
            break;
            case 2 :printf("Enter patient id number : ");
                    int id;
                    scanf("%d",&id);

                    if(id < 1 || id > patientcount){
                        printf("Patient not found ....\n");
                        return;
                    }
                        printf("patient name : %s\n",patients[id - 1].name);
                        printf("patient age : %d\n",patients[id - 1].age);
                        printf("patient D.O.B.(DD/MM/YYYY) : %s\n",patients[id - 1].DOB);
                        printf("patient Blood group : %s\n",patients[id - 1].blood_group);
                        printf("patient Illness: %s\n",patients[id - 1].Illness);
                        printf("patient Gender : %s\n",patients[id - 1].Gender);
                        printf("patient mobile : %s\n",patients[id - 1].mobile);
                        printf("patient Address : %s\n\n\n",patients[id - 1].address);
            break;
            case 3 : return ;

            case 4 : printf("Exiting .....\n");
            break;
            
            default : printf("Invalid choice! Try again....\n\n");
        }
    }while(option_Display_patient != 4);
}

void Room_Allocation(){
    int option_room_allocation;
    for(int i=0; i<MAX_ROOM; i++){
        rooms[i].roomNumber = i+1;
        rooms[i].Room_occupied = 0;
        rooms[i].patientID = -1;
    }
    roomcount = MAX_ROOM;

    if(patientcount == 0 ){
        printf("No patient found For room allocation .....\n");
        return ;
    }
    
    printf("Enter patient ID to allocate room : ");
    scanf("%d",&option_room_allocation);

    if(option_room_allocation < 1 || option_room_allocation > patientcount){
        printf("Invalid patient ID\n");
        return ;
    }

    for(int i=0; i<roomcount; i++){
        if(rooms[i].Room_occupied == 0){
            rooms[i].Room_occupied = 1;
            rooms[i].patientID = option_room_allocation;
            printf("Room %d allocated to patient %d\n",rooms[i].roomNumber,option_room_allocation);
            return;
        }
    }
    printf("NO available rooms for allocation .....\n\n");
}

void Display_Room(){
    printf("____________________________________________________________\n");
    printf("| Sr No.\t| Room No.\t| Patient ID \t| Status   |\n");
    printf("------------------------------------------------------------\n");
    for(int i=0; i<roomcount; i++){
        printf("| %d\t\t| %d\t\t| %d\t\t| %s |\n",i+1,rooms[i].roomNumber,rooms[i].patientID,rooms[i].Room_occupied ? "Occupied" : "Available");
        printf("-------------------------------------------------------------\n");
    }
}

void Room_Disallocation(){
    int option_room_disallocation;
    printf("Enter room number to disallocate room : ");
    scanf("%d",&option_room_disallocation);

    if(option_room_disallocation < 1 || option_room_disallocation > roomcount){
        printf("Invalid room number\n");
        return ;
    }

    if(rooms[option_room_disallocation - 1].Room_occupied == 0 ){
        printf("Room %d is already available\n\n",option_room_disallocation);
        return ;
    }

    rooms[option_room_disallocation - 1].Room_occupied = 0;
    rooms[option_room_disallocation - 1].patientID = -1;

    printf("Room No. %d disallocated successfully.\n\n",option_room_disallocation);

}

void Add_Doctor(){
    if(doctorcount >= MAX_DOCTORS){
        printf("Doctors limit reached!\n");
        return;
    }

    doctor new_doctor;
    new_doctor.id = doctorcount + 1;
    
    printf("Doctor's ID : %d\n",new_doctor.id);

    printf("Enter Doctor's Name : ");
    scanf("%s",new_doctor.name);

    printf("Enter Doctor's Age : ");
    scanf("%d",&new_doctor.age);

    printf("Enter Doctor's Contact NUmber : ");
    scanf("%s",new_doctor.contact);

    printf("Doctor's Specialization\n\n");
    printf("1. Cardiologist\n");
    printf("2. Neurologist\n");
    printf("3. Orthopedic Surgeon\n");
    printf("4. Pediatrician\n");
    printf("5. Dermatologist\n");
    printf("6. Gastroenterologist\n");
    printf("7. Pulmonologist\n");
    printf("8. Psychiatrist\n");
    printf("9. Ophthalmologist\n");
    printf("10. Endocrinologist\n");
    printf("11. Oncologist\n");
    printf("12. Nephrologist\n");
    printf("13. Hematologist\n");
    printf("14. Rheumatologist\n");
    printf("15. Obstetrician/Gynecologist\n");
    printf("16. Urologist\n");
    printf("17. Radiologist\n");
    printf("18. Anesthesiologist\n");
    printf("19. Otolaryngologist\n");
    printf("20. General Surgeon\n");
    printf("21. General Practitioner\n\n");

    int specialization_choice;
    do{
        printf("Select One of the above options : ");
        scanf("%d", &specialization_choice);
    
        switch (specialization_choice){
            case 1: strcpy(new_doctor.specialization, "Cardiologist"); 
            break;

            case 2: strcpy(new_doctor.specialization, "Neurologist"); 
            break;

            case 3: strcpy(new_doctor.specialization, "Orthopedic Surgeon");
            break;

            case 4: strcpy(new_doctor.specialization, "Pediatrician"); 
            break;

            case 5: strcpy(new_doctor.specialization, "Dermatologist"); 
            break;

            case 6: strcpy(new_doctor.specialization, "Gastroenterologist"); 
            break;

            case 7: strcpy(new_doctor.specialization, "Pulmonologist"); 
            break;

            case 8: strcpy(new_doctor.specialization, "Psychiatrist"); 
            break;

            case 9: strcpy(new_doctor.specialization, "Ophthalmologist"); 
            break;

            case 10: strcpy(new_doctor.specialization, "Endocrinologist"); 
            break;

            case 11: strcpy(new_doctor.specialization, "Oncologist"); 
            break;

            case 12: strcpy(new_doctor.specialization, "Nephrologist"); 
            break;

            case 13: strcpy(new_doctor.specialization, "Hematologist"); 
            break;

            case 14: strcpy(new_doctor.specialization, "Rheumatologist"); 
            break;

            case 15: strcpy(new_doctor.specialization, "Obstetrician/Gynecologist"); 
            break;

            case 16: strcpy(new_doctor.specialization, "Urologist"); 
            break;

            case 17: strcpy(new_doctor.specialization, "Radiologist"); 
            break;

            case 18: strcpy(new_doctor.specialization, "Anesthesiologist"); 
            break;

            case 19: strcpy(new_doctor.specialization, "Otolaryngologist"); 
            break;

            case 20: strcpy(new_doctor.specialization, "General Surgeon"); 
            break;

            case 21: strcpy(new_doctor.specialization, "General Practitioner"); 
            break;

            default: printf("Invalid choice! please try again.\n\n");
            break;

        }

    }while(specialization_choice >= 21);
    
    doctors[doctorcount] = new_doctor;
    doctorcount++;

    printf("\n\nDoctor added successfully!\nDoctor ID Number : %d\n\n", new_doctor.id);
    return;
}

void Display_doctor(){
    int option_docter;
    do{
        printf("1. Display Doctors List\n");
        printf("2. Display doctor by ID\n");
        printf("3. Back\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");

        scanf("%d",&option_docter);

        switch(option_docter){
            case 1: Display_All_Doctor();
            break;

            case 2: Display_doctor_by_ID();

                for (int i = 0; i < appointmentcount; i++) {
                    if (appointments[i].Doctor_ID == doctors[i].id && appointments[i].Status == 0) {
                        printf("\nAppointment ID: %d\nPatient ID: %d\nDate: %s\nTime: %s\n", 
                        appointments[i].Appointment_ID, 
                        appointments[i].Patient_ID, 
                        appointments[i].Date, 
                        appointments[i].Time);
                    }
                }
            break;

            case 3: return;
          
            case 4: printf("Exiting ......\n");
            break;
        }
    }while(option_docter != 4);

    return;
}

void Display_All_Doctor(){
    if(doctorcount == 0){
        printf("No doctors found\n");
        return;
    }
    
    printf("___________________________________________________________________________________________________\n");
    printf("| Sr NO.\t| Doctor ID\t| Name\t\t| Age\t| Specialization\t\t\t\t\t| Contact |\n");
    for(int i = 0; i < doctorcount; i++){
        printf("| %d\t\t| %d\t\t| %s\t\t| %d\t| %s\t\t\t\t\t|   %s\t|\n",i+1,doctors[i].id,doctors[i].name,doctors[i].age,doctors[i].specialization,doctors[i].contact);
    }
    return;
}

void Display_doctor_by_ID(){
    int id;
    printf("Enter Doctor ID : ");
    scanf("%d",&id);

    if(id < 1 || id > doctorcount){
        printf("Invalid Doctor ID\n");
        return;
    }

    printf("Doctor ID : %d\n",doctors[id-1].id);
    printf("Doctor Name : %s\n",doctors[id-1].name);
    printf("Doctor Age : %d\n",doctors[id-1].age);
    printf("Doctor Contact No. : %s\n",doctors[id-1].contact);
    printf("Specialization : %s\n",doctors[id-1].specialization);

    return;
}

void Remove_doctor(){
    int remove_doctor;
    do{
        printf("choose one option\n");
        printf("1. Remove Doctor by ID\n");
        printf("2. Back\n");
        printf("3  Exit\n");
        
        printf("Choose one option : ");
        scanf("%d",&remove_doctor);

        switch(remove_doctor){

        case 1: 
                printf("Enter Doctor ID for removal : ");
                int id;
                scanf("%d",&id);

                if(id < 1 || id > doctorcount){
                    printf("Invalid Doctor ID\n");
                    return;
                }
        
                for(int i = id-1; i < doctorcount-1; i++){
                doctors[i] = doctors[i+1];
                }

                doctorcount--;

                printf("Doctor with ID %d removed successfully\n",id);
        break;

        case 2:
                return;

        case 3:
                printf("Exiting .....\n");
        break;

        default : printf("You have entered wrong option\n");
        }
    }while(remove_doctor != 3);
    return;
}

void Add_Appointment(){
    Appointments new_App;
    new_App.Appointment_ID = appointmentcount + 1;
    
    printf("Enter Patient ID : ");
    scanf("%d",&new_App.Patient_ID);
    
    if( new_App.Patient_ID < 1 || new_App.Patient_ID> patientcount ){
        printf("Invalid Patient ID\n");
        return;
    }

    printf("Enter Doctor ID : ");
    scanf("%d",&new_App.Doctor_ID);

    if(new_App.Doctor_ID < 1 || new_App.Doctor_ID > doctorcount ){
        printf("Invalid Doctor ID\n");
        return;
    }

    for (int i = 0; i < appointmentcount; i++) {
        if (appointments[i].Patient_ID == patients[i].id && appointments[i].Doctor_ID == new_App.Doctor_ID && appointments[i].Status == 0){
            printf("Patient ID no %d already have an appointment with this doctor.\n",patients[i].id);
            return;
        }
    }

    printf("Enter Date of Appointment : ");
    scanf("%s",&new_App.Date);

    printf("Enter Time of Appointment : ");
    scanf("%s",&new_App.Time);
                
    new_App.Status = 0;

    appointments[appointmentcount] = new_App;
    appointmentcount++;
    printf("\n\nAppointment Added Successfully. %s's Appointment ID is %d\n\n\n",patients[new_App.Patient_ID - 1].name, new_App.Appointment_ID);

    return;
}


void View_Appointments(){
    if(appointmentcount == 0){
        printf("\n\nNo Appointments Available\n\n");
        return;
    }
    int choice;
    do{
        printf("<------- View Appointments Window ------->\n");
        printf("1. View All Appointments\n");
        printf("2. View Appointments by Patient ID\n");
        printf("3. Back\n");
        printf("\nEnter Your Choice : ");
        scanf("%d",&choice);

        switch( choice ){
            case 1: Appointment_All();
                break;
            
            case 2: Appointment_Patient();
                break;
            
            case 3: return;

            default : printf("\n\nInvalid Choice\n\n");
                break;
        }
    }while( choice != 3);
}

void Remove_Appointment() {
    int appointmentID;
    printf("Enter Appointment ID to remove: ");
    scanf("%d", &appointmentID);

    if (appointmentID < 1 || appointmentID > appointmentcount) {
        printf("Invalid Appointment ID\n");
        return;
    }

    for (int i = appointmentID - 1; i < appointmentcount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointmentcount--;
    printf("Appointment removed successfully.\n");
}

void Appointment_All(){
    for(int i=0 ; i<appointmentcount ; i++){
        printf("\n\nAppointment ID : %d\n", appointments[i].Appointment_ID);
        printf("Patient ID : %d\n", appointments[i].Patient_ID);
        printf("Doctor ID : %d\n", appointments[i].Doctor_ID);
        printf("Appointment Date : %s\n", appointments[i].Date);
        printf("Appointment Time : %s\n", appointments[i].Time);
        printf("Appointment Status : %s\n\n\n", appointments[i].Status ? "Scheduled" : "Not Scheduled");
    }
    return;
}

void Appointment_Patient(){
    int patientid;
    printf("\nEnter Patient ID : ");
    scanf("%d",&patientid);

    if( patientid  < 0 || patientid > appointmentcount ){
        printf("\n\nInvalid Patient ID\n\n");
        return;
    }

    printf("\n\nPatient ID : %d\n", appointments[patientid - 1].Patient_ID);
    printf("Patient Name : %s\n", patients[patientid - 1].name);
    printf("Doctor ID : %d\n", appointments[patientid - 1].Doctor_ID);
    printf("Appointment Date : %s\n",appointments[patientid - 1].Date);
    printf("Appointment Time : %s\n", appointments[patientid - 1].Time);
    printf("Appointment Status : %s\n\n\n", appointments[patientid - 1].Status ? "Scheduled" : "Not Scheduled");
    return;
}

void Add_Medical_Staff(){
    int add_staff;
    do{
        printf("1. Add Medical Staff\n");
        printf("2. Back\n");
        printf("3. Exit\n");

        printf("Choose one option : ");
        scanf("%d",&add_staff);

        switch(add_staff){
            case 1: if(staffcount >= MAX_STAFF){
                printf("staffs limit reached\n");
                return;
            }
            
            staff newStaff;
            newStaff.id = staffcount + 1;

            printf("Enter Name : ");
            scanf("%s",newStaff.name);

            printf("Enter Age : ");
            scanf("%d",&newStaff.age);

            printf("Enter Contact No. : ");
            scanf("%s",newStaff.contact);

            printf("Select Staff Department\n\n");

            printf("1.  Nurse\n");
            printf("2.  Medical Assistant\n");
            printf("3.  Lab Technician\n");
            printf("4.  Radiology Technician\n");
            printf("5.  Surgical Technologist\n");
            printf("6.  Physiotherapist\n");
            printf("7.  Dietitian/Nutritionist\n");
            printf("8.  Emergency Medical Technician (EMT)\n");
            printf("9.  Paramedic\n");
            printf("10. Clinical Research Coordinator\n");
            printf("11. Occupational Therapist\n");
            printf("12. Speech Therapist\n");
            printf("13. Respiratory Therapist\n");
            printf("14. Medical Records Clerk\n");
            printf("15. Phlebotomist\n");
            printf("16. Medical Coder\n");
            printf("17. Health Administrator\n");
            printf("18. Patient Care Technician\n");
            printf("19. Social Worker (Medical)\n");
            printf("20. Ward Attendant\n\n");

            printf("           Choose a option : ");
            int option_staff;
            scanf("%d",&option_staff);

            switch(option_staff) {
                case 1: 
                    strcpy(newStaff.designation, "Nurse");
                    break;
                case 2: 
                    strcpy(newStaff.designation, "Medical Assistant");
                    break;
                case 3: 
                    strcpy(newStaff.designation, "Lab Technician");
                    break;
                case 4: 
                    strcpy(newStaff.designation, "Radiology Technician");
                    break;
                case 5: 
                    strcpy(newStaff.designation, "Surgical Technologist");
                    break;
                case 6: 
                    strcpy(newStaff.designation, "Physiotherapist");
                    break;
                case 7: 
                    strcpy(newStaff.designation, "Dietitian/Nutritionist");
                    break;
                case 8: 
                    strcpy(newStaff.designation, "Emergency Medical Technician (EMT)");
                    break;
                case 9: 
                    strcpy(newStaff.designation, "Paramedic");
                    break;
                case 10: 
                    strcpy(newStaff.designation, "Clinical Research Coordinator");
                    break;
                case 11: 
                    strcpy(newStaff.designation, "Occupational Therapist");
                    break;
                case 12: 
                    strcpy(newStaff.designation, "Speech Therapist");
                    break;
                case 13: 
                    strcpy(newStaff.designation, "Respiratory Therapist");
                    break;
                case 14: 
                    strcpy(newStaff.designation, "Medical Records Clerk");
                    break;
                case 15: 
                    strcpy(newStaff.designation, "Phlebotomist");
                    break;
                case 16: 
                    strcpy(newStaff.designation, "Medical Coder");
                    break;
                case 17: 
                    strcpy(newStaff.designation, "Health Administrator");
                    break;
                case 18: 
                    strcpy(newStaff.designation, "Patient Care Technician");
                    break;
                case 19: 
                    strcpy(newStaff.designation, "Social Worker (Medical)");
                    break;
                case 20: 
                    strcpy(newStaff.designation, "Ward Attendant");
                    break;
                default:
                    printf("Invalid choice! Defaulting to 'Unknown Staff'.\n");
                    strcpy(newStaff.designation, "Nurse");
            }
                staffs[staffcount] = newStaff;
                staffcount++;

                printf("Medical staff added successfully!\nStaff ID Number : %d\n", newStaff.id);

            break;

            case 2: return;
            break;

            case 3: printf("Exiting.......\n");
            break;

            default : printf("you pressed wrong key ....\n");
        }
    }while(add_staff != 3);
}

void Display_medical_staff(){
    
    int option_Display_staff;
    do{
    printf("<------ Welcome ------>\n");
    printf("1. Display Medical Staff by ID\n");
    printf("2. Display All Medical Staff\n");
    printf("3. Back\n");
    printf("4. Exit\n");

    printf("Choose a Option : ");
    scanf("%d",&option_Display_staff);

    switch(option_Display_staff){
        
        case 1: Display_Staff_ID();
        break;

        case 2: Display_Staff_All();
        break;

        case 3: return;
        break;

        case 4: printf("Exiting .......\n");
        break;

        default : printf("you pressed wrong key ....\n");
        break;
        }
    }while(option_Display_staff != 4);
    return;
}

void Display_Staff_ID(){
    int staff_id;
    printf("Enter Staff ID : ");
    scanf("%d",&staff_id);

    if(staff_id < 1 || staff_id > staffcount){
        printf("Invalid Staff ID\n");
        return;
    }

    printf("Staff ID : %d\n",staffs[staff_id - 1].id);
    printf("Staff Name : %s\n",staffs[staff_id - 1].name);
    printf("Staff Age : %d\n",staffs[staff_id - 1].age);
    printf("Staff Contact No. : %s\n",staffs[staff_id - 1].contact);
    printf("Designation : %s\n",staffs[staff_id - 1].designation);
    
    return;
}

void Display_Staff_All(){
    if(staffcount == 0){
        printf("No Staff Available\n");
        return;
    }
    
    printf("\n\n_________________________________________________________________________________________________________________________________________________\n\n\n");

    for(int i = 0; i < staffcount; i++){
        printf(" Staff ID No. : %d\n Staff Name : %s\n Staff Age : %d\n Department of Staff : %s\n Staff Contact No. : %s\n\n\n",staffs[i].id, staffs[i].name, staffs[i].age , staffs[i].designation , staffs[i].contact);
    }

    return;
}

void Remove_medical_staff(){
    int staff_id;
    printf("Enter Staff ID : ");
    scanf("%d",&staff_id);

    if( staff_id < 1 || staff_id > staffcount){
        printf("Invalid Staff ID\n");
        return;
    }

    for(int i = staff_id - 1; i < staffcount - 1; i++){
        staffs[i] = staffs[i + 1];
    }
    staffcount--;
    printf("Staff Removed Successfully\n");
    return;
}

void Inventory_Management(){
    int option_Inventory;
    printf("________________________________________________________________________________________________________________________________________\n\n\n");
    printf("<--------------- Welcome to Inventory Management ----------------->\n");
    do{
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Remove Item\n");
        printf("4. Back\n");
        printf("5. Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d",&option_Inventory);

        switch(option_Inventory){
            case 1:{
                if( inventorycount >= MAX_PATIENTS ){
                    printf("Inventory is full\n");
                    break;
                }
                inventory newitem;
                newitem.id = inventorycount + 1;

                printf("Enter item name : ");
                scanf("%s",newitem.name);

                printf("Enter item quantity : ");
                scanf("%d",&newitem.quantity);

                printf("Enter item price : ");
                scanf("%d",&newitem.price);

                printf("Enter item Manufacturing Date (MM/YY): ");
                scanf("%s",newitem.Manufacturing_Date);

                printf("Enter item Expiry Date (MM/YY): ");
                scanf("%s",newitem.Expiry_Date);   

                inventorys[inventorycount] = newitem;
                inventorycount++;

                printf("Item added successfully!\nItem ID : %d\n",newitem.id);
                break;      
            }

            case 2:{
                if(inventorycount == 0){
                     printf("No item in inventory\n");
                     return;
                }
                printf("<------------------- Inventory List -------------------->\n\n");

                for(int i = 0; i < inventorycount; i++){
                    printf(" Item ID No. : %d\n Item Name : %s\n Item Quantity : %d\n Item Price : %d\n Item Manufacturing Date : %s\n Item Expiry Date : %s\n\n\n",inventorys[i].id,inventorys[i].name,inventorys[i].quantity,inventorys[i].price,inventorys[i].Manufacturing_Date,inventorys[i].Expiry_Date);
                }
                break;
            }
            
            case 3:{
                int id;
                printf("Enter item ID to remove : ");
                scanf("%d",&id);

                if( id < 1 || id > inventorycount ){
                    printf("Invalid Item ID\n");
                    return;
                }

                for(int i = id - 1; i < inventorycount - 1; i++){
                    inventorys[i] = inventorys[i + 1];
                }
                inventorycount--;
                printf("Item removed successfully!\n");

                break;
            }

            case 4: return;

            case 5:   
                printf("Exiting ..........\n");
                break;
            
            default : printf("Invalid choice.Please Try again.\n");
        }
    }while( option_Inventory != 5 );

    return;
}

void Payment_Billing_Management(){
    int option_Billing;
    printf("<------------------- Welcome in Billing and Payment Management  -------------------->\n\n");
    do{
        printf("1. Generate Bill\n");
        printf("2. Display Bills\n");
        printf("3. Process Payment\n");
        printf("4. Back\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&option_Billing);

        switch(option_Billing){
            case 1:{
                Generate_Bill();
                break;
            }

            case 2:{
                Display_Bills();
                break;
            }

            case 3:{
                Process_Payment();
                break;
            }

            case 4: return;

            case 5: printf("Exiting .........\n");
            break;

            default : printf("Invalid choice.Please Try again.\n");
        }
    }while( option_Billing != 5 );
    return;
}

void Generate_Bill(){
    if(billcount >= MAX_PATIENTS){
        printf("Bill limit reached!\n");
        return;
    }

    Bill newBill;

    printf("Enter Patient ID : ");
    scanf("%d",&newBill.PatientID);

    if( newBill.PatientID < 1 || newBill.PatientID > MAX_PATIENTS ){
        printf("Invalid Patient ID! Try again \n");
        return;
    }

    printf("Enter Patient Name : ");
    scanf("%s",newBill.name);

    if( strcmp(patients[newBill.PatientID - 1].name , newBill.name) != 0 && patients[newBill.PatientID - 1].id != newBill.PatientID ){
        printf("Patient Name and ID doesn't match! Try again \n");
        return;
    }
    
    int doctorCharge = 1200;
    int RoomCharge_per_day = 500;
    int Days;
    printf("Enter number of days stayed in room : ");
    scanf("%d",&Days);
    
    int other;
    printf("Enter other charges : ");
    scanf("%d",&other);

    double GST = 0.18;
    double TotalAmount = (doctorCharge * Days) + (RoomCharge_per_day * Days) + other;
    double GST_Amount = TotalAmount * GST;
    TotalAmount += GST_Amount;

    newBill.amount = (int)TotalAmount;
    newBill.Status = 0;
    
    bills[billcount] = newBill;
    billcount++;
    printf("\n\nBill generated successfully! Bill ID : %d\n",billcount);
    printf("Total Amount : %d (including GST)\n", newBill.amount);
    printf("BreakDown:\n\n");
    printf("Doctor Charge (No of Days X 1200): %d\n",doctorCharge * Days);
    printf("Room Charge (No of Days X 500) : %d\n",RoomCharge_per_day * Days);
    printf("Other Charges : %d\n",other);
    printf("GST (18 percent) : %d\n",(int)GST_Amount);
    printf("Total Amount : %d\n\n",newBill.amount);
    return;
}

void Display_Bills(){
    int option_Display_Bills;

    do{
        printf("1. Display Bill by ID\n");
        printf("2. Display all Bills\n");
        printf("3. Back\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&option_Display_Bills);

        switch(option_Display_Bills){
            case 1: Display_Bill_by_ID();
            break;

            case 2: Display_all_Bills();
            break;

            case 3: return;
            break;

            case 4: printf("Exiting ....\n");
            break;

            default : printf("Invalid choice!\n");

        }
    }while( option_Display_Bills != 4 );
    return;
}

void Display_Bill_by_ID(){
    int id;
    printf("Enter Bill ID : ");
    scanf("%d",&id);

    if(id < 1 || id > billcount){
        printf("Invalid Bill ID!\n");
        return;
    }

    printf("Patient ID : %d\n",bills[id - 1].PatientID);
    printf("Patient Name : %s\n",patients[id - 1].name);
    printf("Patient Bill Amount : %d\n",bills[id - 1].amount);
    printf("Patient Bill Status : %s\n",bills[id - 1].Status ? "Paid" : "Unpaid");
    
    return;
}

void Display_all_Bills(){

    if(billcount == 0){
        printf("No Bills generated!\n");
        return;
    }

    printf("Sr.no.\tPatient ID\tName\t\tAmount\tStatus\n");
    for(int i = 0; i <= billcount; i++){
        printf("%d\t%d\t%s\t\t%d\t%s\n",i+1,bills[i].PatientID,patients[i].name,bills[i].amount,bills[i].Status ? "Paid" : "Unpaid");
    }
    return;
}

void Process_Payment(){
    int id;
    printf("Enter Bill ID : ");
    scanf("%d",&id);

    if(id < 1 || id > billcount){
        printf("Invalid Bill ID!\n");
        return;
    }

    printf("Patient ID : %d\n",bills[id - 1].PatientID);
    printf("Patient Bill Amount : %d\n",bills[id - 1].amount);

    int amount;
    do{
        printf("Enter 1 to pay the Bill : ");
        scanf("%d",&amount);

        if(amount == 1){
            bills[id - 1].Status = 1;
            printf("Payment processed Successfully!\n");
        }
        else{
        printf("Invalid Input.Please enter 1 to pay the bill.\n");
        }

    }while(amount != 1);

    return;
}

void History_Management(){
    int option_history;
    printf("_______________________________________________________________________________________________________________________\n\n\n");
    printf("<------------------------ Welcome in History Management Window ------------------------>\n");
    
    do{
        printf("NOTE : You can see medical history of Discharge patients only.\n\n");
        printf("1. View Medical History\n");
        printf("2. Delete Medical History\n");
        printf("3. Back\n");
        printf("Enter your choice : ");
        scanf("%d",&option_history);
        
        int found = 0;
        switch(option_history){
            case 1: printf("_____________________________________________________________________________________________________________________\n\n\n");
                    printf("Discharged patient 's Medical History :\n");
                    for(int i = 0; i < historycount; i++){
                        if(strcmp(histories[i].status, "Discharged") == 0){
                            printf("Patient ID : %d\n",histories[i].Patient_id);
                            printf("Medical Name : %s\n",histories[i].name);
                            printf("Patient Age : %d\n",histories[i].age);
                            printf("Patient Gender : %s\n",histories[i].Gender);
                            printf("Patient Illness: %s\n",histories[i].Illness);
                            printf("Patient Blood Group : %s\n",histories[i].blood_group);
                            printf("Patient Contact Number : %s\n",histories[i].mobile);
                            printf("Patient Address : %s\n",histories[i].address);
                            printf("Patient Status : %s\n",histories[i].status);
                            printf("_____________________________________________________________________________________________________________________\n\n");
                        }
                        else{
                            printf("No patient found !\n");
                            return;
                        }
                    }
            break;

            case 2: printf("_____________________________________________________________________________________________________________________\n\n\n");
                    int delete_history;
                    printf("Enter the patient ID to delete medical history : ");
                    scanf("%d",&delete_history);

                    for(int i=0; i<historycount; i++){
                        if(histories[i].Patient_id == delete_history){
                            found = 1;
                            for(int j=i; j<historycount-1; j++){
                                histories[j] = histories[j+1];
                            }
                            historycount--;
                            printf("Medical History of Patient ID %d has been deleted successfully.\n",delete_history);
                        } 
                    }
                    if(found == 0){
                        printf("Patient ID %d not found.\n",delete_history);
                    }
            break;

            case 3: return;
            break;

            default : printf("Invalid choice. Try again.\n");
            break;
        }
    }while(option_history !=3);
}

void patient_login(){
    char username[25];
    int password;
    int login_status = 0;
    
    printf("Enter your username : ");
    scanf("%s",&username);
    printf("Enter your password : ");
    scanf("%d",&password);

    for(int i=0; i<patientcount; i++){
        if(strcmp(username,patients[i].name) == 0 && patients[i].id == password){
            login_status = 1;
            if(strcmp(histories[i].status, "Discharged") == 0){
                printf("You have been discharged.\n");
                return;
            }
            printf("login succesfully Now you can excess these window .\n");
            Patient();
            return;
        }
        else{
            printf("Invalid username or password.\n");
            return;
        }
    }
    return;
}

void Patient(){
    int option_patient;
    printf("<----------- Welcome in Patient Portal ---------->\n");
    do{
        printf("1. View Appointment\n");
        printf("2. View Medical History\n");
        printf("3. Back\n");
        
        printf("Enter your choice : ");
        scanf("%d",&option_patient);

        switch(option_patient){
            case 1: view_appointment_ID();
            break;

            case 2: view_Medical();
            break;

            case 3: main();
            break;

            default : printf("Invalid Choice .\n");
            break;
        }
    }while(option_patient != 3);
}

void view_appointment_ID(){
    int id;
    printf("Enter your ID : ");
    scanf("%d",&id);

    printf("Current Appointments for Patient ID: %d\n", id);
    printf("____________________________________________________________________________________________\n");
    for (int i=0; i <appointmentcount; i++) {
        if (appointments[i].Patient_ID == id) {
            printf("Appointment ID: %d\n", appointments[i].Appointment_ID);
            printf("Date: %s\n", appointments[i].Date);
            printf("Time: %s\n", appointments[i].Time);
            printf("Doctor ID: %s\n", appointments[i].Doctor_ID);
            printf("Doctor Name: %s\n", doctors[i].name);
            printf("Doctor Contact: %s\n", doctors[i].contact);
            printf("Doctor Specialization: %s\n", doctors[i].specialization);
            printf("Appointment Status: %s\n\n", appointments[i].Status);
            printf("_____________________________________________________________________________________________\n");
        }
    }
}

void view_Medical(){
    int id;
    printf("Enter your ID : ");
    scanf("%d",&id);

    for (int i=0; i <patientcount; i++) {
        if (patients[i].id == id) {
            printf("Patient ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Patient Age : %d\n",patients[i].age);
            printf("Patient Gender : %s\n",patients[i].Gender);
            printf("Patient Illness: %s\n",patients[i].Illness);
            printf("Patient Blood Group : %s\n",patients[i].blood_group);
            printf("Patient Contact Number : %s\n",patients[i].mobile);
            printf("Patient Address : %s\n",patients[i].address);
            printf("_____________________________________________________________________________________________________\n");
            break;
        }
    }
}

void saveData(){
    FILE *file;
    

    file = fopen("users.txt","a");
    if(file == NULL){
        printf("Error opening file!\n");
        return;
    }

    for(int i = 0; i < usercount; i++){
        fprintf(file, "%s %s\n", users[i].username, users[i].password);
    }
    fclose(file);


    file = fopen("patients.txt","a");
    if(file == NULL){
        printf("Error opening file!\n");
        return;
    }

    for(int i = 0; i < patientcount; i++){
        fprintf(file, "%d %s %d %s %s %s %s %s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].DOB , patients[i].blood_group, patients[i].Illness, patients[i].mobile, patients[i].Gender);
    }
    fclose(file);
  
    file = fopen("rooms.txt","a");
    if(file == NULL){
        printf("Error opening file!\n");
        return;
    }

    for(int i = 0; i < roomcount; i++){
        fprintf(file, "%d %d %s %s\n", rooms[i].roomNumber, rooms[i].patientID, rooms[i].Room_occupied, rooms[i].Aadhaar_Card);
    }
    fclose(file);

    file = fopen("doctors.txt","a");
    if(file == NULL){
        printf("Error opening file!\n");
        return;
    }

    for(int i = 0; i < doctorcount; i++){
        fprintf(file, "%d %s %d %s %s\n", doctors[i].id, doctors[i].name, doctors[i].age, doctors[i].contact, doctors[i].specialization);
    }
    fclose(file);

    file = fopen("staffs.txt", "a");
    if(file == NULL){
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < staffcount; i++) {
        fprintf(file, "%d %s %d %s %s\n", staffs[i].id, staffs[i].name, staffs[i].age, staffs[i].contact, staffs[i].designation);
    }
    fclose(file);

    file = fopen("inventory.txt", "a");
    if(file == NULL){
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < inventorycount; i++) {
        fprintf(file, "%d %s %d %d %s %s\n", inventorys[i].id, inventorys[i].name, inventorys[i].quantity, inventorys[i].price, inventorys[i].Manufacturing_Date, inventorys[i].Expiry_Date);
    }
    fclose(file);

    file = fopen("bills.txt", "a");
    if(file == NULL){
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < billcount; i++) {
        fprintf(file, "%d %d %s %d %s\n", bills[i].PatientID, bills[i].amount, bills[i].name, bills[i].Status);
    }
    fclose(file);

}

void loadData(){
    FILE *file;

    file = fopen("users.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%s %s", users[usercount].username, users[usercount].password) != EOF) {
            usercount++;
        }
        fclose(file);
    }

    file = fopen("patients.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%d %s %d %s %s %s %s %s", &patients[patientcount].id, patients[patientcount].name, &patients[patientcount].age, patients[patientcount].DOB, patients[patientcount].blood_group, patients[patientcount].Illness, patients[patientcount].mobile, patients[patientcount].Gender) != EOF) {
            patientcount++;
        }
        fclose(file);
    }

    file = fopen("rooms.txt", "r");
    if(file != NULL){
        while(fscanf(file, "%d %d %s %s", &rooms[patientcount].roomNumber, &rooms[patientcount].patientID, rooms[patientcount].Room_occupied, rooms[patientcount].Aadhaar_Card) != EOF){
            patientcount++;
        }
        fclose(file);
    }

    file = fopen("doctors.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%d %s %d %s %s", &doctors[doctorcount].id, doctors[doctorcount].name, &doctors[doctorcount].age, doctors[doctorcount].contact, doctors[doctorcount].specialization) != EOF) {
            doctorcount++;
        }
        fclose(file);
    }

    file = fopen("staffs.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%d %s %d %s %s", &staffs[staffcount].id, staffs[staffcount].name, &staffs[staffcount].age, staffs[staffcount].contact, staffs[staffcount].designation) != EOF) {
            staffcount++;
        }
        fclose(file);
    }

    file = fopen("inventory.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%d %s %d %d %s %s", &inventorys[inventorycount].id, inventorys[inventorycount].name, &inventorys[inventorycount].quantity, &inventorys[inventorycount].price, inventorys[inventorycount].Manufacturing_Date, inventorys[inventorycount].Expiry_Date) != EOF) {
            inventorycount++;
        }
        fclose(file);
    }

    file = fopen("bills.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%d %d %s %d %s", &bills[billcount].PatientID, &bills[billcount].amount, bills[billcount].name, &bills[billcount].Status) != EOF) {
            billcount++;
        }
        fclose(file);
    }

}