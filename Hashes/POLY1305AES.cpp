#include "POLY1305AES.h"

const mpz_class POLY1305AES::mod1305("3fffffffffffffffffffffffffffffffb", 16);

POLY1305AES::POLY1305AES(const std::string & R, const std::string & NONCE)
    : r(mpz_class(little_end(zfill(hexlify(R), 32, '0').substr(0, 32), 16), 16)),
      nonce(zfill(NONCE, 16, 0).substr(0, 16))
{}

void POLY1305AES::HASH(const std::string & key, const std::string & message){
    std::string aes = little_end(hexlify(AES(zfill(key, 16, 0).substr(0, 16)).encrypt(nonce)), 16);
    unsigned int q = (message.size() >> 4) + (bool) (message.size() & 15);
    std::vector <std::string> m;
    unsigned int x = 0;
    while ((message.size() - x) >= 16){
        m.push_back("1" + little_end(hexlify(message.substr(x, 16)), 16));
        x += 16;
    }
    if (message.size()){
        m.push_back(zfill("1" + little_end(hexlify(message.substr(x, 16)), 16), 33, '0'));
    }

    mpz_class h(aes, 16);
    for(unsigned int x = 0; x < q; x++){
        mpz_class temp; mpz_pow_ui(temp.get_mpz_t(), r.get_mpz_t(), q - x);
        h += mpz_class(m[x], 16) * temp;
    }
    h %= mod1305;

    mpz_class mask("ffffffffffffffffffffffffffffffff", 16);
    mpz_and(mask.get_mpz_t(), mask.get_mpz_t(), h.get_mpz_t());
    H = mask.get_str(16);
    H = little_end(H, 16);
}

std::string POLY1305AES::hexdigest(){
    return H;
}

std::string POLY1305AES::digest(){
    return unhexlify(H);
}
