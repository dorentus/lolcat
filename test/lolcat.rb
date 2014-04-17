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
  assert_nothing_raised { Lol.println 'RAINBOWS AN UNICORNS!', opts }
  assert_nothing_raised { Lol.cat! ['README.md'], opts }
  assert_nothing_raised { Lol.cat! ['./nonexistent'], opts }
  assert_nothing_raised { Lol.println 'こんにちは世界', opts }
end
