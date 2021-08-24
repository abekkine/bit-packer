#include "catch.hpp"

#include "BitPacker.hpp"

TEST_CASE("Create & Destroy", "[basics]") {
    BitPacker * bp = 0;

    bp = new BitPacker();
    REQUIRE( bp != nullptr );

    delete bp;
}

TEST_CASE("C'tor / D'tor Coverage", "[basics]") {
    BitPacker * bp = 0;

    bool dtor = false, ctor = false;
    bp = new BitPacker(
        [&ctor]() {
            ctor = true;
        },
        [&dtor](){
            dtor = true;
        }
    );
    REQUIRE( ctor == true );

    delete bp;
    REQUIRE( dtor == true );
}

TEST_CASE("Bit Packing", "[basics]") {
    BitPacker * bp = 0;

    bp = new BitPacker();

    bp->Reserve(1, 3);
    bp->Reserve(2, 2);
    bp->Set(1, 6);
    bp->Set(2, 1);
    // 11001000 : 0xc8
    uint8_t data;
    bp->FetchBlock(&data, 1);
    REQUIRE( data == 0xc8 );

    delete bp;
}

TEST_CASE("Bit Read", "[basics]") {
    BitPacker * bp = 0;

    bp = new BitPacker();

    bp->Reserve(1, 3);
    bp->Reserve(2, 2);
    bp->Set(1, 6);
    bp->Set(2, 1);

    auto v1 = bp->Get(1);
    REQUIRE( v1 == 6 );
    auto v2 = bp->Get(2);
    REQUIRE( v2 == 1 );

    delete bp;
}

TEST_CASE("Block Read", "[basics]") {
    BitPacker * bp = 0;

    bp = new BitPacker();

    bp->Reserve(1, 3);
    bp->Reserve(2, 2);

    uint8_t data = 0xc8;

    bp->ParseBlock(&data, 1);

    auto v1 = bp->Get(1);
    REQUIRE( v1 == 6 );
    auto v2 = bp->Get(2);
    REQUIRE( v2 == 1 );    

    delete bp;
}