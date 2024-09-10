#ifndef HASH_H
#define HASH_H

#include <string>
#include <vector>

class hash {
public:
    int Encode(const std::string& key, const std::string& name);
    std::string Decode(const std::string& name);
    bool Login(const std::string& name);

private:
    const int SHIFT = 5; // Fixed shift value for encoding
};

#endif // HASH_H
