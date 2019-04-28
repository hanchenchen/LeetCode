#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;


vector<vector<pair<int, int>>> input;
vector<int> col;
vector<vector<pair<int, int>>> output;
int d[] = { -1, 0, 1 };


int search(int i, int p) {
    for (int j = 0; j < input[i].size(); j++) {
        if (p <= input[i][j].second) {
            return input[i][j].first;
        }
    }
}


int search_index(int i, int p) {
    for (int j = 0; j < input[i].size(); j++) {
        if (p <= input[i][j].second) {
            return j;
        }
    }
}


int main() {
    // input
    int n;
    while (cin >> n && n != 0) {
        col.push_back(n);
        vector<pair<int, int>> t;
        int a, b;
        int count = 0;
        while (cin >> a && cin >> b && a != 0 && b != 0) {
            count += b;
            t.push_back(pair<int, int>(a, count));
        }
        input.push_back(t);
    }
    // solve
    for (int i = 0; i < col.size(); i++) {
        int count = input[i][input[i].size() - 1].second; // total pixels
        int c = col[i]; // c pixels in one row
        int r = count / c; // r pixels in one column
        int arr[9];
        for (int j = 0; j < count; j++) {
            int index = j + 1;
            int row = (index - 1) / c + 1;
            int col = index - c * (row - 1);
            int maximum;
            if (search_index(i, index - c - 1) == search(i, index + c + 1)) {
                maximum = 0;
            }
            else {
                for (int m = 0; m < 3; m++) {
                    for (int n = 0; n < 3; n++) {
                        if (row + d[m] >= 1 && row + d[m] <= r && col + d[n] >= 1 && col + d[n] <= c) {
                            arr[3 * m + n] = abs(search(i, index) - search(i, (row + d[m] - 1)*c + col + d[n]));
                        }
                        else {
                            arr[3 * m + n] = 0;
                        }
                    }
                }
                maximum = *max_element(arr, arr + 9);
            }
            if (output.size() == i) {
                vector<pair<int, int>> t;
                t.push_back(pair<int, int>(maximum, 1));
                output.push_back(t);
            }
            else {
                if (maximum == output[i][output[i].size() - 1].first) {
                    output[i][output[i].size() - 1].second++;
                }
                else {
                    output[i].push_back(pair<int, int>(maximum, 1));
                }
            }
        }
    }
    // output
    for (int i = 0; i < col.size(); i++) {
        cout << col[i] << endl;
        for (int j = 0; j < output[i].size(); j++) {
            cout << output[i][j].first << " " << output[i][j].second << endl;
        }
        cout << "0 0" << endl;
    }
    cout << "0" << endl;
}
