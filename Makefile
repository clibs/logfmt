
CFLAGS = -Wall -I deps/* -O3

example: utils.c logfmt.c logfmt_example.c
	$(CC) $(CFLAGS) $^ -o $@

bench: utils.c logfmt.c logfmt_bench.c
	$(CC) $(CFLAGS) $^ -o $@

logfmt.c: logfmt.rl
	ragel $< -o $@ -G2

clean:
	rm -f logfmt.c bench example
.PHONY: clean
