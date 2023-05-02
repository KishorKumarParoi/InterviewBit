#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
// #include<conio.h>
#include <time.h>
#include<stdlib.h>
// #include<windows.h>
#include<stdbool.h>

// This structure work to get time

struct times
{
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliSecond;
};

typedef struct times Times;

// This structure work to get admin account information

struct account
{
    char userName[20];
    char password[20];

};
typedef struct account Account;

// this structure work to get daily update information
struct dailyCount
{
    Times entryTime;
    Times exitTime;
    int hour;
    int min;
    double dailyIncome;
};


typedef struct dailyCount Day;

//Here all new employee all information add this structure

struct Employees
{
    char first_name[20];
    char last_name[20];
    char id[15];
    char email[30];
    char phoneNumber[15];
    char designation[20];
    double per_rate;
    double over_time_rate;
    int monthly_target_hour;
    double monthly_bonus_income;
    Day dayStatistics[32];
    // double dailyWorkHour[32];

};
typedef struct Employees Employee;



struct node
{
    Employee member;
    struct node *next;
};
typedef struct node snode;

COORD coord = {0,0};
void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//<function prototype>

void logInMenue();
void mainMenue();
void employeeMenue();
void updateMenu();
void salaryMenu();
int userNameTest(char name[20]);
void signUpAccount();
int logInAccount(char username[20],char pass[20]);
int checkAccount();
int checkCofirmation();
//File Function
void addminWriteData();
void adminReadFileData();
void employeeWriteFile();
void employeeReadFile();
void writeFilePerEmployee(char id[]);
void readAllEmployeeFile();
void reportFileWrite();
//File Function

snode* createNode(Employee emp);
void AddEmployeeLast(Employee list);
void createEmployeeList();

// all display function
void all_employe_display();
void search_employee_Display(char id[]);
void view_employee_personal_info(char id[]);
void search_employee_Display_no_2(char id[]);
void employee_per_month_salary_view();
void per_employee_salary_view(char id[]);
void dailyEarningMessageDisplay(char id[]);

//<start time function
Times getTimes();
Times getCurrentTime();
int timeCorrection(int hour);
 //<end time function

int isIdCompare(char id[]);
void deleteEmployeeInformation(char id[]);
void employee_personal_information_update(char id[]);
void perDayUpdate(int type);
double perDayTimeHourCount(int h1,int m1,int h2,int m2,int position);
double perDayEarningCount(int tmHour,int tmMin,int position);
int calculatePresent(char id[]);
int calculateAbsence(char id[]);
int gmailVerified(char ch[]);
int numberFormateCorrection(char arr[]);
double baseSalaryCalculate(char id[]);
int totalHourWork(char id[]);
int totalMin(char id[]);
double bonusSalaryCalculate();
double totalMonthlySalary(char id[]);
void maintainMainMenu();

//</end function prototype>

//<Variable>

snode *newnode;
snode *head = NULL;
int currentMonthDay;
char accountName[20];
Account firstAccount[50];
int start = 0;
bool checkWriteData = false;
//</variable>

/*This is the log in display menu*/
void logInMenue()
{
    system("cls");
    int i;
    gotoxy(33,4);
    for(i=0; i<55; i++)
    {
        printf("%c",240);
    }
    gotoxy(40,6);
    printf("Welcome to the Employee Management System");
    gotoxy(33,8);
    for(i=0; i<55; i++)
    {
        printf("%c",240);
    }

    gotoxy(45,12);
    printf("%c  1  %c   Admin Login ",178,178);
    gotoxy(45,14);
    printf("%c  2  %c   New Admin Sign Up",178,178);
    gotoxy(45,16);
    printf("%c  3  %c   Exit management system\n",178,178);
}
//This is my project main menu
void mainMenue()
{
    system("cls");
    int i,j;
    gotoxy(53,4);
    printf("MAIN MENUE");
    gotoxy(33,6);
    for(i=0; i<50; i++)
    {
        printf("%c",240);
    }
    gotoxy(30,8);
    for(i=0; i<55; i++)
    {
        printf("%c",177);
    }
    gotoxy(45,12);
    printf("%c  1  %c      Employee",178,178);
    gotoxy(45,14);
    printf("%c  2  %c      Update",178,178);
    gotoxy(45,16);
    printf("%c  3  %c      Salary",178,178);
    gotoxy(45,18);
    printf("%c  4  %c      Log Out",178,178);

    for(j=9; j<21; j++)
    {
        gotoxy(30,j);
        printf("%c",178);
        gotoxy(84,j);
        printf("%c",178);
    }
    gotoxy(30,21);
    for(i=0; i<55; i++)
    {
        printf("%c",177);
    }
    printf("\n\n");
}

// This function work to display employee menu

void employeeMenue()
{
    system("cls");
    int i,j;
    gotoxy(49,2);
    printf("Welcome Employee Menu");
    gotoxy(33,4);
    for(i=0; i<50; i++)
    {
        printf("%c",240);
    }
    gotoxy(30,6);
    for(i=0; i<55; i++)
    {
        printf("%c",177);
    }
    gotoxy(45,8);
    printf("%c  1  %c      Add New Employee",178,178);
    gotoxy(45,10);
    printf("%c  2  %c      Search Employee",178,178);
    gotoxy(45,12);
    printf("%c  3  %c      Personal Info",178,178);
    gotoxy(45,14);
    printf("%c  4  %c      View Employees",178,178);
    gotoxy(45,16);
    printf("%c  5  %c      Delete Employees",178,178);
    gotoxy(45,18);
    printf("%c  6  %c      Go to Main Menu",178,178);

    for(j=7; j<21; j++)
    {
        gotoxy(30,j);
        printf("%c",178);
        gotoxy(84,j);
        printf("%c",178);
    }
    gotoxy(30,21);
    for(i=0; i<55; i++)
    {
        printf("%c",177);
    }
    printf("\n\n");

}

// Thsi function work to display update menu

void updateMenu()
{

    system("cls");
    int i,j;
    gotoxy(53,4);
    printf("UPDATE MENU");
    gotoxy(33,6);
    for(i=0; i<50; i++)
    {
        printf("%c",240);
    }
    gotoxy(30,8);
    for(i=0; i<55; i++)
    {
        printf("%c",177);
    }
    gotoxy(45,12);
    printf("%c  1  %c      Entry Time",178,178);
    gotoxy(45,14);
    printf("%c  2  %c      Exit Time",178,178);
    gotoxy(45,16);
    printf("%c  3  %c      Absence",178,178);
    gotoxy(45,18);
    printf("%c  4  %c      Go To Main Menu",178,178);

    for(j=9; j<21; j++)
    {
        gotoxy(30,j);
        printf("%c",178);
        gotoxy(84,j);
        printf("%c",178);
    }
    gotoxy(30,21);
    for(i=0; i<55; i++)
    {
        printf("%c",177);
    }
    printf("\n\n");
}

// This function work to display salary menu

void salaryMenu()
{
    system("cls");
    int i,j;
    gotoxy(53,4);
    printf("SALARY MENU");
    gotoxy(33,6);
    for(i=0; i<50; i++)
    {
        printf("%c",240);
    }
    gotoxy(30,8);
    for(i=0; i<55; i++)
    {
        printf("%c",177);
    }
    gotoxy(45,12);
    printf("%c  1  %c      Individual Salary View",178,178);
    gotoxy(45,14);
    printf("%c  2  %c      All Employee Salary View",178,178);
    gotoxy(45,16);
    printf("%c  3  %c      Monthly Report File",178,178);
    gotoxy(45,18);
    printf("%c  4  %c      Go To Main Menu",178,178);

    for(j=9; j<21; j++)
    {
        gotoxy(30,j);
        printf("%c",178);
        gotoxy(84,j);
        printf("%c",178);
    }
    gotoxy(30,21);
    for(i=0; i<55; i++)
    {
        printf("%c",177);
    }
    printf("\n\n");

}
// Thsi function work to test user name

int userNameTest(char name[20])
{
    int i,flag = -1;
    if(start == 0) return -1;
    for(i=0; i<start; i++)
    {
        if(strcmp(firstAccount[i].userName,name)==0)
        {
            flag = 1;
            break;
        }
    }

    return flag;
}

// Thsi function work to create account

void signUpAccount()
{
    char ch[20],ch1[20];
    gotoxy(45,10);
    printf("User Name       :    ");
    scanf(" %s",ch);
    int test = userNameTest(ch);
    if(test == -1)
    {
        gotoxy(45,12);
        printf("Enter Password  :    ");
        scanf(" %s",ch1);
        strcpy(firstAccount[start].userName,ch);
        strcpy(firstAccount[start].password,ch1);
        system("cls");
        gotoxy(45,8);
        printf("Your Account Successful");
        gotoxy(45,12);
        printf("User Name    :   %s",firstAccount[start].userName);
        gotoxy(45,14);
        printf("Password     :   %s",firstAccount[start].password);
        gotoxy(45,17);
        printf("press any key and Login your account    ");
        start++;
        addminWriteData();
        getch();
    }
    else
    {
        system("cls");
        gotoxy(45,10);
        printf("This user name already exist\n");
        gotoxy(45,12);
        printf("Press any key go to welcome screen    ");
        getch();
    }

}

int logInAccount(char username[20],char pass[20])
{
    int i,flag = -1;
    for(i=0; i<start; i++)
    {
        if(strcmp(firstAccount[i].userName,username)==0  && strcmp(firstAccount[i].password,pass)==0)
        {
            flag = 1;
            break;
        }
    }

    return flag;
}

int checkAccount()
{
    system("cls");
    char pass[20];
    gotoxy(45,10);
    printf("User Name  :  ");
    scanf(" %[^\n]",accountName);
    gotoxy(45,12);
    printf("Password   :  ");
    scanf(" %[^\n]",pass);
    int result = logInAccount(accountName,pass);
    return result;
}

int checkCofirmation()
{
    system("cls");
    char pass[20];
    gotoxy(45,12);
    printf("Password   :  ");
    scanf(" %[^\n]",pass);
    int result = logInAccount(accountName,pass);
    return result;
}


//<start file>

void addminWriteData()
{
    FILE *file;
    int i;
    file = fopen("adminaccount.txt","w");
    if(file == NULL)
    {

        exit(1);
    }
    for(i=0; i<start; i++)
    {
        fprintf(file,"%s %s ",firstAccount[i].userName,firstAccount[i].password);
    }
    fclose(file);
}

void adminReadFileData()
{
    FILE *file;
    file = fopen("adminaccount.txt","r");
    char name[20];
    char password[20];
    if(file == NULL)
    {
        file = fopen("adminaccount.txt","w");
        if(file == NULL)
        {
            exit(1);
        }
    }

    while(fscanf(file,"%s %s ",name,password) != EOF)
    {
        strcpy(firstAccount[start].userName,name);
        strcpy(firstAccount[start].password,password);
        start++;
    }
    fclose(file);

}


void employeeWriteFile()
{
    FILE *fp;
    snode *temp = head;
    char fileName[25];
    int i;
    fp = fopen("allemployee.txt","w");
    if(fp == NULL)
    {
        exit(1);
    }
    while(temp != NULL)
    {
        fprintf(fp,"%s %s %s %s %s %s %lf %lf %lf %d ",temp->member.first_name,temp->member.last_name,temp->member.id,
                temp->member.email,temp->member.phoneNumber,temp->member.designation,temp->member.per_rate,
                temp->member.over_time_rate,temp->member.monthly_bonus_income,temp->member.monthly_target_hour);

        strcpy(fileName,temp->member.first_name);
        strcat(fileName,".txt");
        FILE *file2;
        file2 = fopen(fileName,"w");
        if(file2 == NULL)
        {
            exit(1);
        }
        for(i=1; i<32; i++)
        {
            fprintf(file2,"%d %d %lf %d %d %d %d %d %d %d ",temp->member.dayStatistics[i].hour,temp->member.dayStatistics[i].min,temp->member.dayStatistics[i].dailyIncome,
                    temp->member.dayStatistics[i].entryTime.wDay,temp->member.dayStatistics[i].entryTime.wHour,temp->member.dayStatistics[i].entryTime.wMinute,
                    temp->member.dayStatistics[i].entryTime.wMonth,temp->member.dayStatistics[i].entryTime.wYear,
                    temp->member.dayStatistics[i].exitTime.wHour,temp->member.dayStatistics[i].exitTime.wMinute);


        }
        fclose(file2);
        temp = temp->next;


    }
    fclose(fp);


}

// this function work for write per employee data by their name
void writeFilePerEmployee(char id[])
{
    snode *temp = head;
    char fileName[25];
    int i;
    while(temp != NULL)
    {
        if(strcmp(temp->member.id,id) == 0)
        {
            strcpy(fileName,temp->member.first_name);
            strcat(fileName,".txt");
            FILE *file2;
            file2 = fopen(fileName,"w");
            if(file2 == NULL)
            {
                exit(1);
            }
            for(i=1; i<32; i++)
            {
                fprintf(file2,"%d %d %lf %d %d %d %d %d %d %d ",temp->member.dayStatistics[i].hour,temp->member.dayStatistics[i].min,temp->member.dayStatistics[i].dailyIncome,
                        temp->member.dayStatistics[i].entryTime.wDay,temp->member.dayStatistics[i].entryTime.wHour,temp->member.dayStatistics[i].entryTime.wMinute,
                        temp->member.dayStatistics[i].entryTime.wMonth,temp->member.dayStatistics[i].entryTime.wYear,
                        temp->member.dayStatistics[i].exitTime.wHour,temp->member.dayStatistics[i].exitTime.wMinute);


            }
            fclose(file2);
        }
        temp = temp->next;
    }

}
//This function work to read all employee data
void readAllEmployeeFile()
{
    FILE *fp;
    snode *temp ;
    Employee list;
    char fileName[25];
    int i;
    fp = fopen("allemployee.txt","r+");
    if(fp == NULL)
    {
        fp = fopen("allemployee.txt","w");
        if(fp == NULL)
        {
            exit(1);
        }
    }
    while( fscanf(fp,"%s %s %s %s %s %s %lf %lf %lf %d ",list.first_name,list.last_name,list.id,
                  list.email,list.phoneNumber,list.designation,&list.per_rate,
                  &list.over_time_rate,&list.monthly_bonus_income,&list.monthly_target_hour) != EOF)
    {

        strcpy(fileName,list.first_name);
        strcat(fileName,".txt");
        FILE *file2;
        file2 = fopen(fileName,"r+");
        if(file2 == NULL)
        {
            exit(1);
        }
        for(i=1; i<32; i++)
        {
            fscanf(file2,"%d %d %lf %d %d %d %d %d %d %d ",&list.dayStatistics[i].hour,&list.dayStatistics[i].min,&list.dayStatistics[i].dailyIncome,
                   &list.dayStatistics[i].entryTime.wDay,&list.dayStatistics[i].entryTime.wHour,&list.dayStatistics[i].entryTime.wMinute,
                   &list.dayStatistics[i].entryTime.wMonth,&list.dayStatistics[i].entryTime.wYear,
                   &list.dayStatistics[i].exitTime.wHour,&list.dayStatistics[i].exitTime.wMinute);


        }
        AddEmployeeLast(list);
        fclose(file2);


    }
    fclose(fp);
}

void reportFileWrite()
{
    FILE *report;
    report = fopen("reportfile.txt","w");
    if(report == NULL)
    {
        exit(1);
    }
    int i,j=12;
    snode *temp = head;
    fprintf(report,"\n\n\n\n%45sEmployee Monthly Record\n\n","");
    fprintf(report,"\nEmployee name");
    fprintf(report,"%8sEmployee ID","");
    fprintf(report,"%6sBase salary","");
    fprintf(report,"%6sOver time","");
    fprintf(report,"%6sTotal Salary","");
    fprintf(report,"%6sTotal Present","");
    fprintf(report,"%6sTotal Absence\n","");
    for(i=0; i< 120; i++)
    {
        fprintf(report,"~");
    }

    while(temp != NULL)
    {
        double base_salary = baseSalaryCalculate(temp->member.id);
        double bonus_salary = bonusSalaryCalculate(temp->member.id);
        double total_salary = totalMonthlySalary(temp->member.id);
        int present = calculatePresent(temp->member.id);
        int absence = calculateAbsence(temp->member.id);

        fprintf(report,"\n%-8s %-10s",temp->member.first_name,temp->member.last_name);
        fprintf(report,"%10s",temp->member.id);
        fprintf(report,"%10s%.3lf $","",base_salary);
        fprintf(report,"%10s%.3lf $","",bonus_salary);
        fprintf(report,"%10s%.3lf $","",total_salary);
        fprintf(report,"%10s%d day","",present);
        fprintf(report,"%12s%d day\n","",absence);
        temp = temp->next;
        j+=2;
    }
    fclose(report);
    gotoxy(40,6);
    printf("You Record file create successful\n");
}


//end file

/*I already used linked list data structure
 * This is the create node function
 * It's create a NewNode
 */
//This function work to create new node
snode* createNode(Employee emp)
{
    newnode = (snode*)malloc(sizeof(snode));
    if(newnode == NULL)
    {
        printf("Memory is not allocated\n");
        return 0;
    }
    newnode->member = emp;
    newnode->next = NULL;
    return newnode;

}


//Thsi function work to add linked list

void AddEmployeeLast(Employee list)
{

    newnode = createNode(list);
    if(head == NULL)
    {
        head = newnode;
        head->next = NULL;
        return;
    }
    snode *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp -> next = newnode;


}

//This function work to create new employee by their details
void createEmployeeList()
{
    int stop;
    Employee emp;
    Times tm = getTimes();
    char first_name[20],last_name[20],email[30],phone[15],designation[20],id[20];
    double rate,over_rate;
    double statistics[32];
    int target_hour,i;
    gotoxy(54,1);
    printf("EMPLOYEE DETAILS");
    gotoxy(35,3);
    for(i=0; i<55; i++)
    {
        printf("%c",240);
    }
    gotoxy(45,6);
    printf("Employee id Number          :     ");
    scanf(" %[^\n]",id);
    int d = isIdCompare(id);
    if(d != -1)
    {
        gotoxy(45,12);
        printf("This id number already exist\n");
        return;
    }
    gotoxy(45,8);
    printf("Employee first name         :     ");
    scanf(" %s",first_name);
    gotoxy(45,10);
    printf("Employee last name          :     ");
    scanf(" %s",last_name);
    while(1)
    {
        gotoxy(45,12);
        printf("Email                       :     ");
        scanf(" %[^\n]",email);
        int check = gmailVerified(email);
        if(check != -1) break;
        printf("\r");
        printf("                    ");

        gotoxy(78,12);
        printf("please verified your email address");
        getch();
        gotoxy(78,12);
        printf("                                   ");


    }

    while(1)
    {
        gotoxy(45,14);
        printf("Phone Number                :     +88 ");
        scanf(" %[^\n]",phone);
        int check = numberFormateCorrection(phone);
        if(check == 11) break;
        printf("\r");
        printf("                    ");
        gotoxy(78,14);
        printf("Invalid mobile number");
        getch();
        gotoxy(78,14);
        printf("                                   ");

    }
    gotoxy(45,16);
    printf("Designation                 :     ");
    scanf(" %[^\n]",designation);
    gotoxy(45,18);
    printf("Employee rate(per hour) $   :     ");
    scanf("%lf",&rate);
    gotoxy(45,20);
    printf("Over time bonus(per hour) $ :     ");
    scanf("%lf",&over_rate);
    gotoxy(45,22);
    printf("Monthly target hour (hh)    :     ");
    scanf("%d",&target_hour);

    for(i=0; i<strlen(designation); i++)
    {
        if(designation[i]==' ')
        {
            designation[i] = '_';
        }

    }

    strcpy(emp.id, id);
    strcpy(emp.first_name,first_name);
    strcpy(emp.last_name,last_name);
    strcpy(emp.email,email);
    strcpy(emp.designation,designation);
    strcpy(emp.phoneNumber,phone);
    emp.per_rate = rate;
    emp.over_time_rate = over_rate;
    emp.monthly_target_hour = target_hour;
    for(i=1; i<32; i++)
    {
        emp.dayStatistics[i].hour = 0;
        emp.dayStatistics[i].min = 0;
        emp.dayStatistics[i].dailyIncome = 0;
        emp.dayStatistics[i].entryTime.wDay = i;
        emp.dayStatistics[i].entryTime.wHour = 0;
        emp.dayStatistics[i].entryTime.wMinute = 0;
        emp.dayStatistics[i].entryTime.wMonth = tm.wMonth;
        emp.dayStatistics[i].entryTime.wYear = tm.wYear;
        emp.dayStatistics[i].exitTime.wDay = i;
        emp.dayStatistics[i].exitTime.wHour = 0;
        emp.dayStatistics[i].exitTime.wMinute = 0;

    }
    AddEmployeeLast(emp);



}


void all_Employe_Display()
{
    system("cls");
    int i,j=8;
    snode *temp = head;
    if(temp == NULL)
    {
        printf("The employee list is empty\n");
    }

    else
    {

        gotoxy(45,1);
        printf("All Employee Information");
        for(i=40; i<75; i++)
        {
            gotoxy(i,2);
            printf("%c",254);
        }
        gotoxy(0,4);
        printf("Employee Name");
        gotoxy(22,4);
        printf("Employee ID");
        gotoxy(44,4);
        printf("Per rate ($)");
        gotoxy(66,4);
        printf("Target Hour (hh)");
        gotoxy(88,4);
        printf("Employee Designation\n");
        for(i=0; i<115; i++)
        {
            gotoxy(i,6);
            printf("%c",247);
        }

        while(temp!= NULL)
        {
            gotoxy(0,j);
            printf("%s %s",temp->member.first_name,temp->member.last_name);
            gotoxy(22,j);
            printf("%s",temp->member.id);
            gotoxy(44,j);
            printf("%.3f",temp->member.per_rate);
            gotoxy(66,j);
            printf("%d",temp->member.monthly_target_hour);
            gotoxy(88,j);
            printf("%s",temp->member.designation);

            temp = temp->next;
            j+=2;
            printf("\n");
        }
        printf("\n");

    }

}

void search_employee_Display(char id[])
{
    system("cls");
    snode *temp = head;

    if(temp != NULL)
    {
        while(temp != NULL)
        {
            if(strcmp(id,temp->member.id)==0)
            {
                int i;
                gotoxy(54,1);
                printf("EMPLOYEE DETAILS ");
                gotoxy(28,3);
                for(i=0; i<75; i++)
                {
                    printf("%c",176);
                }
                gotoxy(38,6);
                printf("Employee name            : \t\t%s %s\n",temp->member.first_name,temp->member.last_name);

                gotoxy(38,8);
                printf("Employee Id              : \t\t%s\n",temp->member.id);
                gotoxy(38,10);
                printf("Email                    : \t\t%s\n",temp->member.email);
                gotoxy(38,12);
                printf("Phone Number             : \t\t%s\n",temp->member.phoneNumber);
                gotoxy(38,14);
                printf("Designation              : \t\t%s\n",temp->member.designation);
                gotoxy(38,16);
                printf("Per rate(per hour)       : \t\t%.3f $",temp->member.per_rate);

                gotoxy(38,18);
                printf("Over time rate(per hour) : \t\t%.3f $",temp->member.over_time_rate);
                gotoxy(38,20);
                printf("Monthly target hour (hh) : \t\t%d  hour\n",temp->member.monthly_target_hour);
                gotoxy(28,20);
                for(i=0; i<75; i++)
                {
                    printf("%c",176);
                }
                gotoxy(8,22);
                printf("Base salary");
                gotoxy(28,22);
                printf("Over time");
                gotoxy(48,22);
                printf("Total Salary");
                gotoxy(68,22);
                printf("Total Present");
                gotoxy(98,22);
                printf("Total Absence");

                double base_salary = baseSalaryCalculate(temp->member.id);
                double bonus_salary = bonusSalaryCalculate(temp->member.id);
                double total_salary = totalMonthlySalary(temp->member.id);
                int present = calculatePresent(temp->member.id);
                int absence = calculateAbsence(temp->member.id);
                gotoxy(8,24);
                printf("%.3lf $",base_salary);
                gotoxy(28,24);
                printf("%.3lf $",bonus_salary);
                gotoxy(48,24);
                printf("%.3lf $",total_salary);
                gotoxy(68,24);
                printf("%d day",present);
                gotoxy(98,24);
                printf("%d day\n",absence);
                gotoxy(05,26);
                for(i=0; i<110; i++)
                {
                    printf("%c",176);
                }

                temp = temp->next;

                return;
            }
            temp = temp->next;
        }
        gotoxy(45,12);
        printf("this id number is not here\n");
    }
    else
    {
        gotoxy(45,12);
        printf("There have no id\n");
    }

}


void view_employee_personal_info(char id[])
{
    system("cls");
    snode *temp = head;
    if(temp != NULL)
    {
        while(temp != NULL)
        {
            if(strcmp(id,temp->member.id)==0)
            {
                int i;
                gotoxy(56,1);
                printf("EMPLOYEE DETAILS ");
                gotoxy(30,3);
                for(i=0; i<75; i++)
                {
                    printf("%c",254);
                }
                gotoxy(45,6);
                printf("Employee name            : \t\t%s %s\n",temp->member.first_name,temp->member.last_name);

                gotoxy(45,8);
                printf("Employee Id              : \t\t%s\n",temp->member.id);
                gotoxy(45,10);
                printf("Email                    : \t\t%s\n",temp->member.email);
                gotoxy(45,12);
                printf("Phone Number             : \t\t%s\n",temp->member.phoneNumber);
                gotoxy(45,14);
                printf("Designation              : \t\t%s\n",temp->member.designation);
                gotoxy(45,16);
                printf("Per rate(per hour)       : \t\t%.3f $",temp->member.per_rate);

                gotoxy(45,18);
                printf("Over time rate(per hour) : \t\t%.3f $",temp->member.over_time_rate);
                gotoxy(45,20);
                printf("Monthly target hour (hh) : \t\t%d  hour\n",temp->member.monthly_target_hour);

                return;
            }
            temp = temp->next;
        }
        gotoxy(45,12);
        printf("this id number is not here\n");
    }
    else
    {
        gotoxy(45,12);
        printf("There have no id\n");
    }

}

int isIdCompare(char id[])// this function compare id number
{
    int i,type = -1,count = 0;
    snode *temp = head;
    while(temp != NULL)
    {
        count++;
        if(strcmp(id,temp->member.id)==0)
        {
            type = count;
            break;
        }

        temp = temp->next;
    }

    return type;
}

//this function work to delete employee personal information
void deleteEmployeeInformation(char id[])
{
    system("cls");
    int i;
    int position = isIdCompare(id);
    printf("%d\n",position);
    snode *prev,*temp;
    temp = head;
    system("cls");
    if(position != -1)
    {
        search_employee_Display(id);
        char key;
        printf("\n\n%35sYou want to sure delete this record \"y\" or \"n\" : ","");
        scanf(" %c",&key);


        if(key == 'y')
        {
            int result = checkCofirmation();

            if(result != -1)
            {
                if(position == 1)
                {
                    head = head->next;
                    system("cls");
                    gotoxy(45,12);
                    printf("Delete successfully\n");
                }
                else
                {
                    temp = head;
                    for(i=1; i<position; i++)
                    {
                        prev = temp;
                        temp = temp->next;
                    }
                    prev->next = temp->next;
                    system("cls");
                    gotoxy(45,12);
                    printf("Delete successfully\n");
                }
            }
            else
            {
                system("cls");
                gotoxy(45,12);
                printf("this password is wrong \n");
                getch();
            }
        }
        else
        {
            system("cls");
            gotoxy(45,12);
            printf("This id number is not delete\n");
        }



    }
    else
    {
        system("cls");
        gotoxy(45,12);
        printf("this id number is not here\n");
        getch();
    }
}
// This function work to display employee personal information

void search_employee_Display_no_2(char id[])
{
    system("cls");
    int i;
    gotoxy(52,1);
    printf("EMPLOYEE PERSONAL INFORMATION ");
    gotoxy(30,3);
    for(i=0; i<75; i++)
    {
        printf("%c",254);
    }
    snode *temp = head;
    if(temp != NULL)
    {
        while(temp != NULL)
        {
            if(strcmp(id,temp->member.id)==0)
            {
                gotoxy(38,6);
                printf("(not editable)   Employee name          : \t\t%s %s",temp->member.first_name,temp->member.last_name);
                gotoxy(38,8);
                printf("(not editable)   Employee Id            : \t\t%s",temp->member.id);
                gotoxy(38,10);
                printf("%c   1    %c     Email                    : \t\t%s",178,178,temp->member.email);
                gotoxy(38,12);
                printf("%c   2    %c     Phone Number             : \t\t%s",178,178,temp->member.phoneNumber);
                gotoxy(38,14);
                printf("%c   3    %c     Designation              : \t\t%s",178,178,temp->member.designation);
                gotoxy(38,16);
                printf("%c   4    %c     Per rate(per hour)       : \t\t%.3f $",178,178,temp->member.per_rate);
                gotoxy(38,18);
                printf("%c   5    %c     Over time rate           : \t\t%.3lf",178,178,temp->member.over_time_rate);
                gotoxy(38,20);
                printf("%c   6    %c     Monthly target hour (hh) : \t\t%d\n",178,178,temp->member.monthly_target_hour);

                return;
            }
            temp = temp->next;
        }
        system("cls");
        gotoxy(45,12);
        printf("this id number is not here\n");
    }
    else
    {
        gotoxy(45,12);
        printf("There have no id\n");
    }

}

// This function work to display per month salary

void employee_per_month_salary_view()
{
    int i,j=8;
    snode *temp = head;
    gotoxy(49,1);
    printf("All Employee Salary");
    for(i=40; i<75; i++)
    {
        gotoxy(i,3);
        printf("%c",254);
    }
    gotoxy(0,5);
    printf("Employee name");
    gotoxy(16,5);
    printf("Employee ID");
    gotoxy(32,5);
    printf("Base salary");
    gotoxy(48,5);
    printf("Over time");
    gotoxy(64,5);
    printf("Total Salary");
    gotoxy(80,5);
    printf("Total Present");
    gotoxy(96,5);
    printf("Total Absence");
    for(i=0; i<115; i++)
    {
        gotoxy(i,6);
        printf("%c",240);
    }

    while(temp != NULL)
    {
        double base_salary = baseSalaryCalculate(temp->member.id);
        double bonus_salary = bonusSalaryCalculate(temp->member.id);
        double total_salary = totalMonthlySalary(temp->member.id);
        int present = calculatePresent(temp->member.id);
        int absence = calculateAbsence(temp->member.id);
        gotoxy(0,j);
        printf("%s %s",temp->member.first_name,temp->member.last_name);
        gotoxy(18,j);
        printf("%s",temp->member.id);
        gotoxy(32,j);
        printf("%.3lf $",base_salary);
        gotoxy(48,j);
        printf("%.3lf $",bonus_salary);
        gotoxy(64,j);
        printf("%.3lf $",total_salary);
        gotoxy(80,j);
        printf("%d day",present);
        gotoxy(96,j);
        printf("%d day",absence);
        temp = temp->next;
        j+=2;
    }

    printf("\n");
}

// This function work to display per month salary

void per_employee_salary_view(char id[])
{
    system("cls");
    int position = isIdCompare(id);
    int i;
    snode *temp = head;
    for(i=1; i<position; i++)
    {
        temp = temp->next;
    }

    if(position != -1)
    {
        double base_salary = baseSalaryCalculate(temp->member.id);
        double bonus_salary = bonusSalaryCalculate(temp->member.id);
        double total_salary = totalMonthlySalary(temp->member.id);
        int present = calculatePresent(temp->member.id);
        int absence = calculateAbsence(temp->member.id);

        int totalHour =  totalHourWork(temp->member.id);
        int totalMin1 = totalMin(temp->member.id);
        int totalTime = (totalHour*60)+totalMin1;
        int finalHour = totalTime/60;
        int finalMin = totalTime%60;
        gotoxy(45,8);
        printf("Id                : %s",temp->member.id);
        gotoxy(45,10);
        printf("Name              : %s %s",temp->member.first_name,temp->member.last_name);
        gotoxy(45,12);
        printf("Total present    -> %d day",present);
        gotoxy(45,14);
        printf("Total Absence    -> %d day",absence);
        gotoxy(45,16);
        printf("Total time       -> %d hour %d min",finalHour,finalMin);
        gotoxy(45,18);
        printf("Base salary      -> %.3lf $",base_salary);
        gotoxy(45,20);
        printf("Over Time salary -> %.3lf $",bonus_salary);
        gotoxy(45,22);
        printf("Total Salary     -> %.3lf $\n",total_salary);

    }
    else
    {
        gotoxy(45,12);
        printf("This id number is not here\n");
    }


}

//This function work to display daily working message

void dailyEarningMessageDisplay(char id[])
{
    system("cls");
    int i;
    int position = isIdCompare(id);
    snode *temp = head;
    for(i=1; i<position; i++)
    {
        temp = temp->next;
    }
    gotoxy(45,10);
    printf("Today Entry Time        -> %d : %d",temp->member.dayStatistics[currentMonthDay].entryTime.wHour,temp->member.dayStatistics[currentMonthDay].entryTime.wMinute);
    gotoxy(45,12);
    printf("Today Exit Time         -> %d : %d",temp->member.dayStatistics[currentMonthDay].exitTime.wHour,temp->member.dayStatistics[currentMonthDay].exitTime.wMinute);
    gotoxy(45,14);
    printf("Today Your Working Hour -> %d hour %d Minutes",temp->member.dayStatistics[currentMonthDay].hour,temp->member.dayStatistics[currentMonthDay].min);
    gotoxy(45,16);
    printf("Today your Earn         -> %.3lf $\n",temp->member.dayStatistics[currentMonthDay].dailyIncome);
}

//This function work to update employee personal information

void employee_personal_information_update(char id[])
{
    system("cls");
    int num,i;
    double num2;
    char ch[30],ch1[30],ch2[30];
    int position = isIdCompare(id);
    if(position != -1)
    {
        snode *temp;
        temp = head;
        for(i=1; i<position; i++)
        {
            temp = temp->next;
        }
        search_employee_Display_no_2(id);
        gotoxy(52,1);
        gotoxy(30,22);
        for(i=0; i<75; i++)
        {
            printf("%c",254);
        }

        printf("\n\n\n%34sWhich information you want to update choose the number :  ","","");
        scanf("%d",&num);
        system("cls");
        switch(num)
        {
        case 1 :
        {

            while(1)
            {
                gotoxy(45,10);
                printf("Email                       :     ");
                scanf(" %[^\n]",ch1);
                int check = gmailVerified(ch1);
                if(check != -1)
                {
                    strcpy(temp->member.email,ch1);
                    system("cls");
                    gotoxy(45,10);
                    printf("Update successfully\n");
                    break;
                }
                printf("\r");
                printf("                    ");
                gotoxy(78,10);
                printf("please verified your email address");
                getch();
                gotoxy(78,10);
                printf("                                   ");

            }

            break;
        }
        case 2 :
        {

            while(1)
            {
                gotoxy(45,10);
                printf("Phone Number                :     +88 ");
                scanf(" %[^\n]",ch1);
                int check = numberFormateCorrection(ch1);
                if(check == 11)
                {
                    strcpy(temp->member.phoneNumber,ch1);
                    gotoxy(45,12);
                    printf("Update successfully\n");
                    break;
                }
                printf("\r");
                printf("                    ");
                gotoxy(78,10);
                printf("Invalid mobile number");
                getch();
                gotoxy(78,10);
                printf("                                   ");

            }

            break;
        }
        case 3 :
        {
            int i;
            gotoxy(45,10);
            printf("Designation   :   ");
            scanf(" %[^\n]",ch2);
            for(i=0; i<strlen(ch2); i++)
            {
                if(ch2[i]==' ')
                {
                    ch2[i] = '_';
                }

            }
            strcpy(temp->member.designation,ch2);
            gotoxy(45,12);
            printf("Update successfully\n");
            break;
        }
        case 4 :
        {
            gotoxy(45,10);
            printf("Rate(per hour) $  :   ");
            scanf("%lf",&num2);
            temp->member.per_rate = num2;
            gotoxy(45,12);
            printf("Update Successfully\n");
            break;
        }
        case 5 :
        {
            gotoxy(45,10);
            printf("Over time bonus(per hour)$   :   ");
            scanf("%lf",&num2);
            temp->member.over_time_rate = num2;
            gotoxy(45,12);
            printf("Update Successfully\n");
            break;
        }
        case 6 :
        {
            gotoxy(45,10);
            printf("Target Hour $   :   ");
            scanf("%d",&num);
            temp->member.monthly_target_hour = num;
            gotoxy(45,12);
            printf("Update Successfully\n");
            break;
        }
        default :
        {
            gotoxy(45,12);
            printf("Wrong input\n");
            break;
        }

        }
    }
    else
    {
        system("cls");
        gotoxy(45,12);
        printf("This id number is not here\n");
    }

}
//this function work to get time

Times getTimes()
{
    Times tm;
    GetSystemTime(&tm);
    return tm;
}
//This function work to get current time
Times getCurrentTime()
{
    Times tm = getTimes();
    tm.wHour+=6;
    if(tm.wHour>=24)
    {
        tm.wHour = tm.wHour - 24;
        tm.wDay = tm.wDay + 1;
    }
    return tm;
}
// This function work to correction time

int timeCorrection(int hour)
{
    int time = hour + 6;
    if(time >24) return (time-24);
    return time;
}
//This function work to update daily task
void perDayUpdate(int type)
{

    system("cls");
    int tmH,tmM,i;
    if(type == 1)
    {
        char id[25];
        snode *temp = head;
        gotoxy(45,10);
        printf("Enter the Id Number    :  ");
        scanf(" %[^\n]",id);
        Times tm = getCurrentTime();
        int position = isIdCompare(id);
        if(position != -1)
        {
            for(i=1; i<position; i++)
            {
                temp = temp->next;
            }
            if(temp->member.dayStatistics[currentMonthDay].entryTime.wHour == 0 && temp->member.dayStatistics[currentMonthDay].entryTime.wMinute == 0)
            {
                temp->member.dayStatistics[currentMonthDay].entryTime.wHour = tm.wHour;
                temp->member.dayStatistics[currentMonthDay].entryTime.wMinute = tm.wMinute;
                temp->member.dayStatistics[currentMonthDay].entryTime.wDay = tm.wDay;
                gotoxy(45,12);
                printf("Successfully updated");
                getch();
                writeFilePerEmployee(id);
            }
            else
            {
                gotoxy(45,12);
                printf("Your have already updated");
                getch();
            }


        }
        else
        {
            system("cls");
            gotoxy(45,12);
            printf("This id number is not here\n");
            getch();
        }
    }

    else if(type==2)
    {
        char id[20];
        snode *temp = head;
        gotoxy(45,10);
        printf("Enter the Id Number    :  ");
        scanf(" %[^\n]",id);
        Times tm = getCurrentTime();
        int position = isIdCompare(id);
        if(position != -1)
        {

            for(i=1; i<position; i++)
            {
                temp = temp->next;
            }
            if(temp->member.dayStatistics[currentMonthDay].exitTime.wHour == 0 && temp->member.dayStatistics[currentMonthDay].exitTime.wMinute==0 && temp->member.dayStatistics[currentMonthDay].entryTime.wMinute != 0)
            {
                temp->member.dayStatistics[currentMonthDay].exitTime.wHour = tm.wHour;
                temp->member.dayStatistics[currentMonthDay].exitTime.wMinute = tm.wMinute;
                double perDayTotalEarn = perDayTimeHourCount(temp->member.dayStatistics[currentMonthDay].entryTime.wHour, temp->member.dayStatistics[currentMonthDay].entryTime.wMinute,temp->member.dayStatistics[currentMonthDay].exitTime.wHour,temp->member.dayStatistics[currentMonthDay].exitTime.wMinute,position);
                // per person id relate all start timing and ending time pass to perDayTimeHourCount
                temp->member.dayStatistics[currentMonthDay].dailyIncome = perDayTotalEarn;
                gotoxy(45,8);
                printf("successfully update\n");
                dailyEarningMessageDisplay(id);
                writeFilePerEmployee(id);
                getch();


            }
            else
            {
                gotoxy(45,12);
                printf("Your have already updated");
                getch();
            }

        }
        else
        {
            gotoxy(45,12);
            printf("This Id Number is not here\n");
            getch();
        }

    }
    else if(type==3)
    {
        char id[20];
        snode *temp = head;
        gotoxy(45,10);
        printf("Enter the Id Number    :  ");
        scanf(" %[^\n]",id);
        int position = isIdCompare(id);
        if(position != -1)
        {
            for(i=1; i<position; i++)
            {
                temp = temp->next;
            }
            temp->member.dayStatistics[currentMonthDay].dailyIncome = -1;
            gotoxy(45,12);
            printf("successfully updated\n");
            writeFilePerEmployee(id);
            getch();
        }
        else
        {
            gotoxy(45,12);
            printf("This Id Number is not here\n");
            getch();
        }

    }

}

//this function work to count per day time hour

double perDayTimeHourCount(int h1,int m1,int h2,int m2,int position)
{
    int tmHour,tmMin,i;
    int t1 = (h1*60)+(h2*60);
    int t2 = m1+m2;
    int t3 = m2-m1;
    if(h1>h2)
    {
        if(m1>m2)
        {
            int total_time_sec = t1-t2;
            tmHour = total_time_sec/60;
            tmMin = (total_time_sec%60);

        }
        else
        {
            int total_time_sec = t1+t3;
            tmHour = total_time_sec/60;
            tmMin = (total_time_sec%60);

        }

    }

    else if(h1 == h2)
    {
        if(m1>m2)
        {
            int total_time_sec = 1440-(m1-m2);
            tmHour = total_time_sec/60;
            tmMin = (total_time_sec%60);

        }
        else
        {
            int total_time_sec = ((h2*60)+m2)-((h1*60)+m1);
            tmHour = total_time_sec/60;
            tmMin = (total_time_sec%60);


        }
    }

    else
    {
        int total_time_sec = ((h2*60)+m2)-((h1*60)+m1);
        tmHour = total_time_sec/60;
        tmMin = (total_time_sec%60);

    }

    snode *temp = head;
    for(i=1; i<position; i++)
    {
        temp = temp->next;
    }
    temp->member.dayStatistics[currentMonthDay].hour = tmHour;
    temp->member.dayStatistics[currentMonthDay].min = tmMin;
    double perDayEarn =  perDayEarningCount(tmHour,tmMin,position);
    return perDayEarn;

}

//this function work to count per day earning

double perDayEarningCount(int tmHour,int tmMin,int position)
{
    int i;
    snode *temp = head;
    for(i=1; i<position; i++)
    {
        temp = temp->next;
    }
    double perEarnHour = temp->member.per_rate * (double)tmHour;   // this variable hourly per rate calculate
    double perEarnMin = ( temp->member.per_rate/60)* (double)tmMin;
    double perDayTotalEarn = perEarnHour +  perEarnMin ;
    return perDayTotalEarn;
}


// This function work to display calculate present

int calculatePresent(char id[])
{
    int i,count = 0;;
    int position = isIdCompare(id);
    snode *temp = head;

    for(i=1; i<position; i++)
    {
        temp = temp->next;
    }
    for(i=1; i<32; i++)
    {
        if(temp->member.dayStatistics[i].dailyIncome > 0)
        {
            count++;
        }

    }
    return count;
}

//Thsi function work to calculate absence

int calculateAbsence(char id[])
{
    int i,count = 0;
    int position = isIdCompare(id);
    snode *temp = head;
    for(i=1; i<position; i++)
    {
        temp = temp->next;
    }
    for(i=1; i<32; i++)
    {
        if(temp->member.dayStatistics[i].dailyIncome == -1)
        {
            count++;
        }
    }
    return count;
}

//email formate check

int gmailVerified(char ch[])
{
    int i,k=0,j=0,l,result = -1,count1=0,count2=0;
    char arr[9];
    char arr2[30];
    for(i=0; i<strlen(ch); i++)
    {
        if(ispunct(ch[0]))break;
        if(ch[i]>='0' && ch[i]<='9' || ch[i]>='a' && ch[i] <= 'z' || ch[i]>='A' && ch[i] <= 'Z' || ch[i] == '@' || ch[i] == '.')
        {
            if(ch[i] == '@')
            {
                j=i;
                count1++;
                break;
            }
            if(ch[i] == '.' && ch[i+1] == '.')
            {
                count2++;
            }

        }
        else
        {
            count2++;
        }
    }
    if(j>2 && count1 == 1 && count2==0 && ch[j-1] != '.')
    {
        l=0;
        int dotcount1 = 0,dotcount2 = 0,test=0;
        for(i=j+1; i<strlen(ch); i++)
        {
            if(isalpha(ch[i]) || ch[i] == '.' && ch[j+1] != '.')
            {
                if(ch[i]=='.')
                {
                    test = i-(j+1);
                    dotcount1++;

                }


                if(ch[i]=='.' && ch[i+1] =='.')
                {

                    dotcount2++;
                }

            }

        }

        if(dotcount2 == 0 && dotcount1>0 && test != 0)
        {
            result = 1;
        }

    }

    return result;
}

// Thsi function work to bd mobile number correction

int numberFormateCorrection(char arr[])
{
    int i,count = 0;
    for(i=0; i<strlen(arr); i++)
    {
        if(arr[i]>='0' && arr[i]<='9')
        {
            count++;
        }
    }
    return count;

}

// This function work to update calculate base salary

double baseSalaryCalculate(char id[])
{
    int i;
    double base_salary = 0.0;
    int position = isIdCompare(id);
    snode *temp = head;
    for(i=1; i<position; i++)
    {
        temp = temp->next;
    }
    for(i=1; i<32; i++)
    {
        if(temp->member.dayStatistics[i].dailyIncome > 0)
        {
            base_salary += temp->member.dayStatistics[i].dailyIncome;
        }

    }
    return base_salary;
}

// This function work to count total hour work

int totalHourWork(char id[])
{
    int i;
    int hour_count = 0;
    int position = isIdCompare(id);
    snode *temp = head;
    for(i=1; i<position; i++)
    {
        temp = temp->next;
    }
    for(i=1; i<32; i++)
    {
        hour_count += temp->member.dayStatistics[i].hour;
    }
    return hour_count;
}

// This function wotk to count total minute

int totalMin(char id[])
{
    int i;
    int position = isIdCompare(id);
    int min_count = 0;
    snode *temp = head;
    for(i=1; i<position; i++)
    {
        temp = temp->next;
    }
    for(i=1; i<32; i++)
    {
        min_count += temp->member.dayStatistics[i].min;
    }
    return min_count;
}

// this function work to calculate bonus salary

double bonusSalaryCalculate(char id[])
{
    int i;
    int position = isIdCompare(id);
    int total_hour = totalHourWork(id);
    int total_min = totalMin(id);
    int bonus_hour;
    int total_bonus_hour = 0;
    snode *temp = head;
    double bonusEarnHour = 0.0;
    double bonusEarnMin = 0.0;
    double bonusTotalEarn ;
    for(i=1; i<position; i++)
    {
        temp = temp->next;
    }
    if(temp->member.monthly_target_hour < total_hour )
    {
        total_bonus_hour = total_hour  - temp->member.monthly_target_hour;
        bonusEarnHour = temp->member.over_time_rate * (double)total_bonus_hour;   // this variable hourly per rate calculate
        bonusEarnMin = ( temp->member.over_time_rate /60)* (double)total_min ;

    }

    bonusTotalEarn =  bonusEarnHour  +  bonusEarnMin ;

    return bonusTotalEarn;
}

// Thsi function work to calculate total monthly salary

double totalMonthlySalary(char id[])
{
    double baseSalary = baseSalaryCalculate(id);
    double bonusSalary = bonusSalaryCalculate(id);
    double totalSalary = baseSalary + bonusSalary;
    return totalSalary;

}

// this function maintain main menu

void maintainMainMenu()
{

    int choose;

    int i;
    do
    {
        int num;
        mainMenue();
        printf("\n%42s Choose the Number  :   ","");
        scanf("%d",&num);
        system("cls");
        switch(num)
        {
        case 1 :
        {
            char ch;
            int exit = 0;

            do
            {
                system("cls");
                employeeMenue();
                printf("\n%42s Choose the Number  :   ","");
                scanf("%d",&choose);
                system("cls");
                switch(choose)
                {
                case 1 :
                {
                    int out = 0;
                    do
                    {

                        createEmployeeList();

                        printf("\n\n%45sYou want to add another \"y\" or \"n\" : ","");
                        scanf(" %c",&ch);
                        system("cls");
                        if(ch == 'y')
                        {
                            out = 0;
                        }
                        else if(ch == 'n')
                        {
                            out = -1;
                        }
                        else
                        {
                            gotoxy(45,10);
                            printf("\n Wrong Input\n");
                        }
                    }
                    while(out != -1);

                    break;
                }

                case 2 :
                {
                    system("cls");
                    char id[20];
                    gotoxy(45,10);
                    printf("Enter the Id Number : ");
                    scanf(" %[^\n]",id);
                    search_employee_Display(id);
                    printf("\n\n%45sPress any key go to Employee Menu...","");
                    getch();
                    break;
                }

                case 3 :
                {
                    int choose;
                    system("cls");
                    gotoxy(40,6);
                    printf("%c  1  %c  View personal info",178,178);
                    gotoxy(40,8);
                    printf("%c  2  %c  Update personal info",178,178);
                    gotoxy(40,10);
                    printf("Choose the number  :  ");
                    scanf("%d",&choose);
                    switch(choose)
                    {
                    case 1 :
                    {
                        system("cls");
                        char id[20];
                        gotoxy(45,10);
                        printf("Enter the Id Number : ");
                        scanf(" %[^\n]",id);
                        view_employee_personal_info(id);
                        gotoxy(45,24);
                        printf("Press any key go to Employee Menu...");
                        getch();
                        break;
                    }
                    case 2 :
                    {
                        char id[30];
                        gotoxy(40,12);
                        printf("Enter the id Number  : ");
                        scanf(" %[^\n]",id);
                        employee_personal_information_update(id);
                        gotoxy(56,1);
                        printf("Update Information");
                        view_employee_personal_info(id);
                        gotoxy(56,1);
                        printf("New Update Information");
                        gotoxy(45,24);
                        printf("Press any key go to Employee Menu...");
                        getch();
                        break;

                    }
                    default :
                        printf("\n\n%45sWrong Input","");
                        break;
                    }
                    break;
                }

                case 4 :
                {
                    all_Employe_Display();
                    printf("\n\n%45sPress any key go to Employee Menu...","");
                    getch();
                    break;
                }
                case 5 :
                {
                    char id[30],select;
                    gotoxy(45,10);
                    printf("Enter the id number for delete from your record\n");
                    while(1)
                    {
                        system("cls");
                        gotoxy(45,12);
                        printf("Id Number : ");
                        scanf(" %[^\n]",id);
                        deleteEmployeeInformation(id);
                        printf("\n%35sYou want to delete another \"y\" or \"n\" : ","");
                        scanf(" %c",&select);
                        if(select == 'n')
                        {
                            break;
                        }

                    }
                    break;
                }
                case 6 :
                {
                    employeeWriteFile();
                    exit = -1;
                    break;
                }

                default :
                    printf("\n\n%45sWrong Input\n","");
                    break;

                }


            }
            while(exit != -1);
            break;
        }

        case 2:
        {
            char ch;
            int num,type;
            char idNum[30];
            updateMenu();
            printf("\n%45sChoose :  ","");
            scanf("%d",&num);
            system("cls");
            if(num==4) break;
            perDayUpdate(num);
            system("cls");
            break;

        }


        case 3 :
        {
            int out = 0;
            do
            {

                int num;
                system("cls");
                salaryMenu();
                printf("\n\n%45s Select : ","");
                scanf("%d",&num);
                system("cls");
                char id[20];
                if(num == 1)
                {
                    char id[20];
                    gotoxy(45,10);
                    printf("Enter the Id Number : ");
                    scanf(" %[^\n]",id);
                    per_employee_salary_view(id);
                    getch();
                }
                else if(num == 2)
                {
                    system("cls");
                    employee_per_month_salary_view();

                    getch();

                }
                else if(num == 3)
                {
                    reportFileWrite();
                    break;
                }
                else
                {
                    out = -1;
                    break;
                }
            }
            while(out != -1);

            break;
        }

        case 4 :
            choose = -1;
            break;

        default :
        {
            gotoxy(45,10);
            printf("Wrong Input\n");
            getch();
            break;
        }
        }
        gotoxy(45,10);
        system("pause");
        system("cls");

    }
    while(choose != -1);

}



int main()
{
    system("color 4f");
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    currentMonthDay = t->tm_mday;
    int temp = 0,choose;
    adminReadFileData();
    readAllEmployeeFile();
    do
    {
        logInMenue();
        gotoxy(44,20);
        printf("Choose the Number  :  ");
        scanf("%d",&choose);
        switch(choose)
        {
        case 1 :
        {
            system("cls");
            int result = checkAccount();
            if(result == 1)
            {

                system("cls");
                maintainMainMenu();

            }
            else
            {
                system("cls");
                gotoxy(45,10);
                printf("Your user name and password does not match\n");
                gotoxy(45,12);
                printf("Press any key go to the welcome screen");
                getch();
            }
            break;
        }
        case 2 :
        {
            system("cls");
            signUpAccount();
            break;

        }
        case 3 :
        {

            system("cls");
            printf("\n\n%40sThank you for using this system\n\n","");
            temp = -1;
            break;
        }
        default :
            break;

        }

    }
    while(temp != -1);

}










