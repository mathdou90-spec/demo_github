#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> srr;
        stringstream ss(path);
        string temp;
        while(getline(ss,temp,'/')) {
            if(temp==""||temp==".") continue;
            if(temp!="..") srr.push_back(temp);
            else if(!srr.empty()) srr.pop_back();
        }
        string result = "";
        for(const string& dir : srr) {
            result += "/" + dir;
        }
        return result.empty() ? "/" : result;
    }
};