#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n, idx, p; // 当前已经解压缩了 p 字节，下一个读的是第 idx 下标的字符
string res; // 解压后的数据

string readBytes(int num)
{
    char byte[2 * num];
    for (int i = 0; i < 2 * num; i ++) cin >> byte[i];
    idx += num * 2;
    return string(byte, 2 * num);
}

void trackBack(int o, int l)
{
    int start = res.length() - o * 2;
    int len = o * 2;
    string back_track_string = res.substr(start, len);
    int cnt = 0;
    while (cnt < l * 2 - l * 2 % len)
    {
        res += back_track_string;
        cnt += len;
    }
    res += back_track_string.substr(0, l * 2 % len);
}
int main()
{
    cin >> n;
    string bts;
    vector<int> c;
    int v_c;
    // 读入字节 直到最高位为0
    while ((bts = readBytes(1)) >= "80")
    {
        v_c = stoi(bts, nullptr, 16);
        v_c -= 128;
        c.push_back(v_c);
    }
    // 最高位为0时，直接保存到c里
    v_c = stoi(bts, nullptr, 16);
    c.push_back(v_c);
    // 引导区结束，计算原始数据长度
    int length = 0;
    for (int i = 0; i < c.size(); i ++) length += c[i] * pow(128, i);

    while (idx < n * 2)
    {
        // 接下来是数据域
        // 读入一个字节
        bts = readBytes(1);
        string string_to_binary = bitset<8>(stoi(bts, nullptr, 16)).to_string();
        string lowest_two_digits = string_to_binary.substr(6, 2);
        if (lowest_two_digits == "00")
        {
            string high_six_digits = string_to_binary.substr(0, 6);
            int ll = stoi(high_six_digits, nullptr, 2);
            // l <= 60，高六位 ll 表示 l - 1
            if (ll <= 59)
                res += readBytes(ll + 1);
            else
            {
                // 第一个字节的高六位存储的值为 60、61、62 或 63 时，分别代表 l - 1 用 1、2、3 或 4 个字节表示
                int literal_length = ll - 59;
                // 按照小端序重组字符串 0x01 0x0A => 0x0A01
                string string1 = readBytes(literal_length);
                string string2;
                // 字符串每两位反转
                for (int i = string1.length() - 2; i >= 0; i -= 2)
                    string2 += string1.substr(i, 2);
                int l = 1 + stoi(string2, nullptr, 16); // 字面量长度
                res += readBytes(l);
            }
        }
        else if (lowest_two_digits == "01")
        {
            // 第 2 ~ 4 位即 从下标 3 开始的三位 001 011 01
            string two_to_four_digits = string_to_binary.substr(3, 3);
            // l - 4 占 3 位，存储于首字节的 2 至 4 位中
            int l = stoi(two_to_four_digits, nullptr, 2) + 4;
            // o 占 11 位，其低 8 位存储于随后的字节中，高 3 位存储于首字节的高 3 位中
            string high_three_digits = string_to_binary.substr(0, 3);
            string next_byte_binary = bitset<8>(stoi(readBytes(1), nullptr, 16)).to_string();
            int o = stoi(high_three_digits + next_byte_binary, nullptr, 2);
            // 回溯引用
            trackBack(o, l);
        }
        else if (lowest_two_digits == "10")
        {
            string high_six_digits = string_to_binary.substr(0, 6);
            // l 占 6 位，存储于首字节的高 6 位中
            int l = stoi(high_six_digits, nullptr, 2) + 1;
            // o 占 16 位，以小端序存储于随后的两个字节中
            string string1 = readBytes(2);
            string string2;
            // 字符串每两位反转
            for (int i = string1.length() - 2; i >= 0; i -= 2)
                string2 += string1.substr(i, 2);
            int o = stoi(string2, nullptr, 16);
            // 回溯引用
            trackBack(o, l);
        }
    }
    for (int i = 0; i < res.length(); i ++)
    {
        cout << res[i];
        // 输出，每16个字符加一个换行
        if ((i + 1) % 16 == 0) cout << endl;
    }
    // 若最后一行不能凑8个，则补一个换行
    if (res.length() % 16) cout << endl;
    return 0;
}