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

int main(){
    string input = getting_input();
    vector<int> dict_array = dictionary(input);
    return 0;
}