// 方程式 | 2023/12 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312-OFFLINE/Equation.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312-OFFLINE/Equation.zip
#include <bits/stdc++.h>
//exp.cpp
#include<cstdio>
#include<cstring>
#include<stack>
#include<cassert>
const int MAXN = 505;

using namespace std;

struct Exp {
    int coef[2];
};

Exp makeX()
{
    Exp ret;
    ret.coef[0] = 0;
    ret.coef[1] = 1;
    return ret;
}

Exp makeConst(int val)
{
    Exp ret;
    ret.coef[0] = val;
    ret.coef[1] = 0;
    return ret;
}

Exp add(Exp a, Exp b)
{
    Exp ret;
    ret.coef[0] = a.coef[0] + b.coef[0];
    ret.coef[1] = a.coef[1] + b.coef[1];
    return ret;
}

Exp mul(Exp a, Exp b)
{
    Exp ret;
    assert(a.coef[1] == 0 || b.coef[1] == 0);
    ret.coef[0] = a.coef[0] * b.coef[0];
    ret.coef[1] = a.coef[0] * b.coef[1] + a.coef[1] * b.coef[0];
    return ret;
}

Exp calc(const char *s, const int *pos, int lb, int ub)
{
    int idx = lb;
    Exp ret;
    std::stack<Exp> stkVal;
    std::stack<char> stkOp;

    ret.coef[0] = ret.coef[1] = 0;

    while (idx <= ub)
    {
        if (s[idx] == '(')
        {
            Exp val1 = calc(s, pos, idx + 1, pos[idx] - 1), val2;
            if (stkOp.size() && stkOp.top() == '*')
            {
                val2 = stkVal.top(); stkVal.pop();
                stkVal.push(mul(val1, val2));
                stkOp.pop();
            }
            else
            {
                stkVal.push(val1);
            }
            idx = pos[idx] + 1;
        }
        else if (('0' <= s[idx] && s[idx] <= '9') || s[idx] == 'x')
        {
            Exp val1, val2;
            if (s[idx] == 'x')
            {
                val1 = makeX();
            }
            else
            {
                val1 = makeConst(s[idx] - '0');
            }
            if (stkOp.size() && stkOp.top() == '*')
            {
                val2 = stkVal.top(); stkVal.pop();
                stkVal.push(mul(val1, val2));
                stkOp.pop();
            }
            else
            {
                stkVal.push(val1);
            }
            ++idx;
        }
        else
        {
            stkOp.push(s[idx]);
            ++idx;
        }
    }
    while (stkVal.size())
    {
        ret = add(ret, stkVal.top());
        stkVal.pop();
    }
    return ret;
}

int init(char *exp, int *pos)
{
    int idx = 0;
    stack<int> stk;
    for (int i = 0; exp[i] != '\n' && exp[i]; ++i)
    {
        if (exp[i] != ' ')
        {
            exp[idx] = exp[i];
            if (exp[idx] == '(')
            {
                stk.push(idx);
            }
            else if (exp[idx] == ')')
            {
                pos[stk.top()] = idx;
                stk.pop();
            }
            ++idx;
        }
    }
    exp[idx] = '\0';

    return idx;
}

int main()
{
    char exp[MAXN + 5];
    int pos[MAXN], n;
    Exp l, r;
    fgets(exp, MAXN, stdin);
    n = init(exp, pos);
    l = calc(exp, pos, 0, n - 1);
    fgets(exp, 775, stdin);
    n = init(exp, pos);
    r = calc(exp, pos, 0, n - 1);
    printf("%d\n", (r.coef[0] - l.coef[0]) / (l.coef[1] - r.coef[1]));
    return 0;
}
