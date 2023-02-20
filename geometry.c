#include <stdio.h>
#include <string.h>
int Figur(char *str) {
  int flag = 1;
  char data[100];
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] != '(')
      data[i] = str[i];
    else
      break;
  }
  char figure[] = "circle";
  if (strcmp(data, figure) == 0) {
    flag = 0;
  }
  return flag;
}
int Arg(char *str) {
  int flag = 1;
  int data;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == '(') {
      data = i;
      break;
    }
  }
  for (int i = data + 1; i < strlen(str) - 1; i++) {
    if ((str[i] >= 48 && str[i] <= 57) || str[i] == '.' || str[i] == ',' ||
        str[i] == ' ')
      flag = 0;
    else {
      flag = 1;
      break;
    }
  }
  for (int i = data + 1; i < strlen(str) - 1; i++) {
    if (str[i] == '.' && (str[i + 1] < 48 && str[i + 1] > 57) && (str[i - 1] < 48 && str[i - 1] > 57))
      flag = 1;
    else if(str[i]==' ' && (str[i+1]<48 && str[i+1]>57) && ((str[i-1]<48 && str[i-1]>57)||str[i-1]!=','))
      flag = 1;
    else if(str[i]==',' && (str[i+1]!=' ') && (str[i-1]<48 && str[i-1]>57))
      flag = 1;
  }
  return flag;
}
int End(char *str) {
  int flag = 1;
  int bracket = 0;
  long int ending = strlen(str) - 1;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == ')') {
      bracket = i;
      break;
    }
  }
  if (bracket == ending)
    flag = 0;
  return flag;
}
int main() {
  FILE *file;
  file = fopen("geom.txt", "r");
  char str[40];
  fgets(str, 40, file);
  if (Figur(str))
    printf("Неправильный ввод названия объекта\n");
  else if (Arg(str))
    printf("Неправильно введены координаты объекта\n");
  else if (End(str))
    printf("Неправильный завершающий символ\n", strlen(str) - 1);
  else
    printf("%s\n", str);
  fclose(file);
  return 0;
}
