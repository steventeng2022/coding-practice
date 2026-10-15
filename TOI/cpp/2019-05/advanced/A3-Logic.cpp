// 3-邏輯運算 | 2019/05/27~2019/05/31 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201905/A3-Logic(Q).pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201905/A3-Logic.zip
#include <bits/stdc++.h>
#include<bits/stdc++.h>
int num[1000005];
int check[1000005];
struct Instructs
{
    int op,p,q;
};
void Print(int p, std::vector<Instructs> &ins)
{
    int &n=num[p];
    if(!check[p])
    {
        int len=ins.size();
        for(int i=0; i<len; i++)
        {
            if(p%ins[i].p==0)
            {
                int op=ins[i].op;
                if(op==2)
                    n &= ins[i].q;
                else if (op==3)
                    n |= ins[i].q;
                else
                    n ^= ins[i].q;
            }
        }
        check[p]=1;
    }
    printf("%d\n",n);
}
int main()
{
    memset(check, 0, sizeof(check));
    int N;
    scanf("%d", &N);
    std::vector<Instructs> ins;
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &num[i]);
    }
    int op;
    while(scanf("%d", &op)!=EOF&&op!=0)
    {
        if(op==1)
        {
            int p;
            scanf("%d", &p);
            Print(p, ins);
        }
        else
        {
            Instructs temp;
            temp.op=op;
            scanf("%d%d", &temp.p,&temp.q);
            ins.push_back(temp);
        }
    }
}
