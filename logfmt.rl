
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "logfmt.h"

#define emit(T) \
  cb(T, ts, te - ts, data)

%%{
  machine logfmt;
  write data nofinal noerror;

  newline = '\r\n' | '\r' | '\n';
  id = (33..126 - [="])+;
  string = '"' ([^"\\])* '"';
  exponent = [eE] [+\-]? digit+;
  decimal = '0' | [1-9] digit*;
  octal = '0' digit+;
  float = (digit* '.' digit+ | digit+ '.') exponent? | digit+ exponent;
  hex = '0x' [0-9a-fA-F]+;

  main := |*
    decimal  => { emit(LOGFMT_TOK_DECIMAL); };
    float    => { emit(LOGFMT_TOK_FLOAT); };
    octal    => { emit(LOGFMT_TOK_OCTAL); };
    hex      => { emit(LOGFMT_TOK_HEX); };
    id       => { emit(LOGFMT_TOK_LIT); };
    '='      => { emit(LOGFMT_TOK_EQ); };
    string   => { emit(LOGFMT_TOK_LIT); };
    newline  => { emit(LOGFMT_TOK_EOL); };
    [ \t]+;
  *|;

}%%


int
logfmt_parse_callback(char *buf, size_t len, logfmt_callback_t cb, void *data) {
  char *pe = buf + len;
  char *ts, *te;
  char *eof = 0;
  char *p = buf;
  int act = 0;

  (void) logfmt_en_main;

  int cs;

  %%{
    write init;
    write exec;
  }%%

  return 0;
}
