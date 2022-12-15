#include <iostream>
#include <string>

std::string convert(std::string s, uint16_t numRows) {
    if (numRows == 1) return s;
    else{
        std::string zigzag_string{};
        for (uint16_t i{}; i < numRows; i++) {
                    if ((i == 0) || (i == numRows - 1)) {
                        for (uint16_t j{}; (i+j) < s.size(); j += (numRows + abs(numRows - 2))) {
                                zigzag_string += s.at(i + j);
                        }
                    }
                    else {
                        for (uint16_t j{}; abs(i+j-2*i) < s.size(); j += (numRows + abs(numRows - 2))){
                            if (j) zigzag_string += s.at(i + j - 2*i);
                            if((i+j)<s.size())
                                zigzag_string += s.at(i + j);
                        }
                    }
        }
        return zigzag_string;
    }
}

int main()
{
    std::string F{};
    int nR{};
    std::cin >> F>>nR;
    std::cout << convert(F, nR);
}
