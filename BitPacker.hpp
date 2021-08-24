#ifndef BIT_PACKER_HPP
#define BIT_PACKER_HPP

#include <iostream>
#include <cstdint>
#ifdef UNIT_TESTS
#include <functional>
#endif // UNIT_TESTS

class BitPacker {
#ifdef UNIT_TESTS
private:
    std::function<void()> dtor_fun_;
#endif // UNIT_TESTS
public:
    BitPacker() {
        std::cout << "BitPacker::C'tor()\n";
        #ifdef UNIT_TESTS
        dtor_fun_ = [](){};
        #endif
    }
    #ifdef UNIT_TESTS
    BitPacker(std::function<void()> ctorFn, std::function<void()> dtorFn)
    : BitPacker()
    {
        ctorFn();
        dtor_fun_ = dtorFn;
    }
    #endif // UNIT_TESTS
    ~BitPacker() {
        std::cout << "BitPacker::D'tor()\n";
        #ifdef UNIT_TESTS
        dtor_fun_();
        #endif // UNIT_TESTS
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
