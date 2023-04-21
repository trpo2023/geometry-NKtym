#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include <libgeometry/Error.h>

#define ZEROASCII 48
#define NINEASCII 57

int circle_check(char* str)
{
    int flag = 1;
    char data[40];
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] != '(') {
            data[i] = tolower(str[i]);
        } else
            break;
    }
    char figure[] = "circle";
    if (strcmp(data, figure) == 0) {
        flag = 0;
    }
    return flag;
}

int open_bracket_check(char* str)
{
    int flag = 1;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] != '(')
            continue;
        else {
            flag = 0;
            break;
        }
    }
    return flag;
}

int arguments_check(char* str)
{
    int flag = 1;
    int data = 0;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == '(') {
            data = i;
            break;
        }
    }
    for (size_t i = data + 1; i < strlen(str) - 2; i++) {
        if ((str[i] >= ZEROASCII && str[i] <= NINEASCII) || str[i] == '.'
            || str[i] == ',' || str[i] == ' ')
            flag = 0;
        else {
            flag = 1;
            break;
        }
    }
    for (size_t i = data + 1; i < strlen(str) - 1; i++) {
        if (str[i] == '.'
            && ((str[i + 1] < ZEROASCII || str[i + 1] > NINEASCII)
                || (str[i - 1] < ZEROASCII || str[i - 1] > NINEASCII)))
            flag = 1;
        else if (
                str[i] == ',' && (str[i + 1] != ' ')
                && (str[i - 1] < ZEROASCII && str[i - 1] > NINEASCII))
            flag = 1;
    }
    return flag;
}

int center_radius_check(char* str)
{
    int flag = 1;
    int data = 0;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == '(') {
            data = i;
            break;
        }
    }
    int cnt = 0;
    for (size_t i = data + 1; i < strlen(str) - 2; i++) {
        if (str[i] >= ZEROASCII && str[i] <= NINEASCII)
            cnt++;
        else if (str[i] == '.')
            cnt--;
        if (cnt > 3)
            flag = 1;
        else
            flag = 0;
        if (str[i] == ',') {
            if (cnt != 2) {
                flag = 1;
                break;
            } else
                cnt = 0;
        }
        if (str[i + 1] == ')') {
            if (cnt != 1) {
                flag = 1;
                break;
            }
        }
    }
    return flag;
}

int correct_number_check(char* str)
{
    int flag = 1;
    int data = 0;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == '(') {
            data = i;
            break;
        }
    }
    int cnt = 0;
    for (size_t i = data + 1; i < strlen(str) - 2; i++) {
        if (str[i] >= ZEROASCII && str[i] <= NINEASCII) {
            for (int j = i; str[j] != ' ' && str[j] != ')' && str[j] != ','; j++) {
                if (str[j] == '.')
                    cnt++;
            }
        }
        if (cnt > 2) {
            flag = 1;
            return flag;
        } else
            flag = 0;
    }
    return flag;
}

int comma_check(char* str)
{
    int flag = 1;
    int data = 0;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == '(') {
            data = i;
            break;
        }
    }
    for (size_t i = data + 1; i < strlen(str) - 2; i++) {
        if (str[i] == ',') {
            flag = 0;
        } else {
            continue;
        }
    }
    return flag;
}

int close_bracket_check(char* str)
{
    int flag = 1;
    int bracket = 0;
    long int ending = strlen(str) - 2;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == ')') {
            bracket = i;
            break;
        }
    }
    if (bracket == ending || bracket == ending + 1)
        flag = 0;
    return flag;
}
