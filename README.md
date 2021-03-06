# mruby-lolcat
mruby fork of the [`lolcat`](https://github.com/busyloop/lolcat/).

Powerd by [mruby](https://github.com/mruby/mruby), will build a standalone binary for OS X, Linux, or maybe for any other *NIX platforms.

[![Build Status](http://img.shields.io/travis/dorentus/mruby-lolcat.svg?style=flat)](https://travis-ci.org/dorentus/mruby-lolcat)

## Special Thanks
- https://github.com/busyloop/lolcat, the original ruby gem, most of the code was from there
- https://github.com/janlelis/paint, the colors!
- https://github.com/mruby/mruby

## The command line program

### Installation

#### Prerequisites
To compile out of the source code you need the following tools:

- C Compiler (i.e. `gcc`)
- Linker (i.e. `gcc`)
- Archive utility (i.e. `ar`)
- Parser generator (i.e. `bison`)
- Ruby 1.8 or 1.9 (i.e. `ruby` or `jruby`)

Read [mruby's document](https://github.com/mruby/mruby/tree/master/doc/compile)  for more infomation.

#### Get the code
```bash
git clone https://github.com/dorentus/mruby-lolcat.git
cd mruby-lolcat
```
Or if you'd prefer downloading tarballs, navigate to: https://github.com/dorentus/mruby-lolcat/releases

#### Build
The following command will build and install `lolcat` to `/usr/local/bin/lolcat`:
```bash
make -C binutils install PREFIX=/usr/local APPNAME=lolcat
```
Or you could just run:
```bash
make -C binutils install
```

#### If you're using OS X and [homebrew](https://github.com/Homebrew/homebrew)
Ignore previous instructions and just do:
```bash
brew install dorentus/recipes/lolcat_mruby
```

### Usage
Run `lolcat -h` for details and examples.

![usage](https://dn-madokami.qbox.me/lolcat/usage_updated.png)
![screenshot](https://dn-madokami.qbox.me/lolcat/screenshot.png)

## As a mruby gem

### Build
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'iij/mruby-io'
    conf.gem :github => 'iij/mruby-regexp-pcre'
    conf.gem :github => 'matsumoto-r/mruby-sleep'
    conf.gem :github => 'dorentus/mruby-lolcat'
end
```

### Usage
```ruby
opts = {
  :animate => false,
  :duration => 12,
  :os => 0,
  :speed => 20,
  :spread => 8.0,
  :freq => 0.3,
  :colored => true
}

Lol.println 'RAINBOWS AN UNICORNS! '

Lol.cat! ['/etc/hosts', '/etc/fstab'], opts

Lol.cat $stdin, opts

fd = File.open('/etc/hosts')
Lol.cat fd, opts
fd.close
```

## License
[The MIT LICENSE](LICENSE)
