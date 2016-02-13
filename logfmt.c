
#line 1 "logfmt.rl"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "logfmt.h"

#define emit(T) \
  cb(T, ts, te - ts, data)


#line 15 "logfmt.c"
static const char _logfmt_actions[] = {
	0, 1, 0, 1, 1, 1, 6, 1, 
	7, 1, 8, 1, 9, 1, 10, 1, 
	11, 1, 12, 1, 13, 1, 14, 1, 
	15, 2, 2, 3, 2, 2, 4, 2, 
	2, 5
};

static const char _logfmt_key_offsets[] = {
	0, 0, 2, 16, 18, 19, 24, 33, 
	44, 55, 64, 77, 89, 106
};

static const char _logfmt_trans_keys[] = {
	34, 92, 9, 10, 13, 32, 34, 46, 
	48, 61, 33, 47, 49, 57, 58, 126, 
	9, 32, 10, 33, 35, 60, 62, 126, 
	33, 35, 47, 48, 57, 58, 60, 62, 
	126, 33, 69, 101, 35, 47, 48, 57, 
	58, 60, 62, 126, 33, 43, 45, 35, 
	47, 48, 57, 58, 60, 62, 126, 33, 
	35, 47, 48, 57, 58, 60, 62, 126, 
	33, 46, 69, 101, 120, 35, 47, 48, 
	57, 58, 60, 62, 126, 33, 46, 69, 
	101, 35, 47, 48, 57, 58, 60, 62, 
	126, 33, 35, 47, 48, 57, 58, 60, 
	62, 64, 65, 70, 71, 96, 97, 102, 
	103, 126, 33, 46, 69, 101, 35, 47, 
	48, 57, 58, 60, 62, 126, 0
};

static const char _logfmt_single_lengths[] = {
	0, 2, 8, 2, 1, 1, 1, 3, 
	3, 1, 5, 4, 1, 4
};

static const char _logfmt_range_lengths[] = {
	0, 0, 3, 0, 0, 2, 4, 4, 
	4, 4, 4, 4, 8, 4
};

static const char _logfmt_index_offsets[] = {
	0, 0, 3, 15, 18, 20, 24, 30, 
	38, 46, 52, 62, 71, 81
};

static const char _logfmt_indicies[] = {
	1, 2, 0, 3, 4, 5, 3, 0, 
	7, 8, 10, 6, 9, 6, 2, 3, 
	3, 11, 4, 12, 6, 6, 6, 13, 
	6, 6, 14, 6, 6, 13, 6, 16, 
	16, 6, 14, 6, 6, 15, 6, 17, 
	17, 6, 18, 6, 6, 13, 6, 6, 
	18, 6, 6, 19, 6, 14, 16, 16, 
	22, 6, 21, 6, 6, 20, 6, 14, 
	16, 16, 6, 21, 6, 6, 23, 6, 
	6, 24, 6, 6, 24, 6, 24, 6, 
	19, 6, 14, 16, 16, 6, 9, 6, 
	6, 20, 0
};

static const char _logfmt_trans_targs[] = {
	1, 2, 0, 3, 2, 4, 5, 6, 
	10, 13, 2, 2, 2, 2, 7, 2, 
	8, 9, 9, 2, 2, 11, 12, 2, 
	12
};

static const char _logfmt_trans_actions[] = {
	0, 7, 0, 0, 9, 0, 0, 0, 
	0, 0, 5, 21, 19, 17, 0, 13, 
	0, 31, 25, 23, 11, 0, 31, 15, 
	28
};

static const char _logfmt_to_state_actions[] = {
	0, 0, 1, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0
};

static const char _logfmt_from_state_actions[] = {
	0, 0, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0
};

static const char _logfmt_eof_trans[] = {
	0, 0, 0, 12, 13, 14, 14, 16, 
	14, 20, 21, 24, 20, 21
};

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

  
#line 128 "logfmt.c"
	{
	cs = logfmt_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 136 "logfmt.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_acts = _logfmt_actions + _logfmt_from_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 1:
#line 1 "NONE"
	{ts = p;}
	break;
#line 157 "logfmt.c"
		}
	}

	_keys = _logfmt_trans_keys + _logfmt_key_offsets[cs];
	_trans = _logfmt_index_offsets[cs];

	_klen = _logfmt_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _logfmt_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _logfmt_indicies[_trans];
_eof_trans:
	cs = _logfmt_trans_targs[_trans];

	if ( _logfmt_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _logfmt_actions + _logfmt_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 2:
#line 1 "NONE"
	{te = p+1;}
	break;
	case 3:
#line 26 "logfmt.rl"
	{act = 2;}
	break;
	case 4:
#line 28 "logfmt.rl"
	{act = 4;}
	break;
	case 5:
#line 29 "logfmt.rl"
	{act = 5;}
	break;
	case 6:
#line 30 "logfmt.rl"
	{te = p+1;{ emit(LOGFMT_TOK_EQ); }}
	break;
	case 7:
#line 31 "logfmt.rl"
	{te = p+1;{ emit(LOGFMT_TOK_LIT); }}
	break;
	case 8:
#line 32 "logfmt.rl"
	{te = p+1;{ emit(LOGFMT_TOK_EOL); }}
	break;
	case 9:
#line 25 "logfmt.rl"
	{te = p;p--;{ emit(LOGFMT_TOK_DECIMAL); }}
	break;
	case 10:
#line 26 "logfmt.rl"
	{te = p;p--;{ emit(LOGFMT_TOK_FLOAT); }}
	break;
	case 11:
#line 27 "logfmt.rl"
	{te = p;p--;{ emit(LOGFMT_TOK_OCTAL); }}
	break;
	case 12:
#line 29 "logfmt.rl"
	{te = p;p--;{ emit(LOGFMT_TOK_LIT); }}
	break;
	case 13:
#line 32 "logfmt.rl"
	{te = p;p--;{ emit(LOGFMT_TOK_EOL); }}
	break;
	case 14:
#line 33 "logfmt.rl"
	{te = p;p--;}
	break;
	case 15:
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
	break;
#line 290 "logfmt.c"
		}
	}

_again:
	_acts = _logfmt_actions + _logfmt_to_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 0:
#line 1 "NONE"
	{ts = 0;}
	break;
#line 303 "logfmt.c"
		}
	}

	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	if ( _logfmt_eof_trans[cs] > 0 ) {
		_trans = _logfmt_eof_trans[cs] - 1;
		goto _eof_trans;
	}
	}

	_out: {}
	}

#line 54 "logfmt.rl"


  return 0;
}
