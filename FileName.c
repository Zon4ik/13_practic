#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//
//
//int main(void)
//{
//    int array[] = { 1, 6, 2, 4, 4 };
//    char string[255] = { 0 };
//
//    /*do something*/
//    
//    for (size_t i = 0; i < (sizeof(array) / sizeof(int)); i++)
//    {
//        sprintf(&string[strlen(string)], "%d ", array[i]);
//    }
//
//    printf("%s\n", string);
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int mains() {
//    int array[] = { 1, 2, 3 };
//    int length = sizeof(array) / sizeof(array[0]);
//
//    char* str = (char*)malloc(100);
//    sprintf(str, "%d", array[0]);
//
//    char* temp = (char*)malloc(1);
//    for (int i = 1; i < length; i++) {
//        sprintf(temp, " %d", array[i]);
//        strcat(str, temp);
//    }
//
//    printf("%s", str);
//
//    free(str);
//    free(temp);
//    return 0;
//}