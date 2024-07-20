#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>

using namespace std;

struct my_input{
    bitset<30> max;
    vector<bitset<30>> array;
};

my_input getting_input(){
    int n;
    cin >> n;
    vector<bitset<30>> result;
    int max_int = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(max_int < x) max_int = x;
        bitset<30> y(x);
        result.push_back(y);
    }
    bitset<30> max(max_int);
    return {max, result};
}

int bigest_index(bitset<30> max){
    int x = 0;
    for(int i = 29; i >= 0; i--){
        if(max[i] == 1){
            x = i;
            break;
        }
    }
    x++;
    return x;
}

bitset<30> max_xor(const bitset<30>& x, const vector<bitset<30>>& inputs) {
    bitset<30> max = x ^ inputs[0];
    for (int i = 1; i < inputs.size(); i++) {
        bitset<30> temp = x ^ inputs[i];
        if (temp.to_ulong() > max.to_ulong()) {
            max = temp;
        }
    }
    return max;
}

bitset<30> min_max_xor(const vector<bitset<30>>& array,const int biggest_size,const bitset<30> min) {
    if (biggest_size == 0) {
        bitset<30> min_left = min, min_right = min;
        min_left[biggest_size] = 0;
        min_right[biggest_size] = 1;
        min_left = max_xor(min_left, array);
        min_right = max_xor(min_right, array);
        if (min_left.to_ulong() <= min_right.to_ulong()) {
            return min_left;
        }
        return min_right;
    }
    bitset<30> min_left = min, min_right = min;
    min_left[biggest_size] = 0;
    min_right[biggest_size] = 1;
    min_left = min_max_xor(array, biggest_size - 1, min_left);
    min_right = min_max_xor(array, biggest_size - 1, min_right);
    if (min_left.to_ulong() <= min_right.to_ulong()) {
        return min_left;
    }
    return min_right;
}


int main(){
    my_input inputs = getting_input();
    int bigest_size = bigest_index(inputs.max);
    bitset<30> x(0);
    x = min_max_xor(inputs.array, bigest_size-1, x);
    int num = x.to_ulong();
    cout << num << endl;
    return 0;
}