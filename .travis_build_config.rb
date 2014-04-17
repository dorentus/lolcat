MRuby::Build.new do |conf|
  toolchain :gcc
  conf.gembox 'default'
  conf.gem :core => 'mruby-string-utf8'
  conf.gem :github => 'iij/mruby-regexp-pcre'
  conf.gem :github => 'iij/mruby-errno'
  conf.gem :github => 'iij/mruby-io'
  conf.gem :github => 'matsumoto-r/mruby-sleep'
  conf.gem '../mruby-lolcat'
end
