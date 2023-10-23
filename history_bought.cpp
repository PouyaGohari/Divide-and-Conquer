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
    int x = 0;
    int y = 0;
    for(int i = 0; i < acc1.size() + acc2.size(); i++){
        if(x < acc1.size() && y < acc2.size()){
            if(acc1[x] < acc2[y]){
                acc.push_back(acc1[x]);
                x++;
                continue;
            }
            else{
                acc.push_back(acc2[y]);
                y++;
                continue;
            }
        }
        else if(x == acc1.size() && y < acc2.size()){
            acc.push_back(acc2[y]);
            y++;
            continue;
        }
        else if(x < acc1.size() && y == acc2.size()){
            acc.push_back(acc1[x]);
            x++;
            continue;
        }
    }
}

void merge(vector<vector<int>> arrays, int first_index, int last_index, vector<int>& acc){
    if(first_index == last_index){
        acc = arrays[first_index];
        return;
    }
    int mid = (first_index + last_index)/2;
    vector<int> acc1;
    vector<int> acc2;
    merge(arrays, first_index, mid ,acc1);
    merge(arrays, mid + 1, last_index, acc2);
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
    merge(numbers, 0, numbers.size() - 1, acc);
    print_vec(acc);
    return 0;
}