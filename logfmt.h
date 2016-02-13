
#ifndef LOGFMT_H
#define LOGFMT_H

#include <stdlib.h>

// List of tokens.
#define LOGFMT_TOKEN_LIST \
  t(ILLEGAL) t(LIT) t(EQ) t(FLOAT) t(DECIMAL) t(OCTAL) t(HEX) t(EOL)

// Log token.
typedef enum {
#define t(T) LOGFMT_TOK_##T,
  LOGFMT_TOKEN_LIST
#undef t
} logfmt_token_t;

// Scanner callback function. The buffer passed is a reference of the original,
// and should be copied if you wish you manipulate or store elsewhere.
typedef void (*logfmt_callback_t)(logfmt_token_t, const char *, size_t, void *);

// Scan with callback function.
int logfmt_scan(char *buf, size_t len, logfmt_callback_t cb, void *data);

// Helper function for returning a token string name.
const char *logfmt_token_name(logfmt_token_t token);

// Helper callback for dumping tokens to stdout.
void logfmt_dump(logfmt_token_t, const char *, size_t, void *);

// Helper callback for no-oping, useful for benchmarks.
void logfmt_noop(logfmt_token_t, const char *, size_t, void *);

#endif /* LOGFMT_H */
