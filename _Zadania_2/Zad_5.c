#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct {
    char name[100];
    char surname[100];
    char phoneNumber[100];
}Contact;

void addContact(Contact *contacts, int *size, Contact newContact) {
    contacts[*size] = newContact;
    (*size)++;
}

void displayContacts(Contact *contacts, int size) {
    for(int i = 0; i < size; i++){
        printf("%s %s: %s\n", contacts[i].name, contacts[i].surname, contacts[i].phoneNumber);
    }
}

void searchBySurname(Contact *contacts, int size, char *surname) {
    for(int i = 0; i < size; i++){
        if(strcmp(contacts[i].surname, surname) == 0) {
            printf("%s %s: %s\n", contacts[i].name, contacts[i].surname, contacts[i].phoneNumber);
        }
    }
}

void deleteBySurname(Contact *contacts, int *size, char *surname) {
    for(int i = 0; i < *size;){
        if(strcmp(contacts[i].surname, surname) == 0) {
            for(int j = i; j < *size - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*size)--;
        } else {
            i++;
        }
    }
}

int main() {
    Contact contacts[100];
    contacts[0] = (Contact){"Romek", "Kowalski", "123456789"};
    contacts[1] = (Contact){"Andrzej", "Nowak", "987654321"};
    contacts[2] = (Contact){"Jurek", "Nowak", "123123123"};
    int size = 3;
    int *sizePtr = &size;
    int choice;
    char surname[100];
    Contact newContact;

    while(1) {
        printf("\n1. Add contact\n2. Display contacts\n3. Search by surname\n4. Delete by surname\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name, surname and phone number: ");
                scanf("%s %s %s", newContact.name, newContact.surname, newContact.phoneNumber);
                addContact(contacts, sizePtr, newContact);
                break;
            case 2:
                displayContacts(contacts, size);
                break;
            case 3:
                printf("Enter surname: ");
                scanf("%s", surname);
                searchBySurname(contacts, size, surname);
                break;
            case 4:
                printf("Enter surname: ");
                scanf("%s", surname);
                deleteBySurname(contacts, sizePtr, surname);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

}

