// 錄影片段 | 2021/10/23 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110-OFFLINE/Tapes.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110-OFFLINE/Tapes.zip
#include <bits/stdc++.h>
#include <string.h>
#include <stdio.h>

const char* find(const char *str, const char *term) {
    while (*str) {
        const char *p = str, *q = term;
        while (*p && *q && (*q == '#' || *p == *q)) {
            ++p, ++q;
        }
        if (!*q) {
            return str;
        }
        if (!*p) {
            return NULL;
        }
        ++str;
    }
    return NULL;
}

bool match(const char *format, const char *target) {
    // both end
    if (!*format && !*target) {
        return true;
    }
    // only one end
    if (!*format || !*target) {
        return false;
    }
    // match at lease one char
    if (*format == '.') {
        // is last char
        if (!*(format+1)) {
            return true;
        }
        return match(format+1, target+1);
    }
    // get term
    int term_len = 0; char term[220] = {};
    for (int i = 0; *format && *format != '.'; ++format, ++i) {
        term[i] = *format, ++term_len;
    }
    // is last term
    if (!*format) {
        const char *t = target + strlen(target) - term_len;
        return find(t, term) == t;
    }
    // find term
    const char *p = find(target, term);
    // no find
    if (!p) {
        return false;
    }
    // match next part
    return match(format, p+term_len);
}

int main() {
    int N;
    char format[220], target[220];
    scanf("%s%d", format, &N);
    while (N--) {
        scanf("%s", target);
        // match first term
        int pos = 0; bool check = true;
        while (format[pos] && format[pos] != '.') {
            if (format[pos] != '#' && format[pos] != target[pos]) {
                check = false;
                break;
            }
            ++pos;
        }
        puts(check && match(format + pos, target + pos) ? "Yes" : "No");
    }
}
