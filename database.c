#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>


//REPLACE THIS PATH WITH THE DESIRED PATH IN YOUR DEVICE
char path[100]="/home/yugal/Desktop/C_Project/";
// FOR EXAMPLE
// char path[100]="/home/whoever/asdfsdf/....."

int isLoggedIn = 0;
char USERNAME[50];
int cont;
int found = 1;
char finalAdd[400];

int lengthOfArrayOfStrings(char array[100][40])
{

    int length = 0, i = 0;
    while (strcmp(array[i], "\n") == 0)
    {
        i++;
        length++;
    }

    return length;
}

/////
// SPLIT BY SPACE
////
int splitBySpace(char splitStrings[100][40], char *string, int length)
{

    int i, j, cnt;

    j = 0;
    cnt = 0;
    for (i = 0; i <= length; i++)
    {
        // if space or NULL found, assign NULL into splitStrings[cnt]
        if (string[i] == ' ' || string[i] == '\0')
        {
            splitStrings[cnt][j] = '\0';
            cnt++; //for next word
            j = 0; //for next word, init index to 0
        }
        else
        {
            splitStrings[cnt][j] = string[i];
            j++;
        }
    }

    return cnt;
}

/////
// SPLIT BY SLASH
////
int splitBySlashAndAngularBracket(char splitStrings[100][40], char *string, int length)
{

    int i, j, cnt;

    j = 0;
    cnt = 0;
    for (i = 1; i < length; i++)
    {
        // if space or NULL found, assign NULL into splitStrings[cnt]
        if (string[i] == '|' || string[i] == '>')
        {
            splitStrings[cnt][j] = '\0';
            cnt++; //for next word
            j = 0; //for next word, init index to 0
        }
        else
        {
            splitStrings[cnt][j] = string[i];
            j++;
        }
    }

    return cnt;
}

/////
// SPLIT BY ANDPERCENT
////
int splitByAndAndPercentAngularBracket(char splitStrings[100][40], char *string, int length)
{

    int i, j, cnt;

    j = 0;
    cnt = 0;
    for (i = 1; i < length; i++)
    {
        // if space or NULL found, assign NULL into splitStrings[cnt]
        if (string[i] == '&' || string[i] == '>')
        {
            splitStrings[cnt][j] = '\0';
            cnt++; //for next word
            j = 0; //for next word, init index to 0
        }
        else
        {
            splitStrings[cnt][j] = string[i];
            j++;
        }
    }

    return cnt;
}

/////
// SPLITTING BY COLON
////
int splitByColon(char splitStrings[50][50], char *string, int length)
{

    int i, j, cnt;

    j = 0;
    cnt = 0;
    for (i = 0; i <= length; i++)
    {
        // if space or NULL found, assign NULL into splitStrings[cnt]
        if (string[i] == ':' || string[i] == '\0')
        {
            splitStrings[cnt][j] = '\0';
            cnt++; //for next word
            j = 0; //for next word, init index to 0
        }
        else
        {
            splitStrings[cnt][j] = string[i];
            j++;
        }
    }

    return cnt;
}

/////
// CREATING USER
////
void constructUser(char *username, char *password)
{

    FILE *fp;
    FILE *fpr;
    fp = fopen("users.txt", "a");
    fpr = fopen("users.txt", "r");
    long ID;
    char PASSWORD[50];
    char uname[20];

    while (fscanf(fpr, "_id : %d , username : %s , password : %s\n", &ID, uname, PASSWORD) != EOF)
    {
        if (strcmp(username, uname) == 0)
        {
            fclose(fpr);
            found = 0;
            break;
        }
        else
        {
            found = 1;
        }
    }

    int rand_num;
    srand(time(0));
    rand_num = rand();

    if (found == 1)
    {

        fprintf(fp, "_id : %d , username : %s , password : %s\n", rand_num, username, password);
        fclose(fp);
    }
    else
    {
        printf("User with this username already exits.\n");
    }
}

/////
// CHECK IS USER ALREADY EXISTS
////
void findUser(char *Username, char *password)
{

    FILE *fp;
    FILE *finduserfile;
    fp = fopen("users.txt", "r");

    long ID;
    char PASSWORD[50];
    char username[50];
    int results = 0;
    while (fscanf(fp, "_id : %d , username : %s , password : %s\n", &ID, username, PASSWORD) != EOF)
    {
        if (strcmp(Username, username) == 0 && strcmp(PASSWORD, password) == 0)
        {

            results++;
            isLoggedIn = 1;
            strcpy(USERNAME, username);
            finduserfile = fopen(("%s", USERNAME), "r");
            // if(finduserfile==NULL){
            //     mkdir((path,USERNAME),0777);
            //     }
            break;
        }
    }
    if (results == 0)
    {

        printf("Incorrect username or password.\n");
    }

    fclose;
}

/////
// CREATING DATABASE
////
void creatingDatabase(char *string, int length)
{
    char construct[100] = "construct";
    char database[100] = "database";

    char splitStrings[100][40]; //can store 100 words of 140 characters
    splitBySpace(splitStrings, string, length);

    if (strcmp(construct, splitStrings[0]) >= 0 && strcmp(database, splitStrings[1]) >= 0)
    {
        int check;

        char address[400];

        strcpy(address, path);
        strcat(address, USERNAME);
        strcat(address, "/");
        mkdir(address, 0777);
        strcat(address, ("%s", splitStrings[2]));

        strcpy(finalAdd, address);
        FILE *fp, *databasefolder;
        mkdir(finalAdd, 0700);
        fclose;
    }
};

/////
// CREATING TABLE
////
void creatingdocument(char *string, char *database, int length)
{
    char construct[100] = "construct";
    char document[100] = "document";
    char documentName[100];
    char splitStrings[100][40]; //can store 100 words of 140 characters
    splitBySpace(splitStrings, string, length);

    strcpy(documentName, splitStrings[2]);
    char nameoffile[400];
    FILE *fp;
    FILE *fordocument;
    if (strcmp(construct, splitStrings[0]) >= 0 && strcmp(document, splitStrings[1]) >= 0)
    {
        strcpy(nameoffile, path);
        strcat(nameoffile, USERNAME);
        strcat(nameoffile, "/");
        strcat(nameoffile, database);
        strcat(nameoffile, "/");
        strcat(nameoffile, documentName);
        fordocument = fopen(nameoffile, "a");
        fclose(fordocument);
    };
};

/////
// WRITING DATA TO DATABASE
////
void feedTodocument(char *string, char *database, int length)
{
    char nameoffile[400];
    char documentname[100];
    FILE *document;
    int fp = 10;
    char splitStrings[100][40]; //can store 100 words of 140 characters
    splitBySpace(splitStrings, string, length);

    strcpy(documentname, splitStrings[2]);
    strcpy(nameoffile, path);
    strcat(nameoffile, USERNAME);
    strcat(nameoffile, "/");
    strcat(nameoffile, database);
    strcat(nameoffile, "/");
    strcat(nameoffile, documentname);
    // fclose(fp);
    document = fopen(nameoffile, "a");

    if (fp == 19)
    {
    }
    else
    {
        char documentItems[100][40]; //can store 100 words of 140 characters
        int i, j, count;
        j = 0;
        count = 0;
        int length = strlen(splitStrings[3]);
        for (i = 1; i < length; i++)
        {
            // if space or NULL found, assign NULL into splitStrings[cnt]
            if (splitStrings[3][i] == ',' || splitStrings[3][i] == '>')
            {
                documentItems[count][j] = '\0';
                count++; //for next word
                j = 0;   //for next word, init index to 0
            }
            else
            {
                documentItems[count][j] = splitStrings[3][i];
                j++;
            }
        }
        int rand_num;
        srand(time(0));
        rand_num = rand();

        fprintf(document, "_id:%d ", rand_num);

        for (int m = 0; m < count; m++)
        {
            fprintf(document, "%s ", documentItems[m]);
        }
        fprintf(document, "-");
        fprintf(document, "\n");
        fclose(document);
    }
};

/////
// SORT ASCENDING
////
void sortAscending(char list3D[3000][50][50], char *fieldName, int row, int column)
{

    char fieldsAndValues[50][50];
    char fieldsAndNextValues[50][50];
    char findFieldLocation[50][50];
    int field;


        

        for (int i = 0; i < column; i++)
        {
            splitByColon(findFieldLocation, list3D[0][i], strlen(list3D[0][i]));
            if((strcmp(findFieldLocation[0],fieldName)==0)){
                field=i;
                break;
            }
        }
    



    for (int m = 0; m < row - 1; m++)
    {

        for (int i = 0; i < row - m - 1; i++)
        {

            splitByColon(fieldsAndValues, list3D[i][field], strlen(list3D[i][0]));
            splitByColon(fieldsAndNextValues, list3D[i + 1][field], strlen(list3D[i + 1][0]));
            int x = 0;
            while (fieldsAndValues[1][x] == fieldsAndNextValues[1][x])
            {
                x++;
            }

            if (fieldsAndValues[1][x] > fieldsAndNextValues[1][x])
            {

                for (int a = 0; a < column; a++)
                {
                    char temp[40];
                    strcpy(temp, list3D[i][a]);
                    strcpy(list3D[i][a], list3D[i + 1][a]);
                    strcpy(list3D[i + 1][a], temp);
                }
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        printf("\t\t\t\t\t\t\t\t\t\t");
        printf("(%d)\n", i + 1);
        for (int j = 0; j < column; j++)
        {
            printf("\t\t\t\t\t\t\t\t\t\t");

            printf("%s \n", list3D[i][j]);
        }
        printf("\t\t\t\t\t\t\t\t\t\t");

        printf("-----------------------------\n");
    }

    printf("\n\n");
}


/////
// SORT DESCENDING
////
void sortDesending(char list3D[3000][50][50], char *fieldName, int row, int column)
{

    char fieldsAndValues[50][50];
    char fieldsAndNextValues[50][50];
    char findFieldLocation[50][50];
    int field;

        for (int i = 0; i < column; i++)
        {
            splitByColon(findFieldLocation, list3D[0][i], strlen(list3D[0][i]));
            if((strcmp(findFieldLocation[0],fieldName)==0)){
                field=i;
                break;
            }
        }
    



    for (int m = 0; m < row - 1; m++)
    {

        for (int i = 0; i < row - m - 1; i++)
        {

            splitByColon(fieldsAndValues, list3D[i][field], strlen(list3D[i][0]));
            splitByColon(fieldsAndNextValues, list3D[i + 1][field], strlen(list3D[i + 1][0]));
            int x = 0;
            while (fieldsAndValues[1][x] == fieldsAndNextValues[1][x])
            {
                x++;
            }

            if (fieldsAndValues[1][x] < fieldsAndNextValues[1][x])
            {

                for (int a = 0; a < column; a++)
                {
                    char temp[40];
                    strcpy(temp, list3D[i][a]);
                    strcpy(list3D[i][a], list3D[i + 1][a]);
                    strcpy(list3D[i + 1][a], temp);
                }
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        printf("\t\t\t\t\t\t\t\t\t\t");
        printf("(%d)\n", i + 1);
        for (int j = 0; j < column; j++)
        {
            printf("\t\t\t\t\t\t\t\t\t\t");

            printf("%s \n", list3D[i][j]);
        }
        printf("\t\t\t\t\t\t\t\t\t\t");

        printf("-----------------------------\n");
    }

    printf("\n\n");
}

/////
// RETRIVE FROM  DOCUMENT
////
void showFromdocument(char *string, char *database, int length)
{
    {
        char nameoffile[400];
        char documentname[100];
        char allData[500];

        FILE *document;
        int fp = 10;
        char splitStrings[100][40]; //can store 100 words of 140 characters
        int cnt = splitBySpace(splitStrings, string, length);

        strcpy(documentname, splitStrings[2]);
        strcpy(nameoffile, path);
        strcat(nameoffile, USERNAME);
        strcat(nameoffile, "/");
        strcat(nameoffile, database);
        strcat(nameoffile, "/");
        strcat(nameoffile, documentname);
        document = fopen(nameoffile, "r");

        if (document == NULL)
        {

            printf("%s document doesnot exist.Please check the name of the document correctly.\n", splitStrings[2]);
        }
        else
        {

            char space;
            int found = 0;

            printf("\t\t\t\t\t\t\t\t\t\t");
            printf("-----------------------------\n");
            if (cnt == 3)
            {

                while (fscanf(document, "%s", allData) != EOF)
                {

                    if (strcmp(allData, "-") == 0)
                    {
                        printf("\t\t\t\t\t\t\t\t\t\t");

                        printf("----------------------------\n\n");
                    }
                    else
                    {
                        printf("\t\t\t\t\t\t\t\t\t\t");
                        printf("%s\n", allData);
                    }
                }
                printf("\n\n");
            }
            else if (cnt == 4)
            {
                char datas[500][500];
                char newDatas[500][500];
                char arraySplitByComma[100][40];
                int length = splitBySlashAndAngularBracket(arraySplitByComma, splitStrings[3], strlen(splitStrings[3]));
                int len = splitByAndAndPercentAngularBracket(arraySplitByComma, splitStrings[3], strlen(splitStrings[3]));

                int found = 0, end = 0;
                int i = 0, a = 0;
                while (fscanf(document, "%s", allData) != EOF)
                {

                    if (strcmp(allData, "-") == 0)
                    {
                        end = 1;
                    }
                    else
                    {
                        strcpy(datas[i], allData);
                        i++;
                    }

                    if (length > 0)
                    {
                        if (
                            (strcmp(allData, arraySplitByComma[0]) == 0)
                            // ||
                            // (strcmp(allData, arraySplitByComma[1]) == 0) ||
                            // (strcmp(allData, arraySplitByComma[2]) == 0)
                        )
                        {
                            a++;
                            found = 1;
                        }

                        if (found == 0 && end == 1)
                        {
                            i = 0, end = 0;
                        }

                        if (found == 1 && end == 1)
                        {
                            // printf("\t\t\t\t\t\t\t\t\t\t");

                            for (int k = 0; k < i; k++)
                            {
                                printf("\t\t\t\t\t\t\t\t\t\t");

                                printf("%s\n", datas[k]);
                            }
                            printf("\t\t\t\t\t\t\t\t\t\t");
                            printf("---------------------------\n");
                            i = 0, end = 0, found = 0, a = 0;
                        }
                    }
                }
            }

            else if (cnt == 5 || cnt==6)
            {

                char twoD_for_Name[50][50];
                char threeD_for_Name[3000][50][50];
                int i = 0, j = 0, length = 0, row = 0, column = 0, col = 0;
                while (fscanf(document, "%s", allData) != EOF)
                {
                    if (strcmp(allData, "-") != 0)
                    {
                        strcpy(threeD_for_Name[row][column], allData);
                        column++;
                    }
                    else
                    {
                        j = 1;
                    }

                    if (j == 1)
                    {
                        row++;
                        j = 0;
                        col = column;
                        column = 0;
                    }
                }

                if(strcmp(splitStrings[5],"a")==0){
                sortAscending(threeD_for_Name, splitStrings[4], row, col);
                }else if(strcmp(splitStrings[5],"d")==0){
                sortDesending(threeD_for_Name, splitStrings[4], row, col);
                }else{

                }
            }

            else
            {
            }
        }
    }
}

/////
// UPDATING DOCUMENT
////
void updateFromdocument(char *string, char *database, int length)
{
    // printf("%s\n", string);
    char nameoffile[400];
    char documentname[100];
    char allData[200];
    char filedName[200];
    char intials[10];
    char tempFile[100];
    char renameCurrent[100];
    char newCurrent[100];
    char uname[100];
    strcpy(uname, USERNAME);

    FILE *document;
    int fp = 10;
    char splitStrings[100][40]; //can store 100 words of 140 characters
    splitBySpace(splitStrings, string, length);

    // printf("%s %s %s %s %s.\n", splitStrings[0], splitStrings[1], splitStrings[2], splitStrings[3], splitStrings[4]);

    strcpy(documentname, splitStrings[1]);
    strcpy(nameoffile, path);
    strcat(nameoffile, uname);
    strcat(nameoffile, "/");
    strcat(nameoffile, database);
    strcat(nameoffile, "/");
    strcat(nameoffile, documentname);
    document = fopen(nameoffile, "r+");

    int found = 0;
    FILE *temp;

    strcpy(tempFile, USERNAME);
    strcat(tempFile, "/");
    strcat(tempFile, database);
    strcat(tempFile, "/");

    strcpy(renameCurrent, tempFile);
    strcat(renameCurrent, documentname);

    strcpy(newCurrent, tempFile);
    strcat(newCurrent, "101458");

    strcat(tempFile, "Temporary");

    temp = fopen(tempFile, "a");

    rename(renameCurrent, newCurrent);

    while (fscanf(document, "%s", allData) != EOF)
    {
        char dataKey[50][50];
        splitByColon(dataKey, allData, strlen(allData));
        if (allData[0] == '_')
        {
            strcpy(filedName, allData);
        }
        if (strcmp(allData, "-") == 0)
        {
            fprintf(temp, "-");
            fprintf(temp, "\n");
        }
        else
        {
            if ((strcmp(filedName, splitStrings[2])) == 0 && strcmp(dataKey[0], splitStrings[3]) == 0)
            {
                fprintf(temp, "%s ", strcat(strcat(dataKey[0], ":"), splitStrings[4]));
            }
            else
            {
                fprintf(temp, "%s ", allData);
            }
        }
    }
    remove(newCurrent);
    rename(tempFile, renameCurrent);
    fclose(temp);
    fclose(document);
}

/////
// DELETE FROM  DOCUMENT
////
void deleteFromdocument(char *string, char *database, int length)
{
    char nameoffile[400];
    char documentname[100];
    char allData[200];
    char filedName[200];
    char intials[10];
    char tempFile[100];
    char renameCurrent[100];
    char newCurrent[100];
    char uname[100];
    strcpy(uname, USERNAME);

    FILE *document;
    int fp = 10;
    char splitStrings[100][40]; //can store 100 words of 140 characters
    splitBySpace(splitStrings, string, length);

    // printf("%s %s %s %s %s.\n", splitStrings[0], splitStrings[1], splitStrings[2], splitStrings[3], splitStrings[4]);

    strcpy(documentname, splitStrings[1]);
    strcpy(nameoffile, path);
    strcat(nameoffile, uname);
    strcat(nameoffile, "/");
    strcat(nameoffile, database);
    strcat(nameoffile, "/");
    strcat(nameoffile, documentname);
    document = fopen(nameoffile, "r+");

    int found = 0;
    FILE *temp;

    strcpy(tempFile, USERNAME);
    strcat(tempFile, "/");
    strcat(tempFile, database);
    strcat(tempFile, "/");

    strcpy(renameCurrent, tempFile);
    strcat(renameCurrent, documentname);

    strcpy(newCurrent, tempFile);
    strcat(newCurrent, "101458");

    strcat(tempFile, "Temporary");

    temp = fopen(tempFile, "a");

    rename(renameCurrent, newCurrent);

    while (fscanf(document, "%s", allData) != EOF)
    {
        if (allData[0] == '_')
        {
            strcpy(filedName, allData);
        }
        if (strcmp(filedName, splitStrings[2]) == 0)
        {
        }
        else
        {
            if (strcmp(allData, "-") == 0)
            {
                fprintf(temp, "-");
                fprintf(temp, "\n");
            }
            else
            {
                fprintf(temp, "%s ", allData);
            }
        }
    }

    remove(newCurrent);
    rename(tempFile, renameCurrent);
    fclose(temp);
    fclose(document);
}






int main()
{
    long id;
    char password[50];
    char username[20];
    char choice[50];
    int mode;
    char string[50];
    char gointo[100] = "gointo";

    printf("Welcome to our database.\n");
    printf("------------------\n");
    printf("Login Or Register : \n");
    scanf("%s", choice);

    printf("\n");
    printf("-------------\n");
    if (strcmp(choice, "login") == 0)
    {
    login:
        printf("LOGIN\n");
        printf("Enter your username :\n");
        scanf("%s", username);
        printf("Enter your password : \n");
        scanf("%s", password);
        // password=getch()
        findUser(username, password);
        if (isLoggedIn == 0)
        {
            goto login;
        }
    }
    else if (strcmp(choice, "register") == 0)
    {
        printf("Enter your username : \n");
        scanf("%s", username);
        printf("Enter your password : \n");
        scanf("%s", password);
        constructUser(username, password);
        int result = mkdir(("%s", USERNAME), 0777);
        if (found == 1)
        {
            goto login;
        }
    }
    else
    {
    }

    if (isLoggedIn == 1 && strlen(USERNAME) > 0)
    {
        printf("\t\t\t\t\t\t\t");
        printf("--------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t");
        printf("|                             WELCOME %s                              |\n", USERNAME);
        printf("\t\t\t\t\t\t\t");
        printf("--------------------------------------------------------------------------\n");

        //FOR DEVELOPER'S MODE

        if (mode == 0)
        {
            char a[500];
            struct dirent *de; // Pointer for directory entry

        comebackup:

            printf("--->\n");

            for (int i = 0; i < 500; i++)
            {
                scanf("%c", &a[i]);

                if (a[i] == 59)
                {
                    a[i] = '\0';
                    break;
                }
            }
            a[0] = '#';
            if (strcmp(a, "#listdb") == 0)
            {
                char location[500];
                strcpy(location, path);
                strcat(location, USERNAME);
                DIR *dr = opendir(location);

                if (dr == NULL)
                {
                    printf("You have not created any database yet.\n");

                    goto comebackup;
                }

                printf("\t\t\t\t\t\t\t\t\t\t");

                printf("---------------------\n");

                while ((de = readdir(dr)) != NULL)
                {

                    if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0)
                    {
                    }
                    else
                    {
                        printf("\t\t\t\t\t\t\t\t\t\t");
                        printf("%s \n", de->d_name);
                    }
                }
                printf("\t\t\t\t\t\t\t\t\t\t");

                printf("---------------------\n");
                closedir(dr);
                goto comebackup;
            }

            else if (a[0] == 'c' || a[1] == 'c')
            {
                creatingDatabase(a, strlen(a));
                goto comebackup;
            }

            else if (a[0] == 'g' || a[1] == 'g')
            {
                // char string[100]=a
                char splitStrings[100][40]; //can store 100 words of 140 characters
                int i, j, cnt;

                j = 0;
                cnt = 0;
                for (i = 0; i <= strlen(a); i++)
                {
                    // if space or NULL found, assign NULL into splitStrings[cnt]
                    if (a[i] == ' ' || a[i] == '\0')
                    {
                        splitStrings[cnt][j] = '\0';
                        cnt++; //for next word
                        j = 0; //for next word, init index to 0
                    }
                    else
                    {
                        splitStrings[cnt][j] = a[i];
                        j++;
                    }
                }
                FILE *fp;
                char add[400];
                char uname[100];
                char dbName[100];
                strcpy(uname, USERNAME);
                strcpy(dbName, splitStrings[1]);
                int check;
                strcpy(add, path);
                strcat(add, USERNAME);
                strcat(add, "/");
                strcat(add, splitStrings[1]);

                DIR *dir = opendir(add);
                if (dir)
                {

                insidedb:
                    char document[500];
                    printf("-- %s >\n", splitStrings[1]);
                    for (int i = 0; i < 100; i++)
                    {
                        scanf("%c", &document[i]);
                        if (document[i] == 59)
                        {
                            document[i] = '\0';
                            break;
                        }
                    }
                    document[0] = '#';

                    char location[500];
                    strcpy(location, path);
                    strcat(location, USERNAME);
                    strcat(location, "/");
                    strcat(location, splitStrings[1]);

                    if (strcmp(document, "#listdocu") == 0)
                    {
                        DIR *dr = opendir(location);

                        if (dr == NULL)
                        {
                            printf("Could not open the database.\n");
                            return 0;
                        }
                        printf("\t\t\t\t\t\t\t\t\t\t");

                        printf("---------------------\n");
                        while ((de = readdir(dr)) != NULL)
                        {

                            if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0)
                            {
                            }
                            else
                            {
                                printf("\t\t\t\t\t\t\t\t\t\t");
                                printf("%s \n", de->d_name);
                            }
                        }
                        printf("\t\t\t\t\t\t\t\t\t\t");

                        printf("---------------------\n");

                        closedir(dr);

                        goto insidedb;
                    }
                    else if (document[0] == 'c' || document[1] == 'c')
                    {
                        creatingdocument(document, splitStrings[1], strlen(document));
                        goto insidedb;
                    }
                    else if (document[0] == 'f' || document[1] == 'f')
                    {
                        feedTodocument(document, dbName, strlen(document));
                        goto insidedb;
                    }
                    else if (document[0] == 's' || document[1] == 's')
                    {
                        showFromdocument(document, dbName, strlen(document));
                        goto insidedb;
                    }
                    else if (document[0] == 'm' || document[1] == 'm')
                    {
                        updateFromdocument(document, dbName, strlen(document));
                        goto insidedb;
                    }
                    else if (document[0] == 'd' || document[1] == 'd')
                    {
                        deleteFromdocument(document, dbName, strlen(document));
                        goto insidedb;
                    }

                    else if (document[0] == 'j' || document[1] == 'j')
                    {
                        goto comebackup;
                    }
                   else if (document[0]=='x' || document[1]=='x')
                    {
                        system("clear");
                        goto insidedb;   
                    }
                    else
                    {
                        printf("Something is wrong in this statement.\n");
                        goto insidedb;
                    }
                }
                else if (ENOENT == errno)
                {
                    printf("This database doesnot exist.\n");
                    goto comebackup;
                }
                else
                {
                    /* opendir() failed for some other reason. */
                }
                // closedir(add);
            }
            else if (a[0] == 'e' || a[1] == 'e')
            {
                goto comebackup;
            }
            else
            {
                printf("Something wrong in this statement.\n");
                goto comebackup;
            }
        }

        //FOR GENERAL MODE
        else
        {
        }
    }
    return 0;
}