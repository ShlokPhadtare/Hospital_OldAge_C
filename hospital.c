#include<stdio.h>
#include<string.h>
#include<unistd.h>


//Program Defination
void hospital();
void medic(int age);
void oldage(int age);


//Animations
void dot(int n);
void dot_cycle(const char *text, int times);
void only_dot(int times );
void clear_screen();




int main(void)
{
    int age,result;
    char a;
    char fname[50], lname[50];
    char option;




    do{
        clear_screen();

    printf("\n\n\tWelcome!\n1) Hospital\n2) Applications History\n3) About\n4) Exit \n\nEnter your choice: ");
    scanf(" %c",&option);

    switch (option)
    {
    case '1':
    
        hospital();
        sleep(3);
        clear_screen();
        break;
   
   

        case '2':
         {

            clear_screen();
    char input[20];
    char encrypted[20];
    const char correct[] = "}rvyu;<="; 

    printf("Enter Admin Password: ");
    scanf("%19s", input);

    // Encrypt user input
    for (int i = 0; input[i] != '\0'; i++) {
        encrypted[i] = input[i] + 10;
    }
    encrypted[strlen(input)] = '\0';  // Null terminate

    if (strcmp(encrypted, correct) == 0) 
    {
       do
       { char a;
        printf("\n\n1) Hospital Data\n2) Old Age Home Data\n3) Exit (Menu)\nEnter choice: ");
        while ((getchar()) != '\n');  // clear input buffer before reading char
        scanf("%c", &a);

        FILE *fp = NULL;
        if(a == '1')
        {
            fp = fopen("hospital.txt", "r");
        }
        else if(a == '2')
        {
            fp = fopen("applications.txt", "r");
        }
        else
        {
            printf("Invalid choice.\n");
            break;
        }

        if (fp == NULL) {
            printf("\nNo applications found.\n");
        } 
        else 
        {
            clear_screen();
            printf("\n--- Application History ---\n\n");
            char line[150];
            while (fgets(line, sizeof(line), fp))
            {
                printf("%s", line);
            }
            fclose(fp);
            
        }
    }while (a!='3');
        
    
    }
    else 
    {
        clear_screen();
        printf("\n❌ Incorrect password.\n");
        sleep(2);
    }
    break;
}




    case '3':
    clear_screen();
    printf("\n--- About This Program ---\n");
    printf("This is a C-based application that simulates an Old Age Home Admission system.\n");
    printf("It includes user validation, terminal animations, and file-based data storage.\n");
    printf("Created by Shlok for a practice project.\n\n");
    only_dot(10);
    
    break;



   case '4':
   clear_screen();
    printf("\nExiting... Goodbye!\n");
    dot(5);
   clear_screen();
    break;
    
    default:
    printf("\nPlease enter correct option!\n");
        break;
    }

}while (option!='4');






    return 0;
}













void hospital()
{
     int age,result;

    do {
    printf("\nEnter Your Age: ");
    result = scanf("%d", &age);

    if (result != 1) { 
        
        printf("Invalid input. Please enter a number!\n");

        
        while (getchar() != '\n'); 
    }
} while (result != 1 || age <= 0);
    


    if(age>120)
    {
        printf("\n\n\t\t\033[1;37mYou can't be Alive!\n\n\t\tAge: %d\033[0m\n\n",age);
    }
    else if (age>60)
    {
        oldage(age);
    }
    
    
    else
    {   
        medic(age);
    }
    
}






void oldage(int age)
{


    int result;
    char a;
    char fname[50], lname[50];


        sleep(1);
    printf("Loading");
    dot(3);
    dot_cycle("Validating", 3);

    
    printf("Verifying your age");
    dot(4);
    
    printf("\n\n");

    usleep(1000);

    
    
        printf("\n\n\t  ---Welcome to---");
        printf("\n\n\t==================\n");
        printf("    \t\033[44m   Old Age Home   \033[0m");
        printf("\n  \t==================\n\n\n");
        printf("You are eligible to apply\n\n");
        do{
                printf("Do you want continue filling Application Form? (y/n): ");
                scanf(" %c",&a);
            }
            while (a !='y' && a!='Y' && a!='n' && a!='N');
        
        if(a == 'y' || a == 'Y')
        {
            printf("\n\nEnter your First Name: ");
            scanf("%49s",fname);
        
            printf("Enter your Last Name: ");
            scanf("%49s",lname);

            printf("\n\n\t---Your Info---\n\n\nName: %s %s \n Age: %d\n\n",fname,lname,age);
            printf("T&C (can be accessed by entering 1)\n\n\n\n\n");

            do {
    
                printf("\nAgree and SUBMIT the info? (y/n): ");
    
                scanf(" %c", &a);
                
                if (a=='1')
                 {
                    printf("After your death we will have full rights\n1) On your whole life savings and\n2) Your body organs\n3) And whatever you have \n");
                        printf("All will be organisation's property on it\n\n");
                 }

    
                else if (a !='y' && a!='Y' && a!='n' && a!='N')
                 { 
                    printf("Invalid input... Please enter y/n: \n");
                    while (getchar() != '\n'); 
                }
            } while (a !='y' && a!='Y' && a!='n' && a!='N');


           if (a=='y' || a=='Y')
            {
                dot(3);

                dot_cycle("Preparing",5);

                
                printf("\n\n[\033[1;36m     submitting    ]\033[0m");
                printf("\r  ");
                
                for (int i = 0; i < 3;i++)
                {
                    printf("\033[42m \033[0m");
                    fflush(stdout);
                    usleep(1000000);
                    
                }
                 for (int i=0; i < 15;i++)
                {
                    printf("\033[42m \033[0m");
                    fflush(stdout);
                    usleep(100000);
                    
                }
                printf("\033[42m \033[0m");


                printf("\n\n");
                sleep(1);
                printf("\n=============================\n");

                printf("   ✅ Application Submitted   \n");

                printf("=============================\n\n");

                
                
                FILE *fp = fopen("applications.txt", "a");
                if (fp != NULL) {
                    fprintf(fp, "Name: %s %s | Age: %d\n", fname, lname, age);
                    fclose(fp);
                    printf("\n✅ Info saved to file successfully!\n");
                } else {
                    printf("\n❌ Error saving file!\n");
                }

            }


        }
        else
        {
            printf("\n\nThank You!\n");
        }
}


void medic(int age)
{
    char a;
    char opt;
    char fname[20],lname[20];

    printf("\n\n--Welcome to ABC Hospital---\n\n\n");

    printf("Enter Your First Name: ");
    scanf("%19s",&fname);
    printf("Enter Your Last Name: ");
    scanf("%19s",&lname);

    printf("\n\n\n\t--Your Info--\n\nName: %s %s\nAge:%d",fname,lname,age);
    printf("\n\nDo you want to continue applying (y/n): ");
    scanf(" %c",&a);

    if (a=='y' || a=='Y')
    {
    
    printf("\n\nReason of visiting\n\n\n");
    printf("1) Regular Health Checkup\n");
    printf("2) Viral Infection\n");
    printf("3) Emergency Care\n4) Chronic Illness Management\n5) Follow-up Appointment\n6) Vaccination\n7) Specialist Consultation\n8) Prescription Refill\n");
    

    printf("Enter anything if you are at wrong place.\n");
    printf("\n\nEnter the option number that best describes your visit: ");
    scanf(" %c",&opt);

    const char *reason;
    switch (opt)
    {
    case '1': reason = "Routine Health Checkup"; break;
        case '2': reason = "Flu or Viral Infection"; break;
        case '3': reason = "Emergency Care"; break;
        case '4': reason = "Chronic Illness Management"; break;
        case '5': reason = "Follow-up Appointment"; break;
        case '6': reason = "Vaccination"; break;
        case '7': reason = "Specialist Consultation"; break;
        case '8': reason = "Prescription Refill"; break;

    
    default:
    printf("\nInvalid option or wrong place selected.\n");
        break;

    }

    printf("\nAgree and SUBMIT the info? (y/n): ");
    
                scanf(" %c", &a);
    if (a=='y' || a=='Y')
            {
                dot(3);

                dot_cycle("Preparing",5);

                
                printf("\n\n[\033[1;36m     submitting    ]\033[0m");
                printf("\r  ");
                
                for (int i = 0; i < 3;i++)
                {
                    printf("\033[42m \033[0m");
                    fflush(stdout);
                    usleep(1000000);
                    
                }
                 for (int i=0; i < 15;i++)
                {
                    printf("\033[42m \033[0m");
                    fflush(stdout);
                    usleep(100000);
                    
                }
                printf("\033[42m \033[0m");


                printf("\n\n");
                sleep(1);
                printf("\n=============================\n");

                printf("   ✅ Application Submitted   \n");

                printf("=============================\n\n");


    FILE *fp = fopen("hospital.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "Name: %s %s | Age: %d | Reason: %s\n", fname, lname, age, reason);
        fclose(fp);
        printf("\n✅ Info saved to file successfully!\n");
    } else {
        printf("\n❌ Error saving file!\n");
    }
}

}
}





void dot(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(".");
        fflush(stdout);
        usleep(300000);
    }
    
}

void dot_cycle(const char *text, int times ) 
{
    for (int i = 0; i < times; i++) 
    {
        printf("\r%s",text);  
        for (int j = 0; j <= i % 3; j++) 
        {
            printf(".");
        }
        fflush(stdout);
        usleep(500000);
    }
    printf("\n");
}

void only_dot(int times ) 
{
    for (int i = 0; i < times; i++) 
    {

        printf("\r");
        for (int j = 0; j <= i % times; j++) {
            printf(".");
        }
        fflush(stdout);
        usleep(500000);
    }
    printf("\n");
}



void clear_screen()
 {
    printf("\033[2J\033[H");
    fflush(stdout);
}
