#include <iostream>
#include <vector>

using namespace std;

vector<int> getting_input(){
    int n;
    cin >> n;
    vector<int> result(n);
    for(int i = 0; i < n; i++){
        cin >> result[i];
    }
    return result;
}

vector<int> possible_numbers(int max){
    vector<int> result(max);
    for(int i = 0 ; i < max; i++){
        result[i] = i + 1;
    }
    return result;
}

int max_xor(int x, vector<int> inputs){
    int max = x ^ inputs[0];
    int temp;
    for(int i = 1; i < inputs.size(); i++){
        temp = x ^ inputs[i];
        if(max < temp) max = temp;
    }
    return max;
}

void calculating_max_beautiful(vector<int> numbers, vector<int> inputs, int first_index, int last_index, int& min){
    if(first_index == last_index){
        min = max_xor(numbers[first_index], inputs);
        return;
    }
    int min_left, min_right;
    int mid = (first_index + last_index)/2;
    calculating_max_beautiful(numbers, inputs, first_index, mid, min_left);
    calculating_max_beautiful(numbers, inputs, mid + 1, last_index, min_right);
    if(min_left <= min_right){
        min = min_left;
    }
    else{
        min = min_right;
    }
}

int main(){
    vector<int> inputs = getting_input();
    vector<int> numbers = possible_numbers(inputs[inputs.size()-1]);
    int min;
    calculating_max_beautiful(numbers, inputs, 0, numbers.size(), min);
    cout << min << endl;
    return 0;
}