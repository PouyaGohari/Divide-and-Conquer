#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> dictionary(string input){
    vector<int> dict_array(26, 0);
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for(auto chr : input){
        dict_array[chr - 'a'] = 1; 
    }
    return dict_array;
}

int main(){
    
    return 0;
}