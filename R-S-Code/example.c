#include <stdio.h>
#include "rs.h"

//unsigned char msg[100] = {0x00,  0x01,  0x1A,  0x1A,  0x04,
//                       0x25,  0x06,  0x07,  0x08,  0x09,
//                       0x0A,  0x0B,  0x0C,  0x0D,  0x0E,
//                       0x0F,  0x10,  0x11,  0x12,  0x13,
//                       0x14,  0x15,  0x16,  0x17,  0x18,
//                       0x19,  0x1A,  0x1B,  0x2E,  0x3F,
//                       0x47,  0xBB,  0x9F,  0xF6,  0x49, 0xC9};

//unsigned char msg[155] = {0x00,  0x01,  0x02,  0x03,  0x04,
//                       0x05,  0x06,  0x07,  0x08,  0x09,
//                       0x0A,  0x0B,  0x0C,  0x0D,  0x0E,
//                       0x0F,  0x10,  0x11,  0x12,  0x13,
//                       0x14,  0x15,  0x16,  0x17,  0x18,
//                       0x19,  0x1A,  0x1B};

//unsigned char msg[] = {0x00,0x00,0xFF,0xA7,0x00,0x05,0xFF,0xFF,0xFF,0xFF,0xFF,0x06,0xFF,0xFF,0xFF,0xFF,0xFF,
//                            0x28,0xC2,0x02,0x11,0x80,0x50,0x03,0x02,0x0B,0x01,0x00,0x00,0x00,0x01,0x04,0x09,0x00,
//                            0x01,0x00,0x01,0x0F,0x85,0x80,0xDC,0x12,0xD0,0x80,0x27,0x12,0x7D,0x01,0x01,0x00,0x00,
//                            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//                            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//                            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//                            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//                            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//                            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x19,0x01,0x02,0x3B,0x72,0x27,0x00,0x00,0x00,
//                            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//                            0x00,0x00,0x17,0x00};   // 174

//unsigned char msg[] = {0x00,0x00,0xFF,0x25,0x00,0x05,0xFF,0xFF,0xFF,0xFF,
//                       0xFF,0x06,0xFF,0xFF,0xFF,0xFF,0xFF,0x2A,0xC2,
//                       0x01,0x15,0x80,0x54,0x01,0x00,0x0F,0x00,0x00,
//                       0x00,0x01,0x20,0x24,0x08,0x21,0x18,0x58,0x44,
//                       0xB2,0x56,0x8C,0xE5,0x08,0x76,0x00};

unsigned char msg[] = {0x00,0x00,0xFF,0x10,0x00,0x05,0xFF,0xFF,0xFF,0xFF,
                       0xFF,0x06,0xFF,0xFF,0xFF,0xFF,0xFF,0x44,
                       0xCA,0x00,0x00,0xF1,0x00};
unsigned char codeword[256];

/* Introduce a byte error at LOC */
void
byte_err (int err, int loc, unsigned char *dst)
{
  printf("Adding Error at loc %d, data %#x\n", loc, dst[loc-1]);
  dst[loc-1] ^= err;
}

/* Pass in location of error (first byte position is
   labeled starting at 1, not 0), and the codeword.
*/
void
byte_erasure (int loc, unsigned char dst[], int cwsize, int erasures[]) 
{
  printf("Erasure at loc %d, data %#x\n", loc, dst[loc-1]);
  dst[loc-1] = 0;
}


void
print_word (int n, unsigned char *data) {
  int i;
  for (i=0; i < n; i++) {
    printf ("%02X ", data[i]);
  }
  printf("\n");
}

//void block_encode(unsigned char data[], unsigned int block_size, unsigned int data_size) {
//    unsigned int i;
//    unsigned char block_data[block_size];
//    for (i = 0; i < data_size; i += block_size) {
//        if (i + block_size <= data_size) {
//            memcpy(block_data, data + i, block_size);
//            decode_data(block_data, ML);
//        } else { // 剩余数据不足以形成一个完整的块
//            break;
//        }
//    }
//}

void removeElements(unsigned char *codeword, int size, int n) {
    if (n > size) {
        codeword[0] = 0;
        return;
    }
    int i, j;
    for (i = 0; i < n; i++) {
        int randomIndex = 17;
        for (j = randomIndex; j < size - 1; j++) {
            codeword[j] = codeword[j + 1];
        }
        size--;
        randomIndex+=3;
    }
}



void main () {
    int erasures[16];   //
    int nerasures = 0;

    initialize_ecc ();
    printf("Data:\n");
    print_word(sizeof(msg),msg);
    /* Encode data into codeword, adding NPAR parity bytes */
    encode_data(msg, sizeof(msg), codeword);
    printf("msg len is %d\n", ML);

    printf("Encode data\n");
    print_word(ML, codeword);

    /* Add one error and two erasures */
    byte_err(0x18, 20, codeword);
    byte_err(0x19, 21, codeword);
    byte_err(0x20, 22, codeword);
//    removeElements(codeword, ML, 1);

    printf("Error data\n");
    print_word(ML, codeword);

    /* We need to indicate the position of the erasures.  Eraseure
       positions are indexed (1 based) from the end of the message... */
    erasures[nerasures++] = ML-3;
    erasures[nerasures++] = ML-4;
    erasures[nerasures++] = ML-6;

    /* Now decode -- encoded codeword size must be passed */
    decode_data(codeword, ML);

    /* check if syndrome is all zeros */
    if (check_syndrome () != 0) {
        correct_errors_erasures (codeword,ML,nerasures,erasures);
        printf("Error erasures data\n");
        print_word(ML, codeword);
    }
}

//void main(void) {
//    int erasures[16];
//    int nerasures = 0;
//    initialize_ecc ();
//    decode_data(msg,36);
//    if (check_syndrome() != 0) {
//        correct_errors_erasures(msg, 36, nerasures, erasures);
//        printf("Error erasures data\n");
//        print_word(36, msg);
//    }
//}