//
//  histogram.cpp
//  Stack
//
//  Created by 신예지 on 27/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangle(vector<int> heights) {
    int maxArea = 0;
    int len = heights.size();
    stack<int> s;
    
    for(int i=0; i<=len; i++) {
        int height;
        if(i==len) height = 0;
        else height = heights[i];
        
        if(s.empty() || height>=heights[s.top()]) s.push(i);
        else {
            int top = s.top();
            s.pop();
            
            maxArea = max(maxArea, heights[top] * (s.empty()? i : i-1-s.top()));
            i--;
        }
    }
    
    return maxArea;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> heights;
    int temp;
    for(int i=0; i<n; i++) {
        cin >> temp;
        heights.push_back(temp);
    }
    cout << largestRectangle(heights);
}
