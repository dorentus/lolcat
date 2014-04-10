#
# Borrowed from https://github.com/janlelis/paint
# => https://github.com/janlelis/paint/blob/master/lib/paint.rb
#
# The MIT LICENSE
#
# Copyright (c) 2011-2014 Jan Lelis
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#

module Lol
  module MiniPaint
    NOTHING = "\033[0m"

    class << self
      def [](string, hexcolor)
        return string.to_s if hexcolor.empty?

        cache[hexcolor] + string.to_s + NOTHING
      end

      private

      def cache
        return @cache if @cache
        @cache = Hash.new { |h, k| h[k] = color(*k) }
        def @cache.[](*k) k.include?(:random) ? self.class.color(*k) : super end
        @cache
      end

      def color(hexcolor)
        return '' if hexcolor.empty?

        "\033[" + hex(hexcolor, false) + "m"
      end

      # Creates a 256-compatible color from rgb values
      def rgb(red, green, blue, background = false)
        "#{background ? 48 : 38}#{rgb_value(red, green, blue)}"
      end

      # Returns nearest supported 256-color an rgb value, without fore-/background information
      # Inspired by the rainbow gem
      def rgb_value(red, green, blue)
        gray_possible = true
        sep = 42.5

        while gray_possible
          if red < sep || green < sep || blue < sep
            gray = red < sep && green < sep && blue < sep
            gray_possible = false
          end
          sep += 42.5
        end

        if gray
          ";5;#{ 232 + ((red.to_f + green.to_f + blue.to_f)/33).round }"
        else # rgb
          ";5;#{ [16, *[red, green, blue].zip([36, 6, 1]).map{ |color, mod|
            (6 * (color.to_f / 256)).to_i * mod
          }].inject(:+) }"
        end
      end

      # Creates 256-compatible color from a html-like color string
      def hex(string, background = false)
        string = string.gsub(/^#/, '')
        rgb(
         *(if string.size == 6
            # string.chars.each_cons(2).map{ |hex_color| hex_color.join.to_i(16) }
            [string[0,2].to_i(16), string[2,2].to_i(16), string[4,2].to_i(16)]
          else
            string.split(//).map{ |hex_color_half| (hex_color_half*2).to_i(16) }
          end + [background]) # 1.8 workaround
        )
      end
    end
  end
end
