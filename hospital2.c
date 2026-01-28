#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM 100

typedef struct {
    int roomNumber;
    int Room_occupied;
    int patientID;
} Room;

Room rooms[MAX_ROOM];
int roomcount;
int patientcount;

void saveroom() {
    FILE *file = fopen("room.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < roomcount; i++) {
        fprintf(file, "%d %d %d\n", rooms[i].roomNumber, rooms[i].Room_occupied, rooms[i].patientID);
    }
    fclose(file);
}

void loadroom() {
    FILE *file = fopen("room.txt", "r");
    if (file == NULL) {
        printf("Error opening file or file does not exist.\n");
        return;
    }
    roomcount = 0;
    while (fscanf(file, "%d %d %d", &rooms[roomcount].roomNumber, &rooms[roomcount].Room_occupied, &rooms[roomcount].patientID) != EOF) {
        roomcount++;
    }
    fclose(file);
}

void Room_Allocation() {
    int option_room_allocation;

    loadroom();

    if (patientcount == 0) {
        printf("No patient found For room allocation .....\n");
        return;
    }

    printf("Enter patient ID to allocate room: ");
    scanf("%d", &option_room_allocation);

    if (option_room_allocation < 1 || option_room_allocation > patientcount) {
        printf("Invalid patient ID\n");
        return;
    }

    for (int i = 0; i < roomcount; i++) {
        if (rooms[i].Room_occupied == 0) {
            rooms[i].Room_occupied = 1;
            rooms[i].patientID = option_room_allocation;
            printf("Room %d allocated to patient %d\n", rooms[i].roomNumber, option_room_allocation);
            saveroom();
            return;
        }
    }
    printf("No available rooms for allocation .....\n\n");
}

void Display_Room() {
    loadroom();
    printf("____________________________________________________________\n");
    printf("| Sr No.\t| Room No.\t| Patient ID \t| Status   |\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < roomcount; i++) {
        printf("| %d\t\t| %d\t\t| %d\t\t| %s |\n", i + 1, rooms[i].roomNumber, rooms[i].patientID, rooms[i].Room_occupied ? "Occupied" : "Available");
        printf("-------------------------------------------------------------\n");
    }
}

void Room_Disallocation() {
    int option_room_disallocation;

    loadroom();

    printf("Enter room number to disallocate room: ");
    scanf("%d", &option_room_disallocation);

    if (option_room_disallocation < 1 || option_room_disallocation > roomcount) {
        printf("Invalid room number\n");
        return;
    }

    if (rooms[option_room_disallocation - 1].Room_occupied == 0) {
        printf("Room %d is already available\n\n", option_room_disallocation);
        return;
    }

    rooms[option_room_disallocation - 1].Room_occupied = 0;
    rooms[option_room_disallocation - 1].patientID = -1;

    printf("Room No. %d disallocated successfully.\n\n", option_room_disallocation);
    saveroom();
}

int main() {
    // Example usage
    patientcount = 10;  // Example patient count
    Room_Allocation();
    Display_Room();
    Room_Disallocation();
    Display_Room();
    return 0;
}
