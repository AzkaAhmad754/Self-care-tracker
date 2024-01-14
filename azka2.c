#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<unistd.h>
#ifdef _WIN32
#include <windows.h>
#endif
#define EXER_MAX 5//defined maximum number of exercises.
#define EX_NAME 18//defined the maximum length of exercise name.
#define MAXIMUM_TASK_SIZE 50
#define MAXIMUM_TASKS 100

struct Task {
    char description[MAXIMUM_TASK_SIZE];
    int completed;
};

struct Task tasks[MAXIMUM_TASKS];
int taskCount = 0;

// Function for adding tasks in the to do list
void addtoTasks() {
    if (taskCount < MAXIMUM_TASKS) {
        printf("Enter the task you'd like to do: "); // Prompting the user to enter task description
       // getchar(); // Clear newline character from buffer
        fgets(tasks[taskCount].description, MAXIMUM_TASK_SIZE, stdin);
        tasks[taskCount].description[strcspn(tasks[taskCount].description, "\n")] = '\0'; // Remove trailing newline
        
        tasks[taskCount].completed = 0; // Set the task as not completed
        taskCount++; //Incrementing the task count
        printf("The task is added successfully!\n");
    } else {
        printf("To-do list is full. You can't add more tasks.\n");
    }
}

//Function for viewing tasks in the to do list
void viewTasks() {
    if (taskCount == 0) {
        printf("There is nothing here :( Try to add tasks first.\n");
    } else {
        printf("To-Do List:\n");
        for (int i = 0; i < taskCount; i++) { // Displaying the list of tasks along with their status
            printf("%d. %s - %s\n", i + 1, tasks[i].completed ? "[DONE]" : "[TODO]", tasks[i].description);
        }
    }
}

//Function for marking tasks as completed in the to do list
void markTaskCompleted() {
    int taskNumber;
    printf("Enter task number to be marked as completed: "); // Prompting the user to input the task number to be marked as completed
    scanf("%d", &taskNumber);
    if (taskNumber > 0 && taskNumber <= taskCount) {
        tasks[taskNumber - 1].completed = 1; // Marking the selected tasks as completed
        printf("You did it! The task is marked to be completed.\n");
    } else {
        printf("Invalid task number!\n");
    }
}


void plan_exercise(char exercises[EXER_MAX][EX_NAME], int exerciseStatus[EXER_MAX]) {//A function which prints whther a tsk is done or not.
    printf("\nExercise Plan:\n");
    for (int i = 0; i < EXER_MAX; i++) {//iterate through the array 
        printf("%d. %-20s\t%s\n", i + 1, exercises[i], exerciseStatus[i] ? "[Done]" : "[Pending]");
    }
}


int main(){
    int options;
    jump1:
    printf("\n\n           |   Welcome to your personalized Self-Care Tracker   | \n");
    Sleep(300);
    printf("          \nLet's prioritize your well-being and embark on the journey of self-discovery.");
    Sleep(300);
    printf("\nLet this space be a guide on your path to a healthier, better and happier you.\nReady to kickstart your day?\n");
    Sleep(300);
    printf("______________________________________________");
    printf("\nEnter (1/2/3/4/5/6)\n1. Quote of the Day.\n_____________________\n2. To-Do List(Plan your day)\n______________________-\n3. Hydration Tracker.\n______________________\n4. Exercise Planner.\n________________________\n5. Day Checker\n.________________________\n6. Exit.\n_______________________\n");
    scanf("\n%d",&options);
    //Checks whether the input  is valid or not.
     if(options!=1 && options != 2 && options!=3 && options!=4 && options!=5 && options!=6){
        printf("\n| Invalid Input. |\n");
        goto jump1;//back to the menu.
    }
    //Incase of exit.
    if(options==6){
        printf("_____________________________________________\nOKAY BYE BYEE!\nSEE YOU LATER!\nHAVE A GOOD DAY!");//Prints a message.
        exit(0);
    }
    //Incase of option#1
    if(options==1){
        
        printf("\n_______________________________________________________________________\n");
          srand(time(NULL));
          Sleep(300);
    const char *quotes[] = {
        "| The only limit to our realization of tomorrow \nwill be our doubts of today. - F. D. Roosevelt |",
        "| In the end, we will remember not the words of our enemies,\n but the silence of our friends. - M. L. King, Jr. |",
        "| Life is what happens when you're \nbusy making other plans. - John Lennon |",
        "| The only way to do great work is \nto love what you do. - Steve Jobs |",
        "| The future belongs to those who believe\n in the beauty of their dreams. - E. Roosevelt|",
       "| Surah Al-Baqarah (2:286): Allah does not \nburden a soul beyond that it can bear...|",

        "| Surah Ash-Sharh (94:5-6): For indeed, with hardship\n [will be] ease. Indeed, with hardship [will be] ease.|",

        "| Surah Al-Ankabut (29:69):And those who strive for Us - We will surely\n guide them to Our ways. And indeed, Allah is with the doers of good.|",

        "| Surah Al-Imran (3:139): So do not weaken and do not grieve, \nand you will be superior if you are [true] believers.|",

        "| Surah Al-Baqarah (2:286):\nAllah is with those who are patient.|",

        "| Surah At-Tawbah (9:51):\nSay, 'Never will we be struck except by what Allah has\n decreed for us; He is our protector.' And upon Allah let the believers rely.|",

        "| Surah An-Najm (53:39-40):And that there is not for man except that [good] for which he strives, And that his effort is going to be seen.|"
    };

    int noOfQ = sizeof(quotes) / sizeof(quotes[0]);
    int Index = rand() % noOfQ;

    printf("Remember:\n %s\n", quotes[Index]);
    printf("\n_____________________________________________________________________________\n");
    goto jump1;
    

    }
    //Incase of option#2
    if(options==2){
        int choice;
            printf("______________________________________________________");
    printf("\n|       Welcome to your To-Do List Menu!     |\n|     What would you like to do?      |\n");
    do { // Displaying the menu options
        printf("\nPlease select the following:\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("\n%d", &choice);
        getchar();

        // Performing actions based on user's choice
        if (choice == 1){
            addtoTasks(); // Calling the function to add tasks
        } else if (choice == 2){
            viewTasks(); // Calling the function to view tasks
        } else if (choice == 3){
            markTaskCompleted(); // Calling the function to mark the tasks as completed
        } else if (choice == 4){
            printf("|    See you other time. Goodbye!    |\n"); // Exiting the program
            goto jump1;
        } else {
            printf("|  Invalid choice! Please enter a valid option.    |\n");
        }

    } while (choice != 4); // Continue the loop until user chooses to exit
    }

    //INcase options#3
    if(options==3){
        start_again://control will come back here on invalid input
    #ifdef _WIN32
    //glasses will appear for the sake o looks T-T
    printf("|       |        |       |       |       |\n");
    Sleep(300);
    printf("\\       /        \\       /       \\......./\n");
    Sleep(300);
    printf(" |     |          |.....|         |.....|\n");
    Sleep(300);
    printf(" |     |          |.....|         |.....|\n");
    Sleep(300);
    printf(" |_ _ _|            |_ _ _|          |_ _ _|  \n");
    #endif
    //starting of tracker:
    printf("________________________________________________________");
    printf("\n|   Welcome to your caring hydration tracker!!   |\n");
    printf("\nPlease set your daily Water/Hydration goal (In Glasses): ");
    //float values to be able to add decimal goals according to recommendations
    float goal, total_glasses = 0;
    scanf("%f", &goal);
   //invalid if goal input is less than 0 or greater than 50
    if (goal <= 0||goal>50) {
        printf("Please enter a valid number of glasses.\n");
        goto start_again;
    }

    printf("Your daily hydration goal is set to %.2f glasses.\n", goal);
    
    //menu:
    while (1) {
        printf("\nMenu:\n");
        printf("1. Update your daily hydration goal.\n");
        printf("2. Add the Glasses consumed.\n");
        printf("3. View current hydration.\n");
        printf("4. Recommend a hydration goal.\n");
        printf("5. Exit\n");
        
        int user_choice;
       //ask for user's choice:
        printf("Enter your choice: ");
        scanf("%d", &user_choice);
        //if user chooses option 1:
        if (user_choice == 1) {
            printf("Set your new hydration goal: ");
            scanf("%f", &goal);
            printf("Your new hydration goal is %.2f\n", goal);
        //if user chooses option 2:    
        } else if (user_choice == 2) {
            printf("Enter the number of glasses consumed: ");
            float glasses;
            scanf("%f", &glasses);
        //condition for if user enters invalid no of glasses:
            if (glasses < 0||glasses >50) {
                printf("\nPlease enter a valid number of glasses.\n\n");
                continue;
            }
            //update the no of glasses consumed:
            total_glasses += glasses;
            printf("%.2f glasses have been added. Total Number of Glasses consumed: %.2f\n", glasses, total_glasses);
            //for user input : 3, It will display the current level
        } else if (user_choice == 3) {
            printf("Your current water consumption in Glasses is: %.2f\n", total_glasses);
            //when user inputs 4, will recommend glasses no
        } else if (user_choice == 4) {
            printf("Please enter your weight in pounds: ");
            float weight;
            scanf("%f", &weight);

            float recommendation = (weight * (2.0 / 3.0)) / 8.0;
            printf("According to your weight, we recommend consuming %.2f glasses per day (where a glass is approximately 8 ounces).\n", recommendation);
        } else if (user_choice == 5) {
            goto jump1;
            //will tell user that its invald if the option is something not 1 to 5:
        } else {
            printf("Invalid choice. Please enter a valid option.\n");
            continue;
        }

    }

    }

    //INcase option#4
    if(options==4){

    int task;//a variable to store the  number of task.
    char timer;
    int mark;
    char exer[EXER_MAX][EX_NAME];//A 2-D character array 
    int exerciseStatus[EXER_MAX] = {0}; // 0: Not done, 1: Done
    jump:
    printf("\n\n");
    printf("\t\t'''Welcome to Exercise Planner!'''\nWhat do you want to do? Type(1/2/3/4)\n1.Create your own Exercise Planner.\n2.Display Suggested planner.\n3.Display Exercise Progress\n4.Exit.");
    scanf("%d",&task);
    if(task==4){
        goto jump1;
    }
    //Incase option #1
    if (task==1){
        jmps:
                printf("\nWhich exercise do you want to add?(At most 5 exercises )\n");
        for (int i = 0; i < EXER_MAX; i++) {
            printf("Exercise %d: ", i + 1);
            scanf(" %s", exer[i]);
        }
        printf("Exercises added:\n");
        for (int i = 0; i < EXER_MAX; i++) {
            printf("%d. %s\n", i + 1, exer[i]);
        }
    goto jump;  
  }

    if(task==2){
        int day;
        printf("which level do you wanna start with?\n(From: 1-5)\n");
        scanf("%d",&day);
        if(day>=1 && day<5){
        printf("""Here is your exercise plan.\n1.%d Pushups \n2.%d Squarts \n3.%d minutes Plank\n4.%d Jumping Jacks.\n5.%d Pull ups.""",day*10,day*5,day,day*15,day*7);
        goto jump;
        }
        else{
            printf("Invalid input.");
            goto jump;
        }
    }
    if (task==3){
        int qtn;
        
        jum:
        printf("HAve you added the exercises?\n(Enter 1 for yes and 0 for No.)");
        scanf("%d",&qtn);
       
        if(qtn==1){
            jumping:
        printf("Here is your Exercise Progress.");
          // Display Exercise Progress
        
        plan_exercise(exer, exerciseStatus);

        int exerciseNumber;
        printf("\nEnter the exercise number you completed (1 to %d, 0 to exit): ", EXER_MAX);
        scanf("%d", &exerciseNumber);

        if (exerciseNumber == 0) {
            goto jum;
        }

        if (exerciseNumber < 1 || exerciseNumber > EXER_MAX) {
            printf("Invalid exercise number. Please enter a number between 1 and %d.\n", EXER_MAX);
            goto jumping;
        } else {
            //prints the suggested exercise planner.

            // Mark the exercise as done
            exerciseStatus[exerciseNumber - 1] = 1;

            // Display the updated exercise plan
            plan_exercise(exer, exerciseStatus);
            goto jump;
            
        }}
        else{
            printf("Firstly add Exercises.");
            goto jmps;
            goto jumping;
            goto jump;
        }
    }

   
}
    
    
        
    
    if(options==5){
   s_tart:
   printf("How was your day on a scale of 1 to 10?\n");//ask user about their day
   int scale;
   scanf("%d",&scale);//take user input
   if(scale>=0&&scale<=10)//enter loop for values 0-10
    {
        if(scale==0){
            printf("| It couldn't have been this bad. \n But if it was, Have trust that it was for the best.\n Learn from it well.\n Better days are not far away. |");
        }
        if(scale==1)
        {
            printf("| Every journey begins with a single step.\n Today might be tough, but you're stronger than you think.\n Keep going. |");
            
        }
        if(scale==2)
        {
            printf("| Challenges are what make life interesting.\n  Overcoming them is what makes life meaningful.\n  You've got this! |");
        }
        if(scale==3)
        {
            printf("| Progress is progress, no matter how small.\n  Tomorrow is a new day and a new chance for improvement.\n  Stay positive! |");
            
        }
        if(scale==4)
        {
            printf("| Remember, you're one step closer than you were yesterday.\n Keep pushing forward with determination. |");
        }
        if(scale==5)
        {
            printf("| Embrace the journey, celebrate the progress.\n You're on the right track. Keep moving forward! |");
        }
        if(scale==6)
        {
            printf("| Your efforts are paying off. \n Keep up the momentum and believe in the power of your resilience. |");
        }
        if(scale==7)
        {
            printf("| A positive attitude can turn a difficult day into a victorious one.\n  Keep shining bright! |");
        }
        if(scale==8)
        {
            printf("| You're doing amazing things.\n Keep up the great work and\n watch how your efforts transform your life. |");
            
        }
        if(scale==9)
        {
            printf("| Almost there! Your dedication is unmatched. Continue to strive for excellence. You're unstoppable! |");
        }
        if(scale==10)
        {
            printf("| Yay ! I'm so Proud of you.\n  Stay Happy , Always.|");
            
        }
        
    }
    //prints an error message if an invalid input is entered:
    else{
        printf("Please enter a valid number from 1 to 10.\n");
        goto s_tart;//takes us back to the question
    }
    printf("\n__");
    //2nd question about users day:
    start2:
    printf("\n\nIs there something you did today to be proud of?\ny/n\n");
    
    char op_tion;
    scanf(" %c",&op_tion);//take input
    //enter if user enters y/Y:
      if(op_tion=='y'||op_tion=='Y'){
        printf("Thats Great! Keep doing great things");
      }
      //enter if user enters n/N:
       else if(op_tion=='n'||op_tion=='N')
      {
          printf("Its ok if all you did today was hold yourself together.\n That too is an Achievement.");
      }
      //if user inputs invalid option:
      else{
          printf("Invalid input. Please input Y/y/N/n\n");
          goto start2;
      }
      printf("\n__");
      //3rd question:
      printf("\nDid you achieve your daily goals of Todo-list?\n(y/n)");
     char op_tion2;
    scanf(" %c",&op_tion2);//take input:
    //if user enters y/Y:
      if(op_tion2=='y'||op_tion2=='Y'){
        printf("\nThats Great! Keep doing great things");
        goto jump1;
      }
      //if user enters n/N:
       else if(op_tion2=='n'||op_tion2=='N')
      {
          printf("\nIts ok if all you did today was hold yourself together.\n That too is an Achievement.");
          goto jump1;
      }
      //displays invalid message for invalid input.
      else{
          printf("Invalid input. Please input Y/y/N/n\n");
          goto start2;//takes command back to the question
          goto jump1;
      }
    }
    return 0;
}