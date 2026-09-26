#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string timeConversion(string s)
{
    int hour = stoi(s.substr(0, 2));

    if (s[8] == 'A')
    {
        if (hour == 12)
        {
            s[0] = '0';
            s[1] = '0';
        }
    }
    else
    {
        if (hour != 12)
        {
            hour += 12;
            s[0] = char('0' + hour / 10);
            s[1] = char('0' + hour % 10);
        }
    }

    s.erase(8, 2);

    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(),
                not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(),
                not1(ptr_fun<int, int>(isspace)))
            .base(),
        s.end());

    return s;
}