/*rsa.c RSA算法实现*/
#include "encrypt.h"

int main()
{
    Huge plaintext = 85;
    Huge ciphertext, *c;
    c = &ciphertext;
    RsaPubKey M;
    RsaPriKey D;
    D.d = 103;
    D.n = 143;
    M.e = 7;
    M.n = 143;
    rsa_encipher(plaintext, c, M);
    printf("%ld", ciphertext);
    c = &plaintext;
    rsa_decipher(ciphertext, c, D);
    printf("\n%ld", plaintext);
}



/*modexp 二进制平方乘算法函数*/
static Huge modexp(Huge a, Huge b, Huge n)
{
    Huge y;

    /*使用二进制平方乘法计算 pow(a,b) % n*/
    y=1;

    while(b != 0)
    {
        /*对于b中的每个1，累加y*/
        
        if(b & 1)
            y = (y*a) % n;
        
        /*对于b中的每一位，计算a的平方*/
        a = (a*a) % n;
        
        /*准备b中的下一位*/
        b = b>>1;
    }
    
    return y;
}

/*rsa_encipher RSA算法加密*/
void rsa_encipher(Huge plaintext, Huge *ciphertext, RsaPubKey pubkey)
{
    *ciphertext = modexp(plaintext, pubkey.e, pubkey.n);
    return;
}

/*rsa_decipher RSA算法解密*/
void rsa_decipher(Huge ciphertext, Huge *plaintext, RsaPriKey prikey)
{
    *plaintext = modexp(ciphertext, prikey.d, prikey.n);
    return;
}