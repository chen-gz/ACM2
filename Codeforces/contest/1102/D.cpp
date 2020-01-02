#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
//    FILE *file = freopen("../input", "r", stdin);
    int n;
    cin >> n;
    string str;
    cin >> str;
    int cnt0, cnt1, cnt2;
    cnt0 = cnt1 = cnt2 = 0;
    for (auto i:str) {
        if (i == '0')
            cnt0++;
        else if (i == '1')
            cnt1++;
        else if (i == '2')
            cnt2++;
    }
    int rest0 = -n/3 + cnt0;
    int rest1 = -n/3 + cnt1;
    int rest2 = -n/3 + cnt2;

    int lack0 = -rest0;
    int lack1 = -rest1;
    int lack2 = -rest2;
    int cnt = 0;
    //section0
    while(lack0 > 0){
        if(str[cnt] == '1'){
            if(rest1 > 0){
                str[cnt] = '0';
                rest1 --;
                lack1++;
                lack0--;
                rest0++;
            }
        }
        else if(str[cnt] == '2'){
            if(rest2> 0){
                str[cnt] = '0';
                rest2 --;
                lack2++;
                lack0--;
                rest0++;
            }
        }
        else if(str[cnt] != '0'){
            str[cnt] = '0';
            lack0 --;
            rest0++;
        }
        cnt++;
    }
    //section1
    cnt =0;
    cnt0 = 0;
    while(lack1 > 0){
        if(str[cnt] == '0'){
            cnt0++;
            if(rest0 > 0 && cnt0> n/3){
                str[cnt] = '1';
                rest0 --;
                lack0++;
                lack1--;
                rest1++;
            }
        }
        else if(str[cnt] == '2'){
            if(rest2> 0){
                str[cnt] = '1';
                rest2 --;
                lack2++;
                lack1--;
                rest1++;
            }
        }
        else if(str[cnt] != '1'){
            str[cnt] = '1';
            lack1 --;
            rest1++;
        }
        cnt++;
    }

    cnt =0;
    cnt0=0;
    cnt1=0;
    while(lack2 > 0){
        if(str[cnt] == '0'){
            cnt0++;
            if(rest0 > 0 && cnt0>n/3){
                str[cnt] = '2';
                rest0 --;
                lack0++;
                lack2--;
                rest2++;
            }
        }
        else if(str[cnt] == '1'){
            cnt1++;
            if(rest1> 0 && cnt1> n/3){
                str[cnt] = '2';
                rest1 --;
                lack1++;
                lack2--;
                rest2++;
            }
        }
        else if(str[cnt] != '2'){
            str[cnt] = '2';
            lack2 --;
            rest2++;
        }
        cnt++;
    }
    cout<<str<<endl;
    // cout << cnt0 << " " << cnt1 << " " << cnt2 << endl;
    return 0;
}
