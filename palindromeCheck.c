#include <stdio.h>
#include <stdbool.h>

void lower(char *letter);
bool isAlphanumeric(char *letter);
// void isPalindrome(char *s[], bool *output);


int main() {
    char s[] = "A man, a plan, a canal: PANAMA!";
    int size = sizeof(s) / sizeof(s[0]) -2;
    bool output = false;

    int leftIndex = 0;
    int rightIndex = size;
    while (leftIndex < rightIndex) {
        for (int i = 0; i < size; i++) {
            lower(&s[i]);
        }
        while (!isAlphanumeric(&s[leftIndex])) leftIndex++;
        while (!isAlphanumeric(&s[rightIndex])) rightIndex--;

        if (s[leftIndex] != s[rightIndex]) {
            output = false;
            break;
        } else if (leftIndex == rightIndex) {
            output = true;
            break;
        }

        leftIndex++;
        rightIndex--;
    }

    if (output == true) {
        printf("%s is Palindrome\n", s);
    } else {
        printf("%s isn't Palindrome\n", s);
    }

    return 0;
}

void lower(char *letter)
{
   if (*letter >= 'A' && *letter <= 'Z')
       *letter= *letter + ('a' - 'A');
}

bool isAlphanumeric(char *letter)
{
    if (*letter >= 'a' && *letter <= 'z' || *letter >= '0' && *letter <= '9')
        return true;
    return false;
}

