//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h> 
//#include <stdlib.h> 
//#include <locale.h>
//
//void create_file() {
//    FILE* ptr;
//
//    ptr = fopen("C:\\Users\\a_naz\\source\\repos\\ConsoleApplication16\\File_h2.txt", "w");
//
//    if (ptr == NULL) {
//        printf("Error Occurred While creating a "
//            "file !");
//        exit(1);
//    }
//    fclose(ptr);
//
//    printf("File created\n\n");
//}
//
//void read_file() {
//   FILE *file;
//   char ch;
//
//   file = fopen("File_in.txt", "r");
//
//   // Проверка, удалось ли открыть файл
//   if (file == NULL) {
//      printf("Ошибка при открытии файла.\n");
//      return 1;
//   }
//
//   // Чтение и вывод содержимого файла
//   while ((ch = fgetc(file)) != EOF) {
//      printf("%c", ch);
//   }
//
//   // Закрытие файла
//   fclose(file);
//
//}
//
//void write_file() {
//    FILE* file;
//
//    // Открытие файла для записи
//    file = fopen("File_out.txt", "w");
//
//    // Проверка, удалось ли открыть файл
//    if (file == NULL) {
//        printf("Ошибка при открытии файла.\n");
//        return 1;
//    }
//
//    // Запись данных в файл
//    char* n = "2";
//    fprintf(file, n);
//    fprintf(file, "6");
//
//    // Закрытие файла
//    fclose(file);
//}
//int mains()
//{
//    setlocale(0, "");
//    write_file();
//    return 0;
//}