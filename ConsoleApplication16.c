#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



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

    // print massive
    printf("Массив: ");
    for (int i = 0; i < *count_nums; i++) printf("%d ", mas[i]);

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
    // Finde len max number
    int Max = 0;
    for (int i = 0; i < count_nums; i++) {
        if (Max < mas[i]) Max = mas[i];
    }
    int max_digits = 0;
    while (Max > 0) {
        Max /= 10;
        max_digits++;
    }

    //base SC
    int base = 10;

    //sorted elm
    int digit;
    for (int i = 0; i < max_digits; i++) {
        // Crete empty massive from 10 numbers 0 - 9 
        int** bins = (int**)malloc(base * sizeof(int*));
        for (int i = 0; i < base; i++) {
            bins[i] = (int*)malloc(1 * sizeof(int));
        }
        int* flags_elements = (int*)calloc(base, sizeof(int));

        for (int j = 0; j < count_nums; j++) {
            digit = (mas[j] / (int)pow(base, i)) % base;
            flags_elements[digit] += 1;

            bins[digit] = (int*)realloc(bins[digit], flags_elements[digit] * sizeof(int));
            bins[digit][flags_elements[digit] - 1] = mas[j];
        }

        // push to massive
        int ii = 0;
        for (int i = 0; i < base; i++) {
            for (int j = 0; j < flags_elements[i]; j++) {
                //printf("%d ", bins[i][j]);
                mas[ii] = bins[i][j];
                ii++;
            }
        }

        // Clear empty massive for seconds numbers
        free(flags_elements);
        for (int s = 0; s < base; s++) {
            free(bins[s]);
        }
        free(bins);
    }

    return mas;
}


int main() {
    setlocale(0, "");
    int* mas = (int*)malloc(10 * sizeof(int));
    int count_nums = 0;

    mas = read_file(mas, &count_nums);

    //mas = sort_mas_shake(mas, count_nums);  
    mas = sort_mas_radix(mas, count_nums);

    printf("\n\nРезультат сортировки: ");
    for (int i = 0; i < count_nums; i++) printf("%d ", mas[i]);

    free(mas);
    return 0;
}