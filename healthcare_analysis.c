#include <stdio.h>
#include <time.h>

int main()
{
    int choice;

    printf("INTEGRATED SMART HEALTHCARE SYSTEM\n");
    printf("1. Health Analysis Module\n");
    printf("2. Emergency Response Module\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    time_t t;
    struct tm *tm_info;
    char date[20];

    time(&t);
    tm_info = localtime(&t);
    strftime(date, 20, "%d-%m-%Y", tm_info);

    if(choice == 1)
    {
        FILE *fp;
        char name[50], blood[10], city[30];
        char existing;
        int age;
        int risk = 0;
        char cont;
        int symptom[10];
        int severity[10];
        int count = 0;

        printf("\nHEALTH ANALYSIS MODULE\n");
        printf("Are you an existing patient? (y/n): ");
        scanf(" %c", &existing);

        if(existing == 'n' || existing == 'N')
        {
            printf("\n--- NEW PATIENT REGISTRATION ---\n");

            printf("Enter Patient Name: ");
            scanf(" %[^\n]", name);

            printf("Enter Age: ");
            scanf("%d", &age);

            printf("Enter Blood Group: ");
            scanf("%s", blood);

            printf("Enter City: ");
            scanf("%s", city);

            fp = fopen("patients.txt", "a");

            fprintf(fp, "\nDate: %s\n", date);
            fprintf(fp, "Name: %s\n", name);
            fprintf(fp, "Age: %d\n", age);
            fprintf(fp, "Blood Group: %s\n", blood);
            fprintf(fp, "City: %s\n", city);
            fprintf(fp, "--\n");

            fclose(fp);

            printf("Patient Registered Successfully!\n");
        }
        else
        {
            char ch;
            fp = fopen("patients.txt", "r");

            if(fp == NULL)
            {
                printf("No Records Found.\n");
            }
            else
            {
                printf("\n--- PATIENT RECORD ---\n");
                while((ch = fgetc(fp)) != EOF)
                {
                    printf("%c", ch);
                }
                fclose(fp);
            }

            printf("\nEnter Patient Name: ");
            scanf(" %[^\n]", name);

            printf("Enter Age: ");
            scanf("%d", &age);
        }

        do {
            printf("\nSelect Symptom:\n");
            printf("1. Fever\n2. Cough and Cold\n3. Headache\n4. Stomach Pain\n");
            printf("5. Skin Problems\n6. Eye Irritation\n7. Chest Pain\n");
            printf("8. Joint Pain\n9. Breathing Difficulty\n10. Tooth Pain\n");

            printf("\nEnter symptom: ");
            scanf("%d", &symptom[count]);

            printf("Enter Severity (1-Mild, 2-Moderate, 3-Severe, 4-Critical): ");
            scanf("%d", &severity[count]);

            if(severity[count] < 1 || severity[count] > 4)
            {
                printf("Invalid severity.\n");
                continue;
            }

            if(symptom[count] == 7 || symptom[count] == 9)
                risk += severity[count] * 2;
            else
                risk += severity[count];

            count++;

            printf("Add another symptom? (y/n): ");
            scanf(" %c", &cont);

        } while(cont == 'y' || cont == 'Y');

        printf("\nFINAL HEALTH REPORT\n");
        printf("Date: %s\n", date);
        printf("Patient: %s\n", name);
        printf("Age: %d\n", age);
        printf("Risk : %d\n", risk);

        if(risk <= 3)
            printf("Risk Level: LOW\n");
        else if(risk <= 7)
            printf("Risk Level: MODERATE\n");
        else
            printf("Risk Level: HIGH\n");


if(risk >= 8){
    printf("Advice: Visit doctor immediately.\n");
}
else if(risk >= 4){
    printf("Advice: Visit doctor soon.\n");
}
else{
    printf("Advice: Monitor symptoms and rest.\n");
}

for(int i = 0; i < count; i++)
{
    printf("\nCase %d:\n", i+1);

    if(symptom[i] == 1)
    {
        printf("Condition: Fever\n");
        printf("Suggested Medicine: Paracetamol\n");
        printf("Doctor: General Physician\nRoom: 101\n");
        printf("Precautions: Drink fluids, Rest properly, Monitor temperature.\n");
    }
    else if(symptom[i] == 2)
    {
        printf("Condition: Cough and Cold\n");
        printf("Suggested Medicine: Cetirizine / Cough Syrup\n");
        printf("Doctor: ENT Specialist\nRoom: 102\n");
        printf("Precautions: Avoid cold food, Steam inhalation, Stay warm.\n");
    }
    else if(symptom[i] == 3)
    {
        printf("Condition: Headache\n");
        printf("Suggested Medicine: Ibuprofen\n");
        printf("Doctor: Neurologist\nRoom: 201\n");
        printf("Precautions: Reduce screen time, Proper sleep, Hydration.\n");
    }
    else if(symptom[i] == 4)
    {
        printf("Condition: Stomach Pain\n");
        printf("Suggested Medicine: Antacid / ORS\n");
        printf("Doctor: Gastroenterologist\nRoom: 202\n");
        printf("Precautions: Avoid spicy food, Drink clean water.\n");
    }
    else if(symptom[i] == 5)
    {
        printf("Condition: Skin Problem\n");
        printf("Suggested Medicine: Antifungal / Calamine Lotion\n");
        printf("Doctor: Dermatologist\nRoom: 301\n");
        printf("Precautions: Maintain hygiene, Avoid Allergens.\n");
    }
    else if(symptom[i] == 6)
    {
        printf("Condition: Eye Irritation\n");
        printf("Suggested Medicine: Lubricating Eye Drops\n");
        printf("Doctor: Ophthalmologist\nRoom: 302\n");
        printf("Precautions: Avoid rubbing eyes, Limit screen time.\n");
    }
    else if(symptom[i] == 7)
    {
        printf("Condition: Chest Pain\n");
        printf("Suggested Medicine: Immediate medical evaluation needed\n");
        printf("Doctor: Cardiologist\nRoom: 401\n");
        printf("Precautions: Do NOT ignore, Visit hospital immediately.\n");
    }
    else if(symptom[i] == 8)
    {
        printf("Condition: Joint Pain\n");
        printf("Suggested Medicine: Pain reliever / Calcium supplements\n");
        printf("Doctor: Orthopedic\nRoom: 402\n");
        printf("Precautions: Light exercise, Avoid strain.\n");
    }
    else if(symptom[i] == 9)
    {
        printf("Condition: Breathing Difficulty\n");
        printf("Suggested Medicine: Inhaler (if prescribed)\n");
        printf("Doctor: Pulmonologist\nRoom: 501\n");
        printf("Precautions: Seek emergency care if severe.\n");
    }
    else if(symptom[i] == 10)
    {
        printf("Condition: Tooth Pain\n");
        printf("Suggested Medicine: Pain reliever\n");
        printf("Doctor: Dentist\nRoom: 502\n");
        printf("Precautions: Avoid sweets, Maintain oral hygiene.\n");
    }
    else
    {
        printf("Invalid Entry.\n");
    }
}
    }

    else if(choice == 2)
    {
        int type, severity;

        printf("Emergency Types:\n");
        printf("1.Accident\n2.Fire\n3.Cardiac Arrest\n4.General Emergency\n5.Seizures\n");
        printf("Enter your Emergency Type: ");
        scanf("%d", &type);

        printf("Severity Type (1-5): ");
        scanf("%d", &severity);

        printf("\nEMERGENCY REPORT:\n");

        switch(type)
        {
            case 1:
                printf("Emergency Type: Accident\nControl Bleeding.\nDo not move injured person.\n");
                break;
            case 2:
                printf("Emergency Type: Fire\nCover burns.\nMove away from fire.\n");
                break;
            case 3:
                printf("Emergency Type: Cardiac Arrest\nStart CPR.\n");
                break;
            case 4:
                printf("Emergency Type: General Emergency\nMonitor condition.\n");
                break;
            case 5:
                printf("Emergency Type: Seizures\nRemove sharp objects.\n");
                break;
            default:
                printf("Invalid.\n");
        }

        if(severity == 5)
            printf("Priority : CRITICAL\n");
        else if(severity >= 3)
            printf("Priority : HIGH\n");
        else if(severity == 2)
            printf("Priority : MEDIUM\n");
        else
            printf("Priority : LOW\n");

        printf("Emergency Dispatched Successfully\n");
    }

    else
    {
        printf("Invalid Choice.\n");
    }

    return 0;
}
