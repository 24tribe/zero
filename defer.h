#ifndef DEFER_H_MON_FEB_16_2026_02_19
#define DEFER_H_MON_FEB_16_2026_02_19

// https://thephd.dev/c2y-the-defer-technical-specification-its-time-go-go-go
// https://gustedt.wordpress.com/2026/02/15/defer-available-in-gcc-and-clang/

#if __has_include(<stddefer.h>)
# include <stddefer.h>
# if defined(__clang__)
#  if __is_identifier(_Defer)
#   error "clang may need the option -fdefer-ts for the _Defer feature"
#  endif
# endif
#elif __GNUC__ > 8
# define defer _Defer
# define _Defer      _Defer_A(__COUNTER__)
# define _Defer_A(N) _Defer_B(N)
# define _Defer_B(N) _Defer_C(_Defer_func_ ## N, _Defer_var_ ## N)
# define _Defer_C(F, V)                                                 \
  auto void F(int*);                                                    \
  __attribute__((__cleanup__(F), __deprecated__, __unused__))           \
     int V;                                                             \
  __attribute__((__always_inline__, __deprecated__, __unused__))        \
    inline auto void F(__attribute__((__unused__)) int*V)
#else
# error "The _Defer feature seems not available"
#endif

#endif