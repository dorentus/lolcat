MRuby::Build.new do |conf|
  toolchain :gcc
  conf.gembox 'default'
  conf.gem :github => 'iij/mruby-regexp-pcre'
  conf.gem :github => 'iij/mruby-errno'
  conf.gem :github => 'iij/mruby-io'
  conf.gem '../mruby-lolcat'
end
