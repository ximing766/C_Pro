#ifndef RS_H
#define RS_H

#define NPAR 10    // 能纠正 NPAR/2 个symbol error

/****************************************************************/
#define TRUE 1

typedef unsigned long BITU32;
typedef unsigned short BITU16;

/* **************************************************************** */

/* Maximum degree of various polynomials. */
#define MAXDEG (NPAR*2)
#define ML (sizeof (msg) + NPAR)
//#define ML (sizeof (APDU_MSG) + NPAR)

extern int pBytes[MAXDEG];
extern int synBytes[MAXDEG];
extern int DEBUGER;



void initialize_ecc (void);
int check_syndrome (void);
void decode_data (unsigned char data[], int nbytes);
void encode_data (unsigned char msg[], int nbytes, unsigned char dst[]);

extern int gexp[];
extern int glog[];

void init_galois_tables (void);
int ginv(int elt); 
int gmult(int a, int b);

int correct_errors_erasures (unsigned char codeword[], int csize,int nerasures, int erasures[]);

void add_polys(int dst[], int src[]) ;
void scale_poly(int k, int poly[]);
void mult_polys(int dst[], int p1[], int p2[]);
void copy_poly(int dst[], int src[]);
void zero_poly(int poly[]);

#endif
