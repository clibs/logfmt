
#line 1 "logfmt_parse.rl"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "logfmt.h"

// TODO: handle strtoll/strtod retvals

#define emit(T) \
  field.type = LOGFMT_##T; \
  cb(&field, data)


#line 18 "logfmt_parse.c"
static const int parser_start = 1;

static const int parser_en_main = 1;


#line 98 "logfmt_parse.rl"


int
logfmt_parse(char *buf, size_t len, logfmt_parse_callback_t cb, void *data) {
  char *pe = buf + len;
  char *mark = 0;
  char *eof = pe;
  char *p = buf;
  int has_value = 0;

  logfmt_field_t field = {0};

  (void) parser_en_main;

  int cs;

  
#line 42 "logfmt_parse.c"
	{
	cs = parser_start;
	}

#line 47 "logfmt_parse.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 1:
	if ( (*p) == 33 )
		goto tr0;
	if ( (*p) < 58 ) {
		if ( 35 <= (*p) && (*p) <= 47 )
			goto tr0;
	} else if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto tr0;
	} else
		goto tr0;
	goto st0;
st0:
cs = 0;
	goto _out;
tr0:
#line 22 "logfmt_parse.rl"
	{
    has_value = false;
    field.name = p;
  }
	goto st2;
tr59:
#line 78 "logfmt_parse.rl"
	{
    return p-buf;
  }
#line 22 "logfmt_parse.rl"
	{
    has_value = false;
    field.name = p;
  }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 90 "logfmt_parse.c"
	switch( (*p) ) {
		case 9: goto tr2;
		case 10: goto tr3;
		case 13: goto tr4;
		case 32: goto tr2;
		case 33: goto st2;
		case 61: goto tr6;
	}
	if ( 35 <= (*p) && (*p) <= 126 )
		goto st2;
	goto st0;
tr2:
#line 27 "logfmt_parse.rl"
	{
    field.name_len = p - field.name;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st27;
tr13:
#line 61 "logfmt_parse.rl"
	{
    field.value.as_string = mark;
    field.string_len = p-mark;
    emit(STRING);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st27;
tr21:
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st27;
tr24:
#line 31 "logfmt_parse.rl"
	{
    field.value.as_int = strtoll(mark, &p, 10);
    emit(INT);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st27;
tr32:
#line 46 "logfmt_parse.rl"
	{
    field.value.as_float = strtod(mark, &p);
    emit(FLOAT);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st27;
tr37:
#line 36 "logfmt_parse.rl"
	{
    field.value.as_int = strtoll(mark, &p, 8);
    emit(INT);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st27;
tr41:
#line 41 "logfmt_parse.rl"
	{
    field.value.as_int = strtoll(mark, &p, 16);
    emit(INT);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st27;
tr49:
#line 56 "logfmt_parse.rl"
	{
    field.value.as_bool = false;
    emit(BOOL);
  }
#line 61 "logfmt_parse.rl"
	{
    field.value.as_string = mark;
    field.string_len = p-mark;
    emit(STRING);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st27;
tr55:
#line 51 "logfmt_parse.rl"
	{
    field.value.as_bool = true;
    emit(BOOL);
  }
#line 61 "logfmt_parse.rl"
	{
    field.value.as_string = mark;
    field.string_len = p-mark;
    emit(STRING);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 271 "logfmt_parse.c"
	switch( (*p) ) {
		case 9: goto st27;
		case 32: goto st27;
		case 33: goto tr0;
	}
	if ( (*p) < 58 ) {
		if ( 35 <= (*p) && (*p) <= 47 )
			goto tr0;
	} else if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto tr0;
	} else
		goto tr0;
	goto st0;
tr3:
#line 27 "logfmt_parse.rl"
	{
    field.name_len = p - field.name;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st28;
tr14:
#line 61 "logfmt_parse.rl"
	{
    field.value.as_string = mark;
    field.string_len = p-mark;
    emit(STRING);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st28;
tr22:
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st28;
tr25:
#line 31 "logfmt_parse.rl"
	{
    field.value.as_int = strtoll(mark, &p, 10);
    emit(INT);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st28;
tr33:
#line 46 "logfmt_parse.rl"
	{
    field.value.as_float = strtod(mark, &p);
    emit(FLOAT);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st28;
tr38:
#line 36 "logfmt_parse.rl"
	{
    field.value.as_int = strtoll(mark, &p, 8);
    emit(INT);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st28;
tr42:
#line 41 "logfmt_parse.rl"
	{
    field.value.as_int = strtoll(mark, &p, 16);
    emit(INT);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st28;
tr50:
#line 56 "logfmt_parse.rl"
	{
    field.value.as_bool = false;
    emit(BOOL);
  }
#line 61 "logfmt_parse.rl"
	{
    field.value.as_string = mark;
    field.string_len = p-mark;
    emit(STRING);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st28;
tr56:
#line 51 "logfmt_parse.rl"
	{
    field.value.as_bool = true;
    emit(BOOL);
  }
#line 61 "logfmt_parse.rl"
	{
    field.value.as_string = mark;
    field.string_len = p-mark;
    emit(STRING);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
#line 455 "logfmt_parse.c"
	if ( (*p) == 33 )
		goto tr59;
	if ( (*p) < 58 ) {
		if ( 35 <= (*p) && (*p) <= 47 )
			goto tr59;
	} else if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto tr59;
	} else
		goto tr59;
	goto st0;
tr4:
#line 27 "logfmt_parse.rl"
	{
    field.name_len = p - field.name;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st29;
tr15:
#line 61 "logfmt_parse.rl"
	{
    field.value.as_string = mark;
    field.string_len = p-mark;
    emit(STRING);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st29;
tr23:
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st29;
tr26:
#line 31 "logfmt_parse.rl"
	{
    field.value.as_int = strtoll(mark, &p, 10);
    emit(INT);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st29;
tr34:
#line 46 "logfmt_parse.rl"
	{
    field.value.as_float = strtod(mark, &p);
    emit(FLOAT);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st29;
tr39:
#line 36 "logfmt_parse.rl"
	{
    field.value.as_int = strtoll(mark, &p, 8);
    emit(INT);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st29;
tr43:
#line 41 "logfmt_parse.rl"
	{
    field.value.as_int = strtoll(mark, &p, 16);
    emit(INT);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st29;
tr51:
#line 56 "logfmt_parse.rl"
	{
    field.value.as_bool = false;
    emit(BOOL);
  }
#line 61 "logfmt_parse.rl"
	{
    field.value.as_string = mark;
    field.string_len = p-mark;
    emit(STRING);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st29;
tr57:
#line 51 "logfmt_parse.rl"
	{
    field.value.as_bool = true;
    emit(BOOL);
  }
#line 61 "logfmt_parse.rl"
	{
    field.value.as_string = mark;
    field.string_len = p-mark;
    emit(STRING);
  }
#line 67 "logfmt_parse.rl"
	{
    has_value = 1;
  }
#line 71 "logfmt_parse.rl"
	{
    if (!has_value) {
      field.value.as_bool = true;
      emit(BOOL);
    }
  }
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 636 "logfmt_parse.c"
	switch( (*p) ) {
		case 10: goto st28;
		case 33: goto tr59;
	}
	if ( (*p) < 58 ) {
		if ( 35 <= (*p) && (*p) <= 47 )
			goto tr59;
	} else if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto tr59;
	} else
		goto tr59;
	goto st0;
tr6:
#line 27 "logfmt_parse.rl"
	{
    field.name_len = p - field.name;
  }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 660 "logfmt_parse.c"
	switch( (*p) ) {
		case 34: goto st5;
		case 48: goto tr9;
		case 102: goto tr11;
		case 116: goto tr12;
	}
	if ( (*p) < 49 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto tr7;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 60 ) {
			if ( 62 <= (*p) && (*p) <= 126 )
				goto tr7;
		} else if ( (*p) >= 58 )
			goto tr7;
	} else
		goto tr10;
	goto st0;
tr7:
#line 18 "logfmt_parse.rl"
	{
    mark = p;
  }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 689 "logfmt_parse.c"
	switch( (*p) ) {
		case 9: goto tr13;
		case 10: goto tr14;
		case 13: goto tr15;
		case 32: goto tr13;
		case 33: goto st4;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st4;
	} else if ( (*p) >= 35 )
		goto st4;
	goto st0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	switch( (*p) ) {
		case 34: goto tr18;
		case 92: goto st0;
	}
	goto tr17;
tr17:
#line 18 "logfmt_parse.rl"
	{
    mark = p;
  }
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 722 "logfmt_parse.c"
	switch( (*p) ) {
		case 34: goto tr20;
		case 92: goto st0;
	}
	goto st6;
tr18:
#line 18 "logfmt_parse.rl"
	{
    mark = p;
  }
#line 61 "logfmt_parse.rl"
	{
    field.value.as_string = mark;
    field.string_len = p-mark;
    emit(STRING);
  }
	goto st7;
tr20:
#line 61 "logfmt_parse.rl"
	{
    field.value.as_string = mark;
    field.string_len = p-mark;
    emit(STRING);
  }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 752 "logfmt_parse.c"
	switch( (*p) ) {
		case 9: goto tr21;
		case 10: goto tr22;
		case 13: goto tr23;
		case 32: goto tr21;
	}
	goto st0;
tr9:
#line 18 "logfmt_parse.rl"
	{
    mark = p;
  }
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 770 "logfmt_parse.c"
	switch( (*p) ) {
		case 9: goto tr24;
		case 10: goto tr25;
		case 13: goto tr26;
		case 32: goto tr24;
		case 46: goto st9;
		case 69: goto st11;
		case 101: goto st11;
		case 120: goto st15;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st14;
	goto st0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st10;
	goto st0;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	switch( (*p) ) {
		case 9: goto tr32;
		case 10: goto tr33;
		case 13: goto tr34;
		case 32: goto tr32;
		case 69: goto st11;
		case 101: goto st11;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st10;
	goto st0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	switch( (*p) ) {
		case 43: goto st12;
		case 45: goto st12;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st13;
	goto st0;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st13;
	goto st0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	switch( (*p) ) {
		case 9: goto tr32;
		case 10: goto tr33;
		case 13: goto tr34;
		case 32: goto tr32;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st13;
	goto st0;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	switch( (*p) ) {
		case 9: goto tr37;
		case 10: goto tr38;
		case 13: goto tr39;
		case 32: goto tr37;
		case 46: goto st9;
		case 69: goto st11;
		case 101: goto st11;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st14;
	goto st0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st16;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st16;
	} else
		goto st16;
	goto st0;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	switch( (*p) ) {
		case 9: goto tr41;
		case 10: goto tr42;
		case 13: goto tr43;
		case 32: goto tr41;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st16;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st16;
	} else
		goto st16;
	goto st0;
tr10:
#line 18 "logfmt_parse.rl"
	{
    mark = p;
  }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 895 "logfmt_parse.c"
	switch( (*p) ) {
		case 9: goto tr24;
		case 10: goto tr25;
		case 13: goto tr26;
		case 32: goto tr24;
		case 46: goto st9;
		case 69: goto st11;
		case 101: goto st11;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st17;
	goto st0;
tr11:
#line 18 "logfmt_parse.rl"
	{
    mark = p;
  }
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
#line 918 "logfmt_parse.c"
	switch( (*p) ) {
		case 9: goto tr13;
		case 10: goto tr14;
		case 13: goto tr15;
		case 32: goto tr13;
		case 33: goto st4;
		case 97: goto st19;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st4;
	} else if ( (*p) >= 35 )
		goto st4;
	goto st0;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	switch( (*p) ) {
		case 9: goto tr13;
		case 10: goto tr14;
		case 13: goto tr15;
		case 32: goto tr13;
		case 33: goto st4;
		case 108: goto st20;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st4;
	} else if ( (*p) >= 35 )
		goto st4;
	goto st0;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	switch( (*p) ) {
		case 9: goto tr13;
		case 10: goto tr14;
		case 13: goto tr15;
		case 32: goto tr13;
		case 33: goto st4;
		case 115: goto st21;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st4;
	} else if ( (*p) >= 35 )
		goto st4;
	goto st0;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	switch( (*p) ) {
		case 9: goto tr13;
		case 10: goto tr14;
		case 13: goto tr15;
		case 32: goto tr13;
		case 33: goto st4;
		case 101: goto st22;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st4;
	} else if ( (*p) >= 35 )
		goto st4;
	goto st0;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	switch( (*p) ) {
		case 9: goto tr49;
		case 10: goto tr50;
		case 13: goto tr51;
		case 32: goto tr49;
		case 33: goto st4;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st4;
	} else if ( (*p) >= 35 )
		goto st4;
	goto st0;
tr12:
#line 18 "logfmt_parse.rl"
	{
    mark = p;
  }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
#line 1014 "logfmt_parse.c"
	switch( (*p) ) {
		case 9: goto tr13;
		case 10: goto tr14;
		case 13: goto tr15;
		case 32: goto tr13;
		case 33: goto st4;
		case 114: goto st24;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st4;
	} else if ( (*p) >= 35 )
		goto st4;
	goto st0;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	switch( (*p) ) {
		case 9: goto tr13;
		case 10: goto tr14;
		case 13: goto tr15;
		case 32: goto tr13;
		case 33: goto st4;
		case 117: goto st25;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st4;
	} else if ( (*p) >= 35 )
		goto st4;
	goto st0;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	switch( (*p) ) {
		case 9: goto tr13;
		case 10: goto tr14;
		case 13: goto tr15;
		case 32: goto tr13;
		case 33: goto st4;
		case 101: goto st26;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st4;
	} else if ( (*p) >= 35 )
		goto st4;
	goto st0;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	switch( (*p) ) {
		case 9: goto tr55;
		case 10: goto tr56;
		case 13: goto tr57;
		case 32: goto tr55;
		case 33: goto st4;
	}
	if ( (*p) > 60 ) {
		if ( 62 <= (*p) && (*p) <= 126 )
			goto st4;
	} else if ( (*p) >= 35 )
		goto st4;
	goto st0;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 28: 
	case 29: 
#line 78 "logfmt_parse.rl"
	{
    return p-buf;
  }
	break;
#line 1123 "logfmt_parse.c"
	}
	}

	_out: {}
	}

#line 117 "logfmt_parse.rl"


  return 0;
}
