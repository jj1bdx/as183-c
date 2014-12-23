# AS183 PRNG algorithm internal state calculator in C

A preliminary result running in OS X 10.10.1 of Mac Mini 2012 (2.6GHz Core i7) shows this in *less than 9 hours*:

```
Internal state loop detected
count = 6953607871644, y1 = 3172, y2=9814, y3 = 20125
```

`bc` command result says the cycle length is about `2^(42.661)`:

```
l(6953607871644)/l(2)
42.66089885144506525546
```

## how to compile

```
cc -O3 -o main main.c # main: internal state loop tester
cc -o main2 main.c # main2: dump all possible internal state values
```

