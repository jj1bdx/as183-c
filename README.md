# AS183 PRNG algorithm internal state calculator in C

* This is a PoC code to show Erlang/OTP random module PRNG weakness.

## Execution time example

* FreeBSD 10.1-STABLE #56 r275872 (amd64)
* On `Intel(R) Core(TM) i5-3427U CPU @ 1.80GHz (2294.84-MHz)`
* 8h18m37s = 29917 seconds
* Begin: Tue Dec 23 09:21:33 JST 2014
* End:   Tue Dec 23 17:40:10 JST 2014

## Test result

Results for every 100 million counts: `interval-log.txt`

```
Internal state loop detected
count = 6953607871644 y1 = 3172 y2 = 9814 y3 = 20125
```

`bc` command result says the cycle length is about `2^(42.661)`:

```
l(6953607871644)/l(2)
42.66089885144506525546
```

See also <http://erlang.org/pipermail/erlang-bugs/2014-December/004728.html>

Execution of main3.c proved no Erlang/OTP `random:uniform/1` output is less than 1.0e-13.

## how to compile

Use `build.sh`, or:

```
# main: internal state loop tester
cc -O3 -o main main.c
# main2: dump all possible internal state values
cc -o main2 main.c
# main3: check all internal states and
#        find if any OTP random:uniform/1
#        output value is less than < 1.0e-13
cc -O3 -o main3 main3.c
```

