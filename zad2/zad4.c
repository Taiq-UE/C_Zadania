#include <stdio.h>
#include <math.h>

typedef struct {
    char name[100];
    float mark;
}student;

void sortStudents(student students[], int size){
    for(int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].mark < students[j + 1].mark) {
                student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {

    student students[3];
    students[0] = (student){"Romek", 3.5};
    students[1] = (student){"Andrzej", 4.5};
    students[2] = (student){"Jurek", 4.6};

    sortStudents(students, 3);

    for(int i = 0; i < 3; i++){
        printf("%s: %.2f\n", students[i].name, students[i].mark);
    }

    return 0;
}

