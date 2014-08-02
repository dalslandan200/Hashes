#include "./Hashes.h"
 
bool validate_all_hashes(std::ostream & stream, const unsigned int & linew){
    bool all_correct = true, correct;

    // No input == empty string == ""
    stream << "No input:" << std::endl;
    
    all_correct &= validate_hash <LM>             ("", "aad3b435b51404eeaad3b435b51404ee", stream, "LM");
    all_correct &= validate_hash <MD2>            ("", "8350e5a3e24c153df2275c9f80692773", stream, "MD2");
    all_correct &= validate_hash <MD4>            ("", "31d6cfe0d16ae931b73c59d7e0c089c0", stream, "MD4");
    all_correct &= validate_hash <MD5>            ("", "d41d8cd98f00b204e9800998ecf8427e", stream, "MD5");
    all_correct &= validate_hash <RIPEMD128>      ("", "cdf26213a150dc3ecb610f18f6b38b46", stream, "RIPEMD128");
    all_correct &= validate_hash <RIPEMD160>      ("", "9c1185a5c5e9fc54612808977ee8f548b2258d31", stream, "RIPEMD160");
    all_correct &= validate_hash <SHA1>           ("", "da39a3ee5e6b4b0d3255bfef95601890afd80709", stream, "SHA1");
    all_correct &= validate_hash <SHA224>         ("", "d14a028c2a3a2bc9476102bb288234c415a2b01f828ea62ac5b3e42f", stream, "SHA224");
    all_correct &= validate_hash <SHA256>         ("", "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855", stream, "SHA256");
    all_correct &= validate_hash <SHA384>         ("", "38b060a751ac96384cd9327eb1b1e36a21fdb71114be07434c0cc7bf63f6e1da274edebfe76f65fbd51ad2f14898b95b", stream, "SHA384");
    all_correct &= validate_hash <SHA512>         ("", "cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e", stream, "SHA512");
    all_correct &= validate_HMAC <HMAC <MD5> >    ("", "", "74e6f7298a9c2d168935f58c001bad88", stream, "HMAC MD5");
    all_correct &= validate_HMAC <HMAC <SHA1> >   ("", "", "fbdb1d1b18aa6c08324b7d64b71fb76370690e1d", stream, "HMAC SHA1");
    all_correct &= validate_HMAC <HMAC <SHA256> > ("", "", "b613679a0814d9ec772f95d778c35fc5ff1697c493715653c6c712144292c5ad", stream, "HMAC SHA256");
    all_correct &= validate_HMAC <HMAC <SHA512> > ("", "", "b936cee86c9f87aa5d3c6f2e84cb5a4239a5fe50480a6ec66b70ab5b1f4ac6730c6c515421b327ec1d69402e53dfb49ad7381eb067b338fd7b0cb22247225d47", stream, "HMAC SHA512");

    std::string data = "The quick brown fox jumps over the lazy dog";
    stream << "\nInput: \x22" + data + "\x22" << std::endl;

    all_correct &= validate_hash <LM>             (data, "a7b07f9948d8cc7f97c4b0b30cae500f", stream, "LM");
    all_correct &= validate_hash <MD2>            (data, "03d85a0d629d2c442e987525319fc471", stream, "MD2");
    all_correct &= validate_hash <MD4>            (data, "1bee69a46ba811185c194762abaeae90", stream, "MD4");
    all_correct &= validate_hash <MD5>            (data, "9e107d9d372bb6826bd81d3542a419d6", stream, "MD5");
    all_correct &= validate_hash <RIPEMD128>      (data, "3fa9b57f053c053fbe2735b2380db596", stream, "RIPEMD128");
    all_correct &= validate_hash <RIPEMD160>      (data, "37f332f68db77bd9d7edd4969571ad671cf9dd3b", stream, "RIPEMD160");
    all_correct &= validate_hash <SHA1>           (data, "2fd4e1c67a2d28fced849ee1bb76e7391b93eb12", stream, "SHA1");
    all_correct &= validate_hash <SHA224>         (data, "730e109bd7a8a32b1cb9d9a09aa2325d2430587ddbc0c38bad911525", stream, "SHA224");
    all_correct &= validate_hash <SHA256>         (data, "d7a8fbb307d7809469ca9abcb0082e4f8d5651e46d3cdb762d02d0bf37c9e592", stream, "SHA256");
    all_correct &= validate_hash <SHA384>         (data, "ca737f1014a48f4c0b6dd43cb177b0afd9e5169367544c494011e3317dbf9a509cb1e5dc1e85a941bbee3d7f2afbc9b1", stream, "SHA384");
    all_correct &= validate_hash <SHA512>         (data, "07e547d9586f6a73f73fbac0435ed76951218fb7d0c8d788a309d785436bbb642e93a252a954f23912547d1e8a3b5ed6e1bfd7097821233fa0538f3db854fee6", stream, "SHA512");
    all_correct &= validate_HMAC <HMAC <MD5> >    ("key", data, "80070713463e7749b90c2dc24911e275", stream, "HMAC MD5");
    all_correct &= validate_HMAC <HMAC <SHA1> >   ("key", data, "de7c9b85b8b78aa6bc8a7a36f70a90701c9db4d9", stream, "HMAC SHA1");
    all_correct &= validate_HMAC <HMAC <SHA256> > ("key", data, "f7bc83f430538424b13298e6aa6fb143ef4d59a14946175997479dbc2d1a3cd8", stream, "HMAC SHA256");
    all_correct &= validate_HMAC <HMAC <SHA512> > ("key", data, "b42af09057bac1e2d41708e48a902e09b5ff7f12ab428a4fe86653c73dd248fb82f948a549f7b791a5b41915ee4d1ec3935357e4e2317250d0372afa2ebeeb3a", stream, "HMAC SHA512");

    stream << "\nOthers:" << std::endl;

    data = unhexlify("f3f6");
    std::string key = unhexlify("ec074c835580741701425b623235add6");
    std::string r = unhexlify("851fc40c3467ac0be05cc20404f3f700");
    std::string nonce = unhexlify("fb447350c4e868c52ac3275cf9d4327e");
    POLY1305AES p1(r, nonce);
    p1.HASH(key, data);
    correct = (p1.hexdigest() == "f4c633c3044fc145f84f335cb81953de");
    stream <<  "    POLY1305AES TEST 1:  " << (correct?"Passed":"Failed") << std::endl;;
    all_correct &= correct;

    data = unhexlify("");
    key = unhexlify("75deaa25c09f208e1dc4ce6b5cad3fbf");
    r = unhexlify("a0f3080000f46400d0c7e9076c834403");
    nonce = unhexlify("61ee09218d29b0aaed7e154a2c5509cc");
    POLY1305AES p2(r, nonce);
    p2.HASH(key, data);
    correct = (p2.hexdigest() == "dd3fab2251f11ac759f0887129cc2ee7");
    stream << "    POLY1305AES TEST 2:  " << (correct?"Passed":"Failed") << std::endl;
    all_correct &= correct;

    data = unhexlify("ab0812724a7f1e342742cbed374d94d136c6b8795d45b3819830f2c04491faf0990c62e48b8018b2c3e4a0fa3134cb67fa83e158c994d961c4cb21095c1bf9");
    key = unhexlify("e1a5668a4d5b66a5f68cc5424ed5982d");
    r = unhexlify("12976a08c4426d0ce8a82407c4f48207");
    nonce = unhexlify("9ae831e743978d3a23527c7128149e3a");
    POLY1305AES p3(r, nonce);
    p3.HASH(key, data);
    correct = (p3.hexdigest() == "5154ad0d2cb26e01274fc51148491f1b");
    stream << "    POLY1305AES TEST 3:  " << (correct?"Passed":"Failed") << std::endl;
    all_correct &= correct;

    return all_correct;
}