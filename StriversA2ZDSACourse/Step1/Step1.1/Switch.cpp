//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        cout<<setprecision(3)<<fixed;
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i]<< " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    double switchCase(int choice, vector<double> &arr) {
        // code here
        double area;
        switch (choice)
        {
        case 1:
            area = 3.14 * arr[0] * arr[0];
            return area;
            break;
        case 2:
            area = arr[0] * arr[1];
            return area;
            break;
        default:
            break;
        }
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int choice;
        scanf("%d",&choice);
        
        
        vector<double> arr(choice);
        Array::input(arr,choice);
        
        Solution obj;
        double res = obj.switchCase(choice, arr);
        // cout<<fixed<<endl;
        if(res == int(res)){
            cout<<int(res)<<endl;
            continue;
        }
        cout<<setprecision(14)<<fixed;
        // 
        // }else{
            cout<<res<<endl;
        // }
        
    }
}

// } Driver Code Ends


// In this one if you are solving it in c++ then you have to use the setprecision() function to get the correct answer but GFG doesnt allow it. Right when I was submitting it precison was 14 and output were rounded off to 2 decimal.
// So dont worry about it you are not wrong.