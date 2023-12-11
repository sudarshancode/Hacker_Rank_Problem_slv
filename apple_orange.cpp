#include<iostream>
#include<vector>
using namespace std;
void appleOrange(int s,int t,int a,int b,vector<int> apple,vector<int>org){
    int count_apple=0;
    int count_org=0;
    for(int i=0;i<apple.size();i++){
        if(apple[i]>0){
            int app_dis=a+apple[i];
            if(app_dis>=s && app_dis<=t){
                count_apple++;
            }
        }
    }
    cout<<count_apple<<endl;
    for(int i=0;i<org.size();i++){
        if(org[i]<0){
            int org_dis=b+org[i];
            if(org_dis>=s && org_dis<=t){
                count_org++;
            }
        }
    }
    cout<<count_org<<endl;
}
int main(){
    int s,t,a,b,m,n;
    vector<int> apple;
    vector<int> org;
    cin>>s>>t;
    cin>>a>>b;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        int d=0;
        cin>>d;
        apple.push_back(d);
    }
    for(int k=0;k<n;k++){
        int od=0;
        cin>>od;
        org.push_back(od);
    }
    appleOrange(s,t,a,b,apple,org);
    return 0;
}