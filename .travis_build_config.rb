MRuby::Build.new do |conf|
  toolchain :gcc
  conf.gembox 'default'
  conf.gem :github => 'iij/mruby-regexp-pcre'
  conf.gem '../mruby-lolcat'
end
