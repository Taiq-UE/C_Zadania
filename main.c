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
    for(int i = 0; i < *size; i++){
        if(strcmp(contacts[i].surname, surname) == 0) {
            for(int j = i; j < *size - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*size)--;
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

    Contact newContact = {"Jan", "Ziomson", "123123999"};
    addContact(contacts, sizePtr, newContact);

    //searchBySurname(contacts, size, "Nowak");

    deleteBySurname(contacts, sizePtr, "Nowak");

    displayContacts(contacts, size);

    return 0;
}

