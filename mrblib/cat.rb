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
  def self.halp!(text, opts={})
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

  def self.cat!(files, opts={})
    opts[:os] = rand(256) if opts[:os] == 0
    files = [:stdin] if files.empty?
    files.each do |file|
      fd = $stdin if file == '-' or file == :stdin

      begin
        fd = File.open file unless fd == $stdin

        if opts[:colored]
          Lol.cat fd, opts
        else
          until fd.eof? do
            $stdout.write(fd.read(8192))
          end
        end
      rescue Errno::ENOENT
        puts "lolcat: #{file}: No such file or directory"
        return
      rescue Errno::EACCES
        puts "lolcat: #{file}: Permission denied"
        return
      rescue Errno::EISDIR
        puts "lolcat: #{file}: Is a directory"
        return
      rescue Errno::EPIPE
        return
      end

      fd.close unless fd == $stdin
    end
  end
end
