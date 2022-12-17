class Solution {
public:
    bool isValid(string s) {
        vector<char> c;

        for (int i = 0; i < s.size(); ++i) {
            switch(s.at(i)) {
                case '(':
                case '{':
                case '[':
                    c.push_back(s.at(i));
                    break;
                case ')':
                    if (c.size() == 0 || c.back() != '(') {
                        return false;
                    }
                    c.pop_back();
                    break;
                case '}':
                    if (c.size() == 0 || c.back() != '{') {
                        return false;
                    }
                    c.pop_back();
                    break;
                case ']':
                    if (c.size() == 0 || c.back() != '[') {
                        return false;
                    }
                    c.pop_back();
                default:
                    break;
            }
        }

        if (c.size() != 0)
            return false;
    
        return true;  
    }
};
