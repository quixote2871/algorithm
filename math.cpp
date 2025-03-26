long long euler_phi(long long n) {
	long long res = n;
	for(long long i=2; i*i<=n; i++) {
		if(n%i==0) {
			while(n%i==0)
				n /= i;
			res = res/i*(i-1);
		}
	}
	if(n!=1)
		res = res/n*(n-1);
	return res;
}

long long pow(long long a, long long b, long long mod) {
	if(b==0)
		return 1;
	if(b==1)
		return a%mod;
	long long res = pow(a, b/2, mod);
	if(b%2==1)
		return (res*res)%mod*a%mod;
	else
		return (res*res)%mod;
}

long long inverse(long long n, long long mod) {
	return pow(n, mod-2, mod);
}
