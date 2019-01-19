 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>

 main()
 {

     FILE *fp, *ftemp;
     char more_data, choice;
     struct date
     {

         int day;
         int month;
         int year;

     };
     struct employee{
     char name[40];
     char lastname[40];
     char dept[30];
     int age;
     struct date doj;
     int emp_level;
     float salary;


     };


     struct employee e;
     char emp_name[30];
     char emp_ln[30];
     char dep[30];
     long int recsize;
     fp=fopen("C:\\EMPS.DAT","rb+");
     if(fp==NULL)
     {

         fp=fopen("C:\\EMPS.DAT","wb+");
         if(fp==NULL)
         {

             printf("Cannot open file");
             exit(1);
         }
     }

   recsize=sizeof(e);

   while(1)
   {

       system("cls");
       printf("1. Add Record \n");
       printf("2. List All Employees \n");
       printf("3. List all Employees at a particular level \n");
       printf("4. List of Employees DOJ in a particular year\n");
       printf("5. Modify Employee Records \n");
       printf("6. Delete Employee Records \n");
       printf("7. Exit \n");

       printf("Your Choice: \n");
       fflush(stdin);
       choice= getche();

       switch(choice){

   case '1':
    system("cls");
    fseek(fp,0,SEEK_END);

    more_data ='y';

    while(more_data == 'y')
    {
        printf("\n Enter name:");
        scanf("%s", e.name);
        printf("\n Enter lastname:");
        scanf("%s", e.lastname);
        printf("\n Enter name of Department:");
        scanf("%s",e.dept);

        printf("\n Enter age: ");
        scanf("%d",&e.age);
        printf("\n Enter date of joining as ddmmyy \n");
        scanf("%2d%2d%2d",&e.doj.day,&e.doj.month,&e.doj.year);

        printf("\n Enter the employee level(1-7) \n");
        scanf("%d",&e.emp_level);

        printf("\n Enter basic salary: ");
        scanf("%f",&e.salary);

        fwrite(&e,recsize,1,fp);
        printf("\n Add another record(y/n)");
        fflush(stdin);
        more_data=getche();





    }
       break;


   case '2':

    system("cls");
    printf(" Name    Lastname    Department    Age    DOJ    Level   Salary \n");
    rewind(fp);
    while(fread(&e,recsize,1,fp)==1)
    {

        printf("\n %s  %2s\t\t %2s \t%4d\t %d%d%d %6d %.2f\n",e.name,e.lastname,e.dept,e.age,e.doj.day,e.doj.month,e.doj.year,e.emp_level,e.salary);
    }
    getch();
    break;

   case '3':
    {
        int level=0;
        system("cls");
        printf("To find employees at a particular level, enter level \n");
        scanf("%d",&level);
        rewind(fp);
        while(fread(&e,recsize,1,fp)==1)
              {
                 if(e.emp_level==level)
                 printf("\n %s %2s\t\t %2s\t %4d \t %d%d%d %6d %.2f\n",e.name,e.lastname,e.dept,e.age,e.doj.day,e.doj.month,e.doj.year,e.emp_level,e.salary);
              }
                getch();


    }
    break;

   case '4':
       {int year;
       system("cls");
       printf("Enter the year of joining of the employees  in yy format:\n");
       scanf("%d",&year);
       rewind(fp);
       while(fread(&e,recsize,1,fp)==1)
       {

           if(e.doj.year==year)
            printf("\n %s %2s\t \t%2s\t %4d \t,%d%d%d %6d %.2f\n",e.name,e.lastname,e.dept,e.age,e.doj.day,e.doj.month,e.doj.year,e.emp_level,e.salary);
       }
       getch();

       }
       break;

   case '5':
    system("cls");
    more_data='y';
    while(more_data=='y')
    {

        printf("Enter the employee name to modify:");
        scanf("%s",emp_name);
        rewind(fp);
        while(fread(&e,recsize,1,fp)==1){
                if(strcmp(e.name,emp_name)==0){
                    printf("\n Enter new name:");
                    scanf("%s",e.name);
                    printf("Enter the employee level(1-7) \n");
                    scanf("%d",&e.emp_level);
                    printf("\n Enter new basic salary:");
                    scanf("%f",*&e.salary);
                    fseek(fp,-recsize,SEEK_CUR);
                    fwrite(&e,recsize,1,fp);
                    break;
                }

        }
        printf("\n Modify another record(y/n)");
        fflush(stdin);
        more_data=getche();



    }
break;

   case '6':
    {
        system("cls");
        more_data='y';
        while(more_data=='y'){
            printf("\n Enter name of employee to delete:");
            scanf("%s",emp_name);
            rewind(fp);
            ftemp=fopen("Temp.dat","wb");
            while(fread(&e,recsize,1,fp)==1)
            {

                if(strcmp(e.name,emp_name)!=0)
                {

                    fwrite(&e,recsize,1,ftemp);

                }
                fclose(fp);
                fclose(ftemp);
                remove("EMP3.DAT");
                rename("Temp.dat","EMP3.DAT");
                fp=fopen("EMP3.DAT","rb+");
                printf("Delete another record(y/n)");
                fflush(stdin);
                more_data=getche();


            }
        }


    }
break;
   case '7':
    fclose(fp);
    exit(0);



    }
   }
   return 0;
 }



