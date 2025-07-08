#include <string>
#include <vector>

std::vector<int> z_function(std::string& s) {
    std::vector<int> z(s.length());
    int l = 0;
    int r = 0;
    for (int i = 1; i < s.length(); ++i) {
        if (r >= i) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while (z[i] + i < s.length() && s[z[i]] == s[z[i] + i]) {
            z[i]++;
        }
        if (z[i] + i - 1 > r) {
            r = z[i] + i - 1;
            l = i;
        }
    }
    return z;
}