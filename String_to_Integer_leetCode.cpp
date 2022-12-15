#include <iostream>
#include <string>
//#include <cstdint>

using std::string;

int myAtoi(string s) {
    int i{}, temp{}, uni_lock{}, space_lock{1};
    long long number{};
    bool sgn = true;
    while (i < s.size()) {
        if (int(s.at(i)) == 32) {
            if (space_lock) {
                ++i;
                ++space_lock;
                continue;
            }
            else break;
        }
        
        if (int(s.at(i)) == 43) {
            if (!uni_lock) {
                sgn = true;
                ++uni_lock;
                space_lock = 0;
                ++i;
                continue;
            }
            else break;
        }
        
        if (int(s.at(i)) == 45) {
            if (!uni_lock) {
                sgn = false;
                ++uni_lock;
                space_lock = 0;
                ++i;
                continue;
            }
            else break;
        }

        if (int(s.at(i))<48 || int(s.at(i)) > 57) break;

        while (i < s.size() && (47 < int(s.at(i))) && (int(s.at(i)) < 58)) {
            if (number < 2147483649) {
                if (i != temp && number) number *= 10;
                number += abs(48 - int(s.at(i)));
                temp = i;
                ++i;
                ++uni_lock;
            }
            else break;
        }
        if (uni_lock) break;
        ++i;
    }
    if (sgn) {
        if (number > 2147483647) return 2147483647;
        else return number;
    }
    else {
        if ((-1 * number) < (-2147483648)) return -2147483648;
        return (number * (-1));
    }
}


int main()
{
    string some{"  +341"};
    std::cout << myAtoi(some)<<'\n';
}

