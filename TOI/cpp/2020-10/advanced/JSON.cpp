// 3-JSON | 2020/10/26~2020/10/30 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202010/JSON.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202010/JSON.zip
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define is_numchar(num) (num >= '0' && num <= '9')
using namespace std;

void cmd_parser(const string &cmd,  list<pair<bool,string> > &res)
{
    int cmdlen = cmd.length();
    int digest_mode = 0;
    bool str_end_pharse = true;
    string charbuf = "";

    for(int index = 3;index != cmdlen;++index)
    {
        if(cmd[index] == '[')
            continue;
        else if(cmd[index] == ']')
        {
            if(charbuf != "")
                res.push_back(make_pair(false,charbuf));
            charbuf = "";
        }
        else if(cmd[index] == '"')
        {
            str_end_pharse = !str_end_pharse;
            if(digest_mode == 1)
            {
                digest_mode = 0;
                res.push_back(make_pair(true,charbuf));
                charbuf = "";
            }
            else
                digest_mode = 1;
        }
        else if(digest_mode == 1 || is_numchar(cmd[index]))
        {
            charbuf+= cmd[index];
        }
    }
}
void remove_obj(int &st, const string &obj)
{
    //easy case
    bool is_num = false;
    while(is_numchar(obj[st]))
    {
        is_num = true;
        st++;
    }
    if(is_num)
        return;

    bool is_str = false;
    if (obj[st] == '"')
    {
        st++;
        while(obj[st] != '"')
        {
            is_str = true;
            st++;
        }
        st++;
    }
    if(is_str)
        return;

    if(obj[st] == 't')
    {
        st+=4;
        return;
    }

    if(obj[st] == 'f')
    {
        st+=5;
        return;
    }

    //hard one
    stack<string> token;
    string buf = "";
    while(true)
    {
        if(obj[st] == '{' || obj[st] == '[')
        {
            string c = ""+obj[st];
            token.push(c);
        }
        else if(obj[st] == '}' || obj[st] == ']')
        {
            token.pop();
            if(token.empty())
                break;
        }
        st++;
    }
    st++;
}
void map_traversal(string key, int &st, int &ed, const string &obj)
{
    int c_st = st;
    int c_ed = ed;
    for(;c_st <= c_ed; ++c_st)
    {
        if(obj[c_st] == '{' || obj[c_st] == '}')
             continue;
        if(obj[c_st] == '"')
        {
            string k="";
            c_st++;
            while(obj[c_st] != '"')
            {
                k += obj[c_st];
                c_st++;
            }

            if (k == key)
            {
                c_st += 2;
                /*
                "key":...,
                ^     ^
                */
                c_ed = c_st;
                st = c_st;
                remove_obj(c_ed,obj);
                ed = c_ed-1;
                return;
            }
            else
            {
                /*
                "not key":...
                ^         ^
                */
                c_st+=2;
                remove_obj(c_st,obj);
            }
        }

    }
}
void arr_traversal(int i, int &st, int &ed, const string &str)
{

    st ++;
    for(int d = 0 ; d != i ; ++d)
    {
        remove_obj(st,str);
        while(str[st] != ',')
            st++;
        st++;
    }
    ed = st;
    remove_obj(ed, str);
    ed--;
}
string json_traversal(list<pair<bool,string> > &cmds, const string &obj)
{
    int st=0 ,ed=obj.length()-1;
    for(auto i = cmds.begin(); i!=cmds.end() ; ++i)
    {
        //cout <<(((*i).first)? "string":"num")<< " key:" << (*i).second << '\n';
        //cout << "ori:"<<obj.substr(st,ed-st+1)<<'\n';

        if((*i).first) // is string as key
            map_traversal((*i).second, st, ed, obj);
        else // is num as key
            arr_traversal(atoi((*i).second.c_str()), st, ed ,obj);

        //cout <<"cur:"<<obj.substr(st,ed-st+1)<<'\n';
    }
    return obj.substr(st,ed-st+1);
}
int main()
{
    string json;
    string cmd;
    getline(cin,json);
    cin >> cmd;
    list<pair<bool, string> > res;
    cmd_parser(cmd, res);
    cout<<json_traversal(res, json) << '\n';

    return 0;
}
