/** SAJIB BISWAS
ID=171-35-1960
Manager Password= sajib
Employee Password= sajib
Employee ID= available employees id in file.ex: 1,2,3.
**/



#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>
void  manager();
void append();
void display();
void displayAll();
void modify();
void del();
void search();
void sort();
void date();
void remider();
void tasklist();
void viewtasklist();
void createtask();
void edittask();
int check(int a);


void  employee();
void  employeedata();
void empmain(int id;);
void empprofile(int id);
void viewtask(int id);


char fname[]={"HRM.txt"};
//char mygetch();

struct emp
{
int id;
char name[20];
int salary;
int shift;
int task;
int day;
int month;
int year;
};//For employee info

struct task
{
    int no;
    char details[1000][1000];
};//For Task list


struct tm *t;//Time structure

int main()
{
 char loop = 'n';
 system("cls");
 while(loop=='n'||loop=='N')
 {
 int menu;
  system("cls");
    printf("\n\t<<HR management>>");
    printf("\n____________________");
    printf("\n\n\t1.Manager Log in");
    printf("\n\t2.Employee Log in.");
    printf("\n\t(Enter 0 for exits)");
    printf("\n____________________");
    printf("\nSelect Option(1-2)\n");
    scanf("%d",& menu);
 switch(menu)
{
    case 1:
    {
        system("cls");
        printf("\n<<#1-Manager Log in>>");
        printf("\n=====================================");
        manager();
    }
        break;
    case 2:
    {
        system("cls");
        printf("\n<<#2-Employee Log in>>");
        printf("\n=====================================");
        employee();
    }
        break;

    case 0:
    {
        printf("\n\t\t*****THANK YOUR FOR USING HRM SYSTEM*****\t\t\n");
        exit(0);
        break;
    }


    default:
        printf("\nNot an option.");
    }
        printf("\n\n^^Thank you for using HR management^^");
        printf("\nDo you want to exit?(y/n)");
        scanf(" %c",& loop);
        if(loop=='y'||loop=='Y')
    return 0;
 else
 loop='n';
 }
 getch();
 }



 void  manager()//This is for manager page.
 {
    char passmanager[10],ch;
    int loop1=0,loopm1=0,i=0;
    //strcpy(passmanager, "");
    printf("\nEnter your password:");
    while(loop1==0)
        {
            memset(passmanager,0,strlen(passmanager));
               while (1) {
      if (i < 0) {
         i = 0;
      }
      ch = getch();

      if (ch == 13)//ASCII value of Enter.
         break;
      if (ch == 8) /*ASCII value of BACKSPACE*/
      {
         putch('\b');
         putch(NULL);
         putch('\b');
         passmanager[i] ='\0';
         i--;
         passmanager[i] ='\0';
         continue;
      }

      passmanager[i++] = ch;
      ch = '*';
      putch(ch);
   }
   //printf("\n:%s",passmanager);
  // printf("\n%s\n",passmanager);
            //scanf("%s",passmanager);
                      /*  int ret=1;
            if(i<5)
            {
                i=5;
            }
            ret = strncmp(passmanager, "sajib", i);
            printf("%d",i);
            if(ret==0)*/
            if(strcmp(passmanager, "sajib") == 0) //Password for manager.
                {loop1++;
                    printf("\n\n**Access Granted**\n\n(press any key to continue...)");
                    getch();
                    manmain();
                }
            else
                {
                    system("cls");
                                           //printf("\n:%s",passmanager);
                        //strcpy(passmanager, "");
                        //printf("\n:%s",passmanager);
                    printf("\n<<#1-Manager Log in>>");
                    printf("\n=====================================");
                    printf("\nPassword does not match!\nTry again:");
                    i=0;
                    loop1=0;
                }
        }
 }




void  employee()//This is for employee page.
{
    char passemployee[10],ch;
    int loop1=0,loopm1=0,i=0,id,found=0;
    struct emp t1;
    FILE *fp;
    while(found==0)
    {
        printf("\nEnter ID:");
        scanf("%d",&id);
        fp=fopen(fname,"rb");
while(1)
{
    fread(&t1,sizeof(t1),1,fp);
        if(t1.id==id)
    {
        found=1;
            //printf("%d",found);
        break;
    }
    //else{printf("\n no match!%d %d",t1.id,id);}
   /*     else
    {
        found=3;
    }*/
    if(feof(fp))
    {
        found=0;
        system("cls");
        printf("\n<<#2-Employee Log in>>");
        printf("\n=====================================");
        printf("\nID does not match!");
        break;
    }
}
    fclose(fp);
    }
if(found==1)
{
    system("cls");
    printf("\n<<#2-Employee Log in>>");
    printf("\n=====================================");
    printf("\nID:%d",id);
    printf("\nEnter your password:");
        memset(passemployee,0,strlen(passemployee));
    while(loop1==0)
        {
            memset(passemployee,0,strlen(passemployee));
               while (1) {
      if (i < 0) {
         i = 0;
      }
      ch = getch();

      if (ch == 13)
      {//ASCII value of Enter.
         passemployee[i] ='\0';
         break;
      }
      if (ch == 8) /*ASCII value of BACKSPACE*/
      {
         putch('\b');
         putch(NULL);
         putch('\b');
         passemployee[i] ='\0';
         i--;
         passemployee[i] ='\0';
         continue;
      }

      passemployee[i++] = ch;
      ch = '*';
      putch(ch);
   }
  // printf("\n%s\n",passemployee);
            //scanf("%s",passemployee);
      /*      int ret=1;
            if(i<5)
            {
                i=5;
            }
            ret = strncmp(passemployee, "sajib", i);
            //printf("%d",i);
          if(ret==0) */
            if(strcmp(passemployee, "sajib") == 0) //Password for manager.
                {loop1++;
                    printf("\n\n**Access Granted**\n\n(press any key to continue...)");
                    getch();
                    empmain(id);
                }
            else
                {
                    system("cls");
                    printf("\n<<#2-Employee Log in>>");
                    printf("\n=====================================");
                    printf("\nID:%d",id);
                                       // printf("\n:%s",passemployee);
                    printf("\nPassword does not match!\nTry again:");
                    i=0;
                    loop1=0;
                }
        }
}
}

void manmain()
{
int ch;
int condition=0;
int b=0;
FILE *fp;
fp=fopen(fname,"ab");
fclose(fp);
while(1)
{
    //clrscr();
    system("cls");
    //printf("%d",condition);
    condition=check(b);
   // printf("%d",condition);
    printf("\n==================Employee Management System=============\n\n");
       if(condition==1)
   {
    printf(" \t\t\tYou have Reminder!!!\n\n");
   }
    printf("1. Append\n\n");
    printf("2. Modify\n\n");
    printf("3. Delete\n\n");
    printf("4. Search\n\n");
    printf("5. Display\n\n");
    printf("6. Display All\n\n");
    printf("7. Task list\n\n");
   if(condition==1)
   {
    printf("8. Reminder!!!\n\n");
   }
    printf("0. Log out\n\n");
    printf("========================================================\n\n");

    printf("\nPlease enter your Choice:");
    scanf("%d",&ch);
    system("cls");
switch(ch)
{
    case 1: append();
    break;

    case 2: modify();
    break;

    case 3: del();
    break;

    case 4: search();
    break;

    case 5: display();
    break;

    case 6: displayAll();
    break;

    case 7: tasklist();
    break;

    /*case 7: sort();
    break;*/
    case 8: remider();
        break;

    case 0: main();
        //exit(0);
    break;

    default:
    printf("\nNot an option.");
    break;
}

//mygetch();
printf("\n(press any key to get back..)\n");
getch();
}

return 0;
}


void append()
{
FILE *fp;
int id,found=0,a=0,loop=0;
struct emp t1;
    int mon,day,year;
   time_t now = time(NULL);
fp=fopen(fname,"ab");
fclose(fp);
fp=fopen(fname,"rb");

printf("\nEnter ID:");
scanf("%d",&id);
while(1)
{
    fread(&t1,sizeof(t1),1,fp);
        if(t1.id==id)
    {
        printf("ID already exist");
        found==1;
        break;
    }
   /*     else
    {
        found=3;
    }*/
    if(feof(fp))
    {
        found=3;
        break;
    }
}

//printf("\n %d %d %d",t1.id,id,found);
fclose(fp);
//printf("%d",found);
  if(found==3)
{
    fp=fopen(fname,"ab");

    t1.id=id;
    printf("\nEnter name:");
    scanf("%s",t1.name);
    printf("\nEnter salary:");
    scanf("%d",&t1.salary);
    while(1)
    {
        printf("\nEnter Shift (1.Morning 2.Noon 3.Evening):");
        scanf("%d",&t1.shift);
        if(t1.shift<1 || t1.shift>3)
        {
            printf("\nWrong Choice!");
        }
        else
        {
            break;
        }
    }
        while(1)
    {
        printf("\nEnter Task no(1-4):");
        scanf("%d",&t1.task);
        if(t1.task<1 || t1.task>4)
        {
            printf("\nWrong Choice!");
        }
        else
        {
            break;
        }
    }
    struct tm *d = localtime(&now);
    t1.month=d->tm_mon+1;
    t1.day=d->tm_mday;
    t1.year=d->tm_year+1900;
    fwrite(&t1,sizeof(t1),1,fp);
}

fclose(fp);
sort();
}

void modify()
    {
        FILE *fp,*fp1;
        struct emp t,t1;
        int id,found=0,count=0;

        fp=fopen(fname,"rb");
        fp1=fopen("temp.dat","wb");

        printf("\nEnter the Emp ID you want to Modify:");
        scanf("%d",&id);

        while(1)
    {
        fread(&t,sizeof(t),1,fp);

    if(feof(fp))
    {
        break;
    }
    if(t.id==id)
    {
        found=1;
        printf("\nEnter Employee ID:");
        scanf("%d",&t.id);
        fflush(stdin);
        printf("\nEnter Employee Name:");
        scanf("%s",t.name);
        printf("\nEnter Employee Salary:");
        scanf("%d",&t.salary);
    while(1)
    {
        printf("\nEnter Shift (1.Morning 2.Noon 3.Evening):");
        scanf("%d",&t1.shift);
        if(t1.shift<1 || t1.shift>3)
        {
            printf("\nWrong Choice!");
        }
        else
        {
            break;
        }
    }
        while(1)
    {
        printf("\nEnter Task no(1-4):");
        scanf("%d",&t1.task);
        if(t1.task<1 || t1.task>4)
        {
            printf("\nWrong Choice!");
        }
        else
        {
            break;
        }
    }
        t.day=t.day;
        t.month=t.month;
        t.year=t.year;
        fwrite(&t,sizeof(t),1,fp1);
    }
    else
    {
        fwrite(&t,sizeof(t),1,fp1);
    }
    }
    fclose(fp);
    fclose(fp1);

    if(found==0)
    {
        printf("Sorry No Record Found\n\n");
    }
    else
    {
        fp=fopen(fname,"wb");
        fp1=fopen("temp.dat","rb");

    while(1)
    {
        fread(&t,sizeof(t),1,fp1);

    if(feof(fp1))
    {
        break;
    }
        fwrite(&t,sizeof(t),1,fp);
    }

    }
fclose(fp);
fclose(fp1);
}

void del()
{
FILE *fp,*fp1;
struct emp t,t1;
int id,found=0,count=0;

fp=fopen(fname,"rb");
fp1=fopen("temp.dat","wb");

printf("\nEnter the Emp ID you want to Delete:");
scanf("%d",&id);

while(1)
{
    fread(&t,sizeof(t),1,fp);

    if(feof(fp))
    {
        break;
    }
    if(t.id==id)
    {
        found=1;
    }
    else
    {
        fwrite(&t,sizeof(t),1,fp1);
    }
}
fclose(fp);
fclose(fp1);

if(found==0)
    {
        printf("Sorry No Record Found\n\n");
    }
else
    {
        fp=fopen(fname,"wb");
        fp1=fopen("temp.dat","rb");

        while(1)
        {
            fread(&t,sizeof(t),1,fp1);
            if(feof(fp1))
            {
                break;
            }
            fwrite(&t,sizeof(t),1,fp);
        }
    }
fclose(fp);
fclose(fp1);
printf("\nDone!");
}

void display()
{
FILE *fp;
struct emp t;
int id,found=0;

fp=fopen(fname,"rb");

printf("\nEnter the Emp ID:");
scanf("%d",&id);

while(1)
{
    fread(&t,sizeof(t),1,fp);

    if(feof(fp))
    {
        break;
    }
    if(t.id==id)
    {
        found=1;
        printf("\n========================================================\n\n");
        printf("\t\t Employee Details of %d\n\n",t.id);
        printf("========================================================\n\n");

    printf("Name\tSalary\tJoinDate\tShift\tTaskNO\n\n");

    printf("%s\t",t.name);
    printf("%d\t",t.salary);
    printf("%d/",t.day);
    printf("%d/",t.month);
    printf("%d\t",t.year);
    printf("%d\t",t.shift);
    printf("%d\t\n\n",t.task);

    printf("========================================================\n\n");
    }
}
    if(found==0)
    {
        printf("\nSorry No Record Found");
    }
fclose(fp);
}

void search()
{
FILE *fp;
struct emp t;
int found=0;
char name[20];

fp=fopen(fname,"rb");

printf("\nEnter the Employee Name:");
scanf("%s",&name);

while(1)
    {
        fread(&t,sizeof(t),1,fp);

        if(feof(fp))
        {
            break;
        }
        if(strcmp(name,t.name)==0)
        {
            found=1;
            printf("\n========================================================\n\n");
            printf("\t\t Employee Details of %d\n\n",t.id);
            printf("========================================================\n\n");

            printf("Name\tSalary\tJoinDate\tShift\tTaskNO\n\n");

            printf("%s\t",t.name);
            printf("%d\t",t.salary);
            printf("%d/",t.day);
            printf("%d/",t.month);
            printf("%d\t",t.year);
            printf("%d\t",t.shift);
            printf("%d\t\n\n",t.task);

            printf("========================================================\n\n");

        }
    }
    if(found==0)
    {
        printf("\nSorry No Record Found");
    }
fclose(fp);
}

void displayAll()
{
FILE *fp;
struct emp t;

fp=fopen(fname,"rb");

printf("\n========================================================\n\n");
printf("\t\t All Employee Details\n\n");
printf("========================================================\n\n");

printf("ID\tName\tSalary\tJoinDate\tShift\tTaskNO\n\n");

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
printf("%d\t",t.id);
printf("%s\t",t.name);
printf("%d\t",t.salary);
printf("%d/",t.day);
printf("%d/",t.month);
printf("%d\t",t.year);
printf("%d\t",t.shift);
printf("%d\t\n\n",t.task);

}
printf("========================================================\n\n");

fclose(fp);
}

void sort()
{
FILE *fp,*fp1;
struct emp t,t1;
int i=0,count=0,j,k,l;
int tempid,tempsalary,temptask,tempday,tempmonth,tempyear,tempshift;
int id[100],salary[100],task[100],day[100],month[100],year[100],shift[100];
char name[100][100];
char tempname[100][100];

fp=fopen(fname,"rb");

//printf("ID\tName\tSalary\tTaskNO\n\n");
while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
i++;
count++;
id[i]=t.id;
strcpy(name[i],t.name);
salary[i]=t.salary;
task[i]=t.task;
shift[i]=t.shift;
day[i]=t.day;
month[i]=t.month;
year[i]=t.year;
//printf("%d\t",id[i]);
//printf("%s\t",name[i]);
//printf("%d\t\n\n",salary[i]);
}
fclose(fp);
for (j = 1 ; j <=count; j++)
 {
	for (k = 1 ; k<=count-j;k++)
		{
		 if (id[k] > id[k+1])
			{
			tempid = id[k];
			id[k] = id[k+1];
			id[k+1] = tempid;
                strcpy(tempname,name[k]);
                strcpy(name[k],name[k+1]);
                strcpy(name[k+1],tempname);
                    tempsalary = salary[k];
                    salary[k] = salary[k+1];
                    salary[k+1] = tempsalary;
                        temptask = task[k];
                        task[k] = task[k+1];
                        task[k+1] = temptask;
                            tempday = day[k];
                            day[k] = day[k+1];
                            day[k+1] = tempday;
                                tempmonth = month[k];
                                month[k] = month[k+1];
                                month[k+1] = tempmonth;
                                    tempyear = year[k];
                                    year[k] = year[k+1];
                                    year[k+1] = tempyear;
                                        tempshift = shift[k];
                                        shift[k] = task[k+1];
                                        shift[k+1] = tempshift;
			 }
		 }
 }
 fp=fopen(fname,"wb");
 //fp1=fopen("temp.dat","wb");
 for(l=1;l<=count;l++)
 {
    //printf("%d\t",id[l]);
    //printf("%s\t",name[l]);
    //printf("%d\t\n\n",salary[l]);
    t.id=id[l];
    strcpy(t.name,name[l]);
    t.salary=salary[l];
    t.task=task[l];
    t.shift=shift[l];
    t.day=day[l];
    t.month=month[l];
    t.year=year[l];
//fprintf(fp1,"%d%s%d",t.id,t.name,t.salary);
    fwrite(&t,sizeof(t),1,fp);
 }
 fclose(fp);
 //fclose(fp1);
/* fp=fopen(fname,"rb");
 //fp1=fopen("temp.dat","rb");

 while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
printf("%d\t",t.id);
printf("%s\t",t.name);
printf("%d\t",t.salary);
printf("%d\t\n\n",t.task);

}
printf("========================================================\n\n");

fclose(fp); */
}

/*char mygetch()
{
char val;
char rel;

scanf("%c",&val);
scanf("%c",&rel);
return (val);
}*/
int check(int a)
{
        FILE *fp;
        struct emp t;
        int id,found=0,count=0;
    int mon,day,year;
   time_t now = time(NULL);
   struct tm *d1;
   struct tm *d = localtime(&now);

        fp=fopen(fname,"rb");
        while(1)
    {
        fread(&t,sizeof(t),1,fp);
//printf("%d\t",t.day);
    if(feof(fp))
    {
        break;
    }
    if(t.day==d->tm_mday && t.month==d->tm_mon+1 && t.year!=d->tm_year+1900)
    {
        found=1;
        //printf("found\t");
        a=1;
    }
    else
    {
        found=2;
        //a=2;
    }
    }
    fclose(fp);
return a;
fclose(fp);
}


void remider()
{
FILE *fp;
struct emp t;
int id,found=0,choice;
   time_t now = time(NULL);
   struct tm *d1;
   struct tm *d = localtime(&now);

fp=fopen(fname,"rb");


while(1)
{
    fread(&t,sizeof(t),1,fp);

    if(feof(fp))
    {
        break;
    }
    if(t.day==d->tm_mday && t.month==d->tm_mon+1)
    {
        found=1;
        printf("\n========================================================\n\n");
        printf("\t\t Employee %d will get a rise!\n\n",t.id);
        printf("========================================================\n\n");
    id=t.id;
    printf("Name\tSalary\tJoinDate\tShift\tTaskNO\n\n");

    printf("%s\t",t.name);
    printf("%d\t",t.salary);
    printf("%d/",t.day);
    printf("%d/",t.month);
    printf("%d\t",t.year);
    printf("%d\t",t.shift);
    printf("%d\t\n\n",t.task);

    printf("========================================================\n\n");
    }
}
    if(found==0)
    {
        printf("\nSorry No Record Found");
    }
fclose(fp);


    if(found==1)
    {
        printf("\nPress 1 for raise salary. Press any other for go back:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
    {
        FILE *fp,*fp1;
        struct emp t,t1;
        int found1=0,count1=0;

        fp=fopen(fname,"rb");
        fp1=fopen("temp.dat","wb");
        while(1)
    {
        fread(&t,sizeof(t),1,fp);

    if(feof(fp))
    {
        break;
    }
    if(t.id==id)
    {
        found1=1;
        t.id=t.id;
        strcpy(t.name,t.name);
        printf("\nPrevious salary:%d\nEnter new salary:",t.salary);
        scanf("%d",&t.salary);
        printf("Done!");
        t.task=t.task;
        t.day=t.day;
        t.month=t.month;
        t.year=t.year;
        fwrite(&t,sizeof(t),1,fp1);
    }
    else
    {
        fwrite(&t,sizeof(t),1,fp1);
    }
    }
    fclose(fp);
    fclose(fp1);

    if(found1==0)
    {
        printf("Sorry No Record Found\n\n");
    }
    else
    {
        fp=fopen(fname,"wb");
        fp1=fopen("temp.dat","rb");

    while(1)
    {
        fread(&t,sizeof(t),1,fp1);

    if(feof(fp1))
    {
        break;
    }
        fwrite(&t,sizeof(t),1,fp);
    }

    }
fclose(fp);
fclose(fp1);
    }

            break;
        default:
            break;
        }
    }



}



void tasklist()
{
int choice;
printf("\n\t\t====Tasklist====");
printf("\n\t\t1.Create Task\n\n\t\t2.Edit Task\n\n\t\t3.View Task list\n\n\t\tSelect option:");
scanf("%d",&choice);
switch(choice)
{
case 1:createtask();
    break;

case 2:edittask();
    break;

case 3:viewtasklist();
    break;

    default:printf("\nNot an option");
}

}



void createtask()
{
int no,condition=0;
struct task a;
FILE *fp;
fp=fopen("task.txt","ab");
fclose(fp);
    while(1)
    {
        printf("\nEnter Task no(1-4):");
        scanf("%d",&no);
        if(no<1 || no>4)
        {
            printf("\nWrong Choice!");
        }
                else
        {
            break;
        }
    }
        fp=fopen("task.txt","rb");
        while(1)
        {
            if(feof(fp))
            {
                break;
            }
            fread(&a,sizeof(a),1,fp);
if(a.no==no)
{
    printf("\nTask no. already exist");
    condition=1;
}
        }
fclose(fp);
    if(condition==0)
    {
        fp=fopen("task.txt","ab");
        a.no=no;
        printf("\nEnter task:");
        scanf(" %[^\n]s",a.details);
        fwrite(&a,sizeof(a),1,fp);
        fclose(fp);
    }
}



void edittask()
{
int no,found=0;
struct task a;
FILE *fp,*fp1;
fp=fopen("task.txt","ab");
fclose(fp);
    while(1)
    {
        printf("\nEnter Task no(1-4):");
        scanf("%d",&no);
        if(no<1 || no>4)
        {
            printf("\nWrong Choice!");
        }
        else
        {
            break;
        }
    }
        fp=fopen("task.txt","rb");
        fp1=fopen("temp.txt","wb");
        while(1)
        {
            fread(&a,sizeof(a),1,fp);
                        //printf("\n%d %d",a.no,no);
            if(feof(fp))
            {
                break;
            }
                if(a.no==no)
                {
                    a.no=no;
                    printf("\nEnter task:");
                    scanf(" %[^\n]s",a.details);
                    fwrite(&a,sizeof(a),1,fp1);
                    found=1;
                }
                else
                {
                    fwrite(&a,sizeof(a),1,fp1);
                    //printf("\n Task no didn't exist");
                }
            }
fclose(fp);
fclose(fp1);
if(found==0)
{
    printf("\nTask no.does not exist");
}
else
{

        fp=fopen("task.txt","wb");
        fp1=fopen("temp.txt","rb");
        while(1)
        {
            fread(&a,sizeof(a),1,fp1);
            if(feof(fp1))
            {
                break;
            }
                    fwrite(&a,sizeof(a),1,fp);
            }
fclose(fp);
fclose(fp1);
}
}

void viewtasklist()
{
struct task a;
FILE *fp;
fp=fopen("task.txt","ab");
fclose(fp);
fp=fopen("task.txt","rb");
while(1)
{
    fread(&a,sizeof(a),1,fp);

    if(feof(fp))
{
    break;
}

printf("\n%d:%s",a.no,a.details);
}
fclose(fp);
}

void date()
{
   time_t now = time(NULL);
   struct tm *t = localtime(&now);
   printf( "%d\n", t->tm_mon+1 );
   printf( "%d\n", t->tm_mday );
   printf( "%d\n", t->tm_year+1900 );
   printf( "%d\n", t->tm_hour );
   printf( "%d\n", t->tm_min );
   printf( "%d\n", t->tm_sec );

   return 0;

}


void empmain(int id)
{
int ch;
int a;
int condition=0;
int b=0;
a=id;
FILE *fp;
fp=fopen(fname,"ab");
fclose(fp);
while(1)
{
    //clrscr();
    system("cls");
    printf("\n==================Employee Management System=============\n\n");
    printf("1. Profile\n\n");
    printf("2. Task\n\n");
    printf("0. Log out\n\n");
    printf("========================================================\n\n");

    printf("\nPlease enter your Choice:");
    scanf("%d",&ch);
    system("cls");
switch(ch)
{
    case 1: empprofile(a);
    break;

    case 2: viewtask(a);
    break;

    case 0: main();
    break;

    default:
    printf("\nNot an option.");
    break;
}

//mygetch();
printf("\n(press any key to get back..)\n");
getch();
}

return 0;
}


void empprofile(int id)
{
FILE *fp;
struct emp t;
int found=0;

fp=fopen(fname,"rb");

while(1)
{
    fread(&t,sizeof(t),1,fp);

    if(feof(fp))
    {
        break;
    }
    if(t.id==id)
    {
        found=1;
        printf("\n========================================================\n\n");
        printf("\t\t Employee Details of %d\n\n",t.id);
        printf("========================================================\n\n");

    printf("Name\tSalary\tJoinDate\tShift\tTaskNO\n\n");

    printf("%s\t",t.name);
    printf("%d\t",t.salary);
    printf("%d/",t.day);
    printf("%d/",t.month);
    printf("%d\t",t.year);
    printf("%d\t",t.shift);
    printf("%d\t\n\n",t.task);

    printf("========================================================\n\n");
    }
}
    if(found==0)
    {
        printf("\nSorry No Record Found");
    }
fclose(fp);
}

void viewtask(int id)
{
    int task;
  FILE *fp;
struct emp t;
int found=0;

fp=fopen(fname,"rb");

while(1)
{
    fread(&t,sizeof(t),1,fp);

    if(feof(fp))
    {
        break;
    }
    if(t.id==id)
    {
        found=1;
        task=t.task;
        //printf("\n%d %d",task,t.task);
    }
}
    if(found==0)
    {
        printf("\nSorry No Record Found");
    }
fclose(fp);

struct task a;
FILE *fp1;
fp1=fopen("task.txt","ab");
fclose(fp1);
fp1=fopen("task.txt","rb");
while(1)
{
    fread(&a,sizeof(a),1,fp1);

    if(feof(fp1))
{
    break;
}
if(a.no==task)
{
printf("\n%d:%s",a.no,a.details);
}
}
fclose(fp1);
}
