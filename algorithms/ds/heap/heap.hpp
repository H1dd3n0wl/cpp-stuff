#include <vector>

//min-heap
class Heap {

    const static int NMAX = 1e6 + 5;

    int a[NMAX] = {};

    int n;

public:
    int get_min() {
        return a[0];
    }

    void remove_min() {
        // sift down after deleting mininum
        a[0] = a[--n];
        int i = 0;
        while (2 * i + 1 < n) {
            int j = 2 * i + 1;
            if (2 * i + 2 < n && a[2 * i + 2] < a[j]) {
                j = 2 * i + 2;
            }
            if (a[i] <= a[j]) {
                break;
            } else {
                a[i] ^= a[j];
                a[j] ^= a[i];
                a[i] ^= a[j];
            }
            i = j;
        }
    }

    void insert(int x) {
        // sifting up
        a[n++] = x;
        int j = n - 1;
        while (j > 0 && a[j] < a[(j - 1) / 2]) {
            a[j] ^= a[(j - 1) / 2];
            a[(j - 1) / 2] ^= a[j];
            a[j] ^= a[(j - 1) / 2];
            j = (j - 1) / 2;
        }
    }

};


// O(n), sifting down from the end of an array
void heapify(std::vector<int> &a) {
    int n = (int)a.size();
    for (int k = n / 2; k >= 0; --k) {
        int i = k;
        while (2 * i + 1 < n) {
            int j = 2 * i + 1;
            if (2 * i + 2 < n && a[2 * i + 2] < a[j]) {
                j = 2 * i + 2;
            }
            if (a[i] <= a[j]) {
                break;
            } else {
                a[i] ^= a[j];
                a[j] ^= a[i];
                a[i] ^= a[j];
            }
            i = j;
        }
    }
}