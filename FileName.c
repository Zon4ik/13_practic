#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>




int* read_file(int* mas, int* count_nums) {
    FILE* file;
    char ch;
    

    file = fopen("File_in.txt", "r");

    // Проверка, удалось ли открыть файл
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }

    int i = 0; int ii = 1;
    char* buff = (char*)malloc(ii * sizeof(char));
    // Чтение и вывод содержимого файла
    while ((ch = fgetc(file)) != EOF) {
        if (ch != ' ' && ch != '\n') {
            buff[ii - 1] = ch;
            ii++;
            buff = (char*)realloc(buff, ii * sizeof(char));
        }
        else {
            buff[ii] = '\0';
            mas[i] = atoi(buff);
            i++;
            ii = 1;
            buff = (char*)realloc(buff, ii * sizeof(char));
        }
    }
   
    free(buff);
    fclose(file);
    *count_nums = i;
    mas = (int*)realloc(mas, *count_nums * sizeof(int));
    for(int i = 0; i < *count_nums ; i++) printf("%d ", mas[i]);
    return mas;
    
}

int* sort_mas_shake(int* mas, int count_nums) {
    int  left = 0;
    int right = count_nums - 1;
    while (left <= right) {
        for (int i = right; i > left; i--) {
            if (mas[i - 1] > mas[i]) {
                //swap(mas, i -1, i);
                int sw = mas[i - 1];
                mas[i - 1] = mas[i];
                mas[i] = sw;
            }
        }
        left++;
        for (int i = left; i < right; i++) {
            if (mas[i] > mas[i + 1]) {
                //swap(mas, i, i  + 1);
                int sw_two = mas[i];
                mas[i] = mas[i + 1];
                mas[i + 1] = sw_two;
            }
        }
        right--;
    }
    return mas;
}



int* sort_mas_radix(int* mas, int count_nums) {
    int Max = 0;
    for (int i = 0; i < count_nums; i++) {
        if (Max < mas[i]) Max = mas[i];
    }
    int count = 0;
    while (Max > 0) {
        Max /= 10;
        count++;
    }
    int** cut_mas = (char**)malloc(count_nums * sizeof(int*));
    for (int i = 0; i < count_nums; i++) {
        cut_mas[i] = (int*)malloc(count * sizeof(int));
    }
    int* mas2 = (int*)malloc(count_nums * sizeof(int));
    
    //copy massive mas to mas2
    for (int i = 0; i < count_nums; i++) {
        mas2[i] = mas[i];
    }

    for (int i = 0; i < count_nums; i++) {
        for (int j = 0; j < count; j++) {
            if (mas2[i] > 0) {
                cut_mas[i][j] = mas2[i] % 10;
                mas2[i] /= 10;
            }
            else {
                cut_mas[i][j] = 0;
            }
        }
    }
    printf("\n");
    for (int i = 0; i < count_nums; i++) {
        printf("\n");
        for (int j = 0; j < count; j++) {
            printf("%d ", cut_mas[i][j]);
        }
    }

    printf("\n\n\n123: ");
    // sorted
    int sw; int sw_c; int counter_i = 0;
    while (counter_i < count) {
        for (int i = 0; i < count_nums - 1; i++) {
            int asf = cut_mas[i][counter_i];
            int add = cut_mas[i + 1][counter_i];
            if (cut_mas[i][counter_i] > cut_mas[i + 1][counter_i]) {
                sw = mas[i];
                sw_c = cut_mas[i][counter_i];

                /*mas[i] = mas[i + 1];
                mas[i + 1] = sw;*/

                cut_mas[i][counter_i] = cut_mas[i + 1][counter_i];
                cut_mas[i + 1][counter_i] = sw_c;
            }
        }
        printf("\n\n");
        
        for (int f = 0; f < count_nums; f++) {
            printf("\n");
            for (int g = 0; g < count; g++) {
                printf("%d ", cut_mas[f][g]);
            }
        }

        
        counter_i++;
    }

    printf("\n");
    for (int i = 0; i < count_nums; i++) {
        printf("%d ", mas[i]);
    }
    

    for (int i = 0; i < count_nums; i++) {
        free(cut_mas[i]);
    }
    free(cut_mas);
    free(mas2);
    
    return mas;
}

int main() {
    setlocale(0, "");
    //count_numbers();
    int* mas = (int*)malloc(10*sizeof(int));
    int count_nums = 0;
    
    mas = read_file(mas, &count_nums);
    
    //mas = sort_mas_shake(mas, count_nums);
    mas = sort_mas_radix(mas, count_nums);

    

    printf("\n\n");
    //for (int i = 0; i < count_nums; i++) printf("%d ", mas[i]);
    free(mas);
	return 0;
}