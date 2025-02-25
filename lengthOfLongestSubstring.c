#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    char* start_ptr = s;
    int cnt = 0, longestsubstring = 0;
    int j[256];
    memset(j, -1, 256 * sizeof(int));

    while(*s != '\0') {
        if (j[(int)*s] == -1){
            j[(int) *s] = (int)(s - start_ptr);
            cnt++;
        } else {
            start_ptr++;
            s = start_ptr;
            cnt = 0;
            memset(j, -1, 256 * sizeof(int));
            continue;
        }
        if (cnt > longestsubstring) longestsubstring = cnt;
        s++;
    }
    return longestsubstring;
 }

 int main() {
    char string[] = "pwwkew";
    int result = lengthOfLongestSubstring(string);
    printf("Length of Longest Substring: %d\n", result);
    return 0;
}
