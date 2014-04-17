#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <getopt.h>
#include <stdbool.h>
#include <mruby.h>
#include <mruby/string.h>
#include <mruby/array.h>
#include <mruby/hash.h>
#include "lolcat.h"

void lolhalp(char * const text)
{
  mrb_state * mrb = mrb_open();
  mrb_value param_text = mrb_str_new_cstr(mrb, text);
  struct RClass * lol_module = mrb_module_get(mrb, "Lol");
  mrb_funcall(mrb, mrb_obj_value(lol_module), "halp!", 1, param_text);
  mrb_close(mrb);
}

void
lolcat(float spread, float frequency, uint32_t seed,
  _Bool animate, uint32_t duration, float speed, _Bool force,
  char *files[], int count)
{
  _Bool output_colored = force;
  if (!output_colored) {
    output_colored = isatty(fileno(stdout));
  }

  mrb_state * mrb = mrb_open();

  mrb_value param_files = mrb_ary_new_capa(mrb, count);
  int index;
  for (index = 0; index < count; ++index) {
    mrb_ary_set(mrb, param_files, index, mrb_str_new_cstr(mrb, files[index]));
  }

  mrb_value param_opts = mrb_hash_new_capa(mrb, 7);
  mrb_hash_set(mrb, param_opts,
    mrb_symbol_value(mrb_intern_cstr(mrb, "spread")),
    mrb_float_value(mrb, spread));
  mrb_hash_set(mrb, param_opts,
    mrb_symbol_value(mrb_intern_cstr(mrb, "freq")),
    mrb_float_value(mrb, frequency));
  mrb_hash_set(mrb, param_opts,
    mrb_symbol_value(mrb_intern_cstr(mrb, "os")),
    mrb_fixnum_value(seed));
  mrb_hash_set(mrb, param_opts,
    mrb_symbol_value(mrb_intern_cstr(mrb, "animate")),
    mrb_bool_value(animate));
  mrb_hash_set(mrb, param_opts,
    mrb_symbol_value(mrb_intern_cstr(mrb, "duration")),
    mrb_fixnum_value(duration));
  mrb_hash_set(mrb, param_opts,
    mrb_symbol_value(mrb_intern_cstr(mrb, "speed")),
    mrb_float_value(mrb, speed));
  mrb_hash_set(mrb, param_opts,
    mrb_symbol_value(mrb_intern_cstr(mrb, "colored")),
    mrb_bool_value(output_colored));

  struct RClass * lol_module = mrb_module_get(mrb, "Lol");

  mrb_funcall(mrb, mrb_obj_value(lol_module), "cat!", 2, param_files, param_opts);

  if (mrb->exc) {
    mrb_p(mrb, mrb_obj_value(mrb->exc));
    mrb_close(mrb);
    exit(EXIT_FAILURE);
  }

  mrb_close(mrb);
}

void
print_version()
{
  lolhalp(LOL_VERSION_MESSAGE);
}

void
print_help()
{
  lolhalp(LOL_HELP_MESSAGE);
}

void die(char * const message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

int
main(int argc, char **argv)
{
  static struct option longopts[] = {
    { "spread",    required_argument,  NULL,  'p' },
    { "freq",      required_argument,  NULL,  'F' },
    { "seed",      required_argument,  NULL,  'S' },
    { "animate",   no_argument,        NULL,  'a' },
    { "duration",  required_argument,  NULL,  'd' },
    { "speed",     required_argument,  NULL,  's' },
    { "force",     no_argument,        NULL,  'f' },
    { "version",   no_argument,        NULL,  'v' },
    { "help",      no_argument,        NULL,  'h' }
  };

  float spread = LOL_SPREAD;
  float frequency = LOL_FREQ;
  uint32_t seed = LOL_SEED;
  _Bool animate = LOL_ANIMATE;
  uint32_t duration = LOL_DURATION;
  float speed = LOL_SPEED;
  _Bool force = LOL_FORCE;
  int c;

  while ((c = getopt_long(argc, argv, "p:F:S:ad:s:fvh", longopts, NULL)) != -1) {
    switch (c) {
      case 'p':
        spread = atof(optarg);
        break;
      case 'F':
        frequency = atof(optarg);
        break;
      case 'S':
        seed = atoi(optarg);
        break;
      case 'a':
        animate = 1;
        break;
      case 'd':
        duration = atoi(optarg);
        break;
      case 's':
        speed = atof(optarg);
        break;
      case 'f':
        force = 1;
        break;
      case 'v':
        print_version();
        return 0;
      case 'h':
        print_help();
        return 0;
      default:
        abort();
    }
  }

  if (spread < 0.1) {
    die("spread must be >= 0.1");
  }

  if (duration < 0.1) {
    die("duration must be >= 0.1");
  }

  if (speed < 0.1) {
    die("speed must be >= 0.1");
  }

  int i;
  int count = argc - optind;
  char* files[count];
  for (i = 0; i < count; ++i) {
    files[i] = argv[i + optind];
  }

  lolcat(spread, frequency, seed, animate, duration, speed, force, files, count);

  return EXIT_SUCCESS;
}
