int Solution::braces(string A) {
    stack<char> s;
    for(int i=0; i<A.size(); i++) {
        if(A[i] != ')') {
            s.push(A[i]);
        }
        else {
            int flag = 0;
            while(!s.empty() && s.top()!='(') {
                char ch = s.top();
                if(ch == '+' || ch == '-' || ch == '*' || ch == '/') flag = 1;
                s.pop();
            }
            s.pop();
            if(!flag) return 1;
        }
    }
    return 0;
}
