class Solution {
public:
    string simplifyPath(string path) {
        string res, name;
        if (path.back() != '/') path += '/';
        for (auto c : path) {
            if (c != '/') name += c;
            else {
                if (name == "..") {
                    while (res.size() && res.back() != '/') res.pop_back();
                    if (res.size()) res.pop_back();
                } else if (name != "." && name != "") {
                    res += '/' + name;
                }
                name.clear();
            }
        }
        if (res.empty()) res = "/";
        return res;
    }
};