#include <bits/stdc++.h>
using namespace std;

int total_calls = 0, incorrect_call_num = 0;
map<string, int> call_num, call_time;

bool iscorrect_num(string tel)
{
    if (tel.length() != 10)
        return false;
    for (int i = 0; i < tel.length(); i++)
    {
        if (tel[i] < '0' || tel[i] > '9')
            return false;
    }
    return true;
}

int duration(string st, string et)
{
    int stime = (st[0] * 10 + st[1]) * 3600 + (st[3] * 10 + st[4]) * 60 + (st[6] * 10 + st[7]);
    int etime = (et[0] * 10 + et[1]) * 3600 + (et[3] * 10 + et[4]) * 60 + (et[6] * 10 + et[7]);
    return etime - stime;
}

void solve()
{
    string cmd, tel;
    do {
        cin >> cmd;
        if (cmd == "#") continue;
        else if (cmd == "?check_phone_number") {
            if (incorrect_call_num == 0) cout << 1;
        }
        else if (cmd == "?number_total_calls")
            cout << total_calls << endl;
        else if (cmd == "?number_calls_from")
        {
            cin >> tel;
            cout << call_num[tel] << endl;
        }
        else if (cmd == "?count_time_calls_from")
        {
            cin >> tel;
            cout << call_time[tel] << endl;
        }
    } while (cmd != "#");
}

void input()
{
    string cmd, from_number, to_number, date, from_time, end_time;
    do
    {
        cin >> cmd;
        if (cmd == "#") continue;
        if (cmd == "call") cin >> from_number >> to_number >> date >> from_time >> end_time;
        if (!iscorrect_num(from_number) || !iscorrect_num(to_number)) incorrect_call_num++;
        total_calls ++;
        call_num[from_number] ++;
        call_time[from_number] += duration(from_time, end_time);
    } while (cmd != "#");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    solve();
    return 0;
}