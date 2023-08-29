
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longest(const string& str1, const string& str2) {
    int length = min(str1.size(), str2.size());
    int index = 0;
    while(index < length && str1[index] == str2[index]) {
        ++index;
    }
    return str1.substr(0, index);
}

string longestCommonPrefix(vector<string>& strs) {
    if(!str.size()) {
        return "";
    }
    string prefix = strs[0];
    int count = strs.size();
    for(int i = 1; i < count; ++i) {
        prefix = longest(prefix, strs[i]);
	if(!prefix.size()) {
	    break;
	}
    }
    return prefix;
}


int main()
{
    string s;
    vector<string> arr;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; ++i) {
        if(s[i] == "") {
            int left = ++i;

	    int n = 0;
	    while(s[i] != '"') {
                n++;
		i++;
	    }
	    string temp = s.substr(left, n);
	    arr.push_back(temp);
	}
    }
    string ans = longestCommonPrefix(arr);
    cout << ans << endl;
    return 0;
}
