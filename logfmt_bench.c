

#include <locale.h>
#include <stdio.h>
#include <strings.h>

#include "bench.h"
#include "logfmt.h"

int
scan() {
  char *s = "request at=finish status=200 user=brandur@mutelight.org "
            "user_id=1234 app=mutelight app_id=1234 mode=0644 color=0xffeE01\n";

  float start = cpu();
  int ops = 10e6;
  size_t len = strlen(s);

  for (size_t i = 0; i < ops; i++) {
    if (logfmt_scan(s, len, logfmt_token_noop, NULL) < 0) {
      printf("error parsing\n");
      return 1;
    }
  }

  setlocale(LC_ALL, "");

  float d = cpu() - start;
  printf("\n  Scanner:\n");
  printf("   len: %lu\n", len);
  printf("   ops: %'d\n", ops);
  printf("   ops/s: %'.2f\n", ops / d);
  printf("   ns/op: %'.2f\n", d / ops * 1e9);
  printf("   MiB/s: %'.2lu\n", ops * len / (1 << 20));
  printf("   duration: %.2fs\n", d);
  return 0;
}

int
parse() {
  char *s = "request at=finish status=200 user=brandur@mutelight.org "
            "user_id=1234 app=mutelight app_id=1234 mode=0644 color=0xffeE01\n";

  float start = cpu();
  int ops = 10e6;
  size_t len = strlen(s);

  for (size_t i = 0; i < ops; i++) {
    if (logfmt_parse(s, len, logfmt_field_noop, NULL) < 0) {
      printf("error parsing\n");
      return 1;
    }
  }

  setlocale(LC_ALL, "");

  float d = cpu() - start;
  printf("\n  Parser:\n");
  printf("   len: %lu\n", len);
  printf("   ops: %'d\n", ops);
  printf("   ops/s: %'.2f\n", ops / d);
  printf("   ns/op: %'.2f\n", d / ops * 1e9);
  printf("   MiB/s: %'.2lu\n", ops * len / (1 << 20));
  printf("   duration: %.2fs\n", d);
  return 0;
}

int
main() {
  if (scan() < 0) return 1;
  if (parse() < 0) return 1;
  printf("\n");
  return 0;
}
