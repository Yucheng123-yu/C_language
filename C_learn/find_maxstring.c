#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//  使用C语言实现一个函数，找到一个字符串中最长的无重复字符的子串。
char *findLongestUniqueSubstr(char *str) {
	if (str == NULL || str[0] == '\0') return NULL;
	
	int n = strlen(str);
	int start = 0; 
	int maxLen = 0; 
	int maxStart = 0;
	int usedChar[256]; 
	int flag;
	for (int i = 0; i < 256; i++) {
		usedChar[i] = -1;
	}
	
	for (int i = 0; i < n; ++i) {
		if (usedChar[(unsigned char)str[i]] >= start) {
			start = usedChar[(unsigned char)str[i]] + 1;
		} else { 
			if (i - start + 1 > maxLen) {
				maxLen = i - start + 1;
				maxStart = start;
			}
		}
		flag = (unsigned char)str[i];
		usedChar[(unsigned char)str[i]] = i;
	}
	
	char *longestSubstr = (char *)malloc(maxLen + 1);
	if (longestSubstr != NULL) {
		strncpy(longestSubstr, &str[maxStart], maxLen);
		longestSubstr[maxLen] = '\0';
	}
	return longestSubstr;
}

char* find_maxstring(char *str)
{
    int len = strlen(str);
    int startindex = 0;
    int endindex = 0;
    int currentlength = 0;
    int max_len = 0;
	int max_startindex=0;
	int max_endindex=0;
	
    while (endindex < len)
    {
        char pendingcahr = str[endindex];
        for (int j = startindex; j < endindex; j++)
        {
            if (str[j] == pendingcahr)
            {
                startindex = j+1;
                currentlength = endindex-startindex;
                break;
            }
        }
        endindex++;
        currentlength++;
        if (currentlength > max_len)
        {
            max_len = currentlength;
            max_startindex = startindex;
            max_endindex = endindex;
        }
    }

    // printf("%d %d %d\n", max_startindex, max_endindex,max_len);
    char *long_string = (char*)malloc(max_len*sizeof(char));
    strncpy(long_string, &str[max_startindex], max_len);
    long_string[max_len] = '\0';
    return long_string;
}
    

int main()
{
    char input_str[100] = "abcdefsalhdzvkpoabb";
	printf("%s\n", input_str);
    char *long_string = find_maxstring(input_str);
    char *result = findLongestUniqueSubstr(input_str);
    printf("%s\n", long_string);
    printf("%s\n", result);
    free(long_string);
    free(result);
    return 0;
}


