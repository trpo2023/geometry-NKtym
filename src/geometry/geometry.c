#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <libgeometry/Error.h>
#include <libgeometry/SP.h>

int main()
{
    FILE* file = fopen("geom.txt", "r");
    circle* figur[3];
    if (file == NULL) {
        printf("Ошибка открытия файла");
        return -1;
    }
    char str[40];
    int cnt = 1;
    fgets(str, 40, file);
    if (circle_check(str)) {
        printf("Неправильное название фигуры в %d строке %s\n", cnt, str);
        if (open_bracket_check(str))
            printf("Конкретная ошибка:Ошибка открывающей скобки\n");
    } else if (arguments_check(str))
        printf("Неправильно введены координаты в %d строке %s\n", cnt, str);
    else if (center_radius_check(str))
        printf("Неправильная передача аргументов в %d строке %s\n", cnt, str);
    else if (correct_number_check(str))
        printf("Неправильная запись дробного аргумента в %d строке %s\n",
               cnt,
               str);
    else if (comma_check(str))
        printf("Неправильная постановка запятой в %d строке %s\n", cnt, str);
    else if (close_bracket_check(str))
        printf("Ошибка завершающей скобки в %d строке %s\n", cnt, str);
    else {
        printf("%s", str);
        circle* circles = (circle*)malloc(sizeof(circle));
        double rad = radius(str);
        double cordx = coordinatesx(str);
        double cordy = coordinatesy(str);
        printf("Radius:%.1f X:%.1f Y:%.1f\n", rad, cordx, cordy);
        circles->r = rad;
        circles->x = cordx;
        circles->y = cordy;
        int s = area(rad);
        int p = perimeter(rad);
        printf("Area:%d\nPerimeter:%d\n", s, p);
        figur[0] = circles;
    }
    for (long unsigned int i = 0; i < strlen(str); i++) {
        if (str[i] == '\n' && fgets(str, 40, file) != NULL) {
            cnt++;
            if (circle_check(str)) {
                printf("Неправильное название фигуры во %d строке %s\n",
                       cnt,
                       str);
                if (open_bracket_check(str))
                    printf("Конкретная ошибка:Ошибка открывающей скобки\n");
            } else if (arguments_check(str))
                printf("Неправильно введены координаты во %d строке %s\n",
                       cnt,
                       str);
            else if (center_radius_check(str))
                printf("Неправильная передача аргументов во %d строке %s\n",
                       cnt,
                       str);
            else if (correct_number_check(str))
                printf("Неправильная запись дробного аргумента во %d строке "
                       "%s\n",
                       cnt,
                       str);
            else if (comma_check(str))
                printf("Неправильная постановка запятой во %d строке %s\n",
                       cnt,
                       str);
            else if (close_bracket_check(str))
                printf("Ошибка завершающей скобки во %d строке %s\n", cnt, str);
            else {
                printf("\n%s", str);
                circle* circles = (circle*)malloc(sizeof(circle));
                double rad = radius(str);
                double cordx = coordinatesx(str);
                double cordy = coordinatesy(str);
                printf("Radius:%.1f X:%.1f Y:%.1f\n", rad, cordx, cordy);
                circles->r = rad;
                circles->x = cordx;
                circles->y = cordy;
                int s = area(rad);
                int p = perimeter(rad);
                printf("Area:%d\nPerimeter:%d\n", s, p);
                figur[cnt - 1] = circles;
            }
            i = 0;
        }
    }
    long unsigned int n = sizeof(figur) / sizeof(figur[0]);
    printf("\nTest\n");
    for (long unsigned int i = 0; i < n; i++) {
        printf("%.1lf %.1lf %.1lf \n", figur[i]->x, figur[i]->y, figur[i]->r);
    }
    if (intersection(figur, n))
        printf("Фигуры пересекаются\n");
    else
        printf("Фигуры не пересекаются\n");
    fclose(file);
    return 0;
}
