#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

void LCS(vector <int> v1, vector <int> v2){
    int l1 = v1.size(),l2 = v2.size();
    vector <vector <int> > v(l1+1,vector<int> (l2+1));
    vector <int> ans;
    for(int i=0;i <= l1;i++){
        for(int j=0;j <= l2;j++){
            if(i == 0 || j == 0) v[i][j] = 0;
            else if(v1[i-1] == v2[j-1])
                v[i][j] = v[i-1][j-1] + 1;
            else v[i][j] = max(v[i-1][j],v[i][j-1]);
        }
    }
    cout << "Longest Comman Subsequence length: " << v[l1][l2] << endl;
    cout << "Displaying the subsequence: " << endl;
    while(l1 != 0 && l2 != 0){
        if(v[l1][l2] == v[l1][l2-1]) l2--;
        else if(v[l1][l2] == v[l1-1][l2]) l1--;
        else if(v[l1][l2] == (1 + v[l1-1][l2-1])){
            ans.push_back(v1[l1-1]);
            l1--;l2--;
        }
    }
    for(int k=ans.size()-1;k >= 0;k--)
        cout << ans[k] << " ";
    cout << endl;
}

int main() {
    int n1,n2;
    vector <int> v1,v2;
    cout << "Enter 1st array length: " << endl;
    cin >> n1;
    cout << "Enter 2nd array length: " << endl;
    cin >> n2;
    int elem;
    cout << "Enter 1st array elements: " << endl;
    for(int i=0;i<n1;i++){
        cin >> elem;
        v1.push_back(elem);
    }
    cout << "Enter 2nd array elements: " << endl;
    for(int i=0;i<n2;i++){
        cin >> elem;
        v2.push_back(elem);
    }
    LCS(v1,v2);
    return 0;
}
