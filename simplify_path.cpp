class Solution {
public:
    string simplifyPath(string path) {
        vector<string> items;
        for(int i=0; i<path.size();) {
            if(path[i] == '/') {
                int j=i+1;
                string s = "";
                while(j < path.size() && path[j] != '/') {
                    s.push_back(path[j++]);
                }
                items.push_back(s);
                i=j;
            }
        }
        stack<string> s;
        for(int i=0; i<items.size(); i++) {
            cout << "\nIt is " << items[i];
        }
        for(int i=0; i<items.size(); i++) {
            if(items[i] == "") {
                continue;
            }
            else if(items[i] == ".") {
                continue;
            }
            else if(items[i] == "..") {
                if(!s.empty()) s.pop();
            }
            else s.push(items[i]);
        }
        string ans = "";
        stack<string> rev;
        while(!s.empty()) {
            rev.push(s.top());
            s.pop();
        }
        while(!rev.empty()) {
            ans.push_back('/');
            ans.append(rev.top());
            rev.pop();
        }
        if(ans == "") ans = "/";
        return ans;
    }
};