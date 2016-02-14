
CFLAGS = -Wall -I deps/* -O3

example: utils.c logfmt_scan.c logfmt_parse.c logfmt_example.c
	$(CC) $(CFLAGS) $^ -o $@

bench: utils.c logfmt_scan.c logfmt_parse.c logfmt_bench.c
	$(CC) $(CFLAGS) $^ -o $@

logfmt_scan.c: logfmt_scan.rl
	ragel $< -o $@ -G2

logfmt_parse.c: logfmt_parse.rl
	ragel $< -o $@ -G2

%.png: %.rl
	ragel -Vp $< | dot -Tpng > $@

clean:
	rm -f logfmt_scan.c logfmt_parse.c bench example *.png
.PHONY: clean
