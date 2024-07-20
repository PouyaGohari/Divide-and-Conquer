#include <iostream>
#include <vector>

using namespace std;

struct zip{
    bool equal_array;
    vector<int> dictionary;
    vector<int> help_array;
};

string getting_input(){
    string input;
    cin >> input;
    return input;
}

vector<int> dictionary(string input){
    vector<int> dict_array(26, 0);
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for(auto chr : input){
        dict_array[chr - 'a'] = 1; 
    }
    return dict_array;
}

vector<int> help_array(string input, vector<int> dictionary){
    vector<int> helping_array(input.size(), 0);
    for(int i = 0; i < input.size(); i++){
        if(dictionary[input[i]-'a'] == 1 && dictionary[26-(input[i]-'a')-1] == 1){
            helping_array[i] = 1;
        }
    }
    return helping_array;
}

bool whole_are_one(vector<int> help_array, int first, int last){
    for(int i = first; i <= last; i++){
        if(help_array[i] == 0) return false;
    }
    return true;
}

bool equal_arrays(vector<int> help1, vector<int> help2){
    for(int i = 0; i < help1.size(); i++){
        if(help1[i] != help2[i]) return false;
    }
    return true;
}

zip find_acc(string input, vector<int> help ,int first_index, int last_index){
    vector<int> new_dict = dictionary(input.substr(first_index, last_index - first_index + 1));
    vector<int> help2 = help_array(input.substr(first_index, last_index - first_index + 1), new_dict);
    vector<int> help1(help.begin() + first_index, help.begin() + last_index + 1);
    return {equal_arrays(help1, help2), new_dict, help2};
}

int finding_piviot(vector<int> help, int first_index, int last_index){
    int piviot = (first_index + last_index) / 2;
    if(help[piviot] == 0) return piviot;
    for(int i = 0; i <= (last_index-first_index)/2 + 1; i++){
        if(piviot - i > first_index && help[piviot - i] == 0) {
            return (piviot - i);
        }
        if(piviot + i < last_index && help[piviot + i] == 0) {
            return (piviot + i);
        }
    }
    if(help[first_index] == 0) return first_index;
    return last_index;
}

string max_sub_string(string input, vector<int> help, int first_index, int last_index){
    if(first_index >= last_index){
        return "";
    }
    if(whole_are_one(help, first_index, last_index)){
        zip temp = find_acc(input, help, first_index, last_index);
        if(temp.equal_array){
            return input.substr(first_index, last_index - first_index + 1);
        }
        else{
            int piviot = finding_piviot(temp.help_array, 0, temp.help_array.size()-1);
            string acc_left = max_sub_string(input.substr(first_index, last_index-first_index+1), temp.help_array, 0, piviot-1);
            string acc_right = max_sub_string(input.substr(first_index, last_index-first_index+1), temp.help_array, piviot + 1, temp.help_array.size()-1);
            if(acc_left.size() >= acc_right.size()){
                return acc_left;
            }
            else{
                return acc_right;
            }
        }
    }
    int piviot = finding_piviot(help, first_index, last_index); 
    if(piviot == last_index && help[last_index] == 1){
        return "";
    }
    string acc_left = max_sub_string(input, help, first_index,piviot - 1);
    string acc_right = max_sub_string(input, help, piviot + 1, last_index);
    if(acc_left.size() >= acc_right.size()){
        return acc_left;
    }
    else{
        return acc_right;
    }
}

int main(){
    string input = getting_input();
    vector<int> dict_array = dictionary(input);
    vector<int> helping_array = help_array(input, dict_array);
    string acc =  max_sub_string(input, helping_array, 0, input.size()-1);
    cout << acc << endl;
    return 0;
}