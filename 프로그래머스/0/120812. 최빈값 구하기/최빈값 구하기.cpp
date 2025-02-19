#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int val = -1;
    bool flag = false;
    map<int, int> freq;
    
    for(auto num : array) {
        freq[num]++;
        
        if(freq[num] > answer) {
            answer = freq[num];
            val = num;
            flag = false;
        }
        else if(freq[num] == answer) {
            flag = true;
        }
    }
    
    return flag ? -1 : val;
}