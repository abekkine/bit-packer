#include "BitPacker.hpp"

#include <memory>

#include <cstdio>

void pack_bits(std::shared_ptr<BitPacker> bp) {
    //  5 bits [ 0.. 4] : target count  [0..4B0]
    // 16 bits [ 5..20] : crc           [5..7B0| 8..15B1 | 16..20B2]
    // 13 bits [21..33] : range         [21..23B2| 24..31B3 | 32..33B4]
    // 18 bits [34..51] : distance      [34..39B4| 40..47B5 | 48..51B6]
    // 23 bits [52..74] : duration      [52..55B6| 56..63B7 | 64..71B8 | 71..74B9]
    //  5 bits [75..79] : padding       [75..79B9]
    enum {
        bf__TARGET_COUNT,
        bf__CRC,
        bf__RANGE,
        bf__DISTANCE,
        bf__DURATION,
        bf__SPARE,
    };
    bp->Reserve(bf__TARGET_COUNT, 5);
    bp->Reserve(bf__CRC, 16);
    bp->Reserve(bf__RANGE, 13);
    bp->Reserve(bf__DISTANCE, 18);
    bp->Reserve(bf__DURATION, 23);
    bp->Reserve(bf__SPARE, 5);

    bp->Set(bf__TARGET_COUNT, 1);
    bp->Set(bf__CRC, 1);
    bp->Set(bf__RANGE, 1);
    bp->Set(bf__DISTANCE, 1);
    bp->Set(bf__DURATION, 1);
    bp->Set(bf__SPARE, 0);
    // 0000100000000000000010000000000001000000
    // 0000000000010000000000000000000000100000
    // 08 00 08 00 40
    // 00 10 00 00 20

    uint8_t data[10] = {};
    bp->FetchBlock(data, 10);

    for (int i=0; i<10; ++i) {
        printf("%02x ", data[i]);
    }
    printf("\n");
}

int main() {

    std::shared_ptr<BitPacker> bp = std::make_shared<BitPacker>();

    pack_bits(bp);

    return 0;
}