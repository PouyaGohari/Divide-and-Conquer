#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<vector<int>> getting_input(){
    int numb;
    int n;
    int m;
    cin >> n;
    vector<vector<int>> numbers;
    while(cin >> m){
        vector<int> number;
        for(int i = 0; i < m; i++){
            cin >> numb;
            number.push_back(numb);
        }
        numbers.push_back(number);
    }
    return numbers;
}

void merge_tool(vector<int> acc1, vector<int> acc2, vector<int>& acc){
    vector<int> result = acc1;
    result.insert(result.end(), acc2.begin(), acc2.end());
    acc = result;
    int first_pos = 0;
    int second_pos = acc1.size();
    int last_index = result.size() - 1;
    int first_index = 0;
    int mid_index = acc1.size() - 1;
    for(int i = 0; i < last_index - first_index + 1; i++){
        if(first_pos < mid_index + 1 && second_pos < last_index + 1){
            if(result[first_pos] < result[second_pos]){
                acc[i + first_index] = result[first_pos];
                first_pos ++;
                continue;
            }
            else{
                acc[i + first_index] = result[second_pos];
                second_pos ++;
                continue;
            }
        }
        else if(first_pos == mid_index + 1 && second_pos < last_index + 1){
            acc[i + first_index] = result[second_pos];
            second_pos ++;
            continue;
        }
        else if(first_pos < mid_index + 1 && second_pos == last_index + 1){
            acc[i + first_index] = result[first_pos];
            first_pos ++;
            continue;
        }
    }
}

void merge(vector<vector<int>> arrays, vector<int>& acc){
    if(arrays.size() == 1){
        acc = arrays[0];
        return;
    }
    int mid = arrays.size()/2;
    vector<vector<int>> first_half(arrays.begin(), arrays.begin() + mid);
    vector<vector<int>> second_half(arrays.begin() + mid, arrays.end());
    vector<int> acc1;
    vector<int> acc2;
    merge(first_half, acc1);
    merge(second_half, acc2);
    merge_tool(acc1, acc2, acc);
}

void print_vec(vector<int> acc){
    for(auto x : acc){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    vector<vector<int>> numbers = getting_input();
    vector<int> acc;
    merge(numbers, acc);
    print_vec(acc);
    return 0;
}