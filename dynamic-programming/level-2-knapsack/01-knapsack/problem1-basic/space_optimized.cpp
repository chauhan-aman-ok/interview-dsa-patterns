// space complexity - O(n)
// time complexity - O(m*bag)

int tabulation(vector<int> &val, vector<int> &wt, int bag) {
		vector<int> prev(bag+1);
		for (int i = 0; i<val.size(); i++) {
		    vector<int> curr(bag+1);
			for (int j = 0; j <= bag; j++) {
				if (i == 0) {
					if (wt[i] <= j) {
						curr[j] = val[i]; 
					}
				} else {
						if (wt[i] <= j) {
							curr[j] = max(val[i]+prev[j - wt[i]], prev[j]);
						} else {
							curr[j] = prev[j];
						}
			    }
			}
			prev=curr;
		}
			return prev[bag];
		}
		
		int knapsack(int W, vector<int> &val, vector<int> &wt) {
			// code here
			return tabulation(val, wt, W);
    }

