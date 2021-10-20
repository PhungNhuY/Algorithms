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

int random(int minN, int maxN)// sinh mot so nguyen ngau nhien tu minN den maxN
{
    return minN + (int)rand() % (maxN + 1 - minN);
}

long long randomLL(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

int main()
{
    srand((int)time(0));//giup ham rand sinh ra cac so khac nhau tai moi thoi diem
    int start, end;
    cout << "nhap chi so cua test dau va test cuoi: ";
    cin >> start >> end;
    for (int chay = start; chay <= end; chay++)// chay sinh ra cac test tu a den b
    {
        string DuongDan = "D:\\hocTap\\olp\\sinhTestNgauNhien\\test\\"; // ghi nguon file o day
        DuongDan += "test";
        DuongDan += doiSoSangXau(chay);
        DuongDan += ".txt";
        char *sub = new char[DuongDan.length() + 1];
        strcpy(sub, DuongDan.c_str());
        freopen(sub, "w", stdout);
//file duoc xuat ra co dang test+so.txt


//code sinh test o day
        vector <string> pokemon;
        for(int sl=1;sl<=300;sl++)
        {
            int doDai = random(1, 10);
            string name = "";
            for(int i=1;i<=doDai;i++)
                name = name + (char)random('a', 'z');
            pokemon.push_back(name);
        }
        cout << 100000 << "\n";
        for(int i=1;i<=100000;i++)
            cout << pokemon[0] << " ";
    }
    return 0;
}
