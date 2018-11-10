MRuby::Build.new do |conf|
  toolchain :gcc
  conf.gembox 'default'
  conf.gem :core => 'mruby-io'
  conf.gem :github => 'iij/mruby-regexp-pcre'
  conf.gem :github => 'iij/mruby-errno'
  conf.gem :github => 'matsumoto-r/mruby-sleep'
  conf.gem '../../'
end
