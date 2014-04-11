assert('Lol.cat!') do
  opts = {
    :animate => false,
    :duration => 12,
    :os => 0,
    :speed => 20,
    :spread => 8.0,
    :freq => 0.3,
    :colored => true
  }
  assert_nothing_raised { Lol.println 'Rainbows and unicorns!', opts }
  assert_nothing_raised { Lol.cat! ['README.md'], opts }
end
