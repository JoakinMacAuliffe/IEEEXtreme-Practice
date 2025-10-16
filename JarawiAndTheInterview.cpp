// Incomplete attempt.
// Jarawi and The Interview

#include <iostream>
#include <stack>

using namespace std;

int main() {

    string s, p;
    int q, res;
    cin>s;
    cin>q;
    for(int i=0; i<q; ++i){
        res=0;
        cin>p;
        stack<int> sfx;
        for(int i=0; i<p.size(); ++i){
            sfx.push(p[i]);
        }
        while(sfx.size()!=0) {
            int tmp=0;
            int sz = sfx.size();
            if(s[tmp] == sfx.top()){
                   
            }else{
                tmp++;
            }
            
        }
    }
    
    return 0;
}