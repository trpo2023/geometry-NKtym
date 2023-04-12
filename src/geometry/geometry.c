#include <ctype.h>
#include <libgeometry/Error.h>
#include <libgeometry/SP.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE* file = fopen("geom.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла");
        return -1;
    }
    char str[40];
    int cnt = 1;
    fgets(str, 40, file);
    if (figure(str)) {
        printf("Неправильное название фигуры в %d строке %s\n", cnt, str);
        if (first(str))
            printf("Конкретная ошибка:Ошибка открывающей скобки\n");
    } else if (arg(str))
        printf("Неправильно введены координаты в %d строке %s\n", cnt, str);
    else if (num(str))
        printf("Неправильная передача аргументов в %d строке %s\n", cnt, str);
    else if (flout(str))
        printf("Неправильная запись дробного аргумента в %d строке %s\n",
               cnt,
               str);
    else if (sumbol(str))
        printf("Неправильная постановка запятой в %d строке %s\n", cnt, str);
    else if (end(str))
        printf("Ошибка завершающей скобки в %d строке %s\n", cnt, str);
    else {
        printf("%s", str);
        circle* circles = (circle*)malloc(sizeof(circle));
        double rad = radius(str);
        printf("Radius:%.1f\n", rad);
        circles->r = rad;
        int s = area(rad);
        int p = perimeter(rad);
        printf("Area:%d\nPerimeter:%d\n", s, p);
    }
    for (long unsigned int i = 0; i < strlen(str); i++) {
        if (str[i] == '\n' && fgets(str, 40, file) != NULL) {
            cnt++;
            if (figure(str)) {
                printf("Неправильное название фигуры во %d строке %s\n",
                       cnt,
                       str);
                if (first(str))
                    printf("Конкретная ошибка:Ошибка открывающей скобки\n");
            } else if (arg(str))
                printf("Неправильно введены координаты во %d строке %s\n",
                       cnt,
                       str);
            else if (num(str))
                printf("Неправильная передача аргументов во %d строке %s\n",
                       cnt,
                       str);
            else if (flout(str))
                printf("Неправильная запись дробного аргумента во %d строке "
                       "%s\n",
                       cnt,
                       str);
            else if (sumbol(str))
                printf("Неправильная постановка запятой во %d строке %s\n",
                       cnt,
                       str);
            else if (end(str))
                printf("Ошибка завершающей скобки во %d строке %s\n", cnt, str);
            else {
                printf("\n%s", str);
                circle* circles = (circle*)malloc(sizeof(circle));
                double rad = radius(str);
                printf("Radius: %.1f \n", rad);
                circles->r = rad;
                int s = area(rad);
                int p = perimeter(rad);
                printf("Area:%d\nPerimeter:%d\n", s, p);
            }
            i = 0;
        }
    }
    fclose(file);
    return 0;
}
