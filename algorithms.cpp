#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
using std::cout, std::cin, std::endl;

/* precondition: a >= b >= 0 */
/* postcondition: return d = gcd(a, b) */
int EuclidAlgGCD(int a, int b){
	while (b != 0){ // repeat until b = 0
		int remainder = a % b; // get the remainder of a and b
		a = b; // replace a with b
		b = remainder; // replace b with the current remainder
	}
	return a;
}
	
/* precondition: a>=b>=0 */
/* postcondition: return d=gcd(a,b), s and t are set so that d=sa+tb */
int ExtendedEuclidAlgGCD (int a, int b, int & s, int & t){
	if (b == 0){
		s = 1;
		t = 0;
		return a;
	}
	int s1, t1;
	int d = ExtendedEuclidAlgGCD(b, a % b, s1, t1);
	s = t1;
	t = s1 - (a / b) * t1;
	return d;
}


/* precondition: n is greater than 1,a can be negative
postcondition: return a mod n (as defined in class)
a mod n = r if and only if a = nk+r, 0 =< r < n (note that
r needs to be non-negative).
*/
int mod(int a, int n){
	int r = a % n;
	if (r < 0){ // if the remainder is negative, makes it non-negative
	       r += n;
       }
       return r; // returns non-negative result
}      

bool isPrime(int n){
	if (n <= 1) return false;
        if (n == 2) return true;       
        if (n % 2 == 0) return false;
	for (int i = 3; i * i <= n; i += 2){
		if (n % i == 0)
			return false;
	}
	return true;
}
/* return an integer that is relatively prime with n, and greater than 1
i.e., the gcd of the returned int and n is 1
Note: Although gcd(n,n-1)=1, we don't want to return n-1*/
int RelativelyPrime (int n){
	int i;
	do {
		i = 2 + rand() % (n - 3);
	} while (EuclidAlgGCD(i, n) != 1 || !isPrime(i));
	return i;
}



/* n>1, a is nonnegative */
/* a<=n */
/* a and n are relative prime to each other */
/* return s such that a*s mod n is 1 */
int inverse (int a, int n){
	int s, t;
	int d = ExtendedEuclidAlgGCD(n, a, s, t);
	if (d == 1){
		return mod(t, n);
	} else {
		cout <<"a and n are not relatively prime!\n";
		return -1;
	}
}

// Return M^e mod PQ
int Encode(int M, int e, int PQ){
	int result = 1;
	for (int i = 0; i < e; ++i){
		result = (result * M) % PQ;
	}
	return result;
}

//Return C^d mod PQ
int Decode (int C, int d, int PQ){
	int result = 1;
	for (int i = 0; i < d; ++i){
		result = (result * C) % PQ;
	}
	return result;
}



int main(){
	srand(time(0));
	int a, b; // test for euclid
	cout << "Testing Euclid Algorithm" << endl;
	cout << "Enter two non negative integers (a >= b): ";
	cin >> a >> b;
	int d = EuclidAlgGCD(a, b);
	cout << "The GCD of " << a << " and " << b << " is: " << d << endl;
        
	int s, t; // test for extended euclid
	int d_extended = ExtendedEuclidAlgGCD(a, b, s, t);
	cout << "The coefficients are: s = " << s << " , t = " << t << endl;

	int n, num; // test for mod function
        cout << "Testing mod()" << endl;
	cout << "Enter an integer: ";
	cin >> num;
	cout << "Enter modulus (n > 1): ";
	cin >> n;
	int result = mod(num, n);
	cout << num << " mod " << n << " = " << result << endl;

	int x; // testing Relatively prime
	cout << "Testing Relatively prime" << endl;
	cout << "Enter an integer: ";
	cin >> x;
	int y = RelativelyPrime(x);
        cout << "Relatively prime to " << x << " is " << y << endl;




	// testing RSA algorithm
	cout << "Testing RSA algorithm" << endl;
	const int P = 23;
	const int Q = 17;
	const int PQ = P * Q;
	const int formula = (P - 1) * (Q - 1);
	cout << "P = " << P << " ,Q = " << Q << ", PQ = " << PQ << endl;;

        int e = RelativelyPrime(formula);
	cout << "Relatively prime e = " << e << endl;

	int d_RSA = inverse(e, formula);
	cout << "Inverse d = " << d_RSA << endl;

	int M;
       	/* M is an integer that is smaller than PQ */
	cout <<"Enter an integer that is smaller than "<< PQ << " : ";
	cin >> M;
	assert(M < PQ);
	int C = Encode(M, e, PQ);
	cout << "Encoded C = " << C << endl;
	int M1 = Decode(C, d_RSA, PQ);
	cout << "Decoded M1 = " << M1 << endl;
	assert (M == M1);





return 0;
}
