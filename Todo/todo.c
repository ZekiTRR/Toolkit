#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_TASKS 100
#define FILENAME "todo.txt"

typedef struct {
    int id;
    char description[100];
    char due_date[11]; // YYYY-MM-DD
    int completed;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

// Function prototypes
void initialize_todo_system();
void display_main_menu();
void handle_user_choice(int choice);
void add_new_task();
void remove_task();
void mark_task_completed();
void show_all_tasks();
void display_upcoming_tasks();
void save_to_file();
void load_from_file();
void clear_input_buffer();
int validate_date_format(const char *date);
int compare_dates(const char *date1, const char *date2);



void initialize_todo_system() {
    load_from_file();
    int user_choice;
    
    do {
        display_main_menu();
        scanf("%d", &user_choice);
        clear_input_buffer();
        handle_user_choice(user_choice);
    } while (user_choice != 6);
}

void display_main_menu() {
    printf("\nTodo List Manager\n");
    printf("1. Add New Task\n");
    printf("2. Delete Task\n");
    printf("3. Mark Task as Completed\n");
    printf("4. Show All Tasks\n");
    printf("5. Display Upcoming Tasks\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void handle_user_choice(int choice) {
    switch(choice) {
        case 1: add_new_task(); break;
        case 2: remove_task(); break;
        case 3: mark_task_completed(); break;
        case 4: show_all_tasks(); break;
        case 5: display_upcoming_tasks(); break;
        case 6: printf("Exiting...\n"); break;
        default: printf("Invalid selection!\n");
    }
}

void load_from_file() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) return;

    task_count = 0;
    while (fscanf(file, "%d;%99[^;];%10[^;];%d\n", 
           &tasks[task_count].id, 
           tasks[task_count].description, 
           tasks[task_count].due_date, 
           &tasks[task_count].completed) == 4) {
        task_count++;
    }
    fclose(file);
}

void save_to_file() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error saving data!\n");
        return;
    }

    for (int i = 0; i < task_count; i++) {
        fprintf(file, "%d;%s;%s;%d\n", 
                tasks[i].id,
                tasks[i].description,
                tasks[i].due_date,
                tasks[i].completed);
    }
    fclose(file);
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int validate_date_format(const char *date) {
    if (strlen(date) != 10) return 0;
    if (date[4] != '-' || date[7] != '-') return 0;

    int year, month, day;
    if (sscanf(date, "%d-%d-%d", &year, &month, &day) != 3) return 0;
    
    if (year < 2023 || month < 1 || month > 12 || day < 1 || day > 31) return 0;
    return 1;
}

void add_new_task() {
    if (task_count >= MAX_TASKS) {
        printf("Task limit reached!\n");
        return;
    }

    Task new_task;
    new_task.id = task_count + 1;
    
    printf("Enter task description: ");
    scanf(" %99[^\n]", new_task.description);
    clear_input_buffer();

    do {
        printf("Enter due date (YYYY-MM-DD): ");
        scanf(" %10s", new_task.due_date);
        clear_input_buffer();
    } while (!validate_date_format(new_task.due_date));

    new_task.completed = 0;
    tasks[task_count++] = new_task;
    save_to_file();
    printf("Task added successfully!\n");
}

void remove_task() {
    int target_id;
    printf("Enter task ID to remove: ");
    scanf("%d", &target_id);
    clear_input_buffer();

    for (int i = 0; i < task_count; i++) {
        if (tasks[i].id == target_id) {
            for (int j = i; j < task_count - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            task_count--;
            save_to_file();
            printf("Task deleted successfully!\n");
            return;
        }
    }
    printf("Task not found!\n");
}

void mark_task_completed() {
    int target_id;
    printf("Enter task ID to mark as completed: ");
    scanf("%d", &target_id);
    clear_input_buffer();

    for (int i = 0; i < task_count; i++) {
        if (tasks[i].id == target_id) {
            tasks[i].completed = 1;
            save_to_file();
            printf("Task marked as completed!\n");
            return;
        }
    }
    printf("Task not found!\n");
}

void show_all_tasks() {
    if (task_count == 0) {
        printf("No tasks found!\n");
        return;
    }

    printf("\n%-5s %-40s %-12s %s\n", "ID", "Description", "Due Date", "Status");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < task_count; i++) {
        printf("%-5d %-40s %-12s %s\n", 
               tasks[i].id,
               tasks[i].description,
               tasks[i].due_date,
               tasks[i].completed ? "Completed" : "Pending");
    }
}

int compare_dates(const char *date1, const char *date2) {
    return strcmp(date1, date2);
}

void display_upcoming_tasks() {
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    char today[11];
    strftime(today, sizeof(today), "%Y-%m-%d", current_time);

    printf("\nUpcoming Tasks:\n");
    printf("%-5s %-40s %-12s %s\n", "ID", "Description", "Due Date", "Status");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < task_count; i++) {
        if (compare_dates(tasks[i].due_date, today) >= 0 && !tasks[i].completed) {
            printf("%-5d %-40s %-12s %s\n", 
                   tasks[i].id,
                   tasks[i].description,
                   tasks[i].due_date,
                   "Pending");
        }
    }
}