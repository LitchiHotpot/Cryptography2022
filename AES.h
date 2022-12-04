//
// Created by sokoface on 2022/12/3.
//

#ifndef AES_AES_H
#define AES_AES_H
#include <stdint.h>


#define GF28mult(a,b) GF28mult[256*a+b]
void ExpansionKey(uint8_t *key,uint8_t *new_key);
void AesEncry(uint8_t *in,uint8_t *out,uint8_t *key);
void AesDecry(uint8_t *in,uint8_t *out,uint8_t *key);
#endif //AES_AES_H
