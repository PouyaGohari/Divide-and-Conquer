#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> getting_input() {
    int n;
    cin >> n;
    vector<vector<int>> numbers;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int> number(m);
        for (int j = 0; j < m; j++) {
            cin >> number[j];
        }
        numbers.push_back(number);
    }

    return numbers;
}

vector<int> merge_tool(const vector<int>& acc1, const vector<int>& acc2) {
    vector<int> acc;
    int i = 0, j = 0;

    while (i < acc1.size() && j < acc2.size()) {
        if (acc1[i] < acc2[j]) {
            acc.push_back(acc1[i]);
            i++;
        } else {
            acc.push_back(acc2[j]);
            j++;
        }
    }

    while (i < acc1.size()) {
        acc.push_back(acc1[i]);
        i++;
    }

    while (j < acc2.size()) {
        acc.push_back(acc2[j]);
        j++;
    }

    return acc;
}

vector<int> merge(vector<vector<int>>& arrays) {
    if (arrays.size() == 1) {
        return arrays[0];
    }

    int mid = arrays.size() / 2;
    vector<vector<int>> first_half(arrays.begin(), arrays.begin() + mid);
    vector<vector<int>> second_half(arrays.begin() + mid, arrays.end());

    vector<int> acc1 = merge(first_half);
    vector<int> acc2 = merge(second_half);

    return merge_tool(acc1, acc2);
}

void print_vec(const vector<int>& acc) {
    for (int x : acc) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> numbers = getting_input();
    vector<int> acc = merge(numbers);
    print_vec(acc);
    return 0;
}
