def palindrome?( string )
  s = string.downcase.gsub( /\W/, ' ' ).split( ' ' ).join
  s == s.reverse
end

def count_words( string )
  a = string.downcase.gsub( /\W/, ' ' ).split( ' ' )
  h = Hash.new( 0 )
  a.each { |i| h[i] += 1 }
  h
end