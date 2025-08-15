class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string component = "";
        
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == '/') {
                if (!component.empty()) {
                    if (component == "..") {
                        if (!stack.empty()) {
                            stack.pop_back();
                        }
                    } else if (component != ".") {
                        stack.push_back(component);
                    }
                    component = "";
                }
            } else {
                component += path[i];
            }
        }
        
        if (!component.empty()) {
            if (component == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else if (component != ".") {
                stack.push_back(component);
            }
        }
        
        string result = "/";
        for (int i = 0; i < stack.size(); i++) {
            result += stack[i];
            if (i < stack.size() - 1) {
                result += "/";
            }
        }
        
        return result;
    }
};