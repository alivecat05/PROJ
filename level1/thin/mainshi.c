#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 函数用于检查是否有连续相同的字符
int hasConsecutiveChars(char *str, int len) {
    for (int i = 0; i < len - 2; i++) {
        if (str[i] == str[i + 1] && str[i] == str[i + 2]) {
            return i; // 返回第一个连续字符的索引
        }
    }
    return -1;
}

// 函数用于检查是否有两对连续的相同字符（AABB型）
int hasConsecutivePairs(char *str, int len) {
    for (int i = 0; i < len - 3; i++) {
        if (str[i] == str[i + 1] && str[i + 2] == str[i + 3]) {
            return i; // 返回第一对连续字符的索引
        }
    }
    return -1;
}

// 自动校对函数
void autoCorrect(char *str) {
    int len = strlen(str);
    while (len > 1) {
        int index = -1;
        // 优先检查AABB型错误
        if ((index = hasConsecutivePairs(str, len)) != -1) {
            // 去掉第二对中的一个字符
            memmove(&str[index + 1], &str[index + 2], len - index - 1);
        } else if ((index = hasConsecutiveChars(str, len)) != -1) {
            // 去掉三个连续字符中的一个
            memmove(&str[index + 1], &str[index + 2], len - index - 2);
        }
        len = strlen(str); // 更新字符串长度
    }
}

int main() {
    int N;
    scanf("%d", &N); // 读取待校验的字符串数量

    while (N--) {
        char str[1001];
        scanf("%s", str); // 读取待校验的字符串

        autoCorrect(str); // 调用自动校正函数

        printf("%s\n", str); // 输出校正后的字符串
    }

    return 0;
}