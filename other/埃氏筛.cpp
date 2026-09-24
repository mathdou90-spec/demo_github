#include <iostream>
#include <vector>
using namespace std; 

vector<int> sieve(int n) {
    vector<bool> isprimes(n+1,true);
    for(int i=2;i*i<=n;i++) {
        if(isprimes[i]) {
            for(int j=i*i;j<=n;j+=i) isprimes[j]=false;
        }
    }
    vector<int> primes;
    for(int i=2;i<=n;i++) {
        if(isprimes[i]) primes.push_back(i);
        
    }
    return primes;
}