//problemDes: https://www.hackerrank.com/challenges/day-of-the-programmer/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    char s[20];
    int feb=28;
    if(year>1918){
        if((year%4==0) && (year%400==0 || year%100!=0)){
            feb=feb+1;
        }
        int numbersOfDay=0,day=0,month=9;
        for(int i=1;i<8;i++){
            if(i==2){
                numbersOfDay=numbersOfDay+feb;
            }else if(i%2==0){
                numbersOfDay=numbersOfDay+30;
            }else{
                numbersOfDay=numbersOfDay+31;
            }  
        }
        numbersOfDay=numbersOfDay+31;
        day=256-numbersOfDay;
        s[0]=(char)(day/10);
        s[1]=(char)(day%10);
        s[3]='.';
        s[4]='0';
        s[5]='9';
        s[6]='.';
        snprintf(s, sizeof(s), "%02d.%02d.%d", day ,month, year);
    }else if(year==1918){
        if(year%4==0){
            feb=feb+1;
        }
        int numbersOfDay=0,day=0,month=9;
        for(int i=1;i<8;i++){
            if(i==2){
                numbersOfDay=numbersOfDay+feb;
            }else if(i%2==0){
                numbersOfDay=numbersOfDay+30;
            }else{
                numbersOfDay=numbersOfDay+31;
            }  
        }
        numbersOfDay=numbersOfDay+31;
        day=256-numbersOfDay +13;
        s[0]=(char)(day/10);
        s[1]=(char)(day%10);
        s[3]='.';
        s[4]='0';
        s[5]='9';
        s[6]='.';
        snprintf(s, sizeof(s), "%02d.%02d.%d", day ,month, year);
    }
    else{
        if(year%4==0){
            feb=feb+1;
        }
        int numbersOfDay=0,day=0,month=9;
        for(int i=1;i<8;i++){
            if(i==2){
                numbersOfDay=numbersOfDay+feb;
            }else if(i%2==0){
                numbersOfDay=numbersOfDay+30;
            }else{
                numbersOfDay=numbersOfDay+31;
            }  
        }
        numbersOfDay=numbersOfDay+31;
        day=256-numbersOfDay;
        s[0]=(char)(day/10);
        s[1]=(char)(day%10);
        s[3]='.';
        s[4]='0';
        s[5]='9';
        s[6]='.';
        snprintf(s, sizeof(s), "%02d.%02d.%d", day ,month, year);
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

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
