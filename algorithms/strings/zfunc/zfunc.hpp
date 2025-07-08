#include <string>
#include <vector>

std::vector<int> z_function(std::string& s) {
    std::vector<int> res(s.length());
    int l = 0;
    int r = 0;
    for (int i = 1; i < s.length(); ++i) {
        if (r >= i) {
            res[i] = std::min(r - i + 1, res[i - l]);
        }
        while (res[i] + i < s.length() && s[res[i]] == s[res[i] + i]) {
            res[i]++;
        }
        if (res[i] + i - 1 > r) {
            r = res[i] + i - 1;
            l = i;
        }
    }
    return res;
}