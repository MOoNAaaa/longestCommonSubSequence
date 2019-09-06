#include<iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
class Solution{
public:
    // 最长公共子序列初始化改进
    string longestCommonSubSequence2(string& str1, string& str2){
        // 二维dp数组多添加一行一列便于初始化
        vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
        vector<vector<int>> flag(str1.size() + 1, vector<int>(str2.size() + 1, -1));
        // 计算过程
        for(int i=1; i<=str1.length(); ++i){
            for(int j=1; j<=str2.length(); ++j){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    flag[i][j] = 0; // 向左上角
                }else{
                    if(dp[i-1][j] > dp[i][j-1]){
                        dp[i][j] = dp[i-1][j];
                        flag[i][j] = 1; // 向上
                    } else{
                        dp[i][j] = dp[i][j-1];
                        flag[i][j] = 2; // 向左
                    }
                }

            }
        }
        // 打印结果
        string res;
        int i = str1.length(), j = str2.length();
        while (i > 0 && j > 0){
            if(flag[i][j] == 0){
                res += str1[i-1];
                i--;
                j--;
            } else if(flag[i][j] == 1){
                i--;
            } else if(flag[i][j] == 2){
                j--;
            } else{
                break;
            }
        }
        // 反转字符串
        reverse(res.begin(), res.end());
        return res;
    }
    // 最长公共子序列
    string longestCommonSubSequence(string& str1, string& str2){

        vector<vector<int>> dp(str1.size(), vector<int>(str2.size(), 0));
        vector<vector<int>> flag(str1.size(), vector<int>(str2.size(), -1));
        // 初始化第0列
        for(int i=0; i<str1.length(); ++i){
            if(str1[i] == str2[0]){
                while (i < str1.length()){
                    dp[i++][0] == 1;
                }
            }
        }
        // 初始化第0行
        for(int j=0; j<str2.length(); ++j){
            if(str1[0] == str2[j]){
                while (j < str2.length()){
                    dp[0][j++] == 1;
                }
            }
        }
        for(int i=1; i<str1.length(); ++i){
            for(int j=1; j<str2.length(); ++j){
                if(str1[i] == str2[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    flag[i][j] = 0; // 向左上角
                }else{
                    if(dp[i-1][j] > dp[i][j-1]){
                        dp[i][j] = dp[i-1][j];
                        flag[i][j] = 1; // 向上
                    } else{
                        dp[i][j] = dp[i][j-1];
                        flag[i][j] = 2; // 向左
                    }
                }

            }
        }
        // 打印结果
        string res;
        int i = str1.length() - 1, j = str2.length() - 1;
        while (i >= 0 && j >= 0){
            if(flag[i][j] == 0){
                res += str1[i];
                i--;
                j--;
            } else if(flag[i][j] == 1){
                i--;
            } else if(flag[i][j] == 2){
                j--;
            } else{
                break;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main(){
    Solution solution;
    string str1, str2;
    while (cin>>str1>>str2){
        string res = solution.longestCommonSubSequence2(str1, str2);
        cout<<res<<endl;
    }

    return 0;
}