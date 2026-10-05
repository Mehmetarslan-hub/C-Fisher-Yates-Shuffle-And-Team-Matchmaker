#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 50

/* Function Prototypes */
void fisher_yates_shuffle(char **array, int size);
void create_and_print_groups(char **array, int total_elements, int group_size);
void free_student_list(char **array, int size);

int main() {
    srand((unsigned int)time(NULL));

    const char *default_names[] = {
        "Ahmet", "Mehmet", "Ali", "Murat", "Veli",
        "Suleyman", "Abdullah", "Orhan", "Murathan", "Oguzhan",
        "Tugrul", "Emin", "Ismet", "Ozgur", "Zeynep",
        "Sila", "Beyza", "Selim", "Mahmut", "Elif",
        "Esin", "Hilal", "Derin", "Sevgi", "Asiye"
    };
    int total_students = 25;
    int group_size = 4; // Default team size

    printf("==================================================\n");
    printf("   FISHER-YATES SHUFFLE & TEAM MATCHMAKER (C)\n");
    printf("==================================================\n");

    // Allocate memory for array of string pointers
    char **students = (char **)malloc(total_students * sizeof(char *));
    if (!students) {
        printf("[ERROR] Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < total_students; i++) {
        students[i] = (char *)malloc(MAX_NAME_LEN * sizeof(char));
        strncpy(students[i], default_names[i], MAX_NAME_LEN - 1);
        students[i][MAX_NAME_LEN - 1] = '\0';
    }

    printf("\n[1] Original List Loaded (%d students).\n", total_students);

    // Apply O(n) Fisher-Yates Shuffle
    fisher_yates_shuffle(students, total_students);
    printf("[2] Applied Fisher-Yates Shuffle algorithm successfully.\n");

    // Divide into automated teams
    printf("\n[3] Generating Randomized Teams (Team Size: %d):\n", group_size);
    create_and_print_groups(students, total_students, group_size);

    // Free allocated dynamic memory
    free_student_list(students, total_students);
    printf("\n[INFO] All dynamic memory deallocated.\n");

    return 0;
}

void fisher_yates_shuffle(char **array, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Pick random index from 0 to i
        
        // Swap pointers
        char *temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void create_and_print_groups(char **array, int total_elements, int group_size) {
    int group_number = 1;
    
    printf("--------------------------------------------------\n");
    printf(" Group %d: ", group_number);

    for (int i = 0; i < total_elements; i++) {
        printf("%s", array[i]);

        // If not the last element of the group, add separator
        if ((i + 1) % group_size != 0 && i != total_elements - 1) {
            printf(" | ");
        }

        // Start new group
        if ((i + 1) % group_size == 0 && i != total_elements - 1) {
            group_number++;
            printf("\n Group %d: ", group_number);
        }
    }
    printf("\n--------------------------------------------------\n");
}

void free_student_list(char **array, int size) {
    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);
}