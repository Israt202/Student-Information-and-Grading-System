#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void EXIT();
void student_basic_info();
void student_grade();

struct student_info
{
    struct basic_info
    {
        char name[30], email[30], address[30], dob[20];
        int id, phone;
    } basic_info;

    struct previous_edu_info
    {
        char institution_ssc[100], institution_hsc[100];
        int year_of_exam_ssc, year_of_exam_hsc;
        float grade_ssc, grade_hsc;
    } previous_edu_info;

    struct nsu_info
    {
        char department[15];
        int number_of_semester_completed;
        float previous_cgpa;

        struct semester
        {
            char semester_name[15];
            int number_of_course;

            struct course
            {
                char course_name[10], faculty_name[15];
                int credit_number;
                struct exam
                {
                    int quiz_1, quiz_2, quiz_3;
                    int mid_1, mid_2;
                    int assignment, final;
                } exam;

            } course[6];

        } semester;

    } nsu_info;

} st_info;

float new_cgpa, grade[6];

int main()
{
    char choice;
first:
main_f:
    printf("\n1. Input Student Basic Information.");
    printf("\n2. Show Students Grade.");
    printf("\n0. EXIT");

    printf("\nEnter your choice : ");
    fflush(stdin);
    scanf("%c", &choice);

    switch (choice)
    {
    case '0':
        EXIT();
    case '1':
        student_basic_info();
        break;
    case '2':
        student_grade();
        break;
    default:
        printf("\n\n\t\tYour choice is incorrect\n\n");
        goto first;
    }
    goto main_f;
    return 0;
}

void student_grade()
{
    char course_n[10], course[10];
    int i;
    float grd;
    FILE *fp = fopen("Student_grade.txt", "r");
    printf("\n\n\tEnter Course Name : ");
    fflush(stdin);
    gets(course_n);
    printf("<==============================================>");

    while (fscanf(fp, "%s %d %s %f", st_info.basic_info.name, &st_info.basic_info.id, course, &grd) != EOF)
    {
        if (strcmp(course_n, course) == 0)
        {
            printf("\n\tStudent Name : ");
            puts(st_info.basic_info.name);

            printf("\n\tStudent ID : ");
            printf("%d", st_info.basic_info.id);

            printf("\n\n\tCourse Name : ");
            puts(course);

            printf("\n\tGrade : ");
            printf("%.2f\n", grd);
            printf("------------------------------------------------\n\n");
        }
    }
    fclose(fp);
}

void student_basic_info()
{
    FILE *fp1 = fopen("student_info.txt", "a"), *fp2 = fopen("Student_grade.txt", "a"), *fp3 = fopen("Student_cgpa.txt", "a");
    char another = 'y';
    int i, x;
    float mid_avg[6], quiz_avg[6];
    while (another == 'y' || another == 'Y')
    {
        x = 0;
        printf("\n\n\tEnter Student Name : ");
        fflush(stdin);
        gets(st_info.basic_info.name);

        printf("\n\n\tEnter Student ID : ");
        fflush(stdin);
        scanf("%d", &st_info.basic_info.id);

        printf("\n\n\tEnter Student Date of Birth : ");
        fflush(stdin);
        gets(st_info.basic_info.dob);

        printf("\n\n\tEnter Student Phone No : ");
        fflush(stdin);
        scanf("%d", &st_info.basic_info.phone);

        printf("\n\n\tEnter Student E-mail : ");
        fflush(stdin);
        gets(st_info.basic_info.email);

        printf("\n\n\tEnter Student Address : ");
        fflush(stdin);
        gets(st_info.basic_info.address);

        printf("\n\n\tEnter Student Institute (SSC / O-Level) : ");
        fflush(stdin);
        gets(st_info.previous_edu_info.institution_ssc);

        printf("\n\n\tEnter Student Year-of-Exam (SSC / O-Level) : ");
        fflush(stdin);
        scanf("%d", &st_info.previous_edu_info.year_of_exam_ssc);

        printf("\n\n\tEnter Student Grade (SSC / O-Level) : ");
        fflush(stdin);
        scanf("%f", &st_info.previous_edu_info.grade_ssc);
        gets(st_info.basic_info.address);

        printf("\n\n\tEnter Student Institute (HSC / A-Level) : ");
        fflush(stdin);
        gets(st_info.previous_edu_info.institution_hsc);

        printf("\n\n\tEnter Student Year-of-Exam (HSC / A-Level) : ");
        fflush(stdin);
        scanf("%d", &st_info.previous_edu_info.year_of_exam_hsc);

        printf("\n\n\tEnter Student Grade (HSC / A-Level) : ");
        fflush(stdin);
        scanf("%f", &st_info.previous_edu_info.grade_hsc);

        printf("\n\n\tEnter Student Department : ");
        fflush(stdin);
        gets(st_info.nsu_info.department);

        printf("\n\n\tEnter Student Number of Semester Completed  : ");
        fflush(stdin);
        scanf("%d", &st_info.nsu_info.number_of_semester_completed);

        printf("\n\n\tEnter Student Previous CGPA : ");
        fflush(stdin);
        scanf("%f", &st_info.nsu_info.previous_cgpa);

        printf("\n\n\tEnter Semester name : ");
        fflush(stdin);
        gets(st_info.nsu_info.semester.semester_name);

        printf("\n\n\tEnter Number of Course : ");
        fflush(stdin);
        scanf("%d", &st_info.nsu_info.semester.number_of_course);
        fprintf(fp1, "%s %d %s %d %s %s %s %d %f %s %d %f %s %d %f %s %d ", st_info.basic_info.name, st_info.basic_info.id,
                st_info.basic_info.dob, st_info.basic_info.phone,
                st_info.basic_info.email, st_info.basic_info.address, st_info.previous_edu_info.institution_ssc,
                st_info.previous_edu_info.year_of_exam_ssc, st_info.previous_edu_info.grade_ssc, st_info.previous_edu_info.institution_hsc,
                st_info.previous_edu_info.year_of_exam_hsc, st_info.previous_edu_info.grade_hsc, st_info.nsu_info.department,
                st_info.nsu_info.number_of_semester_completed, st_info.nsu_info.previous_cgpa, st_info.nsu_info.semester.semester_name,
                st_info.nsu_info.semester.number_of_course);

        for (i = 0; i < st_info.nsu_info.semester.number_of_course; i++)
        {
            printf("\n\t\tFor Course %d", i + 1);

            printf("\n\n\tEnter Course Name : ");
            fflush(stdin);
            gets(st_info.nsu_info.semester.course[i].course_name);

            printf("\n\n\tEnter Faculty Name : ");
            fflush(stdin);
            gets(st_info.nsu_info.semester.course[i].faculty_name);

            printf("\n\n\tEnter Number of Credit : ");
            fflush(stdin);
            scanf("%d", &st_info.nsu_info.semester.course[i].credit_number);
            x = x + st_info.nsu_info.semester.course[i].credit_number;
            if (x > 15)
            {
                printf("\n\n\tSorry!, You can't add more creadit\n\n");
                fclose(fp1);
                fclose(fp2);
                fclose(fp3);
                main();
            }

            printf("\n\n\tEnter Quiz-01 Number: ");
            fflush(stdin);
            scanf("%d", &st_info.nsu_info.semester.course[i].exam.quiz_1);

            printf("\n\n\tEnter Quiz-02 Number: ");
            fflush(stdin);
            scanf("%d", &st_info.nsu_info.semester.course[i].exam.quiz_2);

            printf("\n\n\tEnter Quiz-03 Number: ");
            fflush(stdin);
            scanf("%d", &st_info.nsu_info.semester.course[i].exam.quiz_3);

            printf("\n\n\tEnter Mid-01 Number: ");
            fflush(stdin);
            scanf("%d", &st_info.nsu_info.semester.course[i].exam.mid_1);

            printf("\n\n\tEnter Mid-02 Number: ");
            fflush(stdin);
            scanf("%d", &st_info.nsu_info.semester.course[i].exam.mid_2);

            printf("\n\n\tEnter Assignment Number: ");
            fflush(stdin);
            scanf("%d", &st_info.nsu_info.semester.course[i].exam.assignment);

            printf("\n\n\tEnter Final Number: ");
            fflush(stdin);
            scanf("%d", &st_info.nsu_info.semester.course[i].exam.final);

            mid_avg[i] = (st_info.nsu_info.semester.course[i].exam.mid_1 + st_info.nsu_info.semester.course[i].exam.mid_2) / 2;
            quiz_avg[i] = (st_info.nsu_info.semester.course[i].exam.quiz_1 + st_info.nsu_info.semester.course[i].exam.quiz_2 + st_info.nsu_info.semester.course[i].exam.quiz_3) / 3;

            grade[i] = ((mid_avg[i] * 0.3) + (quiz_avg[i] * 0.2) + (st_info.nsu_info.semester.course[i].exam.final * 0.3) + (st_info.nsu_info.semester.course[i].exam.assignment * 0.2))/x;

            fprintf(fp1, "%s %s %d %d %d %d %d %d %d %d\n", st_info.nsu_info.semester.course[i].course_name,
                    st_info.nsu_info.semester.course[i].faculty_name, st_info.nsu_info.semester.course[i].credit_number,
                    st_info.nsu_info.semester.course[i].exam.quiz_1, st_info.nsu_info.semester.course[i].exam.quiz_2,
                    st_info.nsu_info.semester.course[i].exam.quiz_3, st_info.nsu_info.semester.course[i].exam.mid_1,
                    st_info.nsu_info.semester.course[i].exam.mid_2, st_info.nsu_info.semester.course[i].exam.assignment,
                    st_info.nsu_info.semester.course[i].exam.final);
            fprintf(fp2, "%s %d %s %f\n", st_info.basic_info.name, st_info.basic_info.id,
                    st_info.nsu_info.semester.course[i].course_name, grade[i]);
            fprintf(fp3, "%s %d %s %f\n", st_info.basic_info.name, st_info.basic_info.id,
                    st_info.nsu_info.semester.course[i].course_name, new_cgpa);
        }

        printf("\n\n\t\tEnter Another Student Information ? (Y/N) : ");
        fflush(stdin);
        scanf("%c", &another);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}

void EXIT()
{
    printf("\n\t\tThank you for watching this Project.\n\n");
    exit(0);
}
