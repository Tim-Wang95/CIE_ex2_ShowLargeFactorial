#include <iostream>
#include <cmath>

int get_length (int x) {
    int leng=0;
    while (x!=0) {x /= 10; ++leng;}
    return leng;
}

int main() {
    int num, temp, iter, count;
    int max_int = std::pow(2, 8*sizeof(num)-1)-1;
    const int n = 2*get_length(max_int);
    int digits [n]; digits [0] = 1;
    for (int i=1; i<n; ++i) {digits [i] = 0;}
    
    std::cout << "Enter a positive integer: ";
    std::cin >> num;
    
    for (int j=1; j<=num; ++j) {
        for (int k=0; k<n; ++k) {digits [k] *= j;}
        
        for (int l=0; l<n; ++l) {
            if (digits[l]>=10) {
                temp = digits [l]; iter = get_length(temp);
                digits [l] = temp%10; temp/=10;
                
                for (int m=1; m<iter; ++m) {
                    digits [l+m] += temp%10; temp/=10;}
            }
        }
        
    }

    for (int c=n-1; c>=0; --c) {
        if (digits [c] !=0) {count=c; break;}
    }
    
    std::cout << "The factorial of " << num << " is ";
    for (int c=count; c>=0; --c) {
        std::cout << digits [c];
    }
    std::cout << std::endl;
    
    return 0;
}
