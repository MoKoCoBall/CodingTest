#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    pair<int, int> ans = {0, 1000000};
    
    int s = 0, e = 0;
    int sum = 0;
    
    while(e < sequence.size()) {
        sum += sequence[e++];
        
        while(sum > k && s < e) {
            sum -= sequence[s++];
        }
        
        if(sum == k) {
            if(ans.second - ans.first > e - s) {
                ans = {s, e};
            } 
        } 
    }
    
    return {ans.first, ans.second - 1};
}