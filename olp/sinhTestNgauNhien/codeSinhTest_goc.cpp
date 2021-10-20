#include<bits/stdc++.h>
using namespace std;
string doiSoSangXau(int i)
{
    string ans = "";
    while(i)
    {
        ans += ((char)(i % 10 + 48));
        i /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    srand((int)time(0));//giup ham rand sinh ra cac so khac nhau tai moi thoi diem
    int a, b;
    cout << "nhap chi so cua test dau va test cuoi: ";
    cin >> a >> b;
    for (int i = a; i <= b; i++)// chay sinh ra cac test tu a den b
    {
        string s = "D:\\hocTap\\olp\\sinhTestNgauNhien\\test\\test"; // ghi nguon file o day
        s += doiSoSangXau(i);
        s += ".txt";
        char *sub = new char[s.length() + 1];
        strcpy(sub, s.c_str());
        freopen(sub, "w", stdout);
        //file duoc xuat ra co dang test+so.txt


        //code sinh test o day
        int t;
        t = (int)rand() % 1000 + 1;
        cout << t << '\n';
        while(t--)
        {
            int b, a = ((int)rand()) % 12;
            int x = a;
            if(a == 2)
                b = ((int)rand()) % 29 + 1;
            else if(a == 4 || a == 6 || a == 9 || a == 11)
                b = ((int)rand()) % 30 + 1;
            else
                b = ((int)rand()) % 21 + 1;
            cout << b << ' ' << x << '\n';
        }
    }
    return 0;
}
