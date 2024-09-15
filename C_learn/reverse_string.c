#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 输入一串字符串，对字符串进行翻转，并找到反转后的字符串的第一个不重复的字符输出:
//反转后的字符串及反转后的字符串的第一个不重复的字符


// 函数用于反转字符串
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// 函数用于找到反转后的字符串的第一个不重复的字符
char findFirstNonRepeatingChar(const char *str) {
    int charCount[256] = {0}; // 用来记录每个字符出现的次数
    for (int i = 0; str[i]; ++i) {
        charCount[(unsigned char)str[i]]++;
    }
    
    for (int i = 0; str[i]; ++i) {
        if (charCount[(unsigned char)str[i]] == 1) {
            return str[i];
        }
    }
    return '\0'; // 如果没有不重复的字符，返回空字符
}

int main() {
    // char input[] = "abacabad";
    char input[100]; // 假设输入不会超过100个字符
    printf("Please enter a string: ");
    fgets(input, sizeof(input), stdin); // 从输入流读取一行数据

    // 去除末尾的换行符
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    char *reversedStr = strdup(input); // 使用 strdup 复制字符串以便修改
    
    if (reversedStr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // 反转字符串
    reverseString(reversedStr);

    // 找到第一个不重复的字符
    char firstNonRepeatingChar = findFirstNonRepeatingChar(reversedStr);

    // 输出结果
    printf("Original string: %s\n", input);
    printf("Reversed string: %s\n", reversedStr);
    if (firstNonRepeatingChar != '\0') {
        printf("First non-repeating character in the reversed string: '%c'\n", firstNonRepeatingChar);
    } else {
        printf("No non-repeating character found in the reversed string.\n");
    }

    free(reversedStr); // 释放内存
    return 0;
}