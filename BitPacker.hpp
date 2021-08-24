#ifndef BIT_PACKER_HPP
#define BIT_PACKER_HPP

#include <iostream>
#include <cstdint>

class BitPacker {
public:
    BitPacker() {
        std::cout << "BitPacker::C'tor()\n";
    }
    ~BitPacker() {
        std::cout << "BitPacker::D'tor()\n";
    }
    void Reserve(const int id, const int size) {
        // TODO
    }
    void Set(const int id, const uint64_t value) {
        // TODO
    }
    uint64_t Get(const int id) const {
        return 0;
    }
    void ParseBlock(uint8_t * buffer, const int size) {
        // TODO
    }
    void FetchBlock(uint8_t * buffer, const int size) {
        // TODO
    }
};

#endif // BIT_PACKER_HPP
