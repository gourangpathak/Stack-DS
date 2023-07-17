class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int n = s.size();
        vector<int> valid(n, 0);
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                stk.push(i);
            }
            else if (s[i] == ')')
            {
                if (stk.empty())
                    continue;
                valid[stk.top()] = 1;
                valid[i] = 1;
                stk.pop();
            }
        }
        string ans;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == ')')
            {
                if (valid[i])
                    ans.push_back(s[i]);
            }
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};