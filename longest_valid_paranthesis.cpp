class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> stk;
        vector<int> valid(n, 0);
        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                stk.push(i);
            }
            else if(s[i] == ')') {
                if(stk.empty()) continue;
                valid[stk.top()] = 1;
                valid[i] = 1;
                stk.pop();
            }
        }
        int ans = 0 , count = 0;  
        for(int i=0; i<n; i++) {
            if(valid[i] == 1) {
                count++;
            }
            else count = 0;
            ans = max(ans, count);
        }
        return ans;
    }
};