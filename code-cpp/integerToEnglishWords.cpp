#include <iostream>
#include <stack>
#include <map>

using namespace std;

/**
 * Convert a non-negative integer num to its English words representation.
 */

const string SPACE = " ";
const map<int, string> pos_significant = {
        {9, "Billion"},
        {6, "Million"},
        {3, "Thousand"},
        {2, "Hundred"},
        {1, "Tens"},
        {0, "Ones"}
};

const map<int, string> integer_string_value = {
        {0, "Zero"},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
};

const map<int, string> integer_tens_value = {
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
};

const map<int, string> integer_tens_special_value = {
        {2, "Twenty"},
        {3, "Thirty"},
        {4, "Forty"},
        {5, "Fifty"},
        {6, "Sixty"},
        {7, "Seventy"},
        {8, "Eighty"},
        {9, "Ninety"},
};

// String is a valid remainder if it is not empty and isn't all zeroes
bool isStringAValidRemainder(string remainder) {
    if (remainder.size() == 0) {
        return false;
    }
    bool hasNonZeroCharacter = false;
    for (auto s : remainder) {
        if (s != '0') {
            hasNonZeroCharacter = true;
            break;
        }
    }
    return hasNonZeroCharacter;
}

string numberToWords(int num) {
    //start from MSB until you encounter a significant position
    //pick the name's value and then recursively, solve for the next part
    if (num < 10) {
        return integer_string_value.at(num);
    }
    //handle 11-20
    if (num < 20) {
        return integer_tens_value.at(num);
    }
    string s = to_string(num);
    int i = 0, n = s.size(), msb_mark;

    string num_until_significant_msb = "";
    bool seen_significant = false;

    while (i < n) {
        msb_mark = n - 1 - i;
        //whenever you see a significant msb stop
        if (!seen_significant && pos_significant.find(msb_mark) != pos_significant.end()) {
            //found it. add the current digit to val
            num_until_significant_msb += to_string(s[i] - '0');
            seen_significant = true;
            // now whatever you've seen from initial msb to now, solve it
            // ans = num_so_far + value at this position + recurse for rest of the string

            //if this is a tens position, we need to handle it properly
            string left;
            if (msb_mark == 1) {
                left = integer_tens_special_value.at(s[i] - '0');
            } else {
                left = numberToWords(stoi(num_until_significant_msb)) + SPACE + pos_significant.at(msb_mark);
            }
            string remainder = s.substr(i + 1);
            //if remainder is all zeroes or empty, we don't bother
            if (isStringAValidRemainder(remainder)) {
                string right = numberToWords(stoi(remainder));
                return left + SPACE + right;
            } else {
                return left;
            }

        } else {
            //we haven't seen it..keep building the number
            num_until_significant_msb += to_string(s[i] - '0');
        }
        msb_mark -= 1;
        i += 1;
    }

    return "";
}


int main() {
    std::cout << "0 :" << numberToWords(0) << std::endl;
    std::cout << "7 :" << numberToWords(7) << std::endl;
    std::cout << "10 :" << numberToWords(10) << std::endl;
    std::cout << "12 :" << numberToWords(12) << std::endl;
    std::cout << "47 :" << numberToWords(47) << std::endl;
    std::cout << "100 :" << numberToWords(100) << std::endl;
    std::cout << "553 :" << numberToWords(553) << std::endl;
    std::cout << "647 :" << numberToWords(647) << std::endl;
    std::cout << "1300 :" << numberToWords(1300) << std::endl;
    std::cout << "3647 :" << numberToWords(3647) << std::endl;
    std::cout << "10000 :" << numberToWords(10000) << std::endl;
    std::cout << "10009 :" << numberToWords(10009) << std::endl;
    std::cout << "83647 :" << numberToWords(83647) << std::endl;
    std::cout << "483647 :" << numberToWords(483647) << std::endl;
    std::cout << "7483647 :" << numberToWords(7483647) << std::endl;
    std::cout << "47483647 :" << numberToWords(47483647) << std::endl;
    std::cout << "147483647 :" << numberToWords(147483647) << std::endl;
    std::cout << "2147483647 :" << numberToWords(2147483647) << std::endl;
    return 0;
}
