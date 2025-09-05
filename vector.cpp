#include <vector>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n;
    
    cout << "Number of Vectors: ";
    cin >> n;
    
    vector<vector<int>> v;
    
    for (int i=0; i<n; i++){
        
        int ele;
        cout << "Number of Elements: ";
        cin >> ele;
        
        vector<int> temp;
        
        for(int j=0; j<ele; j++){
            int x;
            cin >> x;

            temp.push_back(x);
        }
        
        v.push_back(temp);
    }
       
    cout << endl << "Vector Elements: " << endl;

    
    for (int i=0; i<v.size(); i++){

        cout << "Vector " << i+1 << ": " ;

        for(int j=0; j<v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}