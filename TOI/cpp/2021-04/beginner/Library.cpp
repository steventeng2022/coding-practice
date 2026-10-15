// 1-圖書館 | 2021/04/26~2021/04/30 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202104/Library.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202104/Library.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    int book[2001]={};
    int idx = 0;
    int fine = 0;

    for(int i=0; i<N; ++i)
    {
        int book_id, day;
        scanf("%d%d", &book_id, &day);
        if(day>100)
        {
            fine += 5*(day-100);
            book[idx] = book_id;
            idx += 1;
        }
    }

    if(fine!=0)
    {
        sort(book, book+idx);
        for(int i=0; i<idx-1; ++i)
        {
            printf("%d ", book[i]);
        }
        printf("%d\n", book[idx-1]);
    }

    printf("%d\n", fine);

}
