#define _CRT_SECURE_NO_WARNINGS
#include "handling_datas.h"

void checking_for_null_pointer(void* ptr) {
    if (ptr == NULL) {
        printf("sorry something wrong has happened\n");
        exit(EXIT_FAILURE);
    }
    return;
}

void load_users(User** pointer_to_list_of_users, int* size) {
    FILE* pointer_to_file = fopen("users.txt", "a+");
    fseek(pointer_to_file, 0, SEEK_SET);
    char c;
    while ((c = fgetc(pointer_to_file) != EOF)) {
        fseek(pointer_to_file, -1, SEEK_CUR);
        (*size)++;
        *pointer_to_list_of_users = (User*)realloc(*pointer_to_list_of_users, *size * sizeof(User));
        checking_for_null_pointer(*pointer_to_list_of_users);
        // read username
        char* name;
        int word_size;
        read_word_from_file(pointer_to_file, &name, &word_size);
        (*pointer_to_list_of_users + *size - 1)->username = (char*)malloc(word_size);
        checking_for_null_pointer((*pointer_to_list_of_users + *size - 1)->username);
        memcpy((*pointer_to_list_of_users + *size - 1)->username, name, word_size);
        free(name);
        // read id
        char* identity;
        read_word_from_file(pointer_to_file, &identity, &word_size);
        (*pointer_to_list_of_users + *size - 1)->id = atoi(identity);
        free(identity);
        // read password
        char* pass;
        read_word_from_file(pointer_to_file, &pass, &word_size);
        (*pointer_to_list_of_users + *size - 1)->password = (char*)malloc(word_size);
        checking_for_null_pointer((*pointer_to_list_of_users + *size - 1)->password);
        memcpy((*pointer_to_list_of_users + *size - 1)->password, pass, word_size);
        free(pass);
    }
    fclose(pointer_to_file);
    return;
}

void load_foods(Food** pointer_to_list_of_foods, int* size) {
    FILE* pointer_to_file = fopen("foods.txt", "a+");
    fseek(pointer_to_file, 0, SEEK_SET);
    char c;
    while ((c = fgetc(pointer_to_file) != EOF)) {
        fseek(pointer_to_file, -1, SEEK_CUR);
        (*size)++;
        *pointer_to_list_of_foods = (Food*)realloc(*pointer_to_list_of_foods, *size * sizeof(Food));
        checking_for_null_pointer(*pointer_to_list_of_foods);
        // read name
        char* name;
        int word_size;
        read_word_from_file(pointer_to_file, &name, &word_size);
        (*pointer_to_list_of_foods + *size - 1)->name = (char*)malloc(word_size);
        checking_for_null_pointer((*pointer_to_list_of_foods + *size - 1)->name);
        memcpy((*pointer_to_list_of_foods + *size - 1)->name, name, word_size);
        free(name);
        // read id
        char* identity;
        read_word_from_file(pointer_to_file, &identity, &word_size);
        (*pointer_to_list_of_foods + *size - 1)->id = atoi(identity);
        free(identity);
        // read price
        char* price;
        read_word_from_file(pointer_to_file, &price, &word_size);
        (*pointer_to_list_of_foods + *size - 1)->price = atoi(price);
        free(price);
        // read capacity
        char* capacity;
        read_word_from_file(pointer_to_file, &capacity, &word_size);
        (*pointer_to_list_of_foods + *size - 1)->capacity = atoi(capacity);
        free(capacity);
        // read hall id
        char* hall_id;
        read_word_from_file(pointer_to_file, &hall_id, &word_size);
        (*pointer_to_list_of_foods + *size - 1)->hall.id = atoi(hall_id);
        // read day
        char* day;
        read_word_from_file(pointer_to_file, &day, &word_size);
        (*pointer_to_list_of_foods + *size - 1)->day = atoi(day);
        free(day);
    }
    fclose(pointer_to_file);
    return;
}

void load_halls(Hall** pointer_to_list_of_halls, int* size) {
    FILE* pointer_to_file = fopen("halls.txt", "a+");
    fseek(pointer_to_file, 0, SEEK_SET);
    char c;
    while ((c = fgetc(pointer_to_file) != EOF)) {
        fseek(pointer_to_file, -1, SEEK_CUR);
        (*size)++;
        *pointer_to_list_of_halls = (Hall*)realloc(*pointer_to_list_of_halls, *size * sizeof(Hall));
        checking_for_null_pointer(*pointer_to_list_of_halls);
        // read name
        char* name;
        int word_size;
        read_word_from_file(pointer_to_file, &name, &word_size);
        (*pointer_to_list_of_halls + *size - 1)->name = (char*)malloc(word_size);
        checking_for_null_pointer((*pointer_to_list_of_halls + *size - 1)->name);
        memcpy((*pointer_to_list_of_halls + *size - 1)->name, name, word_size);
        free(name);
        // read id
        char* identity;
        read_word_from_file(pointer_to_file, &identity, &word_size);
        (*pointer_to_list_of_halls + *size - 1)->id = atoi(identity);
        free(identity);
        // read capacity
        char* capacity;
        read_word_from_file(pointer_to_file, &capacity, &word_size);
        (*pointer_to_list_of_halls + *size - 1)->capacity = atoi(capacity);
        free(capacity);
    }
    fclose(pointer_to_file);
    return;
}

void load_coupons(Coupon** pointer_to_list_of_copouns, int* size) {
    FILE* pointer_to_file = fopen("coupons.txt", "a+");
    fseek(pointer_to_file, 0, SEEK_SET);
    char c;
    while ((c = fgetc(pointer_to_file) != EOF)) {
        fseek(pointer_to_file, -1, SEEK_CUR);
        // now we have one more coupon
        (*size)++;
        *pointer_to_list_of_copouns = (Coupon*)realloc(*pointer_to_list_of_copouns, *size * sizeof(Coupon));
        checking_for_null_pointer(*pointer_to_list_of_copouns);
        // read id
        char* identity;
        int word_size;
        read_word_from_file(pointer_to_file, &identity, &word_size);
        (*pointer_to_list_of_copouns + *size - 1)->id = atoi(identity);
        free(identity);
        // read percentage
        char* percentage;
        read_word_from_file(pointer_to_file, &percentage, &word_size);
        (*pointer_to_list_of_copouns + *size - 1)->percantage = atoi(percentage);
        free(percentage);
        // read capacity
        char* capacity;
        read_word_from_file(pointer_to_file, &capacity, &word_size);
        (*pointer_to_list_of_copouns + *size - 1)->capacity = atoi(capacity);
        free(capacity);
    }
    fclose(pointer_to_file);
    return;
}

void read_word_from_file(FILE* pointer_to_file, char** word, int* word_size) {
    char letter;
    *word_size = 0;
    *word = NULL;
    while ((letter = fgetc(pointer_to_file)) != EOF && letter != '\n' && letter != ' ') {
        // getting letter each time and reallocating
        *word_size += sizeof(char);
        *word = (char*)realloc(*word, *word_size);
        checking_for_null_pointer(*word);
        *(*word + (*word_size - 1)) = letter;
    }
    *word = (char*)realloc(*word, *word_size + 1);  // just to put null at the end
    *(*word + (*word_size)) = NULL;
    (*word_size)++;
    return;
}

void freeing(User* list_of_users, int size_users, Food* list_of_foods, int size_foods, Hall* list_of_halls, int size_halls, Coupon* list_of_coupons, int size_coupons) {
    FILE* users_file = fopen("users.txt", "w");
    FILE* foods_file = fopen("foods.txt", "w");
    FILE* halls_file = fopen("halls.txt", "w");
    FILE* coupons_file = fopen("coupons.txt", "w");

    for (int i = 0; i < size_users; i++) {
        fprintf(users_file, "%s %d %s\n", (list_of_users + i)->username, (list_of_users + i)->id, (list_of_users + i)->password);
        free((list_of_users + i)->username);
        free((list_of_users + i)->password);
    }
    for (int i = 0; i < size_foods; i++) {
        fprintf(foods_file, "%s %d %d %d %d %d\n", (list_of_foods + i)->name, (list_of_foods + i)->id, (list_of_foods + i)->price, (list_of_foods + i)->capacity, (list_of_foods + i)->hall.id, (list_of_foods + i)->day);
        free((list_of_foods + i)->name);
    }
    for (int i = 0; i < size_halls; i++) {
        fprintf(halls_file, "%s %d %d\n", (list_of_halls + i)->name, (list_of_halls + i)->id, (list_of_halls + i)->capacity);
        free((list_of_halls + i)->name);
    }
    for (int i = 0; i < size_coupons; i++) {
        fprintf(coupons_file, "%d %d %d\n", (list_of_coupons + i)->id, (list_of_coupons + i)->percantage, (list_of_coupons + i)->capacity);
    }

    free(list_of_users);
    free(list_of_foods);
    free(list_of_halls);
    free(list_of_coupons);

    fclose(users_file);
    fclose(foods_file);
    fclose(halls_file);
    fclose(coupons_file);
	
    printf("wish you enjoyed, bye");
    return;
}