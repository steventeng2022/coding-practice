// 益智方塊 | 2022/08 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202208-OFFLINE/Puzzle.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202208-OFFLINE/Puzzle.zip
#include <bits/stdc++.h>
#include <iostream>
#include <array>
#include <cassert>
#include <unordered_map>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Block
{
public:
    const std::array<int, 27> &get_value() const  // return the state of the puzzle
    {
        return this->value;
    }

    int &get(const std::array<int, 3> &i) // take a place coordinate(x,y,z)
    {
        return this->get(i[0], i[1], i[2]);
    }

    int &get(int i, int j, int k) // take a place coordinate(x,y,z)
    {
        return this->value[i * 9 + j * 3 + k];
    }

    const int &get(const std::array<int, 3> &i) const // take a place coordinate(x,y,z)
    {
        return this->get(i[0], i[1], i[2]);
    }

    const int &get(int i, int j, int k) const // take a place coordinate(x,y,z)
    {
        return this->value[i * 9 + j * 3 + k];
    }

    bool can_move(const std::array<int, 3> &i) const // whether can move to this direction
    {
        return this->can_move(i[0], i[1], i[2]);
    }

    bool can_move(int i, int j, int k) const // whether can move to this direction
    {
        int _i = this->slot[0] + i;
        int _j = this->slot[1] + j;
        int _k = this->slot[2] + k;
        return (_i >= 0 && _i < 3) && (_j >= 0 && _j < 3) && (_k >= 0 && _k < 3);
    }

    bool operator==(const Block &other) const //overwrite
    {
        return this->value == other.value;
    }

    bool operator<(const Block &other) const //overwrite
    {
        return this->value < other.value;
    }

    Block move(std::array<int, 3> i) const // call 67
    {
        return this->move(i[0], i[1], i[2]);
    }

    Block move(int i, int j, int k) const // move a block
    {
        Block moved = *this;
        auto index = moved.slot;
        //assert(moved.get(index) == 0);
        moved.slot[0] += i;
        moved.slot[1] += j;
        moved.slot[2] += k;
        //assert(index != moved.slot);
        //assert(moved.get(moved.slot) != 0);
        std::swap(moved.get(moved.slot), moved.get(index));
        return moved;
    }

    static Block build_final_state() // final state
    {
        std::array<int, 27> arr;
        for (size_t i = 0; i < 26; i++)
        {
            arr[i] = i + 1;
        }
        arr[26] = 0;
        return Block(arr);
    }

    Block(std::array<int, 27> value_) : value(value_) // change array to a block , find the empty block, verify
    {
        std::array<int, 27> pos;
        pos.fill(-1);

        for (int i = 0; i < 27; i++)
        {
            auto v = this->value[i];
            assert(pos[v] == -1);
            pos[v] = i;
        }
        int i = pos[0];
        int d = 9;
        for (int j = 0; j < 3; j++)
        {
            this->slot[j] = i / d;
            i %= d;
            d /= 3;
        }
        assert(this->get(this->slot) == 0);
    }

    friend class std::hash<Block>;

private:
    std::array<int, 27> value;  // block --> array (save state)
    std::array<int, 3> slot; // put coordinate (x,y,z) (empty place)
};

namespace std //how to hash
{
    template <>
    struct hash<Block>
    {
        size_t operator()(const Block &k) const
        {
            auto h = hash<int>();
            size_t r = 0;
            for (auto v : k.value)
                r = r * 31 + h(v);
            return r;
        }
    };
}

int diff(const Block &a, const Block &b) //
{
    int result = 0;
    const auto &av = a.get_value();
    const auto &bv = b.get_value();
    for (size_t i = 0; i < 27; i++)
    {
        result += av[i] != bv[i];
    }
    return result;
}

int main()
{
    array<int, 27> val;
    for (size_t i = 0; i < 27; i++) // input
    {
        cin >> val[i];
    }

    Block final_state = Block::build_final_state(); // calculate final state
    auto initial_state = Block(val); // change to block
    //A*
    unordered_map<Block, int> min_dis;
    priority_queue<tuple<int, int, Block>, vector<tuple<int, int, Block>>, greater<tuple<int, int, Block>>> q;
    q.push(make_tuple(0, 0, initial_state));
    min_dis[initial_state] = 0;

    array<int, 3> move_vecs[] = {
        {1, 0, 0},
        {-1, 0, 0},
        {0, 1, 0},
        {0, -1, 0},
        {0, 0, 1},
        {0, 0, -1},
    };

    while (!q.empty())
    {
        auto [f, g, b] = q.top();
        q.pop();
        if (b == final_state)
        {
            break;
        }
        for (const auto &mv : move_vecs)
        {
            if (b.can_move(mv))
            {
                auto nx = b.move(mv);
                auto nx_g = g + 1;
                // Can't relax
                if (min_dis.count(nx) && min_dis[nx] <= nx_g)
                    continue;
                min_dis[nx] = nx_g;
                q.push(make_tuple(nx_g + diff(nx, final_state), nx_g, nx));
            }
        }
    }

    cout << (min_dis.count(final_state) ? min_dis[final_state] : -1) << '\n';
    return 0;
}
