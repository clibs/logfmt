
#include <stdio.h>
#include <strings.h>

#include "logfmt.h"

int
main() {
  char *s = "request at=finish status=200 user=brandur@mutelight.org \t\t"
            "user_id=1234 app=mutelight app_id=1234 mode=0644 color=0xffeE01\n";

  if (logfmt_scan(s, strlen(s), logfmt_dump, NULL) < 0) {
    printf("error parsing\n");
    return 1;
  }

  return 0;
}
