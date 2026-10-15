// 1-小畫家 | 2022/04/25~2022/04/29 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202204/Painter.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202204/Painter.zip
#include <bits/stdc++.h>
// painting_dsu.cpp
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

class DSU{
public:
    vector<int> fa;
    DSU()
    {

    }
    void init(int n)
    {
        this->n = n;
        this->fa.resize(n);
        for(int i = 0; i < n; ++i)
        {
            this->fa[i] = i;
        }
        return;
    }
    int getfa(int x)
    {
        return x == this->fa[x] ? x : this->fa[x] = getfa(this->fa[x]);
    }
    void merg(int a, int b)
    {
        this->fa[this->getfa(a)] = this->getfa(b);
    }
    int compressPath(int a)
    {
        return getfa(a);
    }
private:
    int n;
};

int main()
{
    int h, w, si, sj, z;
    DSU dsu;
    vector<vector<int>> v;
    scanf("%d%d%d%d%d", &h, &w, &si, &sj, &z);
    --si; --sj;
    v.resize(h);
    for(int i = 0; i < h; ++i)
    {
        v[i].resize(w);
        for(int j = 0; j < w; ++j)
        {
            scanf("%d", &v[i][j]);
        }
    }
    dsu.init(h * w);
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            for(int k = 0; k < 2; ++k)
            {
                int ni = i + k, nj = j + (1 - k);
                //printf("(%d, %d) and (%d, %d)\n", i, j, ni, nj);
                if(ni < h && nj < w && v[i][j] == v[ni][nj])
                {
                    dsu.merg(i * w + j, ni * w + nj);
                }
            }
        }
    }
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            dsu.compressPath(i * w + j);
        }
    }
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            //dsu.getfa(i * w + j);
            //printf("(%d, %d) = %d\n", i, j, dsu.fa[i * w + j]);
            if(dsu.fa[i * w + j] == dsu.fa[si * w + sj])
            {
                v[i][j] = z;

            }
        }
    }
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            printf("%d%c", v[i][j], j == w - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
