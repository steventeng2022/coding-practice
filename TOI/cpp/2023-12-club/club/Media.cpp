// 社交媒體 | 2023/12 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312-OFFLINE/Media.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312-OFFLINE/Media.zip
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Post
{
    string id;
    int follow;
    int count;
    int serial_number;

    bool operator<(const Post& rhs) const
    {
        if (count != rhs.count)
            return count > rhs.count;
        if (follow != rhs.follow)
            return follow < rhs.follow;
        return serial_number < rhs.serial_number;
    }
};

int main()
{
    int command;
    priority_queue<Post> posts;
    int serial_number = 0;
    while (cin >> command && command != 0)
    {
        if (command == 1)
        {
            Post newPost;
            string id;
            string x;
            cin >> newPost.id >> x;
            if (x == "SF")
                newPost.follow = 1;
            else if (x == "F")
                newPost.follow = 0;
            else
                newPost.follow = -1;
            newPost.count = 0;
            newPost.serial_number = serial_number;
            ++serial_number;
            posts.push(newPost);
        }
        else if (command == 2)
        {
            Post post = posts.top();
            posts.pop();

            cout << post.id << endl;
            post.count++;
            posts.push(post);
        }
    }
}
