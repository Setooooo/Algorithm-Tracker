#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <io.h>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;

        // TODO: Implement your algorithm here.
        // Suggested approach:
        // 1) Sort each string and use it as the key.
        // 2) Push the original string into mp[key].
        // 3) Collect all mp values into the answer.
        (void)strs;
        (void)mp;
        return {};
    }
};

struct TestCase {
    vector<string> input;
    vector<vector<string>> expected;
};

string trim(const string& s) {
    size_t left = 0;
    while (left < s.size() && isspace(static_cast<unsigned char>(s[left]))) {
        ++left;
    }

    size_t right = s.size();
    while (right > left && isspace(static_cast<unsigned char>(s[right - 1]))) {
        --right;
    }

    return s.substr(left, right - left);
}

string readAllStdin() {
    ostringstream oss;
    oss << cin.rdbuf();
    return oss.str();
}

bool hasPipedInput() {
#if defined(_WIN32)
    return !_isatty(_fileno(stdin));
#else
    return !isatty(fileno(stdin));
#endif
}

vector<string> parseStringArray(const string& rawInput) {
    size_t leftBracket = rawInput.find('[');
    size_t rightBracket = rawInput.rfind(']');

    if (leftBracket == string::npos || rightBracket == string::npos || leftBracket > rightBracket) {
        return {};
    }

    vector<string> result;
    string current;
    bool inString = false;

    for (size_t i = leftBracket + 1; i < rightBracket; ++i) {
        char c = rawInput[i];
        if (c == '"') {
            if (inString) {
                result.push_back(current);
                current.clear();
            }
            inString = !inString;
            continue;
        }

        if (inString) {
            current.push_back(c);
        }
    }

    return result;
}

string stringArrayToString(const vector<string>& items) {
    string out = "[";
    for (size_t i = 0; i < items.size(); ++i) {
        if (i > 0) {
            out += ",";
        }
        out += "\"" + items[i] + "\"";
    }
    out += "]";
    return out;
}

vector<vector<string>> normalizeGroups(vector<vector<string>> groups) {
    for (auto& group : groups) {
        sort(group.begin(), group.end());
    }
    sort(groups.begin(), groups.end());
    return groups;
}

string groupArrayToString(const vector<vector<string>>& groups) {
    string out = "[";
    for (size_t i = 0; i < groups.size(); ++i) {
        if (i > 0) {
            out += ",";
        }
        out += stringArrayToString(groups[i]);
    }
    out += "]";
    return out;
}

void runSampleCases() {
    vector<TestCase> tests = {
        {
            {"eat", "tea", "tan", "ate", "nat", "bat"},
            {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}}
        },
        {
            {""},
            {{""}}
        },
        {
            {"a"},
            {{"a"}}
        }
    };

    Solution solution;

    cout << "Running sample cases...\n\n";
    for (size_t i = 0; i < tests.size(); ++i) {
        vector<string> input = tests[i].input;
        vector<vector<string>> expected = normalizeGroups(tests[i].expected);
        vector<vector<string>> actual = normalizeGroups(solution.groupAnagrams(input));

        bool passed = (actual == expected);

        cout << "Case " << (i + 1) << ": " << (passed ? "PASS" : "FAIL") << "\n";
        cout << "  Input:    " << stringArrayToString(tests[i].input) << "\n";
        cout << "  Expected: " << groupArrayToString(expected) << "\n";
        cout << "  Got:      " << groupArrayToString(actual) << "\n\n";
    }

    cout << "Tip: implement Solution::groupAnagrams and run again.\n";
    cout << "You can also pass custom input from stdin, for example:\n";
    cout << "strs = [\"eat\",\"tea\",\"tan\",\"ate\",\"nat\",\"bat\"]\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!hasPipedInput()) {
        runSampleCases();
        return 0;
    }

    string raw = trim(readAllStdin());

    if (raw.empty()) {
        runSampleCases();
        return 0;
    }

    vector<string> strs = parseStringArray(raw);

    Solution solution;
    vector<vector<string>> answer = solution.groupAnagrams(strs);
    cout << groupArrayToString(answer) << "\n";

    return 0;
}
