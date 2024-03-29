#include <stdint.h>

uint8_t in[2][16]={{0x00,0x01,
                   0x00,0x01,
                   0x01,0xa1,
                   0x98,0xaf,
                   0xda,0x78,
                   0x17,0x34,
                   0x86,0x15,
                   0x35,0x66
                  },{
        0x32,0x43,
        0xf6,0xa8,
        0x88,0x5a,
        0x30,0x8d,
        0x31,0x31,
        0x98,0xa2,
        0xe0,0x37,
        0x07,0x34

}};

uint8_t key[2][16]={{
                          0x00,0x01,
                          0x20,0x01,
                          0x71,0x01,
                          0x98,0xae,
                          0xda,0x79,
                          0x17,0x14,
                          0x60,0x15,
                          0x35,0x94

                  },{
        0x2b,0x7e,
        0x15,0x16,
        0x28,0xae,
        0xd2,0xa6,
        0xab,0xf7,
        0x15,0x88,
        0x09,0xcf,
        0x4f,0x3c
}};

uint8_t out_cor[2][16]{
        {  0x6c,0xdd,
           0x59,0x6b,
           0x8f,0x56,
           0x42,0xcb,
           0xd2,0x3b,
           0x47,0x98,
           0x1a,0x65,
           0x42,0x2a
        },
        {
                0x39,0x25,
                0x84,0x1d,
                0x02,0xdc,
                0x09,0xfb,
                0xdc,0x11,
                0x85,0x97,
                0x19,0x6a,
                0x0b,0x32

        }
};