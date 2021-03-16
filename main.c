#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Name {
    char familyName[20];
    char surName[21];
    char lastName[20];
}name;

typedef struct Student {
    int studentID;
    name studentName;
    double GPA;
}student;

void inputStudentName(name* studentName) {
    printf("Family Name: ");
    fgets(studentName->familyName, 100, stdin);
    studentName->familyName[strlen(studentName->familyName)-1]='\0';
    printf("Surname: ");
    fgets(studentName->surName, 100, stdin);
    studentName->surName[strlen(studentName->surName)-1]='\0';
    printf("Last Name: ");
    fgets(studentName->lastName, 100, stdin);
    studentName->lastName[strlen(studentName->lastName)-1]='\0';
}
student inputStudent()
{
    student Student;
    printf("Student ID: ");
    scanf("%d", &Student.studentID);
    fflush(stdin);
    inputStudentName(&Student.studentName);
    fflush(stdin);
    printf("Student GPA: ");
    scanf("%lf", &Student.GPA);
    fflush(stdin);
    return Student;
}
void showStudentInfo( student Student) {
    printf("%-30d %-30s %-30s %-30s %-20.2f\n",
    Student.studentID, Student.studentName.familyName, Student.studentName.surName, Student.studentName.lastName, Student.GPA);
}
void showColumnName() {
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s %-30s %-30s %-30s %-20s\n",
        "Student ID", "Family Name", "Surname", "Last Name", "Student GPA");
}

void showStudentList(student *ds, int numberOfStudent)
{
    showColumnName();
    int i;
    for(i = 0; i < numberOfStudent; i++) {
        showStudentInfo(ds[i]);
    }
}
void swap(student *xp, student *yp)
{
    student temp = *xp;
    *xp = *yp;
    *yp= temp;
}
void sortFollowingGPA( student *ds, int numberOfStudent  )
{
    for (int i=0; i<numberOfStudent-1; i++)
    {
        for (int j=0 ;j<numberOfStudent-i-1 ; j++)
        {
            if (ds[j].GPA>ds[j+1].GPA) {
                swap(&ds[j] , &ds[j+1]);
            }
        }
    }
}
void sortFollowingName( student *ds, int numberOfStudent  )
{
    for (int i=0; i<numberOfStudent-1; i++)
    {
        for (int j=0 ;j<numberOfStudent-i-1 ; j++)
        {
            if (strcmp(ds[j].studentName.lastName,ds[j+1].studentName.lastName)>0)
            {
                swap(&ds[j], &ds[j+1]);
            }
        }
    }
}
void findStudentbyName(student *a, int *n)
{
    char name[20];
    fflush(stdin);
    int x=-1;
    int check=0;
    do{
    printf("Enter student name you want to find: ");
    fgets(name,100,stdin);
    name[strlen(name)-1]='\0';
    for (int i=0;i<*n;i++){
        x = strcmp(name,a[i].studentName.lastName);
    if ( x==0 )
    {
        showColumnName();
        showStudentInfo(a[i]);
        check = 1; break;
    }
        if(check ==1) break;
        printf("Invalid ID!\nPlease try again\n");
    }
    }while(check!=0);
}
void findStudentbyID(student *a, int *n)
{
    int ID;
    int check=0;
    do{
    fflush(stdin);
    printf("Enter student ID you want to find: ");
    scanf("%d",&ID);
    for(int i=0;i<*n; i++)
    {
        
        if (a[i].studentID==ID)
        {
            showColumnName();
            showStudentInfo(a[i]);
            check = 1; break;
        }
    }
        if(check ==1) break;
        printf("Invalid ID!\nPlease try again\n");
    }while(check !=0);
}
void findStudent(student *a, int *n){
    char option;
    do {
        printf("=============== MENU ===============");
        printf("\n1. Find student by name");
        printf("\n2. Find student by ID");
        printf("\n3. Return");
        printf("\nYour selection: ");
        scanf("%c",&option);
        switch (option) {
            case '1':
                findStudentbyName(a, n);
                break;
            case '2':
                findStudentbyID(a, n);
                break;
            case '3':
                break;
            default:
                printf("Invalid selection!\nTry again!\n");
                break;
        }
        
    } while (option!=3);
}


int main() {
    student Students[100];
    int numberOfStudent = 0;
    char options;
    do {
        printf("=============== MENU ===============");
        printf("\n1. Add student to the list.");
        printf("\n2. Show the student list.");
        printf("\n3. Sort student following name.");
        printf("\n4. Sort student following GPA.");
        printf("\n5. Find Student.");
        printf("\n6. Write student's information to file.");
        printf("\n7. Exit.");
        printf("\nYour selection:  ");
        scanf("%c", &options);
        student Student;
        switch(options) {
            case '1':
                Student = inputStudent();
                Students[numberOfStudent++] = Student;
                break;
            case '2':
                showStudentList(Students,numberOfStudent);
                break;
               
            case '3':
                sortFollowingName(Students, numberOfStudent);
                showStudentList(Students,numberOfStudent);
                break; 
                
            case '4':
                sortFollowingGPA(Students, numberOfStudent);
                showStudentList(Students,numberOfStudent);
                break;
            case '5':
                findStudent(Students, &numberOfStudent);
                break;
            case '7':
                break;
            default:
                printf("Invalid selection!\nTry again!\n");
                break;
        }
        
    } while(options);
    
    return 0;
}
