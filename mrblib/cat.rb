#
# lolcat (c)2011 moe@busyloop.net
#

#            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
#                    Version 2, December 2004
#
# Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>
#
# Everyone is permitted to copy and distribute verbatim or modified
# copies of this license document, and changing it is allowed as long
# as the name is changed.
#
#            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
#   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
#
#  0. You just DO WHAT THE FUCK YOU WANT TO.

module Lol
  def self.cat!(text, opts={})
    opts = {
      :animate => false,
      :duration => 12,
      :os => 0,
      :speed => 20,
      :spread => 8.0,
      :freq => 0.3
    }.merge opts

    i = 20
    o = rand(256)
    text.split("\n").each do |line|
      i -= 1
      opts[:os] = o+i
      Lol.println line, opts
    end
    puts "\n"
  end
end
