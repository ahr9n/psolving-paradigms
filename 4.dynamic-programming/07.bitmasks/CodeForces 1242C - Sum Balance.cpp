//problem link: https://codeforces.com/contest/1242/problem/C
//difficutly: CF 2400

/*solution idea:
  First of all we know that each group must eventually have sum equal to (SUM) / k, where SUM is the sum of all elements in all groups
  Second we construct an array delta ::= the amount I shoud subtract from or add to each group.
  For a certain mask we say it's valid if it can be grouped together (forming a cycle in some order).
  note a valid mask must have a delta sum = 0.
  We then try constructing all valid masks by walking from some starting node and going through some out-going edge untill we hit the start back.
  The time complexity for this is O(k * ni * k).
  In the final solution there will be one or more groups connected together each one formming a cycle,
  we try to form these groups using DP with time complexity O(3^k) iterating over all masks and their submasks.
  The time complexity O(k^2 * ni + 3^k)
  The space complexity O(2^k)
*/

#include<bits/stdc++.h>
using namespace std;

const int K = 15;
int k;
long long each;
vector<int> X[K];
vector<int> sz;
vector<long long> delta;
bool can[1 << K];
int dp[1 << K];
map<long long , int> mp;
int solve(int mask){
     if(mask == 0)
          return 1;
     
     int &ret = dp[mask];
     if(ret != -1)
          return ret;
     
     ret = 0;
     for(int msk = mask; msk; msk = (msk - 1) & mask)
          ret |= can[msk] && solve(mask ^ msk);
     
     return ret;
}
vector<int> ans[K];
vector<vector<int>> way[1 << K];
//how can I construct a ginve mask

void process(int mask){
     for(auto &v : way[mask])
          ans[v[0]] = {v[1], v[2] + 1};
}
void trace(int mask){
     if(mask == 0)
          return;
     
     for(int msk= mask; msk; msk = (msk - 1) & mask){
          if(can[msk] && solve(mask ^ msk)){
               process(msk);
               trace(mask ^ msk);
               return;
          }
     }
     assert(0);
}

int main() {
     cin.tie(0);
     cin.sync_with_stdio(0);
     
     cin>>k;
     sz.resize(k);
     delta.resize(k);
     
     long long sum = 0;
     for(int i = 0; i < k; i++){
          cin>>sz[i];
          X[i].resize(sz[i]);
          for(int &x : X[i]){
               cin>>x;
               mp[x] = i;
               sum += x;
          }
     }
     if(sum % k){
          cout<<"No\n";
          return 0;
     }
     each = sum / k;
     for(int i = 0; i < k; i++){
          delta[i] = accumulate(X[i].begin(), X[i].end(), 0LL) - each;
     }
     
     long long delta_sum[1 << k];
     memset(delta_sum, 0LL, sizeof delta_sum);
     
     for(int mask = 0; mask < (1 << k); mask++){
          for(int i = 0; i < k; i++){
               if(mask & (1 << i)){
                    delta_sum[mask] += delta[i];
               }
          }
     }
     for(int start = 0; start < k; start++){
          for(int out : X[start]){
               vector<vector<int>> seq;
               int node = start;
               int mask = 0;
               int out_edge = out;
               while(true){
                    mask |= (1 << node);
                    long long needY = out_edge - delta[node];
                    if(mp.count(needY) != 0){
                         seq.push_back({mp[needY], (int)needY, node});
                         node = mp[needY];
                         out_edge = needY;
                         
                         if(node == start){
                              can[mask] = delta_sum[mask] == 0;
                              way[mask] = seq;
                              break;
                         }else if(mask & (1 << node))
                              break;
                         
                    }else break;
               }
          }
     }
     
     
     memset(dp, -1, sizeof dp);
     if(solve((1 << k) - 1)){
          cout<<"Yes\n";
          trace((1 << k) - 1);
          for(auto v : ans){
               for(int x : v){
                    cout<<x<<" ";
               }
               cout<<"\n";
               if(v.size() == 0)
                    break;
          }
          
     }else{
          cout<<"No\n";
     }
}
