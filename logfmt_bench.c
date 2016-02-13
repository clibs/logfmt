

#include <locale.h>
#include <stdio.h>
#include <strings.h>

#include "bench.h"
#include "logfmt.h"

int
main() {
  char *s = "request at=finish status=200 user=brandur@mutelight.org \t\t"
            "user_id=1234 app=mutelight app_id=1234 mode=0644 color=0xffeE01\n";

  float start = cpu();
  int ops = 10e6;
  size_t len = strlen(s);

  for (size_t i = 0; i < ops; i++) {
    if (logfmt_parse_callback(s, len, logfmt_noop, NULL) < 0) {
      printf("error parsing\n");
      return 1;
    }
  }

  setlocale(LC_ALL, "");

  float d = cpu() - start;
  printf("len: %lu\n", len);
  printf("ops: %'d\n", ops);
  printf("ops/s: %'.2f\n", ops / d);
  printf("MiB/s: %'.2lu\n", ops * len / (1 << 20));
  printf("duration: %.2fs\n", d);

  return 0;
}
