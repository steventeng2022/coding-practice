// 2-上菜 | 2022/11/28~2022/12/02 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202211/Serving.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202211/Serving.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

long long int Inversion(vector<int> &order, int lb, int ub)
{
    if(lb+1>=ub)
        return 0;

    long long int count = 0, mid = (lb+ub)/2;
    count += Inversion(order,lb,mid);
    count += Inversion(order,mid,ub);

    vector<int> sorted;
    int left=lb, right=mid;
    while(left<mid || right<ub)
    {
        if(left==mid)
        {
            sorted.push_back(order[right]);
            right+=1;
        }
        else if(right==ub)
        {
            sorted.push_back(order[left]);
            left+=1;
        }
        else if(order[right]<order[left])
        {
            count += (mid-left);
            sorted.push_back(order[right]);
            right+=1;
        }
        else
        {
            sorted.push_back(order[left]);
            left += 1;
        }

    }

    for(int i=lb;i<ub;i+=1)
    {
        order[i] = sorted[i-lb];
    }
    return count;
}

int main()
{
    int N;
    cin >> N;
    unordered_map<int, queue<int>> menu;
    vector<int> order;
    queue<int> dish;
    for(int i=0;i<N;i+=1)
    {
        int a, b;
        cin >> a >> b;
        menu[b].push(i);
        dish.push(a);
        while(!dish.empty() && !menu[dish.front()].empty())
        {
            order.push_back(menu[dish.front()].front());
            menu[dish.front()].pop();
            dish.pop();
        }
    }
    cout << Inversion(order, 0, N);
    return 0;
}
