#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	// Write your code here.
	int col0 = 1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (matrix[i][j] == 0 ) {
				if (j==0) col0 = 0;
				else matrix[0][j]=0;
				matrix[i][0]=0;
			}
		}
	}
	for (int i=1; i<n; i++) {
		for(int j=1; j<m; j++) {
		   if ((matrix[0][j]==0) || (matrix[i][0]==0)) {
			   matrix[i][j] = 0;
		   }
		}
	}

	if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

	return matrix;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}