#ifndef SRC_SSCANF_H_
#define SRC_SSCANF_H_

#include <stdarg.h>

#include "../s21_string.h"

struct Specificators {
  int width, argWidth;
  char length;
  char Specif;
  char Space;
  char buff[8192];
};

int s21_sscanf(const char *input, const char *format, ...);
void getNextFormatElem(char *input, char elem[8192], int *checkStartScanf,
                       bool *startParse, bool *startProg);
void assignI(char currentInputElem[8192], bool *varArgLoaded,
             void *currentVarArg, struct Specificators Specif);
void assignS(char currentInputElem[8192], bool *varArgLoaded,
             void *currentVarArg);
void assignF(char inCurrentInputElem[8192], bool *varArgLoaded,
             void *currentVarArg, struct Specificators Specif);
void assignD(char inCurrentInputElem[8192], bool *varArgLoaded,
             void *currentVarArg, struct Specificators Specif);
void assignI(char inCurrentInputElem[8192], bool *varArgLoaded,
             void *currentVarArg, struct Specificators Specif);
void assignO(char inCurrentInputElem[8192], bool *varArgLoaded,
             void *currentVarArg, struct Specificators Specif);
void assignX(char inCurrentInputElem[8192], bool *varArgLoaded,
             void *currentVarArg, struct Specificators Specif);
void assignN(bool *varArgLoaded, void *currentVarArg, s21_size_t *n_counter,
             int *counterForReturn);
void assignP(char inCurrentInputElem[8192], bool *varArgLoaded,
             void *currentVarArg);
char formatParsing(char formatStatic[16384], char currentFormatElem[8192],
                   bool *formatLoaded, struct Specificators *Specif,
                   int *checkStartScanf, int *status, bool *startParse,
                   bool *startProg);
void chooseSpecif(struct Specificators *Specif, char inputStatic[16384],
                  bool *stopMove);
void someJump(char inputStatic[16384], int *startParse, int wid);
void ifSpecIsD(struct Specificators *Specif, char inputStatic[16384],
               bool *stopMove);
void ifSpecIsI(struct Specificators *Specif, char inputStatic[16384],
               bool *stopMove);
void ifSpecIsF(struct Specificators *Specif, char inputStatic[16384],
               bool *stopMove);
void ifSpecIsO(struct Specificators *Specif, char inputStatic[16384],
               bool *stopMove);
void ifSpecIsX(struct Specificators *Specif, char inputStatic[16384],
               bool *stopMove);
void FspecifHelp(struct Specificators *Specif, char inputStatic[16384],
                 bool *stopMove, int i, int startParse);
void helpHexPars(struct Specificators *Specif, char inputStatic[16384],
                 bool *stopMove, int startParse);
void helpOctPars(struct Specificators *Specif, char inputStatic[16384],
                 bool *stopMove, int startParse);
void inputParsing(char inputStatic[16384], char currentInputElem[8192], int wid,
                  bool *inputLoaded, struct Specificators Specif,
                  s21_size_t *n_counter, bool *startProg);
void varArgParsingAndAssignment(char currentInputElem[8192], bool *varArgLoaded,
                                void *currentVarArg,
                                struct Specificators Specif,
                                s21_size_t *n_counter, int *counterForReturn);
char *strtokChop(char *str, const char *delim, char *leftOver);
void fillOneByOne(char input[16384], char currentInputElem[8192], int wid,
                  struct Specificators Specif, s21_size_t *n_counter,
                  bool *startProg);
void chopLeft(char input[16384], int howMany, s21_size_t *n_counter,
              struct Specificators Specif, bool *startProg);
void chopIfBuff(char input[16384], s21_size_t *n_counter,
                struct Specificators Specif, bool *startProg);
unsigned long hexToBaseTenLong(char *hexVal);
unsigned int hexToBaseTen(char *hexVal);
unsigned short int hexToBaseTenShort(char *hexVal);
unsigned int octToBaseTen(char *octVal);
unsigned long int octToBaseTenLong(char *octVal);
unsigned short int octToBaseTenShort(char *octVal);
int s21_atoi(char *str);
short int s21_atoiShort(char *str);
long int s21_atoiLong(char *str);
double s21_atof(char *str);
long double s21_atofLong(char *str);
bool checkInfNan(char inputStatic[16384], int i);
bool checkHex(char inputStatic[16384], int i);

void hexToBase(struct Specificators Specif, int checkSign, void *currentVarArg,
               char *temp);
void octToBase(struct Specificators Specif, int checkSign, void *currentVarArg,
               char *temp);
void tenToBase(struct Specificators Specif, int checkSign, void *currentVarArg,
               char *temp);

#endif  // SRC_SSCANF_H_
