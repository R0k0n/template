        int nnn;nnn = 10000007;
        vector<bool> is_prime(nnn+1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= nnn; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= nnn; j += i)
                    is_prime[j] = false;
            }
        }
        
        for(ll i = 2 ; i <= nnn ; i++){
            if(is_prime[i])primes.push_back(i);
        }
        
