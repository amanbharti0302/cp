#include<bits/stdc++.h>
using namespace std;

int random(int l, int r){
  return(rand() %(r - l + 1))+l;
}


int main(){
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

  std::ifstream infile("soln.in");
  if(infile.good()){
  assert(freopen("soln.in","w",stdout));
  assert(freopen("soln.out","r",stdin));
  }

  int tc = 10;
  cout<<tc<<endl;

  while(tc--){
    int n = random(1,5);
    cout<<n<<" "<<1<<endl;
    for(int i = 0;i<n;i++)cout<<random(1,2e5)<<" ";    
    cout<<endl;
  }

  cerr<<endl<<"Time: "<<(clock() * 1000. / CLOCKS_PER_SEC)<<" ms"<<endl;
}