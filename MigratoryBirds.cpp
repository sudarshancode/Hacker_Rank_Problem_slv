#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'migratoryBirds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
/*
    //Optimal Solution
    vector<int> freq(6, 0); // Assuming bird types are in the range 1 to 5

    // Count frequency of each bird type
    for (int bird : arr) {
        freq[bird]++;
    }

    int maxCount = 0;
    int mostCommonBird = -1;

    // Find the most common bird type
    for (int i = 1; i <= 5; i++) {
        if (freq[i] > maxCount) {
            maxCount = freq[i];
            mostCommonBird = i;
        }
    }

    return mostCommonBird;
*/
int migratoryBirds(vector<int> arr) {
    int f;
    int i=0;
    int previous_count=0;
    while(i<arr.size()){
        int count=0;
        for(int j=i;j<arr.size();j++)
        {
            if(arr[i]==arr[j]){
                count++;
            }
        }
        cout<<arr[i]<<" is "<<count<<" times"<<endl;
        if(i==0){
            previous_count=count;
            f=arr[i];
        }else{
            if(previous_count<count){
                previous_count=count;
                f=arr[i];
            }
        }
        i++;
        for(int l=0;l<i;l++){
            if(arr[l]==arr[i]){
                i++;
            }
        }
    }
    return f;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = migratoryBirds(arr);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
