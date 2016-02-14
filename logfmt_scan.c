
#line 1 "logfmt_scan.rl"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "logfmt.h"

#define emit(T) \
  cb(LOGFMT_TOK_##T, ts, te - ts, data)


#line 15 "logfmt_scan.c"
static const int scanner_start = 6;

static const int scanner_en_main = 6;


#line 38 "logfmt_scan.rl"


int
logfmt_scan(char *buf, size_t len, logfmt_scan_callback_t cb, void *data) {
  char *pe = buf + len;
  char *ts, *te;
  char *eof = 0;
  char *p = buf;
  int act = 0;

  (void) scanner_en_main;

  int cs;

  
#line 37 "logfmt_scan.c"
	{
	cs = scanner_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 45 "logfmt_scan.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr1:
#line 33 "logfmt_scan.rl"
	{te = p+1;{ emit(LIT); }}
	goto st6;
tr3:
#line 1 "NONE"
	{	switch( act ) {
	case 4:
	{{p = ((te))-1;} emit(FLOAT); }
	break;
	case 5:
	{{p = ((te))-1;} emit(OCTAL); }
	break;
	case 7:
	{{p = ((te))-1;} emit(DECIMAL); }
	break;
	}
	}
	goto st6;
tr7:
#line 32 "logfmt_scan.rl"
	{{p = ((te))-1;}{ emit(DECIMAL); }}
	goto st6;
tr10:
#line 34 "logfmt_scan.rl"
	{te = p+1;{ emit(EOL); }}
	goto st6;
tr15:
#line 27 "logfmt_scan.rl"
	{te = p+1;{ emit(EQ); }}
	goto st6;
tr18:
#line 35 "logfmt_scan.rl"
	{te = p;p--;}
	goto st6;
tr19:
#line 34 "logfmt_scan.rl"
	{te = p;p--;{ emit(EOL); }}
	goto st6;
tr20:
#line 26 "logfmt_scan.rl"
	{te = p;p--;{ emit(LIT); }}
	goto st6;
tr21:
#line 32 "logfmt_scan.rl"
	{te = p;p--;{ emit(DECIMAL); }}
	goto st6;
tr26:
#line 29 "logfmt_scan.rl"
	{te = p;p--;{ emit(FLOAT); }}
	goto st6;
tr27:
#line 30 "logfmt_scan.rl"
	{te = p;p--;{ emit(OCTAL); }}
	goto st6;
tr28:
#line 31 "logfmt_scan.rl"
	{te = p;p--;{ emit(HEX); }}
	goto st6;
st6:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 1 "NONE"
	{ts = p;}
#line 118 "logfmt_scan.c"
	switch( (*p) ) {
		case 9: goto st7;
		case 10: goto tr10;
		case 13: goto st8;
		case 32: goto st7;
		case 34: goto st1;
		case 48: goto tr13;
		case 61: goto tr15;
		case 102: goto st16;
		case 116: goto st20;
	}
	if ( (*p) < 49 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto st9;
	} else if ( (*p) > 57 ) {
		if ( 58 <= (*p) && (*p) <= 126 )
			goto st9;
	} else
		goto tr14;
	goto st0;
st0:
cs = 0;
	goto _out;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	switch( (*p) ) {
		case 9: goto st7;
		case 32: goto st7;
	}
	goto tr18;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	if ( (*p) == 10 )
		goto tr10;
	goto tr19;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	if ( (*p) == 33 )
		goto st9;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st9;
	} else if ( (*p) >= 35 )
		goto st9;
	goto tr20;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	switch( (*p) ) {
		case 34: goto tr1;
		case 92: goto st0;
	}
	goto st1;
tr13:
#line 1 "NONE"
	{te = p+1;}
#line 32 "logfmt_scan.rl"
	{act = 7;}
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 189 "logfmt_scan.c"
	switch( (*p) ) {
		case 46: goto st2;
		case 69: goto st3;
		case 101: goto st3;
		case 120: goto st5;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr23;
	goto tr21;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr4;
	goto tr3;
tr4:
#line 1 "NONE"
	{te = p+1;}
#line 29 "logfmt_scan.rl"
	{act = 4;}
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
#line 216 "logfmt_scan.c"
	switch( (*p) ) {
		case 69: goto st3;
		case 101: goto st3;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr4;
	goto tr26;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	switch( (*p) ) {
		case 43: goto st4;
		case 45: goto st4;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st12;
	goto tr3;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st12;
	goto tr3;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st12;
	goto tr26;
tr23:
#line 1 "NONE"
	{te = p+1;}
#line 30 "logfmt_scan.rl"
	{act = 5;}
	goto st13;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
#line 259 "logfmt_scan.c"
	switch( (*p) ) {
		case 46: goto st2;
		case 69: goto st3;
		case 101: goto st3;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr23;
	goto tr27;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st14;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st14;
	} else
		goto st14;
	goto tr7;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st14;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st14;
	} else
		goto st14;
	goto tr28;
tr14:
#line 1 "NONE"
	{te = p+1;}
#line 32 "logfmt_scan.rl"
	{act = 7;}
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 304 "logfmt_scan.c"
	switch( (*p) ) {
		case 46: goto st2;
		case 69: goto st3;
		case 101: goto st3;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr14;
	goto tr21;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	switch( (*p) ) {
		case 33: goto st9;
		case 97: goto st17;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st9;
	} else if ( (*p) >= 35 )
		goto st9;
	goto tr20;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	switch( (*p) ) {
		case 33: goto st9;
		case 108: goto st18;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st9;
	} else if ( (*p) >= 35 )
		goto st9;
	goto tr20;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	switch( (*p) ) {
		case 33: goto st9;
		case 115: goto st19;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st9;
	} else if ( (*p) >= 35 )
		goto st9;
	goto tr20;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	if ( (*p) == 33 )
		goto st9;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st9;
	} else if ( (*p) >= 35 )
		goto st9;
	goto tr20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	switch( (*p) ) {
		case 33: goto st9;
		case 114: goto st21;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st9;
	} else if ( (*p) >= 35 )
		goto st9;
	goto tr20;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	switch( (*p) ) {
		case 33: goto st9;
		case 117: goto st19;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st9;
	} else if ( (*p) >= 35 )
		goto st9;
	goto tr20;
	}
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 7: goto tr18;
	case 8: goto tr19;
	case 9: goto tr20;
	case 10: goto tr21;
	case 2: goto tr3;
	case 11: goto tr26;
	case 3: goto tr3;
	case 4: goto tr3;
	case 12: goto tr26;
	case 13: goto tr27;
	case 5: goto tr7;
	case 14: goto tr28;
	case 15: goto tr21;
	case 16: goto tr20;
	case 17: goto tr20;
	case 18: goto tr20;
	case 19: goto tr20;
	case 20: goto tr20;
	case 21: goto tr20;
	}
	}

	_out: {}
	}

#line 55 "logfmt_scan.rl"


  return 0;
}
