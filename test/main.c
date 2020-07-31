#include "wbsm4.h"

int main()
{
    unsigned char IN[16] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff};
    unsigned char key[16] = {0};
    unsigned char OUT[16];
    unsigned char OOUT[16];

    Sm4Whitebox sm4_wb_ctx;
    
    sm4_wb_gen_tables(key, &sm4_wb_ctx);
    printstate(IN); 
    sm4_wb_enc(IN, OUT, &sm4_wb_ctx);
    printstate(OUT);
    
    sm4_context ctx;
    sm4_setkey_enc(&ctx, key);
    sm4_crypt_ecb(&ctx, 1, 16, IN, OOUT);
    printstate(OOUT);
    return 0;
}