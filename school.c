#include <stdio.h>
#include<string.h>

// struct Student
// {
//     char firstname[20];
//     char lastname[20];
//     char address[40];
//     long long  phonenumber;
//     char gender[20];
//     char grade[40];
//     char section[20];
//     int age;
//     long  registrationNumber;
//     char email[100];
// };

int compare(char word1[],char word2[]){
   int i=0;
   while(word1[i]!='\0' && word2[2]!='\0'){
    if(word1[i]!=word2[i]){
        return 0;
        break;
    }
    i++;
   }
   return 1;

};

int main()
{

    int choice, filteredchoice;

    printf("\n");
    printf("\t\t\t");
    printf("--------------------------------------------\n");
    printf("\t\t\t");
    printf("| WELCOME TO OUR SCHOOL MANAGEMENT SYSTEM. |");
    printf("\n");
    printf("\t\t\t");
    printf("--------------------------------------------\n");
    printf("\n");
    printf("What do you want to do?.\n");
    printf("1 --> to add a new user.\n");
    printf("2 --> to list all users using reistration number.\n");
    printf("3 --> to search the user with registration number.\n");
    printf("4 --> to search the user with firstname.\n");
    printf("5 --> to search the user with lastname.\n");
    // printf("4 -->")

label:
    scanf("%d", &choice);

    if (choice == 1)

    {
        FILE *fp;
        fp = fopen("address.txt", "a");

        char firstname[20];
        char lastname[20];
        char address[40];
        long long  phonenumber;
        char gender[20];
        char grade[40];
        char section[20];
        int age;
        long  registrationNumber;
        char email[100];

        printf("Enter the firstname.\n");
        scanf("%s", firstname);
        printf("Enter the lastname.\n");
        scanf("%s", lastname);
        printf("Enter the address.\n");
        scanf("%s", address);
        printf("Enter the phonenumber.\n");
        scanf("%lld",&phonenumber);
        printf("Enter the gender.\n");
        scanf("%s", gender);
        printf("Enter the grade.\n");
        scanf("%s", grade);
        printf("Enter the section.\n");
        scanf("%s", section);
        printf("Enter the age.\n");
        scanf("%d", &age);
        printf("Enter the registrationnumber.\n");
        scanf("%ld",&registrationNumber);
        printf("Enter the email.\n");
        scanf("%s", email);


        fprintf(fp, "Firstname:%s Lastname:%s Address:%s Phonenumber:%lld Gender:%s Grade:%s Section:%s Age:%d Registrationnumber:%ld Email:%s\n",
        firstname,lastname,address,phonenumber,gender,grade,section,age,registrationNumber,email
        );
        fclose(fp);
    }
    else if(choice==2){

        FILE *fp;
        fp = fopen("address.txt", "r");

        char firstname[20];
        char lastname[20];
        char address[40];
        long long  phonenumber;
        char gender[20];
        char grade[40];
        char section[20];
        int age;
        long  registrationNumber;
        char email[100];

        while(fscanf(fp, "Firstname:%s Lastname:%s Address:%s Phonenumber:%lld Gender:%s Grade:%s Section:%s Age:%d Registrationnumber:%ld Email:%s\n",
        firstname,lastname,address,&phonenumber,gender,grade,section,&age,&registrationNumber,email
        )!=EOF){
            printf("\t\t");
            printf("---------------------------");
            printf("\n\n");
            printf("\t\t");
            printf("Firstname:%s \n\t\tLastname:%s \n\t\tAddress:%s \n\t\tPhonenumber:%lld \n\t\tGender:%s \n\t\tGrade:%s \n\t\tSection:%s \n\t\tAge:%d \n\t\tRegistrationnumber:%ld \n\t\t2Email:%s",
            firstname,lastname,address,phonenumber,gender,grade,section,age,registrationNumber,email
            );
            printf("\n\n");
            
        }

    }
    else if (choice == 3)
    {   
        long regis;
        printf("Enter the registration number.\n");
        scanf("%d",&regis);

         FILE *fp;
        fp = fopen("address.txt", "r");

        char firstname[20];
        char lastname[20];
        char address[40];
        long long  phonenumber;
        char gender[20];
        char grade[40];
        char section[20];
        int age;
        long  registrationNumber;
        char email[100];
        int results=0;

        while(fscanf(fp, "Firstname:%s Lastname:%s Address:%s Phonenumber:%lld Gender:%s Grade:%s Section:%s Age:%d Registrationnumber:%ld Email:%s\n",
        firstname,lastname,address,&phonenumber,gender,grade,section,&age,&registrationNumber,email
        )!=EOF){
            if(regis==registrationNumber){
            printf("\t\t");
            printf("---------------------------");
            printf("\n\n");
            printf("\t\t");
            printf("Firstname:%s \n\t\tLastname:%s \n\t\tAddress:%s \n\t\tPhonenumber:%lld \n\t\tGender:%s \n\t\tGrade:%s \n\t\tSection:%s \n\t\tAge:%d \n\t\tRegistrationnumber:%ld \n\t\t2Email:%s",
            firstname,lastname,address,phonenumber,gender,grade,section,age,registrationNumber,email
            );
            printf("\n\n");
            results++;
            }  
        }
        if(results==0){
            printf("User with this registration number doesnot exit.\n");
        }

    }
    else if(choice==4){

        char fname[20];
        printf("Enter the firstname.\n");
        scanf("%s",fname);

        FILE *fp;
        fp = fopen("address.txt", "r");

        char firstname[20];
        char lastname[20];
        char address[40];
        long long  phonenumber;
        char gender[20];
        char grade[40];
        char section[20];
        int age;
        long  registrationNumber;
        char email[100];
        int results=0;

        while(fscanf(fp, "Firstname:%s Lastname:%s Address:%s Phonenumber:%lld Gender:%s Grade:%s Section:%s Age:%d Registrationnumber:%ld Email:%s\n",
        firstname,lastname,address,&phonenumber,gender,grade,section,&age,&registrationNumber,email
        )!=EOF){
            // printf("%d",compare(fname,firstname));
            if(compare(fname,firstname)==1){
            printf("\t\t");
            printf("---------------------------");
            printf("\n\n");
            printf("\t\t");
            printf("Firstname:%s \n\t\tLastname:%s \n\t\tAddress:%s \n\t\tPhonenumber:%lld \n\t\tGender:%s \n\t\tGrade:%s \n\t\tSection:%s \n\t\tAge:%d \n\t\tRegistrationnumber:%ld \n\t\t2Email:%s",
            firstname,lastname,address,phonenumber,gender,grade,section,age,registrationNumber,email
            );
            printf("\n\n");
            results++;
            }  
        }
        if(results==0){
            printf("User with this firstname doesnot exit.\n");
        }

    }
    else if(choice==5){
         char lname[20];
        printf("Enter the firstname.\n");
        scanf("%s",lname);

        FILE *fp;
        fp = fopen("address.txt", "r");

        char firstname[20];
        char lastname[20];
        char address[40];
        long long  phonenumber;
        char gender[20];
        char grade[40];
        char section[20];
        int age;
        long  registrationNumber;
        char email[100];
        int results=0;

        while(fscanf(fp, "Firstname:%s Lastname:%s Address:%s Phonenumber:%lld Gender:%s Grade:%s Section:%s Age:%d Registrationnumber:%ld Email:%s\n",
        firstname,lastname,address,&phonenumber,gender,grade,section,&age,&registrationNumber,email
        )!=EOF){
            // printf("%d",compare(fname,firstname));
            if(compare(lname,lastname)==1){
            printf("\t\t");
            printf("---------------------------");
            printf("\n\n");
            printf("\t\t");
            printf("Firstname:%s \n\t\tLastname:%s \n\t\tAddress:%s \n\t\tPhonenumber:%lld \n\t\tGender:%s \n\t\tGrade:%s \n\t\tSection:%s \n\t\tAge:%d \n\t\tRegistrationnumber:%ld \n\t\t2Email:%s",
            firstname,lastname,address,phonenumber,gender,grade,section,age,registrationNumber,email
            );
            printf("\n\n");
            results++;
            }  
        }
        if(results==0){
            printf("User with this lastname doesnot exit.\n");
        }

    }
    else
    {
        printf("Please choose the correct option.(You can only choose between 1,2 and 3.)\n");
        goto label;
    }
    return 0;
}