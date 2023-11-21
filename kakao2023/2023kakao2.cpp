#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define endl "\n"

using namespace std;

vector<int> staticDeliveries;
vector<int> staticPickup;
int startDeli;
int startPickup;
long long max_Delivery(int cap){
    long long maxNotZeroDel = -1;
    int leftCap = cap;
    for(int i=startDeli; i>=0;i--){
        if(staticDeliveries[i] != 0){
            if(maxNotZeroDel == -1){
                maxNotZeroDel = i;
            }
            if(leftCap>=staticDeliveries[i]){
                leftCap-=staticDeliveries[i];
                staticDeliveries[i] = 0;
            }
            if(leftCap<staticDeliveries[i]){
                staticDeliveries[i]-=leftCap;
                startDeli = i;
                break;
            }
        }
    }
    return maxNotZeroDel;
}

long long max_Pickup(int cap){
    long long maxNotZeroPick = -1;
    int leftCap = cap;
    for(int i=startPickup; i>=0;i--){
        if(staticPickup[i] != 0){
            if(maxNotZeroPick == -1){
                maxNotZeroPick = i;
            }
            if(leftCap>=staticPickup[i]){
                leftCap-=staticPickup[i];
                staticPickup[i] = 0;
            }
            if(leftCap<staticPickup[i]){
                staticPickup[i]-=leftCap;
                startPickup = i;
                break;
            }
        }
    }
    return maxNotZeroPick;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    staticDeliveries = deliveries;
    staticPickup = pickups;
    startDeli = staticDeliveries.size()-1;
    startPickup = staticPickup.size()-1;
    while(true){
        long long maxDel = max_Delivery(cap);
        long long maxPick = max_Pickup(cap);
        if(maxDel == -1 && maxPick == -1){
            break;
        }
        long long maxMove = max(maxDel, maxPick);
        answer += (maxMove+1)*2;
    }
    return answer;
} 
