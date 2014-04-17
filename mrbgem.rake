require File.expand_path('../mrblib/version.rb', __FILE__)

MRuby::Gem::Specification.new('mruby-lolcat') do |spec|
  spec.license = 'MIT'
  spec.authors = 'lolcat contributors'
  spec.version = Lol::VERSION
  spec.add_dependency('mruby-regexp-pcre')
  spec.add_dependency('mruby-errno')
  spec.add_dependency('mruby-io')
  spec.add_dependency('mruby-sleep')
end
