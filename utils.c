
#include <stdio.h>
#include <stdlib.h>

#include "logfmt.h"

static char *names[] = {
#define t(T) #T,
    LOGFMT_TOKEN_LIST
#undef t
};

const char *
logfmt_token_name(logfmt_token_t token) {
  return names[token];
}

void
logfmt_dump(logfmt_token_t token, const char *buf, size_t len, void *data) {
  printf("  \e[34m%s\e[0m: '%.*s'\n", logfmt_token_name(token), (int)len, buf);
}

inline void
logfmt_noop(logfmt_token_t token, const char *buf, size_t len, void *data) {
}
