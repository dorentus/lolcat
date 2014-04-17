# mruby-lolcat-bin
mruby fork of the [`lolcat`](https://github.com/busyloop/lolcat/).

Powerd by [mruby](https://github.com/mruby/mruby), will build a standalone binary for OS X, Linux, or maybe for any other *NIX platforms.

[![Build Status](https://travis-ci.org/dorentus/mruby-lolcat-bin.svg)](https://travis-ci.org/dorentus/mruby-lolcat-bin)

## Special Thanks
- https://github.com/busyloop/lolcat, the original ruby gem, most of the code was from there
- https://github.com/janlelis/paint, the colors!
- https://github.com/mruby/mruby

## Installation

### Prerequisites
To compile out of the source code you need the following tools:

- C Compiler (i.e. `gcc`)
- Linker (i.e. `gcc`)
- Archive utility (i.e. `ar`)
- Parser generator (i.e. `bison`)
- Ruby 1.8 or 1.9 (i.e. `ruby` or `jruby`)

Read [mruby's document for more infomation](https://github.com/mruby/mruby/tree/master/doc/compile).

### Get the code
```
git clone https://github.com/dorentus/mruby-lolcat-bin.git
cd mruby-lolcat-bin
```
Or if you'd prefer downloading tarballs, navigate to: https://github.com/dorentus/mruby-lolcat-bin/releases

### Build
The following command will build and install `lolcat` to `/usr/local/bin/lolcat`:
```
make install PREFIX=/usr/local APPNAME=lolcat
```
Or you could just run:
```
make install
```

### If you're using OS X and [homebrew](https://github.com/Homebrew/homebrew)
Ignore previous instructions and just do:
```
brew install dorentus/tap/lolcat_mruby
```

## Usage
Run `lolcat -h` for details and examples.

![usage](https://dn-madokami.qbox.me/lolcat/usage.png)
![screenshot](https://dn-madokami.qbox.me/lolcat/screenshot.png)

## LICENSE
[The MIT License](MITL)

License used by the underlying mrbgem is here: https://github.com/dorentus/mruby-lolcat/blob/master/LICENSE.
