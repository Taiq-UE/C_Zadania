#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
    int studentCount = 500;

    srand(time(0));

    student students[studentCount];

    for(int i = 0; i < studentCount; i++){
        char name[studentCount];
        sprintf(name, "Student%d", i+1);

        float mark = 2.0 + (rand() / (float)RAND_MAX) * 3.0;

        strcpy(students[i].name, name);
        students[i].mark = mark;
    }

    sortStudents(students, studentCount);

    for(int i = 0; i < studentCount; i++){
        printf("%s : %f\n", students[i].name, students[i].mark);
    }

    return 0;
}