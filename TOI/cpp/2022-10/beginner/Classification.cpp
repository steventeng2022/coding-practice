// 2-資料分類 | 2022/10/24~2022/10/28 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202210/Classification.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202210/Classification.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int num;
    scanf("%d",&num); // four digit number
    int cnt=0,next_num = num;
    while(num/10>0)
    {
        int st = num/100 , ed = num%100;
        if(st/10>0 && ed/10>0) // if four
        {
            int fnt = (st%10) * (st/10);
            int bk = (ed%10) * (ed/10);
            if(fnt/10 > 0 && bk/10>0 || fnt/10==0 &&  bk/10>0)
                num = fnt*100+bk;
            else if(bk/10==0)
                num = fnt*10+bk;
        }
        else if (st/10>0 && ed<10)// if three(ed is 0x,x=1~9)
        {
            int fnt = (st%10) * (st/10);
            int bk = ed;
            num = fnt * 10 + bk;
        }
        else if (st/10==0 && ed/10>0) // if three(one digit on st)
        {
            int fnt = st * (ed/10);
            int bk = (ed%10) * (ed/10);
            if(fnt/10 > 0 && bk/10>0 || fnt/10==0 &&  bk/10>0)
                num = fnt*100+bk;
            else if(bk/10==0)
                num = fnt*10+bk;
        }
        else if(st/10>0 && ed/10==0)// if three(one digit on ed)
        {
            int fnt = (st/10) * (st%10);
            int bk = ed * (st%10);
            if(fnt/10 > 0 && bk/10>0 || fnt/10==0 &&  bk/10>0)
                num = fnt*100+bk;
            else if(bk/10==0)
                num = fnt*10+bk;
        }
        else if (st/10==0 && ed/10==0)// two digit
        {
            num = st*ed;
        }
    }
    printf("%d\n",num);
}
