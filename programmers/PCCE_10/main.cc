#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    int cal = 0;
    vector<vector<int>> dp(park.size() + 1, vector<int>(park[0].size() + 1, 0));

    for(int i = park.size()-1; i >= 0; i--) {
        for(int j = park[0].size() - 1; j >= 0; j--) {
            if(park[i][j] != "-1") { dp[i][j] = 0; continue; }
            dp[i][j] = 1 + min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]});
            cal = max(cal, dp[i][j]);
        }
    }
      
    for(int i : mats) if(i <= cal) answer = max(answer, i);
            
    return !answer ? -1 : answer;
}