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
    conf.gem :github => 'dorentus/mruby-lolcat'
end
```

## Usage
```ruby
Lol.cat! 'Rainbows and unicorns! '

opts = {
  :animate => false,
  :duration => 12,
  :os => 0,
  :speed => 20,
  :spread => 8.0,
  :freq => 0.3
}

Lol.cat $stdin, opts

fd = File.open('/etc/hosts')
Lol.cat fd, opts
fd.close
```

## License
see [LICENSE](LICENSE)
