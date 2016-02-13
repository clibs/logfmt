
#line 1 "logfmt.rl"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "logfmt.h"

#define emit(T) \
  cb(T, ts, te - ts, data)


#line 15 "logfmt.c"
static const int logfmt_start = 2;

static const int logfmt_en_main = 2;


#line 36 "logfmt.rl"



int
logfmt_parse_callback(char *buf, size_t len, logfmt_callback_t cb, void *data) {
  char *pe = buf + len;
  char *ts, *te;
  char *eof = 0;
  char *p = buf;
  int act = 0;

  (void) logfmt_en_main;

  int cs;

  
#line 38 "logfmt.c"
	{
	cs = logfmt_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 46 "logfmt.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr1:
#line 31 "logfmt.rl"
	{te = p+1;{ emit(LOGFMT_TOK_LIT); }}
	goto st2;
tr4:
#line 32 "logfmt.rl"
	{te = p+1;{ emit(LOGFMT_TOK_EOL); }}
	goto st2;
tr10:
#line 30 "logfmt.rl"
	{te = p+1;{ emit(LOGFMT_TOK_EQ); }}
	goto st2;
tr11:
#line 33 "logfmt.rl"
	{te = p;p--;}
	goto st2;
tr12:
#line 32 "logfmt.rl"
	{te = p;p--;{ emit(LOGFMT_TOK_EOL); }}
	goto st2;
tr13:
#line 29 "logfmt.rl"
	{te = p;p--;{ emit(LOGFMT_TOK_LIT); }}
	goto st2;
tr15:
#line 26 "logfmt.rl"
	{te = p;p--;{ emit(LOGFMT_TOK_FLOAT); }}
	goto st2;
tr19:
#line 1 "NONE"
	{	switch( act ) {
	case 2:
	{{p = ((te))-1;} emit(LOGFMT_TOK_FLOAT); }
	break;
	case 4:
	{{p = ((te))-1;} emit(LOGFMT_TOK_HEX); }
	break;
	case 5:
	{{p = ((te))-1;} emit(LOGFMT_TOK_LIT); }
	break;
	}
	}
	goto st2;
tr20:
#line 25 "logfmt.rl"
	{te = p;p--;{ emit(LOGFMT_TOK_DECIMAL); }}
	goto st2;
tr23:
#line 27 "logfmt.rl"
	{te = p;p--;{ emit(LOGFMT_TOK_OCTAL); }}
	goto st2;
st2:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 1 "NONE"
	{ts = p;}
#line 111 "logfmt.c"
	switch( (*p) ) {
		case 9: goto st3;
		case 10: goto tr4;
		case 13: goto st4;
		case 32: goto st3;
		case 34: goto st1;
		case 46: goto st6;
		case 48: goto st10;
		case 61: goto tr10;
	}
	if ( (*p) < 49 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto st5;
	} else if ( (*p) > 57 ) {
		if ( 58 <= (*p) && (*p) <= 126 )
			goto st5;
	} else
		goto st13;
	goto st0;
st0:
cs = 0;
	goto _out;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	switch( (*p) ) {
		case 9: goto st3;
		case 32: goto st3;
	}
	goto tr11;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( (*p) == 10 )
		goto tr4;
	goto tr12;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 33 )
		goto st5;
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st5;
	} else if ( (*p) >= 35 )
		goto st5;
	goto tr13;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	switch( (*p) ) {
		case 34: goto tr1;
		case 92: goto st0;
	}
	goto st1;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 33 )
		goto st5;
	if ( (*p) < 48 ) {
		if ( 35 <= (*p) && (*p) <= 47 )
			goto st5;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 60 ) {
			if ( 62 <= (*p) && (*p) <= 126 )
				goto st5;
		} else if ( (*p) >= 58 )
			goto st5;
	} else
		goto st7;
	goto tr13;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	switch( (*p) ) {
		case 33: goto st5;
		case 69: goto st8;
		case 101: goto st8;
	}
	if ( (*p) < 48 ) {
		if ( 35 <= (*p) && (*p) <= 47 )
			goto st5;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 60 ) {
			if ( 62 <= (*p) && (*p) <= 126 )
				goto st5;
		} else if ( (*p) >= 58 )
			goto st5;
	} else
		goto st7;
	goto tr15;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	switch( (*p) ) {
		case 33: goto st5;
		case 43: goto tr17;
		case 45: goto tr17;
	}
	if ( (*p) < 48 ) {
		if ( 35 <= (*p) && (*p) <= 47 )
			goto st5;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 60 ) {
			if ( 62 <= (*p) && (*p) <= 126 )
				goto st5;
		} else if ( (*p) >= 58 )
			goto st5;
	} else
		goto tr18;
	goto tr13;
tr17:
#line 1 "NONE"
	{te = p+1;}
#line 29 "logfmt.rl"
	{act = 5;}
	goto st9;
tr18:
#line 1 "NONE"
	{te = p+1;}
#line 26 "logfmt.rl"
	{act = 2;}
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
#line 247 "logfmt.c"
	if ( (*p) == 33 )
		goto st5;
	if ( (*p) < 48 ) {
		if ( 35 <= (*p) && (*p) <= 47 )
			goto st5;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 60 ) {
			if ( 62 <= (*p) && (*p) <= 126 )
				goto st5;
		} else if ( (*p) >= 58 )
			goto st5;
	} else
		goto tr18;
	goto tr19;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	switch( (*p) ) {
		case 33: goto st5;
		case 46: goto st7;
		case 69: goto st8;
		case 101: goto st8;
		case 120: goto tr22;
	}
	if ( (*p) < 48 ) {
		if ( 35 <= (*p) && (*p) <= 47 )
			goto st5;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 60 ) {
			if ( 62 <= (*p) && (*p) <= 126 )
				goto st5;
		} else if ( (*p) >= 58 )
			goto st5;
	} else
		goto st11;
	goto tr20;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	switch( (*p) ) {
		case 33: goto st5;
		case 46: goto st7;
		case 69: goto st8;
		case 101: goto st8;
	}
	if ( (*p) < 48 ) {
		if ( 35 <= (*p) && (*p) <= 47 )
			goto st5;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 60 ) {
			if ( 62 <= (*p) && (*p) <= 126 )
				goto st5;
		} else if ( (*p) >= 58 )
			goto st5;
	} else
		goto st11;
	goto tr23;
tr22:
#line 1 "NONE"
	{te = p+1;}
#line 29 "logfmt.rl"
	{act = 5;}
	goto st12;
tr24:
#line 1 "NONE"
	{te = p+1;}
#line 28 "logfmt.rl"
	{act = 4;}
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 323 "logfmt.c"
	if ( (*p) == 33 )
		goto st5;
	if ( (*p) < 62 ) {
		if ( (*p) < 48 ) {
			if ( 35 <= (*p) && (*p) <= 47 )
				goto st5;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 60 )
				goto st5;
		} else
			goto tr24;
	} else if ( (*p) > 64 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto tr24;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 126 )
					goto st5;
			} else if ( (*p) >= 97 )
				goto tr24;
		} else
			goto st5;
	} else
		goto st5;
	goto tr19;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	switch( (*p) ) {
		case 33: goto st5;
		case 46: goto st7;
		case 69: goto st8;
		case 101: goto st8;
	}
	if ( (*p) < 48 ) {
		if ( 35 <= (*p) && (*p) <= 47 )
			goto st5;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 60 ) {
			if ( 62 <= (*p) && (*p) <= 126 )
				goto st5;
		} else if ( (*p) >= 58 )
			goto st5;
	} else
		goto st13;
	goto tr20;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 3: goto tr11;
	case 4: goto tr12;
	case 5: goto tr13;
	case 6: goto tr13;
	case 7: goto tr15;
	case 8: goto tr13;
	case 9: goto tr19;
	case 10: goto tr20;
	case 11: goto tr23;
	case 12: goto tr19;
	case 13: goto tr20;
	}
	}

	_out: {}
	}

#line 54 "logfmt.rl"


  return 0;
}
