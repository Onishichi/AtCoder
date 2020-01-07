#include <iostream>
#include <algorithm>

int main(){
    const long long MAX_N=200000;
    long long n,k;
    long long a[MAX_N];
    long long f[MAX_N];
    std::cin>>n>>k;
    for(long long i=0;i<n;++i){
        std::cin>>a[i];
    }
    for(long long i=0;i<n;++i){
        std::cin>>f[i];
    }

    std::sort(a,a+n);
    std::sort(f,f+n,std::greater<long long>());
    long long af[MAX_N];
    long long maxAf=0;
    for(long long i=0;i<n;++i){
        af[i]=a[i]*f[i];
        maxAf=af[i]>maxAf?af[i]:maxAf;
    }

    long long ans;
    for(long long i=0;i<maxAf;++i){
        long long kc=k;
        for(long long j=0;j<n;++j){
            if(af[j]>i){
                kc-=(af[j]-i+f[j]-1)/f[j];
            }
        }
        if(kc>0){
            ans=
        }
        else if(){

        }
    }
    return 0;
}