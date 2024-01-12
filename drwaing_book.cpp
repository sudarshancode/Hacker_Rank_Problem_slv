Prob Dev: https://www.hackerrank.com/challenges/drawing-book/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */

int pageCount(int n, int p) {
    int size;
    vector<int> arr;
    arr.push_back(0);
    int count=0;
    int startPageCount=0;
    int endPageCount=0;
    if(n%2==0){
        size=n+1;
        for(int i=1;i<=size;i++){
            arr.push_back(i);
        }
    }else{
        size=n;
        for(int i=1;i<=size;i++){
           arr.push_back(i);
        }
    }
     
    
    for(int j=1;j<=size;j++){
        if(j==1){
            if(arr[j]==p){
                startPageCount=count;
                break;
            }
        }else{
            if(arr[j]==p){
                startPageCount=count;
                break;
            }else if(arr[j+1]==p){
                startPageCount=count;
                break;
            }else{
                count++;
                j++;
                continue;
            }
        }
        count++;
    }
    count=0;
    for(int j=size;j>=1;j--){
        if(j==1){
            if(arr[j]==p){
                endPageCount=count;
                break;
            }
        }else{
            if(arr[j]==p){
                endPageCount=count;
                break;
            }else if(arr[j-1]==p){
                endPageCount=count;
                break;
            }else{
                count++;
                j--;
                continue;
            }
        }
        count++;
    }
    if(startPageCount>endPageCount){
        return endPageCount;
    }else{
        return startPageCount;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
