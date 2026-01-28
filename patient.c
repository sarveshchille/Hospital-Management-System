#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define MAX_USER 10
#define MAX_PATIENTS 50
#define MAX_ROOM 50
#define MAX_DOCTORS 50
#define MAX_STAFF 50

void signUp();
void login();
void Reception();
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
void Inventory();
void Billing_payment();
void Display_All_Doctor();
void Display_doctor_by_ID();
void Display_all_Bills();
void Display_Bill_by_ID();
void Process_Payment();
void Display_Bills();
void Generate_Bill();
void Display_Staff_All();
void Display_Staff_ID();



typedef struct{
    int id;
    char Gender[10];
    char name[25];
    int age;
    char DOB[15];
    char Illness[50];
    char address[100];
    char moblie[15];
    char blood_group[3];
} patient;

typedef struct{
    char username[50];
    char password[50];
} User;

typedef struct{
    int roomNumber;
    int Room_occupied;
    int patientID;
} Room;

typedef struct{
    int id;
    char name[25];
    char specialization[50];
    char contact[15];
    int age;
} doctor;

typedef struct{
    int id;
    char name[25];
    char contact[15];
    char designation[50];
    int age;
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
} Bill;


User users[MAX_USER];
patient patients[MAX_PATIENTS];
doctor doctors[MAX_DOCTORS];
Room rooms[MAX_ROOM];
staff staffs[MAX_STAFF];
inventory inventorys[MAX_PATIENTS];
Bill bills[MAX_PATIENTS];

int usercount = 0;
int patientcount = 0;
int roomcount = 0;
int doctorcount = 0;    
int staffcount = 0;
int inventorycount = 0;
int billcount = 0;

int main(){
    int choice;
    
    printf("**   **  *****  *****  *****  *******  *****  *****   *    \n");
    printf("**   **  *   *  *      *   *     *       *    *   *   *    \n");
    printf("**   **  *   *  *      *   *     *       *    *   *   *     \n");
    printf("*******  *   *  *****  *****     *       *    *****   *    \n");
    printf("**   **  *   *      *  *         *       *    *   *   *    \n");
    printf("**   **  *   *      *  *         *       *    *   *   *     \n");
    printf("**   **  *****  *****  *      *******    *    *   *   *******\n");

    
    do{
    printf("\t\t\t\t--welcome--\n");
    printf("1. Sign Up\n");
    printf("2. Login\n");
    printf("3. Exit \n");

    printf("\t\t\t\t\tChoose option ");
    scanf("%d",&choice);
    
        switch(choice){

        case 1 : signUp();
        break;

        case 2 : login();
                Reception();
        break;

        case 3 :  printf("**** THANKYOU FOR COMING ****");
        break;

        default : printf("You pressed wrong key .........");
        }

    }while( choice != 3);

    return 0; 
}

void signUp() {
    if (usercount >= MAX_USER) {
        printf("User limit reached!\n");
        return;
    }

    User new_user;

    printf("Enter username: ");
    scanf("%s", new_user.username);
    printf("Enter password: ");
    scanf("%s", new_user.password);

    users[usercount] = new_user;
    usercount++;
    printf("Sign-up successful!\n");

    return;
}

void login(){
    
    User old_user;
    printf("enter username : ");
    scanf("%s", old_user.username);

    printf("enter password : ");
    scanf("%s", old_user.password);

    for(int i=0; i<usercount; i++){
        if(strcmp(users[i].username,old_user.username)== 0 && strcmp(users[i].password,old_user.password) == 0){
            printf("Login successfully ! Welcome %s\n", old_user.username);
            return ;
        }
    }
    printf("Invalid username or password \n");
    return ;
}

void Reception(){
    int option_Reception;

    do{
    printf("<--------  Welcome in Reception window  -------->\n\n");

            printf("1. Add patient\n");
            printf("2. Remove patient\n");
            printf("3. Display patient\n");
            printf("4. Room Allocation\n");
            printf("5. Display Rooms\n");
            printf("6. Room Disallocation\n");
            printf("7. Add Doctors\n");
            printf("8. Display Doctors\n");
            printf("9. Remove Doctors\n");
            printf("10.Add Medical Staff\n");
            printf("11.Display Medical Staffs\n");
            printf("12.Remove Medical Staff\n");
            printf("13.Inventory\n");
            printf("14.Billing and Payment\n");
            printf("15.Main menu\n");
            printf("16.Exit\n");
                
            printf("\t\t\t\tChoose one option : ");
            scanf("%d",&option_Reception);

            switch(option_Reception){
                
            case 1 : Add_Patient();
                break;

            case 2 : Remove_patient();
                break;

            case 3 : Display_patient();
                break;

            case 4 : Room_Allocation(); 
                break;
                
            case 5 : Display_Room();
                break;

            case 6 : Room_Disallocation();
                break;

            case 7 : Add_Doctor();
                break;

            case 8 : Display_doctor();
                break;
            
            case 9 : Remove_doctor();
                break;
            
            case 10 : Add_Medical_Staff();
                break;
            
            case 11 : Display_medical_staff();
                break;
            
            case 12 : Remove_medical_staff();
                break;

            case 13: Inventory();
                break;

            case 14: Billing_payment();
                break;

            case 15 : return;
                break;

            case 16 : printf("THANKS FOR COMMING .....\n");
                break;

            default : printf("You are pressed wrong key .....\n");
            }
        }while(option_Reception != 16);
    return ;
}


void Add_Patient(){
    if(patientcount >= MAX_PATIENTS){
        printf("patients level reached !.....\n");
        return ;
    }

    patient new_patient;
    new_patient.id = patientcount + 1 ;

    printf("patient id number : %d\n",new_patient.id);
    printf("patient name : ");
    scanf("%s",new_patient.name);
    printf("patient age : ");
    scanf("%d",&new_patient.age);
    printf("patient D.O.B.(DD/MM/YYYY) : ");
    scanf("%s",new_patient.DOB);
    printf("patient Blood group : ");
    scanf("%s",new_patient.blood_group);
    printf("patient Illness : ");
    scanf("%s",new_patient.Illness);
    printf("patient Moblie Number : ");
    scanf("%s",new_patient.moblie);
    printf("patient Gender : ");
    scanf("%s",new_patient.Gender);
    printf("patient Address : ");
    scanf("%s",new_patient.address);

    patients[patientcount] = new_patient;
    patientcount++;
    
    printf("Patient added successfully.....\t patient's id number is %d",new_patient.id);
    return ;
}

void Remove_patient(){
    int option_Remove_patients;
    do{
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
                printf("Enter the id of the patient you want to remove : ");
                int id;
                scanf("%d",&id);
                
                if(id < 1 || id > patientcount){
                    printf("Patient not found\n");
                }
                else{
                    for(int i=id; i<patientcount; i++){
                        patients[i] = patients[i+1];
                    }
                    patientcount--;
                    printf("Patient removed successfully .......\n");
                }
                break;
            
            case 3:
                return;

            case 4:
                printf("Exiting .......\n");

            default : printf("You are presses wrong key....\n");

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
                printf("patient Moblie : %s\n",patients[i].moblie);
            }
            
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
                        printf("patient Moblie : %s\n",patients[id - 1].moblie);
                        printf("patient Address : %s\n",patients[id - 1].address);

            case 3 : return ;

            case 4 : printf("Exiting .....\n");
            break;
            
            default : printf("You are pressed wrong key....\n");

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
    printf("NO available rooms for allocation .....\n");
}

void Display_Room(){
    printf("Sr No.\tRoom No.\tStatus \t Patient ID\n");
    for(int i=0; i<roomcount; i++){
        printf("%d\t\t%d\t\t%s\t\t%d\n",i+1,rooms[i].roomNumber,rooms[i].Room_occupied ? "Occupied" : "Available",rooms[i].patientID);
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
        printf("Room %d is already available\n",option_room_disallocation);
        return ;
    }

    rooms[option_room_disallocation - 1].Room_occupied = 0;
    rooms[option_room_disallocation - 1].patientID = -1;

    printf("Room No. %d disallocated successfully.\n",option_room_disallocation);

}

void Add_Doctor(){
    if(doctorcount >= MAX_DOCTORS){
        printf("Doctors limit reached!\n");
        return;
    }

    doctor new_doctor;
    new_doctor.id = doctorcount++;

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
    printf("Select One of the above options : ");
    scanf("%d", &specialization_choice);
    
    switch (specialization_choice) {
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

        default: printf("Invalid choice! Defaulting to General Practitioner.\n");
                 strcpy(new_doctor.specialization, "General Practitioner");
        break;

    }
    
    doctors[doctorcount] = new_doctor;
    doctorcount++;

    printf("Doctor added successfully!\nDoctor ID Number : %d\n", new_doctor.id);
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

    printf("Sr NO.\tDoctor ID\tName\t\tAge\t Specialization\t\tContact\n");
    for(int i = 0; i < doctorcount; i++){
        printf("%d\t%d\t%s\t%d\t%s\t%s\n",i+1,doctors[i].id,doctors[i].name,doctors[i].age,doctors[i].specialization,doctors[i].contact);
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
            newStaff.id = staffcount++;

            printf("Enter Name : ");
            scanf("%s",&newStaff.name);

            printf("Enter Age : ");
            scanf("%d",&newStaff.age);

            printf("Enter Contact No. : ");
            scanf("%s",&newStaff.contact);

            printf("Select Staff Department\n\n");

            printf("1. Nurse\n");
            printf("2. Medical Assistant\n");
            printf("3. Lab Technician\n");
            printf("4. Radiology Technician\n");
            printf("5. Surgical Technologist\n");
            printf("6. Physiotherapist\n");
            printf("7. Dietitian/Nutritionist\n");
            printf("8. Emergency Medical Technician (EMT)\n");
            printf("9. Paramedic\n");
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

            printf("Choose a option : ");
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

    printf("Sr.No.\tID no.\tStaff Name\t\tAge\tdesignation\t\tContact No.\n");
    for(int i = 0; i < staffcount; i++){
        printf("%d\t\t%d\t\t%s\t\t%d\t\t%s\t\t%s\n",i+1,staffs[i].id, staffs[i].name, staffs[i].age , staffs[i].designation , staffs[i].contact);
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

void Inventory(){
    int option_Inventory;

    do{
        printf("<--------- Welcome to Inventory Management ---------->\n");
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
                newitem.id = inventorycount++;

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
                printf("<--------- Inventory List ---------->\n\n");
                printf("Sr .No.\tID no\tItem Name\t\tQuantity\tPrice\tManufacturing Date\tExpiry Date\n");

                for(int i = 0; i < inventorycount; i++){
                    printf("%d\t%d\t%s\t\t%d\t%d\t%s\t%s\n",i+1,inventorys[i].id,inventorys[i].name,inventorys[i].quantity,inventorys[i].price,inventorys[i].Manufacturing_Date,inventorys[i].Expiry_Date);
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

void Billing_payment(){
    int option_Billing;

    do{
        printf("<-------- Billing and Payment Menu ---------->\n\n");
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
    patient newpatient;

    printf("Enter Patient ID : ");
    scanf("%d",&newBill.PatientID);

    printf("Enter Patient Name : ");
    scanf("%s",newpatient.name);

    printf("Enter Bill Amount : ");
    scanf("%d",&newBill.amount);
    newBill.Status = 0;

    bills[billcount] = newBill;
    billcount++;
    printf("Bill generated successfully! Bill ID : %d\n",billcount);
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
    for(int i = 1; i <= billcount; i++){
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
            printf("Payment processed Successfully!\n");
        }
        else{
            printf("Invalid Input.Please enter 1 to pay the bill.\n");
        }
    }while(amount != 1);

    return;
}