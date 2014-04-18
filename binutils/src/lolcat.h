#ifndef _LOLCAT_M_H
#define _LOLCAT_M_H

#include <mruby/version.h>

#define LOL_STR_HELPER(x) #x
#define LOL_STR(x) LOL_STR_HELPER(x)

#ifndef LOL_APPNAME
# define LOL_APPNAME "lolcat"
#endif

#ifndef LOL_VERSION
# define LOL_VERSION "0.0.0"
#endif

#define LOL_REPO_URL "https://github.com/dorentus/mruby-lolcat-bin"

#define LOL_SPREAD 3.0
#define LOL_FREQ 0.1
#define LOL_SEED 0
#define LOL_ANIMATE false
#define LOL_DURATION 12
#define LOL_SPEED 20.0
#define LOL_FORCE false

#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) \
  || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
# define LOL_ARCH_NAME "x86_84"
#elif defined(i386) || defined(__i386) || defined(__i386__) \
  || defined(_M_IX86) || defined(__X86__) || defined(_X86_) \
  || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__)
# define LOL_ARCH_NAME "i386"
#elif defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA)
# define LOL_ARCH_NAME "alpha"
#elif defined(__aarch64__)
# define LOL_ARCH_NAME "arm64"
#elif defined(__arm__) || defined(_ARM) || defined(_M_ARM) \
  || defined(_M_ARMT)
# define LOL_ARCH_NAME "arm"
#elif defined(__ia64__) || defined(_IA64) || defined(__IA64__) \
  || defined(__ia64) || defined(_M_IA64) || defined(__itanium__)
# define LOL_ARCH_NAME "ia64"
#elif defined(__m68k__) || defined(M68000) || defined(__MC68K__)
# define LOL_ARCH_NAME "m68k"
#elif defined(__mips__) || defined(mips) || defined(__mips) \
  || defined(__MIPS__)
# define LOL_ARCH_NAME "mips"
#elif defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) \
  || defined(__POWERPC__) || defined(__ppc__) || defined(__ppc64__) \
  || defined(_M_PPC) || defined(_LOL_ARCH_NAME_PPC)
# define LOL_ARCH_NAME "ppc"
#elif defined(__sparc__) || defined(__sparc)
# define LOL_ARCH_NAME "sparc"
#endif

#ifndef LOL_ARCH_NAME
# define LOL_ARCH_NAME ""
#endif

#define LOL_VERSION_MESSAGE "RAINBOWS AN UNICORNS!\n"LOL_APPNAME" v"LOL_VERSION" "LOL_ARCH_NAME", using mruby "MRUBY_VERSION"\n"

/**
 * Notice:
 *  The following text messages was copied from the original lolcat gem here: https://github.com/busyloop/lolcat/blob/master/lib/lolcat/cat.rb#L55
 *  That file is licensed under [DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE](https://github.com/busyloop/lolcat/blob/master/LICENSE)
 *  However, here these messages along with this file is licensed under the MIT license to follow project conventions.
 */
#define LOL_HELP_MESSAGE "\
Usage: "LOL_APPNAME" [OPTION]... [FILE]...\n\
\n\
Concatenate FILE(s), or standard input, to standard output.\n\
With no FILE, or when FILE is -, read standard input.\n\
\n\
    --spread, -p <f>:   Rainbow spread (default: "LOL_STR(LOL_SPREAD)")\n\
      --freq, -F <f>:   Rainbow frequency (default: "LOL_STR(LOL_FREQ)")\n\
      --seed, -S <i>:   Rainbow seed, 0 = random (default: "LOL_STR(LOL_SEED)")\n\
       --animate, -a:   Enable psychedelics\n\
  --duration, -d <i>:   Animation duration (default: "LOL_STR(LOL_DURATION)")\n\
     --speed, -s <f>:   Animation speed (default: "LOL_STR(LOL_SPEED)")\n\
         --force, -f:   Force color even when stdout is not a tty\n\
       --version, -v:   Print version and exit\n\
          --help, -h:   Show this message\n\
\n\
Examples:\n\
  "LOL_APPNAME" f - g      Output f's contents, then stdin, then g's contents.\n\
  "LOL_APPNAME"            Copy standard input to standard output.\n\
  fortune | "LOL_APPNAME"  Display a rainbow cookie.\n\
\n\
Home page: <"LOL_REPO_URL">\n\
Report bugs to: <"LOL_REPO_URL"/issues>\n"

#endif
