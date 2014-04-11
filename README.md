#mruby-lolcat
Rainbows and unicorns! forked as a muby gem.

[![Build Status](https://travis-ci.org/dorentus/mruby-lolcat.svg?branch=master)](https://travis-ci.org/dorentus/mruby-lolcat)

Original ruby gem is here: https://github.com/busyloop/lolcat

## Installation
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

## Usage
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

Lol.println 'Rainbows and unicorns! '

Lol.cat! ['/etc/hosts', '/etc/fstab'], opts

Lol.cat $stdin, opts

fd = File.open('/etc/hosts')
Lol.cat fd, opts
fd.close
```

## License
see [LICENSE](LICENSE)

## Looking for a runnable binary?
see https://github.com/dorentus/mruby-lolcat-bin
