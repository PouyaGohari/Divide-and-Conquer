#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

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

int main(){
    string input = getting_input();
    vector<int> dict_array = dictionary(input);
    vector<int> helping_array = help_array(input, dict_array);
    return 0;
}