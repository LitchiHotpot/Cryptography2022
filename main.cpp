#include <iostream>
#include "AES.h"
#include "test.h"
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

void test(){
    uint8_t *new_key=new uint8_t[200];
    uint8_t  out[16];
    for(int n=0;n<2;n++) {
        ExpansionKey(key[n], new_key);
        AesEncry(in[n], out, new_key);
        bool flag=1;
        for(int i=0;i<16;i++){
            if(out[i]!=out_cor[n][i]) flag=0;
        }
        if(flag) cout<<"第"<<n<<"组加密：正确";
        else cout<<"第"<<n<<"组加密：错误";
        cout<<endl;
    }
    for(int n=0;n<2;n++) {
        ExpansionKey(key[n], new_key);
        AesDecry(out_cor[n], out, new_key);
        bool flag=1;
        for(int i=0;i<16;i++){
            if(out[i]!=in[n][i]) flag=0;
        }
        if(flag) cout<<"第"<<n<<"组解密：正确";
        else cout<<"第"<<n<<"组解密：错误";
        cout<<endl;
    }
}

void snow_test(bool mode){
    uint8_t *new_key=new uint8_t[200];
    uint8_t  out[16];
    for(int n=0;n<2;n++){

        if(!mode){
            int sum=0;
            int bit=rand()%128;
            int k=bit/8;
            bit=bit%8;
            bit=pow(2,bit);
            int s=0;
            while(s<8) {
                memset(out, 0,sizeof(out));
                uint8_t tmpin[16];
                for(int i=0;i<16;i++) tmpin[i]=in[n][i];
                if ((tmpin[k] & bit) == bit) tmpin[k] -= bit;
                else tmpin[k] += bit;
                ExpansionKey(key[n], new_key);
                AesEncry(tmpin, out, new_key);
                int t[16];
                for (int i = 0; i < 16; i++) {
                    t[i] = out[i] ^ out_cor[n][i];
                }
                for (int i = 0; i < 16; i++) {
                    while (t[i] != 0) {
                        if (t[i] % 2 == 1) sum++;
                        t[i] = t[i] >> 1;
                    }
                }
                //cout<<sum<<endl;
                s++;
            }
            cout<<"第"<<n<<"组八次雪崩测试平均改变位数："<<sum/8;
            cout<<endl;
        }
        else{
            int sum=0;
            int bit=rand()%128;
            int k=bit/8;
            bit=bit%8;
            bit=pow(2,bit);
            int s=0;
            while(s<8) {
                memset(out, 0,sizeof(out));
                uint8_t tmpin[16];
                for(int i=0;i<16;i++) tmpin[i]=out_cor[n][i];
                if ((tmpin[k] & bit) == bit) tmpin[k] -= bit;
                else tmpin[k] += bit;
                ExpansionKey(key[n], new_key);
                AesDecry(tmpin, out, new_key);
                int t[16];
                for (int i = 0; i < 16; i++) {
                    t[i] = out[i] ^ in[n][i];
                }
                for (int i = 0; i < 16; i++) {
                    while (t[i] != 0) {
                        if (t[i] % 2 == 1) sum++;
                        t[i] = t[i] >> 1;
                    }
                }
                s++;
            }
            cout<<"第"<<n<<"组八次雪崩测试平均改变位数："<<sum/8;
            cout<<endl;
        }
    }
}
int main() {
    srand(time(0));
    int mode;
    cout<<"请输入操作：0.测试 1.雪崩测试"<<endl;
    cin>>mode;
    if(mode==0){
        test();
    }
    else{
        int snow_mode;
       cout<<"您想改变的是：0.明文 1.密文"<<endl;
       cin>>snow_mode;
        snow_test(snow_mode);
    }
    return 0;
}
