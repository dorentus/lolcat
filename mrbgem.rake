MRuby::Gem::Specification.new('mruby-lolcat') do |spec|
  spec.license = 'DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE & MIT'
  spec.authors = 'ZHANG Yi'
  spec.version = '0.0.1'
  spec.add_dependency('mruby-regexp-pcre')
  spec.add_dependency('mruby-errno')
  spec.add_dependency('mruby-io')
  spec.add_dependency('mruby-sleep')
end
