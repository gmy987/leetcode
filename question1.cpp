#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string str, res = "", tmp;
    int p1, p2, pos;
    string d1 = "http://", d2 = "https://";
    while (getline(cin, str)) {
        res = "";
        stringstream ss(str);
        while (ss >> tmp) {
            p1 = tmp.find(d1, 0);
            p2 = tmp.find(d2, 0);
            if (p1 == -1 && p2 == -1) {
                res += tmp + " ";
            } else {
                if (p1 == -1)
                    pos = p2;
                else if (p2 == -1)
                    pos = p1;
                else
                    pos = min(p1, p2);
                res += tmp.substr(0, pos);
                tmp = tmp.substr(pos, tmp.length());
                res += "<a href=\"" + tmp + "\">" + tmp + "</a> ";
            }
        }
        cout << res.substr(0, res.length() - 1) << endl;
    }
    return 0;
}
