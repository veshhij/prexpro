def combine_anagrams( words )
  h = Hash.new( [] )
  words.each { |i|
    w = []
    w << i
    h[i.downcase.chars.to_a.sort.join] += w
  }
  h.values
end