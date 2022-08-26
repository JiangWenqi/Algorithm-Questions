#include <iostream>
#include <string>

using namespace std;
string decrypt(const string& word){
    string res = "";
    int val = 1;
    for (int i = 0; i < word.size(); i++) {
        char ec = word[i];
        char dc = ec - val;
        while (dc < 'a') dc += 26;
        res.push_back(dc);
        val = ec;
    }
    return res;
}

int main() {
    return 0;
}